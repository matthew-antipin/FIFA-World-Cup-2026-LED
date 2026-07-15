const int red1 = 3; // strip 1
const int green1 = 5;
const int blue1 = 6;
const int red2 = 9; // strip 2
const int green2 = 10;
const int blue2 = 11;

void setStrip1(byte r, byte g, byte b) {
  analogWrite(red1, r);
  analogWrite(green1, g);
  analogWrite(blue1, b);
}

void setStrip2(byte r, byte g, byte b) {
  analogWrite(red2, r);
  analogWrite(green2, g);
  analogWrite(blue2, b);
}

void mexGoal() {
  for (int i = 0; i <= 90; i++) { // strobe light green lol
    setStrip1(0,200,0);
    setStrip2(0,200,0);
    delay(100);
    setStrip1(0,0,0);
    setStrip2(0,0,0);
    delay(100);
  }
  for (int i = 0; i <= 15; i++) { // has the two strips alternate between red and green
    setStrip1(200,0,0); // red
    setStrip2(0,200,0); // green
    delay(700);
    setStrip1(0,200,0); // green
    setStrip2(200,0,0); // red
    delay(700);
  }
  for (int i = 0; i <= 15; i++) { // has the two strips "cycle" through green, white and red.
    setStrip1(0,200,0); // green
    setStrip2(150,150,150); // white
    delay(500);
    setStrip1(150,150,150); // white
    setStrip2(200,0,0); // red
    delay(500);
    setStrip1(200,0,0); // red
    setStrip2(0,200,0); // green
    delay(500);
  }
  setStrip1(0,0,0);
  setStrip2(0,0,0);
}

void canGoal() {
  for (int i = 0; i <= 90; i++) { // strobe light red lol
    setStrip1(2000,0,0);
    setStrip2(200,0,0);
    delay(100);
    setStrip1(0,0,0);
    setStrip2(0,0,0);
    delay(100);
  }
  for (int i = 0; i <= 45; i++) { // has the two strips alternate between red and white
    setStrip1(200,0,0); // red
    setStrip2(150,150,150); // white
    delay(1000);
    setStrip1(150,150,150); // white
    setStrip2(200,0,0); // red
    delay(1000);
  }
  setStrip1(0,0,0);
  setStrip2(0,0,0);
}

void mexPenGoal() {
  for (int i = 0; i <= 20; i++) {
    setStrip1(0,200,0); // green
    setStrip2(0,0,0); // off
    delay(100);
    setStrip1(0,0,0); // green
    setStrip2(0,200,0); // off
    delay(100);
  }
  for (int i = 0; i <= 15; i++) { // has the two strips "cycle" through green, white and red.
        setStrip1(0,200,0); // green
        setStrip2(150,150,150); // white
        delay(500);
        setStrip1(150,150,150); // white
        setStrip2(200,0,0); // red
        delay(500);
        setStrip1(200,0,0); // red
        setStrip2(0,200,0); // green
        delay(500);
  }
  setStrip1(0,0,0);
  setStrip2(0,0,0);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(red1, OUTPUT);  // set output pins for all PWM controlling LED channels
  pinMode(green1, OUTPUT);
  pinMode(blue1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(blue2, OUTPUT);
  Serial.println("Arduino connected and ready to go!");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    command.trim(); // removes newline and spaces

    if (command == "MEXICO") {
      Serial.println("GOAL MEXICO");
      mexGoal();
    }
    else if (command == "CANADA") {
      Serial.println("GOAL CANADA");
      canGoal();
    }
    else if (command == "penMEXICO") {
      Serial.println("PENALTY GOAL MEXICO");
      mexPenGoal();
    }
    else if (command == "setCAN") {
      Serial.println("Setting lighting to Canada...");
      setStrip1(200,0,0);
      setStrip2(200,0,0);
    }
    else if (command == "setMEX") {
      Serial.println("Setting lighting to Mexico...");
      setStrip1(0,200,0);
      setStrip2(0,200,0);
    }
    else if (command == "OFF") {
      Serial.println("Turning all strips off...");
      setStrip1(0,0,0);
      setStrip2(0,0,0);
    }
  }
}