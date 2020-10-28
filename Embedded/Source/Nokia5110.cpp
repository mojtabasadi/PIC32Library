#include "../Embedded/Nokia5110.h"

/*void LCD_Write(uint8_t d)
{
  uint8_t bit_n;
  for (bit_n = 0x80; bit_n; bit_n >>= 1) {
    LCD_CLK = 0;
    if (d & bit_n) LCD_DAT = 1;
    else           LCD_DAT = 0;
    LCD_CLK = 1;
  }
}*/

void write_command(uint8_t c_)
{
  LCD_DC = 0;
  #ifdef LCD_SCE
  LCD_SCE = 0;
  #endif
  LCD_Write(c_);
  #ifdef LCD_SCE
  LCD_SCE = 1;
  #endif
}

void write_data(uint8_t d_)
{
  LCD_DC = 1;
  #ifdef LCD_SCE
  LCD_SCE = 0;
  #endif
  LCD_Write(d_);
  #ifdef LCD_SCE
  LCD_SCE = 1;
  #endif
}

void LCD_Begin()
{
  delay.ms(100);
  #ifdef LCD_RST
    LCD_RST = 0;
    #ifdef DIR_LCD_RST
      DIR_LCD_RST = 0;
    #endif
  // rest the LCD
  delay.ms(500);
  LCD_RST = 1;
  #endif
  #ifdef LCD_SCE
    LCD_SCE = 1;
    #ifdef DIR_LCD_SCE
      DIR_LCD_SCE = 0;
    #endif
  #endif
  #ifdef DIR_LCD_DC
    DIR_LCD_DC = 0;
  #endif

  #ifdef DIR_LCD_DIN
    DIR_LCD_DIN = 0;
  #endif
  #ifdef DIR_LCD_CLK
    DIR_LCD_CLK = 0;
  #endif

  // get into the EXTENDED mode
  write_command(LCD_FUNCTIONSET | LCD_EXTENDEDINSTRUCTION );

  // set bias voltage
  write_command(LCD_SETBIAS | 0x03);

  // set contrast
  write_command( LCD_SETVOP | 0x32);

  // normal mode
  write_command(LCD_FUNCTIONSET);

  // set display to normal mode
  write_command(LCD_DISPLAYCONTROL | LCD_DISPLAYNORMAL);

  LCD_Display();
}

void LCD_SetContrast(uint8_t con)
{
  if (con > 0x7f)
    con = 0x7f;

  write_command(LCD_FUNCTIONSET | LCD_EXTENDEDINSTRUCTION );
  write_command( LCD_SETVOP | con); 
  write_command(LCD_FUNCTIONSET);
 }

void LCD_Display()
{
  uint16_t i;
  write_command(LCD_SETYADDR);  // set y = 0
  write_command(LCD_SETXADDR);  // set x = 0

  LCD_DC = 1;
  #ifdef LCD_SCE
    LCD_SCE = 0;
  #endif

  for(i = 0; i < 504; i++)  // 504 = LCDWIDTH*LCDHEIGHT / 8
    LCD_Write( lcd_buffer[i] );

  #ifdef LCD_SCE
    LCD_SCE = 1;
  #endif

}

void LCD_DrawPixel(uint8_t x, uint8_t y, bool color)
{
  int16_t t;
  if ( (x >= _width) || (y >= _height) )
    return;
  switch(rotation) {
    case 1:
      t = x;
      x = y;
      y =  LCDHEIGHT - 1 - t;
      break;
    case 2:
      x = LCDWIDTH - 1 - x;
      y = LCDHEIGHT - 1 - y;
      break;
    case 3:
      t = x;
      x = LCDWIDTH - 1 - y;
      y = t;
      break;
  }
  
  if ((x >= LCDWIDTH) || (y >= LCDHEIGHT))
    return;

  if (color)
    lcd_buffer[x + (uint16_t)(y / 8) * LCDWIDTH] |=  (1 << (y & 7));

  else
    lcd_buffer[x + (uint16_t)(y / 8) * LCDWIDTH] &=  ~(1 << (y & 7));
}

