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
Sheet 3 4
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 1100 3600 0    98   Input ~ 0
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
L R R15
U 1 1 5646C2E9
P 9450 4850
F 0 "R15" V 9530 4850 50  0000 C CNN
F 1 "10k ohm" V 9450 4850 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 9380 4850 30  0001 C CNN
F 3 "" H 9450 4850 30  0000 C CNN
	1    9450 4850
	0    -1   -1   0   
$EndComp
$Comp
L SW_PUSH SW1
U 1 1 5646C38C
P 8800 4850
F 0 "SW1" H 8950 4960 50  0000 C CNN
F 1 "SW_PUSH" H 8800 4770 50  0000 C CNN
F 2 "Buttons_Switches_SMD:SW_SPST_PTS645" H 8800 4850 60  0001 C CNN
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
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 9388 5300 30  0001 C CNN
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
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 9388 5800 30  0001 C CNN
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
L K155ID1 U8
U 1 1 5646D245
P 6200 1950
F 0 "U8" H 6200 2700 60  0000 C CNN
F 1 "K155ID1" V 6200 2000 60  0000 C CNN
F 2 "Housings_DIP:DIP-16_W7.62mm" H 6200 2700 60  0001 C CNN
F 3 "" H 6200 2700 60  0000 C CNN
	1    6200 1950
	1    0    0    -1  
$EndComp
$Comp
L HEF4028 U5
U 1 1 5646D789
P 3050 1450
F 0 "U5" H 3050 2150 60  0000 C CNN
F 1 "HEF4028" V 3050 1500 60  0000 C CNN
F 2 "Housings_DIP:DIP-16_W7.62mm" H 3050 2150 60  0001 C CNN
F 3 "" H 3050 2150 60  0000 C CNN
	1    3050 1450
	1    0    0    -1  
$EndComp
$Comp
L TLP521 U4
U 1 1 5646D9AA
P 2650 2950
F 0 "U4" H 2650 3350 60  0000 C CNN
F 1 "TLP521" V 2650 3000 60  0000 C CNN
F 2 "Housings_DIP:DIP-8_W7.62mm" H 2650 3350 60  0001 C CNN
F 3 "" H 2650 3350 60  0000 C CNN
	1    2650 2950
	0    1    1    0   
$EndComp
$Comp
L TLP521 U3
U 1 1 5646DC40
P 1900 2950
F 0 "U3" H 1900 3350 60  0000 C CNN
F 1 "TLP521" V 1900 3000 60  0000 C CNN
F 2 "Housings_DIP:DIP-8_W7.62mm" H 1900 3350 60  0001 C CNN
F 3 "" H 1900 3350 60  0000 C CNN
	1    1900 2950
	0    1    1    0   
$EndComp
$Comp
L TLP521 U7
U 1 1 5646DD0A
P 4150 2950
F 0 "U7" H 4150 3350 60  0000 C CNN
F 1 "TLP521" V 4150 3000 60  0000 C CNN
F 2 "Housings_DIP:DIP-8_W7.62mm" H 4150 3350 60  0001 C CNN
F 3 "" H 4150 3350 60  0000 C CNN
	1    4150 2950
	0    1    1    0   
$EndComp
$Comp
L TLP521 U6
U 1 1 5646DD10
P 3400 2950
F 0 "U6" H 3400 3350 60  0000 C CNN
F 1 "TLP521" V 3400 3000 60  0000 C CNN
F 2 "Housings_DIP:DIP-8_W7.62mm" H 3400 3350 60  0001 C CNN
F 3 "" H 3400 3350 60  0000 C CNN
	1    3400 2950
	0    1    1    0   
