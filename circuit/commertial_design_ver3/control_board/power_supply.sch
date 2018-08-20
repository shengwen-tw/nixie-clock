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
LIBS:hc06
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
Text HLabel 9450 3850 2    98   Output ~ 0
170V
$Comp
L MC34063A U2
U 1 1 564633D2
P 5450 4900
F 0 "U2" H 4950 5500 98  0000 C CNN
F 1 "MC34063A" V 5450 4950 98  0000 C CNN
F 2 "Power_Integrations:SO-8" H 5450 5500 98  0001 C CNN
F 3 "" H 5450 5500 98  0000 C CNN
	1    5450 4900
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 56463665
P 4350 3850
F 0 "R1" V 4430 3850 50  0000 C CNN
F 1 "0.5ohm" V 4350 3850 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 4280 3850 30  0001 C CNN
F 3 "" H 4350 3850 30  0000 C CNN
	1    4350 3850
	0    -1   -1   0   
$EndComp
$Comp
L R R2
U 1 1 564636F4
P 4350 4050
F 0 "R2" V 4430 4050 50  0000 C CNN
F 1 "0.5ohm" V 4350 4050 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 4280 4050 30  0001 C CNN
F 3 "" H 4350 4050 30  0000 C CNN
	1    4350 4050
	0    -1   -1   0   
$EndComp
$Comp
L R R4
U 1 1 56463737
P 4850 4000
F 0 "R4" V 4930 4000 50  0000 C CNN
F 1 "1k ohm" V 4850 4000 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 4780 4000 30  0001 C CNN
F 3 "" H 4850 4000 30  0000 C CNN
	1    4850 4000
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 56463766
P 6000 4000
F 0 "R5" V 6080 4000 50  0000 C CNN
F 1 "620ohm" V 6000 4000 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 5930 4000 30  0001 C CNN
F 3 "" H 6000 4000 30  0000 C CNN
	1    6000 4000
	1    0    0    -1  
$EndComp
$Comp
L CP1 C2
U 1 1 564637A1
P 2350 4800
F 0 "C2" H 2375 4900 50  0000 L CNN
F 1 "100uf/16v" H 2150 4650 50  0000 L CNN
F 2 "Capacitors_SMD:c_elec_6.3x5.3" H 2350 4800 60  0001 C CNN
F 3 "" H 2350 4800 60  0000 C CNN
	1    2350 4800
	1    0    0    -1  
$EndComp
$Comp
L CP1 C6
U 1 1 56463846
P 8550 4750
F 0 "C6" H 8575 4850 50  0000 L CNN
F 1 "33uf/250v" H 8575 4650 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D13_L21_P5" H 8550 4750 60  0001 C CNN
F 3 "" H 8550 4750 60  0000 C CNN
	1    8550 4750
	1    0    0    -1  
$EndComp
$Comp
L CP1 C7
U 1 1 5646389B
P 9150 4750
F 0 "C7" H 9175 4850 50  0000 L CNN
F 1 "33uf/250v" H 9175 4650 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D13_L21_P5" H 9150 4750 60  0001 C CNN
F 3 "" H 9150 4750 60  0000 C CNN
	1    9150 4750
	1    0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 56463908
P 8150 4300
F 0 "R6" V 8230 4300 50  0000 C CNN
F 1 "100k ohm" V 8150 4300 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 8080 4300 30  0001 C CNN
F 3 "" H 8150 4300 30  0000 C CNN
	1    8150 4300
	1    0    0    -1  
$EndComp
$Comp
L R R7
U 1 1 56463951
P 8150 5250
F 0 "R7" V 8230 5250 50  0000 C CNN
F 1 "750 ohm" V 8150 5250 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 8080 5250 30  0001 C CNN
F 3 "" H 8150 5250 30  0000 C CNN
	1    8150 5250
	1    0    0    -1  
$EndComp
$Comp
L D D1
U 1 1 564639E5
P 6700 4800
F 0 "D1" H 6700 4900 50  0000 C CNN
F 1 "1N4148" H 6700 4700 50  0000 C CNN
F 2 "Diodes_ThroughHole:Diode_DO-35_SOD27_Horizontal_RM10" H 6700 4800 60  0001 C CNN
F 3 "" H 6700 4800 60  0000 C CNN
	1    6700 4800
	-1   0    0    1   
