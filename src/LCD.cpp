#include <TFT_eSPI.h>  
#include "Image.h"

TFT_eSPI tft = TFT_eSPI();  // Create an object of the TFT class

void setup() {
  tft.init();                // Initialize TFT
  tft.fillScreen(TFT_BLACK); // Clear the screen

  tft.setSwapBytes(true);  // Set the byte order to big-endian (colors are off otherwise)
  tft.setRotation(1);      // Rotate the display by 90 degrees (so it can be displayed horizontally)

  // Draw the image at position x=10, y=10 using the defined width and height.
  tft.pushImage(10, 10, IMAGE_WIDTH, IMAGE_HEIGHT, Image);
}

void loop() {
}