#include<FirebaseArduino.h>
#include <ArduinoJson.h>
#include<ESP8266WiFi.h>
#define WIFI_SSID  "projectsaathi"
#define WIFI_PASSWORD "project@sa"
#define FIREBASE_HOST "dhniot.firebaseio.com"
#define FIREBASE_AUTH "Wzye5RLmuf8rTXzoX1GOMcmjQVQZg7KQQvUBYp5B"

int ledPower = 2;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting");
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.print("connected");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  pinMode(ledPower, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int ledStatus = Firebase.getInt("ledStatus");
  Serial.println(ledStatus);

  if(ledStatus == 0)
  {
    digitalWrite(ledPower, HIGH);
    
  }
  else
  {
      digitalWrite(ledPower, LOW);
  }
}
