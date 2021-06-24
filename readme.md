# RP2040, I2C, and a (very) Tiny OLED

Finally got a chance to bring up the new RP2040 MCU from Raspberry Pi! Captured the getting started process here, as well as a quick example. We'll walk through the I2C subsystem in the Pico SDK, building a logging subsystem to fetch values from an I2C device, and then we'll also use I2C to drive a graph of the outputs to the micro OLED. The example in this repo uses both the SparkFun Razor IMU as an I2C target to fetch accelerometer data, and the SparkFun micro OLED qwiic board for graphing.

*Make sure you clone this repo with recurse-submodules turned on to get the pico-sdk. Run setup.sh to get the dependencies installed!*

## Project Overview

In order to make it easier to bring up the I2C OLED screen, I built out a (very hacky) port of the I2C part of "TwoWire" to mimic the Arduino library's top level interface. This allowed me to used a good portion of the SparkFun OLED library as-is. A few changes are made in the fork of the OLED library (see the submodule), mainly just to remove debug print calls for which I didn't build an interface to RP2040. The cmake projects will build out the TwoWire project, main.cpp (The Example), and the SparkFun OLED dependency - and generate a .uf2 for download to the Adafruit board.

Super rough - but it works! RP2040 is an awesome platform - looking forward to continuing to work with it. 


