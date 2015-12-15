cmake_minimum_required(VERSION 3.0)
project(2015-2016-semester-1)

include_directories(${PROJECT_SOURCE_DIR})
add_library(2015-2016-semester-1 object.cpp object_int.cpp object_list.cpp)
add_executable(object-int-test object_int_test.cpp)
add_executable(object-list-test object_list_test.cpp)
add_executable(min min.cpp)
add_executable(max max.cpp)
target_link_libraries(object-int-test 2015-2016-semester-1)
target_link_libraries(object-list-test 2015-2016-semester-1)
set(CMAKE_CXX_FLAGS "-g -std=c++11")

include(CTest)

add_test(object-int-min-nil object-int-min-nil-test.sh)
add_test(object-int-min-max object-int-min-max-test.sh)
add_test(object-int-nil-max object-int-nil-max-test.sh)
