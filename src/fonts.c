#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string.h>
#include "fonts.h"
#include "graphics.h"


void
F_LoadFont(const char *path, font_t *out_font, int size_w, int size_h)
{
  out_font->texture = GU_LoadTexture(path);
  out_font->h = size_h;
  out_font->w = size_w;
  // ^-^
  int i = 32;
  for (int y = 0; y < 10; y++)
  {
    if (i >= 127)
      break;
    for (int x = 0; x < 10; x++)
    {
      if (i >= 127)
        break;
      out_font->glyphs[i].x = out_font->w*x;
      out_font->glyphs[i].y = out_font->h*y;
      i++;
    }
  }
}

void
F_FreeFont(font_t *font)
{
  SDL_DestroyTexture(font->texture);
}

void
F_DrawText(font_t *font, const int x, const int y, int size, const char *text)
{
  if (size < 1) size = 1;
  int len = strlen(text);
  SDL_Rect src;
  SDL_Rect dst;
  dst.x = x;
  dst.y = y;
  //dst.h = font->h*size;
  //dst.w = font->w*size;
  dst.h = size;
  dst.w = size;

  src.h = font->h;
  src.w = font->w;
  for (int i = 0; i < len; i++)
  {
    src.x = font->glyphs[text[i]].x;
    src.y = font->glyphs[text[i]].y;
    dst.x = x+i*size;
    GU_DrawTexture(font->texture, &src, &dst);
  }
}
