cmake_minimum_required(VERSION 3.15)

execute_process(COMMAND ${COMMAND} ${ARGS} OUTPUT_FILE ${OUTPUT_FILE} RESULT_VARIABLE RESULT)
