cmake_minimum_required(VERSION 3.16)
project(FinalProject C)

set(CMAKE_C_STANDARD 23)

include_directories(
        ${PROJECT_SOURCE_DIR}/modules
        ${PROJECT_SOURCE_DIR}/modules/student
        ${PROJECT_SOURCE_DIR}/modules/database
        ${PROJECT_SOURCE_DIR}/modules/stats
        ${PROJECT_SOURCE_DIR}/utilities
        ${PROJECT_SOURCE_DIR}/utilities/utils
        ${PROJECT_SOURCE_DIR}/utilities/input\ output
)

add_executable(main
        ${PROJECT_SOURCE_DIR}/main.c
        ${PROJECT_SOURCE_DIR}/modules/student/student.c
        ${PROJECT_SOURCE_DIR}/modules/database/database.c
        ${PROJECT_SOURCE_DIR}/modules/stats/stats.c
        ${PROJECT_SOURCE_DIR}/utilities/utils/utils.c
        ${PROJECT_SOURCE_DIR}/utilities/input\ output/io.c
)
