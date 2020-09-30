cmake_minimum_required(VERSION 3.0)

project(proto)

add_executable(proto main.c)
add_executable(uri uri.c)

add_subdirectory(pool)

add_executable(pool_example pool_example.c)
target_link_libraries(pool_example pool)
