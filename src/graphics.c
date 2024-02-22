#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "graphics.h"

static SDL_Window *pWin;
static SDL_Renderer *pRen;
static char img_init = 0;

char
GU_InitAll(const char *title, int w, int h)
{
  printf("Initializing SDL... ");
  if (pWin != NULL || pRen != NULL)
  {
    printf("win or ren already initalized\n");
    return 0;
  }
  if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_EVENTS) != 0)
  {
    printf("Cannot init SDL: %s\n", SDL_GetError());
    return 0;
  }
  printf("OK\n");
  printf("Initializing window... ");
  pWin = SDL_CreateWindow(title,
      SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
  if (pWin == NULL)
  {
    printf("Cannot create window: %s\n", SDL_GetError());
    GU_DeInitAll();
    return 0;
  }
  printf("OK\n");
  printf("Initializing renderer... ");
  pRen = SDL_CreateRenderer(pWin, -1, SDL_RENDERER_ACCELERATED);
  if (pRen == NULL)
  {
    printf("Cannot create renderer: %s\n", SDL_GetError());
    GU_DeInitAll();
    return 0;
  }
  printf("OK\n");
  printf("Initializing IMG... ");
  int imgFlags = IMG_INIT_PNG;
  if (!(IMG_Init(imgFlags) & imgFlags))
  {
    printf("\e[31mCannot init IMG: %s\e[m\n", IMG_GetError());
    GU_DeInitAll();
    return 0;
  }
  img_init = 1;
  printf("OK\n");
  printf("OK\nWell done!\n");
  return 1;
}
void
GU_DeInitAll(void)
{
  printf("Deinitializing.\n");
  if (img_init)
  {
    printf("Deinitializing IMG... ");
    IMG_Quit();
    printf("OK\n");
  }
  printf("Deinitializing renderer... ");
  if (pRen != NULL) SDL_DestroyRenderer(pRen);
  printf("OK\n");
  printf("Deinitializing window... ");
  if (pWin != NULL) SDL_DestroyWindow(pWin);
  printf("OK\n");
  printf("Quiting...\n");
  SDL_Quit();
}

void
GU_Clear(void)
{
  SDL_SetRenderDrawColor(pRen, 0, 0, 0, 0);
  SDL_RenderClear(pRen);
}

void
GU_Render(void)
{
  SDL_RenderPresent(pRen);
}

SDL_Texture*
GU_LoadTexture(const char* path)
{
  return IMG_LoadTexture(pRen, path);
}

void
GU_DrawTexture(SDL_Texture *texture, const SDL_Rect *srcrect, const SDL_Rect *dstrect)
{
  SDL_RenderCopy(pRen, texture, srcrect, dstrect);
}

