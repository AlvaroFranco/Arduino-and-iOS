#include "etherShield.h"
#include "ETHER_28J60.h"

static uint8_t mac[6] = {0x54,0x55,0x58,0x10,0x00,0x24};
static uint8_t ip[4] = {192,168,2,15};
static uint16_t port = 80; 

String led_status = "0";
String shown_text = "";

ETHER_28J60 ethernet;
int led1 = 3;
int led2 = 4;
int led3 = 5;
int led4 = 6;
int led5 = 7;
int led6 = 8;
int led7 = 9;

void setup() {
  
    ethernet.setup(mac, ip, port);
    Serial.begin(9600);
    
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
}

void loop() {
  
  String param;
  if (param = ethernet.serviceRequest())
  {
    String temp_param = param.substring(0,1);
    String temp_string = param.substring(2);
    if ((temp_param=="0")||(temp_param=="1")){
      led_status = temp_param;
      shown_text = temp_string;
    }
    if (led_status=="1"){
        ethernet.print("ON");
        if (shown_text == "") {

        } else {
           char buf[shown_text.length()];
           shown_text.toCharArray(buf,shown_text.length());
           double WVal=atof(buf); 
           Serial.println(WVal);
           
           if (WVal > 0.01 && WVal < 0.11) {
             
               digitalWrite(3, HIGH);
               digitalWrite(4, LOW);
               digitalWrite(5, LOW); 
               digitalWrite(6, LOW);
               digitalWrite(7, LOW);
               digitalWrite(8, LOW);
               digitalWrite(9, LOW);
           } else if (WVal > 0.11 && WVal < 0.25){
             
               digitalWrite(3, HIGH);
               digitalWrite(4, HIGH);
               digitalWrite(5, LOW); 
               digitalWrite(6, LOW);
               digitalWrite(7, LOW);
               digitalWrite(8, LOW);
               digitalWrite(9, LOW);
        } else if (WVal > 0.25 && WVal < 0.35){
               
               digitalWrite(3, HIGH);
               digitalWrite(4, HIGH);
               digitalWrite(5, HIGH); 
               digitalWrite(6, LOW);
               digitalWrite(7, LOW);
               digitalWrite(8, LOW);
               digitalWrite(9, LOW);
        } else if (WVal > 0.35 && WVal < 0.5){
          
               digitalWrite(3, HIGH);
               digitalWrite(4, HIGH);
               digitalWrite(5, HIGH); 
               digitalWrite(6, HIGH);
               digitalWrite(7, LOW);
               digitalWrite(8, LOW);
               digitalWrite(9, LOW);

        } else if (WVal > 0.5 && WVal < 0.75){
          
               digitalWrite(3, HIGH);
               digitalWrite(4, HIGH);
               digitalWrite(5, HIGH); 
               digitalWrite(6, HIGH);
               digitalWrite(7, HIGH);
               digitalWrite(8, LOW);
               digitalWrite(9, LOW);

        } else if (WVal > 0.75 && WVal < 0.9){
          
               digitalWrite(3, HIGH);
               digitalWrite(4, HIGH);
               digitalWrite(5, HIGH); 
               digitalWrite(6, HIGH);
               digitalWrite(7, HIGH);
               digitalWrite(8, HIGH);
               digitalWrite(9, LOW);

        } else if (WVal > 0.9 && WVal < 1){
          
               digitalWrite(3, HIGH);
               digitalWrite(4, HIGH);
               digitalWrite(5, HIGH); 
               digitalWrite(6, HIGH);
               digitalWrite(7, HIGH);
               digitalWrite(8, HIGH);
               digitalWrite(9, HIGH);
        }

        }

    }
    
    ethernet.respond();
    delay(100);
  }
}
