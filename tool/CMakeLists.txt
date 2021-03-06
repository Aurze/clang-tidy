set(LLVM_LINK_COMPONENTS
  support
  )

add_clang_executable(clang-tidy
  ClangTidyMain.cpp
  )
add_dependencies(clang-tidy
  clang-headers
  )
target_link_libraries(clang-tidy
  clangAST
  clangASTMatchers
	clangBasic
	clangTidy
	clangTidyAurzeScriptModule
  clangTidyBoostModule
  clangTidyCERTModule
  clangTidyCppCoreGuidelinesModule
  clangTidyGoogleModule
  clangTidyLLVMModule
  clangTidyMiscModule
  clangTidyModernizeModule
  clangTidyMPIModule
  clangTidyPerformanceModule
  clangTidyReadabilityModule
  clangTidySafetyModule
  clangTooling
  )

install(TARGETS clang-tidy
  RUNTIME DESTINATION bin)

install(PROGRAMS clang-tidy-diff.py DESTINATION share/clang)
install(PROGRAMS run-clang-tidy.py DESTINATION share/clang)
