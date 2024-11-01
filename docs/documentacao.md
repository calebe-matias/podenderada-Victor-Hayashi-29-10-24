# Ponderada do Semáforo
## Foto da Montagem Física
> ![Montagem Física](../assets/semaforo-hayashi.jpg)
## Relato: Como foi feita a montagem ?
&emsp;&emsp; Para montar a ponderada do Semáforo, realizei a conexão do polo negativo de cada LED com o GND do Arduino e cada polo positivo a um resistor de 10 kΩ, que por sua vez conectei a um pino digital do Arduino (verde, amarelo e vermelho respectivamente aos pinos 8, 9 e 10). Para a temporização, utilizei a função ```delay()```, a qual controlou o tempo de cada fase do semáforo. Como "ir além", utilizei a orientação a objetos para criar uma classe ```class Semaforo``` que permite instanciar um objeto que contém os métodos para ligar cada cor e para configurar os pinos digitais do Arduíno.

## Vídeo demonstrando o funcionamento do Semáforo
<video controls src="../assets/semaforo-hayashi-video.mp4" title="Vídeo da Ponderada do Semáforo Funcionando"></video>

## Código da programação do Semáforo

```cpp
// ../codigo-semaforo.ino

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
```

# Tabela de Componentes
| Componente | Quantidade | Descrição |
|------------|------------|-----------|
| Arduino Uno | 1 | Placa de desenvolvimento |
| LED Vermelho | 1 | LED vermelho de alto brilho |
| LED Amarelo | 1 | LED amarelo de alto brilho |
| LED Verde | 1 | LED verde de alto brilho |
| Resistor 10 kΩ | 3 | Resistor de 10 kΩ |
| Protoboard | 1 | Protoboard de 830 pontos |
| Jumpers | 8 | Jumpers macho-macho |
