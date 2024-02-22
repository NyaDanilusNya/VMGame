#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include "graphics.h"
#include "game.h"

static bool isRunning;
static SDL_Event event;
static unsigned long gametick = 0;

int
main(int argc, char **argv)
{
  printf("args (%d): ", argc);
  for (int i = 0; i < argc; i++)
  {
    printf("%s, ", argv[i]);
  }
  printf("\n");
  if (GU_InitAll("VMGame", 800, 600) != 1)
    exit(1);

  Init();

  isRunning = true;

  while(isRunning)
  {
    gametick++;
    while (SDL_PollEvent(&event) != 0)
    {
        if (event.type == SDL_QUIT)
        {
            isRunning = false;
        }
        EventHandler(&event);
    }
    Update(gametick);
    Render();
  }
  DeInit();

  GU_DeInitAll();
  return 0;
}
