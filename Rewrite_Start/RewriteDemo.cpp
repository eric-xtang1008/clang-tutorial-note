#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendAction.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include "clang/Rewrite/Frontend/Rewriters.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"

#include "llvm/Support/CommandLine.h"

using namespace clang::tooling;
using namespace clang;

static llvm::cl::OptionCategory ToolCategory("clang tool options");

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
    ;

    return true;
  }

private:
  ASTContext *Context;
  Rewriter TheRewriter;
};

class RewriteClassConsumer : public ASTConsumer {
public:
  explicit RewriteClassConsumer(ASTContext *Context) : Visitor(Context) {}
  virtual void HandleTranslationUnit(ASTContext &Context) {
    Visitor.TraverseDecl(Context.getTranslationUnitDecl());
  }

private:
  RewriteClassVisitor Visitor;
};

class RewriteClassAction : public ASTFrontendAction {
public:
  virtual std::unique_ptr<ASTConsumer>
  CreateASTConsumer(CompilerInstance &Compiler, llvm::StringRef InFile) {
    return std::make_unique<RewriteClassConsumer>(&Compiler.getASTContext());
  }
};

int main(int argc, const char **argv) {
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
