#include <Arduino.h>
#ifdef ESP32
  #include <WiFi.h>
  #include <AsyncTCP.h>
#else
  #include <ESP8266WiFi.h>
  #include <ESPAsyncTCP.h>
#endif
#include <ESPAsyncWebServer.h>
#include <espnow.h>

#define FASTLED_ESP8266_NODEMCU_PIN_ORDER
#define FASTLED_ESP32_I2S true            
#define FASTLED_ALLOW_INTERRUPTS 0
#define FASTLED_INTERRUPT_RETRY_COUNT 0 
#include <FastLED.h>
#define NUM_LEDS 50
#define LED_PIN 1
CRGB leds[NUM_LEDS];

uint8_t hue = 0;
uint8_t colorIndex[NUM_LEDS];

// These are the two strings used to pass information from the html page to the C++ in void loop()
String inputString;
String brightnessString;
uint8_t CURRENT_PAGE = 0;

// WebPage.h contains the index.html as a raw string
// Patterns.h is shared file containing the palette and patterns for FastLED
#include "Patterns.h"
#include "WebPage.h"
#include "DeskLights.h"

uint8_t deskAddress[] = {0xAC, 0x0B, 0xFB, 0xCE, 0xBE, 0xDD };

AsyncWebServer server(80);

const char* ssid = "*****";
const char* password = "*********";

// addressing the buttons to control which web page to send.
const char* CL_BTN = "clbtn";
const char* DESK_BTN = "deskbtn";
const char* TREE_BTN = "treebtn";
const char* OTHER_BTN = "otherbtn";

// addressing each button on the html page to the C++ code
const char* BTN_THREE = "btn3";
const char* BTN_FOUR = "btn4";
const char* BTN_FIVE = "btn5";
const char* BTN_SIX = "btn6";
const char* BTN_SEVEN = "btn7";
const char* BTN_EIGHT = "btn8";
const char* BTN_NINE = "btn9";
const char* BTN_TEN = "btn10";
const char* BTN_ELEVEN = "btn11";
const char* BTN_TWELVE = "btn12";
const char* BTN_THIRTEEN = "btn13";
const char* BTN_FOURTEEN = "btn14";

// addressing the brightness buttons
const char* BRIGHT_BTN_ONE = "bbtn1";
const char* BRIGHT_BTN_TWO = "bbtn2";
const char* BRIGHT_BTN_THREE = "bbtn3";
const char* BRIGHT_BTN_FOUR = "bbtn4";

void notFound(AsyncWebServerRequest *request) {
  request->send(404, "text/plain", "Not found");
}

