//code
//Define the values for the stick on reciver and encoder 
#define CH1 3
#define CH2 5
int encoder = A0
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
  enc_pos_1=analogRead(enconder);

  //map to degrees
  enc_pos_deg=map(enc_pos_1, 0, 1023, 0, 360);

  //read transmitted values
  ch1Value = readChannel(CH1, -100, 100, 0);
  ch2Value = readChannel(CH2, -100, 100, 0);

  //translate transmitted vaules to usful infromation 
  w_pos_rad=atan(ch1Value/ch2Value);
  w_pos_deg=(w_pos_rad*(180/3.14));

  //set wheel direction

}
