cmake_minimum_required(VERSION 3.16)

enable_language(CUDA)

add_library(DataCompute STATIC DataCompute.cu DataCompute.h)
target_include_directories(DataCompute PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(DataCompute PROPERTIES
    CUDA_SEPARABLE_COMPILATION ON
    CUDA_RESOLVE_DEVICE_SYMBOLS ON
    CUDA_ARCHITECTURES 86
)