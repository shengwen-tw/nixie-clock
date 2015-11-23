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
Sheet 3 6
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 1250 3850 0    98   Input ~ 0
170V
Text HLabel 7700 1450 0    98   Input ~ 0
5V
Text HLabel 7700 3550 0    98   Input ~ 0
GND
$Comp
L ATMEGA328P-A IC1
U 1 1 5646C06F
P 8850 2550
F 0 "IC1" H 8100 3800 40  0000 L BNN
F 1 "ATMEGA328P-A" H 9250 1150 40  0000 L BNN
F 2 "Housings_QFP:TQFP-32_7x7mm_Pitch0.8mm" H 8850 2550 30  0000 C CIN
F 3 "" H 8850 2550 60  0000 C CNN
	1    8850 2550
	1    0    0    -1  
$EndComp
Text HLabel 9750 4850 2    98   Input ~ 0
5V
$Comp
L R R12
U 1 1 5646C2E9
P 9450 4850
F 0 "R12" V 9530 4850 50  0000 C CNN
F 1 "10k ohm" V 9450 4850 50  0000 C CNN
F 2 "" V 9380 4850 30  0001 C CNN
F 3 "" H 9450 4850 30  0000 C CNN
	1    9450 4850
	0    -1   -1   0   
$EndComp
$Comp
L SW_PUSH SW2
U 1 1 5646C38C
P 8800 4850
F 0 "SW2" H 8950 4960 50  0000 C CNN
F 1 "SW_PUSH" H 8800 4770 50  0000 C CNN
F 2 "" H 8800 4850 60  0001 C CNN
F 3 "" H 8800 4850 60  0000 C CNN
	1    8800 4850
	1    0    0    -1  
$EndComp
Text HLabel 8400 4850 0    98   Input ~ 0
GND
Text GLabel 9750 4600 2    60   UnSpc ~ 0
Reset
Text GLabel 10000 2900 2    55   UnSpc ~ 0
Reset
$Comp
L C C8
U 1 1 5646C6D0
P 9350 5450
F 0 "C8" H 9375 5550 50  0000 L CNN
F 1 "22pf" H 9375 5350 50  0000 L CNN
F 2 "" H 9388 5300 30  0001 C CNN
F 3 "" H 9350 5450 60  0000 C CNN
	1    9350 5450
	0    -1   -1   0   
$EndComp
$Comp
L C C9
U 1 1 5646C741
P 9350 5950
F 0 "C9" H 9375 6050 50  0000 L CNN
F 1 "22pf" H 9375 5850 50  0000 L CNN
F 2 "" H 9388 5800 30  0001 C CNN
F 3 "" H 9350 5950 60  0000 C CNN
	1    9350 5950
	0    -1   -1   0   
$EndComp
$Comp
L Crystal Y1
U 1 1 5646C7E1
P 8900 5700
F 0 "Y1" H 8900 5850 50  0000 C CNN
F 1 "16MHZ" H 8900 5550 50  0000 C CNN
F 2 "Crystals:Crystal_HC49-U_Vertical" H 8900 5700 60  0001 C CNN
F 3 "" H 8900 5700 60  0000 C CNN
	1    8900 5700
	0    1    1    0   
$EndComp
Text HLabel 9950 5700 2    98   Input ~ 0
GND
Text GLabel 8650 5450 0    60   UnSpc ~ 0
Crystal1
Text GLabel 8650 5950 0    60   UnSpc ~ 0
Ctystal2
Text GLabel 10000 2050 2    55   UnSpc ~ 0
Crystal1
Text GLabel 10000 2150 2    55   UnSpc ~ 0
Ctystal2
$Comp
L K155ID1 U6
U 1 1 5646D245
P 6050 2000
F 0 "U6" H 6050 2750 60  0000 C CNN
F 1 "K155ID1" V 6050 2050 60  0000 C CNN
F 2 "Housings_DIP:DIP-16_W7.62mm" H 6050 2750 60  0001 C CNN
F 3 "" H 6050 2750 60  0000 C CNN
	1    6050 2000
	1    0    0    -1  
