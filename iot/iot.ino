#include<FirebaseArduino.h>
#include <ArduinoJson.h>
#include<ESP8266WiFi.h>
#define WIFI_SSID  "aplus_engineering"
#define WIFI_PASSWORD "mark@12345"
#define FIREBASE_HOST "dhniot.firebaseio.com"
#define FIREBASE_AUTH "WESdLN84wBtL8S20BVt36rWTBov2W2EEMsvyeNj5"



int ledPower = D3;
int fanPower = D0;
int tvPower = D1;
int acPower = D2;

///code for pir sensor
int pirLed = D4;
int pirInput = D5;
int pir;

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

//  /code for pir sensor
pinMode(pirInput,INPUT);
pinMode(pirLed, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int fanStatus = Firebase.getInt("fanStatus");
  Serial.print("Fan Status :");
  Serial.println(fanStatus);
  delay(2000);
  if(fanStatus == 1)
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
  delay(2000);

  if(ledStatus == 1)
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
  delay(2000);
  if(tvStatus == 1)
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
  Serial.println("\n\n");
  delay(2000);
  if(acStatus == 1)
  {
    digitalWrite(acPower, HIGH);
  }
  else
  {
    digitalWrite(acPower, LOW);
  }



/// code for pir
pir = digitalRead(pirInput);
if(pir == 1)
{
  digitalWrite(pirLed, HIGH);
}
else
{
  digitalWrite(pirLed, LOW);
}
  
}
