PROJECT (NODE_RELATED)
MESSAGE(STATUS "This is NODE_RELATED module source dir:" ${PROJECT_SOURCE_DIR})
MESSAGE(STATUS "This is NODE_RELATED module binary dir:" ${PROJECT_BINARY_DIR})

file(GLOB NODE_RELATED_SRC_LIST "src/*.cpp")
ADD_LIBRARY(node_related_module ${NODE_RELATED_SRC_LIST})

TARGET_INCLUDE_DIRECTORIES(node_related_module PRIVATE ${PROJECT_SOURCE_DIR}/include)