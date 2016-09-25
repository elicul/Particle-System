#include "utils.h"
#include "particle.h"
#include "gui.h"
#include "texture.h"

b2World* world;

b2World* getWorld(){
    return world;
}

double randFrom(double min, double max)
{
    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}
int randFromInt(int min, int max)
{
    int range = (max - min);
    int div = RAND_MAX / range;
    return min + (rand() / div);
}

void drawParticle(b2Vec2 center, float r, float angle, float red, float green, float blue, float alpha){
    glColor4f(red,green,blue,alpha);

    glPushMatrix();
        glTranslatef(center.x*M2P,center.y*M2P,0);
        glRotatef(angle*180.0/M_PI,0,0,1);
        glBegin(GL_TRIANGLE_FAN);
            for (float a = 0; a < 360 * DEGTORAD; a += 10 * DEGTORAD)
                glVertex2f( r*sinf(a)*M2P, r*cosf(a)*M2P );
        glEnd();
    glPopMatrix();
}

void drawBox(b2Vec2* points,b2Vec2 center, float angle, float red, float green, float blue, float alpha){
    glColor4f(0.25,0.55,0.0,alpha);
    glPushMatrix();
        glTranslatef(center.x*M2P,center.y*M2P,0);
        glRotatef(angle*180.0/M_PI,0,0,1);
        glBegin(GL_QUADS);
            for(int i=0;i<4;i++)
                glVertex2f(points[i].x*M2P,points[i].y*M2P);
        glEnd();
    glPopMatrix();
}

void drawCircle(b2Vec2 center, float r, float angle, float red, float green, float blue, float alpha){
    glColor4f(0.0,0.15,0.80,alpha);

    glPushMatrix();
        glTranslatef(center.x*M2P,center.y*M2P,0);
        glRotatef(angle*180.0/M_PI,0,0,1);
        glBegin(GL_TRIANGLE_FAN);
            for (float a = 0; a < 360 * DEGTORAD; a += 10 * DEGTORAD)
                glVertex2f( r*sinf(a)*M2P, r*cosf(a)*M2P );
        glEnd();
    glPopMatrix();
}

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,WIDTH,HEIGHT,0,-1,1);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glShadeModel(GL_SMOOTH);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    world = new b2World(b2Vec2(0.0, 9.81));
}




