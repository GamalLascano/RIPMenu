EESchema Schematic File Version 4
LIBS:riego-cache
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
L basico-cache:Conn_Poncho2P_2x_20x2 XA1
U 2 1 5D9B4CDD
P 1750 2100
F 0 "XA1" H 2100 2647 60  0000 C CNN
F 1 "Conn_Poncho2P_2x_20x2" H 2100 2541 60  0000 C CNN
F 2 "riego:poncho_grande" H 2050 2800 60  0000 C CNN
F 3 "" H 1750 2100 60  0000 C CNN
	2    1750 2100
	1    0    0    -1  
$EndComp
$Comp
L Lcd_user:HD44780_1602A U3
U 1 1 5D9E8A2C
P 3050 6650
F 0 "U3" H 4580 6553 50  0000 L CNN
F 1 "HD44780_1602A" H 4580 6462 50  0000 L CNN
F 2 "riego:rLCD16x2" H 4250 5850 50  0001 C CNN
F 3 "" V 2700 6150 50  0001 C CNN
	1    3050 6650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 5050 3400 6250
Wire Wire Line
	3500 4950 3500 6250
Wire Wire Line
	3600 4850 3600 6250
Wire Wire Line
	3050 3200 2700 3200
Wire Wire Line
	3050 3100 2700 3100
Wire Wire Line
	3050 3000 2700 3000
Wire Wire Line
	3050 2900 2700 2900
Wire Wire Line
	3050 2800 2700 2800
Text Label 3050 2800 0    50   ~ 0
lcd_d7
Text Label 3050 3000 0    50   ~ 0
lcd_d6
Text Label 3050 3100 0    50   ~ 0
lcd_d5
Text Label 3050 3200 0    50   ~ 0
lcd_d4
Wire Wire Line
	1100 2900 1500 2900
Text Label 1100 2900 2    50   ~ 0
lcd_e
Text Label 3050 2900 0    50   ~ 0
lcd_rs
$Comp
L Motor_user:MiniBombaDC M1
U 1 1 5DA18A74
P 7500 3250
F 0 "M1" H 7638 3438 50  0000 L CNN
F 1 "MiniBombaDC" H 7638 3347 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 7500 3260 50  0001 C CNN
F 3 "~" H 7500 3260 50  0001 C CNN
	1    7500 3250
	0    -1   -1   0   
$EndComp
Text Label 3500 2400 2    50   ~ 0
Humedad_A0
Text Label 8550 1100 0    50   ~ 0
Humedad_A0
Text Notes 7350 7500 0    50   ~ 0
Sistema de Riego Automatico
Text Notes 8150 7650 0    50   ~ 0
07-Oct-19
Text Notes 10550 7650 0    50   ~ 0
1.0
$Comp
L Device:R R20
U 1 1 5DA55211
P 3900 6000
F 0 "R20" H 3970 6046 50  0000 L CNN
F 1 "39Ω" H 3970 5955 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 3830 6000 50  0001 C CNN
F 3 "~" H 3900 6000 50  0001 C CNN
	1    3900 6000
	1    0    0    -1  
$EndComp
Text Label 1350 5250 0    50   ~ 0
lcd_rs
Text Label 1350 4750 0    50   ~ 0
lcd_d7
Text Label 1350 4850 0    50   ~ 0
lcd_d6
Text Label 1350 4950 0    50   ~ 0
lcd_d5
Text Label 1350 5050 0    50   ~ 0
lcd_d4
Text Label 1350 5150 0    50   ~ 0
lcd_e
Wire Wire Line
	1350 5150 2900 5150
Wire Wire Line
	1350 5050 3400 5050
Wire Wire Line
	1350 4950 3500 4950
Wire Wire Line
	1350 4850 3600 4850
Wire Wire Line
	1350 4750 3700 4750
Wire Wire Line
	1350 5700 2250 5700
Wire Wire Line
	2500 6250 2500 5800
Wire Wire Line
	2500 5800 2250 5800
Wire Wire Line
	2250 5800 2250 5700
Connection ~ 2250 5700
Wire Wire Line
	2700 6250 2700 5800
Wire Wire Line
	2700 5800 2800 5800
Wire Wire Line
	2800 5800 2800 5250
