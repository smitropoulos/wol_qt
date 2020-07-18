# Unit tests

include_directories(${CMAKE_SOURCE_DIR}/src/)

add_executable(mainTest test_cli_wol.cpp)
target_link_libraries(mainTest linet)

add_test(cliWolTest mainTest)