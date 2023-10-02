//code
//Define the values for the stick on reciver 
#define CH1 3
#define CH2 5
//is for encoder
int encoderp = A3;
//ch1 is X direction 
int ch1Value;
//ch2 is y direction 
int ch2Value;

//enc_pos is actual position of wheel
int enc_pos_1;
int enc_pos_deg;

//wanted position of wheel
int w_pos_rad;
int w_pos_deg;

//options
int op1;
int op2val;
int op2;

//wheel direction
int direct=1;
int deg;

//where wheel is going to go
int tarval;

//
int motor1Speed;
int motor2Speed;

// Read the number of a specified channel and convert to the range provided.
// If the channel is off, return the default value
int readChannel(int channelInput, int minLimit, int maxLimit, int defaultValue){
  int ch = pulseIn(channelInput, HIGH, 30000);
  if (ch < 100) return defaultValue;
  return map(ch, 1000, 2000, minLimit, maxLimit);
}

void setup() {
  // Set up serial monitor
  Serial.begin(115200);
  
  // Set all pins as inputs
  pinMode(CH1, INPUT);
  pinMode(CH2, INPUT);
  

}

void loop() {
  //get encoder position in raw number
  enc_pos_1 = analogRead(encoderp);

  //map to degrees
  enc_pos_deg=map(enc_pos_1, 0, 1023, 0, 360);

  //read transmitted values
  ch1Value = readChannel(CH1, -100, 100, 0);
  ch2Value = readChannel(CH2, -100, 100, 0);

  //translate transmitted vaules to usful infromation 
  w_pos_rad=atan(ch2Value/ch1Value);
  w_pos_deg=(w_pos_rad*(180/3.14));

//math in terms of which dirction for wheel to turn
  op1=(enc_pos_deg-w_pos_deg);
  op2val=abs(w_pos_deg-180);
  op2=(enc_pos_deg-op2val);
  if(abs(op1)<=abs(op2)){
    direct=1;
    tarval=enc_pos_deg;
    deg=op1;
  }
  else{
    direct=-1;
    tarval=op2val;
    deg=op2;
  }

//drive formula
   
}
