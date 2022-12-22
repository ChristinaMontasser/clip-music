# CMake generated Testfile for 
# Source directory: D:/Christy/LiveMaxTest/tst
# Build directory: D:/Christy/LiveMaxTest/build/tst
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(LiveMaxTest_tst "D:/Christy/LiveMaxTest/build/tst/Debug/LiveMaxTest_tst.exe")
  set_tests_properties(LiveMaxTest_tst PROPERTIES  _BACKTRACE_TRIPLES "D:/Christy/LiveMaxTest/tst/CMakeLists.txt;11;add_test;D:/Christy/LiveMaxTest/tst/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(LiveMaxTest_tst "D:/Christy/LiveMaxTest/build/tst/Release/LiveMaxTest_tst.exe")
  set_tests_properties(LiveMaxTest_tst PROPERTIES  _BACKTRACE_TRIPLES "D:/Christy/LiveMaxTest/tst/CMakeLists.txt;11;add_test;D:/Christy/LiveMaxTest/tst/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(LiveMaxTest_tst "D:/Christy/LiveMaxTest/build/tst/MinSizeRel/LiveMaxTest_tst.exe")
  set_tests_properties(LiveMaxTest_tst PROPERTIES  _BACKTRACE_TRIPLES "D:/Christy/LiveMaxTest/tst/CMakeLists.txt;11;add_test;D:/Christy/LiveMaxTest/tst/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(LiveMaxTest_tst "D:/Christy/LiveMaxTest/build/tst/RelWithDebInfo/LiveMaxTest_tst.exe")
  set_tests_properties(LiveMaxTest_tst PROPERTIES  _BACKTRACE_TRIPLES "D:/Christy/LiveMaxTest/tst/CMakeLists.txt;11;add_test;D:/Christy/LiveMaxTest/tst/CMakeLists.txt;0;")
else()
  add_test(LiveMaxTest_tst NOT_AVAILABLE)
endif()
