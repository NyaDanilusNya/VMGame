#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

void Init(void);
void DeInit(void);
void Update(unsigned long tick);
void Render(void);
void EventHandler(SDL_Event *e);

#endif
