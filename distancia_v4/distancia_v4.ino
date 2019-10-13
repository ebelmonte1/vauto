int aleatorio=0;//Variable para guardar un valor aleatorio.
#define izqA 2 
#define izqB 3 
#define derA 4
#define derB 5 
#define pecho 7            // define el pin 7 como (pecho) para el Ultrasonido
#define ptrig 6            // define el pin 6 como (ptrig) para el Ultrasonido
#define distanciaparar 15
#define vel 255            // Velocidad de los motores (0-255)
int duracion, distancia;  // para Calcular distacia

void setup()  { 
  
  pinMode(derA, OUTPUT);
  pinMode(derB, OUTPUT);
  pinMode(izqA, OUTPUT);
  pinMode(izqB, OUTPUT);
  
  pinMode(pecho, INPUT);   // define el pin 2 como entrada (pecho) 
  pinMode(ptrig,OUTPUT);   // define el pin 3 como salida  (ptrig) 
  pinMode(13,OUTPUT);
} 

void loop()  { 
     digitalWrite(ptrig, HIGH);   // genera el pulso de trigger por 10us
     delay(0.01);
     digitalWrite(ptrig, LOW);
     
     duracion = pulseIn(pecho, HIGH);          // Lee el tiempo del Echo
     distancia = (duracion/2) / 29;            // calcula la distancia en centimetros
     delay(10); 
     
     if (distancia <= distanciaparar && distancia >=2){    // si la distancia es menor de 15cm
       delay(250);
       aleatorio=random (2);//Funcion aleatoria para hacer que el robot no gire siempre en el mismo sentido.
        digitalWrite(13,HIGH);                 // Enciende LED
        
        analogWrite(derB, 0);             // Parar los motores por 200 mili segundos
        analogWrite(izqB, 0); 
        analogWrite(derA, 0);    
        analogWrite(izqA, 0); 
        delay (200);
        
        analogWrite(derB, vel);          // Reversa durante 500 mili segundos
        analogWrite(izqB, vel); 
        delay(500);           
        
       if(aleatorio==0){//Si la variable aleatorio vale 0 entra en este bucle.
         analogWrite(derB, 0);   //gira derecha  
         analogWrite(izqB, 0); 
         analogWrite(derA, 0);  
         analogWrite(izqA, vel);
       delay(500);}
       if (aleatorio==1){//Si la variable aleatorio vale 1 entra en este bucle.
         analogWrite(derB, 0);   //gira izquierda  
         analogWrite(izqB, 0); 
         analogWrite(derA, vel);  
         analogWrite(izqA, 0);
       delay(500); }
        digitalWrite(13,LOW);
     }
     else{                             // Si no hay obstaculos se desplaza al frente  
         analogWrite(derB, 0);     
         analogWrite(izqB, 0); 
         analogWrite(derA, vel);  
         analogWrite(izqA, vel); 
     }
  
  
}
