Author: neon1024

Title: Toggle LED on ESP32 via browser

Description: Toggle LED 5 on ESP32 via browser. The board connects to the specified network and provides an IP address to connect to which allows you to toggle the LED 5 on the board and also show its status. The network details can be changed in the code as they are hard coded values. I chose the ESP32 board because it has built in WiFi and Bluetooth capabilities.

Components:
Board:
- ESP32 (https://sigmanortec.ro/placa-de-dezvoltare-esp32-dual-core-wifi-bluetooth-4mb)
Breadboard:
- 400 holes (https://sigmanortec.ro/Breadboard-400-puncte-p129872825)
Cables:
- x40 Dupont Male to male (https://sigmanortec.ro/40-Fire-Dupont-30cm-Tata-Tata-p210849599)
- Micro USB (https://sigmanortec.ro/cablu-date-smart-usb-la-micro-usb-fast-charging)

Software:
- Arduino IDE (https://www.arduino.cc/en/software/)
- ESP32 for Arduino IDE tutorial (https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/)

Setup and build:
- Connect the board pins to the breadboard
- Connect 1 male to male cable to the 3V3 hole for the board and to the corresponding "-" hole
- Connect 1 male to male cable to the GND hole for the board and to the corresponding "+" hole
- Connect the board to the Micro USB cable and to the device

Running:
- The board should go automatically in flash mode when uploading the code via Arduino IDE, but in case it doesn't, follow these steps:
- Hold the RESET button before and during the uploading via Arduino IDE until the "Connecting ....." message appears
- Go to the Serial Monitor in order to get the IP address to connect to