$EndComp
$Comp
L R R3
U 1 1 5646515D
P 4600 5550
F 0 "R3" V 4680 5550 50  0000 C CNN
F 1 "1k ohm" V 4600 5550 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 4530 5550 30  0001 C CNN
F 3 "" H 4600 5550 30  0000 C CNN
	1    4600 5550
	1    0    0    -1  
$EndComp
$Comp
L L_Small L1
U 1 1 564660D5
P 6900 3850
F 0 "L1" V 7050 3950 50  0000 L CNN
F 1 "220uh" V 7050 3600 50  0000 L CNN
F 2 "Inductors:INDUCTOR_V" H 6900 3850 60  0001 C CNN
F 3 "" H 6900 3850 60  0000 C CNN
	1    6900 3850
	0    -1   -1   0   
$EndComp
$Comp
L L_Small L2
U 1 1 56466786
P 8850 3850
F 0 "L2" V 9000 3950 50  0000 L CNN
F 1 "22uh" V 9000 3600 50  0000 L CNN
F 2 "Inductors:INDUCTOR_V" H 8850 3850 60  0001 C CNN
F 3 "" H 8850 3850 60  0000 C CNN
	1    8850 3850
	0    -1   -1   0   
$EndComp
$Comp
L Q_PNP_ECB Q1
U 1 1 56466938
P 6900 5350
F 0 "Q1" H 7200 5400 50  0000 R CNN
F 1 "2SB647" H 7400 5600 50  0000 R CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Narrow_Oval" H 7100 5450 29  0001 C CNN
F 3 "" H 6900 5350 60  0000 C CNN
	1    6900 5350
	1    0    0    1   
$EndComp
$Comp
L Q_NMOS_GDS Q2
U 1 1 56466AEF
P 7350 4800
F 0 "Q2" H 7650 4850 50  0000 R CNN
F 1 "2SK3611" H 8000 4750 50  0000 R CNN
F 2 "TO_SOT_Packages_THT:TO-220_Neutral123_Vertical" H 7550 4900 29  0001 C CNN
F 3 "" H 7350 4800 60  0000 C CNN
	1    7350 4800
	1    0    0    -1  
$EndComp
Text HLabel 1700 5900 0    98   Input ~ 0
GND
Text HLabel 7450 1800 2    98   Output ~ 0
5V
Text HLabel 1700 3850 0    98   Input ~ 0
12V
$Comp
L R R22
U 1 1 578D039C
P 5550 2200
F 0 "R22" V 5630 2200 50  0000 C CNN
F 1 "3k ohm" V 5550 2200 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 5480 2200 30  0001 C CNN
F 3 "" H 5550 2200 30  0000 C CNN
	1    5550 2200
	-1   0    0    1   
$EndComp
$Comp
L R R23
U 1 1 578D04A6
P 5550 2750
F 0 "R23" V 5630 2750 50  0000 C CNN
F 1 "1k ohm" V 5550 2750 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 5480 2750 30  0001 C CNN
F 3 "" H 5550 2750 30  0000 C CNN
	1    5550 2750
	1    0    0    -1  
$EndComp
$Comp
L D_Schottky D2
U 1 1 578D09F1
P 3050 2700
F 0 "D2" H 3050 2800 50  0000 C CNN
F 1 "1N5819" H 3050 2600 50  0000 C CNN
F 2 "Diodes_ThroughHole:Diode_DO-41_SOD81_Horizontal_RM10" H 3050 2700 50  0001 C CNN
F 3 "" H 3050 2700 50  0000 C CNN
	1    3050 2700
	0    1    1    0   
$EndComp
$Comp
L MC34063A U1
U 1 1 578CF876
P 4300 2500
F 0 "U1" H 4300 1950 98  0000 C CNN
F 1 "MC34063A" V 4300 2550 98  0000 C CNN
F 2 "Power_Integrations:SO-8" H 4300 3100 98  0001 C CNN
F 3 "" H 4300 3100 98  0000 C CNN
	1    4300 2500
	1    0    0    -1  
$EndComp
$Comp
L L_Small L3
U 1 1 578D35FA
P 5350 1800
F 0 "L3" V 5500 1900 50  0000 L CNN
F 1 "220uh" V 5500 1550 50  0000 L CNN
F 2 "Inductors:INDUCTOR_V" H 5350 1800 60  0001 C CNN
F 3 "" H 5350 1800 60  0000 C CNN
	1    5350 1800
	0    -1   -1   0   
