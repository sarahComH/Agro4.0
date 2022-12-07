#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
int dado = 0; // variável que será tranmitida
void setup() {
  radio.begin();
  radio.openWritingPipe(address); // abrindo o caminho para a transmissão
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}
void loop() {
  
  dado++;
  radio.write(&dado, sizeof(dado)); // transmite o dado

  delay(1000);
}
