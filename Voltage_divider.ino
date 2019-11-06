float VoltageRead = 0;
float Vin = 0.0;
float Vout = 0.0;

float R1 = 20000.0;
float R2 = 10000.0;
int s = 0;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(6, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Time(s) \tVoltage");
  

}

void loop()
{
    
    VoltageRead = analogRead(A0);
    Vout = (VoltageRead*5.0)/1024.0;
    Vin = Vout /(R2/(R1+R2));
    s++;
    
  

    if (Vin<0.01) {
        Vin=0.0;
        digitalWrite(6,HIGH);
          delay(200);
          digitalWrite(6,LOW);
          delay(200);
          Serial.println("######################");      
          s=0;
    }
  
    else if(Vin< 0.9){
    digitalWrite(6,HIGH);
    Serial.print(s);
    Serial.print(" \t\t");
    Serial.println(Vin);
    delay(1000); // Wait for 1000 millisecond(s)

    }
    
  else {
    Serial.print(s);
    Serial.print(" \t\t");
    Serial.println(Vin);
    delay(1000); // Wait for 1000 millisecond(s)

    }
    
}
