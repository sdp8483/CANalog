EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr B 17000 11000
encoding utf-8
Sheet 1 1
Title "CANalog"
Date ""
Rev ""
Comp "Perry Leumas"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text GLabel 1700 3350 2    50   Input ~ 0
USB_DM
Text GLabel 1700 3250 2    50   Input ~ 0
USB_DP
NoConn ~ 1200 3450
$Comp
L power:GND #PWR02
U 1 1 5FFDC73C
P 900 3750
F 0 "#PWR02" H 900 3500 50  0001 C CNN
F 1 "GND" H 900 3600 50  0000 C CNN
F 2 "" H 900 3750 50  0001 C CNN
F 3 "" H 900 3750 50  0001 C CNN
	1    900  3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	900  3750 900  3700
$Comp
L Connector:USB_B_Micro J2
U 1 1 5FFCA885
P 900 3250
F 0 "J2" H 700 3700 50  0000 L CNN
F 1 "USB_B_Micro" H 700 3600 50  0000 L CNN
F 2 "Connector_USB:USB_Micro-B_Molex-105017-0001" H 1050 3200 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/2002271812_XKB-Connectivity-U254-051T-4BHJ25-S2S_C319163.pdf" H 1050 3200 50  0001 C CNN
F 4 " U254-051T-4BHJ25-S2S" H 900 3250 50  0001 C CNN "MPN"
F 5 " XKB Connectivity" H 900 3250 50  0001 C CNN "Manufacture"
F 6 "C319163" H 900 3250 50  0001 C CNN "SPN"
F 7 "LCSC" H 900 3250 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/USB-Connectors_XKB-Connectivity-U254-051T-4BHJ25-S2S_C319163.html" H 900 3250 50  0001 C CNN "Supplier Link"
	1    900  3250
	1    0    0    -1  
$EndComp
Text Notes 600  2750 0    50   ~ 0
USB Data and Power
Wire Notes Line
	600  2750 2150 2750
Wire Notes Line
	2150 3950 600  3950
Wire Notes Line
	600  3950 600  2650
Wire Notes Line
	600  2650 2150 2650
Wire Notes Line
	2150 2650 2150 3950
$Comp
L power:VBUS #PWR06
U 1 1 60A975AF
P 1700 2950
F 0 "#PWR06" H 1700 2800 50  0001 C CNN
F 1 "VBUS" H 1700 3100 50  0000 C CNN
F 2 "" H 1700 2950 50  0001 C CNN
F 3 "" H 1700 2950 50  0001 C CNN
	1    1700 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 3050 1200 3050
$Comp
L Device:R R2
U 1 1 60C278F0
P 1450 3350
F 0 "R2" V 1530 3350 50  0000 C CNN
F 1 "0" V 1450 3350 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 1380 3350 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1809281528_YAGEO-RC0603JR-070RL_C95177.pdf" H 1450 3350 50  0001 C CNN
F 4 "RC0603JR-070RL" H 1450 3350 50  0001 C CNN "MPN"
F 5 "YAGEO" H 1450 3350 50  0001 C CNN "Manufacture"
F 6 "C95177" H 1450 3350 50  0001 C CNN "SPN"
F 7 "LCSC" H 1450 3350 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_0R-0R-5_C95177.html" H 1450 3350 50  0001 C CNN "Supplier Link"
	1    1450 3350
	0    1    1    0   
$EndComp
$Comp
L Device:R R1
U 1 1 60C2A8A7
P 1450 3250
F 0 "R1" V 1530 3250 50  0000 C CNN
F 1 "0" V 1450 3250 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 1380 3250 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1809281528_YAGEO-RC0603JR-070RL_C95177.pdf" H 1450 3250 50  0001 C CNN
F 4 "RC0603JR-070RL" H 1450 3250 50  0001 C CNN "MPN"
F 5 "YAGEO" H 1450 3250 50  0001 C CNN "Manufacture"
F 6 "C95177" H 1450 3250 50  0001 C CNN "SPN"
F 7 "LCSC" H 1450 3250 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_0R-0R-5_C95177.html" H 1450 3250 50  0001 C CNN "Supplier Link"
	1    1450 3250
	0    1    -1   0   
$EndComp
Wire Wire Line
	1200 3250 1300 3250
Wire Wire Line
	1200 3350 1300 3350
Wire Wire Line
	1600 3250 1700 3250
Wire Wire Line
	1600 3350 1700 3350
$Comp
L Connector_Generic:Conn_01x02 J1
U 1 1 612F8AEC
P 800 1100
F 0 "J1" H 800 1200 50  0000 C CNN
F 1 "PWR" H 800 900 50  0000 C CNN
F 2 "pl_TerminalBlock:WJ127-5.0-2P" H 800 1100 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1912251631_Ningbo-Kangnex-Elec-WJ127-5-0-2P_C3703.pdf" H 800 1100 50  0001 C CNN
F 4 " WJ127-5.0-2P" H 800 1100 50  0001 C CNN "MPN"
F 5 " Ningbo Kangnex Elec" H 800 1100 50  0001 C CNN "Manufacture"
F 6 "C3703" H 800 1100 50  0001 C CNN "SPN"
F 7 "LCSC" H 800 1100 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Screw-terminal_Ningbo-Kangnex-Elec-WJ127-5-0-2P_C3703.html" H 800 1100 50  0001 C CNN "Supplier Link"
	1    800  1100
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1100 2000 1100 1200
Text Notes 2250 650  0    50   ~ 0
5V5 DC-DC Converter
$Comp
L pl_DCDC:BL9342 U1
U 1 1 617A231F
P 3600 1100
F 0 "U1" H 3900 500 50  0000 C CNN
F 1 "BL9342" H 3600 850 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6" H 3600 1100 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1809050135_BL-Shanghai-Belling-BL9342_C93176.pdf" H 3600 1100 50  0001 C CNN
F 4 "BL9342" H 3600 1100 50  0001 C CNN "MPN"
F 5 "BL(Shanghai Belling)" H 3600 1100 50  0001 C CNN "Manufacture"
F 6 "C93176" H 3600 1100 50  0001 C CNN "SPN"
F 7 "LCSC" H 3600 1100 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/DC-DC-Converters_BL-Shanghai-Belling-BL9342_C93176.html" H 3600 1100 50  0001 C CNN "Supplier Link"
	1    3600 1100
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_PMOS_GSD Q1
U 1 1 617CDA23
P 1500 1200
F 0 "Q1" V 1400 1050 50  0000 C CNN
F 1 "DMP3099L-7" V 1750 1200 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 1700 1300 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMP3099L.pdf" H 1500 1200 50  0001 C CNN
F 4 "DMP3099L-7" H 1500 1200 50  0001 C CNN "MPN"
F 5 "Diodes Incorporated" H 1500 1200 50  0001 C CNN "Manufacture"
F 6 "DMP3099L-7DICT-ND" H 1500 1200 50  0001 C CNN "SPN"
F 7 "DigiKey" H 1500 1200 50  0001 C CNN "Supplier"
F 8 "https://www.digikey.com/en/products/detail/diodes-incorporated/DMP3099L-7/4471075?s=N4IgTCBcDaICYFsAOBmADATgwGwLQHYQBdAXyA" H 1500 1200 50  0001 C CNN "Supplier Link"
	1    1500 1200
	0    -1   -1   0   
$EndComp
$Comp
L Device:D_Zener D1
U 1 1 618104D7
P 1900 1350
F 0 "D1" H 1900 1450 50  0000 C CNN
F 1 "BZV55-C15" H 1900 1250 50  0000 C CNN
F 2 "pl_Diode:Nexperia_BZV55_SOD80C" H 1900 1350 50  0001 C CNN
F 3 "https://rocelec.widen.net/view/pdf/mmjrjopmpw/PHGLS22257-1.pdf?t.download=true&u=5oefqw" H 1900 1350 50  0001 C CNN
F 4 "BZV55-C15,115" H 1900 1350 50  0001 C CNN "MPN"
F 5 "Nexperia USA Inc." H 1900 1350 50  0001 C CNN "Manufacture"
F 6 "1727-4962-1-ND" H 1900 1350 50  0001 C CNN "SPN"
F 7 "DigiKey" H 1900 1350 50  0001 C CNN "Supplier"
F 8 "https://www.digikey.com/en/products/detail/nexperia-usa-inc/BZV55-C15-115/1155548?s=N4IgTCBcDaIIwHYwILQBYCcA2MK4oDsATEAXQF8g" H 1900 1350 50  0001 C CNN "Supplier Link"
	1    1900 1350
	0    -1   1    0   
$EndComp
Wire Wire Line
	1900 1200 1900 1100
$Comp
L Device:R R3
U 1 1 6181FB2B
P 1500 1750
F 0 "R3" V 1580 1750 50  0000 C CNN
F 1 "10k" V 1500 1750 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 1430 1750 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1811081617_YAGEO-RC0603JR-0710KL_C99198.pdf" H 1500 1750 50  0001 C CNN
F 4 "RC0603JR-0710KL" H 1500 1750 50  0001 C CNN "MPN"
F 5 "YAGEO" H 1500 1750 50  0001 C CNN "Manufacture"
F 6 "C99198" H 1500 1750 50  0001 C CNN "SPN"
F 7 "LCSC" H 1500 1750 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_YAGEO-RC0603JR-0710KL_C99198.html" H 1500 1750 50  0001 C CNN "Supplier Link"
	1    1500 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 1600 1500 1550
Wire Wire Line
	1900 1500 1900 1550
Wire Wire Line
	1900 1550 1500 1550
Connection ~ 1500 1550
Wire Wire Line
	1500 1550 1500 1400
$Comp
L power:GND #PWR05
U 1 1 6183DA7C
P 1500 2150
F 0 "#PWR05" H 1500 1900 50  0001 C CNN
F 1 "GND" H 1500 2000 50  0000 C CNN
F 2 "" H 1500 2150 50  0001 C CNN
F 3 "" H 1500 2150 50  0001 C CNN
	1    1500 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 2150 1500 2000
$Comp
L Device:C C1
U 1 1 618C235C
P 2450 1350
F 0 "C1" H 2475 1450 50  0000 L CNN
F 1 "4.7uF" H 2475 1250 50  0000 L CNN
F 2 "C_0805_2012Metric" H 2488 1200 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1810191224_Samsung-Electro-Mechanics-CL21A475KBQNNNE_C98192.pdf" H 2450 1350 50  0001 C CNN
F 4 "CL21A475KBQNNNE" H 2450 1350 50  0001 C CNN "MPN"
F 5 "Samsung Electro-Mechanics" H 2450 1350 50  0001 C CNN "Manufacture"
F 6 "C98192" H 2450 1350 50  0001 C CNN "SPN"
F 7 "LCSC" H 2450 1350 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Multilayer-Ceramic-Capacitors-MLCC-SMD-SMT_Samsung-Electro-Mechanics-CL21A475KBQNNNE_C98192.html" H 2450 1350 50  0001 C CNN "Supplier Link"
	1    2450 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 1100 1900 1100
Wire Wire Line
	2450 1200 2450 1100
$Comp
L power:GND #PWR010
U 1 1 61931AFB
P 2450 1550
F 0 "#PWR010" H 2450 1300 50  0001 C CNN
F 1 "GND" H 2450 1400 50  0000 C CNN
F 2 "" H 2450 1550 50  0001 C CNN
F 3 "" H 2450 1550 50  0001 C CNN
	1    2450 1550
	1    0    0    -1  
$EndComp
$Comp
L Device:D_Schottky D3
U 1 1 61A146E2
P 4600 1350
F 0 "D3" H 4600 1450 50  0000 C CNN
F 1 "SS14F" H 4600 1250 50  0000 C CNN
F 2 "pl_Diode:SMAF" H 4600 1350 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1811031612_Shandong-Jingdao-Microelectronics-SS14F_C108832.pdf" H 4600 1350 50  0001 C CNN
F 4 "SS14F" H 4600 1350 50  0001 C CNN "MPN"
F 5 "Shandong Jingdao Microelectronics" H 4600 1350 50  0001 C CNN "Manufacture"
F 6 "C108832" H 4600 1350 50  0001 C CNN "SPN"
F 7 "LCSC" H 4600 1350 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Schottky-Barrier-Diodes-SBD_Shandong-Jingdao-Microelectronics-SS14F_C108832.html" H 4600 1350 50  0001 C CNN "Supplier Link"
	1    4600 1350
	0    1    1    0   
$EndComp
Wire Wire Line
	4600 1100 4600 1200
$Comp
L power:GND #PWR023
U 1 1 61A2690E
P 4600 1600
F 0 "#PWR023" H 4600 1350 50  0001 C CNN
F 1 "GND" H 4600 1450 50  0000 C CNN
F 2 "" H 4600 1600 50  0001 C CNN
F 3 "" H 4600 1600 50  0001 C CNN
	1    4600 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 1600 4600 1500
$Comp
L Device:L L1
U 1 1 61A5E8B2
P 4800 1100
F 0 "L1" V 4750 1100 50  0000 C CNN
F 1 "2.2uH" V 4875 1100 50  0000 C CNN
F 2 "pl_Inductor:L_3.5mmx3.0mm_SMD" H 4800 1100 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/2011091134_PROD-Tech-PSPCAQ32-2R2M_C436276.pdf" H 4800 1100 50  0001 C CNN
F 4 "PSPCAQ32-2R2M" H 4800 1100 50  0001 C CNN "MPN"
F 5 " PROD Tech" H 4800 1100 50  0001 C CNN "Manufacture"
F 6 "C436276" H 4800 1100 50  0001 C CNN "SPN"
F 7 "LCSC" H 4800 1100 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Power-Inductors_PROD-Tech-PSPCAQ32-2R2M_C436276.html" H 4800 1100 50  0001 C CNN "Supplier Link"
	1    4800 1100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4600 1100 4650 1100
$Comp
L Device:C C7
U 1 1 61A70D2B
P 5000 1350
F 0 "C7" H 5025 1450 50  0000 L CNN
F 1 "10uF" H 5025 1250 50  0000 L CNN
F 2 "C_0805_2012Metric" H 5038 1200 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1811011704_Samsung-Electro-Mechanics-CL21A106KPFNNNE_C17024.pdf" H 5000 1350 50  0001 C CNN
F 4 "CL21A106KPFNNNE" H 5000 1350 50  0001 C CNN "MPN"
F 5 "Samsung Electro-Mechanics" H 5000 1350 50  0001 C CNN "Manufacture"
F 6 "C17024" H 5000 1350 50  0001 C CNN "SPN"
F 7 "LCSC" H 5000 1350 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Multilayer-Ceramic-Capacitors-MLCC-SMD-SMT_Samsung-Electro-Mechanics-CL21A106KPFNNNE_C17024.html" H 5000 1350 50  0001 C CNN "Supplier Link"
	1    5000 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 1100 5000 1100
Wire Wire Line
	5000 1100 5000 1200
$Comp
L power:GND #PWR024
U 1 1 61A83685
P 5000 1600
F 0 "#PWR024" H 5000 1350 50  0001 C CNN
F 1 "GND" H 5000 1450 50  0000 C CNN
F 2 "" H 5000 1600 50  0001 C CNN
F 3 "" H 5000 1600 50  0001 C CNN
	1    5000 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 1600 5000 1500
$Comp
L Device:R R12
U 1 1 61AB0DAD
P 5300 1350
F 0 "R12" V 5380 1350 50  0000 C CNN
F 1 "124k" V 5300 1350 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5230 1350 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1810170511_UNI-ROYAL-Uniroyal-Elec-0603WAF1243T5E_C22788.pdf" H 5300 1350 50  0001 C CNN
F 4 "0603WAF1243T5E" H 5300 1350 50  0001 C CNN "MPN"
F 5 " UNI-ROYAL(Uniroyal Elec)" H 5300 1350 50  0001 C CNN "Manufacture"
F 6 "C22788" H 5300 1350 50  0001 C CNN "SPN"
F 7 "LCSC" H 5300 1350 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_UNI-ROYAL-Uniroyal-Elec-0603WAF1243T5E_C22788.html" H 5300 1350 50  0001 C CNN "Supplier Link"
	1    5300 1350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R13
U 1 1 61AB239C
P 5850 1850
F 0 "R13" V 5930 1850 50  0000 C CNN
F 1 "20.5k" V 5850 1850 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5780 1850 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1912111437_UNI-ROYAL-Uniroyal-Elec-0603WAD2052T5E_C423063.pdf" H 5850 1850 50  0001 C CNN
F 4 "0603WAD2052T5E" H 5850 1850 50  0001 C CNN "MPN"
F 5 " UNI-ROYAL(Uniroyal Elec)" H 5850 1850 50  0001 C CNN "Manufacture"
F 6 "C423063" H 5850 1850 50  0001 C CNN "SPN"
F 7 "LCSC" H 5850 1850 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_UNI-ROYAL-Uniroyal-Elec-0603WAD2052T5E_C423063.html" H 5850 1850 50  0001 C CNN "Supplier Link"
	1    5850 1850
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR027
U 1 1 61AB3EC8
P 6100 1950
F 0 "#PWR027" H 6100 1700 50  0001 C CNN
F 1 "GND" H 6100 1800 50  0000 C CNN
F 2 "" H 6100 1950 50  0001 C CNN
F 3 "" H 6100 1950 50  0001 C CNN
	1    6100 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:C C9
U 1 1 61AB57E6
P 5550 1350
F 0 "C9" H 5575 1450 50  0000 L CNN
F 1 "33pF" H 5575 1250 50  0000 L CNN
F 2 "C_0603_1608Metric" H 5588 1200 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1912111437_Chinocera-HGC0603G0330J500NTHJ_C465159.pdf" H 5550 1350 50  0001 C CNN
F 4 "HGC0603G0330J500NTHJ" H 5550 1350 50  0001 C CNN "MPN"
F 5 "Chinocera" H 5550 1350 50  0001 C CNN "Manufacture"
F 6 "C465159" H 5550 1350 50  0001 C CNN "SPN"
F 7 "LCSC" H 5550 1350 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Multilayer-Ceramic-Capacitors-MLCC-SMD-SMT_Chinocera-HGC0603G0330J500NTHJ_C465159.html" H 5550 1350 50  0001 C CNN "Supplier Link"
	1    5550 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 1100 5300 1100
Wire Wire Line
	5300 1100 5300 1200
Connection ~ 5000 1100
Connection ~ 5300 1100
Wire Wire Line
	5300 1100 5550 1100
Wire Wire Line
	5550 1100 5550 1200
Wire Wire Line
	5550 1850 5550 1500
Connection ~ 2450 1100
Wire Wire Line
	1000 1100 1300 1100
Text Notes 600  650  0    50   ~ 0
Power Input with Polarity Protection
Wire Notes Line
	600  650  2150 650 
Wire Notes Line
	2150 2550 600  2550
Wire Notes Line
	600  2550 600  550 
Wire Notes Line
	600  550  2150 550 
Wire Notes Line
	2150 550  2150 2550
Wire Wire Line
	4050 1600 4150 1600
Wire Wire Line
	4150 1600 4150 1500
