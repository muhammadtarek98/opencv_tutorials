cmake_minimum_required(VERSION 3.17)
set(CMAKE_CUDA_COMPILER /usr/local/cuda-11.8/bin/nvcc)
set(CMAKE_CUDA_ARCHITECTURES 75)
project(affine_transformation LANGUAGES C CXX CUDA)
set(CMAKE_CXX_STANDARD 20)
find_package(OpenCV REQUIRED PATHS /home/muhammad/opencv/ NO_DEFAULT_PATH)
add_executable(affine_transformation main.cpp)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
target_include_directories(${PROJECT_NAME} PRIVATE ${OpenCV_INCLUDE_DIRS})