void LCD_DrawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, bool color)
{
  bool steep;
  int8_t ystep;
  uint8_t dx, dy;
  int16_t err;
  steep = abs(y1 - y0) > abs(x1 - x0);
  if (steep) {
    LCD_swap(x0, y0);
    LCD_swap(x1, y1);
  }
  if (x0 > x1) {
    LCD_swap(x0, x1);
    LCD_swap(y0, y1);
  }
  dx = x1 - x0;
  dy = abs(y1 - y0);

  err = dx / 2;
  if (y0 < y1)
    ystep = 1;
  else
    ystep = -1;

  for (; x0 <= x1; x0++) {
    if (steep)
      LCD_DrawPixel(y0, x0, color);
    else
      LCD_DrawPixel(x0, y0, color);
    err -= dy;
    if (err < 0) {
      y0  += ystep;
      err += dx;
    }
  }
}

void LCD_DrawHLine(uint8_t x, uint8_t y, uint8_t w, bool color)
{
   LCD_DrawLine(x, y, x + w - 1, y, color);
}

void LCD_DrawVLine(uint8_t x, uint8_t y, uint8_t h, bool color)
{
  LCD_DrawLine(x, y, x, y + h - 1, color);
}

void LCD_FillRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, bool color)
{
  int16_t i;
  for (i = x; i < x + w; i++)
    LCD_DrawVLine(i, y, h, color);
}

void LCD_DrawCircle(int16_t x0, int16_t y0, int16_t r, bool color)
{
  int16_t f = 1 - r;
  int16_t ddF_x = 1;
  int16_t ddF_y = -2 * r;
  int16_t x = 0;
  int16_t y = r;

  LCD_DrawPixel(x0  , y0 + r, color);
  LCD_DrawPixel(x0  , y0 - r, color);
  LCD_DrawPixel(x0 + r, y0, color);
  LCD_DrawPixel(x0 - r, y0, color);

  while (x < y) {
    if (f >= 0) {
      y--;
      ddF_y += 2;
      f += ddF_y;
    }
    x++;
    ddF_x += 2;
    f += ddF_x;

    LCD_DrawPixel(x0 + x, y0 + y, color);
    LCD_DrawPixel(x0 - x, y0 + y, color);
    LCD_DrawPixel(x0 + x, y0 - y, color);
    LCD_DrawPixel(x0 - x, y0 - y, color);
    LCD_DrawPixel(x0 + y, y0 + x, color);
    LCD_DrawPixel(x0 - y, y0 + x, color);
    LCD_DrawPixel(x0 + y, y0 - x, color);
    LCD_DrawPixel(x0 - y, y0 - x, color);
  }

}

void LCD_DrawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, bool color)
{
  int16_t f     = 1 - r;
  int16_t ddF_x = 1;
  int16_t ddF_y = r * (-2);
  int16_t x     = 0;
  int16_t y     = r;

  while (x < y) {
    if (f >= 0) {
      y--;
      ddF_y += 2;
      f     += ddF_y;
    }
    x++;
    ddF_x += 2;
    f     += ddF_x;
    if (cornername & 0x4) {
      LCD_DrawPixel(x0 + x, y0 + y, color);
      LCD_DrawPixel(x0 + y, y0 + x, color);
    }
    if (cornername & 0x2) {
      LCD_DrawPixel(x0 + x, y0 - y, color);
      LCD_DrawPixel(x0 + y, y0 - x, color);
    }
    if (cornername & 0x8) {
      LCD_DrawPixel(x0 - y, y0 + x, color);
      LCD_DrawPixel(x0 - x, y0 + y, color);
    }
    if (cornername & 0x1) {
      LCD_DrawPixel(x0 - y, y0 - x, color);
      LCD_DrawPixel(x0 - x, y0 - y, color);
    }
  }

}

// Used to do circles and roundrects
void LCD_FillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, bool color)
{
  int16_t f     = 1 - r;
  int16_t ddF_x = 1;
  int16_t ddF_y = -2 * r;
  int16_t x     = 0;
  int16_t y     = r;

  while (x < y) {
    if (f >= 0) {
      y--;
      ddF_y += 2;
      f     += ddF_y;
    }
    x++;
    ddF_x += 2;
    f     += ddF_x;

    if (cornername & 0x01) {
      LCD_DrawVLine(x0 + x, y0 - y, 2 * y + 1 + delta, color);
      LCD_DrawVLine(x0 + y, y0 - x, 2 * x + 1 + delta, color);
    }
    if (cornername & 0x02) {
      LCD_DrawVLine(x0 - x, y0 - y, 2 * y + 1 + delta, color);
      LCD_DrawVLine(x0 - y, y0 - x, 2 * x + 1 + delta, color);
    }
  }

}

