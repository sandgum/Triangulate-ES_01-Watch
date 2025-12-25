# Journal Entry 1: Initial Design (12/5/2025)
*Time spent: 3.0 hours*

I own a smartwatch which I use throughout my daily life, but there are so many gripes I have about my watch which seems like EVERY other manufacturer includes in their watches as well.

1. The watch's OLED display consumes too much power, and is unreadable in bright sunlight. Although manufacturers have tried to brute-force this problem with brighter and brighter OLED screens, that just increases power consumption and nukes battery life.
Why not use E-ink display technology for this??? It consumes so much less power and works in a way that bright sunlight actually makes the watch MORE readable.

2. The watch is BULKY. Modern smartwatches have become so thick, regularly exceeding 11 or 12mm in thickness. This is not the noticeable for regular use, but during workouts, where the wrist has to bend backwards at large angles (for bench-presses, push-ups etc.), the thickness of the watch digs into the wrist, making it extremely uncomfortable. Moreover, most watch manufacturers place their buttons on the side of the watch, exactly where the wrist contacts it when it bends backwards. This results in me accidentally pausing my workouts SO MANY TIMES mid-bench-press.
Therefore, this watch must be less than 5mm thick at its thickest point, and have NO buttons or touch surfaces on the side.

With this set of criteria, I looked towards finding suitable components for the main aspects of the watch, such as the display(s), battery and haptic motor.

