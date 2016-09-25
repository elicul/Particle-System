#include "particle.h"
#include "utils.h"


Particle::Particle(){
    p_body = NULL;
    p_size = 5.0;
    p_pos.x = 400;
    p_pos.y = 100;
    p_alpha = 1.0;
    p_life = 0.0;
    p_lastContact = NULL;
    p_num = 0;
}

void Particle::createParticle(Uint32 life, int pos_x, int pos_y, float size){
    p_life = life;
    p_alpha = 1.0;
    p_pos.x = pos_x;
    p_pos.y = pos_y;
    p_size = size;

    b2BodyDef myBodyDef;
    myBodyDef.type = b2_dynamicBody;
    myBodyDef.position.Set(p_pos.x*P2M,p_pos.y*P2M);
    p_body = getWorld()->CreateBody(&myBodyDef);

    b2CircleShape circleShape;
    circleShape.m_p.Set(0, 0);
    circleShape.m_radius = p_size*P2M;

    b2FixtureDef myFixtureDef;
    myFixtureDef.shape = &circleShape;
    myFixtureDef.density = 1.0;
    myFixtureDef.friction = 0.4;
    myFixtureDef.restitution = 0.0;
    p_body->CreateFixture(&myFixtureDef);
    p_body->SetUserData(&p_num);
}
void Particle::updateParticle(Uint32 decLife){

    p_body->ApplyForce( b2Vec2(randFrom(-1.0, 1.0),randFrom(-1.0, 1.0)), p_body->GetWorldCenter() );

    p_life -= decLife;
    p_alpha -= 0.01;
    if(p_life<=0.0)
        getWorld()->DestroyBody(p_body);

}
void Particle::deleteParticle(){

    getWorld()->DestroyBody(p_body);

}
bool Particle::isDead(){
    if(p_life > 0.0){
        return false;
    }else{
        return true;
    }
}

Box::Box(){
    p_body = NULL;
    p_a = 5.0;
    p_pos.x = 400;
    p_pos.y = 100;
    p_alpha = 1.0;
    p_life = 0.0;
}
void Box::createParticle(Uint32 life, int pos_x, int pos_y, float a, b2BodyType type){
    p_life = life;
    p_alpha = 1.0;
    p_pos.x = pos_x;
    p_pos.y = pos_y;
    p_a = a;
    p_num = 1;

    b2BodyDef myBodyDef;
    myBodyDef.type = type;
    myBodyDef.position.Set(p_pos.x*P2M,p_pos.y*P2M);
    p_body = getWorld()->CreateBody(&myBodyDef);

    b2PolygonShape shape;
    shape.SetAsBox(P2M*p_a,P2M*p_a);

    b2FixtureDef myFixtureDef;
    myFixtureDef.shape = &shape;
    myFixtureDef.density = 1.0;
    myFixtureDef.friction = 0.4;
    myFixtureDef.restitution = 0.0;
    p_body->CreateFixture(&myFixtureDef);
    p_body->SetUserData(&p_num);
}

Circle::Circle(){
    p_body = NULL;
    p_size = 5.0;
    p_pos.x = 400;
    p_pos.y = 100;
    p_alpha = 1.0;
    p_life = 0.0;
    p_lastContact = NULL;
    p_num = 2;
}
void Circle::createParticle(int pos_x, int pos_y, float size, b2BodyType type){
    p_alpha = 1.0;
    p_pos.x = pos_x;
    p_pos.y = pos_y;
    p_size = size;

    b2BodyDef myBodyDef;
    myBodyDef.type = type;
    myBodyDef.position.Set(p_pos.x*P2M,p_pos.y*P2M);
    p_body = getWorld()->CreateBody(&myBodyDef);

    b2CircleShape circleShape;
    circleShape.m_p.Set(0, 0);
    circleShape.m_radius = p_size*P2M;

    b2FixtureDef myFixtureDef;
    myFixtureDef.shape = &circleShape;
    myFixtureDef.density = 1.0;
    myFixtureDef.friction = 0.4;
    myFixtureDef.restitution = 0.0;
    p_body->CreateFixture(&myFixtureDef);
    p_body->SetUserData(&p_num);
}

Cloud::Cloud(){
    p_body = NULL;
    p_size = 5.0;
    p_texture_size = 0;
    p_pos.x = 400;
    p_pos.y = 300;
    p_alpha = 1.0;
    p_life = 0.0;
    p_lastContact = NULL;
    p_num = 3;
}
void Cloud::createParticle(Uint32 life, int pos_x, int pos_y, float size){
    p_life = life;
    p_alpha = 1.0;
    p_pos.x = pos_x;
    p_pos.y = pos_y;
    p_size = size;
    p_texture_size = 0;

    b2BodyDef myBodyDef;
    myBodyDef.type = b2_dynamicBody;
    myBodyDef.position.Set(p_pos.x*P2M,p_pos.y*P2M);
    p_body = getWorld()->CreateBody(&myBodyDef);

    b2CircleShape circleShape;
    circleShape.m_p.Set(0, 0);
    circleShape.m_radius = p_size*P2M;

    b2FixtureDef myFixtureDef;
    myFixtureDef.shape = &circleShape;
    myFixtureDef.density = 1.0;
    myFixtureDef.friction = 0.4;
    myFixtureDef.restitution = 0.0;
    p_body->CreateFixture(&myFixtureDef);
    p_body->SetUserData(&p_num);
}
void Cloud::updateParticle(Uint32 decLife){

    p_body->ApplyForce( b2Vec2(randFrom(-5.0, 5.0),randFrom(-5.0, 5.0)), p_body->GetWorldCenter() );
    p_life -= decLife;

    if(p_life<=0.0){
        getWorld()->DestroyBody(p_body);
    }

}
void myListener::BeginContact(b2Contact* contact){

}
void myListener::EndContact(b2Contact* contact){

}
void myListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse){

}
void myListener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold){
    b2Body* one=contact->GetFixtureA()->GetBody();
    b2Body* two=contact->GetFixtureB()->GetBody();
    int numPoints = contact->GetManifold()->pointCount;
    b2WorldManifold worldManifold;
    contact->GetWorldManifold( &worldManifold );
    int a= *((int*)one->GetUserData());
    if(a==0){

    }else if(a==2){
        for (int i = 0; i < numPoints; i++){
            two->ApplyAngularImpulse( 20 );
            two->ApplyLinearImpulse(b2Vec2(0,-50),two->GetWorldPoint( b2Vec2(worldManifold.points[i].x, worldManifold.points[i].y )));
        }
    }
    int b= *((int*)two->GetUserData());
    if(b==0){

    }else if(b==2){

        for (int i = 0; i < numPoints; i++){
            one->ApplyAngularImpulse( 20 );
            one->ApplyLinearImpulse(b2Vec2(0,-50),two->GetWorldPoint( b2Vec2(worldManifold.points[i].x, worldManifold.points[i].y )));
        }
    }

}
