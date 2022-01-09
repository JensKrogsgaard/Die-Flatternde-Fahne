#include <Servo.h>   //Die Servobibliothek wird aufgerufen. Sie wird benötigt, damit die Ansteuerung des Servos vereinfacht wird.

Servo servofahne;    //Erstellt fuer das Programm einen Servo mit dem Namen "servofahne"

int taster = 6;        //Das Wort "taster" steht jetzt für den Wert 6.
int LEDrot = 9;        //Das Wort "LEDrot" steht jetzt für den Wert 9.
int LEDrotA = 5;       //Das Wort "LEDrotA" steht jetzt für den Wert 5.
int servo = 11;        //Das Wort "servo" steht jetzt für den Wert 11.
int Wiederholung = 20;  //Der Wert in dem Wort "Wiederholung" gibt an, wie oft der Vorgang im scetch wiederholt wird.
int i =1;              //Der Buchstabe "i" zählt wie oft die Schleife "Wiederholung" durchlaufen wurde.
int tasterstatus = 0;  //Das Wort "tasterstatus" steht jetzt zunachst für den Wert 0. Später wird unter dieser Variable gespeichert, ob der Taster gedrückt ist oder nicht.
int pos=0;

void setup()           //Hier beginnt das Setup.
{
  pinMode(LEDrot, OUTPUT);   //Der Pin mit der LED (Pin 4) ist jetzt ein Ausgang.
  pinMode(taster, INPUT );   //Der Pin mit dem Taster (Pin 5) ist jetzt ein Eingang.
  pinMode(LEDrotA, OUTPUT);  //Der Pin mit der LED (Pin 9) ist jetzt ein Ausgang. 
  pinMode(servo, OUTPUT);    //Der Pin mit dem Servo (Pin 11) ist jetzt ein Ausgang.
  servofahne.attach(servo);  //Das Setup enthält die Information, dass das Servo an der Steuerleitung (braun) mit Pin 11 verbunden wird.
}

void loop()
{                                         //Mit dieser Klammer wird der Loop-Teil geöffnet.
  tasterstatus = digitalRead(taster);     //Hier wird der Pin 4 ausgelesen (Befehl:digitalRead).
                                          //Das Ergebnis wird unter der Variable "tasterstatus" mit dem Wert "HIGH" für 5 Volt oder "LOW" für 0 Volt gespeichert.
// tasterstatus=HIGH;
  if (tasterstatus == HIGH)               //Verarbeitung: Wenn der taster gedrückt ist (Das Spannungssignal ist hoch)
  {                                       //Programmabschnitt des IF-Befehls öffnen.
    digitalWrite(LEDrot, HIGH);           //dann soll die rote LED leuchten
    digitalWrite(LEDrotA, HIGH);          //dann soll die rote LED auf der Leiterplatte leuchten   
   {    
    for (i = 1; i <= Wiederholung; i++) 
     {
     servofahne.write(0);
      for (pos = 90; pos >= 70; pos -= 1) // fährt von 90 Grad bis 70 Grad in Stufen von 1 Grad
      { servofahne.write(pos);           // sagt dem Servo zur Position der Variablen 'pos'
        delay(30);                       // wartet 30ms damit der Servo seine Position erreicht               
      }
   
    {
      for (pos = 70; pos <= 80; pos += 1) // fährt von 70 Grad bis 80 Grad
                                          // in Stufen von 1 Grad
      { servofahne.write(pos);            // sagt dem Servo zur Position der Variablen 'pos' zu fahren
        delay(20);                        // wartet 20 ms damit der Servo seine Position erreicht
      }
    }
      
    {
      for (pos = 80; pos >= 60; pos -= 1) // fährt von 80 Grad bis 60 Grad
                                          // in Stufen von 1 Grad
      { servofahne.write(pos);            // sagt dem Servo zur Position der Variablen 'pos' zu fahren
        delay(40);                        // wartet 40ms damit der Servo seine Position erreicht
      }
    }
       
    {
      for (pos = 60; pos <= 90; pos += 1) // fährt von 60 Grad bis 90 Grad
                                          // in Stufen von 1 Grad
      { servofahne.write(pos);            // sagt dem Servo zur Position der Variablen 'pos' zu fahren
        delay(30);                        // wartet 30ms damit der Servo seine Position erreicht
      }
    }
      
    {
      for (pos = 90; pos >= 70; pos -= 1) // fährt von 90 Grad bis 70 Grad zurück (wippen)
                                          // in Stufen von 1 Grad
      { servofahne.write(pos);            // sagt dem Servo zur Position der Variablen 'pos' zu fahren
        delay(20);                        // wartet 20ms damit der Servo seine Position erreicht
      }
    }
        
    {
      for (pos = 70; pos <= 90; pos += 1) // fährt von 70 Grad bis 90 Grad
                                          // in Stufen von 1 Grad
      { servofahne.write(pos);            // sagt dem Servo zur Position der Variablen 'pos' zu fahren
        delay(30);                        // wartet 30ms damit der Servo seine Position erreicht
      }
    }  
     }
    {
      for (pos = 90; pos >= 75; pos -= 1) // fährt von 90 Grad bis 75 Grad zurück (Grundstellung)
                                          // in Stufen von 1 Grad
      { servofahne.write(pos);            // sagt dem Servo zur Position der Variablen 'pos' zu fahren
        delay(30);                        // wartet 30ms damit der Servo seine Position erreicht
      }
    }
    }
      {
      for (pos = 75; pos <= 90; pos += 1) // fährt von 75 Grad bis 90 Grad
                                          // in Stufen von 1 Grad
        { servofahne.write(pos);          // sagt dem Servo zur Position der Variablen 'pos' zu fahren
          delay(40);                      // wartet 40ms damit der Servo seine Position erreicht
        }
     }
        delay(10000);                      // Pause von 10 Sekunden, damit nicht laufend gedrückt wird
  }   
     
    else                              //...ansonsten...
  {                                   //Programmabschnitt des else-Befehls oeffnen.}
    digitalWrite(LEDrot, LOW);        //...soll die LED aus sein.
    digitalWrite(LEDrotA, LOW);       //dann soll die rote LED am Arduino aus sein   
    servofahne.write(90);             //Servo Position 1 ansteuern mit dem Winkel 90°
  }                                   //Programmabschnitt des else-Befehls schliessen.
}
