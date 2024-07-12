cmake_minimum_required(VERSION 3.28.0)

project(EclipsingBinaryStars)
project(${PROJECT_NAME} VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIBS
    raylib
)
add_executable(${PROJECT_NAME})
add_subdirectory(src)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/lib)
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBS})

#######################
# Raylib
#######################
find_package(raylib REQUIRED)
target_include_directories(${PROJECT_NAME} PUBLIC ${raylib_INCLUDE_DIRS})