$EndComp
$Comp
L HEF4028 U5
U 1 1 5646D789
P 3200 1700
F 0 "U5" H 3200 2400 60  0000 C CNN
F 1 "HEF4028" V 3200 1750 60  0000 C CNN
F 2 "SMD_Packages:SO-16-N" H 3200 2400 60  0001 C CNN
F 3 "" H 3200 2400 60  0000 C CNN
	1    3200 1700
	1    0    0    -1  
$EndComp
$Comp
L TLP521 U4
U 1 1 5646D9AA
P 2800 3200
F 0 "U4" H 2800 3600 60  0000 C CNN
F 1 "TLP521" V 2800 3250 60  0000 C CNN
F 2 "SMD_Packages:DIP-8_SMD" H 2800 3600 60  0001 C CNN
F 3 "" H 2800 3600 60  0000 C CNN
	1    2800 3200
	0    1    1    0   
$EndComp
$Comp
L TLP521 U3
U 1 1 5646DC40
P 2050 3200
F 0 "U3" H 2050 3600 60  0000 C CNN
F 1 "TLP521" V 2050 3250 60  0000 C CNN
F 2 "SMD_Packages:DIP-8_SMD" H 2050 3600 60  0001 C CNN
F 3 "" H 2050 3600 60  0000 C CNN
	1    2050 3200
	0    1    1    0   
$EndComp
$Comp
L TLP521 U8
U 1 1 5646DD0A
P 4300 3200
F 0 "U8" H 4300 3600 60  0000 C CNN
F 1 "TLP521" V 4300 3250 60  0000 C CNN
F 2 "SMD_Packages:DIP-8_SMD" H 4300 3600 60  0001 C CNN
F 3 "" H 4300 3600 60  0000 C CNN
	1    4300 3200
	0    1    1    0   
$EndComp
$Comp
L TLP521 U7
U 1 1 5646DD10
P 3550 3200
F 0 "U7" H 3550 3600 60  0000 C CNN
F 1 "TLP521" V 3550 3250 60  0000 C CNN
F 2 "SMD_Packages:DIP-8_SMD" H 3550 3600 60  0001 C CNN
F 3 "" H 3550 3600 60  0000 C CNN
	1    3550 3200
	0    1    1    0   
$EndComp
Text HLabel 2550 1150 0    98   Input ~ 0
5V
Text HLabel 2550 1300 0    98   Input ~ 0
GND
NoConn ~ 3700 2050
NoConn ~ 3700 2200
Text GLabel 2550 1450 0    60   UnSpc ~ 0
Digit_A0
Text GLabel 2550 1600 0    60   UnSpc ~ 0
Digit_A1
Text GLabel 2550 1750 0    60   UnSpc ~ 0
Digit_A2
Text GLabel 2550 1900 0    60   UnSpc ~ 0
Digit_A3
$Comp
L R R11
U 1 1 564700B5
P 1550 3850
F 0 "R11" V 1630 3850 50  0000 C CNN
F 1 "18k ohm" V 1550 3850 50  0000 C CNN
F 2 "" V 1480 3850 30  0001 C CNN
F 3 "" H 1550 3850 30  0000 C CNN
	1    1550 3850
	0    1    1    0   
$EndComp
Text HLabel 5350 1450 0    98   Input ~ 0
5V
Text HLabel 5350 1600 0    98   Input ~ 0
GND
Text GLabel 5350 1750 0    60   UnSpc ~ 0
Font_A
Text GLabel 5350 1900 0    60   UnSpc ~ 0
Font_B
Text GLabel 5350 2050 0    60   UnSpc ~ 0
Font_C
Text GLabel 5350 2200 0    60   UnSpc ~ 0
Font_D
Text GLabel 10000 1450 2    55   UnSpc ~ 0
Digit_A0
Text GLabel 10000 3750 2    55   UnSpc ~ 0
Digit_A1
Text GLabel 10000 3650 2    55   UnSpc ~ 0
Digit_A2
Text GLabel 10000 3550 2    55   UnSpc ~ 0
Digit_A3
Text GLabel 10000 1950 2    55   UnSpc ~ 0
Font_A
Text GLabel 10000 1850 2    55   UnSpc ~ 0
Font_B
Text GLabel 10000 1750 2    55   UnSpc ~ 0
Font_C
Text GLabel 10000 1650 2    55   UnSpc ~ 0
Font_D
Wire Wire Line
	7700 1450 7950 1450
Wire Wire Line
	7800 1550 7950 1550
