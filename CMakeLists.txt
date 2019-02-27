cmake_minimum_required(VERSION 2.8)

project (alita CXX)

find_package(Protobuf REQUIRED)

include_directories(./ ./src)

aux_source_directory(./src SRCS)

#PROTOBUF_GENERATE_CPP(SRCS SRCS ./src/alita_service.proto)

link_libraries(brpc protobuf gflags leveldb pthread ssl crypto dl rt)

add_definitions(-std=c++11 -static)

add_executable(alita ${SRCS})

add_custom_target(output command echo "hello")
