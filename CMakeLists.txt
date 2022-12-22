
cmake_minimum_required(VERSION 3.5)
set(This LiveMaxTest)

project(${This} C CXX)

set(CMAKE_POSITION_INDEPENDENT_CODE  ON)
set(CMAKE_CXX_FLAGS_RELEASE "/MT")
set(CMAKE_CXX_FLAGS_DEBUG "/MTd")

enable_testing()


include_directories(src)
add_subdirectory(src)

add_subdirectory(googletest)
add_subdirectory(tst)



