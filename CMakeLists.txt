cmake_minimum_required(VERSION 3.0)

project(deeplearning LANGUAGES C CXX)
set(PROJECT_ROOT_DIR ${PROJECT_SOURCE_DIR})

set(CMAKE_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 \
    -Wall -Wno-sign-compare -Wno-unused-local-typedefs \
    -Wno-deprecated-declarations -Winit-self -Wno-deprecated-register \
    -Wno-uninitialized \
    -msse -msse2 -pthread \
    -DHAVE_EXECINFO_H=1 -DHAVE_CXXABI_H \
    -g -O2")

#set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/Modules)
#set(CMAKE_PREFIX_PATH $ENV{CONDA_PREFIX})


set(EXECUTABLE_OUTPUT_PATH ${PROJECT_ROOT_DIR}/bin)
#set(LIBRARY_OUTPUT_PATH ${PROJECT_ROOT_DIR}/lib)

include_directories(${CMAKE_CURRENT_LIST_DIR}/src)


FILE(GLOB SOURCES
        src/bin/*.cc
        src/activator/*.cc
        src/perceptron/*.cc
        src/utils/*.cc
)

# bin
add_executable(perceptron src/test/perceptron-test.cc ${SOURCES})

add_executable(linearunit src/test/linearunit-test.cc ${SOURCES})

# link lib
#target_link_libraries(perceptron)
