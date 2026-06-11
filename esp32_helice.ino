#include <dummy.h>

#include <ESP32Servo.h>

// Defina o pino GPIO da ESP32 conectado ao fio de sinal do ESC
#define ESC_PIN 15
#define inp_pin 2
#define RXp2 16
#define TXp2 17

int signalState = 0;

Servo esc; // Cria um objeto servo para controlar o ESC

int velocidade = 0; // Variável para armazenar a velocidade (0 a 180)

void setup() {
  Serial.begin(115200);
  //Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2);
  // Anexa o objeto servo ao pino especificado. 
  // Configuramos os limites de pulso (em microssegundos) 
  // para garantir a faixa correta para o ESC.
  esc.attach(ESC_PIN, 1000, 2000); // Mín: 1000us (parado), Máx: 2000us (max vel)
  pinMode(inp_pin, INPUT);
  
  delay(1000);
  esc.write(velocidade);
  delay(1000);
}

void loop() {
    signalState = digitalRead(inp_pin);

    if(signalState == HIGH){
      if(velocidade == 80){
      }
      else{
        velocidade = 80;
        esc.write(velocidade);
      }
    }
    else{
      velocidade = 0;
      esc.write(velocidade);
    }

  delay(500);

}