cmake_minimum_required(VERSION "3.22.0")

project("AdditionProgram" VERSION 1.0)

enable_testing()

add_executable("${PROJECT_NAME}" MainProgram.cpp)
add_executable(testing_file MainProgram.cpp)
add_test("Addition Test" testing_file)
add_test("Program Execution Test" testing_file)

#add_executable(head_file add.h)
#add_test("Header file test" head_file)

install(TARGETS "${PROJECT_NAME}" DESTINATION src)
install(FILES MainProgram.cpp DESTINATION bin)




