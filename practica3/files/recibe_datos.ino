// RECIBE 
int bit;  
int suma=0;
int potencia=1;

void setup()
{
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop()
{
  if(digitalRead(2)==HIGH)
  {
    delay(1050);
      
    for(int i=8; i>0; i--)
    {
      bit=digitalRead(2);
      Serial.println(bit);
      Serial.println(potencia);
      suma=suma +(bit*potencia);
      Serial.println(suma);
      potencia=potencia*2;
      delay(1000);   
    }
    Serial.println(suma);
  }
  suma=0;
  potencia=1;
  delay(1000);
}
