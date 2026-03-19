# B.R.I.S.A. 🌬️
**Bot de Reciclagem Inteligente e Saneamento do Ar**

O **B.R.I.S.A.** é um sistema automatizado de exaustão e monitoramento de qualidade do ar desenvolvido com Arduino. Projetado para operar dentro de uma câmara de acrílico, o bot detecta impurezas (fumaça, gases ou poeira) e aciona automaticamente um sistema de ventilação para purificar o ambiente interno.

## 🚀 Funcionalidades
- **Monitoramento em Tempo Real:** Sensor de qualidade do ar integrado.
- **Exaustão Automática:** Ativação de ventoinha assim que o limite de impurezas é atingido.
- **Interface Visual:** Display OLED SSD1306 exibindo níveis de poluição e status do sistema.
- **Segurança:** Mantém o ambiente controlado e livre de partículas nocivas.

## 🛠️ Hardware Utilizado
- **Microcontrolador:** Arduino Uno
- **Display:** OLED 128x64 Adafruit SSD1306 (I2C)
- **Sensor:** Sensor de Gás/Fumaça (Linha MQ)
- **Atuador:** Mini Ventilador (Cooler 5V/12V)
- **Controle:** Shield de expansão ou Módulo Relé
- **Estrutura:** Caixa de acrílico sob medida

## 💻 Requisitos de Software
Para compilar o projeto, você precisará das seguintes bibliotecas na sua IDE Arduino:
- `Adafruit_GFX`
- `Adafruit_SSD1306`
- `Wire` (Nativa)

## 🔧 Instalação e Uso
1. Clone este repositório:
   ```bash
   git clone [https://github.com/AndreGomesPeixoto/B.R.I.S.A..git](https://github.com/AndreGomesPeixoto/B.R.I.S.A..git)
