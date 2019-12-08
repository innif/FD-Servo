#define TIME 3000       //Wartezeit (in ms) vor dem öffnen der Schranke

#define OPEN 180        //Winkel der geöffneten Schranke (empfohlen 180)
#define CLOSED 80       //Winkel der geschlossenen Schranke (empfohlen 80)

#define OPEN_TIME 1000  //Zeit (in ms) für die die Schranke geöffnet bleibt (empfohlen 1000)

#define PIN_SERVO 13    //Pin an dem der Servo verbunden ist (aktuell 13)
#define PIN_SWITCH 22   //Pin an dem der Schalter verbunden ist (aktuell 22)


#include <ESP32Servo.h> 

Servo myservo;  

void setup(){
    myservo.attach(PIN_SERVO, 500, 2400); 
    myservo.write(CLOSED);      
    pinMode(PIN_SWITCH, INPUT_PULLUP); 
}

void loop() {
    if(!digitalRead(PIN_SWITCH)){
        delay(TIME);
        myservo.write(OPEN);
        delay(1000);
        myservo.write(CLOSED);
    }
}

