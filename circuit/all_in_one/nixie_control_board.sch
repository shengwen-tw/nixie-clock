EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:costom
LIBS:nixie_control_board-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 5
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 3250 2400 950  800 
U 5645F24C
F0 "power_supply" 60
F1 "power_supply.sch" 60
F2 "170V" O R 4200 2700 60 
F3 "5V" O R 4200 2900 60 
F4 "12V" I L 3250 2700 60 
F5 "GND" I L 3250 2900 60 
$EndSheet
$Sheet
S 4850 2550 2050 2950
U 5645F2A4
F0 "nixie_control" 60
F1 "nixie_control.sch" 60
F2 "170V" I L 4850 2700 60 
F3 "5V" I L 4850 2800 60 
F4 "GND" I L 4850 2900 60 
F5 "I2C_SCL" I L 4850 3200 60 
F6 "I2C_SDA" I L 4850 3100 60 
$EndSheet
$Sheet
S 3250 3600 950  1000
U 5646A754
F0 "RTC" 98
F1 "RTC.sch" 98
F2 "I2C_SCL" I R 4200 4400 60 
F3 "I2C_SDA" I R 4200 4200 60 
F4 "5V" I R 4200 4000 60 
F5 "GND" I R 4200 3800 60 
$EndSheet
$Sheet
S 7306 2544 1200 2450
U 5646AE2C
F0 "display" 98
F1 "display.sch" 98
$EndSheet
$Comp
L BARREL_JACK CON1
U 1 1 5657C68E
P 2650 2800
F 0 "CON1" H 2650 3050 60  0000 C CNN
F 1 "BARREL_JACK" H 2650 2600 60  0000 C CNN
F 2 "Connect:JACK_ALIM" H 2650 2800 60  0001 C CNN
F 3 "" H 2650 2800 60  0000 C CNN
	1    2650 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2950 2700 3250 2700
Wire Wire Line
	2950 2900 3250 2900
Wire Wire Line
	3100 2900 3100 3400
Wire Wire Line
	4200 2700 4850 2700
Wire Wire Line
	4200 2900 4300 2900
Wire Wire Line
	4300 2900 4300 2800
Wire Wire Line
	4300 2800 4850 2800
Wire Wire Line
	3100 3400 4350 3400
Wire Wire Line
	4350 2900 4350 3800
Wire Wire Line
	4350 2900 4850 2900
Connection ~ 3100 2900
Wire Wire Line
	4600 2800 4600 4000
Wire Wire Line
	4600 4000 4200 4000
Connection ~ 4600 2800
Wire Wire Line
	4350 3800 4200 3800
Connection ~ 4350 3400
Wire Wire Line
	4200 4200 4700 4200
Wire Wire Line
	4700 4200 4700 3100
Wire Wire Line
	4700 3100 4850 3100
Wire Wire Line
	4850 3200 4800 3200
Wire Wire Line
	4800 3200 4800 4400
Wire Wire Line
	4800 4400 4200 4400
Wire Wire Line
	2950 2800 2950 2900
$EndSCHEMATC
