// Configuramos los pines que vamos a usar.
#include <Ultrasonic.h>//Incluimos la libreria para el control del sensor HC-SR04.
Ultrasonic sensor(6,7,30000); // (Trig PIN,Echo PIN, microsegundos max "distancia máxima") 30000us = 5 metros.

int velocidad_de_medida=5;//Variable para ajustar la velocidad de medida del sensor.
long int distancia=0;//Variable para almacenar la distancia medida. 
int aleatorio=0;//Variable para guardar un valor aleatorio. 

void setup() 
{ 
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
} 
 
void loop() 
{ 
  digitalWrite(2,1);    //Avanza
  digitalWrite(3,0);
  digitalWrite(4,1);
  digitalWrite(5,0);
   digitalWrite(13,0);
  distancia=sensor.Ranging(CM);//Medimos la distancia y la guardamos en la variable

  delay(velocidad_de_medida);//Delay para controlar la velocidad de medida.
 aleatorio=random (2);//Funcion aleatoria para hacer que el robot no gire siempre en el mismo sentido.
  
  
  while(distancia<20){//Mientras la distancia sea menor que 20 se mantiene en este bucler
        
  delay(velocidad_de_medida);//Delay para controlar la velocidad de medida.
  digitalWrite(2,0);    //para
  digitalWrite(3,0);
  digitalWrite(4,0);
  digitalWrite(5,0); 
   digitalWrite(13,0);     
  distancia=sensor.Ranging(CM);
  delay(1000);
  digitalWrite(2,0);    //Retrocede
  digitalWrite(3,1);
  digitalWrite(4,0);
  digitalWrite(5,1);
  digitalWrite(13,1);
 delay(500);
  if(aleatorio==0){//Si la variable aleatorio vale 0 entra en este bucle.
  digitalWrite(2,1);    //gira derecha
  digitalWrite(3,0);
  digitalWrite(4,0);
  digitalWrite(5,0);
  delay(500);}
  if (aleatorio==1){//Si la variable aleatorio vale 1 entra en este bucle.
  digitalWrite(2,0);    //gira izquierda
  digitalWrite(3,0);
  digitalWrite(4,1);
  digitalWrite(5,0);
  delay(500); }

  }
} 
