/*********************

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *********************/

// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID           "TMPLd4Uvehzf"
#define BLYNK_DEVICE_NAME           "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "8UjwyPWyTxGfRPYhUDaXm4HQHvBL2ZsD"


// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Hot";
char pass[] = "99999999999";

BlynkTimer timer;

// This function is called every time the Virtual Pin 0 state changes
int relayInput = 4;
BLYNK_WRITE(V3){
if (param.asInt()==1){
digitalWrite(relayInput, HIGH); // turn relay on
//digitalWrite(14, HIGH); //led yellow on pin 5
//digitalWrite(12, LOW); //led red off pin 6
}
else{
digitalWrite(relayInput, LOW); // turn relay off
//digitalWrite(12, HIGH); //led red on
//digitalWrite(14, LOW); //led yellow off
}
delay(300);
}
void setup() {
Serial.begin(115200);
Blynk.begin(auth, ssid, pass);
pinMode(relayInput, OUTPUT); // initialize pin as OUTPUT
//pinMode(12,OUTPUT);
//pinMode(14,OUTPUT);
}

void loop()
{
  Blynk.run();
  timer.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}
