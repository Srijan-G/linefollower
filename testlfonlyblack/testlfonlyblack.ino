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
analogWrite(ena,240);
analogWrite(enb,240);
int valleft,valmid,valright;
valleft=digitalRead(left_ir);
valmid=digitalRead(mid_ir);
valright=digitalRead(right_ir);
flag=1;


if (valleft==1 && valright==1 && valmid==0)
flag=0;
Serial.println(flag);

if (flag==1)
{
 if(valleft==0 && valright==0 && valmid==1) 
 {
  straight();
  
 }
 if((valleft==1 && valright==0 && valmid==1) || (valleft==1 && valright==0 && valmid==0))
 {
  turn_left();
    
 }
 if((valleft==0 && valright==1 && valmid==1) || (valleft==0 && valmid==0 && valright==1))
 {
  turn_right();
 
 }
 if(valleft==1 && valright==1 && valmid==1)
 {
  turn_left();
  
 }
 if(valleft==0 && valmid==0 && valright==0)
 {
  moveStop();
  
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
   digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
  delay(30);
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,HIGH);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  int a=digitalRead(left_ir);
  int b=digitalRead(mid_ir);
  int c=digitalRead(right_ir);
  while(!(a==0 && b==1 && c==0))
  {
   digitalWrite(lm1,LOW);
  digitalWrite(lm2,HIGH);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  a=digitalRead(left_ir);
  b=digitalRead(mid_ir);
  c=digitalRead(right_ir);
  
  }
  return;
  }

void turn_right()
{
  
   digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
  delay(30);
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,HIGH);
  int a=digitalRead(left_ir);
  int b=digitalRead(mid_ir);
  int c=digitalRead(right_ir);
  while(!(a==0 && b==1 && c==0))
  {
   digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,HIGH);
  a=digitalRead(left_ir);
  b=digitalRead(mid_ir);
  c=digitalRead(right_ir);

  }
 
  return;
}

  
