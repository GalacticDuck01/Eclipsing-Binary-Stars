cmake_minimum_required(VERSION 3.28.0)

project(EclipsingBinaryStars LANGUAGES CXX)
project(${PROJECT_NAME} VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")

# Recursively find all source files
file(GLOB_RECURSE CPP_SOURCES "${SRC_DIR}/*.cpp")

# Recursively find all header files
file(GLOB_RECURSE HEADERS "${SRC_DIR}/*.hpp")

# Add all source files to the project
include_directories(${SRC_DIR})

add_executable(${PROJECT_NAME} ${CPP_SOURCES} ${HPP_HEADERS})

#######################
# SFML
#######################
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics)