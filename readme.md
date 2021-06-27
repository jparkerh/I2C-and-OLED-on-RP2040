# RP2040, I2C, and a (very) Tiny OLED

![IMG_6335](https://user-images.githubusercontent.com/42722137/123551479-8cc7a780-d737-11eb-85d0-97891ae3b8f2.gif)

### Project Overview

Finally got a chance to bring up the new RP2040 MCU from Raspberry Pi! Brought up this example with the SparkFun micro OLED qwiic board. In order to make it easier to bring up the I2C OLED screen, I built out a (very hacky) port of the I2C part of "TwoWire" to mimic the Arduino library's top level interface. This allowed me to re-use a good portion of the SparkFun OLED library as-is. 
A few changes are made in the fork of the OLED library (see the submodule), extending the library to allow for variable display sizes, single page updates (as oppposed to re-writing the whole array), and removing unsupported debug functions. 
The cmake projects will build out the TwoWire project, main.cpp (The Example), the SparkFun OLED dependency, and a quick scrolling text utility that takes advantage of the ability to wrap the GDRAM buffer (which I'm using to easily visualize data from the board) and gives a terminal-like "println" call. Hoping I can make use of the setup to have a quick debug method to visualize register data on the i2c chain via the screen This does also create a .uf2 you can use to download to the Adafruit board. 
Run setup.sh to install the dependencies for the pico sdk. RP2040 is an awesome platform - looking forward to continuing to work with it.

*Make sure you clone this repo with recurse-submodules turned on to get the pico-sdk. Run setup.sh to get the dependencies installed!*








