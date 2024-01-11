PROJECT (BASIC)
MESSAGE(STATUS "This is BASIC module source dir:" ${PROJECT_SOURCE_DIR})
MESSAGE(STATUS "This is BASIC module binary dir:" ${PROJECT_BINARY_DIR})
File(GLOB BASIC_SRC_LIST src/*.cpp)
ADD_LIBRARY(basic_module ${BASIC_SRC_LIST})

if(NOT WIN32)
    TARGET_LINK_LIBRARIES(basic_module pthread)
endif()
