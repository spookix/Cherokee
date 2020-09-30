cmake_minimum_required(VERSION 3.0)
project(cherokee C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(Criterion)
include_directories(criterion Criterion/include)

include_directories(include)
add_executable(cherokee src/pool.c src/main.c src/server.c)

add_executable (unit_tests test/test.c)
target_link_libraries(unit_tests criterion)
add_test (unit_tests unit_tests)

install(TARGETS cherokee RUNTIME DESTINATION bin)