Connection ~ 7800 1450
Wire Wire Line
	7800 1750 7950 1750
Connection ~ 7800 1550
Wire Wire Line
	7700 3550 7950 3550
Connection ~ 7800 1750
Wire Wire Line
	7800 1450 7800 2050
Wire Wire Line
	7800 3550 7800 3750
Wire Wire Line
	7800 3750 7950 3750
Connection ~ 7800 3550
Wire Wire Line
	7950 3650 7800 3650
Connection ~ 7800 3650
Wire Wire Line
	8400 4850 8500 4850
Wire Wire Line
	9100 4850 9300 4850
Wire Wire Line
	9600 4850 9750 4850
Wire Wire Line
	9200 4600 9200 4850
Wire Wire Line
	9200 4600 9750 4600
Connection ~ 9200 4850
Wire Wire Line
	9850 2900 10000 2900
Wire Wire Line
	8900 5550 8900 5450
Wire Wire Line
	8650 5450 9200 5450
Wire Wire Line
	8650 5950 9200 5950
Wire Wire Line
	8900 5950 8900 5850
Wire Wire Line
	9500 5450 9850 5450
Wire Wire Line
	9850 5450 9850 5950
Wire Wire Line
	9850 5950 9500 5950
Wire Wire Line
	9950 5700 9850 5700
Connection ~ 9850 5700
Connection ~ 8900 5450
Connection ~ 8900 5950
Wire Wire Line
	9850 2050 10000 2050
Wire Wire Line
	9850 2150 10000 2150
Wire Wire Line
	7800 2050 7950 2050
Wire Wire Line
	2550 1150 2650 1150
Wire Wire Line
	2550 1300 2650 1300
Wire Wire Line
	1850 2750 1850 2600
Wire Wire Line
	1450 2600 4400 2600
Wire Wire Line
	4400 2600 4400 2750
Wire Wire Line
	4100 2750 4100 2600
Connection ~ 4100 2600
Wire Wire Line
	3350 2600 3350 2750
Connection ~ 3350 2600
Wire Wire Line
	3650 2750 3650 2600
Connection ~ 3650 2600
Wire Wire Line
	2900 2750 2900 2600
Connection ~ 2900 2600
Wire Wire Line
	2600 2750 2600 2600
Connection ~ 2600 2600
Wire Wire Line
	2150 2750 2150 2600
Connection ~ 2150 2600
Wire Wire Line
	2000 3650 2000 3850
Wire Wire Line
	1700 3850 4550 3850
Wire Wire Line
	4550 3850 4550 3650
Wire Wire Line
	4250 3650 4250 3850
Connection ~ 4250 3850
Wire Wire Line
	3800 3650 3800 3850
Connection ~ 3800 3850
Wire Wire Line
	3500 3650 3500 3850
Connection ~ 3500 3850
Wire Wire Line
	3050 3650 3050 3850
Connection ~ 3050 3850
Wire Wire Line
	2750 3650 2750 3850
Connection ~ 2750 3850
Wire Wire Line
	2300 3650 2300 3850
Connection ~ 2300 3850
Wire Wire Line
	2550 1450 2650 1450
Wire Wire Line
	2550 1600 2650 1600
Wire Wire Line
	2650 1750 2550 1750
Wire Wire Line
	2550 1900 2650 1900
Wire Wire Line
	2650 2050 2000 2050
Wire Wire Line
	2000 2050 2000 2750
Wire Wire Line
	2650 2200 2300 2200
Wire Wire Line
	2300 2200 2300 2750
Wire Wire Line
	2750 2750 2750 2500
Wire Wire Line
	2750 2500 3800 2500
Wire Wire Line
	3800 2500 3800 1150
Wire Wire Line
	3800 1150 3700 1150
Wire Wire Line
	3050 2750 3050 2450
Wire Wire Line
	3050 2450 3850 2450
Wire Wire Line
	3850 2450 3850 1300
Wire Wire Line
	3850 1300 3700 1300
Wire Wire Line
	3900 1450 3900 2400
Wire Wire Line
	3900 2400 3500 2400
Wire Wire Line
	3500 2400 3500 2750
Wire Wire Line
	3700 1450 3900 1450
Wire Wire Line
	3700 1600 3950 1600
Wire Wire Line
	3950 1600 3950 2550
