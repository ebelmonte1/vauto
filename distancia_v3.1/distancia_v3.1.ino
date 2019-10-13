// Configuramos los pines que vamos a usar.
#include <Ultrasonic.h>//Incluimos la libreria para el control del sensor HC-SR04.
Ultrasonic sensor(6,7,30000); // (Trig PIN,Echo PIN, microsegundos max "distancia máxima") 30000us = 5 metros.

int velocidad_de_medida=5;//Variable para ajustar la velocidad de medida del sensor.
long int distancia=0;//Variable para almacenar la distancia medida. 
int aleatorio=0;//Variable para guardar un valor aleatorio. 

void setup() 
{ 
//Serial.begin(9600);//Iniciamos el puerto serie
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
} 
 
void loop() 
{ 
  digitalWrite(2,1);    //avanza
  digitalWrite(3,0);
  digitalWrite(4,1);
  digitalWrite(5,0);
   digitalWrite(13,0);
  distancia=sensor.Ranging(CM);//Medimos la distancia y la guardamos en la variable

  delay(velocidad_de_medida);//Delay para controlar la velocidad de medida.
 
 //Las siguientes lineas de código son para hacer comprobaciones de que todo esta bien.
 //Serial.print("Avanza");
 //Serial.print(" No obstaculo ");//Imprime la palabra No obstaculo.
 //Serial.println(distancia);//Imprime la distancia.
 //Serial.print("aleatorio ");//Imprime la palabra aleatorio
 //Serial.println(aleatorio);//Imprime la variable aleatorio

 aleatorio=random (2);//Funcion aleatoria para hacer que el robot no gire siempre en el mismo sentido.
  
  
  while(distancia<20){//Mientras la distancia sea menor que 30 se mantiene en este bucler
        
  
  delay(velocidad_de_medida);//Delay para controlar la velocidad de medida.
  digitalWrite(2,0);    //define los puertos 9 a 6 en alto
  digitalWrite(3,0);
  digitalWrite(4,0);
  digitalWrite(5,0); 
   digitalWrite(13,0);     
  distancia=sensor.Ranging(CM);
  delay(1000);
digitalWrite(2,0);    //marcha atras
  digitalWrite(3,1);
  digitalWrite(4,0);
  digitalWrite(5,1);
  digitalWrite(13,1);
  //Serial.print("Obstaculo");
 delay(500);
  if(aleatorio==0){//Si la variable aleatorio vale 0 entra en este bucle.
 //Serial.print(" gira derecha 0");//Imprime dentro 0 para comprobar que entro.
 //Serial.println(distancia);//Imprime la variable distancia
 //Serial.print("aleatorio ");//Imprime la palabra aleatorio.
 //Serial.println(aleatorio);//Imprime la variable aleatorio.
 
 digitalWrite(2,1);    //gira derecha
  digitalWrite(3,0);
  digitalWrite(4,0);
  digitalWrite(5,0);
  delay(500);}
  if (aleatorio==1){//Si la variable aleatorio vale 1 entra en este bucle.
 //Serial.print(" gira izquierda 1");//Imprime dentro 1 para comprobar que entro.
 //Serial.println(distancia);//Imprime la variable distancia
 //Serial.print("aleatorio ");//Imprime la palabra aleatorio.
 //Serial.println(aleatorio);//Imprime la variable aleatorio.

  digitalWrite(2,0);    //gira izquierda
  digitalWrite(3,0);
  digitalWrite(4,1);
  digitalWrite(5,0);
  delay(500);}
  }
} 
