cmake_minimum_required(VERSION 3.9)

project(TeethSegmentation)

set(CMAKE_CXX_STANDARD 11)

set(CODE_BASE_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CODE_BASE_PATH}/cmake ${CODE_BASE_PATH}/externals/libigl/cmake)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_BUILD_TYPE Debug)

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else ()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")
endif ()

set(OpenGL_GL_PREFERENCE GLVND)

option(LIBIGL_WITH_OPENGL "Use OpenGL" ON)
option(LIBIGL_WITH_OPENGL_GLFW "Use GLFW" ON)
option(LIBIGL_WITH_VIEWER "Use OpenGL viewer" ON)
option(LIBIGL_WITH_OPENGL_GLFW_IMGUI "Use ImGui" ON)
#option(LIBIGL_WITH_CGAL "Use CGAL" ON)
#option(LIBIGL_WITHOUT_COPYLEFT       "Disable Copyleft libraries"   OFF)
#option(LIBIGL_EXPORT_TARGETS         "Export libigl CMake targets"  ON)


add_subdirectory(externals/libigl)


set(LIBRARIES glfw igl::core igl::opengl igl::opengl_glfw)

set(COMMON_INCLUDES ${CODE_BASE_PATH}/include ${CODE_BASE_PATH}/lib)

set(EXTERNAL_INCLUDES ${LIBIGL_INCLUDE_DIR} ${nanoflann_INCLUDE_DIRS})

FILE(GLOB COMMON_SOURCES ${CODE_BASE_PATH}/src/*.cpp ${CODE_BASE_PATH}/libs/*/*.hpp ${CODE_BASE_PATH}/libs/*/*.h ${CODE_BASE_PATH}/libs/*/*.cpp)
add_executable(${PROJECT_NAME} ${COMMON_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${COMMON_INCLUDES} ${EXTERNAL_INCLUDES})
target_link_libraries(${PROJECT_NAME} PUBLIC ${LIBRARIES})