Wire Wire Line
	1350 5250 2800 5250
Wire Notes Line
	5500 4350 5500 7150
Text Notes 1050 4500 0    50   ~ 0
LCD
Wire Notes Line
	850  4350 850  7150
Text Notes 1050 1050 0    50   ~ 0
PONCHO_BASICO\n
Wire Notes Line
	850  900  850  4000
Wire Wire Line
	7850 3200 7650 3200
Wire Wire Line
	7850 3350 7650 3350
Wire Wire Line
	7850 3200 7850 2950
Wire Wire Line
	7850 2950 8050 2950
Wire Wire Line
	8050 3100 8050 2950
Wire Wire Line
	8050 2950 9800 2950
Connection ~ 8050 2950
Text Label 9900 4425 0    50   ~ 0
riego
$Comp
L Device:R R1
U 1 1 5DA80597
P 9250 4425
F 0 "R1" V 9043 4425 50  0000 C CNN
F 1 "1kΩ" V 9134 4425 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 9180 4425 50  0001 C CNN
F 3 "~" H 9250 4425 50  0001 C CNN
	1    9250 4425
	0    1    1    0   
$EndComp
Wire Wire Line
	9100 4425 8550 4425
Text Notes 6600 2650 0    50   ~ 0
BOMBA\n
Wire Notes Line
	11000 550  6500 550 
Text Notes 6600 750  0    50   ~ 0
SENSOR
$Comp
L Sensor_user:YL69 U2
U 1 1 5D9CE60B
P 7150 1700
F 0 "U2" H 7380 2032 50  0000 L CNN
F 1 "YL69" H 7380 1941 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 6550 3050 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/hdc1080.pdf" H 6200 1750 50  0001 C CNN
	1    7150 1700
	0    1    1    0   
$EndComp
Wire Notes Line
	6500 2400 11000 2400
Wire Notes Line
	6500 550  6500 2400
Wire Notes Line
	11000 2400 11000 550 
Wire Notes Line
	6500 4750 6500 2500
Wire Notes Line
	6500 2500 11000 2500
Wire Notes Line
	11000 2500 11000 4750
Wire Notes Line
	6500 4750 11000 4750
Wire Notes Line
	11000 4900 11000 6450
Wire Notes Line
	11000 6450 6500 6450
Wire Notes Line
	6500 6450 6500 4900
Wire Notes Line
	6500 4900 11000 4900
Text Notes 6600 5050 0    50   ~ 0
ALIMENTACION\n
$Comp
L basico-cache:+5V #PWR0101
U 1 1 5DAF8C1F
P 7750 5450
F 0 "#PWR0101" H 7750 5300 50  0001 C CNN
F 1 "+5V" H 7765 5623 50  0000 C CNN
F 2 "" H 7750 5450 50  0000 C CNN
F 3 "" H 7750 5450 50  0000 C CNN
	1    7750 5450
	1    0    0    -1  
$EndComp
$Comp
L basico-cache:GND #PWR0102
U 1 1 5DAF9131
P 7750 6150
F 0 "#PWR0102" H 7750 5900 50  0001 C CNN
F 1 "GND" H 7755 5977 50  0000 C CNN
F 2 "" H 7750 6150 50  0000 C CNN
F 3 "" H 7750 6150 50  0000 C CNN
	1    7750 6150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7750 6100 7750 6150
$Comp
L Device:R R10
U 1 1 5DB0FF17
P 8750 1650
F 0 "R10" V 8543 1650 50  0000 C CNN
F 1 "1kΩ" V 8634 1650 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 8680 1650 50  0001 C CNN
F 3 "~" H 8750 1650 50  0001 C CNN
	1    8750 1650
	0    1    1    0   
$EndComp
Wire Wire Line
	8900 1650 9650 1650
Text Label 3100 3700 0    50   ~ 0
riego
Wire Notes Line
	850  4350 5500 4350
Wire Notes Line
	850  4000 5850 4000
Wire Notes Line
	850  900  5850 900 
Wire Notes Line
	850  7150 5500 7150
Wire Wire Line
	3100 3700 2700 3700
Wire Wire Line
	3500 2400 3850 2400
