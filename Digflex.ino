
int mode = 0;
int threshold = 500;
int previous = 0;
int sensorValue;
int count = 0;
unsigned long timeDiff1 = 0;
unsigned long timeDiff2 = 0;
unsigned long timeDiff3 = 0;
unsigned long time1 = millis();
int cycles1 = 0;
int cycles2 = 0;
int cycles3 = 0;


// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  
}

// the loop routine runs over and over again forever:
void loop() {  
  sensorValue = analogRead(A1);

  if (previous > threshold
    && sensorValue < threshold
    && count%2 == 0 
  ) {
    Serial.print(".");
    if (timeDiff1 == 0) {
       timeDiff1 = millis();  
       //Serial.println(timeDiff1);     
    } else if (timeDiff2 == 0) {       
       timeDiff2 = millis();
       //Serial.print("Timediff2: ");
       //Serial.println(timeDiff2);   
       //Serial.print("calc Timediff2: ");
       //Serial.println(abs(timeDiff2 - timeDiff1));   
       //Serial.println();   
       cycles1 = 60000 / abs(timeDiff2 - timeDiff1);
       //Serial.print("2: ");
       //Serial.println(cycles1);
    } else if (timeDiff3 == 0) {
       timeDiff3 = millis();
       cycles2 = 60000 / abs(timeDiff3 - timeDiff2);
       Serial.print("cycles: ");
       Serial.print(cycles2);   
       Serial.print(" (");   
       Serial.print(cycles1);   
       Serial.println(")");  
       if (abs(cycles2 - cycles1) < 200) { 
        Serial.println(cycles2);
       } else {
         timeDiff1 = 0;
         timeDiff2 = 0;
         timeDiff3 = 0;
       }
    } else {
        timeDiff1 = 0;
        timeDiff2 = 0;
        timeDiff3 = 0; 
    }
  }

  previous = sensorValue;

  count++;

  if (count%1000 == 0) {
    //Serial.println(timeDiff1);
    //Serial.println(timeDiff2);
    //Serial.println(timeDiff3);
    //Serial.println("-----------------------");
  }

  
 
delay(10);
}
