/********************************-******************
  Aperte os botões para ver o servo motor se mover em
  direções diferentes.

  Desenvolvido por Letícia P Garcez - 03/2023
 ****************************************************/

#include <Servo.h>
#include <laboratorioFW_ARDUNO.h>

#define motor B_5
#define btnEsquerda A_4
#define btnDireita A_7

Servo meuServo;

int angulo = 0;

void setup() {
  meuServo.attach(motor);
  meuServo.write(0);
  pinMode(btnEsquerda, INPUT);
  pinMode(btnDireita, INPUT);
}

void loop() {
  if (digitalRead(btnEsquerda)) {
    angulo += 10;
  }
  else if (digitalRead(btnDireita)) {
    angulo -= 10;
  }
  angulo = angulo % 180;
  meuServo.write(angulo);
  delay(25);//delay
}
