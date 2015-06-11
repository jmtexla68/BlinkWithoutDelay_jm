

/* Blink sin retardo
 
  Enciende y apaga un diodo emisor de luz (LED) conectado a un pin 
  digital, sin utilizar la función de retardo (). Esto significa 
  que otro código se puede ejecutar al mismo tiempo sin ser 
  interrumpido por el código LED.
 
  El circuito:
  * LED conectado del pin 13 a tierra.
  * Nota: en la mayoría de Arduinos, ya hay un LED en el tablero
  que se une a la patilla 13, por lo que se necesita ningún 
  hardware para este ejemplo.
  
  http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay

  */
  
  // Constantes que no cambiarán. Se utilizan para establecer un 
  // número de pin:
  const int pinLed =  13;  //numero de pin
  
  //Variables que puedon cambiar:
  int estadoLed = LOW; //utilizado para establecer el LED
  
 // En general, se debe utilizar "unsigned long" en variables que contienen tiempo
 // El valor se convertirá cuando es  demasiado grande para almacenar en un int
 unsigned long previousMillis = 0;        // almacenará el ultimo tiempo actualizado

// esta constante no puede cambiar:
const long intervalo = 200;      // intervalo del parpadeo

void setup() {
  // establecer el pin digital como salida:
  pinMode(pinLed, OUTPUT);      
}

void loop()
{
  // Comprobar para ver si debe parpadear el LED; es decir, si la
   // diferencia entre la hora actual y la última vez que parpadeó
   // el LED es mayor que el intervalo en el que desea
   // parpadear el LED.
    unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis >= intervalo) {
    // salvar el ultimo momento que parpadeó el led
    previousMillis = currentMillis;   

    // si el LED está apagado encenderlo y viceversa:
    if (estadoLed == LOW)
      estadoLed = HIGH;
    else
      estadoLed = LOW;

    // ajusta el LED con la variable ledState
    digitalWrite(pinLed, estadoLed);
  }
}
