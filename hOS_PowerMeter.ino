/*
 * Copyright (c) 2020, Dave Beusing <david.beusing@gmail.com>
 * All rights reserved.
 *
 * https://www.amazon.de/gp/B0754HWZSQ
 * NodeMCU Amica ESP8266 ESP-12F
 *
 * variants/nodemcu/pins_arduino.h
 * #define LED_BUILTIN 2
 * #define LED_BUILTIN_AUX 16
 * #define PIN_WIRE_SDA (4)
 * #define PIN_WIRE_SCL (5)
 * static const uint8_t D1   = 5;
 * static const uint8_t D2   = 4;
 *
 * #define PIN_A0 (17)
 * static const uint8_t D0   = 16;
 * V1
 *
 * https://gist.github.com/adlerweb/2d60f5bd2af4d91e937a7fd55cd464b2
 * https://raw.githubusercontent.com/Wim3d/Main_power_meter/master/Main_power_meter.ino
 */

#define LEDPIN LED_BUILTIN_AUX

#define SECOND 1e3          // 1e3 ms is 1 second
#define MINUTE SECOND*60    // 60e3 ms is 60 seconds = 1 minute
#define HOUR MINUTE*60      // number of millis in an hour
#define DAY HOUR*24         // number of millis in a day


#define TCRT5000_A0 17
#define TCRT5000_D0 16


void setup() {
  Serial.begin(115200);                                 //init BAUDRATE 115200
  while(!Serial);                                       //time to get serial up & running
  delay(1000);                                          //wait 1 more second
  Serial.println(F("\nPOWER MONITOR - BOOT\n"));


  pinMode(LEDPIN, OUTPUT);
  pinMode(TCRT5000_D0, INPUT);



}

void loop() {
     float fAbstand = 0;
     int i = 1;
     /*---------------------------------*/
     /* Sensorwerte einlesen            */
     /*---------------------------------*/
     int value_D0 = digitalRead(TCRT5000_D0);   // digitale input vom IR distance sensor auslesen
int value_A0 = 0;
  //Mittelwertwertermittlung der analogen Messwerte --> Zuverlässigkeit erhöhung
  for (i = 1; i <= 50; i++)
  {
    value_A0 = analogRead(TCRT5000_A0);   // analoge input vom IR distance sensor auslesen
    fAbstand = fAbstand + value_A0;
  }
  fAbstand = fAbstand / i;





  Serial.print( " A0: ");
  Serial.print( value_A0 );
  Serial.print( " / D0: " );
  Serial.print( value_D0 );
  Serial.print( " /fAbs: " );
  Serial.print( fAbstand );
  Serial.println();
  digitalWrite(LEDPIN, HIGH);     // blink led
      delay(50);
      digitalWrite(LEDPIN, LOW);


}