Wire Wire Line
	4150 1200 4150 1100
Wire Wire Line
	4150 1100 4050 1100
Wire Wire Line
	4150 1100 4600 1100
Connection ~ 4150 1100
Connection ~ 4600 1100
Connection ~ 5550 1850
Wire Notes Line
	2250 650  6300 650 
Wire Notes Line
	6300 2550 2250 2550
Wire Notes Line
	2250 2550 2250 550 
Wire Notes Line
	2250 550  6300 550 
Wire Notes Line
	6300 550  6300 2550
Wire Wire Line
	1900 1100 2450 1100
Text Label 2000 1100 0    50   ~ 0
Vin
$Comp
L power:+5VA #PWR08
U 1 1 6315E07F
P 2000 9800
F 0 "#PWR08" H 2000 9650 50  0001 C CNN
F 1 "+5VA" H 2000 9940 50  0000 C CNN
F 2 "" H 2000 9800 50  0001 C CNN
F 3 "" H 2000 9800 50  0001 C CNN
	1    2000 9800
	-1   0    0    1   
$EndComp
$Comp
L power:PWR_FLAG #FLG05
U 1 1 63164A1A
P 2000 9700
F 0 "#FLG05" H 2000 9775 50  0001 C CNN
F 1 "PWR_FLAG" H 2000 9850 50  0000 C CNN
F 2 "" H 2000 9700 50  0001 C CNN
F 3 "~" H 2000 9700 50  0001 C CNN
	1    2000 9700
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 9700 2000 9800
$Comp
L power:+5V #PWR04
U 1 1 631E86B1
P 1400 9800
F 0 "#PWR04" H 1400 9650 50  0001 C CNN
F 1 "+5V" H 1400 9940 50  0000 C CNN
F 2 "" H 1400 9800 50  0001 C CNN
F 3 "" H 1400 9800 50  0001 C CNN
	1    1400 9800
	-1   0    0    1   
$EndComp
$Comp
L power:PWR_FLAG #FLG03
U 1 1 6322073C
P 1400 9700
F 0 "#FLG03" H 1400 9775 50  0001 C CNN
F 1 "PWR_FLAG" H 1400 9850 50  0000 C CNN
F 2 "" H 1400 9700 50  0001 C CNN
F 3 "~" H 1400 9700 50  0001 C CNN
	1    1400 9700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1400 9800 1400 9700
$Comp
L Device:C C3
U 1 1 6358B59E
P 4150 1350
F 0 "C3" H 4175 1450 50  0000 L CNN
F 1 "100nF" H 4175 1250 50  0000 L CNN
F 2 "C_0603_1608Metric" H 4188 1200 50  0001 C CNN
F 3 "https://api.kemet.com/component-edge/download/datasheet/C0603C104Z3VACTU.pdf" H 4150 1350 50  0001 C CNN
F 4 "C0603C104Z3VACTU" H 4150 1350 50  0001 C CNN "MPN"
F 5 "KEMET" H 4150 1350 50  0001 C CNN "Manufacture"
F 6 "399-1100-1-ND" H 4150 1350 50  0001 C CNN "SPN"
F 7 "DigiKey" H 4150 1350 50  0001 C CNN "Supplier"
F 8 "https://www.digikey.com/en/products/detail/kemet/C0603C104Z3VACTU/411099?s=N4IgTCBcDaIMwE4EFoCMqAMG3IHYBMQBdAXyA" H 4150 1350 50  0001 C CNN "Supplier Link"
	1    4150 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	800  3650 800  3700
Wire Wire Line
	800  3700 900  3700
Connection ~ 900  3700
Wire Wire Line
	900  3700 900  3650
Wire Wire Line
	1100 1200 1000 1200
$Comp
L Regulator_Linear:MIC5504-3.3YM5 U5
U 1 1 60DBDCAC
P 9200 1200
F 0 "U5" H 9400 950 50  0000 L CNN
F 1 "MIC5504-3.3YM5" H 8900 1450 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5" H 9200 800 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/MIC550X.pdf" H 8950 1450 50  0001 C CNN
F 4 "MIC5504-3.3YM5-TR" H 9200 1200 50  0001 C CNN "MPN"
F 5 "Microchip Technology" H 9200 1200 50  0001 C CNN "Manufacture"
F 6 "576-4764-1-ND" H 9200 1200 50  0001 C CNN "SPN"
F 7 "DigiKey" H 9200 1200 50  0001 C CNN "Supplier"
F 8 "https://www.digikey.com/en/products/detail/MIC5504-3.3YM5-TR/576-4764-1-ND/4864028?itemSeq=359217799" H 9200 1200 50  0001 C CNN "Supplier Link"
	1    9200 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 1850 5550 1850
Wire Wire Line
	5300 1500 5300 1850
Connection ~ 5300 1850
Wire Wire Line
	3700 1850 3700 1750
Wire Wire Line
	3700 1850 5300 1850
Wire Wire Line
	6100 1950 6100 1850
Wire Wire Line
	6100 1850 6000 1850
Wire Wire Line
	5700 1850 5550 1850
$Comp
L Device:C C14
U 1 1 60FAAE32
P 8400 1450
F 0 "C14" H 8425 1550 50  0000 L CNN
F 1 "1uF" H 8425 1350 50  0000 L CNN
F 2 "C_0603_1608Metric" H 8438 1300 50  0001 C CNN
F 3 "https://www.samsungsem.com/resources/file/global/support/product_catalog/MLCC.pdf" H 8400 1450 50  0001 C CNN
F 4 "CL10A105KQ8NNNC" H 8400 1450 50  0001 C CNN "MPN"
F 5 "Samsung Electro-Mechanics" H 8400 1450 50  0001 C CNN "Manufacture"
F 6 "1276-1036-1-ND" H 8400 1450 50  0001 C CNN "SPN"
F 7 "DigiKey" H 8400 1450 50  0001 C CNN "Supplier"
F 8 "https://www.digikey.com/en/products/detail/samsung-electro-mechanics/CL10A105KQ8NNNC/3886694?s=N4IgTCBcDaIIxgOwDYC0cAMBmNdUDsATEAXQF8g" H 8400 1450 50  0001 C CNN "Supplier Link"
	1    8400 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:C C15
U 1 1 60FAB65B
P 10000 1450
F 0 "C15" H 10025 1550 50  0000 L CNN
F 1 "1uF" H 10025 1350 50  0000 L CNN
F 2 "C_0603_1608Metric" H 10038 1300 50  0001 C CNN
F 3 "https://www.samsungsem.com/resources/file/global/support/product_catalog/MLCC.pdf" H 10000 1450 50  0001 C CNN
F 4 "CL10A105KQ8NNNC" H 10000 1450 50  0001 C CNN "MPN"
F 5 "Samsung Electro-Mechanics" H 10000 1450 50  0001 C CNN "Manufacture"
F 6 "1276-1036-1-ND" H 10000 1450 50  0001 C CNN "SPN"
F 7 "DigiKey" H 10000 1450 50  0001 C CNN "Supplier"
F 8 "https://www.digikey.com/en/products/detail/samsung-electro-mechanics/CL10A105KQ8NNNC/3886694?s=N4IgTCBcDaIIxgOwDYC0cAMBmNdUDsATEAXQF8g" H 10000 1450 50  0001 C CNN "Supplier Link"
	1    10000 1450
	1    0    0    -1  
$EndComp
Text Notes 3800 2250 0    50   ~ 0
Vfb = Vout * Rg/(Rf+Rg)\nRf = 124k for optimal response\nVfb = 0.794 typ
Text Notes 5800 1750 0    50   ~ 0
Rg
Text Notes 5250 1400 1    50   ~ 0
Rf
$Comp
L Amplifier_Operational:LMV321 U2
U 1 1 61003A99
P 7100 1750
F 0 "U2" H 7100 1950 50  0000 L CNN
F 1 "RS321BXF" H 7100 1550 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5" H 7100 1750 50  0001 L CNN
F 3 "https://datasheet.lcsc.com/szlcsc/2010160334_Jiangsu-RUNIC-Tech-RS321BXF_C237022.pdf" H 7100 1750 50  0001 C CNN
F 4 "RS321BXF" H 7100 1750 50  0001 C CNN "MPN"
F 5 "Jiangsu RUNIC Tech" H 7100 1750 50  0001 C CNN "Manufacture"
F 6 "C237022" H 7100 1750 50  0001 C CNN "SPN"
F 7 "LCSC" H 7100 1750 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/General-Purpose-Amplifiers_Jiangsu-RUNIC-Tech-RS321BXF_C237022.html" H 7100 1750 50  0001 C CNN "Supplier Link"
	1    7100 1750
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_PMOS_GSD Q3
U 1 1 6100AD13
P 7800 1750
F 0 "Q3" V 7700 1600 50  0000 C CNN
F 1 "DMP3099L-7" V 8050 1750 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 8000 1850 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMP3099L.pdf" H 7800 1750 50  0001 C CNN
F 4 "DMP3099L-7" H 7800 1750 50  0001 C CNN "MPN"
F 5 "Diodes Incorporated" H 7800 1750 50  0001 C CNN "Manufacture"
F 6 "DMP3099L-7DICT-ND" H 7800 1750 50  0001 C CNN "SPN"
F 7 "DigiKey" H 7800 1750 50  0001 C CNN "Supplier"
F 8 "https://www.digikey.com/en/products/detail/diodes-incorporated/DMP3099L-7/4471075?s=N4IgTCBcDaICYFsAOBmADATgwGwLQHYQBdAXyA" H 7800 1750 50  0001 C CNN "Supplier Link"
	1    7800 1750
	1    0    0    1   
$EndComp
Wire Wire Line
	8800 1300 8700 1300
Wire Wire Line
	8700 1300 8700 1100
Wire Wire Line
	8700 1100 8800 1100
Wire Wire Line
	8400 1300 8400 1100
Wire Wire Line
	8400 1100 8700 1100
Connection ~ 8700 1100
Wire Wire Line
	9600 1100 10000 1100
Wire Wire Line
	10000 1100 10000 1300
$Comp
L power:GND #PWR050
U 1 1 6108889C
P 9200 1850
F 0 "#PWR050" H 9200 1600 50  0001 C CNN
F 1 "GND" H 9200 1700 50  0000 C CNN
F 2 "" H 9200 1850 50  0001 C CNN
F 3 "" H 9200 1850 50  0001 C CNN
	1    9200 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	9200 1850 9200 1750
Wire Wire Line
	8400 1600 8400 1750
Wire Wire Line
	8400 1750 9200 1750
Connection ~ 9200 1750
Wire Wire Line
	9200 1750 9200 1500
Wire Wire Line
	9200 1750 10000 1750
Wire Wire Line
	10000 1750 10000 1600
$Comp
L power:+3V3 #PWR052
U 1 1 610C51AB
P 10000 1000
F 0 "#PWR052" H 10000 850 50  0001 C CNN
F 1 "+3V3" H 10000 1140 50  0000 C CNN
F 2 "" H 10000 1000 50  0001 C CNN
F 3 "" H 10000 1000 50  0001 C CNN
	1    10000 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	10000 1000 10000 1100
Connection ~ 10000 1100
$Comp
L power:VBUS #PWR043
U 1 1 610E464E
P 7900 2200
F 0 "#PWR043" H 7900 2050 50  0001 C CNN
F 1 "VBUS" H 7900 2350 50  0000 C CNN
F 2 "" H 7900 2200 50  0001 C CNN
F 3 "" H 7900 2200 50  0001 C CNN
	1    7900 2200
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR035
U 1 1 6116409F
P 7000 2150
F 0 "#PWR035" H 7000 1900 50  0001 C CNN
F 1 "GND" H 7000 2000 50  0000 C CNN
F 2 "" H 7000 2150 50  0001 C CNN
F 3 "" H 7000 2150 50  0001 C CNN
	1    7000 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 2150 7000 2050
$Comp
L power:+3V3 #PWR031
U 1 1 6119211E
P 6700 1850
F 0 "#PWR031" H 6700 1700 50  0001 C CNN
F 1 "+3V3" H 6700 1990 50  0000 C CNN
F 2 "" H 6700 1850 50  0001 C CNN
F 3 "" H 6700 1850 50  0001 C CNN
	1    6700 1850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6700 1850 6800 1850
$Comp
L power:+5V #PWR046
U 1 1 611E72B6
P 8400 1000
F 0 "#PWR046" H 8400 850 50  0001 C CNN
F 1 "+5V" H 8400 1140 50  0000 C CNN
F 2 "" H 8400 1000 50  0001 C CNN
F 3 "" H 8400 1000 50  0001 C CNN
	1    8400 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	8400 1000 8400 1100
Connection ~ 8400 1100
$Comp
L Device:C C11
U 1 1 6123289C
P 7250 1400
F 0 "C11" H 7275 1500 50  0000 L CNN
F 1 "100nF" H 7275 1300 50  0000 L CNN
F 2 "C_0603_1608Metric" H 7288 1250 50  0001 C CNN
F 3 "https://api.kemet.com/component-edge/download/datasheet/C0603C104Z3VACTU.pdf" H 7250 1400 50  0001 C CNN
F 4 "C0603C104Z3VACTU" H 7250 1400 50  0001 C CNN "MPN"
F 5 "KEMET" H 7250 1400 50  0001 C CNN "Manufacture"
F 6 "399-1100-1-ND" H 7250 1400 50  0001 C CNN "SPN"
F 7 "DigiKey" H 7250 1400 50  0001 C CNN "Supplier"
F 8 "https://www.digikey.com/en/products/detail/kemet/C0603C104Z3VACTU/411099?s=N4IgTCBcDaIMwE4EFoCMqAMG3IHYBMQBdAXyA" H 7250 1400 50  0001 C CNN "Supplier Link"
	1    7250 1400
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR039
U 1 1 61233939
P 7450 1450
F 0 "#PWR039" H 7450 1200 50  0001 C CNN
F 1 "GND" H 7450 1300 50  0000 C CNN
F 2 "" H 7450 1450 50  0001 C CNN
F 3 "" H 7450 1450 50  0001 C CNN
	1    7450 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 1450 7450 1400
Wire Wire Line
	7450 1400 7400 1400
Wire Wire Line
	7100 1400 7000 1400
Wire Wire Line
	7000 1400 7000 1450
Wire Wire Line
	7400 1750 7600 1750
$Comp
L Device:D_Schottky D5
U 1 1 6127D939
P 5850 1100
F 0 "D5" H 5850 1200 50  0000 C CNN
F 1 "SS14F" H 5850 1000 50  0000 C CNN
F 2 "pl_Diode:SMAF" H 5850 1100 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1811031612_Shandong-Jingdao-Microelectronics-SS14F_C108832.pdf" H 5850 1100 50  0001 C CNN
F 4 "SS14F" H 5850 1100 50  0001 C CNN "MPN"
F 5 "Shandong Jingdao Microelectronics" H 5850 1100 50  0001 C CNN "Manufacture"
F 6 "C108832" H 5850 1100 50  0001 C CNN "SPN"
F 7 "LCSC" H 5850 1100 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Schottky-Barrier-Diodes-SBD_Shandong-Jingdao-Microelectronics-SS14F_C108832.html" H 5850 1100 50  0001 C CNN "Supplier Link"
	1    5850 1100
	-1   0    0    1   
$EndComp
Wire Wire Line
	5700 1100 5550 1100
Connection ~ 5550 1100
Text Label 5500 1100 2    50   ~ 0
5V5
Text Label 6600 1650 2    50   ~ 0
5V5
Wire Wire Line
	6600 1650 6800 1650
Wire Wire Line
	7900 2200 7900 1950
Text Notes 6400 650  0    50   ~ 0
USB Input Voltage Selection
Wire Wire Line
	7000 1100 7000 1400
Wire Wire Line
	6000 1100 7000 1100
Connection ~ 7000 1400
Wire Notes Line
	6400 650  8150 650 
Wire Notes Line
	8150 2550 6400 2550
Wire Notes Line
	6400 2550 6400 550 
Wire Notes Line
	6400 550  8150 550 
Wire Notes Line
	8150 550  8150 2550
Text Notes 8250 650  0    50   ~ 0
3V3 LDO
Wire Notes Line
	8250 650  10200 650 
Wire Notes Line
	10200 2550 8250 2550
Wire Notes Line
	8250 2550 8250 550 
Wire Notes Line
	8250 550  10200 550 
Wire Notes Line
	10200 550  10200 2550
Wire Wire Line
	7000 1100 7900 1100
Connection ~ 7000 1100
$Comp
L Device:R R29
U 1 1 635EBB6A
P 12150 5550
F 0 "R29" V 12230 5550 50  0000 C CNN
F 1 "1k" V 12150 5550 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 12080 5550 50  0001 C CNN
F 3 "https://www.yageo.com/upload/media/product/productsearch/datasheet/rchip/PYu-RC_Group_51_RoHS_L_11.pdf" H 12150 5550 50  0001 C CNN
F 4 "RC0603JR-071KL" H 12150 5550 50  0001 C CNN "MPN"
F 5 "YAGEO" H 12150 5550 50  0001 C CNN "Manufacture"
F 6 "311-1.0KGRCT-ND" H 12150 5550 50  0001 C CNN "SPN"
F 7 "DigiKey" H 12150 5550 50  0001 C CNN "Supplier"
F 8 "https://www.digikey.com/en/products/detail/yageo/RC0603JR-071KL/726677?s=N4IgTCBcDaIMwEYEFoEDoAMBrA5gJwGMAXZAOwBMQBdAXyA" H 12150 5550 50  0001 C CNN "Supplier Link"
	1    12150 5550
	0    1    1    0   
$EndComp
$Comp
L Device:LED D7
U 1 1 635F6452
P 11750 5550
F 0 "D7" H 11750 5650 50  0000 C CNN
F 1 "GRN" H 11750 5450 50  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 11750 5550 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1811092313_Orient-ORH-G36G_C205443.pdf" H 11750 5550 50  0001 C CNN
F 4 "ORH-G36G" H 11750 5550 50  0001 C CNN "MPN"
F 5 "Orient" H 11750 5550 50  0001 C CNN "Manufacture"
F 6 "C205443" H 11750 5550 50  0001 C CNN "SPN"
F 7 "LCSC" H 11750 5550 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Light-Emitting-Diodes-LED_Orient-ORH-G36G_C205443.html" H 11750 5550 50  0001 C CNN "Supplier Link"
	1    11750 5550
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D9
U 1 1 635F6B4D
P 11750 6150
F 0 "D9" H 11750 6250 50  0000 C CNN
F 1 "RED" H 11750 6050 50  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 11750 6150 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/2008201032_Foshan-NationStar-Optoelectronics-NCD0603R1_C84263.pdf" H 11750 6150 50  0001 C CNN
F 4 "NCD0603R1" H 11750 6150 50  0001 C CNN "MPN"
F 5 "Foshan NationStar Optoelectronics" H 11750 6150 50  0001 C CNN "Manufacture"
F 6 "C84263" H 11750 6150 50  0001 C CNN "SPN"
F 7 "LCSC" H 11750 6150 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Light-Emitting-Diodes-LED_Foshan-NationStar-Optoelectronics-NCD0603R1_C84263.html" H 11750 6150 50  0001 C CNN "Supplier Link"
	1    11750 6150
	-1   0    0    1   
