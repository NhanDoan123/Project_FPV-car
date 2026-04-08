int pwm_pin = 3; //Green
int LF_1 = 4; //Red
int LF_2 = 7; //Blue
int RF_1 = 8; //Yellow
int RF_2 = 10;  //Orange

int RB_1 = A0;  //Yellow
int RB_2 = A1;  //Orange
int LB_1 = A2;  //Red
int LB_2 = A3;  //Blue

int speed = 150;
int time = 300;

int motors[8] = {LF_1,LF_2,RF_1,RF_2,RB_1,RB_2,LB_1,LB_2};

void set_pin(){
  pinMode(pwm_pin,OUTPUT);
  pinMode(LF_1,OUTPUT);
  pinMode(LF_2,OUTPUT);
  pinMode(RF_1,OUTPUT);
  pinMode(RF_2,OUTPUT);

  pinMode(RB_1,OUTPUT);
  pinMode(RB_2,OUTPUT);
  pinMode(LB_1,OUTPUT);
  pinMode(LB_2,OUTPUT);

  analogWrite(pwm_pin,0);
}

void Stop(){
  for (int i = 0; i<8; i++){
    digitalWrite(motors[i],LOW);
  }
}

void Forward(){
  digitalWrite(LF_1,LOW);
  digitalWrite(LF_2,HIGH);
  digitalWrite(RF_1,LOW);
  digitalWrite(RF_2,HIGH);

  digitalWrite(LB_1,LOW);
  digitalWrite(LB_2,HIGH);
  digitalWrite(RB_1,LOW);
  digitalWrite(RB_2,HIGH);

  analogWrite(pwm_pin,speed);


}

void Backward(){

  digitalWrite(LF_1,HIGH);
  digitalWrite(LF_2,LOW);
  digitalWrite(RF_1,HIGH);
  digitalWrite(RF_2,LOW);

  digitalWrite(LB_1,HIGH);
  digitalWrite(LB_2,LOW);
  digitalWrite(RB_1,HIGH);
  digitalWrite(RB_2,LOW);

  analogWrite(pwm_pin,speed);

}

void Right(){

  digitalWrite(LF_1,LOW);
  digitalWrite(LF_2,HIGH);

  digitalWrite(RF_1,HIGH);
  digitalWrite(RF_2,LOW);

  digitalWrite(LB_1,HIGH);
  digitalWrite(LB_2,LOW);

  digitalWrite(RB_1,LOW);
  digitalWrite(RB_2,HIGH);

  analogWrite(pwm_pin,speed);

}

void Left(){

  digitalWrite(LF_1,HIGH);
  digitalWrite(LF_2,LOW);
  
  digitalWrite(RF_1,LOW);
  digitalWrite(RF_2,HIGH);
  
  digitalWrite(LB_1,LOW);
  digitalWrite(LB_2,HIGH);
  
  digitalWrite(RB_1,HIGH);
  digitalWrite(RB_2,LOW);
  
  analogWrite(pwm_pin,speed);

}

void NW(){

  digitalWrite(LF_1,LOW);
  digitalWrite(LF_2,LOW);
  
  digitalWrite(RF_1,LOW);
  digitalWrite(RF_2,HIGH);
  
  digitalWrite(LB_1,LOW);
  digitalWrite(LB_2,HIGH);
  
  digitalWrite(RB_1,LOW);
  digitalWrite(RB_2,LOW);
  
  analogWrite(pwm_pin,speed);
}

void NE(){

  digitalWrite(LF_1,LOW);
  digitalWrite(LF_2,HIGH);
  
  digitalWrite(RF_1,LOW);
  digitalWrite(RF_2,LOW);
  
  digitalWrite(LB_1,LOW);
  digitalWrite(LB_2,LOW);
  
  digitalWrite(RB_1,LOW);
  digitalWrite(RB_2,HIGH);
  
  analogWrite(pwm_pin,speed);
}

void SW(){

  digitalWrite(LF_1,HIGH);
  digitalWrite(LF_2,LOW);
  
  digitalWrite(RF_1,LOW);
  digitalWrite(RF_2,LOW);
  
  digitalWrite(LB_1,LOW);
  digitalWrite(LB_2,LOW);
  
  digitalWrite(RB_1,HIGH);
  digitalWrite(RB_2,LOW);
  
  analogWrite(pwm_pin,speed);
}

void SE(){
  
  digitalWrite(LF_1,LOW);
  digitalWrite(LF_2,LOW);
  
  digitalWrite(RF_1,HIGH);
  digitalWrite(RF_2,LOW);
  
  digitalWrite(LB_1,HIGH);
  digitalWrite(LB_2,LOW);
  
  digitalWrite(RB_1,LOW);
  digitalWrite(RB_2,LOW);
  
  analogWrite(pwm_pin,speed);
}

void Rotate_right(){

  digitalWrite(LF_1,LOW);
  digitalWrite(LF_2,HIGH);
  
  digitalWrite(RF_1,HIGH);
  digitalWrite(RF_2,LOW);
  
  digitalWrite(LB_1,LOW);
  digitalWrite(LB_2,HIGH);
  
  digitalWrite(RB_1,HIGH);
  digitalWrite(RB_2,LOW);
  
  analogWrite(pwm_pin,speed);
}

void Rotate_left(){

  digitalWrite(LF_1,HIGH);
  digitalWrite(LF_2,LOW);
  
  digitalWrite(RF_1,LOW);
  digitalWrite(RF_2,HIGH);
  
  digitalWrite(LB_1,HIGH);
  digitalWrite(LB_2,LOW);
  
  digitalWrite(RB_1,LOW);
  digitalWrite(RB_2,HIGH);
  
  analogWrite(pwm_pin,speed);
}





