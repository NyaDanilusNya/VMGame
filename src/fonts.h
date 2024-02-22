#ifndef FONTS_H
#define FONTS_H

#include <SDL2/SDL.h>

typedef struct
{
  unsigned int x, y;
} glyph_t;

typedef struct
{
  SDL_Texture *texture;
  glyph_t glyphs[127];
  char w, h;
} font_t;

void F_LoadFont(const char *path, font_t *out_font, int size_w, int size_h);
void F_FreeFont(font_t *out_font);
void F_DrawText(font_t *font, const int x, const int y, int size, const char *text);

#endif
