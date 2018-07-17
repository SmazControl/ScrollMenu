#include "ScrollMenu.h"

ScrollMenu::ScrollMenu(int tline)
{
    _tline = tline;
    stime = millis();
    sline = 1;
    fline = 1;
    decending = true;
}

void ScrollMenu::Sloop()
{
    if (millis() -2000 > stime){
      SSD1306Wire display(0x3c, D3, D5);
      display.init();
      display.flipScreenVertically();
      display.setFont(ArialMT_Plain_16);
      display.clear();
      display.setColor(WHITE);
      display.fillRect(0,0+((sline-fline)*16),127,16);
      for (int i=0+(fline-1); i<4+(fline-1); i++){ // loop for menu line
        if (i==(sline-1)) {
          display.setColor(BLACK);
        }
        if (i==3) {
          display.drawString(0, 0+((i-(fline-1))*16), String(millis()));
        } else {
          display.drawString(0, 0+((i-(fline-1))*16), "Menu Line"+String(i+1));
        }
        if (i==(sline-1)) {
          display.setColor(WHITE);
        }        
      }
      if (decending) {
        sline = sline + 1;
        if (sline > 4) {
          fline++;
          if (sline == 9) {
            decending = false;
            sline = sline -2;
            fline = fline -1;
          }
        }
      } else {
        sline = sline - 1;
        if (sline <= 4) {
          fline = fline - 1;
          if (sline == 0) {
            decending = true;
            sline = sline +2;
            fline = 1;
          }
        }
      }
      display.display();  
      stime = millis();
    }
}

