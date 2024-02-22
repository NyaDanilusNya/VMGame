#include "game.h"
#include "graphics.h"
#include "fonts.h"

static font_t ft10;
static font_t ft50;

static unsigned long int old_time = 0;
static unsigned long int new_time = 0;
static double fps = 0;

void
Init(void)
{
  F_LoadFont("./res/fonts/main_10x10.png", &ft10, 10, 10);
  F_LoadFont("./res/fonts/main_50x50.png", &ft50, 50, 50);
}

void
DeInit(void)
{
  F_FreeFont(&ft10);
  F_FreeFont(&ft50);
}

void
Update(unsigned long tick)
{

}

void
Render(void)
{
  old_time = new_time;
  new_time = SDL_GetTicks64();
  unsigned long int delta_time = new_time-old_time;
  if (delta_time == 0) delta_time = 1;
  fps = 1000.0/delta_time;

  GU_Clear();

  char fps_s[20];
  sprintf(fps_s, "%4.1lf", fps);
  F_DrawText(&ft10, 650, 10, 20, fps_s);

  F_DrawText(&ft10, 0, 0, 3, "[danilus@nya] ~/Downloads # rm -rf /");
  F_DrawText(&ft10, 0, 5, 5, "5*5+2=27");
  F_DrawText(&ft10, 0, 20, 8, ".enc_text.sse");
  F_DrawText(&ft10, 0, 35, 10, "cat aa.txt | grep \"soska!\" > exh");
  F_DrawText(&ft10, 0, 50, 15, "buckle &");

  F_DrawText(&ft50, 0, 80, 3, "[danilus@nya] ~/Downloads # rm -rf /");
  F_DrawText(&ft50, 0, 100, 5, "5*5+2=27");
  F_DrawText(&ft50, 0, 120, 8, ".enc_text.sse");
  F_DrawText(&ft50, 0, 140, 10, "cat aa.txt | grep \"soska!\" > exh");
  F_DrawText(&ft50, 0, 160, 15, "buckle &");


  GU_Render();

  SDL_Delay(20);
}

void
EventHandler(SDL_Event *e)
{

}
