#include <IRremote.h>

#define START_GAME_KEY 0xFF629D
#define RESET_KEY 0xFF18E7
#define QUIT_KEY 0xFFC23D

// constants of the pins to be filled out
const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;
const int RED_BUTTON = 7;
const int GREEN_BUTTON = 6;
const int BLUE_BUTTON = 5;
const int RECV_PIN = 3;
const int PIEZO_PIN = 12;
IRrecv irrecv(RECV_PIN);  // Initialize IR Library
decode_results results;   // Initialize IR Library

// In-game variables
boolean isOn = false;
int score;
boolean inProgress; // = true
long startTime;

void setup() {
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(RED_BUTTON, INPUT);
  pinMode(BLUE_BUTTON, INPUT);
  pinMode(GREEN_BUTTON, INPUT);
  irrecv.enableIRIn();  // Start the receiver
  Serial.begin(9600);
  Serial.println("Welcome to the Color Game! Please press the power button to start the game.");
  Serial.println("Press the quit key to quit at any time.");
  isOn = false;
}

void loop() {
  if (irrecv.decode(&results)) {
    irrecv.resume();    // Receive the next value
    // Power switch
    if (results.value == START_GAME_KEY) {
      if (isOn == true) {
        Serial.println("Turning off.");
        isOn = false;
        Serial.println("*****************************************************************************************************");
        Serial.println("Game shut down");
      }
      else if (isOn == false) {
        Serial.println("Turning on.");
        isOn = true;
        Serial.println("*****************************************************************************************************");
        Serial.println("Game starts now!");
        score = 0;
        startTime = millis();
      }
    }
    if (isOn == true) {
      if (results.value == RESET_KEY) {
        Serial.println("*****************************************************************************************************");
        Serial.println("Game has been reset. Prepare for a new game.");
        score = 0;
      }
      else if (results.value == QUIT_KEY) {
        Serial.print("Game over. Your score was: ");
        Serial.println(score);
        score = 0;
        isOn = false;
      }
    }
  }
  if (isOn == true) {
    inProgress = true;
  }
  else {
    inProgress = false;
  }
  if (inProgress) {
    Serial.println("Match the color of the LED with the buttons.");
    String color = randomColor();
    //Serial.println(color);
    if (color == "red") {
      analogWrite(RED_PIN, 255);
      analogWrite(BLUE_PIN, 0);
      analogWrite(GREEN_PIN, 0);
    }
    else if(color == "blue") {
      analogWrite(RED_PIN, 0);
      analogWrite(BLUE_PIN, 255);
      analogWrite(GREEN_PIN, 0);
    }
    else if (color == "green") {
      analogWrite(RED_PIN, 0);
      analogWrite(BLUE_PIN, 0);
      analogWrite(GREEN_PIN, 255);
    }
    else if (color == "yellow") {
      analogWrite(RED_PIN, 255);
      analogWrite(BLUE_PIN, 0);
      analogWrite(GREEN_PIN, 255);
    } 
    else if (color == "cyan") {
      analogWrite(RED_PIN, 0);
      analogWrite(BLUE_PIN, 255);
      analogWrite(GREEN_PIN, 255);
    }
    else if (color == "purple") {
      analogWrite(RED_PIN, 255);
      analogWrite(BLUE_PIN, 255);
      analogWrite(GREEN_PIN, 0);
    }
    else if (color == "white") {
      analogWrite(RED_PIN, 255);
      analogWrite(BLUE_PIN, 255);
      analogWrite(GREEN_PIN, 255);
    }
    boolean buttonsPressed = false;
    boolean redPressed = false;
    boolean bluePressed = false;
    boolean greenPressed = false;
  
    while (buttonsPressed == false) {
      if (digitalRead(RED_BUTTON) == HIGH) {
        redPressed = true;
      }
      if (digitalRead(BLUE_BUTTON) == HIGH) {
        bluePressed = true;
      }
      if (digitalRead(GREEN_BUTTON) == HIGH) { 
        greenPressed = true;
      }
      
      if (color == "red") {
        if (redPressed == true) {
          buttonsPressed = true;
          score++;
        }
      }
      else if (color == "blue") {
        if (bluePressed == true) {
          buttonsPressed = true;
          score++;
        }
      }
      else if (color == "green") {
        if(greenPressed == true) {
          buttonsPressed = true;
          score++;
        }
      }
      else if (color == "yellow") {
        if(redPressed == true && greenPressed == true) {
          buttonsPressed = true;
          score++;
        }
      }
      else if (color == "cyan") {
        if(bluePressed == true && greenPressed == true) {
          buttonsPressed = true;
          score++;
        }
      }
      else if (color == "purple") {
        if(redPressed == true && bluePressed == true) {
          buttonsPressed = true;
          score++;
        }
      }
      else if (color == "white") {
        if(redPressed == true && bluePressed == true && greenPressed == true) {
          buttonsPressed = true;
          score++;
        }
      }
    }
    Serial.print("Score: ");
    Serial.println(score); //Print the score
    //Turn lights off to set up for next color
    analogWrite(RED_PIN, 0);
    analogWrite(BLUE_PIN, 0);
    analogWrite(GREEN_PIN, 0);
    //Delay so people have time to stop pressing the button.
    delay(500);

    if (millis() - startTime >= 20000) {
      Serial.println("Game over!");
      analogWrite(PIEZO_PIN, 255);
      delay(2000);
      analogWrite(PIEZO_PIN, 0);
      Serial.print("Your score was: ");
      Serial.println(score);
      isOn = false;
    }
  }
}

String randomColor() {
 String color;
 while (true) {
  int rand = random(0, 1000);
  rand = rand % 7;
  if (rand == 0) {
    color = "red"; //Set color to red
    return color;
  }
  else if( rand == 1) {
    color = "blue"; //Set color to blue
    return color;
  }
  else if (rand == 2) {
    color = "green"; //Set color to green
    return color;
  }
  else if (rand == 3) {
    color = "yellow"; //Set color to yellow
    return color;
  }
  else if (rand == 4) {
    color = "cyan"; //Set color to cyan
    return color;
  }
  else if (rand == 5) {
    color = "purple"; //Set color to purple
    return color;
  }
  else if (rand == 6) {
    color = "white"; //Set color to white
    return color;
  }
 }
}