void LCD_FillCircle(int16_t x0, int16_t y0, int16_t r, bool color)
{
  LCD_DrawVLine(x0, y0 - r, 2 * r + 1, color);
  LCD_FillCircleHelper(x0, y0, r, 3, 0, color);
}

// draw a rectangle
void LCD_DrawRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, bool color)
{
  LCD_DrawHLine(x, y, w, color);
  LCD_DrawHLine(x, y + h - 1, w, color);
  LCD_DrawVLine(x, y, h, color);
  LCD_DrawVLine(x + w - 1, y, h, color);
}

// Draw a rounded rectangle
void LCD_DrawRoundRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t r, bool color)
{
  int16_t max_radius = ((w < h) ? w : h) / 2; // 1/2 minor axis
  if(r > max_radius) r = max_radius;
  // smarter version
  LCD_DrawHLine(x + r, y, w - 2 * r, color); // Top
  LCD_DrawHLine(x + r, y + h - 1, w - 2 * r, color); // Bottom
  LCD_DrawVLine(x, y + r, h - 2 * r, color); // Left
  LCD_DrawVLine(x + w - 1, y + r, h - 2 * r, color); // Right
  // draw four corners
  LCD_DrawCircleHelper(x + r, y + r, r, 1, color);
  LCD_DrawCircleHelper(x + w - r - 1, y + r, r, 2, color);
  LCD_DrawCircleHelper(x + w - r - 1, y + h - r - 1, r, 4, color);
  LCD_DrawCircleHelper(x + r, y + h - r - 1, r, 8, color);
}

// Fill a rounded rectangle
void LCD_FillRoundRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t r, bool color)
{
  int16_t max_radius = ((w < h) ? w : h) / 2; // 1/2 minor axis
  if(r > max_radius) r = max_radius;
  // smarter version
  LCD_FillRect(x + r, y, w - 2 * r, h, color);
  // draw four corners
  LCD_FillCircleHelper(x + w - r - 1, y + r, r, 1, h - 2 * r - 1, color);
  LCD_FillCircleHelper(x + r        , y + r, r, 2, h - 2 * r - 1, color);
}

// Draw a triangle
void LCD_DrawTriangle(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, bool color)
{
  LCD_DrawLine(x0, y0, x1, y1, color);
  LCD_DrawLine(x1, y1, x2, y2, color);
  LCD_DrawLine(x2, y2, x0, y0, color);
}

void LCD_FillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, bool color)
{
  int16_t a, b, y, last,
          dx01, dx02, dx12, dy01, dy02, dy12;
  int32_t  sa = 0, sb = 0;
  // Sort coordinates by Y order (y2 >= y1 >= y0)
  if (y0 > y1) {
    LCD_swap(y0, y1); LCD_swap(x0, x1);
  }
  if (y1 > y2) {
    LCD_swap(y2, y1); LCD_swap(x2, x1);
  }
  if (y0 > y1) {
    LCD_swap(y0, y1); LCD_swap(x0, x1);
  }

  if(y0 == y2) { // Handle awkward all-on-same-line case as its own thing
    a = b = x0;
    if(x1 < a)      a = x1;
    else if(x1 > b) b = x1;
    if(x2 < a)      a = x2;
    else if(x2 > b) b = x2;
    LCD_DrawHLine(a, y0, b - a + 1, color);
    return;
  }

  dx01 = x1 - x0,
  dy01 = y1 - y0,
  dx02 = x2 - x0,
  dy02 = y2 - y0,
  dx12 = x2 - x1,
  dy12 = y2 - y1;

  if(y1 == y2) last = y1;
  else         last = y1 - 1;

  for(y = y0; y <= last; y++) {
    a   = x0 + sa / dy01;
    b   = x0 + sb / dy02;
    sa += dx01;
    sb += dx02;

    if(a > b) LCD_swap(a, b);
    LCD_DrawHLine(a, y, b - a + 1, color);
  }

  sa = dx12 * (y - y1);
  sb = dx02 * (y - y0);
  for(; y <= y2; y++) {
    a   = x1 + sa / dy12;
    b   = x0 + sb / dy02;
    sa += dx12;
    sb += dx02;

    if(a > b) LCD_swap(a, b);
    LCD_DrawHLine(a, y, b - a + 1, color);
  }
}

