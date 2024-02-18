
//ENVIO potenciometro

int pot=0;

void setup()
{
  pinMode(2, OUTPUT);
  Serial.begin(9600);
  
  delay(2000);//Esperamos inicie Arduino 2
  
  pot=analogRead(A5);
  //Serial.println(pot);
  pot=map(pot,0,1023,0,255);
  Serial.println(pot);
  
  digitalWrite(2, HIGH); //INICIAMOS con HIGH
  delay(1000); 
  for(int i=0; i<8; i++)
  {
    digitalWrite(2,pot%2);
    delay(1000); 
    Serial.print(pot%2);
    pot=pot/2;
  }
  digitalWrite(2, LOW);
  delay(1000); // TERMINAMOS Ccon LOW
  
  Serial.println("");
  
}

void loop()
{

}
/*
// ENVIA DATOS 
// ENVIA DATOS DECIMALES Y LOS GUARDA EN UN ARRAY
int pot=5;
int LED= 2; 
int arreglo[]= {0, 0, 0, 0, 0, 0, 0, 0} ; 

void setup()
{
  pinMode(2, OUTPUT); // LED
  Serial.begin(9600);
}

void loop()
{
  pot=analogRead(A5);
  pot=map(pot,0,1023,0,255);
  Serial.println(pot);

  digitalWrite(LED, HIGH); 
  delay(2000);
  digitalWrite(LED, LOW); 
  delay(2000);
  
  for(int i=0; i<8; i++)
  {
    digitalWrite(i+2,pot%2);
    pot=pot/2;
    arreglo[7-i]= pot%2;
    Serial.print(arreglo[i]); 
    
      if (pot%2 == 1){
        digitalWrite(LED, HIGH);
        delay(100); 
      }
      else {
        digitalWrite(LED, LOW);
        delay(100); 
      }
  }  
  Serial.println("");
  delay(1000);
}
 * /
 */
