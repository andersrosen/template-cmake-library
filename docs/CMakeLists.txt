list(APPEND DOXYGEN_ALIASES "includeexample{1}=\\par Example\\n \\includelineno \\1 \\n")
list(APPEND DOXYGEN_ALIASES "includeexample{2}=\\par Example\\n \\1 \\n \\includelineno \\2 \\n")
list(APPEND DOXYGEN_ALIASES "includeexamplewithoutput{1}=\\par Example\\n \\includelineno \\1 \\n \\par Output \\n \\verbinclude \\1.output")
list(APPEND DOXYGEN_ALIASES "includeexamplewithoutput{2}=\\par Example\\n \\1 \\n \\includelineno \\2 \\n \\par Output \\n \\includelineno \\1.output")
list(APPEND DOXYGEN_EXAMPLE_PATH "${CMAKE_CURRENT_BINARY_DIR}/examples")

doxygen_add_docs(docs ${CMAKE_CURRENT_SOURCE_DIR}/../include ALL)

set(EXAMPLES
    examples/example1.cpp
)

foreach(EXAMPLE ${EXAMPLES})
    get_filename_component(EXECUTABLE ${EXAMPLE} NAME_WE)
    add_executable(${EXECUTABLE} ${EXAMPLE})
    target_link_libraries(${EXECUTABLE} PRIVATE template)
    configure_file(${EXAMPLE} ${CMAKE_CURRENT_BINARY_DIR}/${EXAMPLE} COPYONLY)

    add_custom_command(OUTPUT ${EXAMPLE}.output
        COMMAND ${CMAKE_COMMAND} -DCOMMAND=$<TARGET_FILE:${EXECUTABLE}> -DOUTPUT_FILE=${EXAMPLE}.output -P ${PROJECT_SOURCE_DIR}/cmake/ExecuteAndCaptureStdout.cmake
        DEPENDS ${EXECUTABLE}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    )
    list(APPEND EXAMPLE_OUTPUT_FILES ${EXAMPLE}.output)
endforeach()

add_custom_target(example_outputs DEPENDS ${EXAMPLE_OUTPUT_FILES})
add_dependencies(docs example_outputs)

if (TEMPLATE_ENABLE_INSTALL)
    install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html
        DESTINATION ${CMAKE_INSTALL_DOCDIR}
    )
endif()
