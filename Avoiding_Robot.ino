
// Deklarasi
const int enLM = 5; // pin enable motor kiri
const int lm1 = 6; // pin motor kiri maju
const int lm2 = 7; // pin motor kiri mundur
const int rm1 = 8; // pin motor kanan maju
const int rm2 = 9; // pin motor kanan mundur
const int enRM = 10; // pin enable motor kanan

int M1_speed = 200;
int M2_speed = 200;
int LeftRotationSpeed = 200;
int RightRotationSpeed =200;

int Lsr = 0;
int Rsr = 0;

void setup() {
  // put your setup code here, to run once:

  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);

  pinMode(enLM,OUTPUT);
  pinMode(enRM,OUTPUT);

  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  
Stop();
}

 

void loop() {
  // put your main code here, to run repeatedly:

  Lsr = analogRead(A0);
  Rsr = analogRead(A1);


 if (Lsr > 600 && Rsr > 600) {
   Maju();
 }
 else if (Lsr < 600 && Rsr > 600)  {
   Mundur();
   delay(500);
   belokKanan();
    delay(500);
 }
 else if (Lsr > 600 && Rsr < 600) {
   Mundur();
   delay(500);
    belokKiri();
    delay(500);
  }
 else if (Lsr < 600 && Rsr < 600)  {
   Mundur();
    delay(500);
   belokKiri();
    delay(1000);
 }
  delay(100);

}

void Maju() {

  digitalWrite(lm1, HIGH);
  digitalWrite(lm2, LOW);
  digitalWrite(rm1, HIGH);
  digitalWrite(rm2, LOW);
  analogWrite(enLM, M1_speed);
  analogWrite(enRM, M2_speed);
}

void Mundur() {

  digitalWrite(lm1, LOW);
  digitalWrite(lm2, HIGH);
  digitalWrite(rm1, LOW);
  digitalWrite(rm2, HIGH);
  analogWrite(enLM, M1_speed);
  analogWrite(enRM, M2_speed);

}
  
void Stop() {

  digitalWrite(lm1, LOW);
  digitalWrite(lm2, LOW);
  digitalWrite(rm1, LOW);
  digitalWrite(rm2, LOW);

}

void belokKanan() {

  digitalWrite(lm1, LOW);
  digitalWrite(lm2, HIGH);
  digitalWrite(rm1, HIGH);
  digitalWrite(rm2, LOW);
  analogWrite(enLM, LeftRotationSpeed);
  analogWrite(enRM, RightRotationSpeed);

}

void belokKiri() {

  digitalWrite(lm1, HIGH);
  digitalWrite(lm2, LOW);
  digitalWrite(rm1, LOW);
  digitalWrite(rm2, HIGH);
  analogWrite(enLM, LeftRotationSpeed);
  analogWrite(enRM, RightRotationSpeed);

}
