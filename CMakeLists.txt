cmake_minimum_required(VERSION 3.10)
project(simple_redis C)

set(CMAKE_C_STANDARD 11)

include_directories(src)
aux_source_directory(src SRC_FILES)
aux_source_directory(. CWD_FILES)

add_library(simple_redis_lib SHARED ${SRC_FILES})
add_executable(simple_redis ${CWD_FILES} ${SRC_FILES})
add_subdirectory(test)