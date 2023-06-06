cmake_minimum_required (VERSION 2.6)
set (CMAKE_C_STANDARD 99)

project (stressTransformStruct)

include_directories(${PROJECT_SOURCE_DIR})
add_executable(stressTransform main.c stresstransform.c)
target_link_libraries(stressTransform m)
