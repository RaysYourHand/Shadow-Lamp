const int n_red = 3;
const int n_green = 5;
const int n_blue = 6;

const int blue_led = 2;
const int yellow_led = 4;

const int btn = 8;

int buttonState = 0;
int ledcolor = 0;
void setup() {
  pinMode(blue_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);

  pinMode(n_red, OUTPUT);
  pinMode(n_green, OUTPUT);
  pinMode(n_blue, OUTPUT);

  Serial.begin(9600);
  pinMode(btn, INPUT);
}

void loop() {
  
  buttonState = digitalRead(btn);

  if(buttonState == LOW){
    for( int i = 0 ; i < 10 ; i++){
      ledcolor ++;
      if(ledcolor >=8 ){
        ledcolor = 0;
      }
      delay(i*50);
      showColor(ledcolor);
      delay(i*50);
    }
    int temp = ledcolor;
    for(int j = 0; j < 8 ; j++){
      ledcolor = 0;
      delay(25);
      showColor(ledcolor);
      delay(25);
      ledcolor = temp;
      delay(25);
      showColor(ledcolor);
      delay(25);
    }
    ledcolor = temp;
    delay(1000);
  }
  else{
    ledcolor ++;
    if(ledcolor >=8 ){
        ledcolor = 0;
    }
    delay(100);
    showColor(ledcolor);
    delay(100);
  }
}
void showColor(int ledcolor){
    if(ledcolor == 0){
  digitalWrite(n_red, HIGH);
  digitalWrite(n_green, HIGH);
  digitalWrite(n_blue, HIGH);}

  else if(ledcolor == 1){
  digitalWrite(n_red, LOW);
  digitalWrite(n_green, HIGH);
  digitalWrite(n_blue, HIGH);}  

  else if(ledcolor == 2){
  digitalWrite(n_red, HIGH);
  digitalWrite(n_green, LOW);
  digitalWrite(n_blue, HIGH);}  

  else if(ledcolor == 3){
  digitalWrite(n_red, HIGH);
  digitalWrite(n_green, HIGH);
  digitalWrite(n_blue, LOW);}  

  else if(ledcolor == 4){
  digitalWrite(n_red, LOW);
  digitalWrite(n_green, HIGH);
  digitalWrite(n_blue, HIGH);} 

  else if(ledcolor == 5){
  digitalWrite(n_red, LOW);
  digitalWrite(n_green, HIGH);
  digitalWrite(n_blue, LOW);} 

  else if(ledcolor == 6){
  digitalWrite(n_red, HIGH);
  digitalWrite(n_green, LOW);
  digitalWrite(n_blue, LOW);} 

  else if(ledcolor == 7){
  digitalWrite(n_red, LOW);
  digitalWrite(n_green, LOW);
  digitalWrite(n_blue, LOW);} 
  
  else if(ledcolor == 8){
    ledcolor = 0;
  }
}