$Comp
L power_user:AlimentacionExterna U5
U 1 1 5DB7DF15
P 10200 5225
F 0 "U5" V 10000 5075 50  0000 R CNN
F 1 "AlimentacionExterna" V 10075 5725 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 9500 5625 50  0001 L CIN
F 3 "https://www.analog.com/media/en/technical-documentation/data-sheets/3092fc.pdf" V 10200 5225 50  0001 C CIN
	1    10200 5225
	0    1    1    0   
$EndComp
Wire Wire Line
	7750 5825 7750 6100
Wire Wire Line
	7650 5700 7750 5700
Wire Wire Line
	7650 5825 7750 5825
Wire Wire Line
	10075 5450 10075 6100
$Comp
L basico-cache:GND #PWR0103
U 1 1 5DC00F51
P 9850 3650
F 0 "#PWR0103" H 9850 3400 50  0001 C CNN
F 1 "GND" V 9850 3450 50  0000 C CNN
F 2 "" H 9850 3650 50  0000 C CNN
F 3 "" H 9850 3650 50  0000 C CNN
	1    9850 3650
	0    -1   -1   0   
$EndComp
$Comp
L basico-cache:+5V #PWR0104
U 1 1 5DC034AC
P 9800 2950
F 0 "#PWR0104" H 9800 2800 50  0001 C CNN
F 1 "+5V" V 9815 3123 50  0000 C CNN
F 2 "" H 9800 2950 50  0000 C CNN
F 3 "" H 9800 2950 50  0000 C CNN
	1    9800 2950
	0    1    1    0   
$EndComp
$Comp
L basico-cache:GND #PWR0105
U 1 1 5DC11A58
P 9650 1750
F 0 "#PWR0105" H 9650 1500 50  0001 C CNN
F 1 "GND" V 9650 1550 50  0000 C CNN
F 2 "" H 9650 1750 50  0000 C CNN
F 3 "" H 9650 1750 50  0000 C CNN
	1    9650 1750
	0    -1   -1   0   
$EndComp
$Comp
L basico-cache:GND #PWR0106
U 1 1 5DC15345
P 1325 6050
F 0 "#PWR0106" H 1325 5800 50  0001 C CNN
F 1 "GND" H 1330 5877 50  0000 C CNN
F 2 "" H 1325 6050 50  0000 C CNN
F 3 "" H 1325 6050 50  0000 C CNN
	1    1325 6050
	0    1    1    0   
$EndComp
$Comp
L basico-cache:+5V #PWR0107
U 1 1 5DC1FCCC
P 1350 5700
F 0 "#PWR0107" H 1350 5550 50  0001 C CNN
F 1 "+5V" H 1365 5873 50  0000 C CNN
F 2 "" H 1350 5700 50  0000 C CNN
F 3 "" H 1350 5700 50  0000 C CNN
	1    1350 5700
	0    -1   -1   0   
$EndComp
$Comp
L basico-cache:GND #PWR0108
U 1 1 5DC2443B
P 5400 3700
F 0 "#PWR0108" H 5400 3450 50  0001 C CNN
F 1 "GND" V 5400 3500 50  0000 C CNN
F 2 "" H 5400 3700 50  0000 C CNN
F 3 "" H 5400 3700 50  0000 C CNN
	1    5400 3700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5050 3700 5400 3700
Text Notes 7300 7225 0    50   ~ 0
1
Text Notes 7375 7250 0    50   ~ 0
1
Wire Wire Line
	7900 1750 9650 1750
Wire Wire Line
	7900 1650 8175 1650
Wire Wire Line
	8550 1100 8175 1100
Wire Wire Line
	8175 1100 8175 1650
Connection ~ 8175 1650
Wire Wire Line
	8175 1650 8600 1650
$Comp
L basico-cache:+3.3V #PWR0110
U 1 1 5DC4660B
P 9650 1650
F 0 "#PWR0110" H 9650 1500 50  0001 C CNN
F 1 "+3.3V" V 9600 1775 50  0000 L CNN
F 2 "" H 9650 1650 50  0000 C CNN
F 3 "" H 9650 1650 50  0000 C CNN
	1    9650 1650
	0    1    1    0   
$EndComp
Wire Notes Line
	5850 900  5850 4000
