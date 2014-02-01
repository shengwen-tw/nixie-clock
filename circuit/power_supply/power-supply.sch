EESchema Schematic File Version 2  date 2014年02月01日 (週六) 20時24分48秒
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
LIBS:power-custom
LIBS:power-supply-cache
EELAYER 25  0
EELAYER END
$Descr A4 11700 8267
encoding utf-8
Sheet 1 1
Title ""
Date "1 feb 2014"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	9200 5000 2450 5000
Wire Wire Line
	3350 4350 3350 4000
Wire Wire Line
	3350 4000 4050 4000
Wire Wire Line
	2850 2900 5600 2900
Wire Wire Line
	2850 2900 2850 4000
Connection ~ 2850 5000
Wire Wire Line
	8900 3100 8700 3100
Connection ~ 2850 3100
Wire Wire Line
	5600 2900 5600 4000
Wire Wire Line
	5600 4000 5200 4000
Connection ~ 5200 3100
Connection ~ 7650 5000
Wire Wire Line
	8100 4250 8100 5000
Wire Wire Line
	5200 4150 5500 4150
Wire Wire Line
	5500 4150 5500 4750
Wire Wire Line
	5500 4750 7300 4750
Wire Wire Line
	7300 4750 7300 4100
Connection ~ 7650 4100
Wire Wire Line
	7300 4100 7650 4100
Connection ~ 6950 5000
Wire Wire Line
	6950 5000 6950 3800
Wire Wire Line
	3850 3850 3850 4500
Wire Wire Line
	3850 3850 4050 3850
Connection ~ 5400 3100
Wire Wire Line
	5200 3850 5400 3850
Wire Wire Line
	5400 3850 5400 3100
Connection ~ 6400 3600
Wire Wire Line
	6400 3900 6400 3600
Connection ~ 6950 3100
Wire Wire Line
	6950 3400 6950 3100
Connection ~ 7650 3100
Wire Wire Line
	7650 3450 7650 3100
Wire Wire Line
	8100 3850 8100 3100
Wire Wire Line
	7100 3100 6550 3100
Wire Wire Line
	8100 3100 7500 3100
Wire Wire Line
	8700 3100 8700 3850
Wire Wire Line
	7650 4250 7650 3950
Wire Wire Line
	6250 3600 6650 3600
Wire Wire Line
	6100 4100 5850 4100
Wire Wire Line
	5200 3600 5200 3700
Wire Wire Line
	7650 5000 7650 4750
Wire Wire Line
	4050 4150 3800 4150
Wire Wire Line
	3800 4150 3800 5000
Connection ~ 4200 5000
Wire Wire Line
	6400 5000 6400 4300
Connection ~ 6400 5000
Wire Wire Line
	5850 3600 5850 4500
Wire Wire Line
	5850 4500 3850 4500
Connection ~ 4200 4500
Connection ~ 5850 4100
Connection ~ 8100 5000
Connection ~ 3800 5000
Wire Wire Line
	2850 5000 2850 4400
Connection ~ 3350 5000
Wire Wire Line
	4050 3600 4050 3700
Wire Wire Line
	8700 5000 8700 4250
Connection ~ 8700 5000
Wire Wire Line
	5950 3100 2600 3100
Wire Wire Line
	3350 4750 3350 5000
Text GLabel 2600 3100 0    60   Input ~ 0
12V
$Comp
L INDUCTOR L?
U 1 1 52ECE279
P 8400 3100
F 0 "L?" V 8350 3100 40  0000 C CNN
F 1 "INDUCTOR" V 8500 3100 40  0000 C CNN
	1    8400 3100
	0    -1   -1   0   
$EndComp
$Comp
L INDUCTOR L?
U 1 1 52ECE276
P 6250 3100
F 0 "L?" V 6200 3100 40  0000 C CNN
F 1 "INDUCTOR" V 6350 3100 40  0000 C CNN
	1    6250 3100
	0    -1   -1   0   
