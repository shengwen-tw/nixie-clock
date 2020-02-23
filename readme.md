## Nixie Clock
* Author : Shengwen Cheng (shengwen1997.tw@gmail.com)
* Special thanks : 張世昌, 楊宗凡, 施翰誠, 周明哲, 王尹辰, 陳冠宇
* Microcontroller : Arduino (ATMega328p-au)

## Introduction

A Russian IN-14 Nixie tube clock which support time display, alram and mp3 playing function 

<img src="https://github.com/shengwen1997/nixie-clock/blob/master/material/demo3.jpg?raw=true" width="50%" height="50%">

<img src="https://github.com/shengwen1997/nixie-clock/blob/master/material/demo4.jpg?raw=true" width="50%" height="50%">

<img src="https://github.com/shengwen1997/nixie-clock/blob/master/material/demo1.jpg?raw=true" width="50%" height="50%">

<img src="https://raw.githubusercontent.com/shengwen1997/Nixie-Clock/master/material/tube.jpg" width="50%" height="50%">

## Firmware dependencies

You must install the following arduino libraries before compiling the firmware (find the zip in firmware directory)

* DFPlayer driver (a modified version of AltSoftwareSerial)
* RTC and Time library

## USBasp driver

1. Download Zadig

2. Select **Options/List All Devices**

3. Select **USBasp**

4. Select **libusbK**

5. Click **Replace Driver**

## Circuit files

The hardware was designed under Kicad 4, any previous version may not work properly.

## BOM
read the [BOM.md](https://github.com/shengwen1997/Nixie-Clock/blob/master/BOM.md) for detailed information