$EndComp
$Comp
L C C1
U 1 1 578D3968
P 3400 2850
F 0 "C1" H 3425 2950 50  0000 L CNN
F 1 "182p" H 3300 2750 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 3438 2700 30  0001 C CNN
F 3 "" H 3400 2850 60  0000 C CNN
	1    3400 2850
	1    0    0    -1  
$EndComp
$Comp
L R R20
U 1 1 578D6050
P 2600 1900
F 0 "R20" V 2680 1900 50  0000 C CNN
F 1 "0.5ohm" V 2600 1900 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 2530 1900 30  0001 C CNN
F 3 "" H 2600 1900 30  0000 C CNN
	1    2600 1900
	0    -1   -1   0   
$EndComp
$Comp
L R R21
U 1 1 578D6265
P 2600 2100
F 0 "R21" V 2680 2100 50  0000 C CNN
F 1 "0.5ohm" V 2600 2100 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 2530 2100 30  0001 C CNN
F 3 "" H 2600 2100 30  0000 C CNN
	1    2600 2100
	0    -1   -1   0   
$EndComp
Text HLabel 2250 1900 0    98   Input ~ 0
12V
Text HLabel 7450 3200 2    98   Input ~ 0
GND
$Comp
L CP1 C3
U 1 1 578D8B47
P 6050 2450
F 0 "C3" H 6075 2550 50  0000 L CNN
F 1 "680uf/16v" H 5900 2200 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D10_L16_P5" H 6050 2450 60  0001 C CNN
F 3 "" H 6050 2450 60  0000 C CNN
	1    6050 2450
	1    0    0    -1  
$EndComp
$Comp
L L_Small L4
U 1 1 578DC34D
P 6350 1800
F 0 "L4" V 6500 1900 50  0000 L CNN
F 1 "1uh" V 6500 1550 50  0000 L CNN
F 2 "Inductors:INDUCTOR_V" H 6350 1800 60  0001 C CNN
F 3 "" H 6350 1800 60  0000 C CNN
	1    6350 1800
	0    -1   -1   0   
$EndComp
$Comp
L CP1 C5
U 1 1 578DC9B0
P 6650 2450
F 0 "C5" H 6675 2550 50  0000 L CNN
F 1 "680uf/16v" H 6500 2200 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D10_L16_P5" H 6650 2450 60  0001 C CNN
F 3 "" H 6650 2450 60  0000 C CNN
	1    6650 2450
	1    0    0    -1  
$EndComp
$Comp
L D_Schottky D3
U 1 1 578DE80D
P 7800 3850
F 0 "D3" H 7800 3950 50  0000 C CNN
F 1 "FR154" H 7800 3750 50  0000 C CNN
F 2 "Diodes_ThroughHole:Diode_DO-41_SOD81_Horizontal_RM10" H 7800 3850 50  0001 C CNN
F 3 "" H 7800 3850 50  0000 C CNN
	1    7800 3850
	-1   0    0    1   
$EndComp
Text Notes 3050 3350 0    60   ~ 0
190pf -> switching frequency = 100khz (use 182pf  instead) 
Text Notes 3000 6150 0    60   ~ 0
375pf -> switching frequency = 100khz (use 330pf instead)
$Comp
L C C12
U 1 1 579C8704
P 7200 2450
F 0 "C12" H 7225 2550 50  0000 L CNN
F 1 "0.1uf" H 7250 2200 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 7238 2300 50  0001 C CNN
F 3 "" H 7200 2450 50  0000 C CNN
	1    7200 2450
	1    0    0    -1  
$EndComp
$Comp
L C C10
U 1 1 579C9521
P 1900 4800
F 0 "C10" H 1925 4900 50  0000 L CNN
F 1 "0.1uf" H 1550 4650 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 1938 4650 50  0001 C CNN
F 3 "" H 1900 4800 50  0000 C CNN
	1    1900 4800
	1    0    0    -1  
$EndComp
$Comp
L BC557 Q5
U 1 1 57D6CA32
P 3600 5250
F 0 "Q5" H 3500 5400 50  0000 L CNN
F 1 "BC557" H 3400 5500 50  0000 L CNN
F 2 "TO-92_" H 3100 5650 50  0001 L CIN
F 3 "" H 3600 5250 50  0000 L CNN
	1    3600 5250
	-1   0    0    1   
$EndComp
$Comp
L D_Schottky D4
U 1 1 57D6CACB
P 3900 4950
F 0 "D4" H 3900 5050 50  0000 C CNN
F 1 "1N5819 (Replacement for D_Schottky)" H 3850 4850 50  0000 C CNN
F 2 "Diodes_ThroughHole:Diode_DO-35_SOD27_Horizontal_RM10" H 3900 4950 50  0001 C CNN
F 3 "" H 3900 4950 50  0000 C CNN
	1    3900 4950
	1    0    0    1   