$EndComp
$Comp
L Device:R R31
U 1 1 63627AF7
P 12150 6150
F 0 "R31" V 12230 6150 50  0000 C CNN
F 1 "1k" V 12150 6150 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 12080 6150 50  0001 C CNN
F 3 "https://www.yageo.com/upload/media/product/productsearch/datasheet/rchip/PYu-RC_Group_51_RoHS_L_11.pdf" H 12150 6150 50  0001 C CNN
F 4 "RC0603JR-071KL" H 12150 6150 50  0001 C CNN "MPN"
F 5 "YAGEO" H 12150 6150 50  0001 C CNN "Manufacture"
F 6 "311-1.0KGRCT-ND" H 12150 6150 50  0001 C CNN "SPN"
F 7 "DigiKey" H 12150 6150 50  0001 C CNN "Supplier"
F 8 "https://www.digikey.com/en/products/detail/yageo/RC0603JR-071KL/726677?s=N4IgTCBcDaIMwEYEFoEDoAMBrA5gJwGMAXZAOwBMQBdAXyA" H 12150 6150 50  0001 C CNN "Supplier Link"
	1    12150 6150
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR065
U 1 1 63628CEC
P 12500 6350
F 0 "#PWR065" H 12500 6100 50  0001 C CNN
F 1 "GND" H 12500 6200 50  0000 C CNN
F 2 "" H 12500 6350 50  0001 C CNN
F 3 "" H 12500 6350 50  0001 C CNN
	1    12500 6350
	1    0    0    -1  
$EndComp
Wire Wire Line
	12300 5550 12500 5550
Wire Wire Line
	12300 6150 12500 6150
Wire Wire Line
	12500 6150 12500 6350
Wire Wire Line
	12000 5550 11900 5550
Wire Wire Line
	12000 6150 11900 6150
Wire Wire Line
	12000 5850 11900 5850
Wire Wire Line
	12300 5850 12500 5850
$Comp
L Device:R R30
U 1 1 636274C8
P 12150 5850
F 0 "R30" V 12230 5850 50  0000 C CNN
F 1 "1k" V 12150 5850 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 12080 5850 50  0001 C CNN
F 3 "https://www.yageo.com/upload/media/product/productsearch/datasheet/rchip/PYu-RC_Group_51_RoHS_L_11.pdf" H 12150 5850 50  0001 C CNN
F 4 "RC0603JR-071KL" H 12150 5850 50  0001 C CNN "MPN"
F 5 "YAGEO" H 12150 5850 50  0001 C CNN "Manufacture"
F 6 "311-1.0KGRCT-ND" H 12150 5850 50  0001 C CNN "SPN"
F 7 "DigiKey" H 12150 5850 50  0001 C CNN "Supplier"
F 8 "https://www.digikey.com/en/products/detail/yageo/RC0603JR-071KL/726677?s=N4IgTCBcDaIMwEYEFoEDoAMBrA5gJwGMAXZAOwBMQBdAXyA" H 12150 5850 50  0001 C CNN "Supplier Link"
	1    12150 5850
	0    1    1    0   
$EndComp
$Comp
L Device:LED D8
U 1 1 635E736D
P 11750 5850
F 0 "D8" H 11750 5950 50  0000 C CNN
F 1 "ORG" H 11750 5750 50  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 11750 5850 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/2008201033_Foshan-NationStar-Optoelectronics-NCD0603O1_C84269.pdf" H 11750 5850 50  0001 C CNN
F 4 "NCD0603O1" H 11750 5850 50  0001 C CNN "MPN"
F 5 "Foshan NationStar Optoelectronics" H 11750 5850 50  0001 C CNN "Manufacture"
F 6 "C84269" H 11750 5850 50  0001 C CNN "SPN"
F 7 "LCSC" H 11750 5850 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Light-Emitting-Diodes-LED_Foshan-NationStar-Optoelectronics-NCD0603O1_C84269.html" H 11750 5850 50  0001 C CNN "Supplier Link"
	1    11750 5850
	-1   0    0    1   
$EndComp
Wire Wire Line
	12500 5550 12500 5850
Connection ~ 12500 6150
Connection ~ 12500 5850
Wire Wire Line
	12500 5850 12500 6150
Wire Wire Line
	11450 5850 11600 5850
Wire Wire Line
	11600 6150 11450 6150
Wire Wire Line
	11600 5550 11450 5550
Text Notes 10750 4850 0    50   ~ 0
Indicator LEDs
Wire Notes Line
	10750 4850 12650 4850
Wire Notes Line
	12650 6600 10750 6600
Wire Notes Line
	10750 6600 10750 4750
Wire Notes Line
	10750 4750 12650 4750
Wire Notes Line
	12650 4750 12650 6600
Wire Notes Line
	13800 6700 13800 7900
Wire Notes Line
	12750 6700 13800 6700
Wire Notes Line
	12750 7900 12750 6700
Wire Notes Line
	13800 7900 12750 7900
Wire Notes Line
	12750 6800 13800 6800
Text Notes 12750 6800 0    50   ~ 0
OPA330 Bypass Capacitors
Text Notes 11450 9050 0    50   ~ 0
G = 5.0/3.3\nG = 1 + (68k/[120k + 12k])
Wire Wire Line
	11100 8850 11100 8800
Wire Wire Line
	11100 8500 11100 8400
Connection ~ 11100 8000
Wire Wire Line
	11100 8100 11100 8000
Wire Wire Line
	12250 7450 12300 7450
Wire Wire Line
	12250 7500 12250 7450
$Comp
L power:GND #PWR063
U 1 1 607320D3
P 12250 7500
F 0 "#PWR063" H 12250 7250 50  0001 C CNN
F 1 "GND" H 12250 7350 50  0000 C CNN
F 2 "" H 12250 7500 50  0001 C CNN
F 3 "" H 12250 7500 50  0001 C CNN
	1    12250 7500
	1    0    0    -1  
$EndComp
Wire Wire Line
	12300 7350 12150 7350
$Comp
L Device:Ferrite_Bead_Small FB2
U 1 1 6071125C
P 12050 7350
F 0 "FB2" V 12000 7250 50  0000 C CNN
F 1 "FBS" V 12150 7350 50  0000 C CNN
F 2 "Inductor_SMD:L_0603_1608Metric" V 11980 7350 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/2006221432_FH-Guangdong-Fenghua-Advanced-Tech-CBG160808U070T_C98494.pdf" H 12050 7350 50  0001 C CNN
F 4 "CBG160808U070T" H 12050 7350 50  0001 C CNN "MPN"
F 5 " FH(Guangdong Fenghua Advanced Tech)" H 12050 7350 50  0001 C CNN "Manufacture"
F 6 "C98494" H 12050 7350 50  0001 C CNN "SPN"
F 7 "LCSC" H 12050 7350 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Ferrite-Beads_FH-Guangdong-Fenghua-Advanced-Tech-CBG160808U070T_C98494.html" H 12050 7350 50  0001 C CNN "Supplier Link"
	1    12050 7350
	0    -1   -1   0   
$EndComp
Text GLabel 11050 7250 0    50   Input ~ 0
DAC
$Comp
L Device:R R24
U 1 1 626E6C86
P 11100 8250
F 0 "R24" V 11180 8250 50  0000 C CNN
F 1 "120k" V 11100 8250 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 11030 8250 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/2008171235_YAGEO-RT0603BRD07120KL_C705720.pdf" H 11100 8250 50  0001 C CNN
F 4 "RT0603BRD07120KL" H 11100 8250 50  0001 C CNN "MPN"
F 5 "YAGEO" H 11100 8250 50  0001 C CNN "Manufacture"
F 6 "C705720" H 11100 8250 50  0001 C CNN "SPN"
F 7 "LCSC" H 11100 8250 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_YAGEO-RT0603BRD07120KL_C705720.html" H 11100 8250 50  0001 C CNN "Supplier Link"
	1    11100 8250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R25
U 1 1 626E75EC
P 11100 8650
F 0 "R25" V 11180 8650 50  0000 C CNN
F 1 "12k" V 11100 8650 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 11030 8650 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1811141450_YAGEO-RT0603BRD0712KL_C326735.pdf" H 11100 8650 50  0001 C CNN
F 4 "RT0603BRD0712KL" H 11100 8650 50  0001 C CNN "MPN"
F 5 "YAGEO" H 11100 8650 50  0001 C CNN "Manufacture"
F 6 "C326735" H 11100 8650 50  0001 C CNN "SPN"
F 7 "LCSC" H 11100 8650 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_YAGEO-RT0603BRD0712KL_C326735.html" H 11100 8650 50  0001 C CNN "Supplier Link"
	1    11100 8650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR057
U 1 1 627CD720
P 11100 8850
F 0 "#PWR057" H 11100 8600 50  0001 C CNN
F 1 "GND" H 11100 8700 50  0000 C CNN
F 2 "" H 11100 8850 50  0001 C CNN
F 3 "" H 11100 8850 50  0001 C CNN
	1    11100 8850
	1    0    0    -1  
$EndComp
Wire Notes Line
	11650 2650 11650 4650
Text Label 9950 3400 0    50   ~ 0
RXD
Wire Wire Line
	10750 3500 10750 3400
Text Label 9950 3300 0    50   ~ 0
TXD
Wire Wire Line
	9750 3300 11150 3300
Wire Wire Line
	10050 4350 10050 4300
$Comp
L power:GND #PWR053
U 1 1 604DFCD5
P 10050 4350
F 0 "#PWR053" H 10050 4100 50  0001 C CNN
F 1 "GND" H 10050 4200 50  0000 C CNN
F 2 "" H 10050 4350 50  0001 C CNN
F 3 "" H 10050 4350 50  0001 C CNN
	1    10050 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	10050 3900 9750 3900
Connection ~ 10050 3900
Wire Wire Line
	10050 4000 10050 3900
$Comp
L Device:R R23
U 1 1 604C58E8
P 10050 4150
F 0 "R23" V 10130 4150 50  0000 C CNN
F 1 "10k" V 10050 4150 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 9980 4150 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1811081617_YAGEO-RC0603JR-0710KL_C99198.pdf" H 10050 4150 50  0001 C CNN
F 4 "RC0603JR-0710KL" H 10050 4150 50  0001 C CNN "MPN"
F 5 "YAGEO" H 10050 4150 50  0001 C CNN "Manufacture"
F 6 "C99198" H 10050 4150 50  0001 C CNN "SPN"
F 7 "LCSC" H 10050 4150 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_YAGEO-RC0603JR-0710KL_C99198.html" H 10050 4150 50  0001 C CNN "Supplier Link"
	1    10050 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 9700 2600 9850
Text Label 2600 9850 1    50   ~ 0
Vin
$Comp
L power:PWR_FLAG #FLG07
U 1 1 6318FB46
P 2600 9700
F 0 "#FLG07" H 2600 9775 50  0001 C CNN
F 1 "PWR_FLAG" H 2600 9850 50  0000 C CNN
F 2 "" H 2600 9700 50  0001 C CNN
F 3 "~" H 2600 9700 50  0001 C CNN
	1    2600 9700
	1    0    0    -1  
$EndComp
Text Notes 6200 2750 0    50   ~ 0
ESP8277 WiFi Interface
$Comp
L ESP8266:ESP-12E U4
U 1 1 603A4B57
P 8850 3600
F 0 "U4" H 9400 2950 50  0000 C CNN
F 1 "ESP-12F" H 8850 4250 50  0000 C CNN
F 2 "ESP8266:ESP-12E_SMD" H 8850 3600 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/2102191804_Ai-Thinker-ESP-12F-ESP8266MOD_C82891.pdf" H 8850 3600 50  0001 C CNN
F 4 "ESP-12F(ESP8266MOD)" H 8850 3600 50  0001 C CNN "MPN"
F 5 "Ai-Thinker" H 8850 3600 50  0001 C CNN "Manufacture"
F 6 "C82891" H 8850 3600 50  0001 C CNN "SPN"
F 7 "LCSC" H 8850 3600 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/WIFI-Modules_Ai-Thinker-ESP-12F-ESP8266MOD_C82891.html" H 8850 3600 50  0001 C CNN "Supplier Link"
	1    8850 3600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R21
U 1 1 603ADA14
P 7100 3250
F 0 "R21" V 7180 3250 50  0000 C CNN
F 1 "10k" V 7100 3250 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7030 3250 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1811081617_YAGEO-RC0603JR-0710KL_C99198.pdf" H 7100 3250 50  0001 C CNN
F 4 "RC0603JR-0710KL" H 7100 3250 50  0001 C CNN "MPN"
F 5 "YAGEO" H 7100 3250 50  0001 C CNN "Manufacture"
F 6 "C99198" H 7100 3250 50  0001 C CNN "SPN"
F 7 "LCSC" H 7100 3250 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_YAGEO-RC0603JR-0710KL_C99198.html" H 7100 3250 50  0001 C CNN "Supplier Link"
	1    7100 3250
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR036
U 1 1 603AED73
P 7100 3000
F 0 "#PWR036" H 7100 2850 50  0001 C CNN
F 1 "+3V3" H 7100 3140 50  0000 C CNN
F 2 "" H 7100 3000 50  0001 C CNN
F 3 "" H 7100 3000 50  0001 C CNN
	1    7100 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	7100 3100 7100 3000
Wire Wire Line
	7100 3950 7100 3400
Wire Wire Line
	7950 3500 7750 3500
Text GLabel 7750 3500 0    50   Input ~ 0
CH_PD
Text GLabel 7100 3950 3    50   Input ~ 0
CH_PD
NoConn ~ 7950 3400
$Comp
L power:GND #PWR051
U 1 1 603CDDBD
P 9850 4100
F 0 "#PWR051" H 9850 3850 50  0001 C CNN
F 1 "GND" H 9850 3950 50  0000 C CNN
F 2 "" H 9850 4100 50  0001 C CNN
F 3 "" H 9850 4100 50  0001 C CNN
	1    9850 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	9750 4000 9850 4000
Wire Wire Line
	9850 4000 9850 4100
$Comp
L Device:R R15
U 1 1 603DE143
P 6800 3250
F 0 "R15" V 6880 3250 50  0000 C CNN
F 1 "10k" V 6800 3250 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6730 3250 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1811081617_YAGEO-RC0603JR-0710KL_C99198.pdf" H 6800 3250 50  0001 C CNN
F 4 "RC0603JR-0710KL" H 6800 3250 50  0001 C CNN "MPN"
F 5 "YAGEO" H 6800 3250 50  0001 C CNN "Manufacture"
F 6 "C99198" H 6800 3250 50  0001 C CNN "SPN"
F 7 "LCSC" H 6800 3250 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_YAGEO-RC0603JR-0710KL_C99198.html" H 6800 3250 50  0001 C CNN "Supplier Link"
	1    6800 3250
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR034
U 1 1 603DE6FB
P 6800 3000
F 0 "#PWR034" H 6800 2850 50  0001 C CNN
F 1 "+3V3" H 6800 3140 50  0000 C CNN
F 2 "" H 6800 3000 50  0001 C CNN
F 3 "" H 6800 3000 50  0001 C CNN
	1    6800 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 3000 6800 3100
Wire Wire Line
	6800 3400 6800 3950
Text GLabel 10200 3800 2    50   Input ~ 0
GPIO2
Wire Wire Line
	10200 3800 9750 3800
Text GLabel 6800 3950 3    50   Input ~ 0
GPIO2
$Comp
L power:+3V3 #PWR041
U 1 1 603F36B0
P 7850 3000
F 0 "#PWR041" H 7850 2850 50  0001 C CNN
F 1 "+3V3" H 7850 3140 50  0000 C CNN
F 2 "" H 7850 3000 50  0001 C CNN
F 3 "" H 7850 3000 50  0001 C CNN
	1    7850 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	7850 4000 7950 4000
Wire Wire Line
	7850 4000 7850 3000
$Comp
L Device:C C13
U 1 1 604043ED
P 7850 4200
F 0 "C13" H 7875 4300 50  0000 L CNN
F 1 "10uF" H 7875 4100 50  0000 L CNN
F 2 "C_0805_2012Metric" H 7888 4050 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1811011704_Samsung-Electro-Mechanics-CL21A106KPFNNNE_C17024.pdf" H 7850 4200 50  0001 C CNN
F 4 "CL21A106KPFNNNE" H 7850 4200 50  0001 C CNN "MPN"
F 5 "Samsung Electro-Mechanics" H 7850 4200 50  0001 C CNN "Manufacture"
F 6 "C17024" H 7850 4200 50  0001 C CNN "SPN"
F 7 "LCSC" H 7850 4200 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Multilayer-Ceramic-Capacitors-MLCC-SMD-SMT_Samsung-Electro-Mechanics-CL21A106KPFNNNE_C17024.html" H 7850 4200 50  0001 C CNN "Supplier Link"
	1    7850 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7850 4050 7850 4000
Connection ~ 7850 4000
$Comp
L power:GND #PWR042
U 1 1 60407E64
P 7850 4400
F 0 "#PWR042" H 7850 4150 50  0001 C CNN
F 1 "GND" H 7850 4250 50  0000 C CNN
F 2 "" H 7850 4400 50  0001 C CNN
F 3 "" H 7850 4400 50  0001 C CNN
	1    7850 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	7850 4400 7850 4350
NoConn ~ 8600 4500
NoConn ~ 8700 4500
NoConn ~ 8800 4500
NoConn ~ 8900 4500
NoConn ~ 9000 4500
NoConn ~ 9100 4500
Text GLabel 10200 3900 2    50   Input ~ 0
STM_CS
Wire Wire Line
	10200 3900 10050 3900
$Comp
L Switch:SW_Push SW2
U 1 1 6044D6C7
P 6500 3600
F 0 "SW2" H 6550 3700 50  0000 L CNN
F 1 "ESP_PROG" H 6500 3540 50  0000 C CNN
F 2 "Button_Switch_SMD:SW_SPST_CK_RS282G05A3" H 6500 3800 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1912111437_SHOU-HAN-TS3625A_C398053.pdf" H 6500 3800 50  0001 C CNN
F 4 "TS3625A" H 6500 3600 50  0001 C CNN "MPN"
F 5 "SHOU HAN" H 6500 3600 50  0001 C CNN "Manufacture"
F 6 "C398053" H 6500 3600 50  0001 C CNN "SPN"
F 7 "LCSC" H 6500 3600 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Tactile-Switches_SHOU-HAN-TS3625A_C398053.html" H 6500 3600 50  0001 C CNN "Supplier Link"
	1    6500 3600
	0    -1   -1   0   
