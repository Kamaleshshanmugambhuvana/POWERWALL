
#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL3GPOY2TJs"
#define BLYNK_TEMPLATE_NAME "PowerWall"
#define BLYNK_AUTH_TOKEN "zFpL6jjwfFSwdHqB5yR6HHPeESa8gt4h"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "Galaxy Note 9";
char pass[] = "kamalesh";

// Define the Relay pin and related variable
int RelayPin1 = 5;
int RelayPin2 = 4;
int switchStatus1 = 0;
int switchStatus2 = 1;

const int Pin1 = 14;
const int Pin2 = 12;
const int Pin3 = 13;
//const int Pin4 = 4;
//const int Pin5 = 4;
//const int Pin6 = 4;

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(RelayPin1, OUTPUT);
  pinMode(RelayPin2, OUTPUT);
  digitalWrite(RelayPin1, LOW); 
  digitalWrite(RelayPin2, LOW);
  pinMode(Pin1, INPUT);
  pinMode(Pin2, INPUT);
  pinMode(Pin3, INPUT);
  //pinMode(Pin4, INPUT);
  //pinMode(Pin5, INPUT);
  //pinMode(Pin6, INPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  Blynk.run();

  if (digitalRead(Pin1) == HIGH) {
    Blynk.virtualWrite(V2,HIGH);
  } else {
    Blynk.virtualWrite(V2,LOW);
  }

  if (digitalRead(Pin2) == HIGH) {
    Blynk.virtualWrite(V3,HIGH);
  } else {
    Blynk.virtualWrite(V3,LOW);
  }

  if (digitalRead(Pin3) == HIGH) {
    Blynk.virtualWrite(V4,HIGH);
  } else {
    Blynk.virtualWrite(V4,LOW);
  }

  /*if (digitalRead(Pin4) == HIGH) {
    Blynk.virtualWrite(V5,HIGH);
  } else {
    Blynk.virtualWrite(V5,LOW);
  }

  if (digitalRead(Pin5) == HIGH) {
    Blynk.virtualWrite(V6,HIGH);
  } else {
    Blynk.virtualWrite(V6,LOW);
  }

  if (digitalRead(Pin6) == HIGH) {
    Blynk.virtualWrite(V7,HIGH);
  } else {
    Blynk.virtualWrite(V7,LOW);
  }*/
}

BLYNK_CONNECTED() {
  Blynk.syncVirtual(V0); // updates Virtual Pin V0 to the latest stored value on the server.
  Blynk.syncVirtual(V1);
}

// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V0) {
  switchStatus1 = param.asInt();  // Set incoming value from pin V0 to a variable

  if (switchStatus1 == 1) {
    Serial.println("The switch on Blynk has been turned on.");
    digitalWrite(RelayPin1, HIGH);
  } else {
    Serial.println("The switch on Blynk has been turned off.");
    digitalWrite(RelayPin1, LOW);
  }
}

BLYNK_WRITE(V1) {
  switchStatus2 = param.asInt();  // Set incoming value from pin V0 to a variable

  if (switchStatus2 == 1) {
    Serial.println("The switch on Blynk has been turned on.");
    digitalWrite(RelayPin2, HIGH);
  } else {
    Serial.println("The switch on Blynk has been turned off.");
    digitalWrite(RelayPin2, LOW);
  }
}
