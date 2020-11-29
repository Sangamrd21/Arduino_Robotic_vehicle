//Program for obstacle avoiding robot using arduino

#include <Servo.h>
#include <NewPing.h>

Servo myservo; 
const int a = 5;
const int b = 4;
const int c = 3;
const int d = 2;
const int ena = 9;
const int enb = 10;
#define trig_pin A1 //analog input 1
#define echo_pin A2 //analog input 2

#define maximum_distance 200

NewPing sonar(trig_pin, echo_pin, maximum_distance);

void stp(){
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
}

void fwd(){
  
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
}

void rev(){
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
}

void sright(){
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
}

void sleft(){
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
}

void hright(){
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          digitalWrite(d, HIGH);
}                                                                                                                                                                                                                                                                                                                         

void hleft(){
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
}

//function to find obstacle 
int obstacle(){       
  int d;
  d = sonar.ping_cm();//to read the distance of the obstacle
  delay(20);
  if(d==0){
    d=100;
  }
  return d;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          }
//function to find the obstacle towards the left of the robot 
int lser(){ 
  int d;
  stp();
  delay(200);
  myservo.write(180);  //to move the ultrasonic sensor towards left
  delay(500);
  d = sonar.ping_cm(); //read the distance of the obstacle
  delay(200);
  myservo.write(130);  //to move the ultrasonic sensor towards middle
  return d;
  delay(100);
}

//function to find the obstacle towards the right of the robot
int rser(){
  int d;
  stp();
  delay(200);
  myservo.write(80);   //to move the ultrasonic sensor towards right
  delay(500);
  d = sonar.ping_cm();
  delay(20);
  myservo.write(130);
  return d;
  delay(100);
}
void setup() {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  myservo.attach(6);
  myservo.write(130);
  analogWrite(ena, 180);
  analogWrite(enb, 180);
  delay(1000);
}

void loop() {
  int d,ld,rd;
  top: d = obstacle();
  if(d<30){
    stp();
    delay(300);
    rev();
    delay(400);
    stp();
    delay(300);
    ld = lser();
    delay(300);
    rd = rser();
    if(ld>30 && ld>rd){
      sleft();
      delay(500);
      if(obstacle()>30){
        fwd();
      }
      else{
        goto top;
      }
    }
    else if(rd>30){
      sright();
      delay(500);
      if(obstacle()>30){
        fwd();
      }
      else{
        goto top;
      }
    }
    else{
      stp();
      delay(200);
      rev();
      delay(300);
      hright();
      delay(800);
    }
  }
  else{
    fwd();
  }
   
}
