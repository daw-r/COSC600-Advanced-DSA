cmake_minimum_required(VERSION 3.10)
project(QuicksortTest)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_executable(QuicksortTest main.cc)
#target_compile_options(QuicksortTest PRIVATE  $<$<CXX_COMPILER_ID:Clang>:-g>)
target_include_directories(QuicksortTest PRIVATE Quicksort)

# Prevent in-source builds
if (CMAKE_BINARY_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    message(FATAL_ERROR "Building in-source is not supported! Create a build dir and remove ${CMAKE_SOURCE_DIR}/CMakeCache.txt")
endif()

# Try to support build Catch2 from source and searching for it on the system
Include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.1 # or a later release
  FIND_PACKAGE_ARGS NAMES Catch2
)
FetchContent_MakeAvailable(Catch2)
target_link_libraries(QuicksortTest PRIVATE Catch2::Catch2WithMain)