$EndComp
Text HLabel 2400 900  0    98   Input ~ 0
5V
Text HLabel 2400 1050 0    98   Input ~ 0
GND
NoConn ~ 3550 1800
NoConn ~ 3550 1950
Text GLabel 2400 1200 0    60   UnSpc ~ 0
Digit_A0
Text GLabel 2400 1350 0    60   UnSpc ~ 0
Digit_A1
Text GLabel 2400 1500 0    60   UnSpc ~ 0
Digit_A2
Text GLabel 2400 1650 0    60   UnSpc ~ 0
Digit_A3
$Comp
L R R9
U 1 1 564700B5
P 1400 3600
F 0 "R9" V 1480 3600 50  0000 C CNN
F 1 "18k ohm" V 1400 3600 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 1330 3600 30  0001 C CNN
F 3 "" H 1400 3600 30  0000 C CNN
	1    1400 3600
	0    1    1    0   
$EndComp
Text HLabel 5500 1400 0    98   Input ~ 0
5V
Text HLabel 5500 1550 0    98   Input ~ 0
GND
Text GLabel 5500 1700 0    60   UnSpc ~ 0
Font_A
Text GLabel 5500 1850 0    60   UnSpc ~ 0
Font_B
Text GLabel 5500 2000 0    60   UnSpc ~ 0
Font_C
Text GLabel 5500 2150 0    60   UnSpc ~ 0
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
Text HLabel 10000 2800 2    60   Input ~ 0
I2C_SCL
Text HLabel 10000 2700 2    60   Input ~ 0
I2C_SDA
Text GLabel 10000 3050 2    55   UnSpc ~ 0
USART_RX
Text GLabel 10000 3150 2    55   UnSpc ~ 0
USART_TX
Text HLabel 4900 5450 0    67   Input ~ 0
5V
Text HLabel 5750 5250 0    67   Input ~ 0
GND
Text HLabel 5750 4550 2    67   Input ~ 0
5V
Text HLabel 5750 4450 2    67   Input ~ 0
GND
Text GLabel 5750 5150 0    55   UnSpc ~ 0
USART_RX
Text GLabel 5750 5050 0    55   UnSpc ~ 0
USART_TX
Text GLabel 5750 4350 2    55   UnSpc ~ 0
USART_RX
Text GLabel 5750 4250 2    55   UnSpc ~ 0
USART_TX
Text GLabel 10000 3250 2    55   UnSpc ~ 0
Mode_button
Text HLabel 1950 7050 0    98   Input ~ 0
5V
$Comp
L R R12
U 1 1 5647877C
P 3000 7050
F 0 "R12" V 2950 7250 50  0000 C CNN
F 1 "330ohm" V 3000 7050 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 2930 7050 30  0001 C CNN
F 3 "" H 3000 7050 30  0000 C CNN
	1    3000 7050
	0    1    1    0   
$EndComp
Text HLabel 3550 7050 2    98   Input ~ 0
GND
Text GLabel 3100 6800 2    60   UnSpc ~ 0
Mode_button
$Comp
L R R8
U 1 1 56483273
P 1300 2100
F 0 "R8" V 1380 2100 50  0000 C CNN
F 1 "330ohm" V 1300 2100 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 1230 2100 30  0001 C CNN
F 3 "" H 1300 2100 30  0000 C CNN
	1    1300 2100
	1    0    0    -1  
$EndComp
Text HLabel 1400 1800 2    98   Input ~ 0
GND
$Comp
L Q_NPN_EBC Q3
U 1 1 56531503
P 3450 5000
F 0 "Q3" H 3750 5050 50  0000 R CNN
F 1 "Q_NPN_EBC" H 4050 4950 50  0000 R CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Narrow_Oval" H 3650 5100 29  0001 C CNN
F 3 "" H 3450 5000 60  0000 C CNN
	1    3450 5000
	1    0    0    -1  
$EndComp
$Comp
L Q_NPN_EBC Q4
U 1 1 56531680
P 3450 5800
F 0 "Q4" H 3750 5850 50  0000 R CNN
F 1 "Q_NPN_EBC" H 4050 5750 50  0000 R CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Narrow_Oval" H 3650 5900 29  0001 C CNN
F 3 "" H 3450 5800 60  0000 C CNN
	1    3450 5800
	1    0    0    -1  
