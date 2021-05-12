cmake_minimum_required(VERSION 3.17)
project(Project)

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_STANDARD 14)

# Build GraphViewerCpp
set(GRAPHVIEWERCPP_PATH lib/GraphViewerCpp)
add_subdirectory(${GRAPHVIEWERCPP_PATH})
include_directories(${GRAPHVIEWERCPP_PATH}/include)

# Add the source files of each TP class
file(GLOB SRC_FILES CONFIGURE_DEPENDS
        "src/*.cpp"
        )

add_executable(Project
        src/main.cpp
        ${SRC_FILES}
        )

target_link_libraries(${PROJECT_NAME} graphviewer)