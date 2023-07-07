cmake_minimum_required(VERSION 3.20)
project(progetto)

set(CMAKE_CXX_STANDARD 11)


add_executable(progetto  ${PROJECT_SOURCE_DIR}/main.cpp processi.c thread.c funzioni.c)

