#if (ARDUINO >= 100)
# include "Arduino.h"
#else
# include "WProgram.h"
  //Arduino < 1.0.0 does not define this, so we need to do it ourselves
# define analogInputToDigitalPin(p) ((p) + A0)
#endif

#define MAX_SPEED 90	//tiene que ser 90 como mucho ya que va en funcion de grados. sin 90º=1 = MAXIMO
#define MIN_SPEED 40
