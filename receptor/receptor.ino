#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";

void setup() {
  Serial.begin(9600); // abrindo o monitor serial para visualizarmos a recepção da informação
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  if (radio.available()) { // se tiver algum dado sendo transmitido...
    int dado = 0;
    radio.read(&dado, sizeof(dado)); // vai ler o dado
    Serial.println(dado);
  }
}