$EndComp
Text HLabel 3500 5300 0    98   Input ~ 0
GND
Text HLabel 3500 6100 0    98   Input ~ 0
GND
Text GLabel 3150 5800 0    60   UnSpc ~ 0
right_comma
Text GLabel 3150 5000 0    60   UnSpc ~ 0
left_comma
Text GLabel 10000 2300 2    55   UnSpc ~ 0
right_comma
Text GLabel 10000 2400 2    55   UnSpc ~ 0
left_comma
$Comp
L R R10
U 1 1 5656B24C
P 3250 4650
F 0 "R10" V 3330 4650 50  0000 C CNN
F 1 "R" V 3250 4650 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 3180 4650 30  0001 C CNN
F 3 "" H 3250 4650 30  0000 C CNN
	1    3250 4650
	0    1    1    0   
$EndComp
$Comp
L R R11
U 1 1 5656B5EC
P 3250 5450
F 0 "R11" V 3330 5450 50  0000 C CNN
F 1 "R" V 3250 5450 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 3180 5450 30  0001 C CNN
F 3 "" H 3250 5450 30  0000 C CNN
	1    3250 5450
	0    1    1    0   
$EndComp
NoConn ~ 7950 2800
NoConn ~ 7950 2900
NoConn ~ 9850 1550
$Comp
L CONN_01X08 P1
U 1 1 56A35F26
P 3000 4250
F 0 "P1" H 3000 4700 50  0000 C CNN
F 1 "CONN_01X08" V 3100 4250 50  0000 C CNN
F 2 "SMD_PIN_2_BY_4_REVERSE:SMD_PIN_2_BY_4_REVERSE" H 3000 4250 50  0001 C CNN
F 3 "" H 3000 4250 50  0000 C CNN
	1    3000 4250
	0    1    1    0   
$EndComp
Text GLabel 3000 4650 0    60   UnSpc ~ 0
_cathode_comma_left
Text GLabel 3000 5450 0    60   UnSpc ~ 0
_cathode_comma_right
$Comp
L CONN_01X12 P3
U 1 1 56A3F771
P 5950 3250
F 0 "P3" H 5950 3900 50  0000 C CNN
F 1 "CONN_01X12" V 6050 3250 50  0000 C CNN
F 2 "SMD_PIN_2_BY_6_REVERSE:SMD_PIN_2_BY_6_REVERSE" H 5950 3250 50  0001 C CNN
F 3 "" H 5950 3250 50  0000 C CNN
	1    5950 3250
	0    1    1    0   
$EndComp
Text GLabel 5350 3500 2    60   UnSpc ~ 0
_cathode_comma_right
Text GLabel 5350 3650 2    60   UnSpc ~ 0
_cathode_comma_left
$Comp
L CONN_02X03 P2
U 1 1 56A879D5
P 2350 7150
F 0 "P2" H 2350 7350 50  0000 C CNN
F 1 "CONN_02X03" H 2350 6950 50  0000 C CNN
F 2 "SMD_PIN_2_BY_3_REVERSE:SMD_PIN_2_BY_3_REVERSE" H 2350 5950 50  0001 C CNN
F 3 "" H 2350 5950 50  0000 C CNN
	1    2350 7150
	1    0    0    -1  
$EndComp
Text HLabel 1950 7150 0    98   Input ~ 0
5V
Text HLabel 1950 7250 0    98   Input ~ 0
5V
$Comp
L R R13
U 1 1 56A87DD8
P 3000 7150
F 0 "R13" V 2950 7350 50  0000 C CNN
F 1 "330ohm" V 3000 7150 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 2930 7150 30  0001 C CNN
F 3 "" H 3000 7150 30  0000 C CNN
	1    3000 7150
	0    1    1    0   
