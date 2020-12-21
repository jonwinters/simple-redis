cmake_minimum_required(VERSION 3.10)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
find_package(Threads REQUIRED)


set(CMAKE_CXX_STANDARD 11)
enable_language(CXX)
# aux_source_directory(. TEST_FILES)
add_executable(tests sds_test.cpp)

set_target_properties(tests PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(tests simple_redis_lib ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
gtest_discover_tests(tests)
