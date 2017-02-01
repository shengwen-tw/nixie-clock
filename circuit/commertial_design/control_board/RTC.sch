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
Sheet 4 4
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L DS3231 U9
U 1 1 579B911D
P 5900 3250
F 0 "U9" H 6150 3350 60  0000 C CNN
F 1 "DS3231" H 5850 3350 60  0000 C CNN
F 2 "SMD_Packages:SO-16-W" H 6100 3350 60  0001 C CNN
F 3 "" H 6100 3350 60  0000 C CNN
	1    5900 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 3800 6650 3800
Wire Wire Line
	6650 3800 6650 4400
Wire Wire Line
	6450 4400 7250 4400
Wire Wire Line
	6450 4250 6650 4250
Connection ~ 6650 4250
Wire Wire Line
	6450 4100 6650 4100
Connection ~ 6650 4100
Wire Wire Line
	6450 3950 6650 3950
Connection ~ 6650 3950
Wire Wire Line
	5200 3950 5450 3950
Wire Wire Line
	5200 3950 5200 4400
Wire Wire Line
	5000 4400 5450 4400
Wire Wire Line
	5450 4250 5200 4250
Connection ~ 5200 4250
Wire Wire Line
	5450 4100 5200 4100
Connection ~ 5200 4100
Text HLabel 6850 3500 2    60   Input ~ 0
I2C_SDA
Text HLabel 6850 3350 2    60   Input ~ 0
I2C_SCL
Wire Wire Line
	6450 3350 6850 3350
Wire Wire Line
	6850 3500 6450 3500
$Comp
L Battery-RESCUE-nixie_control_board BT1
U 1 1 579B979A
P 7100 3950
F 0 "BT1" H 7200 4000 50  0000 L CNN
F 1 "CR2032" H 7200 3900 50  0000 L CNN
F 2 "CR2032H:CR2032H" V 7100 3990 60  0001 C CNN
F 3 "" V 7100 3990 60  0000 C CNN
	1    7100 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 3650 7100 3650
Wire Wire Line
	7100 3650 7100 3800
Text HLabel 5000 4400 0    60   Input ~ 0
GND
Connection ~ 5200 4400
Text HLabel 7250 4400 2    60   Input ~ 0
GND
Connection ~ 6650 4400
Wire Wire Line
	7100 4100 7100 4400
Connection ~ 7100 4400
Text HLabel 5000 3500 0    60   Input ~ 0
5V
$Comp
L R R17
U 1 1 579B9E3E
P 6750 3100
F 0 "R17" V 6830 3100 50  0000 C CNN
F 1 "4.7k ohm" V 6750 3100 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 6680 3100 30  0001 C CNN
F 3 "" H 6750 3100 30  0000 C CNN
	1    6750 3100
	1    0    0    -1  
$EndComp
$Comp
L R R16
U 1 1 579B9F6D
P 6550 3100
F 0 "R16" V 6630 3100 50  0000 C CNN
F 1 "4.7k ohm" V 6550 3100 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 6480 3100 30  0001 C CNN
F 3 "" H 6550 3100 30  0000 C CNN
	1    6550 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	6750 3250 6750 3350
Connection ~ 6750 3350
Wire Wire Line
	6550 3250 6550 3500
Connection ~ 6550 3500
Wire Wire Line
	6550 2950 6550 2850
Wire Wire Line
	6550 2850 7000 2850
Wire Wire Line
	6750 2850 6750 2950
Text HLabel 7000 2850 2    60   Input ~ 0
5V
Connection ~ 6750 2850
NoConn ~ 5450 3650
NoConn ~ 5450 3350
NoConn ~ 5450 3800
$Comp
L C C4
U 1 1 579BA543
P 5300 3100
F 0 "C4" H 5325 3200 50  0000 L CNN
F 1 "0.1uf" H 5325 3000 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 5338 2950 30  0001 C CNN
F 3 "" H 5300 3100 60  0000 C CNN
	1    5300 3100
	-1   0    0    1   
$EndComp
Connection ~ 5300 3500
Text HLabel 5600 2850 2    60   Input ~ 0
GND
Wire Wire Line
	5600 2850 5300 2850
Wire Wire Line
	5300 2850 5300 2950
Wire Wire Line
	5300 3250 5300 3500
Wire Wire Line
	5000 3500 5450 3500
$EndSCHEMATC
