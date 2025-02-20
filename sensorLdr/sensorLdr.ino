// Pin definitions
const int ldrPin = A0;      // Pin untuk LDR
const int led1Pin = 2;      // Pin untuk LED 1
const int led2Pin = 3;      // Pin untuk LED 2
const int led3Pin = 4;      // Pin untuk LED 3

// Threshold untuk kegelapan
const int darknessThreshold = 200;  // Nilai ini bisa disesuaikan

void setup() {
  // Inisialisasi pin mode
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(ldrPin, INPUT);

  // Matikan LED saat awal
  digitalWrite(led1Pin, LOW);
  digitalWrite(led2Pin, LOW);
  digitalWrite(led3Pin, LOW);

  // Serial monitor untuk debugging
  Serial.begin(9600);
}

void loop() {
  // Baca nilai dari LDR
  int ldrValue = analogRead(ldrPin);

  // Tampilkan nilai LDR ke Serial Monitor
  Serial.println(ldrValue);

  // Cek jika nilai LDR di bawah threshold (kegelapan)
  if (ldrValue < darknessThreshold) {
    // Nyalakan LED
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, LOW);
  } else {
    // Matikan LED
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, HIGH);
    digitalWrite(led3Pin, HIGH);
  }

  // Jeda sebentar sebelum membaca lagi
  delay(100);
}