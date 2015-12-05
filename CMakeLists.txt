project (2015-2016-semester-1)

include_directories (${PROJECT_SOURCE_DIR})
add_library (2015-2016-semester-1 object.cc object_int.cc)
add_executable (object-int-test object_int_test.cc)
add_executable (min min.cc)
add_executable (max max.cc)
target_link_libraries (object-int-test 2015-2016-semester-1)
set (CMAKE_CXX_FLAGS "-std=c++11")

include (CTest)

add_test (object-int-min-nil object-int-min-nil-test.sh)
add_test (object-int-min-max object-int-min-max-test.sh)
add_test (object-int-nil-max object-int-nil-max-test.sh)
