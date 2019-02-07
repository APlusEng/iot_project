#include<FirebaseArduino.h>
#include <ArduinoJson.h>
#include<ESP8266WiFi.h>
#define WIFI_SSID  "aplus_engineering"
#define WIFI_PASSWORD "Aplus@1234"
#define FIREBASE_HOST "dhniot.firebaseio.com"
#define FIREBASE_AUTH "Wzye5RLmuf8rTXzoX1GOMcmjQVQZg7KQQvUBYp5B"

int ledPower = 2;
int fanPower = D0;
int tvPower = D1;
int acPower = D2;

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
  pinMode(fanPower, OUTPUT);
  pinMode(acPower, OUTPUT);
  pinMode(tvPower, OUTPUT);
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int fanStatus = Firebase.getInt("fanStatus");
  Serial.print("Fan Status :");
  Serial.println(fanStatus);
  if(fanStatus == 0)
  {
    digitalWrite(fanPower, HIGH);
  }
  else
  {
    digitalWrite(fanPower, LOW);
  }

//  code for led
  int ledStatus = Firebase.getInt("ledStatus");
  Serial.print("LED Status :");
  Serial.println(ledStatus);

  if(ledStatus == 0)
  {
    digitalWrite(ledPower, HIGH);
    
  }
  else
  {
      digitalWrite(ledPower, LOW);
  }


//  code for tv
  int tvStatus = Firebase.getInt("tvStatus");
  Serial.print("TV Status : ");
  Serial.println(tvStatus);
  if(tvStatus == 0)
  {
    digitalWrite(tvPower, HIGH);
  }
  else
  {
    digitalWrite(tvPower, LOW);
  }

//  code for ac

  int acStatus = Firebase.getInt("acStatus");
  Serial.print("AC Status : ");
  Serial.println(acStatus);
  if(acStatus == 0)
  {
    digitalWrite(acPower, HIGH);
  }
  else
  {
    digitalWrite(acPower, LOW);
  }


  
}
