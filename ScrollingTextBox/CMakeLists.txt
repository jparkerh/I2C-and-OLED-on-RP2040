add_library(ScrollingTextBox
    ${CMAKE_CURRENT_SOURCE_DIR}/ScrollingTextBox.cpp
)

target_link_libraries(ScrollingTextBox
    pico_stdlib
    SparkFun_Micro_OLED_Arduino_Library
)

target_include_directories(ScrollingTextBox PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/
)