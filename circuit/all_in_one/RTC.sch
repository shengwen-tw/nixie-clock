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
Sheet 4 5
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 6550 4200 2    60   Input ~ 0
I2C_SCL
Text HLabel 7150 4350 2    60   Input ~ 0
I2C_SDA
Text HLabel 7150 3900 2    60   Input ~ 0
5V
Text HLabel 6850 3550 2    60   Input ~ 0
GND
$Comp
L DS1307 U9
U 1 1 5647D894
P 5800 4150
F 0 "U9" H 5600 4550 60  0000 C CNN
F 1 "DS1307" H 5900 4550 60  0000 C CNN
F 2 "Power_Integrations:SO-8" H 5600 4550 60  0001 C CNN
F 3 "" H 5600 4550 60  0000 C CNN
	1    5800 4150
	1    0    0    -1  
$EndComp
$Comp
L C C10
U 1 1 5647D9A5
P 6600 3550
F 0 "C10" H 6625 3650 50  0000 L CNN
F 1 "0.1uf" H 6625 3450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 6638 3400 30  0001 C CNN
F 3 "" H 6600 3550 60  0000 C CNN
	1    6600 3550
	0    1    1    0   
$EndComp
Wire Wire Line
	6750 3550 6850 3550
Wire Wire Line
	6300 3900 7150 3900
Wire Wire Line
	6450 3550 6300 3550
Wire Wire Line
	6300 3550 6300 3900
NoConn ~ 6300 4050
Wire Wire Line
	6300 4200 6550 4200
Wire Wire Line
	6300 4350 7150 4350
Text HLabel 5100 4350 0    60   Input ~ 0
GND
Wire Wire Line
	5100 4350 5300 4350
$Comp
L Crystal Y2
U 1 1 5647DAEC
P 4850 3950
F 0 "Y2" H 4850 4100 50  0000 C CNN
F 1 "32.768khz" H 4850 3800 50  0000 C CNN
F 2 "Crystals:Crystal_Round_Vertical_2mm" H 4850 3950 60  0001 C CNN
F 3 "" H 4850 3950 60  0000 C CNN
	1    4850 3950
	0    1    1    0   
$EndComp
Wire Wire Line
	4850 3800 4850 3750
Wire Wire Line
	4850 3750 5250 3750
Wire Wire Line
	5250 3750 5250 3900
Wire Wire Line
	5250 3900 5300 3900
Wire Wire Line
	5300 4050 5250 4050
Wire Wire Line
	5250 4050 5250 4150
Wire Wire Line
	5250 4150 4850 4150
Wire Wire Line
	4850 4150 4850 4100
$Comp
L Battery BT1
U 1 1 5647DBD2
P 4500 4200
F 0 "BT1" H 4600 4250 50  0000 L CNN
F 1 "CR1220" H 4600 4150 50  0000 L CNN
F 2 "Connect:CR2032H" V 4500 4240 60  0001 C CNN
F 3 "" V 4500 4240 60  0000 C CNN
	1    4500 4200
	0    1    1    0   
$EndComp
Wire Wire Line
	5300 4200 4650 4200
Text HLabel 4200 4200 0    60   Input ~ 0
GND
Wire Wire Line
	4200 4200 4350 4200
$Comp
L R R17
U 1 1 5647E0E9
P 7050 4150
F 0 "R17" V 7130 4150 50  0000 C CNN
F 1 "4.7k ohm" V 7050 4150 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6980 4150 30  0001 C CNN
F 3 "" H 7050 4150 30  0000 C CNN
	1    7050 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 4000 7050 3900
Connection ~ 7050 3900
Wire Wire Line
	7050 4300 7050 4350
Connection ~ 7050 4350
$Comp
L R R16
U 1 1 5647E182
P 6450 4050
F 0 "R16" V 6530 4050 50  0000 C CNN
F 1 "4.7k ohm" V 6450 4050 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6380 4050 30  0001 C CNN
F 3 "" H 6450 4050 30  0000 C CNN
	1    6450 4050
	1    0    0    -1  
$EndComp
Connection ~ 6450 3900
Connection ~ 6450 4200
$EndSCHEMATC
