/*********************************************************************************
 *  MIT License
 *  
 *  Copyright (c) 2020-2024 Gregg E. Berman
 *  
 *  https://github.com/HomeSpan/HomeSpan
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 *  
 ********************************************************************************/

////////////////////////////////////////////////////////////
//                                                        //
//    HomeSpan: A HomeKit implementation for the ESP32    //
//    ------------------------------------------------    //
//                                                        //
// Example 10: Controlling a full-color RGB LED           //
//                                                        //
//                                                        //
////////////////////////////////////////////////////////////

// See also https://johnmu.com/controlling-5050-led-strip-with-esp32 for wiring inspiration.
// See also https://help.sinric.pro/pages/tutorials/light/LED-Stripe-5050 for wiring inspiration.

#include "HomeSpan.h"
#include "DEV_LED.h"

const int GREENPIN = 19;
const int REDPIN = 20;
const int BLUEPIN = 21;
const int STATUSPIN = 8;   // Builtin RGB LED
const int CONTROLPIN = 9;  // BOOT Button on ESP32-C6

void setup() {

  // Example 10 illustrates how to control an RGB LED to set any color and brightness.
  // The configuration below should look familiar by now.  We've created a new derived Service,
  // called DEV_RgbLED to house all the required logic.  You'll find all the code in DEV_LED.h.
  // For completeness, this configuration also contains an on/off LED and a dimmable LED as shown
  // in prior examples.

  Serial.begin(115200);
  homeSpan.setSketchVersion("1.0.1");
  homeSpan.enableOTA();
  // homeSpan.setStatusPixel(STATUSPIN);
  // homeSpan.setControlPin(CONTROLPIN);
  homeSpan.begin(Category::Bridges, "HomeSpan LED Bridge 1");
  // homeSpan.setLogLevel(1);
  // Serial.printf("Log Level: %d\n", homeSpan.getLogLevel());

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Identify();

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Identify();
  new Characteristic::Name("RGB LED Strip");
  new DEV_RgbLED(REDPIN, GREENPIN, BLUEPIN);  // Create an RGB LED attached to pins 20,21,22 (for R, G, and B LED anodes)

}  // end of setup()

//////////////////////////////////////

void loop() {

  homeSpan.poll();

}  // end of loop()
