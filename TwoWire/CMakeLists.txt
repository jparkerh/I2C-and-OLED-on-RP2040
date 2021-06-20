add_library(TwoWire
    ${CMAKE_CURRENT_SOURCE_DIR}/src/TwoWire.cpp
)

target_link_libraries(TwoWire
    pico_stdlib
    hardware_i2c
)

target_include_directories(TwoWire PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/
)