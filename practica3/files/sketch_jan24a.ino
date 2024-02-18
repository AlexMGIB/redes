// ENVIA DATOS 
// ENVIA DATOS DECIMALES Y LOS GUARDA EN UN ARRAY
int pot=5;

void setup()
{
  pinMode(2, OUTPUT); //Bit0
  pinMode(3, OUTPUT); //Bit1
  pinMode(4, OUTPUT); //Bit2
  pinMode(5, OUTPUT); //Bit3
  pinMode(6, OUTPUT); //Bit4
  pinMode(7, OUTPUT); //Bit5
  pinMode(8, OUTPUT); //Bit6
  pinMode(9, OUTPUT); //Bit7
  Serial.begin(9600);
}

void loop()
{
  pot=analogRead(A5);
  //Serial.println(pot);
  pot=map(pot,0,1023,0,255);
  Serial.println(pot);
  
  for(int i=0; i<8; i++)
  {
    digitalWrite(i+2,pot%2);
    Serial.print(pot%2);
    pot=pot/2;
      
    
  }
  Serial.println("");
  delay(1000);
}
