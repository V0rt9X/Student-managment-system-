cmake_minimum_required(VERSION 4.0)
project(FinalProject C)

set(CMAKE_C_STANDARD 23)

add_executable(main
        ${PROJECT_SOURCE_DIR}/main.c
        ${PROJECT_SOURCE_DIR}/modules/student.c
)