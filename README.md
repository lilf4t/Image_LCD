# How to upload an image on a TFT LCD shield with an ESP32.

For this example i'm using 2.8" TFT LCD Shield connected to an ESP32 to display an image.

# Pin config
![circuit_image](https://github.com/user-attachments/assets/38ae7410-2e3d-42ea-8c24-bc39997436ca)

|  LCD | ESP32 Pins                                                |
|-----------------|------------------------------------------------|
| GND             | GND                                            |
| 5V              | 5V                                             |
| 3V3             | 3V3                                            |
| LCD_RST         | GPIO26                                         |
| LCD_CS          | GPIO27                                         |
| LCD_RS          | GPIO14                                         |
| LCD_WR          | GPIO12                                         |
| LCD_RD          | GPIO13                                         |
| LCD_D0          | GPIO16                                         |
| LCD_D1          | GPIO4                                          |
| LCD_D2          | GPIO23                                         |
| LCD_D3          | GPIO22                                         |
| LCD_D4          | GPI21                                          |
| LCD_D5          | GPIO19                                         |
| LCD_D6          | GPIO18                                         |
| LCD_D7          | GPIO17                                         |


# Library
I'm using TFT_eSPI by Bodmer, but I had to change a few things so it could work.

Navigate to libdeps --> TFT_eSPI --> User_Setup.h
Uncomment this bit of code ```#define TFT_PARALLEL_8_BIT``` if you're not using SPI (which you're not if you're using the same pin config as above)
![image](https://github.com/user-attachments/assets/15ec396c-1d72-4013-bd58-f8fb1cd46199)

Next, you want to specify the right pins in User_Setup.h

Underneath this comment ```// ######       EDIT THE PINs BELOW TO SUIT YOUR ESP32 PARALLEL TFT SETUP        ######```
you want to add the pins.
![image](https://github.com/user-attachments/assets/9b8d1f54-3e21-43d9-b8e0-a3e9ab953fc6)

Also, you might want to change the driver accordingly to your TFT, just comment out the one you want to use and comment the others (I didn't have to change mine).
![image](https://github.com/user-attachments/assets/f70eb238-86b2-4725-88aa-fe9d7201fa06)

# Upload image

There's already an image prepared in the code. If you want to use your own, then follow these steps.
1. Choose an image and change the size of the image to match your display size (mine is 320x240, the size is also coded in the Image.h file).
2. Use an LCD image converter, for instance: https://lcd-image-converter.riuson.com/en/about/  (you could use the SD card to store and display the image, I didn't in this example)
3. Go to options --> conversion. Choose the right preset (I'm using color R5G6B5).
4. Still in conversion, go to Image and choose block size 16 bit.
5. Go to File --> convert, it will save it as a C file.
6. Open the C file and copy the hex dump, aka the bitmap image data (each 0x value corresponds to a pixel, in our chosen format R5G6B5 uses 16 bits per pixel, this is essentially the image in pixels.)
7. Go to the code in Image.h

```
static const uint16_t Image[IMAGE_WIDTH * IMAGE_HEIGHT] PROGMEM = {

// dump all the hex code here, replace the one that's already there.

 };
```

8. Save and upload the LCD.cpp code to your ESP32.

![unnamed](https://github.com/user-attachments/assets/78eb5117-8dee-4270-b65e-c645a126d745)







