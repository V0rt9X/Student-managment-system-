cmake_minimum_required(VERSION 4.0)
project(FinalProject C)

set(CMAKE_C_STANDARD 23)

include_directories(${PROJECT_SOURCE_DIR}/modules)

add_executable(test
        ${PROJECT_SOURCE_DIR}/test.c
        ${PROJECT_SOURCE_DIR}/modules/student.c
        ${PROJECT_SOURCE_DIR}/modules/database.c
)