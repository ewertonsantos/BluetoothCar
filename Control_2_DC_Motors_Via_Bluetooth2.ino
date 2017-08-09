
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

      motor1.setSpeed(255); //Seleciona velocidade atual
      motor1.run(FORWARD);          //Movimenta motor no sentido horário
      motor4.setSpeed(255); //Seleciona velocidade atual
      motor4.run(FORWARD);          //Movimenta motor no sentido horário
      delay(10);
      stateStop=0;
    }
    
    // if the state is '2' the motor will turn left
    else if (state == 'B') {

        
      motor1.setSpeed(255); //Seleciona velocidade atual
      motor1.run(BACKWARD);          //Movimenta motor no sentido horário
      motor4.setSpeed(255); //Seleciona velocidade atual
      motor4.run(BACKWARD);          //Movimenta motor no sentido horário
      delay(10);
    }
    // if the state is '3' the motor will Stop
    else if (state == 'L' || stateStop == 1) {
         
      motor1.setSpeed(255); //Seleciona velocidade atual
      motor1.run(FORWARD);          //Movimenta motor no sentido horário
      motor4.setSpeed(255); //Seleciona velocidade atual
      motor4.run(BACKWARD);          //Movimenta motor no sentido horário
      delay(10);
    }
    // if the state is '4' the motor will turn right
    else if (state == 'R') {

      motor1.setSpeed(255); //Seleciona velocidade atual
      motor1.run(BACKWARD);          //Movimenta motor no sentido horário
      motor4.setSpeed(255); //Seleciona velocidade atual
      motor4.run(FORWARD);          //Movimenta motor no sentido horário
      delay(10);
    }
    else if (state == 'G'){

      motor1.setSpeed(255); //Seleciona velocidade atual
      motor1.run(FORWARD);          //Movimenta motor no sentido horário
      motor4.setSpeed(50); //Seleciona velocidade atual
      motor4.run(FORWARD);          //Movimenta motor no sentido horário
      delay(10);
    }
    else if (state == 'I'){

      motor1.setSpeed(50); //Seleciona velocidade atual
      motor1.run(FORWARD);          //Movimenta motor no sentido horário
      motor4.setSpeed(255); //Seleciona velocidade atual
      motor4.run(FORWARD);          //Movimenta motor no sentido horário
      delay(10);
    }
    else if (state == 'J'){

      motor1.setSpeed(255); //Seleciona velocidade atual
      motor1.run(BACKWARD);          //Movimenta motor no sentido horário
      motor4.setSpeed(50); //Seleciona velocidade atual
      motor4.run(BACKWARD);          //Movimenta motor no sentido horário
      delay(10);
    }
    else if (state == 'H'){

      motor1.setSpeed(50); //Seleciona velocidade atual
      motor1.run(BACKWARD);          //Movimenta motor no sentido horário
      motor4.setSpeed(255); //Seleciona velocidade atual
      motor4.run(BACKWARD);          //Movimenta motor no sentido horário
      delay(10);
    }
    else if (state == 'S' || stateStop == 1) {
      motor1.setSpeed(0); //Seleciona velocidade atual
      motor1.run(RELEASE);          //Movimenta motor no sentido horário
      motor4.setSpeed(0); //Seleciona velocidade atual
      motor4.run(RELEASE);          //Movimenta motor no sentido horário
        stateStop=0;
    }
    

}
