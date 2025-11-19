cmake_minimum_required(VERSION 3.23)
project(dsa_lib)
add_executable(dsa_lib_demo)
target_sources(dsa_lib_demo
  PRIVATE
    src/main.cpp
  )
