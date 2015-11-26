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
F7 "Tube_Anode_1" I R 6900 2700 60 
F8 "Tube_Anode_2" I R 6900 2800 60 
F9 "Tube_Anode_3" I R 6900 2900 60 
F10 "Tube_Anode_4" I R 6900 3000 60 
F11 "Tube_Anode_5" I R 6900 3100 60 
F12 "Tube_Anode_6" I R 6900 3200 60 
F13 "Tube_Anode_7" I R 6900 3300 60 
F14 "Tube_Anode_8" I R 6900 3400 60 
F15 "Tube_Cathode_0" I R 6900 4500 60 
F16 "Tube_Cathode_1" I R 6900 3600 60 
F17 "Tube_Cathode_2" I R 6900 3700 60 
F18 "Tube_Cathode_3" I R 6900 3800 60 
F19 "Tube_Cathode_4" I R 6900 3900 60 
F20 "Tube_Cathode_5" I R 6900 4000 60 
F21 "Tube_Cathode_6" I R 6900 4100 60 
F22 "Tube_Cathode_7" I R 6900 4200 60 
F23 "Tube_Cathode_8" I R 6900 4300 60 
F24 "Tube_Cathode_9" I R 6900 4400 60 
F25 "Tube_Cathode_Comma_Left" I R 6900 4700 60 
F26 "Tube_Cathode_Comma_Right" I R 6900 4800 60 
F27 "MP3_TX" I L 4850 5100 60 
F28 "MP3_RX" I L 4850 5200 60 
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
S 3250 4950 950  800 
U 5646A864
F0 "audio" 98
F1 "audio.sch" 98
F2 "MCU_MP3_TX" I R 4200 5200 60 
F3 "MCU_MP3_RX" I R 4200 5300 60 
$EndSheet
$Sheet
S 7306 2544 1200 2450
U 5646AE2C
F0 "display" 98
F1 "display.sch" 98
F2 "Anode_2" I L 7306 2800 60 
F3 "Anode_1" I L 7306 2700 60 
F4 "Anode_3" I L 7306 2900 60 
F5 "Anode_4" I L 7306 3000 60 
F6 "Anode_5" I L 7306 3100 60 
F7 "Anode_6" I L 7306 3200 60 
F8 "Anode_7" I L 7306 3300 60 
F9 "Anode_8" I L 7306 3400 60 
F10 "Cathode_4" I L 7306 3900 60 
F11 "Cathode_3" I L 7306 3800 60 
F12 "Cathode_2" I L 7306 3700 60 
F13 "Cathode_1" I L 7306 3600 60 
F14 "Cathode_Comma_Right" I L 7306 4800 60 
F15 "Cathode_Comma_Left" I L 7306 4700 60 
F16 "Cathode_5" I L 7306 4000 60 
F17 "Cathode_6" I L 7306 4100 60 
F18 "Cathode_7" I L 7306 4200 60 
F19 "Cathode_8" I L 7306 4300 60 
F20 "Cathode_9" I L 7306 4400 60 
F21 "Cathode_0" I L 7306 4500 60 
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
	7300 2700 6900 2700
Wire Wire Line
	7300 2800 6900 2800
Wire Wire Line
	7300 2900 6900 2900
Wire Wire Line
	7300 3000 6900 3000
Wire Wire Line
	7300 3100 6900 3100
Wire Wire Line
	7300 3200 6900 3200
Wire Wire Line
	7300 3300 6900 3300
Wire Wire Line
	7300 3400 6900 3400
Wire Wire Line
	7300 3600 6900 3600
Wire Wire Line
	7300 3700 6900 3700
Wire Wire Line
	7300 3800 6900 3800
Wire Wire Line
	6900 3900 7300 3900
Wire Wire Line
	7300 4000 6900 4000
Wire Wire Line
	7300 4100 6900 4100
Wire Wire Line
	7300 4200 6900 4200
Wire Wire Line
	7300 4300 6900 4300
Wire Wire Line
	7300 4400 6900 4400
Wire Wire Line
	7300 4500 6900 4500
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
	7300 4700 6900 4700
Wire Wire Line
	7300 4800 6900 4800
Wire Wire Line
	4200 5200 4500 5200
Wire Wire Line
	4500 5200 4500 5100
Wire Wire Line
	4500 5100 4850 5100
Wire Wire Line
	4200 5300 4600 5300
Wire Wire Line
	4600 5300 4600 5200
Wire Wire Line
	4600 5200 4850 5200
Wire Wire Line
	2950 2800 2950 2900
$EndSCHEMATC
