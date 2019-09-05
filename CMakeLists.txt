cmake_minimum_required (VERSION 3.1)

project (grayroom)

set (CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_STANDARD 14)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set (PROJECT_NAME grayroom)

find_package (Threads)

# Grab git hash
execute_process(COMMAND git rev-parse HEAD OUTPUT_VARIABLE GITHASH)
add_definitions(-DGITHASH=${GITHASH})
message("Git hash: " ${GITHASH})

add_subdirectory (${CMAKE_CURRENT_SOURCE_DIR}/deps/clipp)
add_subdirectory (${CMAKE_CURRENT_SOURCE_DIR}/deps/halide)
add_subdirectory (${CMAKE_CURRENT_SOURCE_DIR}/deps/libraw)

include_directories (
  ${CLIPP_INCLUDE_DIRS}
  ${HALIDE_INCLUDE_DIRS}
  ${LIBRAW_INCLUDE_DIRS}
)

link_directories (
  ${HALIDE_LIBRARY_DIRS}
  ${LIBRAW_LIBRARY_DIRS}
)

add_executable (${PROJECT_NAME}
  ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

add_dependencies (${PROJECT_NAME}
  ${CLIPP_EXTERNAL_PROJECT}
  ${HALIDE_EXTERNAL_PROJECT}
  ${LIBRAW_EXTERNAL_PROJECT}
)

target_link_libraries (${PROJECT_NAME}
  Halide
  raw
)