void LCD_Clear()
{
  uint16_t i;
  for (i = 0; i < 504; i++)  // 504 = LCDWIDTH*LCDHEIGHT / 8
    lcd_buffer[i] = 0;
}
void LCD_Clear_som(unsigned char x1,unsigned char y1,unsigned char x2,unsigned char y2)
{
  uint16_t i;
  for (i = (x1*y1)/8; i < (x2*y2)/8; i++)  // 504 = LCDWIDTH*LCDHEIGHT / 8
    lcd_buffer[i] = 0;
}
void LCD_Fill()
{
  uint16_t i;
  for (i = 0; i < 504; i++)  // 504 = LCDWIDTH*LCDHEIGHT / 8
    lcd_buffer[i] = 0xFF;
}

void LCD_TextSize(uint8_t t_size)
{
  if(t_size < 1)
    return;
  text_size = t_size;
}

void LCD_GotoXY(uint8_t x, uint8_t y)
{
  if((x >= LCDWIDTH) || (y >= LCDHEIGHT))
    return;
  x_pos = x;
  y_pos = y;
}

uint8_t LCD_GetX()
{
  return x_pos;
}

uint8_t LCD_GetY()
{
  return y_pos;
}

void LCD_TextWrap(bool w)
{
  wrap = w;
}

void LCD_TextColor(bool t_color, bool t_bg)
{
  text_color = t_color;
  text_bg = t_bg;
}

// set rotation setting for display
// 0 thru 3 corresponding to 4 cardinal rotations
void LCD_SetRotation(uint8_t rot)
{
  rotation = (rot & 3);
  switch(rotation) {
    case 0:
    case 2:
      _width  = LCDWIDTH;
      _height = LCDHEIGHT;
    break;
    case 1:
    case 3:
      _width  = LCDHEIGHT;
      _height = LCDWIDTH;
      break;
  }
}

// get rotation setting for display
// 0 thru 3 corresponding to 4 cardinal rotations
uint8_t LCD_GetRotation()
{
  return rotation;
}

// get width of the display, accounting for the current rotation
uint8_t LCD_GetWidth()
{
  return _width;
}

// get height of the display, accounting for the current rotation
uint8_t LCD_GetHeight()
{
  return _height;
}

/* print single char
    \a  Set cursor position to upper left (0, 0)
    \b  Move back one position
    \n  Go to start of current line
    \r  Go to line below
*/
void LCD_PutC(uint8_t c)
{
  uint8_t i, j, line;
  if(c == '\a') {
    x_pos = y_pos = 0;
    return;
  }
  if (c == ' ' && x_pos == 0 && wrap)
    return;
  if( (c == '\b') && (x_pos >= text_size * 6) ) {
    x_pos -= text_size * 6;
    return;
  }
  if(c == '\r') {
    x_pos = 0;
    return;
  }
  if(c == '\n') {
    y_pos += text_size * 8;
    if((y_pos + text_size * 7) > _height)
      y_pos = 0;
    return;
  }
  
  if((c < ' ') || (c > '~'))
    c = '?';
  
  for(i = 0; i < 5; i++ ) {
    line = Font[(c - ' ') * 5 + i];
    for(j = 0; j < 8; j++, line >>= 1) {
      if(line & 1) {
        if(text_size == 1)
          LCD_DrawPixel(x_pos + i, y_pos + j, text_color);
        else
          LCD_FillRect(x_pos + i * text_size, y_pos + j * text_size, text_size, text_size, text_color);
      } 
      else 
        if(text_bg != text_color) {
          if(text_size == 1)
            LCD_DrawPixel(x_pos + i, y_pos + j, text_bg);
          else
            LCD_FillRect(x_pos + i * text_size, y_pos + j * text_size, text_size, text_size, text_bg);
        }
    }
  }

  if(text_bg != text_color) {  // If opaque, draw vertical line for last column
    if(text_size == 1) LCD_DrawVLine(x_pos + 5, y_pos, 8, text_bg);
    else               LCD_FillRect(x_pos + 5 * text_size, y_pos, text_size, 8 * text_size, text_bg);
  }
  
  x_pos += text_size * 6;
  
  if( x_pos > (_width + text_size * 6) )
    x_pos = _width;

  if (wrap && (x_pos + (text_size * 5)) > _width)
  {
    x_pos = 0;
    y_pos += text_size * 8;
    if( y_pos > (_height + text_size * 8) )
      y_pos = _height;
  }
}

