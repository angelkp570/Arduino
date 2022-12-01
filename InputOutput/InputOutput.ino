//2 7 2
void setup(){ 
  DDRD = 0b11111111; 
  DDRB = 0b11000011; 
  Serial.begin(9600); 
} 
void loop(){ 
  byte val=PINB; 
  val=val& B11111100; 
  switch(val){ 
    case B00000000: 
      PORTD=B11111111; 
      PORTB=B00000000; 
      break; 
    case B00000100: 
      PORTD=B00011000; 
      PORTB=B00000000; 
      break;
    case B00001000: 
      PORTD=B01101100; 
      PORTB=B00000001; 
      break; 
    case B00001100: 
      PORTD=B00111100; 
      PORTB=B00000001; 
      break; 
    case B00010000: 
      PORTD=B10011000; 
      PORTB=B00000001; 
      break; 
    case B00010100: 
      PORTD=B10110100; 
      PORTB=B00000001; 
      break; 
    case B00011000: 
      PORTD=B11110100; 
      PORTB=B00000001; 
      break; 
    case B00011100: 
      PORTD=B00011100; 
      PORTB=B00000000; 
      break; 
    case B00100000: 
      PORTD=B11111100; 
      PORTB=B00000001; 
      break; 
    case B00100100: 
      PORTD=B10011100; 
      PORTB=B00000001; 
      break; 
    default: 
      PORTD=B00000000; 
      PORTB=B00000000; 
      break; 
  } 
  
}