PROJECT (BASIC)
MESSAGE(STATUS "This is BASIC module source dir:" ${PROJECT_SOURCE_DIR})
MESSAGE(STATUS "This is BASIC module binary dir:" ${PROJECT_BINARY_DIR})

file(GLOB BASIC_SRC_LIST "src/*.cpp")
ADD_LIBRARY(basic_module ${BASIC_SRC_LIST})

TARGET_INCLUDE_DIRECTORIES(basic_module PRIVATE ${PROJECT_SOURCE_DIR}/include)