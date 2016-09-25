#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <GL/gl.h>
#include <Box2D/Box2D.h>
#include <AntTweakBar.h>

#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f

extern int WIDTH;
extern int HEIGHT;
extern int primjer;
extern int fps;
extern int systemSelect;
extern int PosX[5];
extern int PosY[5];
extern float Size[5];
extern const float M2P;
extern const float P2M;
extern bool running;
extern bool pause;
extern bool texture;
extern bool old_texture;
extern bool tw_color;


b2World* getWorld();
double randFrom(double min, double max);
int randFromInt(int min, int max);

void drawParticle(b2Vec2 center, float r, float angle, float red, float green, float blue, float alpha);
void drawBox(b2Vec2* points,b2Vec2 center, float angle, float red, float green, float blue, float alpha);
void drawCircle(b2Vec2 center, float r, float angle, float red, float green, float blue, float alpha);

void init();

#endif 
