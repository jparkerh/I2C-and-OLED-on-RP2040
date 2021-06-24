# Quick Intro to the I2C subsystem with RP2040 on the Adafruit Feather

Finally got a chance to bring up the new RP2040 MCU from Raspberry Pi! Captured the getting started process here, as well as a quick example. We'll walk through the I2C subsystem in the Pico SDK, building a logging subsystem to fetch values from an I2C device, and then we'll also use I2C to drive a graph of the outputs to the micro OLED. The example in this repo uses both the SparkFun Razor IMU as an I2C target to fetch accelerometer data, and the SparkFun micro OLED qwiic board for graphing.

*Make sure you clone this repo with recurse-submodules turned on to get the pico-sdk. Run setup.sh to get the dependencies installed!*




