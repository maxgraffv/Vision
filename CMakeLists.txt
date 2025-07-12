set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # for VSCode .json
cmake_minimum_required(VERSION 3.16)
project(Vision)

set(CMAKE_CXX_STANDARD 17)

# Setting the path to Qt
set(CMAKE_PREFIX_PATH "/opt/homebrew/opt/qt")

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_library(Matrix Matrix/Matrix.h Matrix/Matrix.cpp)
target_include_directories(Matrix PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Matrix)

add_library(Image Image/Image.h Image/Image.cpp)
target_include_directories(Image PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Image)

add_library(AppWindow AppWindow/AppWindow.cpp AppWindow/AppWindow.h)
target_include_directories(AppWindow PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/AppWindow)

target_link_libraries(Image PUBLIC Matrix)

add_executable(Vision main.cpp )

target_link_libraries(AppWindow PRIVATE Qt6::Widgets)
target_link_libraries(Vision PRIVATE AppWindow Image Qt6::Widgets)
