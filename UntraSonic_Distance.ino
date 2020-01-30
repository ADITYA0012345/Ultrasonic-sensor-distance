const int vcc = A3; 
const int trig = A2;
const int echo = A1; 
const int gnd = A0;

long duration;                           
int distance;

void setup() {
 
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
pinMode(vcc, OUTPUT);
pinMode(gnd, OUTPUT);

digitalWrite(vcc, HIGH);              
digitalWrite(gnd,LOW);               

Serial.begin(9600);
}

void loop() {
        
  
        digitalWrite(trig, LOW);              
        delayMicroseconds(2);                 

        digitalWrite(trig, HIGH);             
        delayMicroseconds(10);                
        digitalWrite(trig, LOW);

        duration = pulseIn(echo, HIGH);       
                                              
        distance = duration*0.034/2;
        
  // speed of sound = 340 m/s
  // implies 0.034 cm/us
  // distance = (speed * time) / 2

  Serial.print("Distance: ");
  Serial.println(distance);                   
  
}
