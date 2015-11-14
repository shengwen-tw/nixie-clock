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
Sheet 1 6
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
S 3950 3300 950  800 
U 5645F24C
F0 "Sheet5645F24B" 60
F1 "power_supply.sch" 60
F2 "170V" O R 4900 3600 60 
F3 "5V" O R 4900 3800 60 
F4 "12V" I L 3950 3600 60 
F5 "GND" I L 3950 3800 60 
$EndSheet
$Sheet
S 5300 3300 950  800 
U 5645F2A4
F0 "nixie_control" 60
F1 "nixie_control.sch" 60
F2 "170V" I L 5300 3500 60 
F3 "5V" I L 5300 3700 60 
F4 "GND" I L 5300 3900 60 
F5 "I2C_SCL" I R 6250 3500 60 
F6 "I2C_SDA" I R 6250 3700 60 
$EndSheet
$Comp
L CONN_01X02 P1
U 1 1 56461034
P 3400 3700
F 0 "P1" H 3400 3850 50  0000 C CNN
F 1 "CONN_01X02" V 3500 3700 50  0000 C CNN
F 2 "" H 3400 3700 60  0001 C CNN
F 3 "" H 3400 3700 60  0000 C CNN
	1    3400 3700
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3600 3650 3800 3650
Wire Wire Line
	3800 3650 3800 3600
Wire Wire Line
	3800 3600 3950 3600
Wire Wire Line
	3600 3750 3800 3750
Wire Wire Line
	3800 3750 3800 4350
Wire Wire Line
	3800 3800 3950 3800
Connection ~ 3800 3800
$Sheet
S 6700 3300 950  1000
U 5646A754
F0 "RTC" 98
F1 "RTC.sch" 98
F2 "I2C_SCL" I L 6700 3500 60 
F3 "I2C_SDA" I L 6700 3700 60 
F4 "5V" I L 6700 3900 60 
F5 "GND" I L 6700 4100 60 
$EndSheet
$Sheet
S 6700 2100 950  800 
U 5646A864
F0 "audio" 98
F1 "audio.sch" 98
$EndSheet
$Sheet
S 5300 2100 950  800 
U 5646AE2C
F0 "display" 98
F1 "display.sch" 98
$EndSheet
Wire Wire Line
	6700 3500 6250 3500
Wire Wire Line
	6250 3700 6700 3700
Wire Wire Line
	5100 4250 6450 4250
Wire Wire Line
	6450 4250 6450 3900
Wire Wire Line
	6450 3900 6700 3900
Wire Wire Line
	3800 4350 6550 4350
Wire Wire Line
	6550 4350 6550 4100
Wire Wire Line
	6550 4100 6700 4100
Wire Wire Line
	4900 3600 5100 3600
Wire Wire Line
	5100 3600 5100 3500
Wire Wire Line
	5100 3500 5300 3500
Wire Wire Line
	4900 3800 5100 3800
Wire Wire Line
	5100 3700 5100 4250
Wire Wire Line
	5100 3700 5300 3700
Connection ~ 5100 3800
Wire Wire Line
	5300 3900 5200 3900
Wire Wire Line
	5200 3900 5200 4350
Connection ~ 5200 4350
$EndSCHEMATC
