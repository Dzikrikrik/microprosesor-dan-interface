byte hijau = 11;
byte kuning = 12;
byte merah = 13;

bool bolehMenyebrang = false;

byte pinD1 = 0;
byte pinD2 = 1;

byte pinA = 3;
byte pinB = 4;
byte pinC = 5;
byte pinD = 6;
byte pinE = 7;
byte pinF = 8;
byte pinG = 9;

unsigned long lastCrossTime = 0; // To keep track of crossing time
const unsigned long interval = 10000; // Time between automatic crossings (10 seconds)

void setup() {
  pinMode(hijau, OUTPUT);
  pinMode(kuning, OUTPUT);
  pinMode(merah, OUTPUT);

  pinMode(pinD1, OUTPUT);
  pinMode(pinD2, OUTPUT);

  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
}

void loop() {
  // Check if it's time to cross
  if (millis() - lastCrossTime >= interval) {
    bolehMenyebrang = true;
    lastCrossTime = millis(); // Update last crossing time
  }

  if (bolehMenyebrang) {
    menyebrang();
    bolehMenyebrang = false; // Reset to wait for the next crossing time
  } else {
    hijauKedip();
  }
}

void hijauKedip(){
  digitalWrite(hijau, HIGH);
  delay(200);
  digitalWrite(hijau, LOW);
  delay(200);
}

void menyebrang(){
  digitalWrite(merah, LOW);
  digitalWrite(hijau, LOW);
  digitalWrite(kuning, HIGH);
  delay(2000);
  
  digitalWrite(merah, HIGH);
  digitalWrite(hijau, LOW);
  digitalWrite(kuning, LOW);
  
  // Countdown from 20 to 0
  for (int count = 20; count >= 0; count--) {
    displayCountdown(count);
  }

  digitalWrite(merah, LOW);
  digitalWrite(hijau, HIGH);
  delay(2000);

  digitalWrite(merah, LOW);
  digitalWrite(hijau, LOW);
  digitalWrite(kuning, LOW);
}

void displayCountdown(int count) {
  int tens = count / 10; // Get tens place
  int units = count % 10; // Get units place

  for (int n = 0; n < 500; n++) {
    digit2();
    setDisplay(tens);
    clear();
    digit1();
    setDisplay(units);
    clear();
  }
}

void setDisplay(int number) {
  switch (number) {
    case 0: angka0(); break;
    case 1: angka1(); break;
    case 2: angka2(); break;
    case 3: angka3(); break;
    case 4: angka4(); break;
    case 5: angka5(); break;
    case 6: angka6(); break;
    case 7: angka7(); break;
    case 8: angka8(); break;
    case 9: angka9(); break;
  }
}

void digit1() {
  digitalWrite(pinD1, HIGH);
  digitalWrite(pinD2, LOW);
}

void digit2() {
  digitalWrite(pinD1, LOW);
  digitalWrite(pinD2, HIGH);
}

void angka0() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
}

void angka1() {
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}

void angka2() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
}

void angka3() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
}

void angka4() {
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void angka5() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void angka6() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void angka7() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}

void angka8() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void angka9() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void clear() {
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
  delay(1);
}
