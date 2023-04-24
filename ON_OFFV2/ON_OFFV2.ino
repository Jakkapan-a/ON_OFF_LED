#include <TcPINOUT.h>
#define ledPin 12

void isLED(bool);
TcPINOUT led(ledPin, isLED, true);

unsigned long period = 1000;  // 1 seconds
unsigned long last_time = 0;
int step = 0;
int count = 0;
int max_count = 10;
 int minute =0;
void setup() {
  Serial.begin(115200);
   minute = int(30 * 60);
  led.off();
}

void loop() {
  count_time();
}

void count_time() {
  if (millis() - last_time >= period) {
    count++;
    Serial.print("Step :" + String(step) + " , ");
    if (step == 0) {
      // minute = 20;
      Serial.print("Second :" + String(count) + " , ");
      Serial.println("Minutes of seconds 1 :" + String(minute));
      if (count > minute) {
        count = 0;
        led.on();  // Alarm ON
        step = 1;
      }
    } else if (step == 1) {
      // 10 Sec
      Serial.print("Second :" + String(count) + " , ");
      Serial.println("Minutes of seconds 2 :" + String(10));
      if (count > 10) {
        count = 0;
        step = 0;
        led.off();  // Alarm ON
      }
    }

    last_time = millis();
  } else if (millis() < 1000) {
    last_time = millis();
  }
}
void isLED(bool state) {
  if (state) {
    Serial.println("LED ON");
  } else {
    Serial.println("LED OFF");
  }
}
