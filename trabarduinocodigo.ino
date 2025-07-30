#include <Adafruit_LiquidCrystal.h>
#include <LiquidCrystal.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servo;

const int trigPin = 8;
const int echoPin = 9;
const int servoPin = 6;

int itemCount = 0;
bool caixaAberta = false;  // variável para saber se a caixa está aberta

void setup() {
  servo.write(0); // Caixa fechada inicialmente
  Serial.begin(9600);
  lcd.init();
  servo.attach(servoPin);
  delay(200);         // estabiliza o servo
  servo.write(0); // Caixa fechada inicialmente
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.setCursor(0, 0);
  lcd.print("Itens: 0");
}
void abrirCaixa() {
  servo.write(90); // abrir
  delay(500);
}

void fecharCaixa() {
  servo.write(0); // fechar
  delay(500);
}

void loop() {
  long duration;
  int distance;

  digitalWrite(trigPin, LOW); delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH, 30000); // 30 milissegundos (timeout)
  distance = duration * 0.034 / 2;

  if (distance > 5 && distance < 100) {
    // Se detectar objeto e a caixa estiver fechada, abre
    if (!caixaAberta) {
      abrirCaixa();
      caixaAberta = true;
      itemCount++;
      lcd.setCursor(0, 0);
      lcd.print("Itens: ");
      lcd.print(itemCount);
      Serial.print("Distancia: ");
      Serial.println(distance);
    }
  } else {
    // Se não detectar objeto e a caixa estiver aberta, fecha
    if (caixaAberta) {
      delay(1000);
      fecharCaixa();
      caixaAberta = false;
    }
  }

  delay(100);
}

