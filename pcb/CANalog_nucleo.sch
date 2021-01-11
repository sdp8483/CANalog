EESchema Schematic File Version 4
EELAYER 30 0
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
L pl_nucleo64:NUCLEO64-F302R8 U?
U 1 1 5FFC73EF
P 5500 3500
F 0 "U?" H 4800 5475 50  0000 R CNN
F 1 "NUCLEO64-F302R8" H 4800 5400 50  0000 R CNN
F 2 "Module:ST_Morpho_Connector_144_STLink" H 6050 1600 50  0001 L CNN
F 3 "" H 4600 2100 50  0001 C CNN
	1    5500 3500
	1    0    0    -1  
$EndComp
$Comp
L Connector:USB_B_Micro J?
U 1 1 5FFCA885
P 1200 1200
F 0 "J?" H 1000 1650 50  0000 L CNN
F 1 "USB_B_Micro" H 1000 1550 50  0000 L CNN
F 2 "" H 1350 1150 50  0001 C CNN
F 3 "~" H 1350 1150 50  0001 C CNN
	1    1200 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6600 3100 7000 3100
Wire Wire Line
	6600 3200 7000 3200
Text GLabel 7000 3100 2    50   Input ~ 0
USB_DM
Text GLabel 7000 3200 2    50   Input ~ 0
USB_DP
Text GLabel 2000 1300 2    50   Input ~ 0
USB_DM
Text GLabel 2000 1200 2    50   Input ~ 0
USB_DP
Wire Wire Line
	2000 1200 1500 1200
Wire Wire Line
	2000 1300 1500 1300
NoConn ~ 1500 1400
Wire Wire Line
	6600 4400 7000 4400
Wire Wire Line
	6600 4500 7000 4500
Text GLabel 7000 4400 2    50   Input ~ 0
CAN_RX
Text GLabel 7000 4500 2    50   Input ~ 0
CAN_TX
NoConn ~ 5600 1500
$Comp
L power:+5V #PWR?
U 1 1 5FFDA7C3
P 5000 1400
F 0 "#PWR?" H 5000 1250 50  0001 C CNN
F 1 "+5V" H 5000 1540 50  0000 C CNN
F 2 "" H 5000 1400 50  0001 C CNN
F 3 "" H 5000 1400 50  0001 C CNN
	1    5000 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 1400 5000 1500
$Comp
L power:+5V #PWR?
U 1 1 5FFDACC9
P 1600 900
F 0 "#PWR?" H 1600 750 50  0001 C CNN
F 1 "+5V" H 1600 1040 50  0000 C CNN
F 2 "" H 1600 900 50  0001 C CNN
F 3 "" H 1600 900 50  0001 C CNN
	1    1600 900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 900  1600 1000
Wire Wire Line
	1600 1000 1500 1000
$Comp
L power:GND #PWR?
U 1 1 5FFDC73C
P 1200 1700
F 0 "#PWR?" H 1200 1450 50  0001 C CNN
F 1 "GND" H 1200 1550 50  0000 C CNN
F 2 "" H 1200 1700 50  0001 C CNN
F 3 "" H 1200 1700 50  0001 C CNN
	1    1200 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 1700 1200 1600
$Comp
L power:GND #PWR?
U 1 1 5FFDCDBD
P 4900 5800
F 0 "#PWR?" H 4900 5550 50  0001 C CNN
F 1 "GND" H 4900 5650 50  0000 C CNN
F 2 "" H 4900 5800 50  0001 C CNN
F 3 "" H 4900 5800 50  0001 C CNN
	1    4900 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 5800 4900 5650
Wire Wire Line
	4900 5650 5000 5650
Wire Wire Line
	5800 5650 5800 5500
Connection ~ 4900 5650
Wire Wire Line
	4900 5650 4900 5500
Wire Wire Line
	5700 5500 5700 5650
Connection ~ 5700 5650
Wire Wire Line
	5700 5650 5800 5650
Wire Wire Line
	5600 5500 5600 5650
Connection ~ 5600 5650
Wire Wire Line
	5600 5650 5700 5650
Wire Wire Line
	5500 5500 5500 5650
Connection ~ 5500 5650
Wire Wire Line
	5500 5650 5600 5650
Wire Wire Line
	5400 5500 5400 5650
Connection ~ 5400 5650
Wire Wire Line
	5400 5650 5500 5650
Wire Wire Line
	5300 5500 5300 5650
Connection ~ 5300 5650
Wire Wire Line
	5300 5650 5400 5650
Wire Wire Line
	5200 5500 5200 5650
Connection ~ 5200 5650
Wire Wire Line
	5200 5650 5300 5650
Wire Wire Line
	5100 5500 5100 5650
Connection ~ 5100 5650
Wire Wire Line
	5100 5650 5200 5650
Wire Wire Line
	5000 5500 5000 5650
Connection ~ 5000 5650
Wire Wire Line
	5000 5650 5100 5650
$EndSCHEMATC
