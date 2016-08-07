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
Sheet 2 2
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
L IN-14 U10
U 1 1 5649391C
P 5450 3950
F 0 "U10" H 5200 4600 60  0000 C CNN
F 1 "IN-14" H 5500 4600 60  0000 C CNN
F 2 "IN-14:IN-14" H 5200 4600 60  0001 C CNN
F 3 "" H 5200 4600 60  0000 C CNN
	1    5450 3950
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X05 P3
U 1 1 57A05282
P 8550 4500
F 0 "P3" H 8550 4800 50  0000 C CNN
F 1 "CONN_01X05" V 8650 4500 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x05" H 8550 4500 50  0001 C CNN
F 3 "" H 8550 4500 50  0000 C CNN
	1    8550 4500
	1    0    0    -1  
$EndComp
Text GLabel 4400 3750 0    60   UnSpc ~ 0
cathode_comma_right
Text GLabel 4400 3600 0    60   UnSpc ~ 0
cathode_comma_left
Text GLabel 4400 3900 0    60   UnSpc ~ 0
cathode1
Text GLabel 4400 4050 0    60   UnSpc ~ 0
cathode2
Text GLabel 4400 4200 0    60   UnSpc ~ 0
cathode3
Text GLabel 4400 4350 0    60   UnSpc ~ 0
cathode4
Text GLabel 4400 3450 0    55   UnSpc ~ 0
anode
Text GLabel 6500 4200 2    60   UnSpc ~ 0
cathode0
Text GLabel 6500 4050 2    60   UnSpc ~ 0
cathode9
Text GLabel 6500 3900 2    60   UnSpc ~ 0
cathode8
Text GLabel 6500 3750 2    60   UnSpc ~ 0
cathode7
Text GLabel 6500 3600 2    60   UnSpc ~ 0
cathode6
Text GLabel 6500 3450 2    60   UnSpc ~ 0
cathode5
$Comp
L CONN_01X04 P1
U 1 1 57A05D56
P 8550 3100
F 0 "P1" H 8550 3350 50  0000 C CNN
F 1 "CONN_01X04" V 8650 3100 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04" H 8550 3100 50  0001 C CNN
F 3 "" H 8550 3100 50  0000 C CNN
	1    8550 3100
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X04 P2
U 1 1 57A05275
P 8550 3750
F 0 "P2" H 8550 4000 50  0000 C CNN
F 1 "CONN_01X04" V 8650 3750 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04" H 8550 3750 50  0001 C CNN
F 3 "" H 8550 3750 50  0000 C CNN
	1    8550 3750
	1    0    0    -1  
$EndComp
Text GLabel 8300 2950 0    55   UnSpc ~ 0
cathode6
Text GLabel 8300 3050 0    55   UnSpc ~ 0
cathode7
Text GLabel 8300 3150 0    55   UnSpc ~ 0
cathode8
Text GLabel 8300 3250 0    55   UnSpc ~ 0
cathode9
Wire Wire Line
	8300 2950 8350 2950
Wire Wire Line
	8300 3050 8350 3050
Wire Wire Line
	8300 3150 8350 3150
Wire Wire Line
	8300 3250 8350 3250
Text GLabel 8300 3600 0    55   UnSpc ~ 0
cathode5
Text GLabel 8300 3700 0    55   UnSpc ~ 0
cathode4
Text GLabel 8300 3800 0    55   UnSpc ~ 0
cathode3
Text GLabel 8300 3900 0    55   UnSpc ~ 0
cathode2
Text GLabel 8300 4300 0    55   UnSpc ~ 0
cathode1
Text GLabel 8300 4400 0    55   UnSpc ~ 0
cathode_comma_left
Text GLabel 8300 4500 0    55   UnSpc ~ 0
anode
Text GLabel 8300 4600 0    55   UnSpc ~ 0
cathode_comma_right
Text GLabel 8300 4700 0    55   UnSpc ~ 0
cathode0
Wire Wire Line
	6400 3450 6500 3450
Wire Wire Line
	6400 3600 6500 3600
Wire Wire Line
	6400 3750 6500 3750
Wire Wire Line
	6400 3900 6500 3900
Wire Wire Line
	6400 4050 6500 4050
Wire Wire Line
	6400 4200 6500 4200
Wire Wire Line
	4400 3450 4500 3450
Wire Wire Line
	4400 3600 4500 3600
Wire Wire Line
	4400 3750 4500 3750
Wire Wire Line
	4400 3900 4500 3900
Wire Wire Line
	4400 4050 4500 4050
Wire Wire Line
	4400 4200 4500 4200
Wire Wire Line
	4400 4350 4500 4350
Wire Wire Line
	8300 3600 8350 3600
Wire Wire Line
	8350 3700 8300 3700
Wire Wire Line
	8300 3800 8350 3800
Wire Wire Line
	8350 3900 8300 3900
Wire Wire Line
	8300 4300 8350 4300
Wire Wire Line
	8350 4400 8300 4400
Wire Wire Line
	8300 4500 8350 4500
Wire Wire Line
	8350 4600 8300 4600
Wire Wire Line
	8300 4700 8350 4700
$EndSCHEMATC
