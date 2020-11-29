//Program for line following robot using arduino uno

#include<NewPing.h>

NewPing sonar(A1,A2,200);

#define a 5 
#define b 4 
#define c 3 
#define d 2 

#define el 9 
#define er 10

#define irl A3 
#define irr A4 

void fwd(){             //function for moving forward
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
}

void stp(){            //function to stop 
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
}
void hright(){         //function to turn right
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
}
void hleft(){          //function to turn left
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
}

void setup() {
  pinMode(a, OUTPUT);  //left motor output 1
  pinMode(b, OUTPUT);  //left motor output 2
  pinMode(c, OUTPUT);  //right motor output 1
  pinMode(d, OUTPUT);  //right motor output 2
  pinMode(irl, INPUT); //left IR sensor input
  pinMode(irr, INPUT); //right IR sensor input
  pinMode(el, OUTPUT); //left motor pwm output
  pinMode(er, OUTPUT); //right motor pwm output
  analogWrite(el, 200);//assigning pwm or speed of 200 for left motor
  analogWrite(er, 200);//assigning pwm or speed of 200 for right motor
  delay(1000);
}

void loop() {
  if(digitalRead(irl)==0 && digitalRead(irr)==0){ //Condition to check the robot in line
    fwd();
  }
  if(digitalRead(irl)==1 && digitalRead(irr)==0){ //Condition to check the robot off the line to right
    hleft();
  }
  if(digitalRead(irl)==0 && digitalRead(irr)==1){ //Condition to check the robot off the line to left 
    hright();
  }
  if(digitalRead(irl)==1 && digitalRead(irr)==1){ //Condition to check whether the robot is at the end of the path
    stp();
  }
}
