#include <clang/AST/ASTConsumer.h>
#include <clang/AST/ASTContext.h>
#include <clang/Basic/CodeGenOptions.h>
#include <clang/Basic/Diagnostic.h>
#include <clang/Basic/DiagnosticFrontend.h>
#include <clang/Basic/LangOptions.h>
#include <clang/Basic/TargetInfo.h>
#include <clang/Basic/TargetOptions.h>
#include <clang/CodeGen/ModuleBuilder.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/Parse/ParseAST.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/TargetParser/Host.h>
#include <memory>

using namespace clang;

class CodeGenExConsumer : public ASTConsumer {
  CodeGenerator &Gen;

public:
  explicit CodeGenExConsumer(CodeGenerator &Gen) : Gen(Gen) {
    llvm::outs() << "CodeGenExConsumer construct" << "\n";
  }
  virtual ~CodeGenExConsumer() {}

  void Initialize(ASTContext &Ctx) override { Gen.Initialize(Ctx); }

  bool HandleTopLevelDecl(DeclGroupRef DG) override {
    return Gen.HandleTopLevelDecl(DG);
  }

  virtual void HandleTranslationUnit(ASTContext &Context) override {
    Gen.HandleTranslationUnit(Context);
  }
};

int main(int Argc, const char **Argv) {
  llvm::LLVMContext VMContext;
  clang::CompilerInstance CI;
  std::unique_ptr<clang::CodeGenerator> CG;
  CoverageSourceInfo *CoverageInfo = nullptr;
  llvm::Module *M;
  clang::LangOptions LO;
  LO.CPlusPlus = 1;
  LO.CPlusPlus11 = 1;
  SmallVector<const char *, 256> Args(Argv, Argv + Argc);

  CI.getLangOpts() = LO;
  CI.getCodeGenOpts() = clang::CodeGenOptions();
  CI.createDiagnostics();

  std::string TrStr = llvm::Triple::normalize(llvm::sys::getProcessTriple());
  llvm::Triple Tr(TrStr);
  CI.getTargetOpts().Triple = Tr.getTriple();
  llvm::outs() << Tr.getTriple() << "\n";

  CI.setTarget(clang::TargetInfo::CreateTargetInfo(
      CI.getDiagnostics(),
      std::make_shared<clang::TargetOptions>(CI.getTargetOpts())));

  CI.createFileManager();

  CI.createSourceManager(CI.getFileManager());
  bool Success = CompilerInvocation::CreateFromArgs(
      CI.getInvocation(), ArrayRef(Args).slice(1), CI.getDiagnostics(),
      Args[0]);
  if (!Success) {
    llvm::errs() << "Failed in CompilerInvocation" << "\n";
    return 1;
  }

  CI.createPreprocessor(clang::TU_Complete);

  CI.createASTContext();

  std::unique_ptr<clang::CodeGenerator> Gen(
      CreateLLVMCodeGen(CI.getDiagnostics(), "", &CI.getVirtualFileSystem(),
                        CI.getHeaderSearchOpts(), CI.getPreprocessorOpts(),
                        CI.getCodeGenOpts(), VMContext, CoverageInfo));

  CI.setASTConsumer(std::make_unique<CodeGenExConsumer>(*Gen));

  std::string File;
  for (const FrontendInputFile &FIF : CI.getFrontendOpts().Inputs) {
    File = FIF.getFile();
    llvm::outs() << File << "\n";
  }
  auto FE = CI.getFileManager().getFileRef(File);
  if (!FE) {
    auto EC = llvm::errorToErrorCode(FE.takeError());
    CI.getDiagnostics().Report(diag::err_fe_error_reading)
        << File << EC.message();
  }
  CI.getSourceManager().setMainFileID(CI.getSourceManager().createFileID(
      *FE, clang::SourceLocation(), clang::SrcMgr::C_User));

  clang::ParseAST(CI.getPreprocessor(), &CI.getASTConsumer(),
                  CI.getASTContext());

  M = Gen->GetModule();
  M->print(llvm::errs(), nullptr);
  return 0;
}
