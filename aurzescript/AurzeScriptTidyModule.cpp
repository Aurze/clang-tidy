//===------- AurzeScriptTidyModule.cpp - clang-tidy -----------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "../ClangTidy.h"
#include "../ClangTidyModule.h"
#include "../ClangTidyModuleRegistry.h"
#include "UsePropertyCheck.h"

using namespace clang::ast_matchers;

namespace clang {
namespace tidy {
namespace aurzescript {

class AurzeScriptModule : public ClangTidyModule {
public:
  void addCheckFactories(ClangTidyCheckFactories &CheckFactories) override {
    CheckFactories.registerCheck<UsePropertyCheck>("aurzescript-use-property");
  }
};

// Register the AurzeScriptModule using this statically initialized variable.
static ClangTidyModuleRegistry::Add<AurzeScriptModule> X("aurzescript-module",
                                                   "Add aurzescript checks.");

} // namespace aurzescript

// This anchor is used to force the linker to link in the generated object file
// and thus register the AurzeScriptModule.
volatile int AurzeScriptModuleAnchorSource = 0;

} // namespace tidy
} // namespace clang
