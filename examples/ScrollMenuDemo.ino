#include <Wire.h>
#include "SSD1306Wire.h"
SSD1306Wire display(0x3c, D3, D5);
#include "ScrollMenu.h"
ScrollMenu smenu(&display, 8);
void setup() {
  smenu.init();
}

void loop() {
  smenu.Sloop();
}

