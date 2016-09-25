#ifndef TEXTURE_H_INCLUDED
#define TEXTURE_H_INCLUDED

#include "utils.h"

SDL_Surface* crop_surface(SDL_Surface* sprite_sheet, int x, int y, int width, int height);
GLuint LoadTexture(char const *filename,int *textw,int *texth);
void DrawTexture(int x, int y, GLuint textureid,int textw,int texth);
#endif 
