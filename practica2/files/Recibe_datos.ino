// RECIBE DATOS
int potencia=1;
int suma=0;
int bit;

void setup()
{
  pinMode(2, INPUT); //Bit7
  pinMode(3, INPUT); //Bit6
  pinMode(4, INPUT); //Bit5
  pinMode(5, INPUT); //Bit4
  pinMode(6, INPUT); //Bit3
  pinMode(7, INPUT); //Bit2
  pinMode(8, INPUT); //Bit1
  pinMode(9, INPUT); //Bit0
  Serial.begin(9600);
}

void loop()
{
  for(int i=8; i>0; i--)
  {
    bit=digitalRead(i+1);
    //Serial.println(bit);
    //Serial.println(potencia);
    suma=suma +(bit*potencia);
    //Serial.println(suma);
    potencia=potencia*2;
  }
  Serial.println(suma);
  suma=0;
  potencia=1;
  delay(1000);
}
