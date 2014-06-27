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
LIBS:nixie-clock-cache
EELAYER 24 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Nixie Clock Control Board"
Date "21 nov 2013"
Rev ""
Comp "Sigma Lab"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L LM7805 U?
U 1 1 52F4EBAC
P 2650 1450
F 0 "U?" H 2800 1254 60  0000 C CNN
F 1 "LM7805" H 2650 1650 60  0000 C CNN
F 2 "" H 2650 1450 60  0000 C CNN
F 3 "" H 2650 1450 60  0000 C CNN
	1    2650 1450
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 52F4EDC4
P 2250 1750
F 0 "C?" H 2250 1850 40  0000 L CNN
F 1 "0.1 uf" H 2256 1665 40  0000 L CNN
F 2 "" H 2288 1600 30  0000 C CNN
F 3 "" H 2250 1750 60  0000 C CNN
	1    2250 1750
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 52F4EDD3
P 3050 1750
F 0 "C?" H 3050 1850 40  0000 L CNN
F 1 "0.1 uf" H 3056 1665 40  0000 L CNN
F 2 "" H 3088 1600 30  0000 C CNN
F 3 "" H 3050 1750 60  0000 C CNN
	1    3050 1750
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 52F4EE14
P 1900 1750
F 0 "C?" H 1900 1850 40  0000 L CNN
F 1 "100 uf" H 1906 1665 40  0000 L CNN
F 2 "" H 1938 1600 30  0000 C CNN
F 3 "" H 1900 1750 60  0000 C CNN
	1    1900 1750
	1    0    0    -1  
$EndComp
Text Notes 1050 2750 0    60   ~ 0
Nixie tube Power Supply
Text Notes 1050 1000 0    60   ~ 0
DC Regulator (12V -> 5V)
$Comp
L ATMEGA328-P IC?
U 1 1 52F4F352
P 5900 2100
F 0 "IC?" H 5150 3350 40  0000 L BNN
F 1 "ATMEGA328-P" H 6300 700 40  0000 L BNN
F 2 "DIL28" H 5900 2100 30  0000 C CIN
F 3 "" H 5900 2100 60  0000 C CNN
	1    5900 2100
	1    0    0    -1  
$EndComp
$Comp
L CRYSTAL X?
U 1 1 52F4F65D
P 10050 2400
F 0 "X?" V 10250 2550 60  0000 C CNN
F 1 "16MHZ" V 10050 2150 60  0000 C CNN
F 2 "" H 10050 2400 60  0000 C CNN
F 3 "" H 10050 2400 60  0000 C CNN
	1    10050 2400
	0    -1   -1   0   
$EndComp
$Comp
L C C?
U 1 1 52F4F745
P 10500 2100
F 0 "C?" H 10500 2200 40  0000 L CNN
F 1 "22pf" V 10350 2000 40  0000 L CNN
F 2 "" H 10538 1950 30  0000 C CNN
F 3 "" H 10500 2100 60  0000 C CNN
	1    10500 2100
	0    -1   -1   0   
$EndComp
$Comp
L C C?
U 1 1 52F4F754
P 10500 2700
F 0 "C?" H 10500 2800 40  0000 L CNN
F 1 "22pf" V 10650 2600 40  0000 L CNN
F 2 "" H 10538 2550 30  0000 C CNN
F 3 "" H 10500 2700 60  0000 C CNN
	1    10500 2700
	0    -1   -1   0   
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 52F4F8A1
P 10100 3200
F 0 "SW?" H 10250 3310 50  0000 C CNN
F 1 "reset button" H 10100 3120 50  0000 C CNN
F 2 "" H 10100 3200 60  0000 C CNN
F 3 "" H 10100 3200 60  0000 C CNN
	1    10100 3200
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 52F4F8B0
P 9650 2850
F 0 "R?" V 9730 2850 40  0000 C CNN
F 1 "10k ohm" V 9657 2851 40  0000 C CNN
F 2 "" V 9580 2850 30  0000 C CNN
F 3 "" H 9650 2850 30  0000 C CNN
	1    9650 2850
	1    0    0    -1  