$EndComp
$Comp
L R R14
U 1 1 56A87E33
P 3000 7250
F 0 "R14" V 2950 7450 50  0000 C CNN
F 1 "330ohm" V 3000 7250 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 2930 7250 30  0001 C CNN
F 3 "" H 3000 7250 30  0000 C CNN
	1    3000 7250
	0    1    1    0   
$EndComp
Text GLabel 3100 6650 2    60   UnSpc ~ 0
Adjust_button
Text GLabel 3100 6500 2    60   UnSpc ~ 0
Search_button
Text GLabel 10000 3450 2    60   UnSpc ~ 0
Adjust_button
Text GLabel 10000 3350 2    60   UnSpc ~ 0
Search_button
$Comp
L R R18
U 1 1 56ACF8C9
P 5150 6200
F 0 "R18" V 5230 6200 50  0000 C CNN
F 1 "1K ohm" V 5150 6200 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 5080 6200 50  0001 C CNN
F 3 "" H 5150 6200 50  0000 C CNN
	1    5150 6200
	0    1    1    0   
$EndComp
$Comp
L R R19
U 1 1 56ACF970
P 5150 6350
F 0 "R19" V 5230 6350 50  0000 C CNN
F 1 "1k ohm" V 5150 6350 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 5080 6350 50  0001 C CNN
F 3 "" H 5150 6350 50  0000 C CNN
	1    5150 6350
	0    1    1    0   
$EndComp
Text HLabel 5250 6050 0    67   Input ~ 0
5V
Text GLabel 10000 2500 2    55   UnSpc ~ 0
MP3_TX
Text GLabel 10000 2600 2    55   UnSpc ~ 0
MP3_RX
Text GLabel 5000 6350 0    55   UnSpc ~ 0
MP3_TX
Text GLabel 5000 6200 0    55   UnSpc ~ 0
MP3_RX
$Comp
L SPEAKER SP1
U 1 1 56AD14DC
P 4900 6950
F 0 "SP1" H 4800 7200 50  0000 C CNN
F 1 "SPEAKER" H 4800 6700 50  0000 C CNN
F 2 "Connect:PINHEAD1-2" H 4900 6950 50  0001 C CNN
F 3 "" H 4900 6950 50  0000 C CNN
	1    4900 6950
	-1   0    0    1   
$EndComp
NoConn ~ 5400 6500
NoConn ~ 5400 6650
Text HLabel 5350 7350 2    98   Input ~ 0
GND
$Comp
L DFPlayer U18
U 1 1 56ACE172
P 5950 6500
F 0 "U18" H 5750 7100 60  0000 C CNN
F 1 "DFPlayer" H 6100 7100 60  0000 C CNN
F 2 "dfplayer:DFPlayer" H 5700 7150 60  0001 C CNN
F 3 "" H 5700 7150 60  0000 C CNN
	1    5950 6500
	1    0    0    -1  
$EndComp
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
	2400 900  2500 900 
Wire Wire Line
	2400 1050 2500 1050
Wire Wire Line
	1700 2500 1700 2350
Wire Wire Line
	1300 2350 4250 2350
Wire Wire Line
	4250 2350 4250 2500
Wire Wire Line
	3950 2500 3950 2350
Connection ~ 3950 2350
Wire Wire Line
	3200 2350 3200 2500
Connection ~ 3200 2350
Wire Wire Line
	3500 2500 3500 2350
Connection ~ 3500 2350
Wire Wire Line
	2750 2500 2750 2350
Connection ~ 2750 2350
Wire Wire Line
	2450 2500 2450 2350
Connection ~ 2450 2350
Wire Wire Line
	2000 2500 2000 2350
Connection ~ 2000 2350
Wire Wire Line
	1850 3400 1850 3600
Wire Wire Line
	1550 3600 4400 3600
Wire Wire Line
	4400 3600 4400 3400
Wire Wire Line
	4100 3400 4100 3600
