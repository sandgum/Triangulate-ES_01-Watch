# Functions implemented so far:

* Wrote driver for 1.54 inch e-ink display to operate over SPI (uses ssd1681 driver IC)
* Wrote driver for FT6336 touch driver IC (for main e-ink panel)
* Implemented LVGL v9 into project
* Implemented OLED displays (ssd1306 driver IC) into project and LVGL
* Upgraded project to use ESP-IDF 5.3 (to use built-in ssd1306 component)
* Created minimal driver library for MAX30102 heart rate sensor
* Implemented basic heart rate measurement using MAX30102
* Implemented various functions using Bosch BHI260AP IMU using Bosch API, including:

  * Orientation tracking using IMU's built-in sensor fusion algorithm
  * Intelligent step counting using IMU's built-in algorithm running on its own coprocessor
  * Intelligent wrist raise detection, sending interrupts to wake ESP32 from light sleep

* Implemented basic sleep/wake-up logic, including:

  * Putting ESP32 in light sleep after a certain period of inactivity on touch screen
  * Putting ESP32 in light sleep when BHI260AP detects that the user's wrist is facing downwards
  * Waking ESP32 from light sleep using its own timer to periodically take heart rate measurements

* Implemented reading Bosch BMP585 pressure/temperature sensor using Bosch sensor API
* Implemented driving DRV2605 haptic driver
* IT BUILDS!!!
