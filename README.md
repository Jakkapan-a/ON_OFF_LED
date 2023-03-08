<!-- Example Code Arduino -->
## Example Code Arduino

```c++ 

const int led1 = 23;          // Rely 1
const int led2 = 16;          // Alarm
unsigned long period = 1000;  // 1 seconds
unsigned long last_time = 0;
bool state_led = true;
int count = 0;
int step = 0;
void setup() {
  Serial.begin(115200);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  step = 0;
  count = 0;
  // TEST
  // count = 1790;
}
void timer() {
  if (millis() - last_time > period) {
    // Count seconds and switch step 0 or 1
    // step 0 = ON LED 1 and OFF Alarm
    // step 1 = OFF LED 1 and ON Alarm
    // And reset count to 0 after 30 minutes or 10 seconds
    count++;
    Serial.print("STEP :" + String(step) + " , ");
    if (step == 0) {
      // 30 minutes = 30 * 60 = 1800 seconds
      // IF count > 1800 seconds THEN step = 1
      // ELSE ON LED 1 and OFF Alarm
      // And reset count
      int minute = int(30 * 60);
      Serial.print("Second :" + String(count) + " , ");
      Serial.println("Minutes of seconds :" + String(minute));
      if (count >= minute) {
        count = 0;
        step = 1;
      } else {
        digitalWrite(led1, HIGH);  // ON LED 1
        digitalWrite(led2, LOW);   // OFF Alarm
      }

    } else if (step == 1) {
      // 10 minutes = 10 * 60 = 600 seconds
      // IF count > 600 seconds THEN step = 0
      // ELSE OFF LED 1 and ON Alarm
      // And reset count
      Serial.print("Second :" + String(count) + " , ");
      Serial.println("Seconds 2 :" + String(10));
      if (count >= 10) {
        count = 0;
        step = 0;
      } else {
        digitalWrite(led1, LOW);   // OFF LED 1
        digitalWrite(led2, HIGH);  // ON Alarm
      }
    }
    last_time = millis();
  } else if (millis() < 1000) {
    last_time = millis();
  }
}
void loop() {
  timer();
}
```
