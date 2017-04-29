#include <IRremote.h>
#include <IRremoteInt.h>

const int RECEIVER_PIN = 2;

int greenLED = 5;
int redLED = 6;
int yellowLED = 7;

IRrecv ir_reciever(RECEIVER_PIN);
decode_results codes_recieved;

void setup() {
  Serial.begin(9600);
  ir_reciever.enableIRIn(); //starts the reception

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
}

void loop() {
  if (ir_reciever.decode(&codes_recieved)) {
    if (codes_recieved.value != 0) {
      Serial.println(codes_recieved.value, HEX);
    }
  }
  //////////////////////////////////////////////////////////////////////////

  //turn on yellow led
  if (codes_recieved.value == 0xFF30CF) { //Number 1
    digitalWrite(yellowLED, HIGH);
    delay(500);
  }
  if (codes_recieved.value == 0xFF10EF) { //Number 4
    digitalWrite(yellowLED, LOW);
    delay(500);
  }


  //turn on red led
  if (codes_recieved.value == 0xFF7A85) { //Number 2
    digitalWrite(greenLED, HIGH);
    delay(500);
  }
  if (codes_recieved.value == 0xFF5AA5) { //Number 5
    digitalWrite(greenLED, LOW);
    delay(500);
  }

  //turn on green led
  if (codes_recieved.value == 0xFF18E7) { //Number 3
    digitalWrite(redLED, HIGH);
    delay(500);
  }
  if (codes_recieved.value == 0xFF38C7) { //Number 6
    digitalWrite(redLED, LOW);
    delay(500);
  }

  ir_reciever.resume(); //recieves next code
  delay(200);
  codes_recieved.value = 0;
}
