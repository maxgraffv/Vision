cmake_minimum_required(VERSION 3.16)

add_library(ImageProcessor STATIC ImageProcessor.cpp ImageProcessor.h)
target_include_directories(ImageProcessor PUBLIC .)

target_link_libraries(ImageProcessor PUBLIC QtImage)
target_link_libraries(QtImage PUBLIC Qt::Widgets)