cmake_minimum_required (VERSION 2.6)

project (matMUL)

find_package(BLAS REQUIRED)

include_directories(${PROJECT_SOURCE_DIR})

add_executable(matMul matMul.c myDGEMM.c blasDGEMM.c)
target_link_libraries(matMul m)
target_link_libraries(matMul ${BLAS_LIBRARIES})

add_executable(benchmark benchmark.cpp myDGEMM.c blasDGEMM.c myDGEMM_OrderLoop.c myDGEMM_Transpose.c myDGEMM_Blocked.c)
target_link_libraries(benchmark m)
target_link_libraries(benchmark ${BLAS_LIBRARIES})

