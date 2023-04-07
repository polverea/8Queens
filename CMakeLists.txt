cmake_minimum_required(VERSION 3.0)
project(Eight_queens)

set(HEADERS_DIR headers)
set(SOURCES_DIR src)

file(GLOB HEADERS ${HEADERS_DIR}/*.h)
file(GLOB SOURCES ${SOURCES_DIR}/*.cpp)

add_executable(run ${SOURCES} ${HEADERS})
target_include_directories(run PUBLIC ${HEADERS_DIR})