$EndComp
Text GLabel 8900 3100 2    60   Output ~ 0
+170V
$Comp
L GND #PWR01
U 1 1 52ECE132
P 9200 5000
F 0 "#PWR01" H 9200 5000 30  0001 C CNN
F 1 "GND" H 9200 4930 30  0001 C CNN
	1    9200 5000
	0    -1   -1   0   
$EndComp
$Comp
L R R?
U 1 1 52ECE108
P 7650 4500
F 0 "R?" V 7730 4500 50  0000 C CNN
F 1 "R" V 7650 4500 50  0000 C CNN
	1    7650 4500
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 52ECE106
P 7650 3700
F 0 "R?" V 7730 3700 50  0000 C CNN
F 1 "R" V 7650 3700 50  0000 C CNN
	1    7650 3700
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 52ECE103
P 5200 3350
F 0 "R?" V 5280 3350 50  0000 C CNN
F 1 "R" V 5200 3350 50  0000 C CNN
	1    5200 3350
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 52ECE101
P 4050 3350
F 0 "R?" V 4130 3350 50  0000 C CNN
F 1 "R" V 4050 3350 50  0000 C CNN
	1    4050 3350
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 52ECE0FB
P 4200 4750
F 0 "R?" V 4280 4750 50  0000 C CNN
F 1 "R" V 4200 4750 50  0000 C CNN
	1    4200 4750
	1    0    0    -1  
$EndComp
$Comp
L CP1 C?
U 1 1 52ECE0DF
P 8700 4050
F 0 "C?" H 8750 4150 50  0000 L CNN
F 1 "CP1" H 8750 3950 50  0000 L CNN
	1    8700 4050
	1    0    0    -1  
$EndComp
$Comp
L CP1 C?
U 1 1 52ECE0D9
P 8100 4050
F 0 "C?" H 8150 4150 50  0000 L CNN
F 1 "CP1" H 8150 3950 50  0000 L CNN
	1    8100 4050
	1    0    0    -1  
$EndComp
$Comp
L DIODE D?
U 1 1 52ECE0D3
P 6050 3600
F 0 "D?" H 6050 3700 40  0000 C CNN
F 1 "DIODE" H 6050 3500 40  0000 C CNN
	1    6050 3600
	1    0    0    -1  
$EndComp
$Comp
L DIODE D?
U 1 1 52ECE0D1
P 7300 3100
F 0 "D?" H 7300 3200 40  0000 C CNN
F 1 "DIODE" H 7300 3000 40  0000 C CNN
	1    7300 3100
	1    0    0    -1  
$EndComp
$Comp
L PNP Q?
U 1 1 52ECE0A1
P 6300 4100
F 0 "Q?" H 6300 3950 60  0000 R CNN
F 1 "PNP" H 6300 4250 60  0000 R CNN
	1    6300 4100
	1    0    0    1   
$EndComp
$Comp
L C C?
U 1 1 52ECE02C
P 3350 4550
F 0 "C?" H 3400 4650 50  0000 L CNN
F 1 "C" H 3400 4450 50  0000 L CNN
	1    3350 4550
	1    0    0    -1  
$EndComp
$Comp
L CP1 C?
U 1 1 52ECE01C
P 2850 4200
F 0 "C?" H 2900 4300 50  0000 L CNN
F 1 "CP1" H 2900 4100 50  0000 L CNN
	1    2850 4200
	1    0    0    -1  
$EndComp
$Comp
L MOS_N Q?
U 1 1 52ECDF19
P 6850 3600
F 0 "Q?" H 6860 3770 60  0000 R CNN
F 1 "MOS_N" H 6860 3450 60  0000 R CNN
	1    6850 3600
	1    0    0    -1  
$EndComp
$Comp
L MCS34063A U?
U 1 1 52ECDE52
P 4600 4050
F 0 "U?" H 4300 4600 60  0000 C CNN
F 1 "MCS34063A" H 4700 4600 60  0000 C CNN
	1    4600 4050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 52ECDB44
P 2450 5000
F 0 "#PWR02" H 2450 5000 30  0001 C CNN
F 1 "GND" H 2450 4930 30  0001 C CNN
	1    2450 5000
	0    1    1    0   
$EndComp
$EndSCHEMATC
