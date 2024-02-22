#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

char GU_InitAll(const char *title, int w, int h);
void GU_DeInitAll(void);
void GU_Clear(void);
void GU_Render(void);
SDL_Texture* GU_LoadTexture(const char* path);
void GU_DrawTexture(SDL_Texture *texture,  const SDL_Rect *srcrect, const SDL_Rect *dstrect);

#endif