// print custom char (dimension: 7x5 pixel)
void LCD_PutCustomC(const uint8_t *c)
{
  uint8_t i, j, line;
  
  for(i = 0; i < 5; i++ ) {
    line = c[i];

    for(j = 0; j < 8; j++, line >>= 1) {
      if(line & 1) {
        if(text_size == 1)
          LCD_DrawPixel(x_pos + i, y_pos + j, text_color);
        else
          LCD_FillRect(x_pos + i * text_size, y_pos + j * text_size, text_size, text_size, text_color);
      }
      else
        if(text_bg != text_color) {
          if(text_size == 1)
            LCD_DrawPixel(x_pos + i, y_pos + j, text_bg);
          else
            LCD_FillRect(x_pos + i * text_size, y_pos + j * text_size, text_size, text_size, text_bg);
        }
    }
  }

  if(text_bg != text_color) {  // If opaque, draw vertical line for last column
    if(text_size == 1) LCD_DrawVLine(x_pos + 5, y_pos, 8, text_bg);
    else               LCD_FillRect(x_pos + 5 * text_size, y_pos, text_size, 8 * text_size, text_bg);
  }

  x_pos += text_size * 6;

  if( x_pos > (_width + text_size * 6) )
    x_pos = _width;

  if (wrap && (x_pos + (text_size * 5)) > _width)
  {
    x_pos = 0;
    y_pos += text_size * 8;
    if( y_pos > (_height + text_size * 8) )
      y_pos = _height;
  }
}

// print text
void LCD_Print(char *s)
{
  while (*s)
  {
    if (*s == ' ' && x_pos == 0 && wrap)
      *s++;
    else
      LCD_PutC(*s++);
  }
}

void LCD_Invert(bool inv)
{
  if(inv == 1)
    write_command(LCD_DISPLAYCONTROL | LCD_DISPLAYINVERTED);
  else
    write_command(LCD_DISPLAYCONTROL | LCD_DISPLAYNORMAL);
}

// draw BMP stored in ROM
void LCD_ROMBMP(uint8_t x, uint8_t y, const uint8_t *bitmap, uint8_t w, uint8_t h, bool color)
{
  uint16_t i, j;
  for( i = 0; i < h/8; i++)
  {    
    for( j = 0; j < (uint16_t)w * 8; j++)
    {      
      if( bitmap[j/8 + i*w] & (1 << (j % 8)) )
        LCD_DrawPixel(x + j/8, y + i*8 + (j % 8), color);
    }
  }
}

// draw BMP stored in RAM
void LCD_RAMBMP(uint8_t x, uint8_t y, uint8_t *bitmap, uint8_t w, uint8_t h, bool color)
{    
  uint16_t i, j;
  for( i = 0; i < h/8; i++)
  {    
    for( j = 0; j < (uint16_t)w * 8; j++)
    {      
      if( bitmap[j/8 + i*w] & (1 << (j % 8)) )
        LCD_DrawPixel(x + j/8, y + i*8 + (j % 8), color);
    }
  }
}

// end of code.
void LCD_Write(uint8_t bytes) 
{
    unsigned int i;
	//Enable controller
	LCD_SCE=0;
	//Send bytes
	for(i=0;i<8;i++) 
    {
		//Set data pin to byte state
		if((bytes>>(7-i)) & 0x01) LCD_DIN=1;
		else LCD_DIN=0;
        LCD_CLK=1;
        delay.us(1);
		//Blink clock		
		LCD_CLK=0;
	}
	//Disable controller
	LCD_SCE=1;
    LCD_DIN=1;
    delay.us(20);
}

 
void testdrawchar(void) {
  uint8_t i;
  LCD_TextSize(1);   // set text size to 1
  LCD_TextColor(BLACK, WHITE);  // set text color to black with white background
  LCD_GotoXY(0, 0);   // move cursor to position (0, 0) pixel (upper left)
 
  for (i = '!'; i < 117; i++)
    LCD_PutC(i);
  LCD_Display();
}
 
void testdrawcircle(void) {
  int16_t i;
  for (i = 0; i < LCD_GetHeight(); i+=2) {
    LCD_DrawCircle(LCD_GetWidth()/2, LCD_GetHeight()/2, i, BLACK);
    LCD_Display();
  }
}
 
void testfillrect(void) {
  uint8_t i, color = 1;
  for (i = 0; i < LCD_GetHeight()/2; i+=3) {
    // alternate colors
    LCD_FillRect(i, i, LCD_GetWidth()-i*2, LCD_GetHeight()-i*2, color%2);
    LCD_Display();
    color++;
  }
}
 
