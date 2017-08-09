
#include <AFMotor.h> //Inclui biblioteca AF Motor

AF_DCMotor motor1(1); //Seleção do Motor 1
AF_DCMotor motor4(4); //Seleção do Motor 2
int state;
int stateStop=0;
void setup() {
  
    // initialize serial communication at 9600 bits per second:
    Serial3.begin(9600);
}

void loop() {
    //if some date is sent, reads it and saves in state
    if(Serial3.available() > 0){     
      state = Serial3.read();   
    }   
    // if the state is '1' the DC motor will go forward
    if (state == 'F') {

        analogWrite(enable1Pin, 255);
        analogWrite(enable2Pin, 255);
        digitalWrite(motor1Pin1, HIGH);
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        delay(10);
    }
    
    // if the state is '2' the motor will turn left
    else if (state == 'R') {

        analogWrite(enable1Pin, 255);
        analogWrite(enable2Pin, 255);
        digitalWrite(motor1Pin1, HIGH); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        delay(10);
    }
    // if the state is '3' the motor will Stop
    else if (state == 'S' || stateStop == 1) {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        stateStop=0;
    }
    // if the state is '4' the motor will turn right
    else if (state == 'L') {

        analogWrite(enable1Pin, 255);
        analogWrite(enable2Pin, 255);
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, HIGH); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        delay(10);
    }
    // if the state is '5' the motor will Reverse
    else if (state == 'B') {

        analogWrite(enable1Pin, 255);
        analogWrite(enable2Pin, 255);
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, HIGH);
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        delay(10);
    }
    else if (state == 'G'){

        analogWrite(enable1Pin, 82);
        analogWrite(enable2Pin, 255);
        digitalWrite(motor1Pin1, HIGH);
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        delay(10);
    }
    else if (state == 'I'){

        analogWrite(enable1Pin, 255);
        analogWrite(enable2Pin, 82);
        digitalWrite(motor1Pin1, HIGH);
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        delay(10);
    }
    else if (state == 'H'){

        analogWrite(enable1Pin, 82);
        analogWrite(enable2Pin, 255);
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, HIGH); 
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        delay(10);
    }
    else if (state == 'J'){

        analogWrite(enable1Pin, 255);
        analogWrite(enable2Pin, 82);
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, HIGH); 
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        delay(10);
    }
    //For debugging purpose
    //Serial.println(state);
}