Wire Wire Line
	3625 1800 3850 1800
$Comp
L basico-cache:+3.3V #PWR0111
U 1 1 5DC4F1A4
P 3625 1800
F 0 "#PWR0111" H 3625 1650 50  0001 C CNN
F 1 "+3.3V" V 3575 1925 50  0000 L CNN
F 2 "" H 3625 1800 50  0000 C CNN
F 3 "" H 3625 1800 50  0000 C CNN
	1    3625 1800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3700 4750 3700 6250
Wire Wire Line
	2250 5300 3900 5300
Wire Wire Line
	3100 5700 3100 6050
Wire Wire Line
	3100 5700 3800 5700
Wire Wire Line
	3800 5700 3800 6250
Wire Wire Line
	9400 4425 9900 4425
$Comp
L Transistor_BJT:TIP41 Q1
U 1 1 5DC61A5B
P 8550 3750
F 0 "Q1" V 8878 3750 50  0000 C CNN
F 1 "TIP31" V 8787 3750 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 8800 3675 50  0001 L CIN
F 3 "" H 8550 3750 50  0001 L CNN
	1    8550 3750
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7850 3350 7850 3650
Wire Wire Line
	7850 3650 8050 3650
Wire Wire Line
	8050 3650 8050 3400
Wire Wire Line
	8050 3650 8350 3650
Connection ~ 8050 3650
$Comp
L Diode:1N4007 D1
U 1 1 5DC8CEAC
P 8050 3250
F 0 "D1" V 8004 3329 50  0000 L CNN
F 1 "1N4007" V 8095 3329 50  0000 L CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 8050 3075 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 8050 3250 50  0001 C CNN
	1    8050 3250
	0    1    1    0   
$EndComp
Wire Wire Line
	2800 6250 2800 6050
Connection ~ 2800 6050
Wire Wire Line
	2800 6050 3100 6050
Wire Wire Line
	2400 6250 2400 6050
Wire Wire Line
	2400 6050 2800 6050
Wire Wire Line
	2900 5150 2900 6250
Wire Wire Line
	3900 6150 3900 6250
Wire Wire Line
	8550 3950 8550 4425
NoConn ~ 3000 6250
NoConn ~ 3100 6250
NoConn ~ 3200 6250
NoConn ~ 3300 6250
NoConn ~ 1500 3200
NoConn ~ 2700 3600
NoConn ~ 2700 3500
NoConn ~ 2700 3400
NoConn ~ 2700 3300
NoConn ~ 1500 3300
NoConn ~ 1500 3400
NoConn ~ 1500 3500
NoConn ~ 1500 3600
NoConn ~ 1500 3700
NoConn ~ 1500 2800
NoConn ~ 1500 2700
NoConn ~ 1500 2600
NoConn ~ 1500 2500
NoConn ~ 1500 2400
NoConn ~ 1500 2300
NoConn ~ 1500 2200
NoConn ~ 1500 2100
NoConn ~ 1500 2000
NoConn ~ 1500 1900
NoConn ~ 1500 1800
NoConn ~ 2700 1800
NoConn ~ 2700 1900
NoConn ~ 2700 2000
NoConn ~ 2700 2100
NoConn ~ 2700 2200
NoConn ~ 2700 2300
NoConn ~ 2700 2400
NoConn ~ 2700 2500
NoConn ~ 2700 2600
NoConn ~ 2700 2700
NoConn ~ 3850 3700
NoConn ~ 3850 3600
NoConn ~ 3850 3500
NoConn ~ 3850 3400
NoConn ~ 3850 3300
NoConn ~ 3850 3200
NoConn ~ 3850 3100
NoConn ~ 3850 3000
NoConn ~ 3850 2900
NoConn ~ 3850 2800
NoConn ~ 3850 2700
NoConn ~ 3850 2600
NoConn ~ 3850 2500
NoConn ~ 5050 3600
NoConn ~ 5050 3500
NoConn ~ 5050 3400
NoConn ~ 5050 3300
NoConn ~ 5050 3200
NoConn ~ 5050 3100
NoConn ~ 5050 3000
NoConn ~ 5050 2900
NoConn ~ 5050 2800
NoConn ~ 5050 2700
NoConn ~ 5050 2600
NoConn ~ 5050 2500
NoConn ~ 5050 2400
NoConn ~ 5050 2300
NoConn ~ 5050 2200
NoConn ~ 5050 2000
NoConn ~ 5050 2100
NoConn ~ 3850 1900
NoConn ~ 3850 2000
NoConn ~ 3850 2100
NoConn ~ 3850 2200
NoConn ~ 3850 2300
NoConn ~ 1500 3000
NoConn ~ 1500 3100
Wire Wire Line
	2400 6050 1325 6050
