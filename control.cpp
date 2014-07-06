#include "cuadricoptero.h"
#include "motor.h"
//#include cuadricoptero.h
int pot_def=50; //potencia de los motores para la sustentacion

/*
Metodo encargado de la secuencia de arranque y despegue
*/
void arranque(){
   Serial.print("Arrancando en 20 segundos..."); 
  delay(20000);//delay por seguridad al arrancar
  Serial.print("Arrancando..."); 
  for(int j=20;j<pot_def;j+=2){
    for(int i=0;i<4;i++){
      set_speed(i,j);
      delay(100);
      Serial.println(velocidad[i]);
    }
  }
  
}

void aterrizaje(){


}
