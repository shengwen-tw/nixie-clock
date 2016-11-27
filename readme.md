#Information
* Project name : Nixie Clock
* Developer : Shengwen Cheng (shengwen1997.tw@gmail.com)
* Thanks to : 張世昌, 楊宗凡, 施翰誠, Ming, JackABK, 陳冠宇 and those people who gave me advice
* Microcontroller : ATMega328p-au with arduino nano bootloader

#Introduction
An old school nixie tube display clock which support clock mode, alarm mode and mp3 player mode

<img src="https://github.com/shengwen1997/nixie-clock/blob/master/material/demo2.jpg?raw=true" width="50%" height="50%">

<img src="https://github.com/shengwen1997/nixie-clock/blob/master/material/demo1.jpg?raw=true" width="50%" height="50%">

<img src="https://raw.githubusercontent.com/shengwen1997/Nixie-Clock/master/material/tube.jpg" width="324px" height="216px">

#Import the required libraries

Use Arduino IDE to import the following libraries (Find the zip file in the project)

* DFPlayer driver with AltSoftwareSerial implementation
* RTC and Time library

#Circuit files
All circuit files was drew under the KiCad 4.1.2, the legacy version could not load the circuit properlly

###Convert format svg to pdf (No need anymore)

Here provide a better way to print out the circuit (print with pdf format):

* Make sure you already installed the application:

  **sudo apt-get install librsvg2-bin**
* Now, you can convert the file with command:

  **rsvg-convert -f pdf -o output.pdf input.svg**

#Burn the bootloader

```
avrdude -c avrisp2 -P usb -u -p atmega328p -U lfuse:w:0xff:m -U hfuse:w:0xd9:m -U efuse:w:0x05:m
```

#Pinout

#Bluetooth serial command (ASCII format)
####Time set command

| start byte | year | year | year | year | month | month | day | day | hour | hour | min | min | sec | sec |
|------------|-------|-------|-------|-------|--------|--------|------|------|-------|-------|---------|---------|---------|---------|
| @          | 1     | 9     | 9     | 7     | 0      | 8      | 1    | 2    | 1     | 9     | 4       | 4       | 0       | 0       |

which means 1997/8/12 19:44:00

####Alarm  set command

| start byte | index | index | hour | hour | min | min |
|------------|-------|-------|------|------|-----|-----|
| $          | 0     | 0     | 1    | 2    | 0   | 8   |

which means set alarm(index 0) to 12:00

####Alarm state set command

| start byte | index | state |
|------------|-------|-------|
| +          | 0     | 1     |

which means enable alarm index 0 (1 = ENABLED, 0 = DISABLED)

####Alarm time request command

**Request for hour information**

| start byte |   |   |
|------------|---|---|
| *          | 1 | 9 |

clock will return message like : "12", which mean hour = 12

**Request for minute information**

| start byte |   |   |
|------------|---|---|
| *          | 4 | 4 |

clock will return message like : "33", which mean minute = 33

**Request for state information**

| start byte |   |   |
|------------|---|---|
| *          | 1 | 7 |

clock will return message like : "1", which mean state = ENABLED

####MP3 volume set command

| start byte | volume | volume |
|------------|--------|--------|
| {          | 1      | 5      |

which means set MP3 player volume to 15 (Volume's range is from 0 to 30)

####Alarm volume set command

| start byte | volume | volume |
|------------|--------|--------|
| }          | 1      | 5      |

which means set alarm volume to 15 (Volume's range is from 0 to 30)

####Music command

**Enable Music loop play**

| start byte |   |   |   |   |   |   |
|------------|---|---|---|---|---|---|
| ~          | l | o | o | p | - | o |

**Disable Music loop play**

| start byte |   |   |   |   |   |   |
|------------|---|---|---|---|---|---|
| ~          | l | o | o | p | - | x |

**Play random music**

| start byte |   |   |   |   |   |   |
|------------|---|---|---|---|---|---|
| ~          | r | a | n | d | o | m |

Clock will ignore command and return message "1" while playing alarm music, otherwise will return "0" message

**Sop playing music**

| start byte |   |   |   |   |   |   |
|------------|---|---|---|---|---|---|
| ~          | s | t | o | p | - | - |

Clock will ignore command and return message "1" while playing alarm music, otherwise will return "0" message 

**Play next music**

| start byte |   |   |   |   |   |   |
|------------|---|---|---|---|---|---|
| ~          | n | e | x | t | - | - |

Clock will ignore command and return message "1" while playing alarm music, otherwise will return "0" message

**Play last music**

| start byte |   |   |   |   |   |   |
|------------|---|---|---|---|---|---|
| ~          | l | a | s | t | - | - |

Clock will ignore command and return message "1" while playing alarm music, otherwise will return "0" message

**Play music to demonstrate the alarm volume**

| start byte |   |   |   |   |   |   |
|------------|---|---|---|---|---|---|
| ~          | a | l | - | t | r | y |

Clock will ignore command and return message "1" while playing alarm music, otherwise will return "0" message

####Synchronization command

| start byte |   |   |   |   |   |   |   |   |   |   |   |
|------------|---|---|---|---|---|---|---|---|---|---|---|
| !          | m | p | 3 | - | v | o | l | u | m | e | - |

clock will return the MP3 player volume like "08" which means volume = 8 (Rang is from 0 to 30)

| start byte |   |   |   |   |   |   |   |   |   |   |   |
|------------|---|---|---|---|---|---|---|---|---|---|---|
| !          | m | u | s | i | c | - | l | o | o | p | - |

clock will return the alarm volume like "08" which means volume = 8 (Rang is from 0 to 30)

| start byte |   |   |   |   |   |   |   |   |   |   |   |
|------------|---|---|---|---|---|---|---|---|---|---|---|
| !          | h | i | b | e | r | n | a | t | e | - | - |

clock will return the time like "013007301" which means hibernate from 1:30 to 7:30 and enabled mode is on

| start byte |   |   |   |   |   |   |   |   |   |   |   |
|------------|---|---|---|---|---|---|---|---|---|---|---|
| !          | h | i | b | - | e | n | a | b | l | e | d |

clock will return the hibernation state like "1" which means ENABLED

####Hibernation set command

| start byte | start_hr | start_hr | start_min | start_min | end_hr | end_hr | end_min | end_min | state |
|------------|----------|----------|-----------|-----------|--------|--------|---------|---------|-------|
| %          | 0        | 1        | 3         | 0         | 0      | 7      | 3       | 0       | 1     |

which means set hibernation time from 1:30 to 7:30 and enabled mode is on

####Hibernation state set command

| start byte | state |
|------------|-------|
| ^          | 1     |

which mean set hibernation mode to ENABLED

#BOM
To get more informations, please read the [BOM.md](https://github.com/shengwen1997/Nixie-Clock/blob/master/BOM.md)
