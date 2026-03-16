# Semin-rio_ArduinoUno_Sistemas_digitais

Seminário da matéria sistemas digitais sobre o arduino uno

# Arduino UNO — Somador de 8 bits

**Seminário — Grupo I | Sistemas Digitais 2026**

Projeto que utiliza o Arduino UNO para somar dois números binários de 7 bits (0 a 127) e exibir o resultado de 8 bits em LEDs físicos.

---

## Como funciona

1. O usuário digita dois números (entre 0 e 127) pelo Monitor Serial
2. O Arduino soma os dois valores
3. O resultado aparece nos **8 LEDs** conectados aos pinos 2–9, em binário
4. Se o resultado ultrapassar 127, o **LED vermelho** (pino 2) acende — indicando o carry bit

---

## Arquivos do projeto

| Arquivo                               | Descrição                                |
| ------------------------------------- | ---------------------------------------- |
| `wokwi/sketch.ino`                    | Código C++ do Arduino                    |
| `wokwi/diagram.json`                  | Diagrama do circuito (LEDs + resistores) |
| `docs/Relatorio_Arduino_Somador.docx` | Relatório completo do seminário          |

---

## Simulador online (Wokwi)

Acesse o simulador sem precisar de hardware físico:

🔗 **https://wokwi.com/projects/new/arduino-uno**

**Como usar:**

1. Abra o link acima
2. Cole o conteúdo de `wokwi/sketch.ino` na aba `sketch.ino`
3. Cole o conteúdo de `wokwi/diagram.json` na aba `diagram.json`
4. Clique em **▶ Play**
5. Abra o **Monitor Serial** e digite um número de 0 a 127, pressione Enter
6. Digite o segundo número e pressione Enter
7. Observe os LEDs acendendo com o resultado em binário

---

## Mapeamento dos pinos

```
Pino 2  → bit 7 (MSB) → LED VERMELHO (carry bit)
Pino 3  → bit 6       → LED VERDE
Pino 4  → bit 5       → LED VERDE
Pino 5  → bit 4       → LED VERDE
Pino 6  → bit 3       → LED VERDE
Pino 7  → bit 2       → LED VERDE
Pino 8  → bit 1       → LED VERDE
Pino 9  → bit 0 (LSB) → LED VERDE
```

---

## Por que máximo 127?

Com **7 bits** só é possível representar valores de 0 a 127.  
A soma máxima é `127 + 127 = 254`, que cabe em 8 bits — exatamente a quantidade de LEDs do circuito.

---

## Tecnologias

- Arduino UNO (ATmega328P)
- C++ (linguagem Arduino)
- Wokwi (simulador online)
