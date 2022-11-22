//definicion de pines
const int pM1 = 8;    // 28BYJ48 - In1
const int pM2 = 9;    // 28BYJ48 - In2
const int pM3 = 10;   // 28BYJ48 - In3
const int pM4 = 11;   // 28BYJ48 - In4

const int ent_0 = 4;
const int ent_1 = 5;
const int ent_2 = 6;
const int ent_3 = 7;

//definicion variables
int vM = 1000;  // variable para determinar la velocidad 
// 800 maxima - minima 1000 o mas
int cP = 0;      // contador para los pasos
int pV = 4076;  // pasos para una vuelta completa
 
//secuencia media fase usar vM = 1000
const int cantidadPasos = 8;
const int tablaPasos[8] = { B1000, B1100, B0100, B0110, B0010, B0011, B0001, B1001 };
 
 
void setup()
{
//declarar pines como salida
pinMode(pM1, OUTPUT);
pinMode(pM2, OUTPUT);
pinMode(pM3, OUTPUT);
pinMode(pM4, OUTPUT);

pinMode(ent_0,INPUT);
pinMode(ent_1,INPUT);
pinMode(ent_2,INPUT);
pinMode(ent_3,INPUT);

Serial.begin(9600);
}
 
void loop(){

  byte val=PIND;
  val=val& B11110000;

  switch(val){
    case B11000000:
      Serial.println("Dato: 1100");
      Serial.println("720 grados Izq");
      for (int i = 0; i < pV * 2; i++){
        sentidoAntihorario();
        delayMicroseconds(vM);
      }
      Serial.println("Dato:??");
      delay(200);
      
      break;

    case B00100000:
      Serial.println("Dato: 0010");
      Serial.println("180 grados Der");
      for (int i = 0; i < 2038; i++)
      {
        sentidoHorario();
        delayMicroseconds(vM);
      }
      Serial.println("Dato:??");
      delay(200);
      break;

    case B01010000:
      Serial.println("Dato: 0101");
      Serial.println("270 grados Izq");
      for (int i = 0; i < 3057; i++){
        sentidoAntihorario();
        delayMicroseconds(vM);
      }
      Serial.println("Dato:??");
      delay(200);
      break;

    case B11110000:

      Serial.println("Dato: 1111");
      Serial.println("45 grados Der");
      for (int i = 0; i < 510; i++)
      {
        sentidoHorario();
        delayMicroseconds(vM);
      }
      Serial.println("Dato:??");
      delay(200);
      break;
        
    default:
    
      digitalWrite(pinMotor1, 0);
      digitalWrite(pinMotor2, 0);
      digitalWrite(pinMotor3, 0);
      digitalWrite(pinMotor4, 0);
      break;
    
    
  }
  
}
 
void sentidoAntihorario() // en dirección de las agujas del reloj
{
cP++;
if (cP >= cantidadPasos) cP = 0;
escribirSalidas(cP);
}
 
void sentidoHorario()// en dirección contraria a las agujas del reloj
{
cP--;
if (cP < 0) cP = cantidadPasos - 1;
escribirSalidas(cP);
}
 
void escribirSalidas(int paso)
{
digitalWrite(pM1, bitRead(tablaPasos[paso], 0));
digitalWrite(pM2, bitRead(tablaPasos[paso], 1));
digitalWrite(pM3, bitRead(tablaPasos[paso], 2));
digitalWrite(pM4, bitRead(tablaPasos[paso], 3));
}