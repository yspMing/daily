PROJECT (ALGORITHM)
MESSAGE(STATUS "This is ALGORITHM module source dir:" ${PROJECT_SOURCE_DIR})
MESSAGE(STATUS "This is ALGORITHM module binary dir:" ${PROJECT_BINARY_DIR})
File(GLOB ALGORITHM_SRC_LIST src/*.cpp)
ADD_LIBRARY(algorithm_module ${ALGORITHM_SRC_LIST})

if(NOT WIN32)
    TARGET_LINK_LIBRARIES(algorithm_module pthread)
endif()
