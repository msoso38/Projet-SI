// Pont en H L298N
//Ports de commande du moteur B
int motorPin1 = 12;
int motorPin2 = 13;
int enablePin = 3;
 
// Vitesse du moteur
int state = 0;

void setup() {
    // Configuration des ports en mode "sortie"
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(enablePin, OUTPUT);
    
    // Initialisation du port série
    Serial.begin(9600);
}
 
void loop() {
    // Valeur du potentiomètre
    int sensorValue = analogRead(A0);
    int poto = map(sensorValue, 0, 1023, -255, 255);

    // Lecture de l'entier passé au port série
    state = poto;
    //
    // Sens du mouvement
    //
    if (state > 0) // avant
    {
      digitalWrite(motorPin1, 255); 
      digitalWrite(motorPin2, 0);
      Serial.print("Avant ");
      Serial.println(state);
    }
    else if (state < 0) // arrière
    {
      digitalWrite(motorPin1, 0); 
      digitalWrite(motorPin2, 255);
      Serial.print("Arriere ");
      Serial.println(state);
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
    analogWrite(enablePin, abs(state));
    Serial.println(poto);

    delay(100);
}