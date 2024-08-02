#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendAction.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"

#include "llvm/Support/CommandLine.h"
#include <clang/AST/Expr.h>
#include <llvm/Support/Casting.h>

using namespace clang::tooling;
using namespace clang;

static llvm::cl::OptionCategory ToolCategory("clang tool options");

static std::unique_ptr<llvm::LLVMContext> TheContext;
static std::unique_ptr<llvm::IRBuilder<>> Builder;
static std::unique_ptr<llvm::Module> TheModule;

class RewriteClassVisitor : public RecursiveASTVisitor<RewriteClassVisitor> {
public:
  explicit RewriteClassVisitor(ASTContext *Context) : Context(Context) {
    // Init TheRewriter
    TheRewriter.setSourceMgr(Context->getSourceManager(),
                             Context->getLangOpts());
  }

  bool VisitTranslationUnitDecl(TranslationUnitDecl *D) {
    // out put the file to terminator
    TheRewriter.getEditBuffer(TheRewriter.getSourceMgr().getMainFileID())
        .write(llvm::outs());

    return true;
  }

private:
  ASTContext *Context;
  Rewriter TheRewriter;
};

class RewriteClassConsumer : public ASTConsumer {
public:
  explicit RewriteClassConsumer(ASTContext *Context)
      : Visitor(Context), Context(Context) {}
  virtual void HandleTranslationUnit(ASTContext &Context) override {
    Visitor.TraverseDecl(Context.getTranslationUnitDecl());
  }
  bool HandleTopLevelDecl(DeclGroupRef DG) override {
    for (DeclGroupRef::iterator I = DG.begin(), E = DG.end(); I != E; ++I) {
      if (VarDecl *D = dyn_cast<VarDecl>(*I)) {
        llvm::Type *ResultType = nullptr;
        QualType T = D->getType();
        const Type *Ty = T.getTypePtr();
        switch (Ty->getTypeClass()) {
        case Type::Builtin: {
          switch (cast<BuiltinType>(Ty)->getKind()) {
          case BuiltinType::Void:
            ResultType = llvm::Type::getInt8Ty(*TheContext);
            break;
          case BuiltinType::Char_S:
          case BuiltinType::Char_U:
          case BuiltinType::SChar:
          case BuiltinType::UChar:
          case BuiltinType::Short:
          case BuiltinType::UShort:
          case BuiltinType::Int:
          case BuiltinType::UInt:
          case BuiltinType::Long:
          case BuiltinType::ULong:
          case BuiltinType::LongLong:
          case BuiltinType::ULongLong:
            ResultType = llvm::IntegerType::get(
                *TheContext, static_cast<unsigned>(Context->getTypeSize(T)));
            break;
          default:
            llvm_unreachable("invalid BuiltinType value");
            break;
          }
          break;
        }
        default:
          llvm_unreachable("invalid Type value");
          break;
        }

        TheModule->getOrInsertGlobal(D->getName(), ResultType);
        llvm::GlobalVariable *GVar = TheModule->getNamedGlobal(D->getName());

        Expr *InitVal = D->getInit();
        IntegerLiteral *IntVal = nullptr;
        if (auto *ImplicitCastVal = dyn_cast<ImplicitCastExpr>(InitVal))
          IntVal = dyn_cast<IntegerLiteral>(ImplicitCastVal->getSubExpr());
        else
          IntVal = dyn_cast<IntegerLiteral>(InitVal);

        if (IntVal)
          GVar->setInitializer(llvm::ConstantInt::get(
              ResultType, IntVal->getValue().getZExtValue()));
        TheModule->print(llvm::errs(), nullptr);
      }
    }
    return true;
  }

private:
  RewriteClassVisitor Visitor;
  ASTContext *Context;
};

class RewriteClassAction : public ASTFrontendAction {
public:
  virtual std::unique_ptr<ASTConsumer>
  CreateASTConsumer(CompilerInstance &Compiler, llvm::StringRef InFile) {
    return std::make_unique<RewriteClassConsumer>(&Compiler.getASTContext());
  }
};

void InitializeModule(const char **argv) {
  // Open a new context and module.
  TheContext = std::make_unique<llvm::LLVMContext>();
  TheModule = std::make_unique<llvm::Module>(*(++argv), *TheContext);

  // Create a new builder for the module.
  Builder = std::make_unique<llvm::IRBuilder<>>(*TheContext);
}

int main(int argc, const char **argv) {
  InitializeModule(argv);
  auto ExpectedParser = CommonOptionsParser::create(argc, argv, ToolCategory);
  if (!ExpectedParser) {
    llvm::errs() << ExpectedParser.takeError();
    return 1;
  }
  CommonOptionsParser &OptionsParser = ExpectedParser.get();
  ClangTool Tool(OptionsParser.getCompilations(),
                 OptionsParser.getSourcePathList());
  // run the Clang Tool, creating a new FrontendAction (explained below)
  return Tool.run(newFrontendActionFactory<RewriteClassAction>().get());
}