$EndComp
$Comp
L TLP521 U?
U 1 1 539C4658
P 7400 5500
F 0 "U?" H 7300 6400 60  0000 C CNN
F 1 "TLP521" V 7450 6050 60  0000 C CNN
F 2 "" H 7450 6050 60  0000 C CNN
F 3 "" H 7450 6050 60  0000 C CNN
	1    7400 5500
	0    1    1    0   
$EndComp
$Comp
L TLP521 U?
U 1 1 539C4667
P 6700 5500
F 0 "U?" H 6600 6400 60  0000 C CNN
F 1 "TLP521" V 6750 6050 60  0000 C CNN
F 2 "" H 6750 6050 60  0000 C CNN
F 3 "" H 6750 6050 60  0000 C CNN
	1    6700 5500
	0    1    1    0   
$EndComp
$Comp
L TLP521 U?
U 1 1 539C4676
P 6000 5500
F 0 "U?" H 5900 6400 60  0000 C CNN
F 1 "TLP521" V 6050 6050 60  0000 C CNN
F 2 "" H 6050 6050 60  0000 C CNN
F 3 "" H 6050 6050 60  0000 C CNN
	1    6000 5500
	0    1    1    0   
$EndComp
$Comp
L TLP521 U?
U 1 1 539C4685
P 5300 5500
F 0 "U?" H 5200 6400 60  0000 C CNN
F 1 "TLP521" V 5350 6050 60  0000 C CNN
F 2 "" H 5350 6050 60  0000 C CNN
F 3 "" H 5350 6050 60  0000 C CNN
	1    5300 5500
	0    1    1    0   
$EndComp
$Comp
L CONN_12 P?
U 1 1 539C4A9F
P 9750 6400
F 0 "P?" V 9700 6400 60  0000 C CNN
F 1 "CONN_12" V 9800 6400 60  0000 C CNN
F 2 "" H 9750 6400 60  0000 C CNN
F 3 "" H 9750 6400 60  0000 C CNN
	1    9750 6400
	0    1    1    0   
$EndComp
$Comp
L CONN_8 P?
U 1 1 539C4AAE
P 6850 6650
F 0 "P?" V 6800 6650 60  0000 C CNN
F 1 "CONN_8" V 6900 6650 60  0000 C CNN
F 2 "" H 6850 6650 60  0000 C CNN
F 3 "" H 6850 6650 60  0000 C CNN
	1    6850 6650
	0    1    1    0   
$EndComp
$Comp
L K155ID1 U?
U 1 1 539C535D
P 9300 5500
F 0 "U?" H 9000 6600 60  0000 C CNN
F 1 "K155ID1" V 9200 6050 60  0000 C CNN
F 2 "" H 9300 5500 60  0000 C CNN
F 3 "" H 9300 5500 60  0000 C CNN
	1    9300 5500
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 539C7026
P 2050 2950
F 0 "R?" V 2130 2950 40  0000 C CNN
F 1 "R" V 2057 2951 40  0000 C CNN
F 2 "" V 1980 2950 30  0000 C CNN
F 3 "" H 2050 2950 30  0000 C CNN
	1    2050 2950
	0    -1   -1   0   
$EndComp
$Comp
L CONN_2 P?
U 1 1 539C7194
P 1150 3050
F 0 "P?" V 1100 3050 40  0000 C CNN
F 1 "CONN_2" V 1200 3050 40  0000 C CNN
F 2 "" H 1150 3050 60  0000 C CNN
F 3 "" H 1150 3050 60  0000 C CNN
	1    1150 3050
	-1   0    0    -1  
