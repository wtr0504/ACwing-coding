# cmake_minimum_required(VERSION 3.10)
# project(MyCppProject)

# set(CMAKE_CXX_STANDARD 17)

# if(NOT CMAKE_BUILD_TYPE)
#   set(CMAKE_BUILD_TYPE Debug)
# endif()

# set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")

# add_executable(code code.cpp)
# target_include_directories(code PRIVATE ${PROJECT_SOURCE_DIR}/solution)
cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 23)

project(code)

add_executable(code
  code.cpp
  solution/binary/search.cpp)


