//Program for line following robot using arduino uno 

#define a 4
#define b 5 
#define c 6 
#define d 7 

#define irl A3 
#define irm A4
#define irr A5 

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
void sright(){         //function to turn right
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
}
void sleft(){          //function to turn left
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
  pinMode(irm, INPUT); //middle IR sensor input
  delay(1000);
}

void loop() {
  if((digitalRead(irl)==0 && digitalRead(irr)==0 && digitalRead(irm)==0) || (digitalRead(irl)==1 && digitalRead(irr)==1 && digitalRead(irm)==1)){ //Condition to check whether the robot is at the end of the path
      stp();
  }
  if(digitalRead(irm)==1 && (digitalRead(irl)==1 || digitalRead(irr)==1)){ //Condition to check whether there is any 90 degree turn
    if(digitalRead(irl)==1){ //If 90 degree Left turn
      while(!(digitalRead(irl)==0 && digitalRead(irm)==1 && digitalRead(irr)==0)){
        sleft();
      }
   }
    if(digitalRead(irr)==1){ //If 90 degree Right turn 
      while(!(digitalRead(irl)==0 && digitalRead(irm)==1 && digitalRead(irr)==0)){
        sright();
      }
    }    
  }
  else{
    if(digitalRead(irl)==0 && digitalRead(irr)==0 && digitalRead(irm)==1){ //Condition to check the robot in line
      fwd();
    }
    if(digitalRead(irl)==1 && digitalRead(irr)==0){ //Condition to check the robot off the line to right
      sleft();
    }
    if(digitalRead(irl)==0 && digitalRead(irr)==1){ //Condition to check the robot off the line to left 
      sright();
    }
  }
}
