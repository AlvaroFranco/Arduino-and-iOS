#include "etherShield.h"
#include "ETHER_28J60.h"
 
static uint8_t mac[6] = {0x54,0x55,0x58,0x10,0x00,0x24};
static uint8_t ip[4] = {192,168,2,15}; // Ponemos un IP que le asignemos al Arduino. IMPORTANTE: No puede coincidir con otra ya usada en nuestra red
static uint16_t port = 80;
 
ETHER_28J60 ethernet;
 
int led = 7; // Ponemos el pin en el que tenemos nuestro LED
 
void setup() {
 
  ethernet.setup(mac, ip, port);
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}
 
void loop() {
 
  char* params;
  if (params = ethernet.serviceRequest()){
 
    if (strcmp(params, "0") == 0){
 
      digitalWrite(led, LOW); // Ponemos que en caso de que se haga un HTTP Request a 192.168.2.15/0 se apague el LED
    }else if (strcmp(params, "1") == 0){
 
      digitalWrite(led, HIGH); // Ponemos que en caso de que se haga un HTTP Request a 192.168.2.15/1 se encienda el LED
    }
 
    ethernet.respond();
  }
}
