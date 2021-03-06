//===--- UsePropertyCheck.h - clang-tidy--------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_MISC_UNUSED_PARAMETERS_H
#define LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_MISC_UNUSED_PARAMETERS_H

#include "../ClangTidy.h"

namespace clang {
namespace tidy {
namespace aurzescript {

/// Finds unused parameters and fixes them, so that `-Wunused-parameter` can be
/// turned on.
class UsePropertyCheck : public ClangTidyCheck {
public:
  UsePropertyCheck(StringRef Name, ClangTidyContext *Context)
      : ClangTidyCheck(Name, Context) {}
  void registerMatchers(ast_matchers::MatchFinder *Finder) override;
  void check(const ast_matchers::MatchFinder::MatchResult &Result) override;

private:
  void
  warnOnUnusedParameter(const ast_matchers::MatchFinder::MatchResult &Result,
                        const FunctionDecl *Function, unsigned ParamIndex);
};

} // namespace aurzescript
} // namespace tidy
} // namespace clang

#endif // LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_MISC_UNUSED_PARAMETERS_H
