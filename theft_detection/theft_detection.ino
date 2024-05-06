#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
// #include <WiFi.h>
// #include <NTPClient.h>
// #include <WiFiUdp.h>
// #include <Arduino_ConnectionHandler.h>
// #include <WiFiManager.h>

#define PIR_PIN1 19 // Connect PIR sensor 1 to GPIO 2
#define PIR_PIN2 18 // Connect PIR sensor 2 to GPIO 4
#define PIR_PIN3 5 // Connect PIR sensor 3 to GPIO 5
#define RELAY_PIN 17 // Connect relay module to GPIO 12
#define BUZZER_PIN 2 // Connect buzzer to GPIO 13
// #define NIGHT_MODE_START_HOUR 14 // Night mode start hour (24-hour format)
// #define NIGHT_MODE_END_HOUR 14 // Night mode end hour (24-hour format)

// const char* ssid = "SCRC_LAB_IOT";
// const char* password = "Scrciiith@123";
// const char* ntpServer = "pool.ntp.org";
// const long gmtOffset_sec = 19800; // GMT offset in seconds (1 hour)
// const int daylightOffset_sec = 3600; // Daylight offset in seconds (1 hour)
//   WiFiConnectionHandler conn(ssid,password);

// WiFiUDP ntpUDP;
// NTPClient timeClient(ntpUDP, ntpServer, gmtOffset_sec, daylightOffset_s


void setup() {
  pinMode(PIR_PIN1, INPUT);
  pinMode(PIR_PIN2, INPUT);
  pinMode(PIR_PIN3, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);


 
  // Initialize serial communication for debugging
  Serial.begin(115200);

  // Connect to Wi-Fi
  // WiFi.begin(ssid, password);
  // while (WiFi.status() != WL_CONNECTED) {
  //   delay(1000);
  //   Serial.println("Connecting to WiFi...");
  // }
  // Serial.println("Connected to WiFi");

 //wifi manager ............
  // WiFi.mode(WIFI_STA); // explicitly set mode, esp defaults to STA+AP
  // WiFiManager wm;
  // wm.resetSettings();
  // bool res;
  // bool wifiConnected = false; // Declare the wifiConnected variable
  // res = wm.autoConnect("AutoConnectAP","password"); // password protected ap
  // if(!res) {
  //     Serial.println("Failed to connect");
  //     // ESP.restart();
  //   } 
  //   else {
  //     Serial.println("Connected to Wi-Fi!");
  //     wifiConnected = true; // Update the wifiConnected variable
  //   }

  // // Initialize the NTP client
  // timeClient.begin();
  // timeClient.setTimeOffset(gmtOffset_sec);
}

void loop() {
  // conn.check(); // reconnecting the wifi after getting disconnected
  // timeClient.update();
  // int currentHour = timeClient.getHours();
//  Serial.println(currentHour);
  // Check if it's nighttime
  // if (currentHour >= NIGHT_MODE_START_HOUR || currentHour < NIGHT_MODE_END_HOUR) {
    // Check for motion from any of the PIR sensors
    if (digitalRead(PIR_PIN1) || digitalRead(PIR_PIN2)) {
      Serial.println("PIR_PIN11");
      Serial.println(digitalRead(PIR_PIN1));
      Serial.println("PIR_PIN12");
      Serial.println(digitalRead(PIR_PIN2));
     // Serial.println("PIR_PIN13");
     // Serial.println(digitalRead(PIR_PIN3));
      // Motion detected during nighttime, trigger the relay and buzzer
      digitalWrite(BUZZER_PIN, HIGH);
      digitalWrite(RELAY_PIN, LOW);
      // Serial.println("LED ON");
      delay(5000); // Delay for 1  (adjust as needed)
      digitalWrite(BUZZER_PIN, LOW);
     while(1){
      if(digitalRead(PIR_PIN1) || digitalRead(PIR_PIN2))
     {
        Serial.println("PIR_PIN21");
        Serial.println(digitalRead(PIR_PIN1));
        Serial.println("PIR_PIN22");
        Serial.println(digitalRead(PIR_PIN2));
        continue;
    }   else
          break;
     }
      delay(20000);
      Serial.print("Motion Detected");
      digitalWrite(RELAY_PIN, HIGH);
    
 }
delay(1000);
}