Wire Wire Line
	3950 2550 3800 2550
Wire Wire Line
	3800 2550 3800 2750
Wire Wire Line
	3700 1750 4250 1750
Wire Wire Line
	4250 1750 4250 2750
Wire Wire Line
	3700 1900 4550 1900
Wire Wire Line
	4550 1900 4550 2750
Connection ~ 2000 3850
Wire Wire Line
	1250 3850 1400 3850
Wire Wire Line
	1850 3650 1850 4200
Wire Wire Line
	1850 4200 2800 4200
Wire Wire Line
	2800 4200 2800 4300
Wire Wire Line
	2150 3650 2150 4150
Wire Wire Line
	2150 4150 2900 4150
Wire Wire Line
	2900 4150 2900 4300
Wire Wire Line
	2600 3650 2600 4100
Wire Wire Line
	2600 4100 3000 4100
Wire Wire Line
	3000 4100 3000 4300
Wire Wire Line
	2900 3650 2900 4050
Wire Wire Line
	2900 4050 3100 4050
Wire Wire Line
	3100 4050 3100 4300
Wire Wire Line
	3350 3650 3350 4050
Wire Wire Line
	3350 4050 3200 4050
Wire Wire Line
	3200 4050 3200 4300
Wire Wire Line
	3650 3650 3650 4100
Wire Wire Line
	3650 4100 3300 4100
Wire Wire Line
	3300 4100 3300 4300
Wire Wire Line
	4100 3650 4100 4150
Wire Wire Line
	4100 4150 3400 4150
Wire Wire Line
	3400 4150 3400 4300
Wire Wire Line
	4400 3650 4400 4200
Wire Wire Line
	4400 4200 3500 4200
Wire Wire Line
	3500 4200 3500 4300
Wire Wire Line
	5350 1450 5500 1450
Wire Wire Line
	5350 1600 5500 1600
Wire Wire Line
	5350 1750 5500 1750
Wire Wire Line
	5350 1900 5500 1900
Wire Wire Line
	5350 2050 5500 2050
Wire Wire Line
	5350 2200 5500 2200
Wire Wire Line
	5500 2350 5350 2350
Wire Wire Line
	5350 2350 5350 3000
Wire Wire Line
	5350 3000 5450 3000
Wire Wire Line
	5450 3000 5450 3100
Wire Wire Line
	5450 2950 5550 2950
Wire Wire Line
	5550 2950 5550 3100
Wire Wire Line
	6550 1450 6650 1450
Wire Wire Line
	6650 1450 6650 2650
Wire Wire Line
	6650 2650 5650 2650
Wire Wire Line
	5650 2650 5650 3100
Wire Wire Line
	5750 3100 5750 2700
Wire Wire Line
	5750 2700 6700 2700
Wire Wire Line
	6700 2700 6700 1600
Wire Wire Line
	6700 1600 6550 1600
Wire Wire Line
	6550 1750 6750 1750
Wire Wire Line
	6750 1750 6750 2750
Wire Wire Line
	6750 2750 5850 2750
Wire Wire Line
	5850 2750 5850 3100
Wire Wire Line
	6550 1900 6800 1900
Wire Wire Line
	6800 1900 6800 2800
Wire Wire Line
	6800 2800 5950 2800
Wire Wire Line
	5950 2800 5950 3100
Wire Wire Line
	6550 2050 6850 2050
Wire Wire Line
	6850 2050 6850 2850
Wire Wire Line
	6850 2850 6050 2850
Wire Wire Line
	6050 2850 6050 3100
Wire Wire Line
	6550 2200 6900 2200
Wire Wire Line
	6900 2200 6900 2900
Wire Wire Line
	6900 2900 6150 2900
Wire Wire Line
	6150 2900 6150 3100
Wire Wire Line
	6550 2350 6950 2350
Wire Wire Line
	6950 2350 6950 2950
Wire Wire Line
	6950 2950 6250 2950
Wire Wire Line
	6250 2950 6250 3100
Wire Wire Line
	6350 3100 6350 3000
Wire Wire Line
	6350 3000 7000 3000
Wire Wire Line
	7000 3000 7000 2500
Wire Wire Line
	7000 2500 6550 2500
Wire Wire Line
	5500 2500 5450 2500
