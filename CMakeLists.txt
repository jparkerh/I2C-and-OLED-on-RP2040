cmake_minimum_required(VERSION 3.3)

# initialize pico-sdk from submodule
# note: this must happen before project()
include(pico-sdk/pico_sdk_init.cmake)

project(i2c_read_write_oled)

set(PICO_BOARD adafruit_feather_rp2040)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

add_subdirectory(TwoWire)
add_subdirectory(SparkFun_Micro_OLED_Arduino_Library)
add_subdirectory(ScrollingTextBox)

AUX_SOURCE_DIRECTORY(./src src_files)

add_executable(i2c_read_write_oled
    ${src_files}
)

pico_enable_stdio_usb(i2c_read_write_oled 1)
pico_enable_stdio_uart(i2c_read_write_oled 0)

target_link_libraries(i2c_read_write_oled
    ScrollingTextBox
)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(i2c_read_write_oled)