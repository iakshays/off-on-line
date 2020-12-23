#include <ESP8266WiFi.h>
#include <SimpleTimer.h>

SimpleTimer timer;
int MODE = 0;

const char* ssid = "Akshay"; //Enter SSID
const char* password = "akshaysp"; //Enter Password

void setup(void)
{ 
  pinMode(D2, OUTPUT);
pinMode(D3, OUTPUT);

  Serial.begin(9600);
  // Connect to WiFi
  WiFi.begin(ssid, password);
 timer.setInterval(3000,check);
}

void check(){
  if (WiFi.status() == WL_CONNECTED) {
    MODE = 1;
  }
  if (WiFi.status()!= WL_CONNECTED) {
    MODE = 0;
  }
}


void loop() 
{
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("Not Connected");
  }
  else
  {
    Serial.println(" Connected");
  }
    timer.run(); // Initiates SimpleTimer
  if (MODE == 1)
    with_internet();
  else
    without_internet();
}

void without_internet()
{
 
  digitalWrite(D2, HIGH);   // Turn the LED on (Note that LOW is the voltage level
  // but actually the LED is on; this is because
  // it is active low on the ESP-01)
  delay(300);                      // Wait for a second
  digitalWrite(D2, LOW);  // Turn the LED off by making the voltage HIGH
  delay(300);  
}

/*---------------------------------------------------------------------------------*/
void with_internet()
 {
  digitalWrite(D3, HIGH);   // Turn the LED on (Note that LOW is the voltage level
  // but actually the LED is on; this is because
  // it is active low on the ESP-01)
  delay(300);                      // Wait for a second
  digitalWrite(D3, LOW);  // Turn the LED off by making the voltage HIGH
  delay(300);  
}