$EndComp
$Comp
L C C14
U 1 1 57D6CE9A
P 3250 5250
F 0 "C14" H 3275 5350 50  0000 L CNN
F 1 "330pf" H 3150 5150 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 3288 5100 30  0001 C CNN
F 3 "" H 3250 5250 60  0000 C CNN
	1    3250 5250
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7000 4800 7000 5150
Connection ~ 6450 5350
Wire Wire Line
	6450 4800 6450 5350
Wire Wire Line
	7450 5900 7450 5000
Wire Wire Line
	7450 3850 7450 4600
Connection ~ 9150 3850
Connection ~ 8550 5900
Wire Wire Line
	9150 5900 9150 4900
Wire Wire Line
	9150 3850 9150 4600
Wire Wire Line
	8950 3850 9450 3850
Connection ~ 8550 3850
Connection ~ 8150 5900
Wire Wire Line
	8550 5900 8550 4900
Connection ~ 8150 3850
Wire Wire Line
	8550 3850 8550 4600
Connection ~ 8150 4750
Wire Wire Line
	7850 4750 8150 4750
Wire Wire Line
	7850 5750 7850 4750
Wire Wire Line
	6200 5750 7850 5750
Wire Wire Line
	6200 5150 6200 5750
Wire Wire Line
	6000 5150 6200 5150
Connection ~ 7450 5900
Wire Wire Line
	8150 5900 8150 5400
Wire Wire Line
	8150 4450 8150 5100
Wire Wire Line
	7950 3850 8750 3850
Wire Wire Line
	8150 4150 8150 3850
Connection ~ 7450 3850
Connection ~ 4600 5350
Connection ~ 4600 5900
Wire Wire Line
	4600 5900 4600 5700
Connection ~ 7000 5900
Connection ~ 4850 5900
Wire Wire Line
	7000 5900 7000 5550
Wire Wire Line
	4600 5350 6700 5350
Connection ~ 6200 3850
Wire Wire Line
	4600 4750 4850 4750
Wire Wire Line
	4600 4750 4600 5400
Wire Wire Line
	4850 5900 4850 5150
Wire Wire Line
	6350 3650 6350 4950
Wire Wire Line
	6350 4950 6000 4950
Connection ~ 6000 3850
Wire Wire Line
	6200 4750 6000 4750
Wire Wire Line
	6200 3850 6200 4750
Wire Wire Line
	6000 4150 6000 4550
Connection ~ 4850 3850
Wire Wire Line
	4850 4150 4850 4550
Wire Wire Line
	4200 3850 4200 4050
Wire Wire Line
	4500 3850 4500 4050
Wire Wire Line
	4500 3850 6800 3850
Connection ~ 2350 3850
Wire Wire Line
	2350 5900 2350 4950
Connection ~ 2350 5900
Wire Wire Line
	1700 3850 4200 3850
Wire Wire Line
	6850 4800 7150 4800
Wire Wire Line
	6550 4800 6450 4800
Connection ~ 7000 4800
Wire Wire Line
	3050 2350 3700 2350
Wire Wire Line
	3700 2150 3450 2150
Wire Wire Line
	5050 2350 4850 2350
Wire Wire Line
	4850 2150 5050 2150
Connection ~ 5050 2150
Wire Wire Line
	3700 3200 3700 2750
Connection ~ 3700 3200
Wire Wire Line
	3050 1800 3050 2550
Wire Wire Line
	3700 2550 3400 2550
Connection ~ 3400 3200
Wire Wire Line
	3050 2850 3050 3200
Wire Wire Line
	3450 2150 3450 1900
Wire Wire Line
	2750 1900 5050 1900
Wire Wire Line
	5050 1900 5050 2350
Connection ~ 3050 2350
Wire Wire Line
	5550 2350 5550 2600
Wire Wire Line
	5550 3200 5550 2900
Wire Wire Line
	4850 2750 5350 2750
Wire Wire Line
	5350 2500 5550 2500
Connection ~ 5550 2500
Wire Wire Line
	2350 1700 2350 4650
Wire Wire Line
	2350 3650 6350 3650
Connection ~ 3450 1900
Wire Wire Line
	2750 2100 2750 1900
Wire Wire Line
	2450 1900 2450 2100