$EndComp
$Comp
L CONN_2 P?
U 1 1 539C719A
P 1150 3050
F 0 "P?" V 1100 3050 40  0000 C CNN
F 1 "CONN_2" V 1200 3050 40  0000 C CNN
F 2 "" H 1150 3050 60  0000 C CNN
F 3 "" H 1150 3050 60  0000 C CNN
	1    1150 3050
	-1   0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 539C6A40
P 1700 4050
F 0 "SW?" H 1850 4160 50  0000 C CNN
F 1 "SW_PUSH" H 1700 3970 50  0000 C CNN
F 2 "" H 1700 4050 60  0000 C CNN
F 3 "" H 1700 4050 60  0000 C CNN
	1    1700 4050
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 539C6A5A
P 1700 4550
F 0 "SW?" H 1850 4660 50  0000 C CNN
F 1 "SW_PUSH" H 1700 4470 50  0000 C CNN
F 2 "" H 1700 4550 60  0000 C CNN
F 3 "" H 1700 4550 60  0000 C CNN
	1    1700 4550
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 539C6A69
P 1700 5050
F 0 "SW?" H 1850 5160 50  0000 C CNN
F 1 "SW_PUSH" H 1700 4970 50  0000 C CNN
F 2 "" H 1700 5050 60  0000 C CNN
F 3 "" H 1700 5050 60  0000 C CNN
	1    1700 5050
	1    0    0    -1  
$EndComp
$Comp
L HEF42028 U?
U 1 1 53A6F84A
P 4550 4500
F 0 "U?" H 4300 4950 60  0000 C CNN
F 1 "HEF42028" V 4550 4400 60  0000 C CNN
F 2 "" H 4300 4950 60  0000 C CNN
F 3 "" H 4300 4950 60  0000 C CNN
	1    4550 4500
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 53A70A06
P 1900 5900
F 0 "R?" V 1980 5900 40  0000 C CNN
F 1 "R" V 1907 5901 40  0000 C CNN
F 2 "" V 1830 5900 30  0000 C CNN
F 3 "" H 1900 5900 30  0000 C CNN
	1    1900 5900
	0    -1   -1   0   
$EndComp
$Comp
L R R?
U 1 1 53A70A15
P 1900 6100
F 0 "R?" V 1980 6100 40  0000 C CNN
F 1 "R" V 1907 6101 40  0000 C CNN
F 2 "" V 1830 6100 30  0000 C CNN
F 3 "" H 1900 6100 30  0000 C CNN
	1    1900 6100
	0    -1   -1   0   
$EndComp
$Comp
L CONN_2 P?
U 1 1 53A70C0C
P 2800 6000
F 0 "P?" V 2750 6000 40  0000 C CNN
F 1 "CONN_2" V 2850 6000 40  0000 C CNN
F 2 "" H 2800 6000 60  0000 C CNN
F 3 "" H 2800 6000 60  0000 C CNN
	1    2800 6000
	1    0    0    -1  
$EndComp
Text Notes 1050 5750 0    60   ~ 0
Garan MP3 module
$Comp
L NPN Q?
U 1 1 53A82B75
P 9050 5650
F 0 "Q?" H 9050 5500 50  0000 R CNN
F 1 "NPN" H 9050 5800 50  0000 R CNN
F 2 "" H 9050 5650 60  0000 C CNN
F 3 "" H 9050 5650 60  0000 C CNN
	1    9050 5650
	1    0    0    1   
$EndComp
$Comp
L CONN_4 P?
U 1 1 53A82EF7
P 2300 7000
F 0 "P?" V 2250 7000 50  0000 C CNN
F 1 "CONN_4" V 2350 7000 50  0000 C CNN
F 2 "" H 2300 7000 60  0000 C CNN
F 3 "" H 2300 7000 60  0000 C CNN
	1    2300 7000
	1    0    0    -1  
$EndComp
Text Notes 1050 6750 0    60   ~ 0
Bluetooth module\n
$Comp
L CONN_2 P?
U 1 1 53AD247D
P 1150 1450
F 0 "P?" V 1100 1450 40  0000 C CNN
F 1 "CONN_2" V 1200 1450 40  0000 C CNN
F 2 "" H 1150 1450 60  0000 C CNN
F 3 "" H 1150 1450 60  0000 C CNN
	1    1150 1450
	-1   0    0    -1  
