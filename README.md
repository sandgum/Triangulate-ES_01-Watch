# Triangulate ES_01 E-ink Watch
---
An ultra-thin ESP32S3-based smartwatch (at just 5mm thick at its thickest point) which uses an E-ink display and two OLEDs to display information while consuming very little power. The main E-ink panel is touch-enabled, with the two additional OLED panels above and below it displaying auxiliary information, such as notifications, background activities etc. 
The watch has built-in heart rate and spO2 sensing via an Analog Devices MAX30102, high-precision smart movement sensing via a Bosch BH260AP IMU and a Bosch BMP585 barometric pressure sensor.

<img width="3840" height="2160" alt="render1" src="https://github.com/user-attachments/assets/fb7dc05c-c978-4ac6-91fd-225cae70b5f9" />
<img width="3840" height="2160" alt="render10" src="https://github.com/user-attachments/assets/e5543c91-088c-427f-89b5-0b45ddf50308" />

*ACKNOWLEDGMENT: Most of the materials and the human hand model you see in the renders are not my own work, but is Royalty-free or CC0 licensed work legitimately downloaded from BlenderKit using their free plan*

---

To top it all off, the ES_01 is completely workout-friendly, with rubberised sides and no pesky side buttons that get pressed mid-pushup (Every physical input is at the top of the watch)!
The watch features a sleek design, with each component being laid out single file and in its own separate segment of the watch. These segments can all bend around the watch, preserving a uniform thickness all around, which also adds the benefit of being aesthetically pleasing.
The main microcontroller running the watch is an Espressif ESP32-S3 running with Bluetooth capabilities, which also allow for it to sync with a smartphone to relay notifications, workout data etc through firmware based on ESP-IDF. (Coming soon!)

---
## PCB:

-  4 layers
-  Flex PCB
-  Single-sided component placement
-  0.2mm board thickness
-  Added 0.1mm FR4 stiffeners
-  All resistors and capacitors are 0402 size

*Schematics:*
<img width="2993" height="2115" alt="E-ink watch sensors schematic" src="https://github.com/user-attachments/assets/d2e8a765-7ff3-49c3-917e-8c7fe9fb490c" />
<img width="2993" height="2115" alt="E-ink watch main schematic" src="https://github.com/user-attachments/assets/ff548654-77bf-4317-9524-009f5500d615" />
<img width="2993" height="2115" alt="E-ink watch drivers schematic" src="https://github.com/user-attachments/assets/70d8513a-2852-4016-9230-cde40bc6e5e5" />
<img width="2993" height="2115" alt="E-ink watch displays schematic" src="https://github.com/user-attachments/assets/374afe60-b3ea-41e2-b6da-ca43353d284f" />

*PCB Layout and render:*
<img width="1454" height="585" alt="Screenshot 2025-12-14 at 1 22 46 pm" src="https://github.com/user-attachments/assets/16a535e6-246d-4e0d-91d4-3cafa5ae3504" />
<img width="2560" height="1440" alt="render4" src="https://github.com/user-attachments/assets/a82eb673-f5c0-45c7-9ac9-8d790fc45b2b" />

---

## Enclosure:

- Main cases and top plates of easch segment 3D printed using an SLA/MSLA printer
- Main cases printed in Black resin from JLC3DP (can substitute with any rigid resin)
- Top plates printed in LEDO 6060 resin from JLC3DP (can substitute with any rigid resin)
- Bottom plates for OLED segments are CNC machined from 6061 Aluminium by JLCCNC (can substitute with any rigid material or also with SLA/MSLA printed resin)
- Bottom plate for main E-ink segment 3D printed using an SLM printer in 316L stainless steel (can substitute with other rigid metal with high thermal conductivity)

---

## Assembly instructions:

1. Use the solder stencil to squeegee solder paste onto main PCB
2. Place each component onto its respective pads on the main PCB
3. Use a hotplate or a reflow oven to reflow the solder paste underneath the components
4. Hand-solder a thin insulated wire (enamel insulated or rubber insulated) connecting the pads "BATT1_WIRE" together on the PCB
5. Create a solder bridge connecting the pads "GND_TO_GNDIO" and "GNDIO_TO_GND"
6. Create a solder bridge connecting the pads "GND_TO_GNDPWR" and "GNDPWR_TO_GND"
7. Assemble the two "end battery" segments by threading battery wires through them, placing the battery in and attaching the top plates to their respective main cases with superglue
8. Assemble the other battery segment and the haptic module segment in the same way, but thread the "end battery" wires through the dedicated channels in these segments, you should have two sets of two segments with four wires coming out of each set of segments
9. Take the main cases of the OLED modules and superglue the OLED displays into the top of each, making sure the flex cables poke through their dedicated holes
10. Do the same with the E-ink segment and the E-ink display
11. Attach each remaining top plate to its respective main case using superglue
12. Place and superglue the main Flex PCB into the bottom of the E-ink segment and the two OLED segments. The back of the PCB should face the displays
13. Thread the wires from the two sets of segments from step 8 through the holes in the side of the OLED modules and hand-solder the wires onto their respective pads
14. Plug in the flex cables from each display into thir respective FPC connectors on the main PCB
15. Superglue the bottom panels for the OLED segments onto their respective main cases
16. Apply thermal paste on the ESP32-S3 chip on the main PCB
17. Superglue the bottom panel to the main case of the E-ink segment
18. Superglue the side TPU pieces to the sides of all the segments
19. Plug in a patch antenna into the exposed U.FL port on the back of the watch, guide the cable through its designated groove, and stick the patch antenna somewhere on the watch

---
## Bill of materials:

*Electronic Components: (Order quantities account for minimum order quantity of parts from the chosen retailer)*