$EndComp
$Comp
L Switch:SW_Push SW1
U 1 1 6044E020
P 4150 4150
F 0 "SW1" H 4200 4250 50  0000 L CNN
F 1 "RESET" H 4150 4090 50  0000 C CNN
F 2 "Button_Switch_SMD:SW_SPST_CK_RS282G05A3" H 4150 4350 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1912111437_SHOU-HAN-TS3625A_C398053.pdf" H 4150 4350 50  0001 C CNN
F 4 "TS3625A" H 4150 4150 50  0001 C CNN "MPN"
F 5 "SHOU HAN" H 4150 4150 50  0001 C CNN "Manufacture"
F 6 "C398053" H 4150 4150 50  0001 C CNN "SPN"
F 7 "LCSC" H 4150 4150 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Tactile-Switches_SHOU-HAN-TS3625A_C398053.html" H 4150 4150 50  0001 C CNN "Supplier Link"
	1    4150 4150
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7950 3300 7750 3300
Text GLabel 7750 3300 0    50   Input ~ 0
ESP_RESET
Wire Wire Line
	9750 3700 10200 3700
Text GLabel 10200 3700 2    50   Input ~ 0
GPIO0
$Comp
L Device:LED D10
U 1 1 6045E683
P 12200 5250
F 0 "D10" H 12200 5350 50  0000 C CNN
F 1 "BLU" H 12200 5150 50  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 12200 5250 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1811100911_Orient-ORH-B36G_C193191.pdf" H 12200 5250 50  0001 C CNN
F 4 "ORH-B36G" H 12200 5250 50  0001 C CNN "MPN"
F 5 "Orient" H 12200 5250 50  0001 C CNN "Manufacture"
F 6 "C193191" H 12200 5250 50  0001 C CNN "SPN"
F 7 "LCSC" H 12200 5250 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Light-Emitting-Diodes-LED_Orient-ORH-B36G_C193191.html" H 12200 5250 50  0001 C CNN "Supplier Link"
	1    12200 5250
	1    0    0    1   
$EndComp
$Comp
L Device:R R28
U 1 1 6045EFF3
P 11750 5250
F 0 "R28" V 11830 5250 50  0000 C CNN
F 1 "1k" V 11750 5250 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 11680 5250 50  0001 C CNN
F 3 "https://www.yageo.com/upload/media/product/productsearch/datasheet/rchip/PYu-RC_Group_51_RoHS_L_11.pdf" H 11750 5250 50  0001 C CNN
F 4 "RC0603JR-071KL" H 11750 5250 50  0001 C CNN "MPN"
F 5 "YAGEO" H 11750 5250 50  0001 C CNN "Manufacture"
F 6 "311-1.0KGRCT-ND" H 11750 5250 50  0001 C CNN "SPN"
F 7 "DigiKey" H 11750 5250 50  0001 C CNN "Supplier"
F 8 "https://www.digikey.com/en/products/detail/yageo/RC0603JR-071KL/726677?s=N4IgTCBcDaIMwEYEFoEDoAMBrA5gJwGMAXZAOwBMQBdAXyA" H 11750 5250 50  0001 C CNN "Supplier Link"
	1    11750 5250
	0    1    1    0   
$EndComp
$Comp
L power:+3V3 #PWR064
U 1 1 6046DD32
P 12500 5100
F 0 "#PWR064" H 12500 4950 50  0001 C CNN
F 1 "+3V3" H 12500 5240 50  0000 C CNN
F 2 "" H 12500 5100 50  0001 C CNN
F 3 "" H 12500 5100 50  0001 C CNN
	1    12500 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	12500 5250 12350 5250
Wire Wire Line
	11900 5250 12050 5250
Text GLabel 11450 5250 0    50   Input ~ 0
GPIO0
Wire Wire Line
	11450 5250 11600 5250
Text GLabel 6500 3250 1    50   Input ~ 0
GPIO0
Wire Wire Line
	6500 3250 6500 3400
$Comp
L power:GND #PWR019
U 1 1 604DD433
P 4150 4400
F 0 "#PWR019" H 4150 4150 50  0001 C CNN
F 1 "GND" H 4150 4250 50  0000 C CNN
F 2 "" H 4150 4400 50  0001 C CNN
F 3 "" H 4150 4400 50  0001 C CNN
	1    4150 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 4400 4150 4350
$Comp
L Device:R R11
U 1 1 604E6577
P 4150 3700
F 0 "R11" V 4230 3700 50  0000 C CNN
F 1 "10k" V 4150 3700 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4080 3700 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1811081617_YAGEO-RC0603JR-0710KL_C99198.pdf" H 4150 3700 50  0001 C CNN
F 4 "RC0603JR-0710KL" H 4150 3700 50  0001 C CNN "MPN"
F 5 "YAGEO" H 4150 3700 50  0001 C CNN "Manufacture"
F 6 "C99198" H 4150 3700 50  0001 C CNN "SPN"
F 7 "LCSC" H 4150 3700 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_YAGEO-RC0603JR-0710KL_C99198.html" H 4150 3700 50  0001 C CNN "Supplier Link"
	1    4150 3700
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR018
U 1 1 604E8ECB
P 4150 3450
F 0 "#PWR018" H 4150 3300 50  0001 C CNN
F 1 "+3V3" H 4150 3590 50  0000 C CNN
F 2 "" H 4150 3450 50  0001 C CNN
F 3 "" H 4150 3450 50  0001 C CNN
	1    4150 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 3550 4150 3450
Wire Wire Line
	7950 3700 7750 3700
Wire Wire Line
	7950 3800 7750 3800
Wire Wire Line
	7950 3900 7750 3900
Text GLabel 7750 3700 0    50   Input ~ 0
SCLK
Text GLabel 7750 3800 0    50   Input ~ 0
MISO
Text GLabel 7750 3900 0    50   Input ~ 0
MOSI
NoConn ~ 7950 3600
Wire Wire Line
	9750 3400 10750 3400
Text GLabel 10200 3600 2    50   Input ~ 0
STM_RDY
Wire Wire Line
	10200 3600 9750 3600
Wire Wire Line
	9750 3500 10200 3500
Wire Notes Line
	6200 2750 11650 2750
Wire Notes Line
	11650 4650 6200 4650
Wire Notes Line
	6200 4650 6200 2650
Wire Notes Line
	6200 2650 11650 2650
$Comp
L Connector_Generic:Conn_01x06 J6
U 1 1 60FEC2BA
P 11400 3500
F 0 "J6" H 11400 3800 50  0000 C CNN
F 1 "ESP_PROG" H 11400 3100 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 11400 3500 50  0001 C CNN
F 3 "~" H 11400 3500 50  0001 C CNN
F 4 "DNP" H 11400 3500 50  0001 C CNN "Population"
	1    11400 3500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR058
U 1 1 61023622
P 11150 3900
F 0 "#PWR058" H 11150 3650 50  0001 C CNN
F 1 "GND" H 11150 3750 50  0000 C CNN
F 2 "" H 11150 3900 50  0001 C CNN
F 3 "" H 11150 3900 50  0001 C CNN
	1    11150 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	11150 3900 11150 3800
Wire Wire Line
	11150 3800 11200 3800
NoConn ~ 11200 3300
NoConn ~ 11200 3700
NoConn ~ 11200 3600
Wire Wire Line
	10750 3500 10800 3500
Wire Wire Line
	11100 3500 11200 3500
Wire Wire Line
	11200 3400 11150 3400
Wire Wire Line
	11150 3400 11150 3300
Wire Notes Line
	12650 6700 12650 9100
Wire Notes Line
	10750 6700 12650 6700
Wire Notes Line
	10750 9100 10750 6700
Wire Notes Line
	12650 9100 10750 9100
Wire Notes Line
	10750 6800 12650 6800
Wire Wire Line
	11100 8000 11100 7450
Wire Wire Line
	11300 8000 11100 8000
Wire Wire Line
	11850 7350 11750 7350
Connection ~ 11850 7350
Wire Wire Line
	11850 8000 11850 7350
Wire Wire Line
	11600 8000 11850 8000
Wire Wire Line
	11050 7250 11150 7250
$Comp
L Device:R R26
U 1 1 626E6347
P 11450 8000
F 0 "R26" V 11530 8000 50  0000 C CNN
F 1 "68k" V 11450 8000 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 11380 8000 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/2010201905_YAGEO-RT0603BRD0768KL_C705793.pdf" H 11450 8000 50  0001 C CNN
F 4 "RT0603BRD0768KL" H 11450 8000 50  0001 C CNN "MPN"
F 5 "YAGEO" H 11450 8000 50  0001 C CNN "Manufacture"
F 6 "C705793" H 11450 8000 50  0001 C CNN "SPN"
F 7 "LCSC" H 11450 8000 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_YAGEO-RT0603BRD0768KL_C705793.html" H 11450 8000 50  0001 C CNN "Supplier Link"
	1    11450 8000
	0    1    1    0   
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J7
U 1 1 6026EDC8
P 12500 7350
F 0 "J7" H 12500 7450 50  0000 C CNN
F 1 "AOUT" H 12500 7150 50  0000 C CNN
F 2 "pl_TerminalBlock:WJ127-5.0-2P" H 12500 7350 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1912251631_Ningbo-Kangnex-Elec-WJ127-5-0-2P_C3703.pdf" H 12500 7350 50  0001 C CNN
F 4 " WJ127-5.0-2P" H 12500 7350 50  0001 C CNN "MPN"
F 5 " Ningbo Kangnex Elec" H 12500 7350 50  0001 C CNN "Manufacture"
F 6 "C3703" H 12500 7350 50  0001 C CNN "SPN"
F 7 "LCSC" H 12500 7350 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Screw-terminal_Ningbo-Kangnex-Elec-WJ127-5-0-2P_C3703.html" H 12500 7350 50  0001 C CNN "Supplier Link"
	1    12500 7350
	1    0    0    -1  
$EndComp
Wire Wire Line
	13050 7600 13050 7500
Connection ~ 13050 7600
Wire Wire Line
	13450 7600 13050 7600
Wire Wire Line
	13450 7500 13450 7600
Wire Wire Line
	13050 7100 13050 7200
Connection ~ 13050 7100
Wire Wire Line
	13450 7100 13050 7100
Wire Wire Line
	13450 7200 13450 7100
$Comp
L Device:C C18
U 1 1 613BF0A2
P 13450 7350
F 0 "C18" H 13475 7450 50  0000 L CNN
F 1 "1uF" H 13475 7250 50  0000 L CNN
F 2 "C_0603_1608Metric" H 13488 7200 50  0001 C CNN
F 3 "https://www.samsungsem.com/resources/file/global/support/product_catalog/MLCC.pdf" H 13450 7350 50  0001 C CNN
F 4 "CL10A105KQ8NNNC" H 13450 7350 50  0001 C CNN "MPN"
F 5 "Samsung Electro-Mechanics" H 13450 7350 50  0001 C CNN "Manufacture"
F 6 "1276-1036-1-ND" H 13450 7350 50  0001 C CNN "SPN"
F 7 "DigiKey" H 13450 7350 50  0001 C CNN "Supplier"
F 8 "https://www.digikey.com/en/products/detail/samsung-electro-mechanics/CL10A105KQ8NNNC/3886694?s=N4IgTCBcDaIIxgOwDYC0cAMBmNdUDsATEAXQF8g" H 13450 7350 50  0001 C CNN "Supplier Link"
	1    13450 7350
	1    0    0    -1  
$EndComp
Wire Wire Line
	13050 7000 13050 7100
Wire Wire Line
	13050 7700 13050 7600
$Comp
L power:GND #PWR069
U 1 1 613A09B6
P 13050 7700
F 0 "#PWR069" H 13050 7450 50  0001 C CNN
F 1 "GND" H 13050 7550 50  0000 C CNN
F 2 "" H 13050 7700 50  0001 C CNN
F 3 "" H 13050 7700 50  0001 C CNN
	1    13050 7700
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR068
U 1 1 613A031B
P 13050 7000
F 0 "#PWR068" H 13050 6850 50  0001 C CNN
F 1 "+5V" H 13050 7140 50  0000 C CNN
F 2 "" H 13050 7000 50  0001 C CNN
F 3 "" H 13050 7000 50  0001 C CNN
	1    13050 7000
	1    0    0    -1  
$EndComp
$Comp
L Device:C C17
U 1 1 6139E330
P 13050 7350
F 0 "C17" H 13075 7450 50  0000 L CNN
F 1 "100nF" H 13075 7250 50  0000 L CNN
F 2 "C_0603_1608Metric" H 13088 7200 50  0001 C CNN
F 3 "https://api.kemet.com/component-edge/download/datasheet/C0603C104Z3VACTU.pdf" H 13050 7350 50  0001 C CNN
F 4 "C0603C104Z3VACTU" H 13050 7350 50  0001 C CNN "MPN"
F 5 "KEMET" H 13050 7350 50  0001 C CNN "Manufacture"
F 6 "399-1100-1-ND" H 13050 7350 50  0001 C CNN "SPN"
F 7 "DigiKey" H 13050 7350 50  0001 C CNN "Supplier"
F 8 "https://www.digikey.com/en/products/detail/kemet/C0603C104Z3VACTU/411099?s=N4IgTCBcDaIMwE4EFoCMqAMG3IHYBMQBdAXyA" H 13050 7350 50  0001 C CNN "Supplier Link"
	1    13050 7350
	1    0    0    -1  
$EndComp
Wire Wire Line
	11950 7350 11850 7350
Wire Wire Line
	11150 7450 11100 7450
Wire Wire Line
	11350 7700 11350 7650
$Comp
L power:GND #PWR060
U 1 1 6133BD5E
P 11350 7700
F 0 "#PWR060" H 11350 7450 50  0001 C CNN
F 1 "GND" H 11350 7550 50  0000 C CNN
F 2 "" H 11350 7700 50  0001 C CNN
F 3 "" H 11350 7700 50  0001 C CNN
	1    11350 7700
	1    0    0    -1  
$EndComp
Wire Wire Line
	11350 7000 11350 7050
$Comp
L power:+5V #PWR059
U 1 1 6132CDD9
P 11350 7000
F 0 "#PWR059" H 11350 6850 50  0001 C CNN
F 1 "+5V" H 11350 7140 50  0000 C CNN
F 2 "" H 11350 7000 50  0001 C CNN
F 3 "" H 11350 7000 50  0001 C CNN
	1    11350 7000
	1    0    0    -1  
$EndComp
Text Notes 10750 6800 0    50   ~ 0
Analog Output Amplification
$Comp
L Amplifier_Operational:OPA330xxDBV U6
U 1 1 6131FB48
P 11450 7350
F 0 "U6" H 11400 7150 50  0000 L CNN
F 1 "OPA330xxDBV" H 11400 7500 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5" H 11350 7150 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/opa330.pdf" H 11450 7550 50  0001 C CNN
F 4 "OPA330AIDBVR" H 11450 7350 50  0001 C CNN "MPN"
F 5 "Texas Instruments" H 11450 7350 50  0001 C CNN "Manufacture"
F 6 "C38649" H 11450 7350 50  0001 C CNN "SPN"
F 7 "LCSC" H 11450 7350 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Precision-OpAmps_Texas-Instruments-OPA330AIDBVR_C38649.html" H 11450 7350 50  0001 C CNN "Supplier Link"
	1    11450 7350
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 1550 7900 1100
Connection ~ 7900 1100
Wire Wire Line
	7900 1100 8400 1100
Wire Notes Line
	6100 4750 6100 5950
Wire Notes Line
	3650 4750 6100 4750
Wire Notes Line
	3650 5950 3650 4750
Wire Notes Line
	6100 5950 3650 5950
Wire Notes Line
	3650 4850 6100 4850
Text Notes 3650 4850 0    50   ~ 0
STM32F302 Power Distribution and Bypass
Wire Wire Line
	3800 5700 3800 5500
$Comp
L power:GND #PWR017
U 1 1 613DAFB1
P 3800 5700
F 0 "#PWR017" H 3800 5450 50  0001 C CNN
F 1 "GND" H 3800 5550 50  0000 C CNN
F 2 "" H 3800 5700 50  0001 C CNN
F 3 "" H 3800 5700 50  0001 C CNN
	1    3800 5700
	1    0    0    -1  
$EndComp
Connection ~ 3800 5100
Wire Wire Line
	3800 5100 3800 5200
Wire Wire Line
	3800 5100 3800 5050
Wire Wire Line
	3950 5100 3800 5100
Wire Wire Line
	4150 5100 4300 5100
$Comp
L Device:C C2
U 1 1 61372843
P 3800 5350
F 0 "C2" H 3825 5450 50  0000 L CNN
F 1 "1uF" H 3825 5250 50  0000 L CNN
F 2 "C_0603_1608Metric" H 3838 5200 50  0001 C CNN
F 3 "https://www.samsungsem.com/resources/file/global/support/product_catalog/MLCC.pdf" H 3800 5350 50  0001 C CNN
F 4 "CL10A105KQ8NNNC" H 3800 5350 50  0001 C CNN "MPN"
F 5 "Samsung Electro-Mechanics" H 3800 5350 50  0001 C CNN "Manufacture"
F 6 "1276-1036-1-ND" H 3800 5350 50  0001 C CNN "SPN"
F 7 "DigiKey" H 3800 5350 50  0001 C CNN "Supplier"
F 8 "https://www.digikey.com/en/products/detail/samsung-electro-mechanics/CL10A105KQ8NNNC/3886694?s=N4IgTCBcDaIIxgOwDYC0cAMBmNdUDsATEAXQF8g" H 3800 5350 50  0001 C CNN "Supplier Link"
	1    3800 5350
	1    0    0    -1  
$EndComp
$Comp
L Device:Jumper_NC_Small JP1
U 1 1 613708F8
P 4050 5100
F 0 "JP1" H 4050 5180 50  0000 C CNN
F 1 "NC" H 4060 5040 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Bridged_RoundedPad1.0x1.5mm" H 4050 5100 50  0001 C CNN
F 3 "~" H 4050 5100 50  0001 C CNN
F 4 "DNP" H 4050 5100 50  0001 C CNN "Population"
	1    4050 5100
	1    0    0    -1  
$EndComp
$Comp
L power:+BATT #PWR016
U 1 1 6136FBBD
P 3800 5050
F 0 "#PWR016" H 3800 4900 50  0001 C CNN
F 1 "+BATT" H 3800 5190 50  0000 C CNN
F 2 "" H 3800 5050 50  0001 C CNN
F 3 "" H 3800 5050 50  0001 C CNN
	1    3800 5050
	1    0    0    -1  
$EndComp
Connection ~ 5300 5100
Wire Wire Line
	5450 5100 5300 5100
Wire Wire Line
	5800 5100 5800 5200
Connection ~ 5800 5100
Wire Wire Line
	5650 5100 5800 5100
Wire Wire Line
	5800 5050 5800 5100
Wire Wire Line
	5800 5700 5800 5650
