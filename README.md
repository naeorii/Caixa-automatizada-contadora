# 📦 Caixa Inteligente com Microcontrolador

Este projeto implementa uma **caixa inteligente automatizada** que detecta objetos usando um **sensor ultrassônico**, abre sua tampa com um **servo motor**, e exibe a **quantidade de objetos** em um **display LCD com interface I2C**. O sistema é controlado por um microcontrolador e pode ser utilizado para aplicações como coleta seletiva, organização de materiais ou controle de estoque simples.
A simulação foi feita utilizando o programa Tinkercad
## 🚀 Funcionalidades

- 📏 Detecção de objetos via **sensor ultrassônico (HC-SR04)**
- ⚙️ Abertura automática da tampa com **servo motor**
- 📟 Exibição da contagem de objetos em um **display LCD I2C**
- 🔁 Atualização contínua da leitura e resposta automática

## 🛠️ Componentes Utilizados

- Arduino Uno (ou similar)
- Sensor Ultrassônico **HC-SR04**
- Servo motor **SG90**
- Display LCD **16x2 com módulo I2C**
- Jumpers e Protoboard
- Fonte de alimentação (ou USB)
- (Opcional) Caixa impressa ou montada para simulação física

## 📚 Bibliotecas Utilizadas

- `LiquidCrystal_I2C.h` ou `LiquidCrystal_AIP31068_I2C.h` (dependendo do display)
- `Servo.h`

> ⚠️ Certifique-se de instalar as bibliotecas necessárias na IDE Arduino via **Gerenciador de Bibliotecas**.

## 💻 Código-fonte

O código principal segue a seguinte lógica:

1. Medição de distância com o sensor ultrassônico
2. Atualização da contagem de objetos detectados
3. Abertura automática da tampa com o servo motor
4. Exibição da contagem no LCD I2C


