cmake_minimum_required(VERSION 4.0)
project(FinalProject C)

set(CMAKE_C_STANDARD 23)

include_directories(${PROJECT_SOURCE_DIR}/modules)

add_executable(main
        ${PROJECT_SOURCE_DIR}/main.c
        modules/student/student.c
        modules/database/database.c
        utilities/utils/utils.c
)