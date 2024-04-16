cmake_minimum_required(VERSION 3.12)
include(pico_sdk_import.cmake)

include(pico_extras_import_optional.cmake)

project(Lamp C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

add_library(diagnostic_controller INTERFACE)
target_sources( diagnostic_controller INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/diagnostic_controller.c
    )
target_include_directories(diagnostic_controller INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}       
    )
target_link_libraries(diagnostic_controller INTERFACE
    hardware_adc
)

add_executable(${PROJECT_NAME}
    main.c
)
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    )
target_link_libraries(${PROJECT_NAME}
    pico_stdlib
    diagnostic_controller
)

pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)

pico_add_extra_outputs(${PROJECT_NAME})

