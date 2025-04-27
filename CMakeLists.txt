cmake_minimum_required(VERSION 3.13)
project(Vision)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 23)

find_package(OpenCV REQUIRED)

# add_subdirectory()

include_directories(${CMAKE_SOURCE_DIR}/matrix)
include_directories(${CMAKE_SOURCE_DIR}/image)

add_executable(vision main.cpp Matrix/Matrix.cpp Image/Image.cpp)

target_link_libraries(vision ${OpenCV_LIBS})