const int REDPIN = 25;
const int BLUEPIN = 27;
const int GREENPIN = 4;

void setup() {
  pinMode(REDPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  Serial.begin(115200);
}

bool isHigh = false;

void loop() {
  // Cycle the RED LED
  analogWrite(BLUEPIN, 0);
  analogWrite(GREENPIN, 0);
  for (int i = 0; i <= 255; i++) {
    analogWrite(REDPIN, i);
    Serial.println(i);
    delay(10);
  }
  delay(1000);
  // Cycle the GREEN LED
  analogWrite(REDPIN, 0);
  analogWrite(BLUEPIN, 0);
  for (int i = 0; i <= 255; i++) {
    analogWrite(GREENPIN, i);
    Serial.println(i);
    delay(10);
  }
  delay(1000);
  // Cycle the BLUE LED
  analogWrite(REDPIN, 0);
  analogWrite(GREENPIN, 0);
  for (int i = 0; i <= 255; i++) {
    analogWrite(BLUEPIN, i);
    Serial.println(i);
    delay(10);
  }
  delay(1000);
  // Cycle all three LEDs
  for (int i = 0; i <= 255; i++) {
    analogWrite(REDPIN, i);
    analogWrite(GREENPIN, i);
    analogWrite(BLUEPIN, i);
    Serial.println(i);
    delay(10);
  }
  delay(1000);
}
