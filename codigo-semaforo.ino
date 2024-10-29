// Classe para representar o semáforo
class Semaforo {
  int vermelho;
  int amarelo;
  int verde;

public:
  // Construtor para inicializar as portas
  Semaforo(int p_vermelho, int p_amarelo, int p_verde) {
    vermelho = p_vermelho;
    amarelo = p_amarelo;
    verde = p_verde;
  }

  // Método para configurar as portas
  void configurar() {
    pinMode(vermelho, OUTPUT);
    pinMode(amarelo, OUTPUT);
    pinMode(verde, OUTPUT);
  }

  // Método para definir o sinal no vermelho
  void sinalVermelho() {
    digitalWrite(vermelho, HIGH);
    digitalWrite(amarelo, LOW);
    digitalWrite(verde, LOW);
  }

  // Método para definir o sinal no amarelo
  void sinalAmarelo() {
    digitalWrite(vermelho, LOW);
    digitalWrite(amarelo, HIGH);
    digitalWrite(verde, LOW);
  }

  // Método para definir o sinal no verde
  void sinalVerde() {
    digitalWrite(vermelho, LOW);
    digitalWrite(amarelo, LOW);
    digitalWrite(verde, HIGH);
  }
};

// Instanciando o semáforo
Semaforo semaforo(10, 9, 8);

void setup() {
  semaforo.configurar();  // Aciona a função de configuração das portas do semáforo
}

void loop() {
  semaforo.sinalVermelho();
  delay(6000);

  semaforo.sinalAmarelo();
  delay(2000);

  semaforo.sinalVerde();
  delay(2000);
  delay(2000);

  semaforo.sinalAmarelo();
  delay(2000);
}