$Comp
L Device:C C10
U 1 1 61099527
P 5800 5350
F 0 "C10" H 5825 5450 50  0000 L CNN
F 1 "100nF" H 5825 5250 50  0000 L CNN
F 2 "C_0603_1608Metric" H 5838 5200 50  0001 C CNN
F 3 "https://api.kemet.com/component-edge/download/datasheet/C0603C104Z3VACTU.pdf" H 5800 5350 50  0001 C CNN
F 4 "C0603C104Z3VACTU" H 5800 5350 50  0001 C CNN "MPN"
F 5 "KEMET" H 5800 5350 50  0001 C CNN "Manufacture"
F 6 "399-1100-1-ND" H 5800 5350 50  0001 C CNN "SPN"
F 7 "DigiKey" H 5800 5350 50  0001 C CNN "Supplier"
F 8 "https://www.digikey.com/en/products/detail/kemet/C0603C104Z3VACTU/411099?s=N4IgTCBcDaIMwE4EFoCMqAMG3IHYBMQBdAXyA" H 5800 5350 50  0001 C CNN "Supplier Link"
	1    5800 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 5650 5300 5650
Connection ~ 4800 5650
Wire Wire Line
	4800 5500 4800 5650
Wire Wire Line
	4300 5650 4300 5500
Connection ~ 4300 5650
Wire Wire Line
	5300 5650 5300 5500
Wire Wire Line
	4300 5650 4800 5650
Wire Wire Line
	4800 5100 5300 5100
Connection ~ 4800 5100
Wire Wire Line
	4800 5200 4800 5100
Wire Wire Line
	4300 5100 4300 5200
Connection ~ 4300 5100
Wire Wire Line
	5300 5100 5300 5200
Wire Wire Line
	4300 5100 4800 5100
$Comp
L Device:C C8
U 1 1 60F43D23
P 5300 5350
F 0 "C8" H 5325 5450 50  0000 L CNN
F 1 "100nF" H 5325 5250 50  0000 L CNN
F 2 "C_0603_1608Metric" H 5338 5200 50  0001 C CNN
F 3 "https://api.kemet.com/component-edge/download/datasheet/C0603C104Z3VACTU.pdf" H 5300 5350 50  0001 C CNN
F 4 "C0603C104Z3VACTU" H 5300 5350 50  0001 C CNN "MPN"
F 5 "KEMET" H 5300 5350 50  0001 C CNN "Manufacture"
F 6 "399-1100-1-ND" H 5300 5350 50  0001 C CNN "SPN"
F 7 "DigiKey" H 5300 5350 50  0001 C CNN "Supplier"
F 8 "https://www.digikey.com/en/products/detail/kemet/C0603C104Z3VACTU/411099?s=N4IgTCBcDaIMwE4EFoCMqAMG3IHYBMQBdAXyA" H 5300 5350 50  0001 C CNN "Supplier Link"
	1    5300 5350
	1    0    0    -1  
$EndComp
$Comp
L Device:C C6
U 1 1 60F1E971
P 4800 5350
F 0 "C6" H 4825 5450 50  0000 L CNN
F 1 "100nF" H 4825 5250 50  0000 L CNN
F 2 "C_0603_1608Metric" H 4838 5200 50  0001 C CNN
F 3 "https://api.kemet.com/component-edge/download/datasheet/C0603C104Z3VACTU.pdf" H 4800 5350 50  0001 C CNN
F 4 "C0603C104Z3VACTU" H 4800 5350 50  0001 C CNN "MPN"
F 5 "KEMET" H 4800 5350 50  0001 C CNN "Manufacture"
F 6 "399-1100-1-ND" H 4800 5350 50  0001 C CNN "SPN"
F 7 "DigiKey" H 4800 5350 50  0001 C CNN "Supplier"
F 8 "https://www.digikey.com/en/products/detail/kemet/C0603C104Z3VACTU/411099?s=N4IgTCBcDaIMwE4EFoCMqAMG3IHYBMQBdAXyA" H 4800 5350 50  0001 C CNN "Supplier Link"
	1    4800 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 5700 4300 5650
$Comp
L power:GND #PWR021
U 1 1 60EFD079
P 4300 5700
F 0 "#PWR021" H 4300 5450 50  0001 C CNN
F 1 "GND" H 4300 5550 50  0000 C CNN
F 2 "" H 4300 5700 50  0001 C CNN
F 3 "" H 4300 5700 50  0001 C CNN
	1    4300 5700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 5050 4300 5100
$Comp
L Device:C C4
U 1 1 60EB5B64
P 4300 5350
F 0 "C4" H 4325 5450 50  0000 L CNN
F 1 "100nF" H 4325 5250 50  0000 L CNN
F 2 "C_0603_1608Metric" H 4338 5200 50  0001 C CNN
F 3 "https://api.kemet.com/component-edge/download/datasheet/C0603C104Z3VACTU.pdf" H 4300 5350 50  0001 C CNN
F 4 "C0603C104Z3VACTU" H 4300 5350 50  0001 C CNN "MPN"
F 5 "KEMET" H 4300 5350 50  0001 C CNN "Manufacture"
F 6 "399-1100-1-ND" H 4300 5350 50  0001 C CNN "SPN"
F 7 "DigiKey" H 4300 5350 50  0001 C CNN "Supplier"
F 8 "https://www.digikey.com/en/products/detail/kemet/C0603C104Z3VACTU/411099?s=N4IgTCBcDaIMwE4EFoCMqAMG3IHYBMQBdAXyA" H 4300 5350 50  0001 C CNN "Supplier Link"
	1    4300 5350
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR020
U 1 1 60E5B830
P 4300 5050
F 0 "#PWR020" H 4300 4900 50  0001 C CNN
F 1 "+3V3" H 4300 5190 50  0000 C CNN
F 2 "" H 4300 5050 50  0001 C CNN
F 3 "" H 4300 5050 50  0001 C CNN
	1    4300 5050
	1    0    0    -1  
$EndComp
$Comp
L power:VDDA #PWR025
U 1 1 60E5AE6B
P 5800 5050
F 0 "#PWR025" H 5800 4900 50  0001 C CNN
F 1 "VDDA" H 5800 5200 50  0000 C CNN
F 2 "" H 5800 5050 50  0001 C CNN
F 3 "" H 5800 5050 50  0001 C CNN
	1    5800 5050
	1    0    0    -1  
$EndComp
$Comp
L Device:Ferrite_Bead_Small FB1
U 1 1 60BA9037
P 5550 5100
F 0 "FB1" V 5500 5000 50  0000 C CNN
F 1 "FBS" V 5650 5100 50  0000 C CNN
F 2 "Inductor_SMD:L_0603_1608Metric" V 5480 5100 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/2006221432_FH-Guangdong-Fenghua-Advanced-Tech-CBG160808U070T_C98494.pdf" H 5550 5100 50  0001 C CNN
F 4 "CBG160808U070T" H 5550 5100 50  0001 C CNN "MPN"
F 5 " FH(Guangdong Fenghua Advanced Tech)" H 5550 5100 50  0001 C CNN "Manufacture"
F 6 "C98494" H 5550 5100 50  0001 C CNN "SPN"
F 7 "LCSC" H 5550 5100 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Ferrite-Beads_FH-Guangdong-Fenghua-Advanced-Tech-CBG160808U070T_C98494.html" H 5550 5100 50  0001 C CNN "Supplier Link"
	1    5550 5100
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C5
U 1 1 60E83E5C
P 4550 4150
F 0 "C5" H 4575 4250 50  0000 L CNN
F 1 "100nF" H 4575 4050 50  0000 L CNN
F 2 "C_0603_1608Metric" H 4588 4000 50  0001 C CNN
F 3 "https://api.kemet.com/component-edge/download/datasheet/C0603C104Z3VACTU.pdf" H 4550 4150 50  0001 C CNN
F 4 "C0603C104Z3VACTU" H 4550 4150 50  0001 C CNN "MPN"
F 5 "KEMET" H 4550 4150 50  0001 C CNN "Manufacture"
F 6 "399-1100-1-ND" H 4550 4150 50  0001 C CNN "SPN"
F 7 "DigiKey" H 4550 4150 50  0001 C CNN "Supplier"
F 8 "https://www.digikey.com/en/products/detail/kemet/C0603C104Z3VACTU/411099?s=N4IgTCBcDaIMwE4EFoCMqAMG3IHYBMQBdAXyA" H 4550 4150 50  0001 C CNN "Supplier Link"
	1    4550 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 4000 4550 3900
Wire Wire Line
	4550 3900 4150 3900
$Comp
L power:GND #PWR022
U 1 1 60EBAED4
P 4550 4400
F 0 "#PWR022" H 4550 4150 50  0001 C CNN
F 1 "GND" H 4550 4250 50  0000 C CNN
F 2 "" H 4550 4400 50  0001 C CNN
F 3 "" H 4550 4400 50  0001 C CNN
	1    4550 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 4400 4550 4300
Wire Wire Line
	1100 2000 1500 2000
Connection ~ 1500 2000
Wire Wire Line
	1500 2000 1500 1900
Text GLabel 5450 3700 2    50   Input ~ 0
ESP_RESET
Connection ~ 4550 3900
Text GLabel 5450 3900 2    50   Input ~ 0
STM_RESET
Text GLabel 10200 3500 2    50   Input ~ 0
STM_RESET
Wire Wire Line
	5450 3700 4550 3700
Wire Wire Line
	4550 3700 4550 3900
Wire Wire Line
	4550 3900 4850 3900
Wire Wire Line
	5150 3900 5450 3900
$Comp
L power:GNDA #PWR026
U 1 1 61967469
P 5800 5700
F 0 "#PWR026" H 5800 5450 50  0001 C CNN
F 1 "GNDA" H 5800 5550 50  0000 C CNN
F 2 "" H 5800 5700 50  0001 C CNN
F 3 "" H 5800 5700 50  0001 C CNN
	1    5800 5700
	1    0    0    -1  
$EndComp
$Comp
L Device:Jumper_NC_Small JP2
U 1 1 619EAE49
P 5550 5650
F 0 "JP2" H 5550 5730 50  0000 C CNN
F 1 "NC" H 5560 5590 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Bridged_RoundedPad1.0x1.5mm" H 5550 5650 50  0001 C CNN
F 3 "~" H 5550 5650 50  0001 C CNN
F 4 "DNP" H 5550 5650 50  0001 C CNN "Population"
	1    5550 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 5650 5800 5650
Connection ~ 5800 5650
Wire Wire Line
	5800 5650 5800 5500
Wire Wire Line
	5450 5650 5300 5650
Connection ~ 5300 5650
$Comp
L Mechanical:MountingHole H1
U 1 1 61BCE530
P 1000 8300
F 0 "H1" H 1000 8500 50  0000 C CNN
F 1 "MountingHole" H 1000 8425 50  0000 C CNN
F 2 "MountingHole:MountingHole_2.7mm_M2.5" H 1000 8300 50  0001 C CNN
F 3 "~" H 1000 8300 50  0001 C CNN
	1    1000 8300
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H3
U 1 1 61BCEAAF
P 1600 8300
F 0 "H3" H 1600 8500 50  0000 C CNN
F 1 "MountingHole" H 1600 8425 50  0000 C CNN
F 2 "MountingHole:MountingHole_2.7mm_M2.5" H 1600 8300 50  0001 C CNN
F 3 "~" H 1600 8300 50  0001 C CNN
	1    1600 8300
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H4
U 1 1 61BCF017
P 1600 8800
F 0 "H4" H 1600 9000 50  0000 C CNN
F 1 "MountingHole" H 1600 8925 50  0000 C CNN
F 2 "MountingHole:MountingHole_2.7mm_M2.5" H 1600 8800 50  0001 C CNN
F 3 "~" H 1600 8800 50  0001 C CNN
	1    1600 8800
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H2
U 1 1 61BCF67B
P 1000 8800
F 0 "H2" H 1000 9000 50  0000 C CNN
F 1 "MountingHole" H 1000 8925 50  0000 C CNN
F 2 "MountingHole:MountingHole_2.7mm_M2.5" H 1000 8800 50  0001 C CNN
F 3 "~" H 1000 8800 50  0001 C CNN
	1    1000 8800
	1    0    0    -1  
$EndComp
$Comp
L Device:Polyfuse F1
U 1 1 60630AA9
P 1450 3050
F 0 "F1" V 1225 3050 50  0000 C CNN
F 1 "500mA" V 1316 3050 50  0000 C CNN
F 2 "Fuse:Fuse_0603_1608Metric_Castellated" H 1500 2850 50  0001 L CNN
F 3 "https://datasheet.lcsc.com/szlcsc/2103231635_BHFUSE-BSMD0603-050-6V_C883095.pdf" H 1450 3050 50  0001 C CNN
F 4 "BSMD0603-050-6V" H 1450 3050 50  0001 C CNN "MPN"
F 5 " BHFUSE" H 1450 3050 50  0001 C CNN "Manufacture"
F 6 "C883095" H 1450 3050 50  0001 C CNN "SPN"
F 7 "LCSC" H 1450 3050 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/PTC-Resettable-Fuses_BHFUSE-BSMD0603-050-6V_C883095.html" H 1450 3050 50  0001 C CNN "Supplier Link"
	1    1450 3050
	0    1    1    0   
$EndComp
Wire Wire Line
	1600 3050 1700 3050
Wire Wire Line
	1700 3050 1700 2950
$Comp
L Device:D_Schottky D4
U 1 1 606CD0B2
P 5000 3900
F 0 "D4" H 5000 4000 50  0000 C CNN
F 1 "1N4148W" H 5000 3800 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 5000 3900 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1809052017_MDD-Microdiode-Electronics-1N4148W_C84367.pdf" H 5000 3900 50  0001 C CNN
F 4 "1N4148W" H 5000 3900 50  0001 C CNN "MPN"
F 5 "Microdiode Electronics" H 5000 3900 50  0001 C CNN "Manufacture"
F 6 "C84367" H 5000 3900 50  0001 C CNN "SPN"
F 7 "LCSC" H 5000 3900 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Switching-Diode_MDD-Microdiode-Electronics-1N4148W_C84367.html" H 5000 3900 50  0001 C CNN "Supplier Link"
	1    5000 3900
	1    0    0    -1  
$EndComp
$Comp
L Device:D_Schottky D6
U 1 1 606DDDEA
P 10950 3500
F 0 "D6" H 10950 3600 50  0000 C CNN
F 1 "1N4148W" H 10950 3400 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 10950 3500 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1809052017_MDD-Microdiode-Electronics-1N4148W_C84367.pdf" H 10950 3500 50  0001 C CNN
F 4 "1N4148W" H 10950 3500 50  0001 C CNN "MPN"
F 5 "Microdiode Electronics" H 10950 3500 50  0001 C CNN "Manufacture"
F 6 "C84367" H 10950 3500 50  0001 C CNN "SPN"
F 7 "LCSC" H 10950 3500 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Switching-Diode_MDD-Microdiode-Electronics-1N4148W_C84367.html" H 10950 3500 50  0001 C CNN "Supplier Link"
	1    10950 3500
	-1   0    0    1   
$EndComp
Wire Wire Line
	12500 5100 12500 5250
Wire Wire Line
	6500 3850 6500 3800
$Comp
L power:GND #PWR030
U 1 1 604BD865
P 6500 3850
F 0 "#PWR030" H 6500 3600 50  0001 C CNN
F 1 "GND" H 6500 3700 50  0000 C CNN
F 2 "" H 6500 3850 50  0001 C CNN
F 3 "" H 6500 3850 50  0001 C CNN
	1    6500 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	8600 8500 8600 8700
$Comp
L power:GNDA #PWR048
U 1 1 6194A711
P 8600 8700
F 0 "#PWR048" H 8600 8450 50  0001 C CNN
F 1 "GNDA" H 8600 8550 50  0000 C CNN
F 2 "" H 8600 8700 50  0001 C CNN
F 3 "" H 8600 8700 50  0001 C CNN
	1    8600 8700
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 5700 7750 5700
Connection ~ 7400 5700
Wire Wire Line
	7400 5600 7400 5700
Wire Wire Line
	7400 5250 7400 5300
$Comp
L power:GND #PWR038
U 1 1 615FAF0A
P 7400 5250
F 0 "#PWR038" H 7400 5000 50  0001 C CNN
F 1 "GND" H 7400 5100 50  0000 C CNN
F 2 "" H 7400 5250 50  0001 C CNN
F 3 "" H 7400 5250 50  0001 C CNN
	1    7400 5250
	-1   0    0    1   
$EndComp
Wire Wire Line
	7750 5700 7800 5700
Connection ~ 7750 5700
Wire Wire Line
	7750 5600 7750 5700
Wire Wire Line
	7750 5250 7750 5300
Wire Wire Line
	7200 5700 7400 5700
$Comp
L Device:C C12
U 1 1 614A8010
P 7400 5450
F 0 "C12" H 7425 5550 50  0000 L CNN
F 1 "100nF" H 7425 5350 50  0000 L CNN
F 2 "C_0603_1608Metric" H 7438 5300 50  0001 C CNN
F 3 "https://api.kemet.com/component-edge/download/datasheet/C0603C104Z3VACTU.pdf" H 7400 5450 50  0001 C CNN
F 4 "C0603C104Z3VACTU" H 7400 5450 50  0001 C CNN "MPN"
F 5 "KEMET" H 7400 5450 50  0001 C CNN "Manufacture"
F 6 "399-1100-1-ND" H 7400 5450 50  0001 C CNN "SPN"
F 7 "DigiKey" H 7400 5450 50  0001 C CNN "Supplier"
F 8 "https://www.digikey.com/en/products/detail/kemet/C0603C104Z3VACTU/411099?s=N4IgTCBcDaIMwE4EFoCMqAMG3IHYBMQBdAXyA" H 7400 5450 50  0001 C CNN "Supplier Link"
	1    7400 5450
	1    0    0    -1  
$EndComp
Text Label 7600 5900 2    50   ~ 0
BOOT0
Wire Wire Line
	6350 5900 6350 5850
Wire Wire Line
	6350 5650 6350 5600
Wire Wire Line
	6350 5900 7800 5900
Text Label 9800 7100 0    50   ~ 0
PA3
Wire Wire Line
	9950 7100 9950 6950
NoConn ~ 7800 6400
NoConn ~ 7800 6600
NoConn ~ 7800 6500
$Comp
L Connector:TestPoint TP1
U 1 1 60D0AAE6
P 9950 6950
F 0 "TP1" H 9950 7220 50  0000 C CNN
F 1 "PA3" H 9950 7150 50  0000 C CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 10150 6950 50  0001 C CNN
F 3 "~" H 10150 6950 50  0001 C CNN
	1    9950 6950
	1    0    0    -1  
$EndComp
Wire Wire Line
	9950 7100 9100 7100
NoConn ~ 9100 7600
Text Label 9300 7800 0    50   ~ 0
I2C_SDA
Text Label 9300 7700 0    50   ~ 0
I2C_SCL
Wire Wire Line
	9650 7700 9100 7700
Wire Wire Line
	9650 7400 9650 7700
Wire Wire Line
	10200 7400 9650 7400
Wire Wire Line
	9750 7500 10200 7500
Wire Wire Line
	9750 7800 9750 7500
Wire Wire Line
	9100 7800 9750 7800
Wire Wire Line
	10100 7300 10200 7300
Wire Wire Line
	10100 7200 10100 7300