Wire Wire Line
	2250 1900 2450 1900
Connection ~ 3050 3200
Wire Wire Line
	2350 1700 5150 1700
Wire Wire Line
	5150 1700 5150 2550
Wire Wire Line
	5150 2550 4850 2550
Connection ~ 2350 1900
Wire Wire Line
	5350 2750 5350 2500
Wire Wire Line
	3050 1800 5250 1800
Wire Wire Line
	5550 1800 5550 2050
Wire Wire Line
	6050 1800 6050 2300
Connection ~ 5550 1800
Wire Wire Line
	6050 3200 6050 2600
Connection ~ 5550 3200
Connection ~ 6050 1800
Connection ~ 6050 3200
Wire Wire Line
	3050 3200 7450 3200
Connection ~ 2350 3650
Wire Wire Line
	5450 1800 6250 1800
Wire Wire Line
	6450 1800 7450 1800
Wire Wire Line
	6650 1800 6650 2300
Wire Wire Line
	6650 3200 6650 2600
Connection ~ 6650 1800
Connection ~ 6650 3200
Wire Wire Line
	7000 3850 7650 3850
Wire Wire Line
	1700 5900 9150 5900
Wire Wire Line
	3400 2550 3400 2700
Wire Wire Line
	3400 3000 3400 3200
Wire Wire Line
	7200 2300 7200 1800
Connection ~ 7200 1800
Wire Wire Line
	7200 3200 7200 2600
Connection ~ 7200 3200
Wire Wire Line
	1900 3850 1900 4650
Connection ~ 1900 3850
Wire Wire Line
	1900 4950 1900 5900
Connection ~ 1900 5900
Wire Wire Line
	3250 4950 3750 4950
Wire Wire Line
	3500 4950 3500 5050
Wire Wire Line
	3800 5250 4100 5250
Wire Wire Line
	3250 4950 3250 5100
Connection ~ 3500 4950
Wire Wire Line
	3500 5450 3500 5500
Wire Wire Line
	3500 5500 3250 5500
Wire Wire Line
	3250 5400 3250 5900
Connection ~ 3250 5900
Connection ~ 3250 5500
Wire Notes Line
	3050 4800 4150 4800
Wire Notes Line
	4150 4800 4150 6000
Wire Notes Line
	4150 6000 3050 6000
Wire Notes Line
	3050 6000 3050 4800
Wire Wire Line
	4050 4950 4850 4950
Wire Wire Line
	4100 5250 4100 4950
Connection ~ 4100 4950
Text Notes 3050 4750 0    60   ~ 0
Ratio extended circuit
$Comp
L LM1117-3.3 U10
U 1 1 589221D9
P 9250 2200
F 0 "U10" H 9350 1950 50  0000 C CNN
F 1 "LM1117-3.3" H 9250 2450 50  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-223" H 9250 2200 50  0001 C CNN
F 3 "" H 9250 2200 50  0000 C CNN
	1    9250 2200
	1    0    0    -1  
$EndComp
Text HLabel 8500 2200 0    98   Input ~ 0
5V
$Comp
L C C11
U 1 1 58922E33
P 8750 2550
F 0 "C11" H 8775 2650 50  0000 L CNN
F 1 "10uf" H 8775 2450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 8788 2400 50  0001 C CNN
F 3 "" H 8750 2550 50  0000 C CNN
	1    8750 2550
	1    0    0    -1  
$EndComp
$Comp
L C C16
U 1 1 58922F4F
P 9750 2550
F 0 "C16" H 9775 2650 50  0000 L CNN
F 1 "10uf" H 9775 2450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 9788 2400 50  0001 C CNN
F 3 "" H 9750 2550 50  0000 C CNN
	1    9750 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	8500 2200 8950 2200
Wire Wire Line
	8750 2400 8750 2200
Connection ~ 8750 2200
Wire Wire Line
	9750 2200 9750 2400
Wire Wire Line
	8750 2700 8750 2900
Wire Wire Line
	8750 2900 9750 2900
Wire Wire Line
	9750 2900 9750 2700
Wire Wire Line
	9250 2500 9250 3100
Connection ~ 9250 2900
Text HLabel 9300 3100 2    98   Input ~ 0
GND
Wire Wire Line
	9250 3100 9300 3100
Connection ~ 9750 2200
Wire Wire Line
	9550 2200 10000 2200
Text HLabel 10000 2200 2    98   Output ~ 0
3V3
$EndSCHEMATC