Connection ~ 2400 6050
Wire Wire Line
	9850 3650 8750 3650
Wire Wire Line
	3100 5700 2750 5700
Wire Wire Line
	2750 5700 2750 5750
Wire Wire Line
	2750 5750 2700 5750
Connection ~ 3100 5700
Wire Wire Line
	2250 5700 2425 5700
Wire Wire Line
	2425 5700 2425 5750
Wire Wire Line
	2425 5750 2500 5750
Wire Wire Line
	2600 5750 2600 6250
$Comp
L riego:rRotary_Encoder SW1
U 1 1 5DCA6C1C
P 2600 5450
F 0 "SW1" V 2600 5975 50  0000 R CNN
F 1 "rRotary_Encoder" V 2500 6425 50  0000 R CNN
F 2 "riego:rPotentiometer" H 2450 5610 50  0001 C CNN
F 3 "~" H 2600 5710 50  0001 C CNN
	1    2600 5450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2250 5300 2250 5700
Wire Wire Line
	3900 5300 3900 5850
Connection ~ 7750 6100
$Comp
L power_user:AlimentacionEDUCIAA U4
U 1 1 5DB7D541
P 7425 5700
F 0 "U4" H 6925 5950 50  0000 C CNN
F 1 "AlimentacionEDUCIAA" H 7275 5875 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 6725 6100 50  0001 L CIN
F 3 "https://www.analog.com/media/en/technical-documentation/data-sheets/3092fc.pdf" V 7425 5700 50  0001 C CIN
	1    7425 5700
	1    0    0    -1  
$EndComp
Connection ~ 7750 5500
Wire Wire Line
	7750 5700 7750 5500
Wire Wire Line
	7750 5500 7750 5450
Wire Wire Line
	9200 6100 9750 6100
Connection ~ 9200 6100
Wire Wire Line
	9200 5500 9750 5500
Connection ~ 9200 5500
Wire Wire Line
	9200 5950 9200 6100
Wire Wire Line
	9750 6100 9750 5950
Wire Wire Line
	9750 5500 9750 5650
Wire Wire Line
	9200 5650 9200 5500
$Comp
L Device:C C1
U 1 1 5DA57C8D
P 9200 5800
F 0 "C1" H 9315 5846 50  0000 L CNN
F 1 "100nf" H 9315 5755 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 9238 5650 50  0001 C CNN
F 3 "~" H 9200 5800 50  0001 C CNN
	1    9200 5800
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 5DAF340F
P 9750 5800
F 0 "C2" H 9865 5846 50  0000 L CNN
F 1 "10μf" H 9865 5755 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D4.0mm_P2.00mm" H 9788 5650 50  0001 C CNN
F 3 "~" H 9750 5800 50  0001 C CNN
	1    9750 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7750 6100 9200 6100
Wire Wire Line
	7750 5500 9200 5500
Wire Wire Line
	9750 5500 10200 5500
Wire Wire Line
	10200 5450 10200 5500
Connection ~ 9750 5500
Wire Wire Line
	9750 6100 10075 6100
Connection ~ 9750 6100
NoConn ~ 5050 1800
$Comp
L basico-cache:Conn_Poncho2P_2x_20x2 XA1
U 1 1 5D9B3031
P 4100 2100
F 0 "XA1" H 4450 2647 60  0000 C CNN
F 1 "Conn_Poncho2P_2x_20x2" H 4450 2541 60  0000 C CNN
F 2 "riego:poncho_grande" H 4250 2850 60  0000 C CNN
F 3 "" H 4100 2100 60  0000 C CNN
	1    4100 2100
	1    0    0    -1  
$EndComp
NoConn ~ 5050 1900
$EndSCHEMATC
