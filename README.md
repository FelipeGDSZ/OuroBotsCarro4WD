# OuroBotsCarro4WD
Códigos usados na programação de um carrinho 4WD autônomo. O projeto envolveu a estruturação do hardware e o mapeamento preciso de pinos lógicos (D7, D8) para o controle dos motores nas entradas do driver.

# Robô 4WD com Propulsão Híbrida (Arduino + ESP32)

Este repositório contém o firmware para um robô móvel 4WD com processamento distribuído. O projeto utiliza um Arduino para o controle de tração (motores DC via driver) e um ESP32 para o sistema de propulsão aerodinâmica.

[Demonstração do Robô] 
(https://github.com/user-attachments/assets/7b8af6a2-6e2f-4f4c-ba3e-244bdfb9dd35)

## Tecnologias e Hardware
* **Linguagem:** C++
* **Microcontroladores:** Arduino Uno e ESP32
* **Componentes:**
  * Driver de Motor Ponte H (L293D)
  * 4 Motores DC
  * 1 Motor Brushless + ESC (Electronic Speed Controller)
  * Módulo de Comunicação Bluetooth (HC-05)

## Arquitetura e Mapeamento de Pinos

O sistema foi dividido para otimizar o processamento e a geração de sinais PWM entre as duas placas:

### 1. Tração (Arduino)
Responsável por receber comandos via Comunicação Serial a 9600 bps e acionar as rodas.
* **Mapeamento do Driver:** O projeto possui uma configuração física específica onde o pino **D8 do Arduino está conectado à Entrada 4 (IN4)** do driver, e o **D7 está conectado à Entrada 3 (IN3)**.
* **Pinos de Controle (Motores):** `D2`, `D4`, `D7`, `D8`.
* **Pino Auxiliar:** `D12` (acionamento extra via comandos `X`, `x` e `Y`).

### 2. Propulsão (ESP32)
Responsável pelo controle da hélice utilizando a biblioteca `ESP32Servo` para gerar sinais precisos.
* **Pino de Sinal do ESC:** `GPIO 15` (Sinal PWM de 1000us para parado e 2000us para velocidade máxima).
* **Pino de Leitura (Gatilho):** `GPIO 2` (Lê o estado digital para acionamento dinâmico da hélice).

Como Funciona

1. **Movimentação (Arduino):** A placa monitora o buffer serial. Ao receber caracteres específicos, o `switch-case` altera o estado dos pinos digitais:
   * `F` (Frente): Aciona os motores para avançar.
   * `B` (Trás): Inverte o sentido dos motores.
   * `R` (Direita) e `L` (Esquerda): Ativa os lados opostos para rotacionar o chassi.
   * `S` (Stop) ou padrão: Chama a função `stop()`, que zera todas as saídas lógicas e garante a parada total do robô.
   * `X` / `x` / `Y`: Controlam o pino auxiliar `D12`.

2. **Hélice (ESP32):** Monitora constantemente a entrada digital no `GPIO 2`. Quando o sinal muda para `HIGH`, o firmware atualiza a velocidade do ESC para o valor `80`, ativando a propulsão da hélice. Quando o sinal retorna para `LOW`, a velocidade é zerada imediatamente.

## Galeria do Projeto

<img width="660" height="980" alt="WhatsApp Image 2025-12-05 at 4 15 06 PM" src="https://github.com/user-attachments/assets/87229aa2-eaa3-4039-bb9f-661f7fbb4081" />
<img width="900" height="1300" alt="WhatsApp Image 2025-12-05 at 4 15 01 PM" src="https://github.com/user-attachments/assets/9172f2a8-2260-4c43-8f9d-10fb507837eb" />
<img width="900" height="1300" alt="WhatsApp Image 2025-12-05 at 4 15 00 PM" src="https://github.com/user-attachments/assets/3e5d3811-5bab-4ac4-bf13-8b251490344e" />



Como rodar este projeto

1. Clone este repositório:
   ```bash
   git clone [https://github.com/FelipeGDSZ/OuroBotsCarro4WD](https://github.com/FelipeGDSZ/OuroBotsCarro4WD)

2. Abra o arquivo arduino_tracao.ino na Arduino IDE, selecione a placa correspondente e faça o upload do código de movimentação.

3. Abra o arquivo esp32_helice.ino na Arduino IDE (certifique-se de ter o pacote do ESP32 e a biblioteca ESP32Servo instalados) e faça o upload do código de propulsão.

4. Conecte o hardware seguindo o mapeamento de pinos descrito e envie os comandos através do Monitor Serial ou interface Bluetooth configurada.