void setup() {

  // Testing this code to avoid soft reset animation disruption. Still not sure if cause.
  ESP.wdtDisable(); 
  ESP.wdtEnable(WDTO_8S);
  ESP.getFreeHeap();
  

   for (int i = 0; i < NUM_LEDS; i++){ // Needed for the sunset shimmer to work
    colorIndex[i] = random8();
  }
  
  FastLED.addLeds<WS2811, LED_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(20);
  
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("WiFi Failed!");
    return;
  }

  Serial.println(WiFi.macAddress());

  esp_now_init();
  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);

  esp_now_add_peer(deskAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
  
  Serial.println();
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  
  
  // Send web page with input fields to client
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html);
  });

  // Send a GET request to <ESP_IP>/get?input1=<inputMessage>
  server.on("/get", HTTP_GET, [] (AsyncWebServerRequest *request) {

    typedef struct struct_message {
      int a;
    } struct_message;

    struct_message myData;
    
    // Determines which page to send
    if (request->hasParam(CL_BTN)) {
      CURRENT_PAGE = 0;
    }
    if (request->hasParam(DESK_BTN)) {
      CURRENT_PAGE = 1;
    }
    if (request->hasParam(TREE_BTN)) {
      CURRENT_PAGE = 2;
    }
    if (request->hasParam(OTHER_BTN)) {
      CURRENT_PAGE = 3;
    }


    if (request->hasParam(BTN_THREE) && CURRENT_PAGE == 0) {   // ------------------------------- CHRISTMAS LIGHTS -------------------------------- \\
      inputString = "1";
    }
    else if (request->hasParam(BTN_FOUR) && CURRENT_PAGE == 0) {
      inputString = "2";
    }
    else if (request->hasParam(BTN_FIVE) && CURRENT_PAGE == 0) {
      inputString = "3";
    }
    else if (request->hasParam(BTN_SIX) && CURRENT_PAGE == 0) {
      inputString = "4";
    }
    else if (request->hasParam(BTN_SEVEN) && CURRENT_PAGE == 0) {
      inputString = "5";
    }
    else if (request->hasParam(BTN_EIGHT) && CURRENT_PAGE == 0) {
      inputString = "6";
    }
    else if (request->hasParam(BTN_NINE) && CURRENT_PAGE == 0) {
      inputString = "7";
    }
    else if (request->hasParam(BTN_TEN) && CURRENT_PAGE == 0) {
      inputString = "8";
    }
    else if (request->hasParam(BTN_ELEVEN) && CURRENT_PAGE == 0) {
      inputString = "9";
    }
    else if (request->hasParam(BTN_TWELVE) && CURRENT_PAGE == 0) {
      inputString = "10";
    }
    else if (request->hasParam(BTN_THIRTEEN) && CURRENT_PAGE == 0) {
      inputString = "11";
    }
    else if (request->hasParam(BTN_FOURTEEN) && CURRENT_PAGE == 0) {
      inputString = "12";
    }
    else if (request->hasParam(BRIGHT_BTN_ONE) && CURRENT_PAGE == 0) {
      brightnessString = "bright1";
    }
    else if (request->hasParam(BRIGHT_BTN_TWO) && CURRENT_PAGE == 0) {
      brightnessString = "bright2";
    }
    else if (request->hasParam(BRIGHT_BTN_THREE) && CURRENT_PAGE == 0) {
      brightnessString = "bright3";
    }
    else if (request->hasParam(BRIGHT_BTN_FOUR) && CURRENT_PAGE == 0) {
      brightnessString = "bright4";
    }
    

    if (request->hasParam(BTN_THREE) && CURRENT_PAGE == 1) {   // ------------------------------- DESK LIGHTS -------------------------------- \\
      myData.a = 1;
      esp_now_send(deskAddress, (uint8_t *) &myData, sizeof(myData));
    }
    else if (request->hasParam(BTN_FOUR) && CURRENT_PAGE == 1) {
      myData.a = 2;
      esp_now_send(deskAddress, (uint8_t *) &myData, sizeof(myData));
    }
    else if (request->hasParam(BTN_FIVE) && CURRENT_PAGE == 1) {
      inputString = "3";
    }
    else if (request->hasParam(BTN_SIX) && CURRENT_PAGE == 1) {
      inputString = "4";
    }
    else if (request->hasParam(BTN_SEVEN) && CURRENT_PAGE == 1) {
      inputString = "5";
    }
    else if (request->hasParam(BTN_EIGHT) && CURRENT_PAGE == 1) {
      inputString = "6";
    }
    else if (request->hasParam(BTN_NINE) && CURRENT_PAGE == 1) {
      inputString = "7";
    }
    else if (request->hasParam(BTN_TEN) && CURRENT_PAGE == 1) {
      inputString = "8";
    }
    else if (request->hasParam(BTN_ELEVEN) && CURRENT_PAGE == 1) {
      inputString = "9";
    }
    else if (request->hasParam(BTN_TWELVE) && CURRENT_PAGE == 1) {
      inputString = "10";
    }
    else if (request->hasParam(BTN_THIRTEEN) && CURRENT_PAGE == 1) {
      inputString = "11";
    }
    else if (request->hasParam(BTN_FOURTEEN) && CURRENT_PAGE == 1) {
      inputString = "12";
    }
    else if (request->hasParam(BRIGHT_BTN_ONE) && CURRENT_PAGE == 1) {
      brightnessString = "bright1";
    }
    else if (request->hasParam(BRIGHT_BTN_TWO) && CURRENT_PAGE == 1) {
      brightnessString = "bright2";
    }
    else if (request->hasParam(BRIGHT_BTN_THREE) && CURRENT_PAGE == 1) {
      brightnessString = "bright3";
    }
    else if (request->hasParam(BRIGHT_BTN_FOUR) && CURRENT_PAGE == 1) {
      brightnessString = "bright4";
    }
      
 

    /*
    request->send(200, "text/html", "HTTP GET request sent to your ESP on input field (" 
                                      ") with value: " + inputString +
                                     "<br><a href=\"/\">Return to Home Page</a>");
    */

    // SOLVED THE INFINITE LOADING issue. Get request would timeout after a certain time 
    // and disconnect the user. Now it appears to be working.

    if (CURRENT_PAGE == 0){
      request->send_P(200, "text/html", index_html);
    }
    else if (CURRENT_PAGE == 1){
      request->send_P(200, "text/html", DeskLights_html);
    }
    else if (CURRENT_PAGE == 2){
      request->send_P(200, "text/html", index_html);
    }
    else if (CURRENT_PAGE == 3){
      request->send_P(200, "text/html", index_html);
    }

  });
  server.onNotFound(notFound);
  server.begin();
}


void loop() {

  if (inputString == "1"){
    test1();
  }
  else if (inputString == "2"){
    test2();
  }
  else if (inputString == "3"){
    test3();
  }
  else if (inputString == "4"){
    off1();
  }
  else if (inputString == "5"){
    newPattern();
  }
  else if (inputString == "6"){
    newPattern2();
  }
  else if (inputString == "7"){
    newPattern3();
  }
  else if (inputString == "8"){
    chocolate();
  }
  else if (inputString == "9"){
    rainbowFill();
  }
  else if (inputString == "10"){
    new1();
  }
  else if (inputString == "11"){
    new2();
  }
  else if (inputString == "12"){
    new3();
  }
  
  if (brightnessString == "bright1"){
    brightness(1);
    // setting to null to prevent infinite loop in brightness control
    brightnessString = "null";
    }
  else if (brightnessString == "bright2"){
    brightness(2);
    brightnessString = "null";
    }
  else if (brightnessString == "bright3"){
    brightness(3);
    brightnessString = "null";
    }
  else if (brightnessString == "bright4"){
    brightness(4);
    brightnessString = "null";
    }
  
}