$EndComp
$Comp
L CONN_2 P?
U 1 1 53AD2483
P 1150 1450
F 0 "P?" V 1100 1450 40  0000 C CNN
F 1 "CONN_2" V 1200 1450 40  0000 C CNN
F 2 "" H 1150 1450 60  0000 C CNN
F 3 "" H 1150 1450 60  0000 C CNN
	1    1150 1450
	-1   0    0    -1  
$EndComp
Text GLabel 3350 1400 2    60   UnSpc ~ 0
5V
Text GLabel 3350 2100 2    60   UnSpc ~ 0
GND
Text GLabel 2600 3150 2    60   UnSpc ~ 0
GND
Text GLabel 2600 2950 2    60   UnSpc ~ 0
170V
Wire Wire Line
	2650 2100 2650 1700
Connection ~ 3050 2100
Connection ~ 1500 1150
Connection ~ 1900 2100
Wire Wire Line
	1900 1950 1900 2100
Connection ~ 1900 1150
Wire Wire Line
	1900 1150 1900 1550
Connection ~ 2650 2100
Wire Wire Line
	3050 2100 3050 1950
Connection ~ 2250 1400
Wire Wire Line
	1500 1150 2250 1150
Connection ~ 2250 2100
Wire Wire Line
	2250 2100 2250 1950
Wire Wire Line
	2250 1150 2250 1550
Wire Wire Line
	1500 1550 1500 2100
Wire Wire Line
	1500 2100 3350 2100
Wire Wire Line
	2150 5900 2450 5900
Wire Wire Line
	2150 6100 2450 6100
Wire Wire Line
	3050 1550 3050 1400
Wire Wire Line
	1500 1350 1500 1150
Wire Wire Line
	3050 1400 3350 1400
Wire Wire Line
	1800 2950 1500 2950
Wire Wire Line
	2300 2950 2600 2950
Wire Wire Line
	2600 3150 1500 3150
Wire Notes Line
	1000 850  3650 850 
Wire Notes Line
	3650 850  3650 2250
Wire Notes Line
	3650 2250 1000 2250
Wire Notes Line
	1000 2250 1000 850 
Wire Notes Line
	1000 2600 1000 3300
Wire Notes Line
	1000 3300 2950 3300
Wire Notes Line
	2950 3300 2950 2600
Wire Notes Line
	2950 2600 1000 2600
Text GLabel 1200 4050 0    60   UnSpc ~ 0
5V
Text GLabel 1200 4550 0    60   UnSpc ~ 0
5V
Text GLabel 1200 5050 0    60   UnSpc ~ 0
5V
Wire Wire Line
	1200 4050 1400 4050
Wire Wire Line
	1400 4550 1200 4550
Wire Wire Line
	1400 5050 1200 5050
$Comp
L R R?
U 1 1 53AD2957
P 2400 4050
F 0 "R?" V 2480 4050 40  0000 C CNN
F 1 "R" V 2407 4051 40  0000 C CNN
F 2 "" V 2330 4050 30  0000 C CNN
F 3 "" H 2400 4050 30  0000 C CNN
	1    2400 4050
	0    -1   -1   0   
$EndComp
$Comp
L R R?
U 1 1 53AD2964
P 2400 4550
F 0 "R?" V 2480 4550 40  0000 C CNN
F 1 "R" V 2407 4551 40  0000 C CNN
F 2 "" V 2330 4550 30  0000 C CNN
F 3 "" H 2400 4550 30  0000 C CNN
	1    2400 4550
	0    -1   -1   0   
