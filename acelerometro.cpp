


#include "cuadricoptero.h"
#include "acelerometro.h"
#include "control.h"
#include "motor.h"
//user defined
int MAX_RAW_X=491; //-90
int MIN_RAW_X=168;  //90
int MAX_RAW_Y=508;  //-90
int MIN_RAW_Y=188;  //90
// no defined by user
int rawX=0;
int degX=0;
int rawY=0;
int degY=0;
int cont=1;
int degX_ant, degY_ant;
int pot[4];
int pot1, pot2, pot3, pot4; //potencia de los motores.

boolean tx=false; //para saber si estamos en modo manual (transmitiendo)

/*void setup(){
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(19, INPUT);
  pinMode(20, INPUT);
  //arranque();
  for(int i=0;i<4;i++){
      pot[i]=pot_def;  //potencia por defecto a lo 4 motores
  }
}*/

/*void loop(){
  
  
  if(tx){
  //meter aqui el codigo de la transmision o control manual
  }
  else{
    captura_acc();  //se encarga del acelerometro y la autoequilibracion
    
  }
}*/


/*
Metodo para capturar del acelerometro y auto estabilizar

*/

void captura_acc(){

  //tratamiento de x
  rawX=analogRead(A0);
  
  //degX=(((rawX -166)*-90)/167) + 90;
  degX=map(analogRead(A0),MIN_RAW_X,MAX_RAW_X,90,-90);
 
  degX_ant=(degX_ant+degX)/2;
   //Serial.println(degX_ant);
  //tratamiento de y
  rawY=analogRead(A1);
  //Serial.println(rawY);
  //degY=(((rawY-186)*(-5))/(9))+90;
  degY=map(analogRead(A1),MIN_RAW_Y,MAX_RAW_Y,90,-90);
  degY_ant=(degY_ant+degY)/2;
  
  delay(10);
  cont++;
  if (cont==100){
    /*Serial.print("eje x: ");
    Serial.println(degX_ant);
    Serial.print("eje y: ");
    Serial.println(degY_ant);*/
    
    //respuesta_esc(degX,degY);
    respuesta_lin(degX,degY); //metodo para auto-estabilizar a partir de los grados
    degX_ant=degX;
    degY_ant=degY;
    cont=0;
  }
}


//  metodo lineal de respuesta de los motores ante un desequilibrio
/*
Suponiendo potencia minima 0 para 0 grados y maxima 255 para +-90 grados
Hay que averiguar potencia minima en los motores para la sustentacion. Suponemos pot_def=50
Puesto que es una ecuacion en X^2 no hay que diferenciar entre X e Y negativos y positivos
Para calcular esta ecuacion, se han hecho coincidir los puntos finales de la recta que pasa por (0,0) y (90, 255-pot_def) con la parabola que pasa por los mismos puntos. (a sumar con la potencia por defecto)
*/
void respuesta_lin(int degX, int degY){
  
  //pot[0]=pot_def+(degX*degX)/53;//ecuacion parabolica (mejor adaptada)    PARA X
  pot[0]=pot_def+(degX*degX)/(MAX_SPEED-pot_def);
  //pot[1]=pot_def+(degY*degY)/53;//ecuacion parabolica (mejor adaptada)    PARA Y
  pot[1]=pot_def+(degY*degY)/(MAX_SPEED-pot_def);
  if(degX>=0){
    //pot1=(degX*255)/90;//ecuacion lineal
   // pot1=(degX*degX)/32;//ecuacion parabolica (mejor adaptada)
    //Serial.println(degX);  
    set_speed(1,pot[0]); 
    Serial.print("potencia en el motor 1:  "); 
    Serial.println(pot[0]);   
  }
  else if(degX<0){
    //pot3=degX*255/90;//ecuacion lineal
    //pot3=(degX*degX)/32;//ecuacion parabolica (mejor adaptada)
    set_speed(3,pot[0]); 
    Serial.print("potencia en el motor 3:  "); 
    Serial.println(pot[0]);   
  }
  if(degY>0){
    //pot4=degY*255/90;//ecuacion lineal
    //pot4=(degX*degX)/32;//ecuacion parabolica (mejor adaptada)
    set_speed(4,pot[1]); 
    Serial.print("potencia en el motor 4:  "); 
    Serial.println(pot[1]);   
  }
  else if(degY<=0){
    //pot2=degY*255/90;//ecuacion lineal
    //pot2=(degX*degX)/32;//ecuacion parabolica (mejor adaptada)
    set_speed(2,pot[1]); 
    Serial.print("potencia en el motor 2:  "); 
    Serial.println(pot[1]);   
  }


}


//  metodo escalonado de respuesta de los motores ante un desequilibrio NO ME MOLA TANTO
void respuesta_esc(int degX, int degY){
  //ZONA CRITICA
    if(degX>50){
      Serial.println("correccion CRITICA positiva de X");  
    }
    else if(degX<-50){
      Serial.println("correccion CRITICA negativa de X");
    }
    if(degY>50){                                                  
      Serial.println("correccion CRITICA positiva de Y");
    }
    else if(degY<-50){
      Serial.println("correccion CRITICA negativa de Y");
    }
    
    //ZONA MEDIA
  if(degX>30){
      Serial.println("correccion MEDIA positiva de X");  
    }
    else if(degX<-30){
      Serial.println("correccion MEDIA negativa de X");
    }
    if(degY>30){                                                  
      Serial.println("correccion MEDIA positiva de Y");
    }
    else if(degY<-30){
      Serial.println("correccion MEDIA negativa de Y");
    }
    //ZONA SUAVE
  if(degX>10){
      Serial.println("correccion SUAVE positiva de X");  
    }
    else if(degX<-10){
      Serial.println("correccion SUAVE negativa de X");
    }
    if(degY>10){                                                  
      Serial.println("correccion SUAVE positiva de Y");
    }
    else if(degY<-10){
      Serial.println("correccion SUAVE negativa de Y");
    }
  
}




