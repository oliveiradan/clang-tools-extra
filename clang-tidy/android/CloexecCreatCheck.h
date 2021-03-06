//===--- CloexecCreatCheck.h - clang-tidy------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_ANDROID_CLOEXEC_CREAT_H
#define LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_ANDROID_CLOEXEC_CREAT_H

#include "CloexecCheck.h"

namespace clang {
namespace tidy {
namespace android {

/// creat() is better to be replaced by open().
/// Find the usage of creat() and redirect user to use open().

/// http://clang.llvm.org/extra/clang-tidy/checks/android-cloexec-creat.html
class CloexecCreatCheck : public CloexecCheck {
public:
  CloexecCreatCheck(StringRef Name, ClangTidyContext *Context)
      : CloexecCheck(Name, Context) {}
  void registerMatchers(ast_matchers::MatchFinder *Finder) override;
  void check(const ast_matchers::MatchFinder::MatchResult &Result) override;
};

} // namespace android
} // namespace tidy
} // namespace clang

#endif // LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_ANDROID_CLOEXEC_CREAT_H