Connection ~ 4100 3600
Wire Wire Line
	3650 3400 3650 3600
Connection ~ 3650 3600
Wire Wire Line
	3350 3400 3350 3600
Connection ~ 3350 3600
Wire Wire Line
	2900 3400 2900 3600
Connection ~ 2900 3600
Wire Wire Line
	2600 3400 2600 3600
Connection ~ 2600 3600
Wire Wire Line
	2150 3400 2150 3600
Connection ~ 2150 3600
Wire Wire Line
	2400 1200 2500 1200
Wire Wire Line
	2400 1350 2500 1350
Wire Wire Line
	2500 1500 2400 1500
Wire Wire Line
	2400 1650 2500 1650
Wire Wire Line
	2500 1800 1850 1800
Wire Wire Line
	1850 1800 1850 2500
Wire Wire Line
	2500 1950 2150 1950
Wire Wire Line
	2150 1950 2150 2500
Wire Wire Line
	2600 2500 2600 2250
Wire Wire Line
	2600 2250 3650 2250
Wire Wire Line
	3650 2250 3650 900 
Wire Wire Line
	3650 900  3550 900 
Wire Wire Line
	2900 2500 2900 2200
Wire Wire Line
	2900 2200 3700 2200
Wire Wire Line
	3700 2200 3700 1050
Wire Wire Line
	3700 1050 3550 1050
Wire Wire Line
	3750 1200 3750 2150
Wire Wire Line
	3750 2150 3350 2150
Wire Wire Line
	3350 2150 3350 2500
Wire Wire Line
	3550 1200 3750 1200
Wire Wire Line
	3550 1350 3800 1350
Wire Wire Line
	3800 1350 3800 2300
Wire Wire Line
	3800 2300 3650 2300
Wire Wire Line
	3650 2300 3650 2500
Wire Wire Line
	3550 1500 4100 1500
Wire Wire Line
	4100 1500 4100 2500
Wire Wire Line
	3550 1650 4400 1650
Wire Wire Line
	4400 1650 4400 2500
Connection ~ 1850 3600
Wire Wire Line
	1100 3600 1250 3600
Wire Wire Line
	1700 3400 1700 3950
Wire Wire Line
	1700 3950 2650 3950
Wire Wire Line
	2650 3950 2650 4050
Wire Wire Line
	2000 3400 2000 3900
Wire Wire Line
	2000 3900 2750 3900
Wire Wire Line
	2750 3900 2750 4050
Wire Wire Line
	2450 3400 2450 3850
Wire Wire Line
	2450 3850 2850 3850
Wire Wire Line
	2850 3850 2850 4050
Wire Wire Line
	2750 3400 2750 3800
Wire Wire Line
	2750 3800 2950 3800
Wire Wire Line
	2950 3800 2950 4050
Wire Wire Line
	3200 3400 3200 3800
Wire Wire Line
	3200 3800 3050 3800
Wire Wire Line
	3050 3800 3050 4050
Wire Wire Line
	3500 3400 3500 3850
Wire Wire Line
	3500 3850 3150 3850
Wire Wire Line
	3150 3850 3150 4050
Wire Wire Line
	3950 3400 3950 3900
Wire Wire Line
	3950 3900 3250 3900
Wire Wire Line
	3250 3900 3250 4050
Wire Wire Line
	4250 3400 4250 3950
Wire Wire Line
	4250 3950 3350 3950
Wire Wire Line
	3350 3950 3350 4050
Wire Wire Line
	5500 1400 5650 1400
Wire Wire Line
	5500 1550 5650 1550
Wire Wire Line
	5500 1700 5650 1700
Wire Wire Line
	5500 1850 5650 1850
Wire Wire Line
	5500 2000 5650 2000
Wire Wire Line
	5500 2150 5650 2150
Wire Wire Line
	5650 2300 5500 2300
Wire Wire Line
	5500 2300 5500 2700
Wire Wire Line
	5500 2700 5600 2700