$EndComp
$Comp
L R R?
U 1 1 53AD296A
P 2400 5050
F 0 "R?" V 2480 5050 40  0000 C CNN
F 1 "R" V 2407 5051 40  0000 C CNN
F 2 "" V 2330 5050 30  0000 C CNN
F 3 "" H 2400 5050 30  0000 C CNN
	1    2400 5050
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2000 4050 2150 4050
Wire Wire Line
	2000 4550 2150 4550
Wire Wire Line
	2000 5050 2150 5050
Text GLabel 2750 4050 2    60   UnSpc ~ 0
GND
Text GLabel 2750 4550 2    60   UnSpc ~ 0
GND
Text GLabel 2750 5050 2    60   UnSpc ~ 0
GND
Wire Wire Line
	2650 4050 2750 4050
Wire Wire Line
	2650 4550 2750 4550
Wire Wire Line
	2650 5050 2750 5050
Text GLabel 2300 3800 2    60   UnSpc ~ 0
Search button
Text GLabel 2300 4300 2    60   UnSpc ~ 0
Adjust button
Text GLabel 2400 4800 2    60   UnSpc ~ 0
Mode button
Wire Wire Line
	2300 3800 2000 3800
Wire Wire Line
	2000 3800 2000 4050
Wire Wire Line
	2300 4300 2000 4300
Wire Wire Line
	2000 4300 2000 4550
Wire Wire Line
	2400 4800 2000 4800
Wire Wire Line
	2000 4800 2000 5050
Text Notes 1050 3750 0    60   ~ 0
Buttons
Wire Notes Line
	1000 3600 3100 3600
Wire Notes Line
	3100 3600 3100 5250
Wire Notes Line
	3100 5250 1000 5250
Wire Notes Line
	1000 5250 1000 3600
Text GLabel 7050 3000 2    57   UnSpc ~ 0
Search button
Wire Wire Line
	7050 3000 6900 3000
Text GLabel 7050 2900 2    57   UnSpc ~ 0
Adjust button
Wire Wire Line
	7050 2900 6900 2900
Text GLabel 7050 2800 2    57   UnSpc ~ 0
Mode button
Wire Wire Line
	7050 2800 6900 2800
Text GLabel 1650 6950 0    57   UnSpc ~ 0
Bluetooth Tx
Text GLabel 1650 6850 0    57   UnSpc ~ 0
Bluetooth Rx
Wire Notes Line
	1000 5600 3000 5600
Wire Notes Line
	3000 5600 3000 6250
Wire Notes Line
	3000 6250 1000 6250
Wire Notes Line
	1000 6250 1000 5600
Wire Wire Line
	1650 6950 1950 6950
Wire Wire Line
	1650 6850 1950 6850
Text GLabel 7050 2600 2    57   UnSpc ~ 0
Bluetooth Tx
Wire Wire Line
	7050 2600 6900 2600
Text GLabel 7050 2700 2    57   UnSpc ~ 0
Bluetooth Rx
Wire Wire Line
	6900 2700 7050 2700
Text GLabel 1650 7150 0    57   UnSpc ~ 0
5V
Text GLabel 1650 7050 0    57   UnSpc ~ 0
GND
Wire Wire Line
	1650 7050 1950 7050
Wire Wire Line
	1950 7150 1650 7150
Wire Notes Line
	1000 6600 2450 6600
Wire Notes Line
	2450 6600 2450 7300
Wire Notes Line
	2450 7300 1000 7300
Wire Notes Line
	1000 7300 1000 6600
Text GLabel 1500 5900 0    60   UnSpc ~ 0
MP3 Tx
Text GLabel 1500 6100 0    60   UnSpc ~ 0
MP3 Rx
Wire Wire Line
	1650 5900 1500 5900
Wire Wire Line
	1650 6100 1500 6100
Text GLabel 7050 2050 2    57   UnSpc ~ 0
MP3 Tx
Text GLabel 7050 2150 2    57   UnSpc ~ 0
MP3 Rx
Wire Wire Line
	7050 2050 6900 2050
Wire Wire Line
	7050 2150 6900 2150
$EndSCHEMATC
