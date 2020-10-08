cmake_minimum_required(VERSION 3.15)
project(olimp)

set(CMAKE_CXX_STANDARD 20)
add_executable(olimp main.cpp test_runner.h token.cpp token.h condition_parser.cpp condition_parser.h  node.cpp node.h database.cpp database.h date.cpp date.h test_runner.h condition_parser_test.cpp test_runner.cpp tester_github.h tester_github.h)