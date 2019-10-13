// Configuramos los pines que vamos a usar.
#include <Ultrasonic.h>//Incluimos la libreria para el control del sensor HC-SR04.
Ultrasonic sensor(7,8,30000); // (Trig PIN,Echo PIN, microsegundos max "distancia máxima") 30000us = 5 metros.
#include <Servo.h>
Servo cabeza;
Servo brazoder; 
Servo brazoizq;  // create servo object to control a servo
int velocidad_de_medida=5;//Variable para ajustar la velocidad de medida del sensor.
long int distancia=0;//Variable para almacenar la distancia medida. 
int pos = 0;  
void setup() 
{ 
brazoizq.attach(5);
brazoder.attach(3);
cabeza.attach(11);
} 
 
void loop() 
{ 
  cabeza.write(90);
  brazoder.write(180);
  brazoizq.write(180);
  distancia=sensor.read(CM);
 for (pos = 45; pos <= 135; pos++) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    cabeza.write(pos);  
    if(distancia<20){//Mientras la distancia sea menor que 30 se mantiene en este bucler
        for (pos = 0; pos <= 180; pos++) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    brazoder.write(pos); 
    cabeza.write(90); // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos--) { // goes from 180 degrees to 0 degrees
    brazoder.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 0; pos <= 180; pos++) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    brazoizq.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos--) { // goes from 180 degrees to 0 degrees
    brazoizq.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
     
  
  }// tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 135; pos >= 45; pos--) { // goes from 180 degrees to 0 degrees
    cabeza.write(pos); 
    if(distancia<20){//Mientras la distancia sea menor que 30 se mantiene en este bucler
        for (pos = 0; pos <= 180; pos++) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    brazoder.write(pos);
    cabeza.write(90);// tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos--) { // goes from 180 degrees to 0 degrees
    brazoder.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 0; pos <= 180; pos++) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    brazoizq.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos--) { // goes from 180 degrees to 0 degrees
    brazoizq.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
     
  
  }// tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
  distancia=sensor.read(CM);//Medimos la distancia y la guardamos en la variable

 
 
  
  
  if(distancia<20){//Mientras la distancia sea menor que 30 se mantiene en este bucler
        for (pos = 0; pos <= 180; pos++) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    brazoder.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos--) { // goes from 180 degrees to 0 degrees
    brazoder.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 0; pos <= 180; pos++) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    brazoizq.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos--) { // goes from 180 degrees to 0 degrees
    brazoizq.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
     
  
  }
  
} 
