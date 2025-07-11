cmake_minimum_required(VERSION 3.16)
project(Vision)

set(CMAKE_CXX_STANDARD 17)

# Setting the path to Qt
set(CMAKE_PREFIX_PATH "/opt/homebrew/opt/qt")

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(Vision main.cpp)
target_link_libraries(Vision PRIVATE Qt6::Widgets)

