void setup()
{
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  
  // Controla direcao dos 4 motores
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  
  pinMode(12, OUTPUT);
  
  // Inicializa motores zerados
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);

  
  Serial.begin(9600); 

}

void loop(){

  
  if(Serial.available() > 0){
    char opc = Serial.read();
    
    switch(opc){
      case 'F':
        //Serial.println('F');
        digitalWrite(8, LOW);
        digitalWrite(7, HIGH);
        digitalWrite(2, HIGH);
        digitalWrite(4, LOW);  
      	break;
      
      case 'B':
      	//Serial.println("B");
        digitalWrite(8, HIGH);
        digitalWrite(7, LOW);
        digitalWrite(2, LOW);
        digitalWrite(4, HIGH); 
        break;
      
      case 'R':
      	//Serial.println("R");
      	digitalWrite(8, HIGH);
        digitalWrite(7, LOW);
        digitalWrite(2, HIGH);
        digitalWrite(4, LOW);    
      	break;
      
      case 'L':
      	//Serial.println("L");
      	digitalWrite(8, LOW);
        digitalWrite(7, HIGH);
        digitalWrite(2, LOW);
        digitalWrite(4, HIGH); 
      break;
      	
      case 'S':
			//Serial.println("S");
        stop(); // Chama a função stop

        break;
      
      case 'X':
        digitalWrite(12, HIGH);
        break;
      case 'x':
        digitalWrite(12, LOW);
        break;
      case 'Y':
        digitalWrite(12, LOW);
        break;
      default:
        stop();
        break;
    }
  }
  
}

    
void stop(){
	// Evita que ele vá pra frente/trás, deixa parado de fato
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
}