cmake_minimum_required (VERSION 2.6)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)

project (pi)

find_package(MPI REQUIRED)
include_directories(SYSTEM ${MPI_INCLUDE_PATH})

include_directories(${PROJECT_SOURCE_DIR})

add_executable(pi gather1.c)
target_link_libraries(pi ${MPI_LIBRARIES})
#target_include(pi ${MPI_INCLUDES})

