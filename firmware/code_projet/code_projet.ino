//Roboduino Motor shield utilise les Pin 4 à 7
int PWM1 = 5;
int DIR1 = 4;
int PWM2 = 6;
int DIR2 = 7;
// Définition des broches du HC-SR04(capteur)
const int trigPin = 9;
const int echoPin = 10;
// Seuil de distance en cm
const int distanceSeuil = 10;

//Fontion pour le controle des moteurs 1 et 2 (0-255, HIGH/LOW), 0 pour l'arrêt et 255 pour la vitesse maximale
void Motor1(int pwm, boolean reverse) 
{
  analogWrite(PWM1, pwm); 
  if (reverse)  
  {
    digitalWrite(DIR1, HIGH);
  }
  else  
  {
    digitalWrite(DIR1, LOW);
  }
}

void Motor2(int pwm, boolean reverse) 
{
  analogWrite(PWM2, pwm);
  if (reverse)  
  {
    digitalWrite(DIR2, HIGH);
  }
  else  
  {
    digitalWrite(DIR2, LOW);
  }
}

void setup() 
{
  int i;
  for (i = 4; i <= 7; i++)    //Pour Roboduino Motor Shield
  {
    pinMode(i, OUTPUT);       //regle pin 6,7,8,9 to output mode(moteurs)    
  }
  pinMode(trigPin, OUTPUT);   //regle pin 9,10 to output mode(capteur)
  pinMode(echoPin, INPUT);
}

void loop() 
{
  int x, delay_en;
  char val;
  long duration;
  int distance;
    
  // Mesure de la distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
    
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  
  // Si il detecte un obstacle 
  if (distance > 0 && distance <= distanceSeuil) 
  {
    // Changer de direction (tourner à droite)
    Motor1(100, true);
    Motor2(100, false);
  } 
  else //Sinon il continue d'avancer
  {
    // Avancer
    Motor1(100, true); //On peut changer la vitesse du moteur en modifiant 100 par 0-255
     Motor2(100, true);
  }
}

//Commande pour deplacer le robot
/*
// Avancer
  Motor1(100, true); 
  Motor2(100, true);
// reculer 
  Motor1(100, false);
  Motor2(100, false);
//tourner à gauche
  Motor1(100, false);
  Motor2(100, true);          
// tourner à droite
  Motor1(100, true);
  Motor2(100, false);
// S'arrêter 
  Motor1(0, false);
  Motor2(0, false);
*/