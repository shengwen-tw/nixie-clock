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
LIBS:special
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
LIBS:nixie-custom
EELAYER 24 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
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
L DS1307 U1
U 1 1 53B3EE00
P 5700 3950
F 0 "U1" H 5900 4250 60  0000 C CNN
F 1 "DS1307" H 5550 4250 60  0000 C CNN
F 2 "" H 5950 4200 60  0000 C CNN
F 3 "" H 5950 4200 60  0000 C CNN
	1    5700 3950
	1    0    0    -1  
$EndComp
NoConn ~ 6250 3900
$Comp
L CONN_4 P1
U 1 1 53B3EE5C
P 7650 3950
F 0 "P1" V 7600 3950 50  0000 C CNN
F 1 "CONN_4" V 7700 3950 50  0000 C CNN
F 2 "" H 7650 3950 60  0000 C CNN
F 3 "" H 7650 3950 60  0000 C CNN
	1    7650 3950
	1    0    0    -1  
$EndComp
$Comp
L BATTERY BT1
U 1 1 53B3EE7B
P 4500 4300
F 0 "BT1" H 4500 4500 50  0000 C CNN
F 1 "BATTERY" H 4500 4110 50  0000 C CNN
F 2 "" H 4500 4300 60  0000 C CNN
F 3 "" H 4500 4300 60  0000 C CNN
	1    4500 4300
	-1   0    0    1   
$EndComp
Text GLabel 7150 3800 0    57   UnSpc ~ 0
5V
Text GLabel 7150 3900 0    57   UnSpc ~ 0
GND
Text GLabel 7150 4000 0    57   UnSpc ~ 0
SCL
Text GLabel 7150 4100 0    57   UnSpc ~ 0
SDA
Text GLabel 6400 3800 2    57   UnSpc ~ 0
5V
Text GLabel 4100 4300 0    57   UnSpc ~ 0
GND
Text GLabel 6400 4000 2    57   UnSpc ~ 0
SCL
Text GLabel 6400 4100 2    57   UnSpc ~ 0
SDA
Text GLabel 5100 4100 0    57   UnSpc ~ 0
GND
$Comp
L CRYSTAL X1
U 1 1 53B3F00F
P 3950 3800
F 0 "X1" H 3950 3950 60  0000 C CNN
F 1 "CRYSTAL" H 3950 3650 60  0000 C CNN
F 2 "" H 3950 3800 60  0000 C CNN
F 3 "" H 3950 3800 60  0000 C CNN
	1    3950 3800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7150 3800 7300 3800
Wire Wire Line
	7300 3900 7150 3900
Wire Wire Line
	7300 4000 7150 4000
Wire Wire Line
	7300 4100 7150 4100
Wire Wire Line
	4800 4000 5100 4000
Wire Wire Line
	4100 4300 4200 4300
Wire Wire Line
	6250 3800 6400 3800
Wire Wire Line
	6250 3900 6400 3900
Wire Wire Line
	6400 4000 6250 4000
Wire Wire Line
	6400 4100 6250 4100
Wire Wire Line
	4800 4000 4800 4300
Wire Wire Line
	4200 3900 5100 3900
Wire Wire Line
	4200 3900 4200 4200
Wire Wire Line
	4200 4200 3950 4200
Wire Wire Line
	3950 4200 3950 4100
Wire Wire Line
	3950 3500 3950 3450
Wire Wire Line
	3950 3450 4200 3450
Wire Wire Line
	4200 3450 4200 3800
Wire Wire Line
	4200 3800 5100 3800
$Comp
L C C1
U 1 1 53B3F0BC
P 6450 3450
F 0 "C1" H 6450 3550 40  0000 L CNN
F 1 "C" H 6456 3365 40  0000 L CNN
F 2 "" H 6488 3300 30  0000 C CNN
F 3 "" H 6450 3450 60  0000 C CNN
	1    6450 3450
	0    -1   -1   0   
$EndComp
Text GLabel 6800 3450 2    57   UnSpc ~ 0
GND
Wire Wire Line
	6800 3450 6650 3450
Wire Wire Line
	6250 3450 6250 3800
$EndSCHEMATC