Of course, including an E-ink display was at the top of my list, so I settled on a 1.54-inch panel with touch functionality from Good Display.
(Link: https://www.aliexpress.com/item/1005005200574055.html)
However, I also remembered some of E-ink's drawbacks which I would have to work around in my design. For example, E-ink does not emit any light, so I would either have to engineer my own backlight/frontlight for the display so that it can be used in the dark, or... I decided to include two tiny 0.91 inch OLED displays alongside the E-ink panel, one above and one below, to show additional information and to show information in the dark.
(Link: https://www.aliexpress.com/item/1005004415958608.html?spm=a2g0o.tesla.0.0.4820nU7CnU7Cr1&pdp_npi=6%40dis%21AUD%21AU%241.39%21AU%241.05%21%21%21%21%21%402103122117624689217517794e3108%2112000046550658291%21btfpre%21%21%21%211%210%21&afTraceInfo=1005004415958608__pc__c_ppc_item_bridge_pc_main__vt8pak6__1762468921809)

I also wanted this watch to have satisfying haptics, so I did some research into different types of haptic motors and settled on a linear motor (The same kind used in Apple's Taptic Engine) with reasonably beefy specs for MAXIMUM HAPTICS!!!
(Link: https://www.aliexpress.com/item/1005006421331249.html?spm=a2g0o.tesla.0.0.24f1nmtsnmts4h&pdp_npi=6%40dis%21AUD%21AU%244.13%21AU%241.54%21%21%21%21%21%402101d9ef17624709252885249e887e%2112000049883253246%21btfpre%21%21%21%211%210%21&afTraceInfo=1005006421331249__pc__c_ppc_item_bridge_pc_main__epipcn9__1762470925359)

Powering everything were three small (but mighty) 100mAh 3.7v LiPo batteries, which I chose because they are thin, narrow and almost the same width as the other components, so it would be a PERFECT fit.
(Link:
https://www.aliexpress.com/item/1005006129236699.html?spm=a2g0o.cart.0.0.157538daxZfUfb&mp=1&pdp_npi=5%40dis%21AUD%21AUD%204.73%21AUD%204.02%21%21AUD%204.02%21%21%21%402103212317648973370843232e461d%2112000035892453159%21ct%21AU%216047249797%21%211%210)

After compiling a list of components I wanted to include into the watch, I had some baseline dimensions to morph the design around.

![IMG_0526](https://github.com/user-attachments/assets/9bc8f426-2281-44ec-9441-6c980937134a)

I took the official dimensions of each component listed by the seller, modelled them in my 3D software of choice, Shapr3D, and started moving around the components in 3D to explore my options.

<img width="2360" height="1640" alt="IMG_0518" src="https://github.com/user-attachments/assets/6e3d086e-47a1-4ecb-b233-ac08ec8bebed" />

I eventually settled on a linear design, as it was one of my criteria for this watch to be as thin as possible for maximum comfort while wearing it. Placing each component in single file in a single layer was the best way to achieve that. I then brainstormed rough 2D renditions of the final design, making sure the overall silhouette looks aesthetically pleasing.

![IMG_0525](https://github.com/user-attachments/assets/506056d2-6d98-4c75-bd44-543a37809970)

I settled on a design which splits up each component into its own segment, which are all connected together using a flexible material (most likely TPU) structurally, while a flexible PCB runs through each segment. To make the design as simple as possible, I wanted to design the watch so that it would only use 1 flexible circuit board for the entire device.

And that's about it for now! Now that I have a basic idea as to what this watch will look like, I can start designing the enclosure for it, making it actually manufacturable.

---

# Journal Entry 2: Enclosure Design (12/6/2025)
*Time spent: 4.0 hours*

After coming up with a rough 2D design of the watch, I then hopped onto Shapr3D to model my vision in 3D. Starting off with the segment of the watch which houses the E-ink display, it was very important to the aesthetics for the display to be centred within the segment. However, as the display itself was asymmetric vertically, this resulted in a significant amount of empty space between the top of the display and the border of the segment. Also, the amount of blank plastic surrounding the display made it look blocky.

<img width="2360" height="1640" alt="IMG_0519" src="https://github.com/user-attachments/assets/286e6d34-29a8-4248-b865-e29529ca7719" />

But then I remembered: One of the criteria for this watch was for it to not have any buttons on the side, so the top of the watch can be used to house buttons! On top of that, this watch is made from segments that bend relative to each other when wrapped around a wrist. That means that the gaps in between each segment will expand towards the top of the segment, which frees up a lot of space for a human finger to reach into the gap and press a button. Plus, fitting two large buttons into the watch filled up the empty space I talked about previously, and also allowed for some of the blank plastic on both sides (as you can see in the picture) to be cut away, which added more visual depth to the design, making it much more aesthetically pleasing.

Now, up until this point, I haven’t really talked about where the control circuitry for the watch will reside. There must be somewhere where I can fit an ESP32-S3 circuit, a heart rate sensor circuit, an IMU circuit, a haptic motor driver circuit and maybe a lil amplifier circuit for a speaker. This is where I decided to design each enclosure which houses a display to have two separate sections, one for the approx. 1.5mm display, and the rest reserved for all of the circuitry, elegantly placed on a single flexible PCB which makes its way through the central three segments.

<img width="2360" height="1640" alt="IMG_0520" src="https://github.com/user-attachments/assets/7aa062e3-35f0-414a-877e-104ee2656fff" />
<img width="2360" height="1640" alt="IMG_0521" src="https://github.com/user-attachments/assets/a4c19939-46f2-4ac5-bcef-5d79aff7cb20" />

Also, you can see the addition of 2 screws (Yes, you see 4, the other two are fake) to hold the top, middle, and bottom pieces of the E-ink segment together, with the bottom piece having a cool mechanism which lets one end slot into the middle piece (Like the battery cover on a TV remote) and the other end gets secured with the screws, which secures all four corners of the bottom plate. Of course, a smartwatch has to be water resistant, so a bunch accommodations were made to ensure that watertight adhesive could easily be used to join all the pieces.

<img width="2360" height="1640" alt="IMG_0523" src="https://github.com/user-attachments/assets/28f9176d-dc7a-4ca7-bea2-5d19577cfe44" />

After coming up with a sick colour palette for the finished product (off-white for the top and bottom, and grey for the sides), I modelled the segments housing the OLED displays, which basically used the exact thickness and width of the E-ink segment to keep the design consistent. Since the modules were too small to incorporate real screws into them, some stylistic circles were carved into the corners, which again added visual depth to the design. Also, at this time I realised that the display segments were still too bland, so a nice indentation around the display borders was also added.

Next, it was time to design the segments of the watch which carry the batteries, which again used the exact same dimensions as the OLED segments. After adding two batteries to one side and two other segments to the other side, the uniform dimensions of each segment started to make the watch almost look like it has a bracelet made from REALLY chunky links. After me blabbering on about visual depth this whole time, you might be surprised to see completely blank faces on the battery segments, but that was done for two reasons:

A: The thickness of the top piece was WAY too thin for any carvings to be made in it (The battery is 4mm thick and the watch is 4.5mm thick)

B: This part of the watch is barely going to be visible to the wearer, and it should only serve to draw attention to the main focus of the watch, the displays. Plus, it looks CLEAN.

<img width="2360" height="1640" alt="IMG_0524" src="https://github.com/user-attachments/assets/44273afc-ca1c-4574-92c4-2d65f284bb5e" />

However boring the face of these battery segments might be, I cut some cable channels inside the middle piece for the cables from segments after it to be neatly routed through, as there really isn’t any room in this watch for messy cabling.

<img width="1800" height="1034" alt="Untitled2" src="https://github.com/user-attachments/assets/b8d44c6f-66e9-471f-b290-2ca680a859c0" />
<img width="1800" height="1034" alt="Untitled3" src="https://github.com/user-attachments/assets/09fffc38-d471-4ff9-af42-18d012769e82" />

Now, it was finally time to address the aspect of this watch I have been shoving under the carpet this whole time. How is each segment actually going to connect to each other??? Initially, I thought about using hinges to allow for each segment to pivot relative to each other, but that would result in the hairs on the wearer’s writs being caught up in the hinge, and also: How can I fit a reliable hinge between two segments just 1.5mm apart?

Next, I thought about inserting a flexible piece of material between each segment, but that also came with potential drawbacks. Firstly, placing flexible material between segments would interfere with the placement of wires and the flex PCB, and it would be extremely fiddly to print and attach tiny 1.5mm-long pieces between segments.

I then settled on having one continuous piece of rubber-like material (Most likely 3D printed TPU) on each side of the watch, with dedicated sections optimised for where the material will bend. I went with this cool circle design to keep things visually interesting, while cutting away the top part of the structure where it’s designed to bend. Moreover, the places where the material bends are curved into the gap between the segments for extra thickness. Apart from being SO MUCH EASIER to print and assemble, another advantage of this design is that the sides of the watch are also rubberised, which improves shock resistance and durability.

<img width="2360" height="1640" alt="IMG_0529" src="https://github.com/user-attachments/assets/9d0df905-bf85-4535-9281-5ff4433fb773" />
<img width="2360" height="1640" alt="IMG_0530" src="https://github.com/user-attachments/assets/c4c43088-c06c-4974-8f1c-34afa698ff10" />
<img width="2360" height="1640" alt="IMG_0531" src="https://github.com/user-attachments/assets/ee401e1b-711f-4099-b2ab-a170c33f8a34" />

After adding some 18mm standard watch band attachment points, the overall design is virtually finished!. Of course, some cutouts will have to be made for the heart rate sensor and the charging pins, but that will only be possible after the flex PCB is fully designed, which is what I will be doing next! In the meantime, enjoy some preliminary renders of the enclosure.

<img width="2360" height="1640" alt="IMG_0533" src="https://github.com/user-attachments/assets/d5a30d89-4480-4050-93c3-4838880812eb" />
<img width="2360" height="1640" alt="IMG_0534" src="https://github.com/user-attachments/assets/5612dd38-b479-4a60-90a6-a6cabe23d816" />
<img width="2360" height="1640" alt="IMG_0538" src="https://github.com/user-attachments/assets/54b4cab3-bf38-4c1a-9238-4714d39812a3" />
<img width="2360" height="1640" alt="IMG_0539" src="https://github.com/user-attachments/assets/486f44d2-717b-48ec-97e1-e156c163be89" />

---

# Journal Entry 3: Started the PCB Schematic (12/8/2025)
*Time spent: 2.5 hours*

Now that I had spent quite a bit of time tweaking and perfecting the aesthetics of the enclosure of the watch, it was time to focus my attention on towards creating the flexible PCB which will precisely fit inside the central three segments housing the displays. So, I booted up KiCad to start work on the first (and most obvious) part of the schematic of the E-ink smartwatch: The ESP32-S3 circuit itself! I had measured the amount of space I had left underneath the main display in my 3D model, and it turns out that the smallest pre-built ESP32-S3 module I could find was more than a millimetre TOO THICK to fit inside the watch’s enclosure. Well, there went my only chance to include a relatively fail-proof built-in module, so I turned to the various teeny-tiny ESP32-S3 boards I could find, and set about finding the one with the simplest schematic that I could integrate into my project. I eventually found that the ESP32-S3 Zero module from Waveshare had an extremely compact circuit schematic which still allowed for a plethora of pins to be exposed to connect to the various other components of the watch.

<img width="341" height="366" alt="Screenshot 2025-12-06 at 6 55 13 pm" src="https://github.com/user-attachments/assets/31530164-81d9-4386-8e28-b4d5f3ab257e" />
<img width="1203" height="721" alt="Screenshot 2025-12-06 at 6 55 36 pm" src="https://github.com/user-attachments/assets/e1562157-30c7-4d46-b530-a4f663fbd04f" />

Then I started trying to create a separate schematic sheet for the driving circuits of all the displays, as the panels I selected for my use case needed quite a lot of extra components to function correctly (This was done because of (you guessed it) thickness). I managed to find proper pinouts for the bare 0.91 inch OLED displays I wanted to use, and there are plenty of manufacturers who make simple breakout boards for the displays to be connected via I2C, so I used a schematic from one of those breakout boards and incorporated that into my design as well. The OLEDs would be simple to implement in code as well, as they communicate over I2C and have extensive libraries that the open-source community have created for them.

<img width="811" height="631" alt="Screenshot 2025-12-06 at 6 55 49 pm" src="https://github.com/user-attachments/assets/c2a6afb2-5841-40c2-8a68-0b7e9d0db371" />

But I had to address the elephant in the room: The fancy Good Display E-ink panel with TOUCH functionality. After checking the data sheet, I was provided with a nice application circuit for the main 24-pin display, however the pinout and application circuit for the touch panel were nowhere to be found. It was only after reaching out to a Good Display representative that I was directed to a full application circuit intended for an ESP32 (How lucky!!) that utilised the display and ALL of its capabilities! I promptly implemented the schematic into my PCB, making sure to link the I2C lines with the ones from the OLED displays and other devices included in the schematic. Interestingly, the display itself uses a variant of SPI for communication with the microcontroller, which, thankfully, the ESP32 also supports through basically all of its pins.

<img width="1336" height="571" alt="Screenshot 2025-12-07 at 9 23 48 pm" src="https://github.com/user-attachments/assets/3bacbb98-594f-416d-81ad-2ce6074e2742" />

After implementing a robust 3.3v regulator to power everything, the first half of the schematic was DONE. Now it’s time to focus my attention towards the sensors that will be included in the watch, and also the driver circuitry for the haptic feedback and possibly the loudspeaker!

---

# Journal Entry 4: Finished the PCB Schematic (12/12/2025)
*Time spent: 3.0 hours*

After fully implementing the circuits for the displays and the main microcontroller, it was time to shift my focus to the various sensors and the haptic driver circuit that would enable the smartwatch to take accurate measurements, both of the user and of the environment around it, and also be able to communicate with the user to notify them of events.

First up was to select the main inertial measurement unit (IMU) as that will be used for various functions, like wake up on raise, step counting, calorie/rep counting during workouts and depending on the quality of the IMU used, it can even be used (sort of) as a 3D mouse by using sensor fusion and dead reckoning together to give rough position estimates in 3D space. Since my main ESP32-S3 only has two cores (although quite powerful ones running at 200MHz), I would ideally want to perform a minimal number of calculations on the main microcontroller, as the IMU is one of the sensors which need to be operational almost all of the time, since it dictates when the device sleeps.

<img width="1208" height="776" alt="Screenshot 2025-12-12 at 9 04 34 am" src="https://github.com/user-attachments/assets/1f4d08b1-f501-487e-9888-2ddcfeb381e0" />
<img width="1212" height="829" alt="Screenshot 2025-12-12 at 9 05 43 am" src="https://github.com/user-attachments/assets/8d4295aa-9743-4918-9add-ec3e9a8fb3a8" />

I then turned to Bosch Sensortec’s line of IMUs, specifically, smart IMUs which incorporate their own teeny-tiny microcontroller to handle basic functions such as sensor fusion and even some tiny machine learning models to provide stuff like step counting. I immediately set my sights on their newest and most powerful addition to their lineup, the BHI385, however there was no library, API, or even SDK (to develop custom machine learning models) available for it, as the chip had only been released in September 2025. Looking around for a chip with more community support and established open-source software, I eventually landed on using the BHI260AP, which foregoes some of the more fancy AI-enabled features of the BHI385, but still provides onboard step tracking, wake interrupts, and sensor fusion so that the gyroscope and the accelerometer’s outputs are properly combined together to give an accurate idea of the absolute position and velocity of the watch. Following the application schematic on the datasheet for the BHI260AP was simple enough, but the implementation of this IMU also needed a separate 1.8V (TWO separate 1.8V power rails, actually) power rail to not fry the chip, and that also meant that the I2C signals coming from the chip had to be level shifted up to 3.3V so that it could interface with the ESP32, and I used a simple bidirectional logic level shifter circuit to achieve this.

<img width="906" height="743" alt="Screenshot 2025-12-12 at 9 07 14 am" src="https://github.com/user-attachments/assets/0d3ed993-5572-4c3d-a7ac-627fb01d1d40" />
<img width="459" height="607" alt="Screenshot 2025-12-12 at 9 07 41 am" src="https://github.com/user-attachments/assets/409c4bf2-61e0-4a10-9617-670bede7790e" />

Another integral part of any smartwatch is the heart rate tracking, which I decided to implement in this watch using the very well-known (and very well-documented) Analog Devices MAX30102 module, which incorporates the sensor IC, an LED, optics, and a light detector all in one tiny package, which was very convenient as it did not require me messing around with those things and possibly blowing something up. The application schematic for this module is also very simple, with it nicely interfacing through I2C and it also having a comprehensive Arduino library which can be implemented into ESP-IDF as a header file.

<img width="885" height="511" alt="Screenshot 2025-12-12 at 9 08 21 am" src="https://github.com/user-attachments/assets/6c5752b5-1efe-4719-9355-59ba6345fedf" />

Since I wanted to possibly enable absolute 3D positioning in this watch (using dead reckoning on the IMU), I thought it would be very useful to include a barometer into the build to precisely monitor the watch’s absolute elevation, which can be used for other things as well, such as an estimation of calories burnt during a hike based on elevation change data and many more. Again, Bosch Sensortec has the perfect option for this available, with the BMP585 pressure sensor being one of their most accurate and also happening to be completely waterproof (It is even specifically designed for wearables!). Plus, the sensor itself integrates a large number of components into its own package, which made it so the sensor only required two external capacitors to function!

<img width="1191" height="828" alt="Screenshot 2025-12-12 at 9 09 10 am" src="https://github.com/user-attachments/assets/20e422fa-f988-405b-b094-777d2ac553ec" />

Lastly, I went on a hunt to find the perfect haptic driver for my linear resonant actuator (LRA) motor that I had selected for the watch. After searching online and reading forums, I settled on the DRV2605L from Texas Instruments, as it provides a handy selection of over 100 of its own built-in haptic waveforms, which can all be triggered using simple I2C yet again. Moreover, the chip has comprehensive open-source libraries available for it, one of them being a module specifically designed for ESP-IDF which would slot nicely into the watch’s firmware stack. So I implemented the application schematic for that as well.

<img width="829" height="598" alt="Screenshot 2025-12-12 at 9 10 41 am" src="https://github.com/user-attachments/assets/3f5c938d-2906-491f-b2c2-0997c62bce50" />

Looking back at the total of four schematic sheets in the whole project, the schematic and all of the watch’s intended functionality was now fully laid out. Now it is time to lay out all of these components on the PCB. Bye for now!

---

# Journal Entry 5: Designed and routed the PCB (12/14/2025)
*Time spent: 7.0 hours*

Now that the schematic for the main PCB on the ES-01 (Yes, I ACTUALLY came up with a name!!) was finished, I then started to lay out the PCB as it would be in its final form (Spoiler! Here’s the finished layout).

<img width="1454" height="585" alt="Screenshot 2025-12-14 at 1 22 46 pm" src="https://github.com/user-attachments/assets/de96bd69-9578-4d47-8266-7013b079002a" />

To start, I drew out a rough outline for the flex PCB inside the 3D model, making sure it precisely matched the dimensions of the space I had left for it in the enclosure. Since the PCB is supposed to flex between the different segments of the watch, I also accounted for the length of the PCB that would be lost due to it bending in the enclosure, which added roughly 4mm to the length. After modelling the PCB’s shape, I exported its sketch in an SVG file, which I imported into KiCAD as the board’s Edge Cuts layer.

<img width="468" height="410" alt="Screenshot 2025-12-14 at 2 26 11 pm" src="https://github.com/user-attachments/assets/cd15ff0c-d19c-49ef-ac08-8f6d9e0b02f6" />

Then, after selecting and assigning various footprints to the custom libraries I uploaded while making the schematic, it was time to place all the components. I determined (and locked in) the placement of the four display connectors (Yes, four, because the E-ink panel’s touch feature needed its own connector), the heart rate sensor and the battery and haptic motor pads, which corresponded to holes cut out for their wires in the enclosure.

Soooooo, I decided to tackle probably the toughest-to-wire and most complicated package in my PCB FIRST, which was the ESP32-S3 chip. I decided on placing this sorta in the corner of the PCB, which allowed for just enough room above and ton the left of it for me to place the circuitry needed for WiFi and Bluetooth, a BUNCH of decoupling caps, and other circuitry for stuff like the external crystal oscillator. I decided to go for a 4-layer flexible PCB to base my design on, as I really need ultimate thinness, and flex PCBs start at just 0.2mm thick (even for 4-layer boards, that’s CRAZY). I’m proud of the way I efficiently placed each component so that it maximises the space used on the top of the PCB while minimising trace length as much as possible. However, to achieve this incredible component density, I did have to use some goofy routing in my internal and bottom layers, which you’ll see later as the board started to become more crowded with components…

<img width="834" height="545" alt="Screenshot 2025-12-10 at 2 10 48 pm" src="https://github.com/user-attachments/assets/3d01ab1b-2aa5-4fcf-9001-395f3b8c3824" />
<img width="943" height="775" alt="Screenshot 2025-12-10 at 2 55 14 pm" src="https://github.com/user-attachments/assets/b19edc1b-5c91-4b8a-945a-d8ff8ef5d8fa" />

During this time, I also placed the pads for the watch’s connection to its charging/programming dock, after which I realised that having exposed pads… with a DIRECT electrical connection to the 3.7v Li-Po batteries AND the internal power management unit was maybe a little bit of an oversight in terms of safety, cause literally ANYTHING could find its way onto those pads, short the batteries, and BLOW UP THE WATCH. So I added two beefy diodes which limited which way the current could go, as I only intended to use those pads for supplying power to the watch, not the other way around. With my configuration, it is also possible for a USB device to supply a clean 5V to power the whole watch without the 3.7v from the batteries, buuuuut that probably won’t be used if I’m already going to implement a battery charging circuit in the charging/programming puck thingy.

<img width="501" height="472" alt="Screenshot 2025-12-14 at 2 27 51 pm" src="https://github.com/user-attachments/assets/6c8ef458-2b1d-4eb9-b15f-1eec03368007" />

When routing the wires for the main display’s connector, things really started to get packed, with me having to resort to using quite a lot of vias (and some crazy precise placement to not violate design rules) to route the SPI and various other signals from the display to the ESP32 chip. It only got worse while routing the wires for the heart rate sensor and the two other sensors, however the wiring for those components could just connect to the shared I2C bus throughout the whole PCB, so that saved MANY vias from being placed near the main chip. There, the main section of the PCB was basically done, but I still had to route the power signals… See, what I had done up to this point was that every time a component needed a connection to the 3.3v or 1.8v power rails, I just placed some vias there in the hopes of connecting them all together when I had fully routed all the signal traces. When the routing for these traces was done, however, there was basically no space left in ANY layer to route the power rails, and so I was left stumped. I even considered switching to a 6-layer flex PCB, but that would drive costs SKY HIGH, limiting how many iterations I could make of the PCB. So I did the difficult task of carefully rerouting a bunch of the signals to make way for 3.3v and 1.8v power traces of acceptable thicknesses which could accommodate the power needs of every component.

<img width="890" height="849" alt="Screenshot 2025-12-14 at 2 28 57 pm" src="https://github.com/user-attachments/assets/570bbc7e-9393-45af-bdaf-88d42dc6ebb7" />

Thankfully, I managed it, which then just left the two auxiliary parts of the PCB to be routed. These would include the two OLED display circuits and the haptic motor driver, which were thankfully very easy to route together, because there was quite a lot of space on these two sections.

Now to spend a couple of hours fixing OVER 100 DESIGN RULES VIOLATIONS that I had somehow missed during the design of the board, and then it was time to finally move on to the silkscreen layer and add some flair to the PCB. I opted to use a very small 0.4mm text size for all the component designations (simply because there was only enough space between said components for that size), and added some nice logos and text to the board, tying up the whole design nicely. I added a custom layer for JLCPCB to apply plastic stiffeners to the parts of the watch which DON’T bend, and finally, FINALLY the first version of the completed PCB was DONE.

<img width="1551" height="288" alt="Screenshot 2025-12-14 at 2 37 20 pm" src="https://github.com/user-attachments/assets/9b85dce3-5c36-4b06-95a1-826080e2ed0b" />

Since I’m using a 4-layer Flex PCB, the manufacturing costs were quite high on JLCPCB, with my putting in a quote and seeing the price of just 5 boards at just less than $150 Australian dollars (that’s basically $100 USD for the Americans). Yikes. (I think it’s time to go tier 1???)

---

# Journal Entry 6: Budgeting!!! (12/17/2025)
*Time spent: 4.5 hours*

After finalising the design of the PCB, I exported all of the production files for it onto JLCPCB, which (through the KiCAD Plugin for JLCPCB I used) also left me with the bill of materials file which I uploaded into JLCPCB’s automatic parts selector. I previously wanted the PCB to be assembled by JLCPCB, but that resulted in the cost for only two PCBs rising to over $400 AUD, which would eat up a significant portion of my allocated budget. Instead, I have chosen to assemble the PCB myself, with the aid of a metal stencil that I will order from JLCPCB and the tools I have for solder reflowing (I have already assembled SMD PCBs before, so I also have experience).

<img width="1135" height="364" alt="Screenshot 2025-12-17 at 11 53 33 am" src="https://github.com/user-attachments/assets/f7b381dc-e0b9-45cd-8b9b-c1e7bf615d93" />

Finding parts on JLC that suited my requirements, the parts needed to assemble one PCB totalled a much more modest $48 AUD, with the actual PCB and stencils totalling $180 AUD (including shipping) for one iteration. That brings the total cost of the PCB to $228 AUD, which is just over $151 USD (Well under my budget!).

<img width="338" height="68" alt="Screenshot 2025-12-17 at 11 50 33 am" src="https://github.com/user-attachments/assets/7c0a7fee-ae49-4796-874f-d1dd7bd59a45" />

However, I have run into a major problem relating to the enclosure design for the ES_01 watch. A lot of the smallest parts that make up the enclosure were too small to be printed by JLC3DP, so I have to revise the design and merge some of the smallest base plates of the battery and haptic segments into the larger main enclosures. This left the bottom plates of the OLED segments that were too small to be printed in any JLC3DP machine, so I decided that the bottom plates of the three central segments (E-ink, and the two OLEDs) will be CNC machined out of aluminium. This, as well as making the small OLED bottom plates manufacturable, will also place metal directly above the heat-generating components of the watch, such as the ESP32-S3 chip which generates quite a lot of heat when doing compute-intensive tasks, especially with any wireless tasks like Bluetooth and WiFi.

Also, having the bottom plates be made from aluminium will add additional rigidity to the watch, and also make it look much more aesthetically pleasing. After quoting the cheapest possible options for 3D printing the remaining parts, CNC machining the bottom plates, fabricating the PCB and obtaining the PCB’s components, the total cost of everything from JLC (including shipping) came to $295 AUD, which is roughly $196 USD. Additionally, the total cost of the rest of the components (E-ink display, two OLEDs, missing PCB components JLCPCB did not have) is approximately $70 AUD, which is roughly $47 USD.

Therefore, the total combined cost of the ES_01 watch at this point is $243 USD. This cost might also increase with the additional charging/programming puck I have yet to design, but the manufacturing of that component will be quite cheap, so my current estimate on its cost is less than $10 USD. Accordingly, I have updated my requested grant from Hack Club to $250 USD. Yippeeee! Now I actually know how much this thing will cost!! Full compiled BoM coming later!

---

# Journal Entry 7: Finishing Touches on the 3D Model (12/22/2025)
*Time spent: 4.0 hours*

Now that I have basically finished the design of the first version of the ES_01, it was time to focus on making some finishing touches to make the project perfect and ready to be manufactured.
First up, I assigned each and every component in my KiCAD PCB to its own 3D STEP file, as a bunch of the packages I had used were from external libraries from Ultra Librarian and SnapEDA. Finding (in some cases, creating), assigning and aligning each 3D model to its respective PCB footprint took about two hours of work, after which I was ready to finally export the full PCB’s 3D model from KiCAD.

<img width="1800" height="1078" alt="pcbrender" src="https://github.com/user-attachments/assets/fa4bb464-b971-4d10-9127-fa6b8f56d6d4" />

After importing the PCB 3D model into Shapr3D, I checked the fitment of the PCB inside of the watch’s enclosure (IT FITS!!) and also started to work on the bottom panel of the segment of the watch which holds the E-ink panel. This component had to be modified now that the PCB that sits above it has a bunch of parts which require extra clearance. I created holes for the 5 or so components on the PCB which stick out the most, and also created holes that expose the contacts for charging the watch and programming it.

Most importantly, I created cutouts for the heart rate sensor and the pressure sensor (they need cutouts for obvious reasons) but then I also created a raised section around the heart rate sensor so that it would provide clearance for air to make its way to the pressure sensor, and so that the two diodes which stick out the most would not dig into the wearer’s wrist uncomfortably. Plus, this raised section allows for a gentle fillet into the cutout for the heart rate sensor, which will hopefully guide the wearer’s skin towards the sensor, potentially improving accuracy.

<img width="1800" height="1078" alt="bottomplate64724" src="https://github.com/user-attachments/assets/e86d9ccc-7336-4f36-9da4-b898396c3a11" />

Also, I previously discussed the benefits of an aluminium bottom panel for providing thermal relief to the ESP32-S3 chip, so I made a raised section towards the chip which aims to contact it directly (through a thermal intersect material like thermal paste) and dissipate its generated heat through the whole panel. Moreover, I made use of the electrical conductivity of aluminium to act as EMI shielding for the circuits in the watch. To achieve this, I created more raised sections towards the PCB which directly connect to exposed GND pads in the PCB (which I designed to connect together analog and digital grounds).

This shielding is especially useful for the U.FL patch antenna I plan on routing through the watch (for Bluetooth and WiFi), which will now have a nice EMI-shielded path for the antenna’s cable (before the actual patch in the patch antenna) to go through to minimise noise.

<img width="1800" height="1078" alt="insideESP32" src="https://github.com/user-attachments/assets/1bbf0442-15e3-40a5-84d1-c342c5657519" />

At this point, I realised that maybe the bottom plate for the E-ink segment was too complicated to CNC machine, especially with the many tiny geometric features I had modelled into it. So I looked towards getting this part 3D printed out of stainless steel, and it is nearly 3 times less expensive to do so! While CNC-ing this part would cost about $36 AUD, 3D printing it only costs about $12 AUD! (Plus, I’ll save some poor CNC machinist the pain of machining such a complex part).

<img width="1729" height="462" alt="bottomsidefinished" src="https://github.com/user-attachments/assets/c1c4ddb5-c6bd-4014-8332-3bcfdf6c5c17" />

Now, the full 3D model is basically done, and now it’s time to focus on polishing up my project (especially the GitHub repo) with some PROPER renders (not in Shapr3D, but BLENDER!!!) of the whole thing!

---

# Journal Entry 8: Finished Blender Renders (12/25/2025)
*Time spent: 3.0 hours*

To polish up my repository so that it passes the design review, I set my sights on creating some really pretty renders of the ES_01 in Blender, where I had WAY more flexibility for lighting and scene design than in the native model renderer in Shapr3D. Importing a model with THOUSANDS of components (thanks to the very detailed PCB model 😅) while preserving colour information for each of them was not very straightforward, however, and required multiple exports into multiple file formats. This continued until I found that exporting into a USDZ file finally retained material information that Blender could recognise.

Of course, this was only for the PCB model, as I planned on assigning more visually advanced materials to the rest of the components which would make the whole watch look even more realistic.

<img width="3024" height="4032" alt="IMG_0914 (1)" src="https://github.com/user-attachments/assets/4a1ecf5b-28bd-45f5-8904-b116db6b8404" />

I then decided that it would be a good idea to bend the watch and actually show what it would look like on a human hand, which required me to create an armature rig for the watch and also required importing a Blender model of a human hand (The BlenderKit add-on was EXTREMELY useful for quickly importing materials and external models).

In the end, I was left with 10 really nice-looking renders (while using all my Blender skills) that I have now updated the Readme on my repository with! Now I just have to add the final touches (Journal, full BoM on repo) and I’ll be ready to submit this project for a design review!!!

<img width="3840" height="2160" alt="render1" src="https://github.com/user-attachments/assets/c3ab5279-35c0-413c-b243-6d8a35135c97" />
<img width="3840" height="2160" alt="render10" src="https://github.com/user-attachments/assets/a0d02226-3232-4262-9841-c50d1b55ddd9" />
<img width="3840" height="2160" alt="render9" src="https://github.com/user-attachments/assets/d70ae236-0778-4c59-ab2b-09ceb52fb6b6" />
<img width="3840" height="2160" alt="render8" src="https://github.com/user-attachments/assets/61c062e5-6ed0-4c1f-9b09-d801a6cae141" />
<img width="3840" height="2160" alt="render7" src="https://github.com/user-attachments/assets/8fd423a5-2f4e-4e8a-8343-638dc83ce1e2" />
<img width="3840" height="2160" alt="render6" src="https://github.com/user-attachments/assets/a12e9e22-c460-4dc0-b1e7-195ae77bf03b" />
<img width="2160" height="3840" alt="render5" src="https://github.com/user-attachments/assets/326cd515-3173-4ee1-8f91-84dbff503dc9" />
<img width="2560" height="1440" alt="render4" src="https://github.com/user-attachments/assets/c2abc8c2-66e1-485a-900b-3daf6046db8f" />
<img width="3840" height="2160" alt="render3" src="https://github.com/user-attachments/assets/950db5fc-a4ea-45e8-a2b3-8b68f4625ec5" />
<img width="3840" height="2160" alt="render2" src="https://github.com/user-attachments/assets/4d66424a-04e7-413b-8710-025cb7367b60" />