$Comp
L power:+5V #PWR054
U 1 1 60C64B12
P 10100 7200
F 0 "#PWR054" H 10100 7050 50  0001 C CNN
F 1 "+5V" H 10100 7340 50  0000 C CNN
F 2 "" H 10100 7200 50  0001 C CNN
F 3 "" H 10100 7200 50  0001 C CNN
	1    10100 7200
	1    0    0    -1  
$EndComp
Wire Wire Line
	10100 7600 10100 7700
Wire Wire Line
	10200 7600 10100 7600
$Comp
L power:GND #PWR055
U 1 1 60C2DD6F
P 10100 7700
F 0 "#PWR055" H 10100 7450 50  0001 C CNN
F 1 "GND" H 10100 7550 50  0000 C CNN
F 2 "" H 10100 7700 50  0001 C CNN
F 3 "" H 10100 7700 50  0001 C CNN
	1    10100 7700
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J4
U 1 1 60C2C21A
P 10400 7400
F 0 "J4" H 10400 7600 50  0000 C CNN
F 1 "I2C2" H 10400 7100 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 10400 7400 50  0001 C CNN
F 3 "~" H 10400 7400 50  0001 C CNN
F 4 "DNP" H 10400 7400 50  0001 C CNN "Population"
	1    10400 7400
	1    0    0    -1  
$EndComp
NoConn ~ 10200 8000
Wire Wire Line
	9100 8300 9300 8300
Wire Wire Line
	10100 8300 10200 8300
Wire Wire Line
	10100 8400 10100 8300
Text Label 9700 8200 0    50   ~ 0
SWCLK
Text Label 9700 8100 0    50   ~ 0
SWDIO
$Comp
L power:GND #PWR056
U 1 1 608117B1
P 10100 8400
F 0 "#PWR056" H 10100 8150 50  0001 C CNN
F 1 "GND" H 10100 8250 50  0000 C CNN
F 2 "" H 10100 8400 50  0001 C CNN
F 3 "" H 10100 8400 50  0001 C CNN
	1    10100 8400
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J5
U 1 1 607E5E4F
P 10400 8100
F 0 "J5" H 10400 8300 50  0000 C CNN
F 1 "STM_PROG" H 10400 7800 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 10400 8100 50  0001 C CNN
F 3 "~" H 10400 8100 50  0001 C CNN
F 4 "DNP" H 10400 8100 50  0001 C CNN "Population"
	1    10400 8100
	1    0    0    -1  
$EndComp
Wire Notes Line
	7100 6600 6250 6600
Wire Notes Line
	7100 7700 7100 6600
Wire Notes Line
	6250 7700 7100 7700
Wire Notes Line
	6250 6600 6250 7700
Text Notes 6350 7550 1    50   ~ 0
For Future 16bit DAC
Wire Wire Line
	6750 6900 6650 6900
Wire Wire Line
	6750 6800 6750 6900
$Comp
L power:+5V #PWR032
U 1 1 60732913
P 6750 6800
F 0 "#PWR032" H 6750 6650 50  0001 C CNN
F 1 "+5V" H 6750 6940 50  0000 C CNN
F 2 "" H 6750 6800 50  0001 C CNN
F 3 "" H 6750 6800 50  0001 C CNN
	1    6750 6800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 7000 6650 7000
Text Label 7050 7000 2    50   ~ 0
SPI3_CS
Text Label 9300 8300 0    50   ~ 0
SPI3_CS
Text Label 7050 7100 2    50   ~ 0
SPI3_SCK
Text Label 7050 7200 2    50   ~ 0
SPI3_MISO
Text Label 7050 7300 2    50   ~ 0
SPI3_MOSI
Wire Wire Line
	6750 7400 6750 7500
Wire Wire Line
	6650 7400 6750 7400
$Comp
L power:GND #PWR033
U 1 1 60664D2E
P 6750 7500
F 0 "#PWR033" H 6750 7250 50  0001 C CNN
F 1 "GND" H 6750 7350 50  0000 C CNN
F 2 "" H 6750 7500 50  0001 C CNN
F 3 "" H 6750 7500 50  0001 C CNN
	1    6750 7500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7800 7100 6650 7100
Wire Wire Line
	7800 7200 6650 7200
Wire Wire Line
	7800 7300 6650 7300
$Comp
L Connector_Generic:Conn_01x06 J3
U 1 1 6061E027
P 6450 7100
F 0 "J3" H 6450 7400 50  0000 C CNN
F 1 "SPI3" H 6450 6700 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 6450 7100 50  0001 C CNN
F 3 "~" H 6450 7100 50  0001 C CNN
F 4 "DNP" H 6450 7100 50  0001 C CNN "Population"
	1    6450 7100
	-1   0    0    -1  
$EndComp
$Comp
L Device:Jumper_NO_Small JP3
U 1 1 60946F1B
P 6350 5750
F 0 "JP3" H 6350 5830 50  0000 C CNN
F 1 "BOOT0" H 6360 5690 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 6350 5750 50  0001 C CNN
F 3 "~" H 6350 5750 50  0001 C CNN
F 4 "DNP" H 6350 5750 50  0001 C CNN "Population"
	1    6350 5750
	0    1    1    0   
$EndComp
$Comp
L power:+3V3 #PWR028
U 1 1 6094AC41
P 6350 5250
F 0 "#PWR028" H 6350 5100 50  0001 C CNN
F 1 "+3V3" H 6350 5390 50  0000 C CNN
F 2 "" H 6350 5250 50  0001 C CNN
F 3 "" H 6350 5250 50  0001 C CNN
	1    6350 5250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R14
U 1 1 609643DB
P 6350 5450
F 0 "R14" V 6430 5450 50  0000 C CNN
F 1 "1k" V 6350 5450 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6280 5450 50  0001 C CNN
F 3 "https://www.yageo.com/upload/media/product/productsearch/datasheet/rchip/PYu-RC_Group_51_RoHS_L_11.pdf" H 6350 5450 50  0001 C CNN
F 4 "RC0603JR-071KL" H 6350 5450 50  0001 C CNN "MPN"
F 5 "YAGEO" H 6350 5450 50  0001 C CNN "Manufacture"
F 6 "311-1.0KGRCT-ND" H 6350 5450 50  0001 C CNN "SPN"
F 7 "DigiKey" H 6350 5450 50  0001 C CNN "Supplier"
F 8 "https://www.digikey.com/en/products/detail/yageo/RC0603JR-071KL/726677?s=N4IgTCBcDaIMwEYEFoEDoAMBrA5gJwGMAXZAOwBMQBdAXyA" H 6350 5450 50  0001 C CNN "Supplier Link"
	1    6350 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 5300 6350 5250
$Comp
L Device:R R22
U 1 1 6147B871
P 7750 5450
F 0 "R22" V 7830 5450 50  0000 C CNN
F 1 "10k" V 7750 5450 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7680 5450 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1811081617_YAGEO-RC0603JR-0710KL_C99198.pdf" H 7750 5450 50  0001 C CNN
F 4 "RC0603JR-0710KL" H 7750 5450 50  0001 C CNN "MPN"
F 5 "YAGEO" H 7750 5450 50  0001 C CNN "Manufacture"
F 6 "C99198" H 7750 5450 50  0001 C CNN "SPN"
F 7 "LCSC" H 7750 5450 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_YAGEO-RC0603JR-0710KL_C99198.html" H 7750 5450 50  0001 C CNN "Supplier Link"
	1    7750 5450
	1    0    0    -1  
$EndComp
$Comp
L MCU_ST_STM32F3:STM32F302C8Tx U3
U 1 1 605CE094
P 8500 7000
F 0 "U3" H 8900 5550 50  0000 L CNN
F 1 "STM32F302C8T6" V 8500 6700 50  0000 L CNN
F 2 "Package_QFP:LQFP-48_7x7mm_P0.5mm" H 7900 5600 50  0001 R CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/DM00093333.pdf" H 8500 7000 50  0001 C CNN
F 4 "STM32F302C8T6 " H 8500 7000 50  0001 C CNN "MPN"
F 5 "STMicroelectronics " H 8500 7000 50  0001 C CNN "Manufacture"
F 6 "511-STM32F302C8T6 " H 8500 7000 50  0001 C CNN "SPN"
F 7 "Mouser" H 8500 7000 50  0001 C CNN "Supplier"
F 8 "https://www.mouser.com/ProductDetail/511-STM32F302C8T6" H 8500 7000 50  0001 C CNN "Supplier Link"
	1    8500 7000
	1    0    0    -1  
$EndComp
Wire Wire Line
	9100 7200 9300 7200
Wire Wire Line
	9100 8200 10200 8200
Wire Wire Line
	9100 8100 10200 8100
Text GLabel 9300 7200 2    50   Input ~ 0
DAC
Text GLabel 7600 7600 0    50   Input ~ 0
CAN_RX
Text GLabel 7600 7700 0    50   Input ~ 0
CAN_TX
Wire Wire Line
	7800 7600 7600 7600
Wire Wire Line
	7800 7700 7600 7700
Text GLabel 7600 8100 0    50   Input ~ 0
SCLK
Text GLabel 7600 8200 0    50   Input ~ 0
MISO
Text GLabel 7600 8300 0    50   Input ~ 0
MOSI
Wire Wire Line
	7800 8100 7600 8100
Wire Wire Line
	7800 8200 7600 8200
Wire Wire Line
	7800 8300 7600 8300
Text GLabel 9300 8000 2    50   Input ~ 0
USB_DP
Text GLabel 9300 7900 2    50   Input ~ 0
USB_DM
Wire Wire Line
	9100 7900 9300 7900
Wire Wire Line
	9100 8000 9300 8000
Text GLabel 7600 8000 0    50   Input ~ 0
STM_CS
Wire Wire Line
	7600 8000 7800 8000
Text GLabel 7600 7900 0    50   Input ~ 0
STM_RDY
Wire Wire Line
	7600 7900 7800 7900
$Comp
L Device:Resonator Y1
U 1 1 6098BD8E
P 6650 6200
F 0 "Y1" H 6650 6425 50  0000 C CNN
F 1 "16MHz" H 6650 6350 50  0000 C CNN
F 2 "Crystal:Resonator_SMD_muRata_CSTxExxV-3Pin_3.0x1.1mm" H 6625 6200 50  0001 C CNN
F 3 "https://www.mouser.com/datasheet/2/281/murata_04192018_CSTN_CeramResonCERAL-1323383.pdf" H 6625 6200 50  0001 C CNN
F 4 "DNP" V 6650 6200 50  0000 C CNN "Population"
F 5 "CSTNE16M0VH3C000R0 " H 6650 6200 50  0001 C CNN "MPN"
F 6 "Murata Electronics" H 6650 6200 50  0001 C CNN "Manufacture"
F 7 "81-CSTNE16M0VH3C000R " H 6650 6200 50  0001 C CNN "SPN"
F 8 "Mouser" H 6650 6200 50  0001 C CNN "Supplier"
F 9 "https://www.mouser.com/ProductDetail/81-CSTNE16M0VH3C000R" H 6650 6200 50  0001 C CNN "Supplier Link"
	1    6650 6200
	0    1    1    0   
$EndComp
Wire Wire Line
	7800 6100 7250 6100
Wire Wire Line
	7250 6100 7250 6000
Wire Wire Line
	6900 6000 6650 6000
Wire Wire Line
	6650 6000 6650 6050
Wire Wire Line
	7800 6200 7250 6200
Wire Wire Line
	7250 6200 7250 6400
Wire Wire Line
	6900 6400 6650 6400
Wire Wire Line
	6650 6400 6650 6350
$Comp
L power:GND #PWR029
U 1 1 609C86F5
P 6350 6300
F 0 "#PWR029" H 6350 6050 50  0001 C CNN
F 1 "GND" H 6350 6150 50  0000 C CNN
F 2 "" H 6350 6300 50  0001 C CNN
F 3 "" H 6350 6300 50  0001 C CNN
	1    6350 6300
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 6300 6350 6200
Wire Wire Line
	6350 6200 6450 6200
Text Label 7600 6100 2    50   ~ 0
XIN
Text Label 7600 6200 2    50   ~ 0
XOUT
$Comp
L Device:R R19
U 1 1 60AC19FC
P 7050 6000
F 0 "R19" V 7130 6000 50  0000 C CNN
F 1 "R" V 7050 6000 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6980 6000 50  0001 C CNN
F 3 "~" H 7050 6000 50  0001 C CNN
F 4 "DNP" V 7200 6000 50  0000 C CNN "Population"
	1    7050 6000
	0    1    1    0   
$EndComp
$Comp
L Device:R R20
U 1 1 60AC1C1C
P 7050 6400
F 0 "R20" V 7130 6400 50  0000 C CNN
F 1 "R" V 7050 6400 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6980 6400 50  0001 C CNN
F 3 "~" H 7050 6400 50  0001 C CNN
F 4 "DNP" V 6950 6400 50  0000 C CNN "Population"
	1    7050 6400
	0    1    1    0   
$EndComp
Wire Wire Line
	7200 6000 7250 6000
Wire Wire Line
	7200 6400 7250 6400
$Comp
L power:+3V3 #PWR047
U 1 1 60B89715
P 8500 5250
F 0 "#PWR047" H 8500 5100 50  0001 C CNN
F 1 "+3V3" H 8500 5390 50  0000 C CNN
F 2 "" H 8500 5250 50  0001 C CNN
F 3 "" H 8500 5250 50  0001 C CNN
	1    8500 5250
	1    0    0    -1  
$EndComp
$Comp
L power:+BATT #PWR044
U 1 1 60C9AF35
P 8300 5400
F 0 "#PWR044" H 8300 5250 50  0001 C CNN
F 1 "+BATT" H 8300 5540 50  0000 C CNN
F 2 "" H 8300 5400 50  0001 C CNN
F 3 "" H 8300 5400 50  0001 C CNN
	1    8300 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	8300 5400 8300 5500
$Comp
L power:VDDA #PWR049
U 1 1 60D65E71
P 8700 5400
F 0 "#PWR049" H 8700 5250 50  0001 C CNN
F 1 "VDDA" H 8700 5550 50  0000 C CNN
F 2 "" H 8700 5400 50  0001 C CNN
F 3 "" H 8700 5400 50  0001 C CNN
	1    8700 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	8500 5250 8500 5400
Wire Wire Line
	8700 5500 8700 5400
Wire Wire Line
	8600 5500 8600 5400
Wire Wire Line
	8600 5400 8500 5400
Connection ~ 8500 5400
Wire Wire Line
	8500 5400 8500 5500
Wire Wire Line
	8500 5400 8400 5400
Wire Wire Line
	8400 5400 8400 5500
Text GLabel 7200 5700 0    50   Input ~ 0
STM_RESET
$Comp
L power:+3V3 #PWR040
U 1 1 614563BF
P 7750 5250
F 0 "#PWR040" H 7750 5100 50  0001 C CNN
F 1 "+3V3" H 7750 5390 50  0000 C CNN
F 2 "" H 7750 5250 50  0001 C CNN
F 3 "" H 7750 5250 50  0001 C CNN
	1    7750 5250
	1    0    0    -1  
$EndComp
Text GLabel 7600 7500 0    50   Input ~ 0
CAN_TERM
Wire Wire Line
	7600 7500 7800 7500
Text GLabel 7600 7400 0    50   Input ~ 0
CAN_RS
Wire Wire Line
	7600 7400 7800 7400
$Comp
L power:GND #PWR045
U 1 1 617533C4
P 8300 8700
F 0 "#PWR045" H 8300 8450 50  0001 C CNN
F 1 "GND" H 8300 8550 50  0000 C CNN
F 2 "" H 8300 8700 50  0001 C CNN
F 3 "" H 8300 8700 50  0001 C CNN
	1    8300 8700
	1    0    0    -1  
$EndComp
Wire Wire Line
	8300 8700 8300 8600
Wire Wire Line
	8300 8600 8400 8600
Connection ~ 8300 8600
Wire Wire Line
	8300 8600 8300 8500
Wire Wire Line
	8500 8500 8500 8600
Wire Wire Line
	8400 8500 8400 8600
Connection ~ 8400 8600
Wire Wire Line
	8400 8600 8500 8600
Text Notes 6200 4850 0    50   ~ 0
STM32F302 CAN Interface
Wire Notes Line
	6200 4850 10650 4850
Wire Notes Line
	10650 9100 6200 9100
Wire Notes Line
	6200 9100 6200 4750
Wire Notes Line
	6200 4750 10650 4750
Wire Notes Line
	10650 4750 10650 9100
Text GLabel 9300 6800 2    50   Input ~ 0
CAN_LED
Text GLabel 9300 6900 2    50   Input ~ 0
SPI_LED
Text GLabel 9300 7000 2    50   Input ~ 0
ERROR_LED
Wire Wire Line
	9100 6800 9300 6800
Wire Wire Line
	9100 6900 9300 6900
Wire Wire Line
	9100 7000 9300 7000
$Comp
L power:+3V3 #PWR014
U 1 1 600D2B0A
P 3050 3000
F 0 "#PWR014" H 3050 2850 50  0001 C CNN
F 1 "+3V3" H 3050 3140 50  0000 C CNN
F 2 "" H 3050 3000 50  0001 C CNN
F 3 "" H 3050 3000 50  0001 C CNN
	1    3050 3000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R10
U 1 1 600CFC58
P 3050 3900
F 0 "R10" V 3130 3900 50  0000 C CNN
F 1 "1.5k" V 3050 3900 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2980 3900 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1811061750_FH-Guangdong-Fenghua-Advanced-Tech-RS-03K152JT_C118361.pdf" H 3050 3900 50  0001 C CNN
F 4 "RS-03K152JT" H 3050 3900 50  0001 C CNN "MPN"
F 5 " FH(Guangdong Fenghua Advanced Tech)" H 3050 3900 50  0001 C CNN "Manufacture"
F 6 "C118361" H 3050 3900 50  0001 C CNN "SPN"
F 7 "LCSC" H 3050 3900 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_FH-Guangdong-Fenghua-Advanced-Tech-RS-03K152JT_C118361.html" H 3050 3900 50  0001 C CNN "Supplier Link"
	1    3050 3900
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NPN_BEC Q2
U 1 1 609ACDB2
P 2950 3500
F 0 "Q2" H 3150 3550 50  0000 L CNN
F 1 "MMBT2222A" H 3150 3450 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 3150 3600 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/2012041134_JSMSEMI-MMBT2222A_C916372.pdf" H 2950 3500 50  0001 C CNN
F 4 "MMBT2222A" H 2950 3500 50  0001 C CNN "MPN"
F 5 "JSMSEMI" H 2950 3500 50  0001 C CNN "Manufacture"
F 6 "C916372" H 2950 3500 50  0001 C CNN "SPN"
F 7 "LCSC" H 2950 3500 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Transistors-NPN-PNP_JSMSEMI-MMBT2222A_C916372.html" H 2950 3500 50  0001 C CNN "Supplier Link"
	1    2950 3500
	1    0    0    -1  
$EndComp
Text Notes 2250 2750 0    50   ~ 0
STM32 USB Pullup
Wire Wire Line
	3050 4050 3050 4150
