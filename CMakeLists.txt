# Set the required version of CMake
cmake_minimum_required(VERSION 2.8)

# Set project title
project(ME759)

# Look for CUDA and set up build environment
# Flag 'REQUIRED' forces us to set up CUDA correctly before building
#find_package("CUDA" REQUIRED)

# Include macros from the SBEL utils library
#Include(ParallelUtils.cmake)
#enable_cuda_support()

# Use cuda_add_executable tells CMake to use with nvcc instead of gcc
#cuda_add_executable()

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall") 
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Wall") 
# Add homework subdirectories
add_subdirectory(HW1)
add_subdirectory(HW2)