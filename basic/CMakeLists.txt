PROJECT (BASIC)
MESSAGE(STATUS "This is BASIC module source dir:" ${PROJECT_SOURCE_DIR})
MESSAGE(STATUS "This is BASIC module binary dir:" ${PROJECT_BINARY_DIR})
SET (BASIC_SRC_LIST src/basic.cpp src/classHeir.cpp src/smartPointer.cpp)
ADD_LIBRARY(basic_module ${BASIC_SRC_LIST})

TARGET_LINK_LIBRARIES(basic_module pthread)