Wire Wire Line
	5450 2500 5450 2950
Wire Wire Line
	9850 1450 10000 1450
Wire Wire Line
	9850 1650 10000 1650
Wire Wire Line
	9850 3550 10000 3550
Wire Wire Line
	9850 3650 10000 3650
Wire Wire Line
	10000 3750 9850 3750
Text HLabel 10000 2800 2    60   Input ~ 0
I2C_SCL
Text HLabel 10000 2700 2    60   Input ~ 0
I2C_SDA
Wire Wire Line
	9850 2700 10000 2700
Wire Wire Line
	10000 2800 9850 2800
Text GLabel 10000 3050 2    55   UnSpc ~ 0
USART_RX
Text GLabel 10000 3150 2    55   UnSpc ~ 0
USART_TX
Wire Wire Line
	9850 3050 10000 3050
Wire Wire Line
	9850 3150 10000 3150
$Comp
L CONN_02X04 P2
U 1 1 56476352
P 6100 4900
F 0 "P2" H 6100 5150 50  0000 C CNN
F 1 "CONN_02X04" H 6100 4650 50  0000 C CNN
F 2 "" H 6100 3700 60  0001 C CNN
F 3 "" H 6100 3700 60  0000 C CNN
	1    6100 4900
	1    0    0    -1  
$EndComp
Text HLabel 5750 5050 0    67   Input ~ 0
5V
Text HLabel 5750 4950 0    67   Input ~ 0
GND
Wire Wire Line
	5750 4950 5850 4950
Text HLabel 6450 5050 2    67   Input ~ 0
5V
Text HLabel 6450 4950 2    67   Input ~ 0
GND
Wire Wire Line
	6350 4950 6450 4950
Text GLabel 5750 4850 0    55   UnSpc ~ 0
USART_RX
Text GLabel 5750 4750 0    55   UnSpc ~ 0
USART_TX
Text GLabel 6450 4850 2    55   UnSpc ~ 0
USART_RX
Text GLabel 6450 4750 2    55   UnSpc ~ 0
USART_TX
Wire Wire Line
	5750 4750 5850 4750
Wire Wire Line
	5750 4850 5850 4850
Wire Wire Line
	6350 4750 6450 4750
Wire Wire Line
	6450 4850 6350 4850
Wire Wire Line
	6450 5050 6350 5050
Wire Wire Line
	5750 5050 5850 5050
Text GLabel 10000 3250 2    55   UnSpc ~ 0
Mode_button
Wire Wire Line
	10000 3250 9850 3250
Text HLabel 5300 6000 0    98   Input ~ 0
5V
$Comp
L SW_PUSH SW1
U 1 1 56478717
P 5750 6000
F 0 "SW1" H 5900 6110 50  0000 C CNN
F 1 "SW_PUSH" H 5750 5920 50  0000 C CNN
F 2 "" H 5750 6000 60  0001 C CNN
F 3 "" H 5750 6000 60  0000 C CNN
	1    5750 6000
	1    0    0    -1  
$EndComp
$Comp
L R R9
U 1 1 5647877C
P 6450 6000
F 0 "R9" V 6530 6000 50  0000 C CNN
F 1 "330ohm" V 6450 6000 50  0000 C CNN
F 2 "" V 6380 6000 30  0001 C CNN
F 3 "" H 6450 6000 30  0000 C CNN
	1    6450 6000
	0    1    1    0   
$EndComp
Text HLabel 6750 6000 2    98   Input ~ 0
GND
Wire Wire Line
	6600 6000 6750 6000
Wire Wire Line
	6050 6000 6300 6000
Wire Wire Line
	5300 6000 5450 6000
Text GLabel 6550 5750 2    60   UnSpc ~ 0
Mode_button
Wire Wire Line
	6200 6000 6200 5750
Wire Wire Line
	6200 5750 6550 5750
Connection ~ 6200 6000
$Comp
L R R10
U 1 1 56483273
P 1450 2350
F 0 "R10" V 1530 2350 50  0000 C CNN
F 1 "330ohm" V 1450 2350 50  0000 C CNN
F 2 "" V 1380 2350 30  0001 C CNN
F 3 "" H 1450 2350 30  0000 C CNN
	1    1450 2350
	1    0    0    -1  
