cmake_minimum_required(VERSION 3.16)
PROJECT (DAILY)
MESSAGE(STATUS "This is poject source dir:" ${PROJECT_SOURCE_DIR})
MESSAGE(STATUS "This is poject binary dir:" ${PROJECT_BINARY_DIR})

ADD_SUBDIRECTORY(basic)
ADD_SUBDIRECTORY(algorithm)
ADD_SUBDIRECTORY(node_related)
ADD_SUBDIRECTORY(examples)