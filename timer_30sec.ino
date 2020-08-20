
unsigned long prevMillis;
int count = 30;
int tapCounter = 0;
int counternow = 0;
boolean countdownVariable = false;


void setup() {
   prevMillis = millis();  // get the time at the start
} 


void loop() {
       buttonprog(); 
       if(countdownVariable){  // IF THE countdownVariable IS TRUE THEN DO THIS
             countdown();           // START COUNTDOWN FUNCTION
       }  
} 

  // THIS IS THE BUTTON SENSING PROGRAM
void buttonprog() {
      unsigned long curMillis = millis();   
      int x;
      x = analogRead (0);
      if (x < 600){
           tapCounter+=1;
           prevMillis = millis();
           count = 31; // SET COUNTERS COUNT TO 31 TO MAKE UP FOR THE 1 SECOND DROP AT START
 
           countdownVariable = true; // START THE COUNTDOWN
      
      }
}

// countdown timer of 30 seconds, using millis and


void countdown() {
    delay(150);

    unsigned long curMillis = millis();
    //  if one second has passed
    if(curMillis - prevMillis >= 1000){
        count -= 1;
        
        prevMillis += 1000;
        // normally prevMillis = curMillis
        // but by adding 1000 insead we prevent
        // accumulation of any mis-timing.
    }
    if(count == 0){
       
        // CALL THE BUZZER HERE SOMEWHERE - tone(piezoPin, 1000, 500);
        // while(1); [DONT, lock up the board until reset]
        countdownVariable = false; // stops the counter
    }   
}





