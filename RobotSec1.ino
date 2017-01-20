/*
 *              
 *              What it does :
 *    Step 1: Initialisation
 *      We first setup constant variables, or some variable used only for better referencing of the object
 *      We then setup normal variables that we modifie in the code below
 *      Finally, we create a robot (or Servo) object, that we will use to move our hand
 *    Step 2: setup
 *      Setup is a reserved function of the robot that will only start when the robat start, but it simply put our object and say where it is and if it is an output or input
 *    Step 3: loop
 *      loop is another reserved function of the robot that always loop until the robot closes. It is the core of the code, as it tell to the robot what to do
 *      step 3.1: read the state of the pushbutton value
 *        this portion check if the button is push, then reset the variables
 *      step 3.2: if (buttonState == HIGH) { and  if (buttonState2 == HIGH) {
 *        this other portion is the quiz start... it tell what do to when the button is pressed
 *        The if portion tell what to do if it is a correct awnser
 *        The else part does the oposite
 *    Step 4: HMquestions
 *      HMquestion is a variable made to check if it is a good one or a bad one.
 *      step 4.1: int question, int button and boolean good = false
 *        those are variables initialisation... The first and second one depend on what is put on in loop though
 *      step 4.2: switch
 *        The switch is a selector... that mean, for our code, that it will choose que good awnser depending on what question we are from. Just remember that we have to use the break to end that part of the switch
 *      step 4.3: return
 *        that last part of code is really important, as it will give out to loop if it is a good awnser or a bad awnser.
 *        
 *             Input and output:
 *         output: led: LED pin number = 13
 *         output: myservo: Robot pin number = 9
 *         input: button: button pin number = 2 
 *         input: button2: button pin number = 4
 *           
 *                         
 *              Code Creator:
 *         -https://www.arduino.cc/en/Tutorial/Button (For button pressing)
 *         -https://www.arduino.cc/en/Tutorial/Sweep (For the mouvement of the hand)
 *         -Luis Hugo Garcia (For mixing the above codes toghether)
 *         -Nathan Marien (for the quiz code)
 * 
 * 
 */

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pinconst 
const int buttonPin2 = 4;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status 
int buttonState2 = 0;         // variable for reading the pushbutton status
int questionNUMB = 1;        // question we are in
#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
 
 
void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT); 
  pinMode(buttonPin2, INPUT);
   myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin); 
  buttonState2 = digitalRead(buttonPin2);
  myservo.write(78);              // tell servo to go to position in variable 'pos' 
    digitalWrite(ledPin, LOW); 
  
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    if (HMquestions(questionNUMB,1)) {
      // true
      digitalWrite(ledPin, HIGH); 
        myservo.write(180);              // put the hand in good position 
      delay(1000);                       // waits 15ms for the servo to reach the position 
    questionNUMB++;
    }
    else {
      // false
       myservo.write(0);              // put the hand in bad position 
      delay(1000);                       // waits 15ms for the servo to reach the position
    }
  } 
    // if it is, the buttonState is HIGH:
  if (buttonState2 == HIGH) {
    if (HMquestions(questionNUMB, 2)) {
      // true
      digitalWrite(ledPin, HIGH); 
        myservo.write(180);              // put the hand in good position 
      delay(1000);                       // waits 15ms for the servo to reach the position 
      questionNUMB++;
    }
    else {
      // false
       myservo.write(0);              // put the hand in bad position 
      delay(1000);                       // waits 15ms for the servo to reach the position
    }
  }
 
}
/********************************************************************************
 * Opon this point, Everything is made by me (Nathan) for the quiz interactivity
 ********************************************************************************/
boolean HMquestions(int question, int button) { // question checking
boolean good = false;
  switch (question) {
    case (1) : {
      if (button = 1) {
        good = true;
        break;
      }
    }
    default : {
      good = false;
      break;
    }
  }
return good;
}

/*
 *            Question list
 *          1.
 *          2. 
 *          3.
 *          4.
 *          5.
 *          6.
 *          7.
 *          8.
 *          9.
 *         10.
 *         
 *            Awnser list
 *          1.
 *          2. 
 *          3.
 *          4.
 *          5.
 *          6.
 *          7.
 *          8.
 *          9.
 *         10.
 */
