int digitalPin = 2; // pour le relais
int analogPin = A0; // pour le capteur de l'humidité du sol
int digitalVal; // digital readings
int analogVal; //analog readings
int LedGreen = 7;
int humiditeVal;

void setup()
{
  Serial.begin(9600); // établit une communication série avec la carte Arduino pour envoyer et recevoir des données sur la voie série
	pinMode(digitalPin, OUTPUT); // configurer le comportement (entrée ou sortie) de la broche passée en paramètre
	digitalWrite(digitalPin, LOW); // écrit une valeur (HIGH ou LOW) sur une broche configurée en tant que sortie (OUTPUT).
  pinMode(LedGreen, OUTPUT);
}

void loop()
{
  analogVal = analogRead(A0); //lire la valeur retournée par le capteur de l'humidité
 	humiditeVal = map(analogVal,667,210,0,100); // map(valeur_entrée, inférieur_entrée, supérieur_entrée, inférieur_sortie, supérieur_sortie); 
 	Serial.print("Humidite : ");
 	Serial.print(humiditeVal);
 	Serial.println("%");
  
  if (humiditeVal < 20){ //si la capteur de l'humidité donne une valeur de < 20%
    digitalWrite(LedGreen, HIGH); // allumer la LED
		digitalWrite(digitalPin, HIGH);// La pompe à eau arrose la plante
    delay(2000);

    digitalWrite(digitalPin, LOW);
    digitalWrite(LedGreen, LOW);
    delay(4000);
  } else { // sinon
		digitalWrite(digitalPin, LOW); //La pompe à eau arrête l'arrosage
		digitalWrite(LedGreen, LOW); // éteindre la LED
    //delay(4000);
  }

  Serial.print ("analogVal: ");
  Serial.println (analogVal);
	delay(100);
}
