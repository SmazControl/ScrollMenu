#ifndef ScrollMenu_h
#define ScrollMenu_h

#include "SSD1306Wire.h"
class ScrollMenu
{
  public:
    ScrollMenu(int tline);
    void Sloop();
    SSD1306Wire display(uint8_t _address, uint8_t _sda, uint8_t _scl);
  private:
    unsigned long stime;
    int _tline;
    int sline;
    int fline;
    boolean decending;
};

#endif
