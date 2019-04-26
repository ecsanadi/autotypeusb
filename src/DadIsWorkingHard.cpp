
#include "DigiKeyboard.h"
#define PIN_LED 1

 unsigned long getRandom();
 int sec,secLast,secLast2 = 1;

  void setup() {

  DigiKeyboard.update();
  pinMode(PIN_LED,OUTPUT);

  } // setup()

  void loop()
  {
      sec = millis() / 1000;
      if (sec > 7200)
      {
          DigiKeyboard.print("666");
          while (1)
          {
             delay(1000);
          }

      }

      if (sec - secLast > 5)
      {
          digitalWrite(PIN_LED,HIGH);
          int random = ((getRandom() * millis()) % 8) + (millis() / 555);
          DigiKeyboard.print(random);
          secLast = sec;
          DigiKeyboard.update();
          digitalWrite(PIN_LED,LOW);
      }

      if((millis() % 20603 == 0) && sec != secLast2)
      {
          digitalWrite(PIN_LED,HIGH);
          DigiKeyboard.print(".");
          secLast2 = sec;
          DigiKeyboard.update();
          digitalWrite(PIN_LED,LOW);
          //delay(100);
      }
      if((millis() % 30809 == 0) && sec != secLast2)
      {
          digitalWrite(PIN_LED,HIGH);
          DigiKeyboard.print(" ");
          secLast2 = sec;
          DigiKeyboard.update();
          digitalWrite(PIN_LED,LOW);
      }
      if(millis() % 16000 == 0)
      {
          delay(10000);
      }


  }

  unsigned long getRandom()
  {
    unsigned long m_w = 1;
    unsigned long m_z = 2;

    m_z = 36969L * (m_z & 65535L) + (m_z >> 16);
    m_w = 18000L * (m_w & 65535L) + (m_w >> 16);
    return static_cast<unsigned long>((m_z << 16) + m_w);  /* 32-bit result */
  }


