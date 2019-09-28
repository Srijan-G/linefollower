// black is 1 white is 0

const int left_ir=3;
const int right_ir=5;
const int mid_ir=4;
const int lm1=10;
const int lm2=12;
const int rm1=8;
const int rm2=9;
const int enb=11;
const int ena=6;
unsigned int flag;
unsigned int dir;
void setup() 
{                
 pinMode(left_ir,INPUT);
 pinMode(right_ir,INPUT);
 pinMode(mid_ir,INPUT);
 pinMode(lm1,OUTPUT);
 pinMode(lm2,OUTPUT);
 pinMode(rm1,OUTPUT);
 pinMode(rm2,OUTPUT);
 pinMode(ena,OUTPUT);
 pinMode(enb,OUTPUT);
 Serial.begin(9600);
 
}
void turn_right();
void turn_left();
void turn_rightw();
void turn_leftw();
void straight();
void moveStop();
void turn_left90();
void loop() 
{
analogWrite(ena,230);
analogWrite(enb,230);
int valleft,valmid,valright;
valleft=digitalRead(left_ir);
valmid=digitalRead(mid_ir);
valright=digitalRead(right_ir);
if(valleft==0 && valright==0 && valmid==1)
flag=1;
else if (valleft==1 && valright==1 && valmid==0)
flag=0;
Serial.println(flag);
if(flag==0)
{
  if(valleft==1 && valright==1 && valmid==0)
  { 
    straight();
    Serial.println("Straight");
  }
  if((valleft==0 && valright==1 && valmid==0) || (valleft==0 && valright==1 && valmid==1))
  {
    Serial.println("Left");
    turn_leftw();
    
  }
  if((valleft==1 && valright==0 && valmid==0) ||  (valleft==1 && valright==0 && valmid==1))
  {
     Serial.println("Right");
    turn_rightw();
   
  }
  if(valleft==1 && valright==1 && valmid==1)
  {
    Serial.println("Stop");
    moveStop();
    
  }
}
if (flag==1)
{
 if(valleft==0 && valright==0 && valmid==1) 
 {
  straight();
   Serial.println("Straight");
  
 }
 if((valleft==1 && valright==0 && valmid==1) || (valleft==1 && valright==0 && valmid==0 ))
 {
  turn_left();
  Serial.println("Left");
    dir=0;
 }
 if((valleft==0 && valright==1 && valmid==1) || (valleft==0 && valright==1 && valmid==0) )
 {
  turn_right();
  dir=1;
  Serial.println("Right");
 
 }
 if(valleft==0 && valmid==0 && valright==0)
 {
  if(dir==1)
  turn_right();
  else if(dir==0)
  turn_left();
 }
}

}
void straight()
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(30);
  return;
}

void moveStop()
{
   digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
 
  return;
}
void turn_left()
{ 
  analogWrite(ena,200);
  analogWrite(enb,200);
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,HIGH);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  
  return;
  }

void turn_right()
{
  analogWrite(ena,210);
  analogWrite(enb,210);
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,HIGH);
   
  
  return;
}
void turn_rightw()
{
 
  analogWrite(ena,210);
  analogWrite(enb,210);  
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,HIGH);
 
 
  return;
}
void turn_leftw()
{ 
   
  analogWrite(ena,200);
  analogWrite(enb,200);
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,HIGH);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  
 
  return;
  }


  
