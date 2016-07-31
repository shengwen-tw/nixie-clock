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
Sheet 1 4
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
S 4450 2450 950  800 
U 5645F24C
F0 "power_supply" 60
F1 "power_supply.sch" 60
F2 "170V" O R 5400 2750 60 
F3 "5V" O R 5400 2950 60 
F4 "12V" I L 4450 2750 60 
F5 "GND" I L 4450 2950 60 
$EndSheet
$Sheet
S 6050 2600 2050 2950
U 5645F2A4
F0 "nixie_control" 60
F1 "nixie_control.sch" 60
F2 "170V" I L 6050 2750 60 
F3 "5V" I L 6050 2850 60 
F4 "GND" I L 6050 2950 60 
F5 "I2C_SCL" I L 6050 3250 60 
F6 "I2C_SDA" I L 6050 3150 60 
$EndSheet
$Sheet
S 4450 3650 950  1000
U 5646A754
F0 "RTC" 98
F1 "RTC.sch" 98
F2 "I2C_SCL" I R 5400 4450 60 
F3 "I2C_SDA" I R 5400 4250 60 
F4 "5V" I R 5400 4050 60 
F5 "GND" I R 5400 3850 60 
$EndSheet
$Comp
L BARREL_JACK CON1
U 1 1 5657C68E
P 3850 2850
F 0 "CON1" H 3850 3100 60  0000 C CNN
F 1 "BARREL_JACK" H 3850 2650 60  0000 C CNN
F 2 "FIXED_POWER_JACK:JACK_ALIM" H 3850 2850 60  0001 C CNN
F 3 "" H 3850 2850 60  0000 C CNN
	1    3850 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 2750 4450 2750
Wire Wire Line
	4150 2950 4450 2950
Wire Wire Line
	4300 2950 4300 3450
Wire Wire Line
	5400 2750 6050 2750
Wire Wire Line
	5400 2950 5500 2950
Wire Wire Line
	5500 2950 5500 2850
Wire Wire Line
	5500 2850 6050 2850
Wire Wire Line
	4300 3450 5550 3450
Wire Wire Line
	5550 2950 5550 3850
Wire Wire Line
	5550 2950 6050 2950
Connection ~ 4300 2950
Wire Wire Line
	5800 2850 5800 4050
Wire Wire Line
	5800 4050 5400 4050
Connection ~ 5800 2850
Wire Wire Line
	5550 3850 5400 3850
Connection ~ 5550 3450
Wire Wire Line
	5400 4250 5900 4250
Wire Wire Line
	5900 4250 5900 3150
Wire Wire Line
	5900 3150 6050 3150
Wire Wire Line
	6050 3250 6000 3250
Wire Wire Line
	6000 3250 6000 4450
Wire Wire Line
	6000 4450 5400 4450
Wire Wire Line
	4150 2850 4150 2950
$EndSCHEMATC