Wire Wire Line
	5600 2700 5600 3050
Wire Wire Line
	5600 2650 5700 2650
Wire Wire Line
	5700 2650 5700 3050
Wire Wire Line
	6700 1400 6800 1400
Wire Wire Line
	6800 1400 6800 2600
Wire Wire Line
	6800 2600 5800 2600
Wire Wire Line
	5800 2600 5800 3050
Wire Wire Line
	5900 3050 5900 2650
Wire Wire Line
	5900 2650 6850 2650
Wire Wire Line
	6850 2650 6850 1550
Wire Wire Line
	6850 1550 6700 1550
Wire Wire Line
	6700 1700 6900 1700
Wire Wire Line
	6900 1700 6900 2700
Wire Wire Line
	6900 2700 6000 2700
Wire Wire Line
	6000 2700 6000 3050
Wire Wire Line
	6700 1850 6950 1850
Wire Wire Line
	6950 1850 6950 2750
Wire Wire Line
	6950 2750 6100 2750
Wire Wire Line
	6100 2750 6100 3050
Wire Wire Line
	6700 2000 7000 2000
Wire Wire Line
	7000 2000 7000 2800
Wire Wire Line
	7000 2800 6200 2800
Wire Wire Line
	6200 2800 6200 3050
Wire Wire Line
	6700 2150 7050 2150
Wire Wire Line
	7050 2150 7050 2850
Wire Wire Line
	7050 2850 6300 2850
Wire Wire Line
	6300 2850 6300 3050
Wire Wire Line
	6700 2300 7100 2300
Wire Wire Line
	7100 2300 7100 2900
Wire Wire Line
	7100 2900 6400 2900
Wire Wire Line
	6400 2900 6400 3050
Wire Wire Line
	6500 3050 6500 2950
Wire Wire Line
	6500 2950 7150 2950
Wire Wire Line
	7150 2950 7150 2450
Wire Wire Line
	7150 2450 6700 2450
Wire Wire Line
	5650 2450 5600 2450
Wire Wire Line
	5600 2450 5600 2650
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
Wire Wire Line
	9850 2700 10000 2700
Wire Wire Line
	10000 2800 9850 2800
Wire Wire Line
	9850 3050 10000 3050
Wire Wire Line
	9850 3150 10000 3150
Wire Wire Line
	5750 5250 6100 5250
Wire Wire Line
	5650 4450 5750 4450
Wire Wire Line
	5750 5050 6200 5050
Wire Wire Line
	5750 5150 6150 5150
Wire Wire Line
	5650 4250 5750 4250
Wire Wire Line
	5750 4350 5650 4350
Wire Wire Line
	5750 4550 5650 4550
Wire Wire Line
	4900 5450 5000 5450
Wire Wire Line
	10000 3250 9850 3250
Wire Wire Line
	3150 7050 3550 7050
Wire Wire Line
	2600 7050 2850 7050
Wire Wire Line
	1950 7050 2100 7050
Wire Wire Line
	2650 7050 2650 6800
Wire Wire Line
	2650 6800 3100 6800
Connection ~ 2650 7050
Wire Wire Line
	1400 1800 1300 1800
Wire Wire Line
	1300 1800 1300 1950
Wire Wire Line
	1300 2250 1300 2350
Connection ~ 1700 2350
Wire Wire Line
	3400 4650 3550 4650
Wire Wire Line
	3550 4650 3550 4800
Wire Wire Line
	3400 5450 3550 5450
Wire Wire Line
	3550 5450 3550 5600
Wire Wire Line
	3500 5300 3550 5300
Wire Wire Line
	3550 5300 3550 5200
Wire Wire Line
	3500 6100 3550 6100
Wire Wire Line
	3550 6100 3550 6000
Wire Wire Line
	3150 5000 3250 5000
Wire Wire Line
	3150 5800 3250 5800
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
Wire Wire Line
	3000 4650 3100 4650
