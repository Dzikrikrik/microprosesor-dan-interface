const byte numeral[11] = {
  B11111100, // 0
  B01100000, // 1
  B11011010, // 2
  B11110010, // 3
  B01100110, // 4
  B10110110, // 5
  B00111110, // 6
  B11100000, // 7
  B11111110, // 8
  B11100110, // 9
  //B00000000, //tidak menampilkan
};
const int segmentPins[8] = { 2, 11, 10, 5, 4, 3, 8, 9 }; //dp,g,f,e,d,c,b,a
void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}
void loop() {
  for (int i = 0; i <= 9; i++) {
    tampilAngka(i);
    delay(1000);
  }
  delay(500);
}
void tampilAngka (int number) {
  boolean isBitSet;
  for (int segment = 1; segment < 8; segment++) {
    isBitSet = bitRead(numeral[number], segment);
    digitalWrite(segmentPins[segment], isBitSet);
    digitalWrite(segmentPins[0], HIGH);
  }
}