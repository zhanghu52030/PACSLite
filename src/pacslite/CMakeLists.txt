file(GLOB SRCS
    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
    ../defs/error_code.h
    ../defs/schema.h)
	
    set(LIBS
    base
    webcc
    jsoncpp
    )

set(EXE_TARGET_NAME pacslite)
add_executable(${EXE_TARGET_NAME} ${SRCS})
target_link_libraries(${EXE_TARGET_NAME} ${LIBS})