void testdrawtriangle(void) {
  int16_t i;
  for (i = 0; i < min(LCD_GetWidth(), LCD_GetHeight())/2; i += 5) {
    LCD_DrawTriangle(LCD_GetWidth()/2, LCD_GetHeight()/2-i,
                     LCD_GetWidth()/2-i, LCD_GetHeight()/2+i,
                     LCD_GetWidth()/2+i, LCD_GetHeight()/2+i, BLACK);
    LCD_Display();
  }
}
 
void testfilltriangle(void) {
  bool color = BLACK;
  int8_t i;
  for (i = min(LCD_GetWidth(), LCD_GetHeight())/2; i > 0; i -= 5) {
    LCD_FillTriangle(LCD_GetWidth()/2, LCD_GetHeight()/2-i,
                     LCD_GetWidth()/2-i, LCD_GetHeight()/2+i,
                     LCD_GetWidth()/2+i, LCD_GetHeight()/2+i, color);
    if (color == WHITE) color = BLACK;
    else color = WHITE;
    LCD_Display();
  }
}
 
void testdrawroundrect(void) {
  uint8_t i;
  for (i = 0; i < LCD_GetHeight()/2 - 2; i += 2) {
    LCD_DrawRoundRect(i, i, LCD_GetWidth()-2*i, LCD_GetHeight()-2*i, LCD_GetHeight()/4, BLACK);
    LCD_Display();
  }
}
 
void testfillroundrect(void) {
  bool color = BLACK;
  uint8_t i;
  for (i = 0; i < LCD_GetHeight()/2-2; i += 2) {
    LCD_FillRoundRect(i, i, LCD_GetWidth()-2*i, LCD_GetHeight()-2*i, LCD_GetHeight()/4, color);
    if (color == WHITE) color = BLACK;
    else color = WHITE;
    LCD_Display();
  }
}
 
void testdrawrect(void) {
  uint8_t i;
  for (i = 0; i < LCD_GetHeight()/2; i += 2) {
    LCD_DrawRect(i, i, LCD_GetWidth()-2*i, LCD_GetHeight()-2*i, BLACK);
    LCD_Display();
  }
}
 
void testdrawline() {
  int16_t i;
  for (i = 0; i < LCD_GetWidth(); i += 4) {
    LCD_DrawLine(0, 0, i, LCD_GetHeight()-1, BLACK);
    LCD_Display();
  }
  for (i = 0; i < LCD_GetHeight(); i += 4) {
    LCD_DrawLine(0, 0, LCD_GetWidth()-1, i, BLACK);
    LCD_Display();
  }
  delay.ms(250);
 
  LCD_Clear();
  for (i = 0; i < LCD_GetWidth(); i += 4) {
    LCD_DrawLine(0, LCD_GetHeight()-1, i, 0, BLACK);
    LCD_Display();
  }
  for (i = LCD_GetHeight() - 1; i >= 0; i -= 4) {
    LCD_DrawLine(0, LCD_GetHeight()-1, LCD_GetWidth()-1, i, BLACK);
    LCD_Display();
  }
  delay.ms(250);
 
  LCD_Clear();
  for (i = LCD_GetWidth() - 1; i >= 0; i -= 4) {
    LCD_DrawLine(LCD_GetWidth()-1, LCD_GetHeight()-1, i, 0, BLACK);
    LCD_Display();
  }
  for (i = LCD_GetHeight()-1; i >= 0; i -= 4) {
    LCD_DrawLine(LCD_GetWidth()-1, LCD_GetHeight()-1, 0, i, BLACK);
    LCD_Display();
  }
  delay.ms(250);
 
  LCD_Clear();
  for (i = 0; i < LCD_GetHeight(); i += 4) {
    LCD_DrawLine(LCD_GetWidth()-1, 0, 0, i, BLACK);
    LCD_Display();
  }
  for (i = 0; i < LCD_GetWidth(); i+=4) {
    LCD_DrawLine(LCD_GetWidth()-1, 0, i, LCD_GetHeight()-1, BLACK);
    LCD_Display();
  }
  delay.ms(250);
}
 
