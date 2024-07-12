target_sources(
    ${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/main.cpp
        ${CMAKE_CURRENT_LIST_DIR}/physics.cpp
        ${CMAKE_CURRENT_LIST_DIR}/simulation.cpp
        ${CMAKE_CURRENT_LIST_DIR}/star.cpp
        ${CMAKE_CURRENT_LIST_DIR}/star_mesh.cpp
)

add_subdirectory(maths)