Wire Wire Line
	3000 5450 3100 5450
Wire Wire Line
	9850 2500 10000 2500
Wire Wire Line
	10000 2600 9850 2600
Wire Wire Line
	5400 3000 5250 3000
Wire Wire Line
	5250 3000 5250 3500
Wire Wire Line
	5250 3500 5350 3500
Wire Wire Line
	5400 3050 5400 3000
Wire Wire Line
	5500 3050 5500 2950
Wire Wire Line
	5500 2950 5150 2950
Wire Wire Line
	5150 2950 5150 3650
Wire Wire Line
	5150 3650 5350 3650
Wire Wire Line
	7800 1450 7800 2050
Wire Wire Line
	1950 7150 2100 7150
Wire Wire Line
	2100 7250 1950 7250
Wire Wire Line
	2600 7150 2850 7150
Wire Wire Line
	2600 7250 2850 7250
Wire Wire Line
	3150 7150 3400 7150
Wire Wire Line
	3400 7050 3400 7250
Connection ~ 3400 7050
Wire Wire Line
	3400 7250 3150 7250
Connection ~ 3400 7150
Wire Wire Line
	3100 6650 2700 6650
Wire Wire Line
	2700 6650 2700 7150
Connection ~ 2700 7150
Wire Wire Line
	2750 7250 2750 6500
Wire Wire Line
	2750 6500 3100 6500
Connection ~ 2750 7250
Wire Wire Line
	9850 3350 10000 3350
Wire Wire Line
	9850 3450 10000 3450
Wire Wire Line
	5300 6200 5400 6200
Wire Wire Line
	5400 6350 5300 6350
Wire Wire Line
	5250 6050 5400 6050
Wire Wire Line
	5200 6850 5200 6800
Wire Wire Line
	5200 6800 5400 6800
Wire Wire Line
	5200 7050 5200 7100
Wire Wire Line
	5200 7100 5400 7100
Wire Wire Line
	5400 6950 5300 6950
Wire Wire Line
	5300 6950 5300 7350
Wire Wire Line
	5300 7350 5350 7350
NoConn ~ 6550 7100
NoConn ~ 6550 6950
NoConn ~ 6550 6800
NoConn ~ 6550 6650
NoConn ~ 6550 6500
NoConn ~ 6550 6350
NoConn ~ 6550 6200
NoConn ~ 6550 6050
Wire Wire Line
	7800 2050 7950 2050
$Comp
L CONN_01X04 P4
U 1 1 57408260
P 5450 4400
F 0 "P4" H 5450 4650 50  0000 C CNN
F 1 "CONN_01X04" V 5550 4400 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_1x04" H 5450 4400 50  0001 C CNN
F 3 "" H 5450 4400 50  0000 C CNN
	1    5450 4400
	-1   0    0    1   
$EndComp
$Comp
L SPST SW2
U 1 1 57408470
P 5500 5450
F 0 "SW2" H 5500 5550 50  0000 C CNN
F 1 "SPST" H 5500 5350 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 5500 5450 50  0001 C CNN
F 3 "" H 5500 5450 50  0000 C CNN
	1    5500 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 5450 6200 5450
Wire Wire Line
	6100 5250 6100 5350
Wire Wire Line
	6100 5350 6200 5350
Wire Wire Line
	6150 5150 6150 5250
Wire Wire Line
	6150 5250 6200 5250
Wire Wire Line
	6200 5050 6200 5150
$Comp
L BLUETOOTH_SJ P5
U 1 1 574BA9A7
P 6400 5300
F 0 "P5" H 6400 5600 50  0000 C CNN
F 1 "BLUETOOTH_SJ" H 6650 4950 50  0000 C CNN
F 2 "HC06:HC06" H 6450 5300 50  0001 C CNN
F 3 "" H 6450 5300 50  0000 C CNN
	1    6400 5300
	1    0    0    -1  
$EndComp
$EndSCHEMATC