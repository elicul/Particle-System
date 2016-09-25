#ifndef PARTICLE_H_INCLUDED
#define PARTICLE_H_INCLUDED

#include "utils.h"

extern float alpha;
extern float red;
extern float green;
extern float blue;
extern const int p_Max;
extern float size;
extern int posX;
extern int posY;

class Particle{
    public:
        b2Body* p_body;
        b2Vec2 p_pos;
        float p_size;
        Uint32 p_life;
        float p_alpha;
        b2Contact* p_lastContact;
        int p_num;

    public:
        Particle();
        void createParticle(Uint32 life, int pos_x, int pos_y, float size);
        void updateParticle(Uint32 decLife);
        void deleteParticle();
        void Die();
        bool isDead();
};

class Box : public Particle{
    public:
        float p_a;
    public:
        Box();
        void createParticle(Uint32 life, int pos_x, int pos_y, float a, b2BodyType type);
};

class Circle : public Particle{
    public:
        Circle();
        void createParticle(int pos_x, int pos_y, float size, b2BodyType type);
};

class Cloud : public Particle{
    public:
        int p_texture_size;
    public:
        Cloud();
        void createParticle(Uint32 life, int pos_x, int pos_y, float size);
        void updateParticle(Uint32 decLife);

};

class myListener : public b2ContactListener{
    public:
        void BeginContact(b2Contact* contact);
        void EndContact(b2Contact* contact);
        void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);
        void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
};

#endif 
 