$EndComp
Text HLabel 1550 2050 2    98   Input ~ 0
GND
Wire Wire Line
	1550 2050 1450 2050
Wire Wire Line
	1450 2050 1450 2200
Wire Wire Line
	1450 2500 1450 2600
Connection ~ 1850 2600
Text HLabel 3500 4300 3    60   Input ~ 0
Tube_Anode_1
Text HLabel 3400 4300 3    60   Input ~ 0
Tube_Anode_2
Text HLabel 3300 4300 3    60   Input ~ 0
Tube_Anode_3
Text HLabel 3200 4300 3    60   Input ~ 0
Tube_Anode_4
Text HLabel 3100 4300 3    60   Input ~ 0
Tube_Anode_5
Text HLabel 3000 4300 3    60   Input ~ 0
Tube_Anode_6
Text HLabel 2900 4300 3    60   Input ~ 0
Tube_Anode_7
Text HLabel 2800 4300 3    60   Input ~ 0
Tube_Anode_8
Text HLabel 5450 3100 3    60   Input ~ 0
Tube_Cathode_1
Text HLabel 5550 3100 3    60   Input ~ 0
Tube_Cathode_2
Text HLabel 5650 3100 3    60   Input ~ 0
Tube_Cathode_3
Text HLabel 5750 3100 3    60   Input ~ 0
Tube_Cathode_4
Text HLabel 5850 3100 3    60   Input ~ 0
Tube_Cathode_5
Text HLabel 5950 3100 3    60   Input ~ 0
Tube_Cathode_6
Text HLabel 6050 3100 3    60   Input ~ 0
Tube_Cathode_7
Text HLabel 6150 3100 3    60   Input ~ 0
Tube_Cathode_8
Text HLabel 6250 3100 3    60   Input ~ 0
Tube_Cathode_9
Text HLabel 6350 3100 3    60   Input ~ 0
Tube_Cathode_0
$Comp
L Q_NPN_EBC Q?
U 1 1 56531503
P 3500 5650
F 0 "Q?" H 3800 5700 50  0000 R CNN
F 1 "Q_NPN_EBC" H 4100 5600 50  0000 R CNN
F 2 "" H 3700 5750 29  0000 C CNN
F 3 "" H 3500 5650 60  0000 C CNN
	1    3500 5650
	1    0    0    -1  
$EndComp
$Comp
L Q_NPN_EBC Q?
U 1 1 56531680
P 3500 6450
F 0 "Q?" H 3800 6500 50  0000 R CNN
F 1 "Q_NPN_EBC" H 4100 6400 50  0000 R CNN
F 2 "" H 3700 6550 29  0000 C CNN
F 3 "" H 3500 6450 60  0000 C CNN
	1    3500 6450
	1    0    0    -1  
$EndComp
Text HLabel 3550 5300 0    60   Input ~ 0
Tube_Cathode_Comma_Left
Text HLabel 3550 6100 0    60   Input ~ 0
Tube_Cathode_Comma_Right
Wire Wire Line
	3550 5300 3600 5300
Wire Wire Line
	3600 5300 3600 5450
Wire Wire Line
	3550 6100 3600 6100
Wire Wire Line
	3600 6100 3600 6250
Text HLabel 3550 5950 0    98   Input ~ 0
GND
Text HLabel 3550 6750 0    98   Input ~ 0
GND
Wire Wire Line
	3550 5950 3600 5950
Wire Wire Line
	3600 5950 3600 5850
Wire Wire Line
	3550 6750 3600 6750
Wire Wire Line
	3600 6750 3600 6650
Text GLabel 3200 6450 0    60   UnSpc ~ 0
right_comma
Text GLabel 3200 5650 0    60   UnSpc ~ 0
left_comma
Wire Wire Line
	3200 5650 3300 5650
Wire Wire Line
	3200 6450 3300 6450
Text GLabel 10000 2300 2    55   UnSpc ~ 0
right_comma
Text GLabel 10000 2400 2    55   UnSpc ~ 0
left_comma
Wire Wire Line
	9850 2300 10000 2300
Wire Wire Line
	9850 2400 10000 2400
Wire Wire Line
	9850 1750 10000 1750
Wire Wire Line
	9850 1850 10000 1850
Wire Wire Line
	9850 1950 10000 1950
$EndSCHEMATC
