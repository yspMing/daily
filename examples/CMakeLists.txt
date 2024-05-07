cmake_minimum_required(VERSION 3.16)
PROJECT (EXAMPLE)
MESSAGE(STATUS "This is EXAMPLE poject source dir:" ${PROJECT_SOURCE_DIR})
MESSAGE(STATUS "This is EXAMPLE poject binary dir:" ${PROJECT_BINARY_DIR})

file(GLOB cpp_files "*_example.cpp")
foreach(source_file ${cpp_files})
    # for each source file, remove path and extension, and prepend "ll_"
    get_filename_component(example_name ${source_file} NAME_WE)
    set(example_name "ll_${example_name}")

    # create executable
    add_executable(${example_name} ${source_file})
    target_include_directories(${example_name} PRIVATE ${PROJECT_SOURCE_DIR}/../include)
    target_link_libraries(${example_name} PRIVATE basic_module algorithm_module node_related_module)

    set_target_properties(${example_name} PROPERTIES CXX_STANDARD 17)

endforeach()