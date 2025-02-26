int M1a = 12;
int M1b = 13;

int M2a = 3;
int M2b = 2;

int IRfront = 7;
int IRright = 8;
int IRleft = 4;

int signalfront;
int signalright;
int signalleft;

void setup() {
  // put your setup code hee, to run once:
  pinMode(M1a,OUTPUT);
  pinMode(M1b,OUTPUT);
  pinMode(M2a,OUTPUT);
  pinMode(M2b,OUTPUT);
  pinMode(IRfront,INPUT);
  pinMode(IRright,INPUT);
  pinMode(IRleft,INPUT);
  
}

void forward()
{
  digitalWrite(M1a,HIGH);
  digitalWrite(M1b,LOW);
  digitalWrite(M2a,HIGH);
  digitalWrite(M2b,LOW);
}

void right()
{
  digitalWrite(M1a,HIGH);
  digitalWrite(M1b,LOW);
  digitalWrite(M2a,LOW);
  digitalWrite(M2b,HIGH);
}

void left()
{
  digitalWrite(M1a,LOW);
  digitalWrite(M1b,HIGH);
  digitalWrite(M2a,HIGH);
  digitalWrite(M2b,LOW);
}

void backward()
{
  digitalWrite(M1a,LOW);
  digitalWrite(M2a,HIGH);
  digitalWrite(M1b,LOW);
  digitalWrite(M2b,HIGH);
}

void stop()
{
  digitalWrite(M1a,LOW);
  digitalWrite(M2a,LOW);
  digitalWrite(M1b,LOW);
  digitalWrite(M2b,LOW);
}

void loop() 
 {
  signalfront = digitalRead(IRfront);
  signalright = digitalRead(IRright);
  signalleft = digitalRead(IRleft);

  if(signalfront == 1)
  {
   forward();
  }
  if(signalfront == 0)
  {
    if(signalright == 0)
    {
      left();
    }
    if(signalleft == 0)
    {
      right();
    }
  }

}