| Manufacturer Part Number | Mfr.                        | Order Qty. | Unit Price(USD) | Ext.Price(USD) | Package                               | Description                                                                                                                | Product Link                                       |
|--------------------------|-----------------------------|------------|-----------------|----------------|---------------------------------------|----------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------|
| CC0402JRNPO9BN110        | YAGEO                       | 100        | 0.0012          | 0.12           | 0402                                   | 11pF ±5% 50V Ceramic Capacitor NP0 0402                                                                                    | https://www.lcsc.com/product-detail/C527000.html   |
| GRM155R61E475ME15D       | muRata                      | 20         | 0.0377          | 0.75           | 0402                                   | 4.7uF ±20% 25V Ceramic Capacitor X5R 0402                                                                                  | https://www.lcsc.com/product-detail/C2858031.html  |
| ESP32-S3                 | ESPRESSIF                   | 1          | 2.7791          | 2.78           | QFN-56-EP(7x7)                         | 150Mbps 2.4GHz 2.412GHz~2.484GHz QFN-56-EP(7x7) RF Transceiver ICs RoHS                                                    | https://www.lcsc.com/product-detail/C2913192.html  |
| 2328702-6                | TE Connectivity             | 5          | 0.1654          | 0.83           | SMD,P=0.5mm,Surface Mount,Right Angle  | FFC/FPC Connector 6 Position 0.5mm Pitch Double-Sided Contacts, Top and Bottom Entry Surface Mount, Right Angle -40℃~+85℃  | https://www.lcsc.com/product-detail/C3151647.html  |
| FFC2B28-24-G             | Global Connector Technology | 1          | 0.5754          | 0.58           | SMD,P=0.5mm,Surface Mount,Right Angle  | FFC/FPC Connector 24 Position 0.5mm Pitch Double-Sided Contacts, Top and Bottom Entry Surface Mount, Right Angle -25℃~+85℃ | https://www.lcsc.com/product-detail/C3151659.html  |
| BHI260AP                 | Bosch                       | 1          | 8.7882          | 8.79           | LGA-44                                 | LGA-44 IMUs (Inertial Measurement Units) RoHS                                                                              | https://www.lcsc.com/product-detail/C3288651.html  |
| SI1308EDL-T1-GE3         | VISHAY                      | 5          | 0.1324          | 0.66           | SOT-323                                | N-Channel 30V 1.5A 0.4W Surface Mount SOT-323                                                                              | https://www.lcsc.com/product-detail/C469327.html   |
| XC6206P302MR             | HXY MOSFET                  | 50         | 0.0154          | 0.77           | SOT-23                                 | Linear Voltage Regulator IC Positive Fixed 1 Output 300mA SOT-23                                                           | https://www.lcsc.com/product-detail/C5148691.html  |
| MBR0530                  | Huixin                      | 20         | 0.0205          | 0.41           | SOD-123                                | 5.5A 30V 500mV@500mA 500mA SOD-123 Single Diodes RoHS                                                                     | https://www.lcsc.com/product-detail/C49435625.html |
| 0402WGF1004TCE           | UNI-ROYAL                   | 100        | 0.0006          | 0.06           | 0402                                   | 1MΩ ±1% 62.5mW 0402 Thick Film Resistor                                                                                    | https://www.lcsc.com/product-detail/C26083.html    |
| CL05A105KA5NQNC          | Samsung Electro-Mechanics   | 100        | 0.0030          | 0.30           | 0402                                   | 1uF ±10% 25V Ceramic Capacitor X5R 0402                                                                                    | https://www.lcsc.com/product-detail/C52923.html    |
| XL2EL89CPI-111YLC-40M    | YXC Crystal Oscillators     | 10         | 0.0578          | 0.58           | SMD3225-4P                             | Crystal 40MHz ±10ppm 15pF SMD3225-4P                                                                                       | https://www.lcsc.com/product-detail/C5444549.html  |
| TS-1088-AR02016          | XUNPU                       | 10         | 0.0421          | 0.42           | SMD,4x3mm                              | Tactile Switch SPST 160gf 2mm SMD (SMT) Tab 4mm x 3mm Surface Mount                                                        | https://www.lcsc.com/product-detail/C720477.html   |
| BSS138                   | R+O                         | 50         | 0.0170          | 0.85           | SOT-23                                 | N-Channel 50V 340mA 350mW Surface Mount SOT-23                                                                             | https://www.lcsc.com/product-detail/C7420339.html  |
| TCR2EF33,LM(CT           | TOSHIBA                     | 5          | 0.0829          | 0.41           | TSOT-25                                | Positive Fixed 3.3V TSOT-25 Voltage Regulators - Linear, Low Drop Out (LDO) Regulators RoHS                                | https://www.lcsc.com/product-detail/C843273.html   |
| LQG15HS3N3S02D           | muRata                      | 100        | 0.0076          | 0.76           | 0402                                   | 800mA 3.3nH 125mΩ 0402 Fixed Inductors RoHS                                                                                | https://www.lcsc.com/product-detail/C86064.html    |
| MRA4003T3G               | onsemi                      | 10         | 0.0873          | 0.87           | SMA(DO-214AC)                          | Diode 300V 1A Surface Mount SMA(DO-214AC)                                                                                  | https://www.lcsc.com/product-detail/C94410.html    |
| DRV2605LDGSR             | TI                          | 1          | 1.2502          | 1.3            | VSSOP-10-0.5mm                         | 2V~5.2V I2C VSSOP-10-0.5mm Motor Drivers, Controllers RoHS                                                                 | https://www.lcsc.com/product-detail/C527464.html   |
| LQG15HS2N0S02D           | muRata                      | 100        | 0.0081          | 0.81           | 0402                                   | 900mA 2nH 90mΩ 0402 Fixed Inductors RoHS                                                                                   | https://www.lcsc.com/product-detail/C18216.html    |
| 0402WGF5603TCE           | UNI-ROYAL                   | 100        | 0.0005          | 0.05           | 0402                                   | 560kΩ ±1% 62.5mW 0402 Thick Film Resistor                                                                                  | https://www.lcsc.com/product-detail/C132339.html   |
| CL05B103KB5NNNC          | Samsung Electro-Mechanics   | 100        | 0.0014          | 0.14           | 0402                                   | 10nF ±10% 50V Ceramic Capacitor X7R 0402                                                                                   | https://www.lcsc.com/product-detail/C15195.html    |
| 0402B102K500NT           | FH                          | 100        | 0.0011          | 0.11           | 0402                                   | 1nF ±10% 50V Ceramic Capacitor X7R 0402                                                                                    | https://www.lcsc.com/product-detail/C1523.html     |
| CL05B104KO5NNNC          | Samsung Electro-Mechanics   | 100        | 0.0012          | 0.12           | 0402                                   | 100nF ±10% 16V Ceramic Capacitor X7R 0402                                                                                  | https://www.lcsc.com/product-detail/C1525.html     |
| 0402CG1R0C500NT          | FH                          | 100        | 0.0012          | 0.12           | 0402                                   | 1pF 50V Ceramic Capacitor C0G 0402                                                                                         | https://www.lcsc.com/product-detail/C1550.html     |
| CL05A106MQ5NUNC          | Samsung Electro-Mechanics   | 100        | 0.0044          | 0.44           | 0402                                   | 10uF ±20% 6.3V Ceramic Capacitor X5R 0402                                                                                  | https://www.lcsc.com/product-detail/C15525.html    |
| CL05B224KO5NNNC          | Samsung Electro-Mechanics   | 100        | 0.0044          | 0.44           | 0402                                   | 220nF ±10% 16V Ceramic Capacitor X7R 0402                                                                                  | https://www.lcsc.com/product-detail/C16772.html    |
| BMP585                   | Bosch                       | 1          | 2.2083          | 2.21           | LGA-9(3.3x3.3)                         | 30Kpa~1.25bar LGA-9(3.3x3.3) Pressure Sensors, Transducers RoHS                                                            | https://www.lcsc.com/product-detail/C18184976.html |
| 0402WGF1001TCE           | UNI-ROYAL                   | 100        | 0.0006          | 0.06           | 0402                                   | 1kΩ ±1% 62.5mW 0402 Thick Film Resistor                                                                                    | https://www.lcsc.com/product-detail/C11702.html    |
| LD39200PU33R             | ST                          | 1          | 1.2693          | 1.27           | DFN-6(3x3)                             | Positive Fixed 3.3V DFN-6(3x3) Voltage Regulators - Linear, Low Drop Out (LDO) Regulators RoHS                             | https://www.lcsc.com/product-detail/C222192.html   |
| CL05A475MP5NRNC          | Samsung Electro-Mechanics   | 50         | 0.0048          | 0.24           | 0402                                   | 4.7uF ±20% 10V Ceramic Capacitor X5R 0402                                                                                  | https://www.lcsc.com/product-detail/C23733.html    |
| 0402WGF220JTCE           | UNI-ROYAL                   | 100        | 0.0007          | 0.07           | 0402                                   | 22Ω ±1% 62.5mW 0402 Thick Film Resistor                                                                                    | https://www.lcsc.com/product-detail/C25092.html    |
| 0402WGF220KTCE           | UNI-ROYAL                   | 100        | 0.0009          | 0.09           | 0402                                   | 2.2Ω ±1% 62.5mW 0402 Thick Film Resistor                                                                                   | https://www.lcsc.com/product-detail/C25101.html    |
| 0402WGF1002TCE           | UNI-ROYAL                   | 100        | 0.0006          | 0.06           | 0402                                   | 10kΩ ±1% 62.5mW 0402 Thick Film Resistor                                                                                   | https://www.lcsc.com/product-detail/C25744.html    |
| 0402WGF2201TCE           | UNI-ROYAL                   | 100        | 0.0006          | 0.06           | 0402                                   | 2.2kΩ ±1% 62.5mW 0402 Thick Film Resistor                                                                                  | https://www.lcsc.com/product-detail/C25879.html    |
| 0402WGF4701TCE           | UNI-ROYAL                   | 100        | 0.0006          | 0.06           | 0402                                   | 4.7kΩ ±1% 62.5mW 0402 Thick Film Resistor                                                                                  | https://www.lcsc.com/product-detail/C25900.html    |
| ANR4012T470M             | APV                         | 10         | 0.0517          | 0.52           | SMD,4x4mm                              | 47uH Magnetic Shielded Inductor 500mA SMD,4x4mm Fixed Inductors RoHS                                                       | https://www.lcsc.com/product-detail/C7497063.html  |
| MAX30102EFD+T            | MAXIM                       | 1          | 13.7281         | 13.73          | OESIP-14                               | I2C OESIP-14 Specialized Sensors RoHS                                                                                      | https://www.lcsc.com/product-detail/C6454833.html  |
| LW06121                  | WENDA                       | 100        | 0.07            | 7              | SMD,P=0.62mm,Surface Mount,Right Angle | 1.2H 14Pin 0.62mm Pitch OLED FPC/FFC Upper Contact Pull-Out Horizontal SMD Flat Connector                                 | https://www.alibaba.com/product-detail/WENDA-LW06121-1-2H-14Pin-0_1601292173873.html |
| 1N4148                   | onsemi                      | 50         | 0.0221          | 1.11           | DO-35                                  | Diode 100V 200mA Through Hole DO-35                                                                                        | https://www.lcsc.com/product-detail/C258182.html   |
| GDEY0154D67-T03          | Goodisplay                  | 1          | 11.32           | 11.32          | -                                      | 1.54Inch Touch E-Paper 200x200 E-Ink Display                                                                               | https://www.aliexpress.com/item/1005005200574055.html |
| SSD1306                  | -                           | 2          | 0.72            | 1.44           | -                                      | 0.91 Inch I2C OLED Module                                                                                                  | https://www.aliexpress.com/item/1005004415958608.html?spm=a2g0o.tesla.0.0.4820nU7CnU7Cr1&pdp_npi=6%40dis%21AUD%21AU%241.39%21AU%241.05%21%21%21%21%21%402103122117624689217517794e3108%2112000046550658291%21btfpre%21%21%21%211%210%21&afTraceInfo=1005004415958608__pc__c_ppc_item_bridge_pc_main__vt8pak6__1762468921809 |
| 401225                   | -                           | 3          | 2.66            | 7.98           | -                                      | 3.7V 100mAh Lithium Polymer Lipo Rechargeable Battery                                                                      | https://www.aliexpress.com/item/1005006129236699.html?spm=a2g0o.cart.0.0.157538daxZfUfb&mp=1&pdp_npi=5%40dis%21AUD%21AUD%204.73%21AUD%204.02%21%21AUD%204.02%21%21%21%402103212317648973370843232e461d%2112000035892453159%21ct%21AU%216047249797%21%211%210 |
| 0619AAC                  | -                           | 1          | 3.06            | 3.06           | -                                      | Brushless X-axis 1.2V 100mA Max Precision Vibration Motor                                                                  | https://www.aliexpress.com/item/1005006421331249.html?spm=a2g0o.tesla.0.0.24f1nmtsnmts4h&pdp_npi=6%40dis%21AUD%21AU%244.13%21AU%241.54%21%21%21%21%21%402101d9ef17624709252885249e887e%2112000049883253246%21btfpre%21%21%21%211%210%21&afTraceInfo=1005006421331249__pc__c_ppc_item_bridge_pc_main__epipcn9__1762470925359 |

Total: $81.51 USD


*Manufactured Components*

| Description | Manufacturer | Material | Price (USD) |
|-------------|--------------|----------|-------------|
| 3D Printed Enclosure Main Cases | JLC3DP | Black Resin | 7.05 |
| 3D Printed Enclosure Top Plates | JLC3DP | LEDO 6060 Resin | 2.11 |
| CNC Machined OLED Segment Bottom Plates | JLCCNC | Aluminium 6061 | 17.46 |
| SLM 3D Printed Main Segment Bottom Plate | JLC3DP | 316L Stainless Steel | 8.39 |
| Main 4-layer Flex PCB | JLCPCB | Yellow 0.2mm Polyimide with 0.1mm FR4 Stiffener | 94.00 |
| SMD Stencil for Main Flex PCB | JLCPCB | Steel | 7.47 |

Total: $136.48 USD

---
## Grand Total (Excl. Shipping): $217.99 USD
---
*Find extensive journalling on my Hack Club Blueprint Project: https://blueprint.hackclub.com/projects/4721*
---

<img width="3840" height="2160" alt="render2" src="https://github.com/user-attachments/assets/f0ed52fa-0158-4048-8f5a-b0dd56644882" />
<img width="3840" height="2160" alt="render3" src="https://github.com/user-attachments/assets/27d17529-9d88-466d-976b-63a03502971e" />
<img width="3840" height="2160" alt="render7" src="https://github.com/user-attachments/assets/4ce2b655-8e93-46a4-b064-5f1a164d9f03" />
<img width="3840" height="2160" alt="render9" src="https://github.com/user-attachments/assets/e6760001-70ca-4997-b6b9-e19bca64b2fd" />
<img width="3840" height="2160" alt="render6" src="https://github.com/user-attachments/assets/3d396cf3-97b8-416f-bb71-77dd1194656e" />
<img width="2160" height="3840" alt="render5" src="https://github.com/user-attachments/assets/603ae98a-a7ab-407d-a89f-0b624756b0c6" />
