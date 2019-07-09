int i=0;
int layer[4] = {A0,A1,A2,A3};

void setup() 
{
  
  DDRD = (DDRD | 0b01111101); //data bus D0 D2 to D7
  DDRB = (DDRB | 0b00111111); //data bus D8 to D10 selection D11 to D13
  DDRC = (DDRC | 0b00001111); //layer selection 
  PORTB = PORTB & 0b11000111;

  for(i=0;i<4;i++)
  {
    digitalWrite(layer[i],1);
  }
}


void on1()
{
  /////////////////////////////////
  PORTD = PORTD & 0b10001010;
  PORTB = PORTB & 0b11111000;
  
}

void off1()
{
   
   PORTD = PORTD | 0b01110101; //set bit
   PORTB = PORTB | 0b00000111; 
}
void Write_low_000()
{
   PORTB = PORTB & 0b11000111; //selection 000
}

void Write_low_001()
{
  PORTB = PORTB | 0b00001000; //selection 001
  PORTB = PORTB & 0b11101111;
}
void Write_low_010()
{
  PORTB = PORTB | 0b00010000; //selection 010
}
void turnEverythingOff()
{
  Write_low_000();// selection 000
  off1();
  Write_low_001();
  Write_low_000();
  
   for(i=0;i<4;i++)
  {
    digitalWrite(layer[i],0);
  }
}
void turnEverythingOn()
{
   Write_low_000();// selection 000
   on1();
   Write_low_001();
   Write_low_000();

   for(i=0;i<4;i++)
  {
    digitalWrite(layer[i],1);
  }
}


void turnOnAndOffAllByLayerUpAndDownNotTimed()
{
  int x = 75;
  for(int i = 5; i != 0; i--)
  {
    turnEverythingOn();
    for(int i = 4; i!=0; i--)
    {
      digitalWrite(layer[i-1], 0);
      delay(x);
    }
    for(int i = 0; i<4; i++)
    {
      digitalWrite(layer[i], 1);
      delay(x);
    }
      for(int i = 0; i<4; i++)
    {
      digitalWrite(layer[i], 0);
      delay(x);
    }
    for(int i = 4; i!=0; i--)
    {
      digitalWrite(layer[i-1], 1);
      delay(x);
    }
  }
}
void turnOnAndOffAllByColumnSideways()
{
    int x = 75;
    turnEverythingOff();
    delay(100);
    //turn on layers
    for(int i = 0; i<4; i++)
    {
      digitalWrite(layer[i], 1);
    }
    for(int y=0;y<4;y++)
    {
       Write_low_000();// selection 000
       PORTD = PORTD & 0b11001010; //first row on
       PORTB = PORTB | 0b00000111; 
       Write_low_010();
       delay(x);
       
       Write_low_000();
       PORTD = PORTD & 0b10001010; //second row on
       PORTB = PORTB & 0b11111000;
       Write_low_010();
       delay(x);
       
       Write_low_001();
       PORTD = PORTD | 0b01000000;
       PORTD = PORTD & 0b11001010; //third row on
       PORTB = PORTB | 0b00000111; 
       Write_low_010();
       delay(x);

       Write_low_001();
       PORTD = PORTD & 0b10001010; //fourth row on
       PORTB = PORTB & 0b11111000;
       Write_low_010();
       delay(x);
    
       ///////////////////////////////////////////
    
       Write_low_000();// selection 000
       PORTD = PORTD | 0b00110101; //first row off
       PORTB = PORTB & 0b11111000;
       Write_low_010();
       delay(x);
       
       Write_low_000();
       PORTD = PORTD | 0b01110101; //second row off
       PORTB = PORTB | 0b00000111; 
       Write_low_010();
       delay(x);
       
       Write_low_001();
       PORTD = PORTD & 0b10111111;
       PORTD = PORTD | 0b00110101; //third row off 
       PORTB = PORTB & 0b11111000;
       Write_low_010();
       delay(x);
       
       Write_low_001();
       PORTD = PORTD | 0b01000000;
       PORTD = PORTD | 0b01110101; //fourth row off
       PORTB = PORTB | 0b00000111; 
       Write_low_010();
       delay(x);
   
       /////////////////////////////////////////////
    
       Write_low_001(); 
       PORTD = PORTD & 0b10111111; //fourth row on
       PORTB = PORTB & 0b11111000;
       Write_low_010();
       delay(x);
       
       Write_low_001();
       PORTD = PORTD & 0b10001010; //third row on
       Write_low_010();
       delay(x);
      
       Write_low_000();// selection 000
       PORTD = PORTD | 0b00110101;
       PORTD = PORTD & 0b10111111;//second row on
       PORTB = PORTB & 0b11111000;
       Write_low_010();
       delay(x);

       Write_low_000();// selection 000
       PORTD = PORTD & 0b10001010; //first row on
       PORTB = PORTB & 0b11111000;
       Write_low_010();
       delay(x);

       ///////////////////////////////

       Write_low_001(); 
       PORTD = PORTD | 0b01000000; //fourth row off
       PORTB = PORTB | 0b00000111; 
       Write_low_010();
       delay(x);
       
       Write_low_001();
       PORTD = PORTD | 0b00110101; //third row off 
       Write_low_010();
       delay(x);
       
       Write_low_000();// selection 000
       PORTD = PORTD & 0b10001010;
       PORTD = PORTD | 0b01000000; //second row off
       PORTB = PORTB | 0b00000111; 
       Write_low_010();
       delay(x);

       Write_low_000();// selection 000
       PORTD = PORTD | 0b00110101; //first row off
       Write_low_010();
       delay(x);
       
    }

}

void FireWork()
{
    int x = 75;
    turnEverythingOff();
    delay(100);
    for(int w=0;w<5;w++)
    { 
        turnEverythingOff();
        Write_low_000(); 
        PORTD = PORTD & 0b11111111; //fourth row on
        PORTB = PORTB & 0b11111110;
        Write_low_010();
      
        for(i=0;i<4;i++)
        {
          digitalWrite(layer[i],1);
          delay(100);
          digitalWrite(layer[i],0);
        }
      
        Write_low_000(); 
        PORTB = PORTB & 0b11111100;
        Write_low_001();
        PORTB = PORTB | 0b00000111;
        PORTD = PORTD & 0b11101011;
        Write_low_010();
        digitalWrite(layer[3],1);
        delay(x);
      
        
        Write_low_000(); 
        PORTD = PORTD & 0b10001010;
        PORTB = PORTB & 0b11111011;
        Write_low_001(); 
        PORTB = PORTB & 0b11111000;
        PORTD = PORTD | 0b00010100;
        PORTD = PORTD & 0b10011110;
        Write_low_010();
      
        for(int i=4;i!=0;i--)
        { 
            digitalWrite(layer[i-1],1); 
            delay(x);
        }
        for(int i=0;i<4;i++)
        {
            digitalWrite(layer[i],0); 
        }
    }
    
}
void loop()
{
   turnOnAndOffAllByLayerUpAndDownNotTimed();
   turnOnAndOffAllByColumnSideways();
   FireWork();
}

