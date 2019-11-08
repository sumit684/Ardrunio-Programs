
// Include Libraries
#include "Arduino.h"


// Pin Definitions
#define RELAYMODULE4CH_1_PIN_IN1	5
#define RELAYMODULE4CH_1_PIN_IN2	4
#define RELAYMODULE4CH_1_PIN_IN4	14
#define RELAYMODULE4CH_1_PIN_IN3	0
#define RELAYMODULE4CH_2_PIN_IN1	12
#define RELAYMODULE4CH_2_PIN_IN2	13
#define RELAYMODULE4CH_2_PIN_IN4	16
#define RELAYMODULE4CH_2_PIN_IN3	15



// Global variables and defines
String blehm10Str = "";
//define an array for the 4ch relay module pins
int RelayModule4ch_1Pins[] = { RELAYMODULE4CH_1_PIN_IN1, RELAYMODULE4CH_1_PIN_IN2, RELAYMODULE4CH_1_PIN_IN3, RELAYMODULE4CH_1_PIN_IN4 };
//define an array for the 4ch relay module pins
int RelayModule4ch_2Pins[] = { RELAYMODULE4CH_2_PIN_IN1, RELAYMODULE4CH_2_PIN_IN2, RELAYMODULE4CH_2_PIN_IN3, RELAYMODULE4CH_2_PIN_IN4 };
// object initialization
HardwareSerial& blehm10(Serial1);


// define vars for testing menu
const int timeout = 10000;       //define timeout of 10 sec
char menuOption = 0;
long time0;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    blehm10.begin(9600);
    //This example uses HM-10 BLE to communicate with an Android or iOS device.
    //For Android download Hm BLE Terminal from google play store, or any other BLE app.
    //For iOS download LightBlue from App Store, or any other BLE app.
    //On both apps, pair and connect to your HM-10
    //You should see this message your Smartphone 
    blehm10.println("BLE On....");
    pinMode(RELAYMODULE4CH_1_PIN_IN1, OUTPUT);
    pinMode(RELAYMODULE4CH_1_PIN_IN2, OUTPUT);
    pinMode(RELAYMODULE4CH_1_PIN_IN3, OUTPUT);
    pinMode(RELAYMODULE4CH_1_PIN_IN4, OUTPUT);
    pinMode(RELAYMODULE4CH_2_PIN_IN1, OUTPUT);
    pinMode(RELAYMODULE4CH_2_PIN_IN2, OUTPUT);
    pinMode(RELAYMODULE4CH_2_PIN_IN3, OUTPUT);
    pinMode(RELAYMODULE4CH_2_PIN_IN4, OUTPUT);
    menuOption = menu();
    
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{
    
    
    if(menuOption == '1') {
    // HM-10 BLE Bluetooth 4.0 - Test Code
    //Receive String from bluetooth device
    if (blehm10.available())
    {
    //Read a complete line from bluetooth terminal
    blehm10Str = blehm10.readStringUntil('\n');
    // Print raw data to serial monitor
    Serial.print("BT Raw Data: ");
    Serial.println(blehm10Str);
    }
    //Send sensor data to Bluetooth device  
    blehm10.println("PUT YOUR SENSOR DATA HERE");

    }
    else if(menuOption == '2') {
    // Relay Module 4-Ch #1 - Test Code
    //This loop will turn on and off each relay in the array for 0.5 sec
    for (int i = 0; i < 4; i++) { 
    digitalWrite(RelayModule4ch_1Pins[i],HIGH);
    delay(500);
    digitalWrite(RelayModule4ch_1Pins[i],LOW);
    delay(500);
    }
    }
    else if(menuOption == '3') {
    // Relay Module 4-Ch #2 - Test Code
    //This loop will turn on and off each relay in the array for 0.5 sec
    for (int i = 0; i < 4; i++) { 
    digitalWrite(RelayModule4ch_2Pins[i],HIGH);
    delay(500);
    digitalWrite(RelayModule4ch_2Pins[i],LOW);
    delay(500);
    }
    }
    
    if (millis() - time0 > timeout)
    {
        menuOption = menu();
    }
    
}



// Menu function for selecting the components to be tested
// Follow serial monitor for instrcutions
char menu()
{

    Serial.println(F("\nWhich component would you like to test?"));
    Serial.println(F("(1) HM-10 BLE Bluetooth 4.0"));
    Serial.println(F("(2) Relay Module 4-Ch #1"));
    Serial.println(F("(3) Relay Module 4-Ch #2"));
    Serial.println(F("(menu) send anything else or press on board reset button\n"));
    while (!Serial.available());

    // Read data from serial monitor if received
    while (Serial.available()) 
    {
        char c = Serial.read();
        if (isAlphaNumeric(c)) 
        {   
            
            if(c == '1') 
    			Serial.println(F("Now Testing HM-10 BLE Bluetooth 4.0"));
    		else if(c == '2') 
    			Serial.println(F("Now Testing Relay Module 4-Ch #1"));
    		else if(c == '3') 
    			Serial.println(F("Now Testing Relay Module 4-Ch #2"));
            else
            {
                Serial.println(F("illegal input!"));
                return 0;
            }
            time0 = millis();
            return c;
        }
    }
}

/*******************************************************

*    Circuito.io is an automatic generator of schematics and code for off
*    the shelf hardware combinations.

*    Copyright (C) 2016 Roboplan Technologies Ltd.

*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.

*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.

*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*    In addition, and without limitation, to the disclaimers of warranties 
*    stated above and in the GNU General Public License version 3 (or any 
*    later version), Roboplan Technologies Ltd. ("Roboplan") offers this 
*    program subject to the following warranty disclaimers and by using 
*    this program you acknowledge and agree to the following:
*    THIS PROGRAM IS PROVIDED ON AN "AS IS" AND "AS AVAILABLE" BASIS, AND 
*    WITHOUT WARRANTIES OF ANY KIND EITHER EXPRESS OR IMPLIED.  ROBOPLAN 
*    HEREBY DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT 
*    NOT LIMITED TO IMPLIED WARRANTIES OF MERCHANTABILITY, TITLE, FITNESS 
*    FOR A PARTICULAR PURPOSE, NON-INFRINGEMENT, AND THOSE ARISING BY 
*    STATUTE OR FROM A COURSE OF DEALING OR USAGE OF TRADE. 
*    YOUR RELIANCE ON, OR USE OF THIS PROGRAM IS AT YOUR SOLE RISK.
*    ROBOPLAN DOES NOT GUARANTEE THAT THE PROGRAM WILL BE FREE OF, OR NOT 
*    SUSCEPTIBLE TO, BUGS, SECURITY BREACHES, OR VIRUSES. ROBOPLAN DOES 
*    NOT WARRANT THAT YOUR USE OF THE PROGRAM, INCLUDING PURSUANT TO 
*    SCHEMATICS, INSTRUCTIONS OR RECOMMENDATIONS OF ROBOPLAN, WILL BE SAFE 
*    FOR PERSONAL USE OR FOR PRODUCTION OR COMMERCIAL USE, WILL NOT 
*    VIOLATE ANY THIRD PARTY RIGHTS, WILL PROVIDE THE INTENDED OR DESIRED
*    RESULTS, OR OPERATE AS YOU INTENDED OR AS MAY BE INDICATED BY ROBOPLAN. 
*    YOU HEREBY WAIVE, AGREE NOT TO ASSERT AGAINST, AND RELEASE ROBOPLAN, 
*    ITS LICENSORS AND AFFILIATES FROM, ANY CLAIMS IN CONNECTION WITH ANY OF 
*    THE ABOVE. 
********************************************************/