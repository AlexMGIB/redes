// CON WIFI
// RUTINA RODILLAS AL PECHO 
// PIERNA IZQUIERDA 1
                 //X, Y
int posicion_1[]= {-5, 66}; // posicion inicial
int posicion_2[]= {-30, 40}; // Talon atras
int posicion_3[]= {0, 68}; // Rodilla arriba
int posicion_4[]= {30, -4}; // patada al frente
int posicion_5[]= {7, -1}; // patada trasera
int posicion_6[]= {77, -2}; // patada lateral

int abductor_1[]= {7, -3}; 
int abductor_2[]= {10, -2}; 

// LIBRERIAS NECESARIAS
#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <MPU6050.h>
#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"
MPU6050 sensor;

// DECLARACIÓN DE STRINGS PARA LA CONEXIÓN WEB
String message="";
String myWebPage="https://alexservernuevo2.000webhostapp.com/";
String sensorN = "sensor1/"; // CAMBIAR DEPENDIENDO DEL SENSOR
String Password = "12345678" ;
String WIFI= "alex" ; 

const int Modulo_vibrador= 17 ; // GPIO 17

// Valores RAW (sin procesar) del acelerometro  en los ejes x,y,z
int ax, ay, az;
int arreglo[]= {0, 0, 0};

void setup() {
  const int Modulo_vibrador= 17 ; // GPIO 5
  
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);
    Wire.begin();
    Serial.begin(115200);
    Serial.println();
    Serial.println();
    Serial.println();
    sensor.initialize();

    // Verificar la conexión con el sensor
  if (sensor.testConnection()) { Serial.println("MPU6050 connection successful"); } 
  else { Serial.println("MPU6050 connection failed");
    while (1);
  }

    for(uint8_t t = 4; t > 0; t--) {
        Serial.printf("[SETUP] WAIT %d...\n", t);
        Serial.flush();
        delay(1000);
    }

    //Conect to wifi network
    WiFi.begin(WIFI, Password);  //Wifi_Network, Wifi_Password ******CHANGE

    //Wait until connection
    while((WiFi.status() != WL_CONNECTED)) {
      delay(500);
      Serial.print(".");
    }
     Serial.println("Wifi conected");
    
}

void loop() {
    // Obtener datos del acelerómetro y el giroscopio
    int16_t ax, ay, az, gx, gy, gz;

    sensor.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

    // Calcular la orientación
    float accel_ang_x=atan(ax/sqrt(pow(ay,2) + pow(az,2)))*(180.0/3.14);
    float accel_ang_y=atan(ay/sqrt(pow(ax,2) + pow(az,2)))*(180.0/3.14);

   // accel_ang_x = toInt
    int A= accel_ang_x; 
    int B= accel_ang_y; 
//                                                    angulos de referencia= X, Y
    // RODILLAS AL PECHO
    rutina(accel_ang_x, accel_ang_y, Modulo_vibrador, posicion_3[0], posicion_3[1]); 
    
    // PADATAS AL FRENTE
    //rutina(accel_ang_x, accel_ang_y, Modulo_vibrador, posicion_4[0], posicion_4[1] );
    
    // TALONES ATRAS 
    //rutina(accel_ang_x, accel_ang_y, Modulo_vibrador, posicion_2[0], posicion_2[1] );
   
    Serial.print("Angulo en X: ");
    Serial.println(accel_ang_x);
    Serial.print("  Angulo en Y: ");
    Serial.println(accel_ang_y); 

    // wait for WiFi connection
    if((WiFi.status() == WL_CONNECTED)) {

        HTTPClient http;

        Serial.print("[HTTP] begin...\n");
        
        // configure traged server and url
        message=myWebPage+sensorN+"?A="+String(A)+"&B="+String(B);  // Request Message Domain/page/request
        http.begin(message); //HTTP
        Serial.print(message);
        
        // start connection and send HTTP header, return error code
        int httpCode = http.GET();
        Serial.print("[HTTP] GET...\n");
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);
        http.end();
    }

    delay(500);
}

// FUNCIONES DE MOVIMIENTOS
void rutina(int angulo_X, int angulo_Y, int vibrador, int ref_X, int ref_Y){
  if ((angulo_X > ref_X-10 && angulo_X < ref_X+10) && (angulo_Y > ref_Y-10 && angulo_Y < ref_Y+10)){ // podemos eliminar los angulos en X porque se mantienen
      analogWrite(vibrador, 250); // Señal PWM a 75% en el PIN 7
      delay(200); 
      analogWrite(vibrador, 0);
      delay(200); 
  }
  else {
      analogWrite(vibrador, 0);
  }
}
