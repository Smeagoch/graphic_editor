cmake_minimum_required(VERSION 3.10)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(graphic_editor VERSION ${PROJECT_VESRION})

add_executable(example main.cpp)
add_library(figure figure.cpp)
add_library(graphic_editor graphic_editor.cpp)

set_target_properties(example figure graphic_editor PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(figure
    PRIVATE "${CMAKE_BINARY_DIR}"
)

target_include_directories(graphic_editor
    PRIVATE "${CMAKE_BINARY_DIR}"
)

target_link_libraries(example PRIVATE figure)
target_link_libraries(example PRIVATE graphic_editor)

if (MSVC)
    target_compile_options(example PRIVATE
        /W4
    )
else ()
    target_compile_options(example PRIVATE
        -Wall -pedantic -Werror
    )
endif()

install(TARGETS example RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

include(CPack)