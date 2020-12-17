cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_FLAGS "-std=c++11")
set(INCLUDE_DIR ./headers)
set(SOURCE_DIR ./src)

project(self_driving)

include_directories(${INCLUDE_DIR})

add_library(
	Vector2
	${INCLUDE_DIR}/Vector2.h
	${SOURCE_DIR}/Vector2.cpp
)

add_executable(
	self_driving
	${SOURCE_DIR}/main.cpp
)

target_link_libraries(self_driving PRIVATE Vector2)
