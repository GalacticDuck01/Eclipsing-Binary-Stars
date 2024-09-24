cmake_minimum_required(VERSION 3.28.0)

project(EclipsingBinaryStars LANGUAGES CXX)
project(${PROJECT_NAME} VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME})
add_subdirectory(src)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/lib)
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBS})

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