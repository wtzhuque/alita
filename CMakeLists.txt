cmake_minimum_required(VERSION 2.8)

project (alita CXX)
find_package(Protobuf REQUIRED)

include_directories(./ ./src ./idl)

aux_source_directory(./src SRV_SRCS)
aux_source_directory(./cli CLI_SRCS)
aux_source_directory(./idl IDL_SRCS)

#protobuf_generate_cpp(IDL_SRCS IDL_SRCS ./idl/alita_service.proto)

link_libraries(brpc protobuf gflags leveldb pthread ssl crypto dl rt)

add_definitions(-std=c++11 -static)

add_executable(alita ${SRV_SRCS} ${IDL_SRCS})
add_executable(acli ${CLI_SRCS} ${IDL_SRCS})
