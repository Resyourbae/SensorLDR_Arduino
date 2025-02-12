// Pin definitions
const int ldrPin = A0;       // Pin untuk LDR
const int buzzerPin = 3;     // Pin untuk buzzer
const int ledPin1 = 10;       // Pin untuk LED 1
const int ledPin2 = 9;       // Pin untuk LED 2
const int ledPin3 = 8;       // Pin untuk LED 3

// Threshold untuk mendeteksi gelap (sesuaikan dengan kebutuhan)
const int darkThreshold = 500;  // Nilai analog saat gelap

void setup() {
  // Inisialisasi pin sebagai input/output
  pinMode(ldrPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  // Matikan buzzer dan LED saat awal
  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);

  // Mulai komunikasi serial dengan baud rate 9600
  Serial.begin(9600);
}

void loop() {
  // Baca nilai dari sensor LDR
  int ldrValue = analogRead(ldrPin);

  // Cek apakah kondisi gelap
  if (ldrValue > darkThreshold) {
    // Jika gelap, nyalakan buzzer dan LED
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
  } else {
    // Jika terang, matikan buzzer dan LED
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
  }

  // Delay untuk stabilisasi
  delay(100);
}