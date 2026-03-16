// bit 7 (pino 2) = MSB,  bit 0 (pino 9) = LSB
const int pinosSaida[8] = {2, 3, 4, 5, 6, 7, 8, 9};

String inputBuffer = "";  // guarda o que o usuário digita até apertar Enter
int numeroA = -1;         // -1 significa "ainda não foi digitado"
int numeroB = -1;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 8; i++) {
    pinMode(pinosSaida[i], OUTPUT);
    digitalWrite(pinosSaida[i], LOW); // começa tudo apagado
  }
  Serial.println("=== SOMADOR DE 7 BITS ===");
  Serial.println("Digite o numero A (0 a 127) e pressione Enter:");
}

// Acende os LEDs de acordo com os bits do valor
void exibirBinario(int valor) {
  for (int i = 0; i < 8; i++) {
    // bit 7 fica no pino 2, bit 0 fica no pino 9
    int bit = (valor >> (7 - i)) & 1;
    digitalWrite(pinosSaida[i], bit ? HIGH : LOW);
  }
}

// Imprime os bits no Serial
void imprimirBinario(int valor, int qtdBits) {
  for (int i = qtdBits - 1; i >= 0; i--) {
    Serial.print((valor >> i) & 1);
  }
}

void loop() {
  // Lê caractere por caractere até receber o Enter (\n)
  while (Serial.available()) {
    char c = Serial.read();

    if (c == '\n' || c == '\r') {
      // Enter pressionado — processa o que foi digitado
      inputBuffer.trim(); // remove espaços extras

      if (inputBuffer.length() == 0) return; // linha vazia, ignora

      int valor = inputBuffer.toInt();
      inputBuffer = ""; // limpa o buffer para a próxima entrada

      if (valor < 0 || valor > 127) {
        Serial.println("Erro! Use apenas valores entre 0 e 127.");
        return;
      }

      if (numeroA == -1) {
        // Ainda não temos o número A
        numeroA = valor;
        Serial.print("A = ");
        Serial.print(numeroA);
        Serial.print("  →  binario: ");
        imprimirBinario(numeroA, 7);
        Serial.println();
        Serial.println("Agora digite o numero B (0 a 127):");

      } else {
        // Já temos A, agora recebemos B
        numeroB = valor;
        int soma = numeroA + numeroB;

        Serial.println("─────────────────────────");
        Serial.print("A     = "); Serial.print(numeroA);
        Serial.print("  →  "); imprimirBinario(numeroA, 7); Serial.println();

        Serial.print("B     = "); Serial.print(numeroB);
        Serial.print("  →  "); imprimirBinario(numeroB, 7); Serial.println();

        Serial.print("A + B = "); Serial.print(soma);
        Serial.print("  →  "); imprimirBinario(soma, 8); Serial.println();

        if (soma > 127) {
          Serial.println(">> Carry! O bit 7 (LED vermelho) acendeu.");
        }
        Serial.println("─────────────────────────");

        exibirBinario(soma);

        // Reseta para nova operação
        numeroA = -1;
        numeroB = -1;
        Serial.println("Digite novo A:");
      }

    } else {
      // Ainda digitando — acumula o caractere no buffer
      inputBuffer += c;
    }
  }
}