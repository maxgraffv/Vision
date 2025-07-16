set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # for VSCode .json
cmake_minimum_required(VERSION 3.16)
project(Vision)
set(CMAKE_AUTOMOC ON)


set(CMAKE_CXX_STANDARD 11)

# Setting the path to Qt
set(CMAKE_PREFIX_PATH "/opt/homebrew/opt/qt")

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_library(Matrix Matrix/Matrix.h Matrix/Matrix.tpp)
target_include_directories(Matrix PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Matrix)

add_library(Image Image/Image.h Image/Image.cpp)
target_include_directories(Image PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Image)

add_library(AppWindow AppWindow/AppWindow.cpp AppWindow/AppWindow.h)
target_include_directories(AppWindow PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/AppWindow)

add_library(Pixel Image/Pixel.cpp Image/Pixel.h)
target_include_directories(Pixel PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Pixel)

add_library(QtImage Image/QtImage.cpp Image/QtImage.h)
target_include_directories(QtImage PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Image)

target_link_libraries(Image PUBLIC Matrix Pixel)
target_link_libraries(QtImage PUBLIC Image)

add_executable(Vision main.cpp )

add_subdirectory(ImageProcessor)

target_link_libraries(AppWindow PRIVATE QtImage Qt6::Widgets ImageProcessor)
target_link_libraries(QtImage PRIVATE Qt6::Widgets)
target_link_libraries(Vision PRIVATE AppWindow QtImage Qt6::Widgets)