void testdrawbitmap(const uint8_t *bitmap, uint8_t w, uint8_t h) {
  uint8_t icons[NUMFLAKES][3], f;
  // initialize
  for (f = 0; f < NUMFLAKES; f++) {
    icons[f][XPOS] = rand() % LCDWIDTH;
    icons[f][YPOS] = 0;
    icons[f][DELTAY] = (rand() % 5) + 1;
  }
 
  while (1) {
    // draw each icon
    for (f = 0; f < NUMFLAKES; f++) {
      LCD_ROMBMP(icons[f][XPOS], icons[f][YPOS], bitmap, w, h, BLACK);
    }
    LCD_Display();
    delay.ms(200);
 
    // then erase it + move it
    for (f = 0; f< NUMFLAKES; f++) {
      LCD_ROMBMP(icons[f][XPOS], icons[f][YPOS],  bitmap, w, h, WHITE);
      // move it
      icons[f][YPOS] += icons[f][DELTAY];
      // if its gone, reinit
      if (icons[f][YPOS] > LCDHEIGHT) {
        icons[f][XPOS] = rand() % LCDWIDTH;
        icons[f][YPOS] = 0;
        icons[f][DELTAY] = (rand() % 5) + 1;
      }
    }
   }
}
void Signal_Bar(unsigned char x,unsigned char y,unsigned char power)
{
    LCD_DrawTriangle(x, y, x+6, y, x+3, y+5, 1);
    LCD_DrawLine(x+3, y, x+3, y+8, 1);
    switch (power)
    {
        case    0:
            LCD_DrawRect(x+5, y+6, 3, 3, 1);
            LCD_DrawRect(x+9, y+4, 3, 5, 1);
            LCD_DrawRect(x+13, y+2, 3, 7, 1);
            LCD_DrawRect(x+17, y, 3, 9, 1);
            break;
        case    1:
            LCD_FillRect(x+5, y+6, 3, 3, 1);
            LCD_DrawRect(x+9, y+4, 3, 5, 1);
            LCD_DrawRect(x+13, y+2, 3, 7, 1);
            LCD_DrawRect(x+17, y, 3, 9, 1);
            break;
        case    2:
            LCD_FillRect(x+5, y+6, 3, 3, 1);
            LCD_FillRect(x+9, y+4, 3, 5, 1);
            LCD_DrawRect(x+13, y+2, 3, 7, 1);
            LCD_DrawRect(x+17, y, 3, 9, 1);
            break;
        case    3:
            LCD_FillRect(x+5, y+6, 3, 3, 1);
            LCD_FillRect(x+9, y+4, 3, 5, 1);
            LCD_FillRect(x+13, y+2, 3, 7, 1);
            LCD_DrawRect(x+17, y, 3, 9, 1);
            break;
        case    4:
            LCD_FillRect(x+5, y+6, 3, 3, 1);
            LCD_FillRect(x+9, y+4, 3, 5, 1);
            LCD_FillRect(x+13, y+2, 3, 7, 1);
            LCD_FillRect(x+17, y, 3, 9, 1);
            break;
    }    
}
void Battery_Bar(unsigned char x,unsigned char y,unsigned char power)
{
    LCD_DrawRoundRect(x, y, 15, 9, 1, 1);
    LCD_DrawRect(x+15, y+2, 1, 5, 1);
    switch (power)
    {
        case    0:
            LCD_DrawRect(x+2, y+2, 3, 5, 0);//clear
            LCD_DrawRect(x+6, y+2, 3, 5, 0);
            LCD_DrawRect(x+10, y+2, 3, 5, 0);
            break;
        case    1:
            LCD_FillRect(x+2, y+2, 3, 5, 1);
            LCD_FillRect(x+6, y+2, 3, 5, 1);
            LCD_DrawRect(x+10, y+2, 3, 5, 0);
            break;
        case    2:
            LCD_FillRect(x+2, y+2, 3, 5, 1);
            LCD_FillRect(x+6, y+2, 3, 5, 1);
            LCD_DrawRect(x+10, y+2, 3, 5, 0);
            break;
        case    3:
            LCD_FillRect(x+2, y+2, 3, 5, 1);
            LCD_FillRect(x+6, y+2, 3, 5, 1);
            LCD_FillRect(x+10, y+2, 3, 5, 1);
            break;
    }    
    
}
void WarningLogo(unsigned char x,unsigned char y)
{
    LCD_DrawTriangle(x, y+8, x+12, y+8, x+6, y, 1);
    LCD_DrawLine(x+6, y+3, x+6, y+4, 1);
    LCD_DrawPixel(x+6,y+6,1);
}

