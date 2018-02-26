cmake_minimum_required(VERSION 3.9)

project(timer_example)

# Add Conan dependencies
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(timer timer.cpp)
set_target_properties(timer PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)
target_link_libraries(timer ${CONAN_LIBS})

