// ENVIA DATOS, VELOCIDAD MAX 100 PULSOS EN 10 MILISEGUNDOS

#define LED 3 
int valor_pulso= 0; 
int cantidad = 83;
int duracion = 11; // en milisegundos
int i= 0;
int flag= 0;

void setup() {
  // put your setup code here, to run once: 
  pinMode(LED, OUTPUT); 
  
}

void loop() {
  while(flag==0){
    pulsos(cantidad, duracion); 
    flag=1; 
  }   
}

void pulsos(int cantidad, int duracion){
  
  for (i; i<cantidad; i++){
    
    digitalWrite(LED, HIGH);  
    delay(duracion);
    //Serial.println("Led encencido");
  
    digitalWrite(LED, LOW);
    delay(duracion);
    //Serial.println("Led apagado");
  } 
}
