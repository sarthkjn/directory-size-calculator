cmake_minimum_required(VERSION 3.10)
project(DirectorySizeCalculator)

set(CMAKE_CXX_STANDARD 17)

# Include headers
include_directories(include)

# Main executable
add_executable(dirsize
    src/File.cpp
    src/Directory.cpp
    src/FileSystem.cpp
    src/main.cpp
)

# Unit test executable
add_executable(test_runner
    src/File.cpp
    src/Directory.cpp
    src/FileSystem.cpp
    test/test_filesystem.cpp
)
