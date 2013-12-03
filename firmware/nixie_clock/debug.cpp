#include <Arduino.h>
#include <Wire.h>

/* RTC Clock  */
#include <Time.h>
#include <DS1307RTC.h>

/* Music player module */
#include <Garan.h>
#include <SoftwareSerial.h>

extern Garan player;
extern SoftwareSerial garanSerial;

void serialEvent()
{
  if (Serial.available()) {
    switch(Serial.read()) {
      case '1':
        player.singlePlay(1);
        break;
      case '2':
        player.sequencePlay(2);
        break;
      case '3':
        player.singlePlay(3);
        break;
      case '4':
        player.singlePlayName("00000001.mp3");
        break;
      case '5':
        player.sequencePlayName("00000001.mp3");
        break;
      case '6':
        player.singleLoopName("00000001.mp3");
        break;
      case '9':
        player.setVolume(15);
        break;
      case '0':
        player.setVolume(0);
        break;      
      case 'f':
        player.feedbackAtEnd();
        break;
      case 'n':
        player.next();
        break;
      case 'p':
        player.prev();
        break;
      case 't':
        player.getMusicNumbers();
        break;
      case 'v':
        player.getVersion();
        break;
      case ']':
        player.volumeUp();
        break;
      case '[':
        player.volumeDown();
        break; 
      default:
        Serial.println("This key maps to none.");     
    }
  }

  if (garanSerial.available()) {
    unsigned char recvByte = garanSerial.read();
    if (recvByte == 0x24) Serial.println();

    Serial.print(String(recvByte, HEX) + " ");
  }
}
