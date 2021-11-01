
#define BLYNK_TEMPLATE_ID "TMPLJKNkKkzy"
#define BLYNK_DEVICE_NAME "ESP8266"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

//#define APP_DEBUG

#include "BlynkEdgent.h"

BlynkTimer timer;

#define  trig  5
#define  echo  4

long duration;
int distance;

void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  delay(100);

  BlynkEdgent.begin();
  timer.setInterval(1000L, sendSensor);
}

void loop() {
  BlynkEdgent.run();
  timer.run();
}

void sendSensor()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance = ");
  Serial.println(distance);
  
  Blynk.virtualWrite(V0, distance);
  delay(1000);
}
