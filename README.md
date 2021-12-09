# ESP8266-FastLED-LightController

This is a simple Web Server built using the ESP8266 Web Module, which controls WS2811 LED lights in my room. Currently, the web page only
controls a single set of LEDs, but I plan on extending the project to have multiple ESP8266 boards, which will interact using ESPNOW.

# Files

-"NodeMCU.ESP8266.ino" is the file containing the Web Server. The web server displayed depends on which button on top is pressed. 
Currently there is only one webpage, "DeskLights.h", but as I add more ESP8266's, there will be an individual web page to control each unit.
-"DeskLights.h" contains the webpage being hosted by Web Server, in the format of a rawliteral string. 

