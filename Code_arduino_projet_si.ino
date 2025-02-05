// Pont en H L298N
//Ports de commande du moteur B
int motorPin1 = 12;
int motorPin2 = 13;
int enablePin = 3;
 

void setup() {
    // Configuration des ports en mode "sortie"
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(enablePin, OUTPUT);
    
    // Initialisation du port série
    Serial.begin(9600);
}
 
void loop() {
    // Valeur du potentiomètre et mapping
    int sensorValue = analogRead(A0);
    int pot = map(sensorValue, 0, 1023, -255, 255);
    //
    // Sens du mouvement
    //
    if (pot > 15) // avant
    {
      digitalWrite(motorPin1, 255); 
      digitalWrite(motorPin2, 0);
      Serial.print("Avant ");
      Serial.println(pot);
    }
    else if (pot < -15) // arrière
    {
      digitalWrite(motorPin1, 0); 
      digitalWrite(motorPin2, 255);
      Serial.print("Arriere ");
      Serial.println(pot);
    }
    else // Stop (freinage)
    {
      digitalWrite(motorPin1, 0); 
      digitalWrite(motorPin2, 0);
      Serial.println("Stop");
    }
    //
    // Vitesse du mouvement
    //
    analogWrite(enablePin, abs(pot));
    Serial.println(pot);

    delay(100);
}