Wire Wire Line
	3050 4150 3150 4150
Wire Wire Line
	3050 3750 3050 3700
Wire Wire Line
	3050 3300 3050 3000
$Comp
L Device:R R4
U 1 1 60A4C83F
P 2650 3250
F 0 "R4" V 2730 3250 50  0000 C CNN
F 1 "10k" V 2650 3250 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2580 3250 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1811081617_YAGEO-RC0603JR-0710KL_C99198.pdf" H 2650 3250 50  0001 C CNN
F 4 "RC0603JR-0710KL" H 2650 3250 50  0001 C CNN "MPN"
F 5 "YAGEO" H 2650 3250 50  0001 C CNN "Manufacture"
F 6 "C99198" H 2650 3250 50  0001 C CNN "SPN"
F 7 "LCSC" H 2650 3250 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_YAGEO-RC0603JR-0710KL_C99198.html" H 2650 3250 50  0001 C CNN "Supplier Link"
	1    2650 3250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 60A4D4B7
P 2650 3750
F 0 "R5" V 2730 3750 50  0000 C CNN
F 1 "20k" V 2650 3750 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2580 3750 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1811081710_UNI-ROYAL-Uniroyal-Elec-0603WAJ0203T5E_C25586.pdf" H 2650 3750 50  0001 C CNN
F 4 "0603WAJ0203T5E" H 2650 3750 50  0001 C CNN "MPN"
F 5 " UNI-ROYAL(Uniroyal Elec)" H 2650 3750 50  0001 C CNN "Manufacture"
F 6 "C25586" H 2650 3750 50  0001 C CNN "SPN"
F 7 "LCSC" H 2650 3750 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_UNI-ROYAL-Uniroyal-Elec-0603WAJ0203T5E_C25586.html" H 2650 3750 50  0001 C CNN "Supplier Link"
	1    2650 3750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR012
U 1 1 60A4E047
P 2650 4400
F 0 "#PWR012" H 2650 4150 50  0001 C CNN
F 1 "GND" H 2650 4250 50  0000 C CNN
F 2 "" H 2650 4400 50  0001 C CNN
F 3 "" H 2650 4400 50  0001 C CNN
	1    2650 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 4400 2650 4250
Wire Wire Line
	2650 3400 2650 3500
Wire Wire Line
	2750 3500 2650 3500
Connection ~ 2650 3500
Wire Wire Line
	2650 3500 2650 3600
Wire Wire Line
	2650 3000 2650 3100
$Comp
L power:VBUS #PWR011
U 1 1 60ABFC32
P 2650 3000
F 0 "#PWR011" H 2650 2850 50  0001 C CNN
F 1 "VBUS" H 2650 3150 50  0000 C CNN
F 2 "" H 2650 3000 50  0001 C CNN
F 3 "" H 2650 3000 50  0001 C CNN
	1    2650 3000
	1    0    0    -1  
$EndComp
Wire Notes Line
	2250 2750 3800 2750
Wire Notes Line
	3800 4650 2250 4650
Wire Notes Line
	2250 4650 2250 2650
Wire Notes Line
	2250 2650 3800 2650
Wire Notes Line
	3800 2650 3800 4650
Text GLabel 3150 4150 2    50   Input ~ 0
USB_DP
$Comp
L Device:R R6
U 1 1 63887C0E
P 2650 4100
F 0 "R6" V 2730 4100 50  0000 C CNN
F 1 "20k" V 2650 4100 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2580 4100 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1811081710_UNI-ROYAL-Uniroyal-Elec-0603WAJ0203T5E_C25586.pdf" H 2650 4100 50  0001 C CNN
F 4 "0603WAJ0203T5E" H 2650 4100 50  0001 C CNN "MPN"
F 5 " UNI-ROYAL(Uniroyal Elec)" H 2650 4100 50  0001 C CNN "Manufacture"
F 6 "C25586" H 2650 4100 50  0001 C CNN "SPN"
F 7 "LCSC" H 2650 4100 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_UNI-ROYAL-Uniroyal-Elec-0603WAJ0203T5E_C25586.html" H 2650 4100 50  0001 C CNN "Supplier Link"
	1    2650 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 3950 2650 3900
$Comp
L Connector_Generic:Conn_01x03 J8
U 1 1 60A9A0A7
P 16200 2000
F 0 "J8" H 16200 2200 50  0000 C CNN
F 1 "CAN" H 16200 1800 50  0000 C CNN
F 2 "pl_TerminalBlock:WJ127-5.0-3P" H 16200 2000 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1912251633_Ningbo-Kangnex-Elec-WJ127-5-0-3P_C8393.pdf" H 16200 2000 50  0001 C CNN
F 4 "WJ127-5.0-3P" H 16200 2000 50  0001 C CNN "MPN"
F 5 " Ningbo Kangnex Elec" H 16200 2000 50  0001 C CNN "Manufacture"
F 6 "C8393" H 16200 2000 50  0001 C CNN "SPN"
F 7 "LCSC" H 16200 2000 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Screw-terminal_Ningbo-Kangnex-Elec-WJ127-5-0-3P_C8393.html" H 16200 2000 50  0001 C CNN "Supplier Link"
	1    16200 2000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR070
U 1 1 633F6BE0
P 13250 2350
F 0 "#PWR070" H 13250 2100 50  0001 C CNN
F 1 "GND" H 13250 2200 50  0000 C CNN
F 2 "" H 13250 2350 50  0001 C CNN
F 3 "" H 13250 2350 50  0001 C CNN
	1    13250 2350
	1    0    0    -1  
$EndComp
$Comp
L pl_diode:PESD1CAN-UX D11
U 1 1 633AC099
P 13250 2150
F 0 "D11" H 13150 2000 50  0000 C CNN
F 1 "PESD1CAN" V 13500 2150 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 13250 2150 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/2010221035_TECH-PUBLIC-PESD1CAN_C907838.pdf" H 13250 2150 50  0001 C CNN
F 4 "PESD1CAN" H 13250 2150 50  0001 C CNN "MPN"
F 5 "TECH PUBLIC" H 13250 2150 50  0001 C CNN "Manufacture"
F 6 "C907838" H 13250 2150 50  0001 C CNN "SPN"
F 7 "LCSC" H 13250 2150 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Diodes-ESD_TECH-PUBLIC-PESD1CAN_C907838.html" H 13250 2150 50  0001 C CNN "Supplier Link"
	1    13250 2150
	-1   0    0    -1  
$EndComp
Wire Wire Line
	16000 2100 15900 2100
Text GLabel 14200 2000 0    50   Input ~ 0
CAN_TERM
$Comp
L Device:C C19
U 1 1 616070FD
P 14050 1800
F 0 "C19" H 14075 1900 50  0000 L CNN
F 1 "100nF" H 14075 1700 50  0000 L CNN
F 2 "C_0603_1608Metric" H 14088 1650 50  0001 C CNN
F 3 "https://api.kemet.com/component-edge/download/datasheet/C0603C104Z3VACTU.pdf" H 14050 1800 50  0001 C CNN
F 4 "C0603C104Z3VACTU" H 14050 1800 50  0001 C CNN "MPN"
F 5 "KEMET" H 14050 1800 50  0001 C CNN "Manufacture"
F 6 "399-1100-1-ND" H 14050 1800 50  0001 C CNN "SPN"
F 7 "DigiKey" H 14050 1800 50  0001 C CNN "Supplier"
F 8 "https://www.digikey.com/en/products/detail/kemet/C0603C104Z3VACTU/411099?s=N4IgTCBcDaIMwE4EFoCMqAMG3IHYBMQBdAXyA" H 14050 1800 50  0001 C CNN "Supplier Link"
	1    14050 1800
	0    -1   -1   0   
$EndComp
$Comp
L power:+5V #PWR072
U 1 1 61604AE6
P 14300 1700
F 0 "#PWR072" H 14300 1550 50  0001 C CNN
F 1 "+5V" H 14300 1840 50  0000 C CNN
F 2 "" H 14300 1700 50  0001 C CNN
F 3 "" H 14300 1700 50  0001 C CNN
	1    14300 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	14400 2000 14200 2000
Wire Wire Line
	14300 2100 14400 2100
Wire Wire Line
	14300 2200 14300 2100
$Comp
L power:GND #PWR073
U 1 1 615A40B2
P 14300 2200
F 0 "#PWR073" H 14300 1950 50  0001 C CNN
F 1 "GND" H 14300 2050 50  0000 C CNN
F 2 "" H 14300 2200 50  0001 C CNN
F 3 "" H 14300 2200 50  0001 C CNN
	1    14300 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	14300 1800 14400 1800
Wire Wire Line
	14300 1700 14300 1800
Wire Wire Line
	15200 1900 15300 1900
$Comp
L power:GND #PWR074
U 1 1 601241D7
P 15900 2300
F 0 "#PWR074" H 15900 2050 50  0001 C CNN
F 1 "GND" H 15900 2150 50  0000 C CNN
F 2 "" H 15900 2300 50  0001 C CNN
F 3 "" H 15900 2300 50  0001 C CNN
	1    15900 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	15900 2300 15900 2100
$Comp
L pl_analog-switch:74AHC1G66 U8
U 1 1 614F94FD
P 14800 1900
F 0 "U8" H 15050 1600 50  0000 C CNN
F 1 "74AHC1G66" H 14800 2100 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-353_SC-70-5" H 14800 1900 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1809191939_Nexperia-74AHC1G66GW-125_C96224.pdf" H 14800 1900 50  0001 C CNN
F 4 "74AHC1G66GW,125" H 14800 1900 50  0001 C CNN "MPN"
F 5 "Nexperia" H 14800 1900 50  0001 C CNN "Manufacture"
F 6 "C96224" H 14800 1900 50  0001 C CNN "SPN"
F 7 "LCSC" H 14800 1900 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Analog-Switches_Nexperia-74AHC1G66GW-125_C96224.html" H 14800 1900 50  0001 C CNN "Supplier Link"
	1    14800 1900
	1    0    0    -1  
$EndComp
Wire Notes Line
	11050 2550 11050 550 
Wire Notes Line
	11050 550  16400 550 
Wire Notes Line
	11050 650  16400 650 
Text Notes 11050 650  0    50   ~ 0
CAN Interface
NoConn ~ 11850 1900
$Comp
L Interface_CAN_LIN:SN65HVD230 U7
U 1 1 600DFA71
P 12250 1800
F 0 "U7" H 12550 1450 50  0000 R CNN
F 1 "SN65HVD230" H 12150 2050 50  0000 R CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 12250 1300 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn65hvd230.pdf" H 12150 2200 50  0001 C CNN
F 4 "SN65HVD230DR" H 12250 1800 50  0001 C CNN "MPN"
F 5 "Texas Instruments" H 12250 1800 50  0001 C CNN "Manufacture"
F 6 "C12084" H 12250 1800 50  0001 C CNN "SPN"
F 7 "LCSC" H 12250 1800 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/CAN-ICs_Texas-Instruments-SN65HVD230DR_C12084.html" H 12250 1800 50  0001 C CNN "Supplier Link"
	1    12250 1800
	1    0    0    -1  
$EndComp
$Comp
L Device:R R27
U 1 1 600E362D
P 11650 2000
F 0 "R27" V 11730 2000 50  0000 C CNN
F 1 "R" V 11650 2000 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 11580 2000 50  0001 C CNN
F 3 "~" H 11650 2000 50  0001 C CNN
F 4 "DNP" H 11650 2000 50  0001 C CNN "Population"
	1    11650 2000
	0    1    1    0   
$EndComp
$Comp
L Device:C C16
U 1 1 600F3B45
P 12450 1250
F 0 "C16" H 12475 1350 50  0000 L CNN
F 1 "100nF" H 12475 1150 50  0000 L CNN
F 2 "C_0603_1608Metric" H 12488 1100 50  0001 C CNN
F 3 "https://api.kemet.com/component-edge/download/datasheet/C0603C104Z3VACTU.pdf" H 12450 1250 50  0001 C CNN
F 4 "C0603C104Z3VACTU" H 12450 1250 50  0001 C CNN "MPN"
F 5 "KEMET" H 12450 1250 50  0001 C CNN "Manufacture"
F 6 "399-1100-1-ND" H 12450 1250 50  0001 C CNN "SPN"
F 7 "DigiKey" H 12450 1250 50  0001 C CNN "Supplier"
F 8 "https://www.digikey.com/en/products/detail/kemet/C0603C104Z3VACTU/411099?s=N4IgTCBcDaIMwE4EFoCMqAMG3IHYBMQBdAXyA" H 12450 1250 50  0001 C CNN "Supplier Link"
	1    12450 1250
	0    1    1    0   
$EndComp
$Comp
L Device:R R32
U 1 1 600FDB45
P 15450 1900
F 0 "R32" V 15530 1900 50  0000 C CNN
F 1 "120" V 15450 1900 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 15380 1900 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1811061723_FH-Guangdong-Fenghua-Advanced-Tech-RS-03K1200FT_C310266.pdf" H 15450 1900 50  0001 C CNN
F 4 "RS-03K1200FT" H 15450 1900 50  0001 C CNN "MPN"
F 5 " FH(Guangdong Fenghua Advanced Tech)" H 15450 1900 50  0001 C CNN "Manufacture"
F 6 "C310266" H 15450 1900 50  0001 C CNN "SPN"
F 7 "LCSC" H 15450 1900 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_FH-Guangdong-Fenghua-Advanced-Tech-RS-03K1200FT_C310266.html" H 15450 1900 50  0001 C CNN "Supplier Link"
	1    15450 1900
	0    1    1    0   
$EndComp
Text Label 13000 1900 2    50   ~ 0
CANL
Text Label 13000 1800 2    50   ~ 0
CANH
Wire Wire Line
	12700 1250 12700 1300
Wire Wire Line
	12600 1250 12700 1250
$Comp
L power:GND #PWR067
U 1 1 600F4F23
P 12700 1300
F 0 "#PWR067" H 12700 1050 50  0001 C CNN
F 1 "GND" H 12700 1150 50  0000 C CNN
F 2 "" H 12700 1300 50  0001 C CNN
F 3 "" H 12700 1300 50  0001 C CNN
	1    12700 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	12250 1250 12250 1500
Connection ~ 12250 1250
Wire Wire Line
	12300 1250 12250 1250
Wire Wire Line
	12250 2300 12250 2200
$Comp
L power:GND #PWR062
U 1 1 600F1A23
P 12250 2300
F 0 "#PWR062" H 12250 2050 50  0001 C CNN
F 1 "GND" H 12250 2150 50  0000 C CNN
F 2 "" H 12250 2300 50  0001 C CNN
F 3 "" H 12250 2300 50  0001 C CNN
	1    12250 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	12250 1150 12250 1250
$Comp
L power:+3V3 #PWR061
U 1 1 600F001C
P 11850 900
F 0 "#PWR061" H 11850 750 50  0001 C CNN
F 1 "+3V3" H 11850 1040 50  0000 C CNN
F 2 "" H 11850 900 50  0001 C CNN
F 3 "" H 11850 900 50  0001 C CNN
	1    11850 900 
	1    0    0    -1  
$EndComp
Text GLabel 11450 2000 0    50   Input ~ 0
CAN_RS
Wire Wire Line
	11500 2000 11450 2000
Wire Wire Line
	11800 2000 11850 2000
Wire Wire Line
	11450 1800 11850 1800
Text GLabel 11450 1800 0    50   Input ~ 0
CAN_RX
Wire Wire Line
	11450 1700 11850 1700
Text GLabel 11450 1700 0    50   Input ~ 0
CAN_TX
Wire Wire Line
	4150 3850 4150 3900
Connection ~ 4150 3900
Wire Wire Line
	4150 3900 4150 3950
Wire Notes Line
	3900 4650 6100 4650
Wire Notes Line
	6100 4650 6100 3050
Wire Notes Line
	6100 3050 3900 3050
Wire Notes Line
	3900 3050 3900 4650
Wire Notes Line
	3900 3150 6100 3150
Text Notes 3900 3150 0    50   ~ 0
Reset Circuitry
Text Notes 550  7800 0    50   ~ 0
Mechanical
Wire Notes Line
	550  7800 2050 7800
Wire Notes Line
	2050 9300 550  9300
Wire Notes Line
	550  9300 550  7700
Wire Notes Line
	550  7700 2050 7700
Wire Notes Line
	2050 7700 2050 9300
Text Notes 550  9450 0    50   ~ 0
ERC Happy Area
Wire Notes Line
	550  9450 3150 9450
Wire Notes Line
	3150 10450 550  10450
Wire Notes Line
	550  10450 550  9350
Wire Notes Line
	550  9350 3150 9350
Wire Notes Line
	3150 9350 3150 10450
Wire Wire Line
	7800 6800 7600 6800
Wire Wire Line
	7800 6900 7600 6900
Wire Wire Line
	7800 7000 7600 7000
Text GLabel 7600 6800 0    50   Input ~ 0
V_B0
Text GLabel 7600 6900 0    50   Input ~ 0
V_B1
Text GLabel 7600 7000 0    50   Input ~ 0
V_B2
Text GLabel 6600 10050 0    50   Input ~ 0
V_B0
Text GLabel 6600 9750 0    50   Input ~ 0
V_B1
Text GLabel 6600 9450 0    50   Input ~ 0
V_B2
$Comp
L Device:R R16
U 1 1 6193F18D
P 6950 9450
F 0 "R16" V 7030 9450 50  0000 C CNN
F 1 "1k" V 6950 9450 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6880 9450 50  0001 C CNN
F 3 "https://www.yageo.com/upload/media/product/productsearch/datasheet/rchip/PYu-RC_Group_51_RoHS_L_11.pdf" H 6950 9450 50  0001 C CNN
F 4 "DNP" V 6850 9450 50  0000 C CNN "Population"
F 5 "RC0603JR-071KL" H 6950 9450 50  0001 C CNN "MPN"
F 6 "YAGEO" H 6950 9450 50  0001 C CNN "Manufacture"
F 7 "311-1.0KGRCT-ND" H 6950 9450 50  0001 C CNN "SPN"
F 8 "DigiKey" H 6950 9450 50  0001 C CNN "Supplier"
F 9 "https://www.digikey.com/en/products/detail/yageo/RC0603JR-071KL/726677?s=N4IgTCBcDaIMwEYEFoEDoAMBrA5gJwGMAXZAOwBMQBdAXyA" H 6950 9450 50  0001 C CNN "Supplier Link"
	1    6950 9450
	0    1    1    0   
