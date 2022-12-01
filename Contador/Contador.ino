void setup(){ 
  //Configuración de los Puertos como salida 
  DDRD = 0b11111111; 
  DDRB = 0b11111111; 
  Serial.begin(9600); 
} 

void loop(){ 
  //************************************************************************* 
  //Corrimiento de 0 a 255 
  //************************************************************************* 
  PORTD = 0b00000000+0b100; 
  int i=0; 
  int j=0; 
  PORTB = B00000000; 
  
  for(j=0;j<=3;j++){ 
    for(i=4;i<=255;i++){ 
      PORTD = PORTD+0b00000001; 
      Serial.println(PORTD); 
      delay(100); 
    } 
    PORTB = PORTB+B00000001; 
    PORTD = B00000000; 
  } 
  //*************************************************************************
  //Contador 0-9 
  //************************************************************************* 
  int val = B00000000; 
  PORTB=val; 
  delay(1000); 
  for(i=0;i<=8;i++){ 
    val = val + B00000001; 
    PORTB = val<<2; 
    delay(1000); 
    Serial.println(PORTB,BIN); 
  } 
}