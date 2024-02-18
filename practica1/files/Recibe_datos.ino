// RECIBE DATOS
#define LED 3 
 
volatile int conteoPulsos = 0;
 
void setup() {
  pinMode(LED, INPUT);
//               funcion         valor a leer, funcion,  edo flanco  
  attachInterrupt(digitalPinToInterrupt(LED), contarPulso, RISING); // cada que el valor sea 1, se suma un pulso 
  Serial.begin(9600);
}
 
void loop() {
}
 
void contarPulso() {
  conteoPulsos++;
  Serial.print("Pulsos recibidos: ");
  Serial.println(conteoPulsos);
}


// apretar botones para resetearlo y hacer pruebas 