$EndComp
$Comp
L Device:R R17
U 1 1 619442A6
P 6950 9750
F 0 "R17" V 7030 9750 50  0000 C CNN
F 1 "1k" V 6950 9750 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6880 9750 50  0001 C CNN
F 3 "https://www.yageo.com/upload/media/product/productsearch/datasheet/rchip/PYu-RC_Group_51_RoHS_L_11.pdf" H 6950 9750 50  0001 C CNN
F 4 "DNP" V 6850 9750 50  0000 C CNN "Population"
F 5 "RC0603JR-071KL" H 6950 9750 50  0001 C CNN "MPN"
F 6 "YAGEO" H 6950 9750 50  0001 C CNN "Manufacture"
F 7 "311-1.0KGRCT-ND" H 6950 9750 50  0001 C CNN "SPN"
F 8 "DigiKey" H 6950 9750 50  0001 C CNN "Supplier"
F 9 "https://www.digikey.com/en/products/detail/yageo/RC0603JR-071KL/726677?s=N4IgTCBcDaIMwEYEFoEDoAMBrA5gJwGMAXZAOwBMQBdAXyA" H 6950 9750 50  0001 C CNN "Supplier Link"
	1    6950 9750
	0    1    1    0   
$EndComp
$Comp
L Device:R R18
U 1 1 6194447C
P 6950 10050
F 0 "R18" V 7030 10050 50  0000 C CNN
F 1 "1k" V 6950 10050 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6880 10050 50  0001 C CNN
F 3 "https://www.yageo.com/upload/media/product/productsearch/datasheet/rchip/PYu-RC_Group_51_RoHS_L_11.pdf" H 6950 10050 50  0001 C CNN
F 4 "RC0603JR-071KL" H 6950 10050 50  0001 C CNN "MPN"
F 5 "YAGEO" H 6950 10050 50  0001 C CNN "Manufacture"
F 6 "311-1.0KGRCT-ND" H 6950 10050 50  0001 C CNN "SPN"
F 7 "DigiKey" H 6950 10050 50  0001 C CNN "Supplier"
F 8 "https://www.digikey.com/en/products/detail/yageo/RC0603JR-071KL/726677?s=N4IgTCBcDaIMwEYEFoEDoAMBrA5gJwGMAXZAOwBMQBdAXyA" H 6950 10050 50  0001 C CNN "Supplier Link"
	1    6950 10050
	0    1    1    0   
$EndComp
Wire Wire Line
	6600 9450 6800 9450
Wire Wire Line
	6600 9750 6800 9750
Wire Wire Line
	6600 10050 6800 10050
$Comp
L power:GND #PWR037
U 1 1 6199AF0D
P 7300 10200
F 0 "#PWR037" H 7300 9950 50  0001 C CNN
F 1 "GND" H 7300 10050 50  0000 C CNN
F 2 "" H 7300 10200 50  0001 C CNN
F 3 "" H 7300 10200 50  0001 C CNN
	1    7300 10200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7300 10200 7300 10050
Wire Wire Line
	7300 9450 7100 9450
Wire Wire Line
	7100 9750 7300 9750
Connection ~ 7300 9750
Wire Wire Line
	7300 9750 7300 9450
Wire Wire Line
	7100 10050 7300 10050
Connection ~ 7300 10050
Wire Wire Line
	7300 10050 7300 9750
Text Notes 6200 9300 0    50   ~ 0
CAN Interface HW Version Indicator
Text Notes 7450 9500 0    50   ~ 0
Version
Text Notes 8300 9500 0    50   ~ 0
V_B2
Text Notes 6350 10150 1    50   ~ 0
GPIO Internal Pullup
Text Notes 7550 9600 0    50   ~ 0
0
Text Notes 7550 9700 0    50   ~ 0
1
Text Notes 7550 9800 0    50   ~ 0
2
Text Notes 7550 9900 0    50   ~ 0
3
Text Notes 7550 10000 0    50   ~ 0
4
Text Notes 7550 10100 0    50   ~ 0
5
Text Notes 7550 10200 0    50   ~ 0
6
Text Notes 7550 10300 0    50   ~ 0
7
Text Notes 7850 9600 0    50   ~ 0
H
Text Notes 7850 10300 0    50   ~ 0
L
Text Notes 7850 9700 0    50   ~ 0
L
Text Notes 8100 10300 0    50   ~ 0
L
Text Notes 8350 10300 0    50   ~ 0
L
Text Notes 8100 9600 0    50   ~ 0
H
Text Notes 8350 9600 0    50   ~ 0
H
Text Notes 8100 9700 0    50   ~ 0
H
Text Notes 8350 9700 0    50   ~ 0
H
Text Notes 8100 9800 0    50   ~ 0
L
Text Notes 7850 9800 0    50   ~ 0
H
Text Notes 8350 9800 0    50   ~ 0
H
Text Notes 8100 9900 0    50   ~ 0
L
Text Notes 7850 9900 0    50   ~ 0
L
Text Notes 8350 9900 0    50   ~ 0
H
Text Notes 8350 10000 0    50   ~ 0
L
Text Notes 8100 10000 0    50   ~ 0
H
Text Notes 7850 10000 0    50   ~ 0
H
Text Notes 8350 10100 0    50   ~ 0
L
Text Notes 7850 10100 0    50   ~ 0
L
Text Notes 8100 10100 0    50   ~ 0
H
Text Notes 8350 10200 0    50   ~ 0
L
Text Notes 8100 10200 0    50   ~ 0
L
Text Notes 7850 10200 0    50   ~ 0
H
Text Notes 8550 9700 0    50   ~ 0
STM 12bit DAC
Text Notes 8050 9500 0    50   ~ 0
V_B1
Text Notes 7800 9500 0    50   ~ 0
V_B0
Wire Notes Line
	7450 9500 9200 9500
Wire Notes Line
	9200 10300 7450 10300
Wire Notes Line
	7450 10300 7450 9400
Wire Notes Line
	7450 9400 9200 9400
Wire Notes Line
	9200 9400 9200 10300
Wire Notes Line
	8500 9400 8500 10300
Wire Notes Line
	8250 9400 8250 10300
Wire Notes Line
	8000 9400 8000 10300
Wire Notes Line
	7750 9400 7750 10300
Wire Notes Line
	7450 9600 9200 9600
Wire Notes Line
	7450 9700 9200 9700
Wire Notes Line
	7450 9800 9200 9800
Wire Notes Line
	7450 9900 9200 9900
Wire Notes Line
	7450 10000 9200 10000
Wire Notes Line
	7450 10100 9200 10100
Wire Notes Line
	7450 10200 9200 10200
Wire Notes Line
	6200 9300 10650 9300
Wire Notes Line
	10650 10400 6200 10400
Wire Notes Line
	6200 10400 6200 9200
Wire Notes Line
	6200 9200 10650 9200
Wire Notes Line
	10650 9200 10650 10400
Text Notes 9250 10050 0    50   ~ 0
This may be used in the future to \nindicate the presence of a 16bit \nDAC or 4 channel output DAC.\nAlso other minor PCB mods as \nrequred. Table will indicate \nversion features when they have \nbeen implemented.
Text Notes 12800 850  0    50   ~ 0
STM32F302 IO is 5V tolerent on CAN_TX and CAN_RX GPIO.\nVoltage Selector added to evauate lower cost 5V xcever ICs
$Comp
L Jumper:Jumper_3_Bridged12 JP4
U 1 1 61E9CAAF
P 12250 1000
F 0 "JP4" H 12150 900 50  0000 C CNN
F 1 "PSELECT" H 12250 1110 50  0000 C CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Bridged2Bar12_Pad1.0x1.5mm" H 12250 1000 50  0001 C CNN
F 3 "~" H 12250 1000 50  0001 C CNN
	1    12250 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	11850 900  11850 1000
Wire Wire Line
	11850 1000 12000 1000
Wire Wire Line
	12650 1000 12500 1000
Wire Wire Line
	14400 1900 13600 1900
Wire Wire Line
	12650 1800 13350 1800
Wire Wire Line
	13600 1800 13600 1500
Wire Wire Line
	13600 1500 15700 1500
Wire Wire Line
	15700 1500 15700 1900
Wire Wire Line
	15700 1900 15600 1900
Wire Wire Line
	15700 1900 16000 1900
Connection ~ 15700 1900
Text Label 15800 1900 0    50   ~ 0
CANH
Text Label 15800 2000 0    50   ~ 0
CANL
Wire Wire Line
	16000 2000 15700 2000
Wire Wire Line
	15700 2000 15700 2450
Wire Wire Line
	15700 2450 13600 2450
Wire Wire Line
	13600 2450 13600 1900
Wire Wire Line
	13150 1950 13150 1900
Wire Wire Line
	13150 1900 12650 1900
Wire Wire Line
	13350 1950 13350 1800
Wire Wire Line
	14200 1800 14300 1800
Connection ~ 14300 1800
$Comp
L power:GND #PWR071
U 1 1 622E4E7F
P 13850 1800
F 0 "#PWR071" H 13850 1550 50  0001 C CNN
F 1 "GND" H 13850 1650 50  0000 C CNN
F 2 "" H 13850 1800 50  0001 C CNN
F 3 "" H 13850 1800 50  0001 C CNN
	1    13850 1800
	0    1    1    0   
$EndComp
Wire Wire Line
	13850 1800 13900 1800
Wire Wire Line
	13600 1800 13350 1800
Connection ~ 13350 1800
Wire Wire Line
	13600 1900 13150 1900
Connection ~ 13600 1900
Connection ~ 13150 1900
Wire Notes Line
	16400 550  16400 2550
Wire Notes Line
	16400 2550 11050 2550
Wire Wire Line
	12650 900  12650 1000
$Comp
L power:+5V #PWR066
U 1 1 61EC3D69
P 12650 900
F 0 "#PWR066" H 12650 750 50  0001 C CNN
F 1 "+5V" H 12650 1040 50  0000 C CNN
F 2 "" H 12650 900 50  0001 C CNN
F 3 "" H 12650 900 50  0001 C CNN
	1    12650 900 
	1    0    0    -1  
$EndComp
NoConn ~ 9100 7300
NoConn ~ 9100 7400
NoConn ~ 9100 7500
NoConn ~ 7800 7800
$Comp
L power:GNDA #PWR01
U 1 1 607356B3
P 800 9800
F 0 "#PWR01" H 800 9550 50  0001 C CNN
F 1 "GNDA" H 800 9650 50  0000 C CNN
F 2 "" H 800 9800 50  0001 C CNN
F 3 "" H 800 9800 50  0001 C CNN
	1    800  9800
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG01
U 1 1 60737834
P 800 9700
F 0 "#FLG01" H 800 9775 50  0001 C CNN
F 1 "PWR_FLAG" H 800 9850 50  0000 C CNN
F 2 "" H 800 9700 50  0001 C CNN
F 3 "~" H 800 9700 50  0001 C CNN
	1    800  9700
	1    0    0    -1  
$EndComp
Wire Wire Line
	800  9700 800  9800
Text GLabel 11450 6150 0    50   Input ~ 0
ERROR_LED
Text GLabel 11450 5850 0    50   Input ~ 0
SPI_LED
Text GLabel 11450 5550 0    50   Input ~ 0
CAN_LED
$Comp
L power:VDDA #PWR09
U 1 1 60766F4F
P 2300 10200
F 0 "#PWR09" H 2300 10050 50  0001 C CNN
F 1 "VDDA" H 2300 10350 50  0000 C CNN
F 2 "" H 2300 10200 50  0001 C CNN
F 3 "" H 2300 10200 50  0001 C CNN
	1    2300 10200
	-1   0    0    1   
$EndComp
$Comp
L power:+BATT #PWR07
U 1 1 60774C38
P 1700 10200
F 0 "#PWR07" H 1700 10050 50  0001 C CNN
F 1 "+BATT" H 1700 10340 50  0000 C CNN
F 2 "" H 1700 10200 50  0001 C CNN
F 3 "" H 1700 10200 50  0001 C CNN
	1    1700 10200
	-1   0    0    1   
$EndComp
$Comp
L power:VBUS #PWR03
U 1 1 6077F8FE
P 1100 10200
F 0 "#PWR03" H 1100 10050 50  0001 C CNN
F 1 "VBUS" H 1100 10350 50  0000 C CNN
F 2 "" H 1100 10200 50  0001 C CNN
F 3 "" H 1100 10200 50  0001 C CNN
	1    1100 10200
	-1   0    0    1   
$EndComp
$Comp
L power:PWR_FLAG #FLG06
U 1 1 6078858E
P 2300 10050
F 0 "#FLG06" H 2300 10125 50  0001 C CNN
F 1 "PWR_FLAG" H 2300 10200 50  0000 C CNN
F 2 "" H 2300 10050 50  0001 C CNN
F 3 "~" H 2300 10050 50  0001 C CNN
	1    2300 10050
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG04
U 1 1 608091F3
P 1700 10050
F 0 "#FLG04" H 1700 10125 50  0001 C CNN
F 1 "PWR_FLAG" H 1700 10200 50  0000 C CNN
F 2 "" H 1700 10050 50  0001 C CNN
F 3 "~" H 1700 10050 50  0001 C CNN
	1    1700 10050
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG02
U 1 1 60809654
P 1100 10050
F 0 "#FLG02" H 1100 10125 50  0001 C CNN
F 1 "PWR_FLAG" H 1100 10200 50  0000 C CNN
F 2 "" H 1100 10050 50  0001 C CNN
F 3 "~" H 1100 10050 50  0001 C CNN
	1    1100 10050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1100 10050 1100 10200
Wire Wire Line
	1700 10050 1700 10200
Wire Wire Line
	2300 10050 2300 10200
Text Label 12250 1450 1    50   ~ 0
OA_PWR
Text Label 2900 10350 1    50   ~ 0
OA_PWR
$Comp
L power:PWR_FLAG #FLG08
U 1 1 60B92501
P 2900 10050
F 0 "#FLG08" H 2900 10125 50  0001 C CNN
F 1 "PWR_FLAG" H 2900 10200 50  0000 C CNN
F 2 "" H 2900 10050 50  0001 C CNN
F 3 "~" H 2900 10050 50  0001 C CNN
	1    2900 10050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 10050 2900 10350
Wire Wire Line
	2450 1100 3050 1100
$Comp
L Device:R R7
U 1 1 606A4C92
P 3050 1300
F 0 "R7" V 3130 1300 50  0000 C CNN
F 1 "120k" V 3050 1300 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2980 1300 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/2008171235_YAGEO-RT0603BRD07120KL_C705720.pdf" H 3050 1300 50  0001 C CNN
F 4 "RT0603BRD07120KL" H 3050 1300 50  0001 C CNN "MPN"
F 5 "YAGEO" H 3050 1300 50  0001 C CNN "Manufacture"
F 6 "C705720" H 3050 1300 50  0001 C CNN "SPN"
F 7 "LCSC" H 3050 1300 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_YAGEO-RT0603BRD07120KL_C705720.html" H 3050 1300 50  0001 C CNN "Supplier Link"
	1    3050 1300
	-1   0    0    1   
$EndComp
$Comp
L Device:R R9
U 1 1 606BAFF1
P 3050 2050
F 0 "R9" V 3130 2050 50  0000 C CNN
F 1 "12k" V 3050 2050 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2980 2050 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1811141450_YAGEO-RT0603BRD0712KL_C326735.pdf" H 3050 2050 50  0001 C CNN
F 4 "RT0603BRD0712KL" H 3050 2050 50  0001 C CNN "MPN"
F 5 "YAGEO" H 3050 2050 50  0001 C CNN "Manufacture"
F 6 "C326735" H 3050 2050 50  0001 C CNN "SPN"
F 7 "LCSC" H 3050 2050 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_YAGEO-RT0603BRD0712KL_C326735.html" H 3050 2050 50  0001 C CNN "Supplier Link"
	1    3050 2050
	-1   0    0    1   
$EndComp
$Comp
L Device:R R8
U 1 1 606D0302
P 3050 1700
F 0 "R8" V 3130 1700 50  0000 C CNN
F 1 "20k" V 3050 1700 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2980 1700 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1811081710_UNI-ROYAL-Uniroyal-Elec-0603WAJ0203T5E_C25586.pdf" H 3050 1700 50  0001 C CNN
F 4 "0603WAJ0203T5E" H 3050 1700 50  0001 C CNN "MPN"
F 5 " UNI-ROYAL(Uniroyal Elec)" H 3050 1700 50  0001 C CNN "Manufacture"
F 6 "C25586" H 3050 1700 50  0001 C CNN "SPN"
F 7 "LCSC" H 3050 1700 50  0001 C CNN "Supplier"
F 8 "https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_UNI-ROYAL-Uniroyal-Elec-0603WAJ0203T5E_C25586.html" H 3050 1700 50  0001 C CNN "Supplier Link"
	1    3050 1700
	-1   0    0    1   
$EndComp
$Comp
L Device:D_Zener D2
U 1 1 606EBD0B
P 2750 1850
F 0 "D2" H 2750 1950 50  0000 C CNN
F 1 "4.7V" H 2750 1750 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 2750 1850 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1811051603_MDD-Microdiode-Electronics-BZT52C4V7_C173408.pdf" H 2750 1850 50  0001 C CNN
F 4 "MDD(Microdiode Electronics)" H 2750 1850 50  0001 C CNN "Manufacture"
F 5 "BZT52C4V7" H 2750 1850 50  0001 C CNN "MPN"
F 6 "LCSC" H 2750 1850 50  0001 C CNN "Supplier"
F 7 "C173408" H 2750 1850 50  0001 C CNN "SPN"
F 8 "https://lcsc.com/product-detail/Zener-Diodes_MDD-Microdiode-Electronics-BZT52C4V7_C173408.html" H 2750 1850 50  0001 C CNN "Supplier Link"
	1    2750 1850
	0    1    1    0   
$EndComp
Wire Wire Line
	2450 1500 2450 1550
Wire Wire Line
	3150 1500 3050 1500
Wire Wire Line
	3050 1500 3050 1450
Wire Wire Line
	3050 1150 3050 1100
Connection ~ 3050 1100
Wire Wire Line
	3050 1100 3150 1100
Wire Wire Line
	3050 1550 3050 1500
Connection ~ 3050 1500
Wire Wire Line
	3050 1900 3050 1850
Wire Wire Line
	2750 1700 2750 1500
Wire Wire Line
	2750 1500 3050 1500
$Comp
L power:GND #PWR013
U 1 1 609C98EF
P 3050 2300
F 0 "#PWR013" H 3050 2050 50  0001 C CNN
F 1 "GND" H 3050 2150 50  0000 C CNN
F 2 "" H 3050 2300 50  0001 C CNN
F 3 "" H 3050 2300 50  0001 C CNN
	1    3050 2300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR015
U 1 1 609C9D4D
P 3500 1850
F 0 "#PWR015" H 3500 1600 50  0001 C CNN
F 1 "GND" H 3500 1700 50  0000 C CNN
F 2 "" H 3500 1850 50  0001 C CNN
F 3 "" H 3500 1850 50  0001 C CNN
	1    3500 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 1850 3500 1750
Wire Wire Line
	3050 2300 3050 2250
Wire Wire Line
	3050 2250 2750 2250
Wire Wire Line
	2750 2250 2750 2000
Connection ~ 3050 2250
Wire Wire Line
	3050 2250 3050 2200
Connection ~ 1900 1100
Text Notes 4300 2550 0    50   ~ 0
Test TPS560430 as drop in replacment for BL9342
Text Notes 3200 2250 1    50   ~ 0
EN Pin Vmax = 5V
$EndSCHEMATC
