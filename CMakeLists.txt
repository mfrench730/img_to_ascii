cmake_minimum_required(VERSION 3.8)

project(img_to_ascii)

set(OpenCV_DIR E:/Coding/OpenCV/opencv/build)
find_package(OpenCV REQUIRED)

add_executable(${PROJECT_NAME} "src/main.cpp" )

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

