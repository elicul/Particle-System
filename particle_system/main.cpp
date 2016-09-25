#include "../external/utils.h"
#include "../external/particle.h"
#include "../external/gui.h"
#include "../external/texture.h"

bool running=true;
int WIDTH=800;
int HEIGHT=600;
const float M2P=20;
const float P2M=1/M2P;
int LastUsedParticle = 0;
float alpha = 1.0;
float red = 1.0;
float green = 0.0;
float blue = 0.0;
float size = 5.0;
float Size[5];
int posX = WIDTH/2;
int posY= 100;
int PosX[5];
int PosY[5];
b2Vec2 points[4];
bool pause = false;
bool texture = false;
bool old_texture = true;
bool tw_color = true;
bool crtaj = false;
bool crtaj2 = false;
bool crtaj3 = true;
int primjer = 1;
Uint32 life = 100;
int fps=0;
int tmp2=0;
int tmp3=0;

const int MAX = 1000;
const int Smax = 5;

int LastDisplayedParticle = 0;
int LastUsedParticleSystems[Smax];
int LastUsedParticleCircle=0;
int LastUsedParticleBox=0;
int LastUsedParticleTexture=0;

Particle p[MAX];
Cloud cloud[MAX];
Particle Systems[Smax][MAX];
Box box[MAX];
Circle circle[MAX];
myListener listener;

GLuint myglu;
int textw,texth;

void display();
void updateAlphaSize(){
    alpha -= 0.01;
    if(alpha < 0.0)
        alpha = 0.0;

    size += 0.3;
    if(size > 40)
        size = 40;
}

int unusedParticle(){

    for(int i=LastUsedParticle; i<MAX; i++){
        if (p[i].isDead()){
            LastUsedParticle = i;
            return i;
        }
    }

    for(int i=0; i<LastUsedParticle; i++){
        if (p[i].isDead()){
            LastUsedParticle = i;
            return i;
        }
    }

    return 0;


}
int undisplayedParticle(){

    for(int i=0; i<MAX; i++){
        if (p[i].isDead() == false){
                if(LastDisplayedParticle != i){
                    LastDisplayedParticle = i;
                    return i;
                }
        }
    }
    return 0;
}
int unusedParticleBox(){

    for(int i=LastUsedParticleBox; i<MAX; i++){
        if (box[i].isDead()){
            LastUsedParticleBox = i;
            return i;
        }
    }

    for(int i=0; i<LastUsedParticleBox; i++){
        if (box[i].isDead()){
            LastUsedParticleBox = i;
            return i;
        }
    }

    return 0;


}
int unusedParticleTexture(){

    for(int i=LastUsedParticleTexture; i<MAX; i++){
        if (cloud[i].isDead()){
            LastUsedParticleTexture = i;
            return i;
        }
    }

    for(int i=0; i<LastUsedParticleTexture; i++){
        if (cloud[i].isDead()){
            LastUsedParticleTexture = i;
            return i;
        }
    }

    return 0;


}
int unusedParticleSystem(int br){

    for(int i=LastUsedParticleSystems[br]; i<MAX; i++){
        if (Systems[br][i].isDead()){
            LastUsedParticleSystems[br] = i;
            return i;
        }
    }


    for(int i=0; i<LastUsedParticleSystems[br]; i++){
        if (Systems[br][i].isDead()){
            LastUsedParticleSystems[br] = i;
            return i;
        }
    }

    return 0;


}
int main(int argc, char** argv)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
    {
        printf( "Warning: Linear texture filtering not enabled!" );
    }
    SDL_Window *screen = SDL_CreateWindow("Particles",0, 0, WIDTH, HEIGHT,SDL_WINDOW_OPENGL);
    SDL_GL_CreateContext( screen );

    init();
    getWorld()->SetContactListener(&listener);
    srand(time(NULL));

    Uint32 start,old,old2;
    SDL_Event event;

    const int FPS = 60;
    old = SDL_GetTicks();
    old2 = SDL_GetTicks();
    TWinit();

    for(int i=0; i<Smax; i++){
        LastUsedParticleSystems[i]=0;
    }

    while(running){

        int handled;

        start=SDL_GetTicks();

        switch(primjer){
            case 1:
                    crtaj = false;
                    crtaj2 = false;
                    tmp2=0;

                    if(TwGetBarByName("Customize Primjer 2") != NULL){
                        TWbar2Delete();
                    }
                    if(TwGetBarByName("Customize Primjer 3") != NULL){
                        TWbar3Delete();
                    }
                    if(TwGetBarByName("Customize Primjer 4") != NULL){
                        TWbar4Delete();
                    }
                    if(TwGetBarByName("Customize Primjer 5") != NULL){
                        TWbar5Delete();
                    }
                    if(TwGetBarByName("Customize Primjer 6") != NULL){
                        TWbar6Delete();
                    }
                    if(TwGetBarByName("Frames per second ") != NULL){
                        TWbar7Delete();
                    }
                    if(TwGetBarByName("Customize Primjer 1") == NULL){
                        TWbar1();
                    }

                    if(pause!=false){

                        if(SDL_GetTicks()-old>=1.0){


                            if(p[0].isDead()==false){
                                    p[0].updateParticle(1);
                            }else{
                                    p[0].createParticle(life,posX,posY,size);
                            }

                            old=SDL_GetTicks();
                        }
                    }
                    while(SDL_PollEvent(&event)){

                        handled = TwEventSDL(&event, SDL_MAJOR_VERSION, SDL_MINOR_VERSION);

                        if(!handled){

                        switch(event.type)
                            {
                                case SDL_QUIT:
                                                running=false;
                                                break;
                                case SDL_KEYDOWN:
                                                switch(event.key.keysym.sym)
                                                {
                                                    case SDLK_ESCAPE:
                                                        running=false;
                                                        break;
                                                }
                                                break;
                            }
                        }
                   }

            break;

            case 2:

                    crtaj = false;
                    crtaj2 = false;
                    tmp2=0;

                    if(TwGetBarByName("Customize Primjer 1") != NULL){
                        TWbar1Delete();
                    }
                    if(TwGetBarByName("Customize Primjer 3") != NULL){
                        TWbar3Delete();
                    }
                    if(TwGetBarByName("Customize Primjer 4") != NULL){
                        TWbar4Delete();
                    }
                    if(TwGetBarByName("Customize Primjer 5") != NULL){
                        TWbar5Delete();
                    }
                    if(TwGetBarByName("Customize Primjer 6") != NULL){
                        TWbar6Delete();
                    }
                    if(TwGetBarByName("Frames per second ") != NULL){
                        TWbar7Delete();
                    }
                    if(TwGetBarByName("Customize Primjer 2") == NULL){
                        TWbar2();
                    }

                    if(pause!=false){

                        if(SDL_GetTicks()-old>=1.0){

                            LastUsedParticle = unusedParticle();
                            p[LastUsedParticle].createParticle(life,posX,posY,size);

                            for(int i=0; i<MAX; i++){
                                if(p[i].isDead()==false){
                                        p[i].updateParticle(1);
                                }
                            }
                            old=SDL_GetTicks();
                        }
                    }
                    while(SDL_PollEvent(&event)){

                            handled = TwEventSDL(&event, SDL_MAJOR_VERSION, SDL_MINOR_VERSION);

                            if(!handled){

                                switch(event.type)
                                {
                                    case SDL_QUIT:
                                        running=false;
                                        break;
                                    case SDL_KEYDOWN:
                                        switch(event.key.keysym.sym)
                                        {
                                            case SDLK_ESCAPE:
                                                running=false;
                                                break;
                                        }
                                        break;
                                }
                            }
                    }
            break;

            case 3:
                    crtaj2 = false;
                    tmp2=0;

                    if(TwGetBarByName("Customize Primjer 1") != NULL){
                        TWbar1Delete();
                    }
                    if(TwGetBarByName("Customize Primjer 2") != NULL){
                        TWbar2Delete();
                    }
                    if(TwGetBarByName("Customize Primjer 4") != NULL){
                        TWbar4Delete();
                    }
                    if(TwGetBarByName("Customize Primjer 5") != NULL){
                        TWbar5Delete();
                    }
                    if(TwGetBarByName("Customize Primjer 6") != NULL){
                        TWbar6Delete();
                    }
                    if(TwGetBarByName("Frames per second ") != NULL){
                        TWbar7Delete();
                    }
                    if(TwGetBarByName("Customize Primjer 3") == NULL){
                        TWbar3();
                    }

                    if(pause!=false){

                        if(SDL_GetTicks()-old>=1.0){

                            if(crtaj == true){
                                LastUsedParticle = unusedParticle();
                                p[LastUsedParticle].createParticle(life,posX,posY,size);
                            }
                            for(int i=0; i<MAX; i++){
                                if(p[i].isDead()==false){
                                    p[i].updateParticle(1);
                                }
                            }
                            old=SDL_GetTicks();
                        }
                    }
                    while(SDL_PollEvent(&event)){

                            handled = TwEventSDL(&event, SDL_MAJOR_VERSION, SDL_MINOR_VERSION);

                            if(!handled){

                                switch(event.type)
                                {
                                    case SDL_QUIT:
                                        running=false;
                                        break;
                                    case SDL_MOUSEBUTTONDOWN:
                                        if(event.button.button == SDL_BUTTON_LEFT){
                                            posX = event.button.x;
                                            posY = event.button.y;

                                            crtaj = true;

                                        }
                                        break;
                                    case SDL_KEYDOWN:
                                        switch(event.key.keysym.sym)
                                        {
                                            case SDLK_ESCAPE:
                                                running=false;
                                                break;
                                        }
                                        break;
                                }
                            }
                    }
            break;

            case 4:
                    crtaj = false;

                    if(TwGetBarByName("Customize Primjer 3") != NULL){
                        TWbar3Delete();
                    }
                    if(TwGetBarByName("Customize Primjer 1") != NULL){
                        TWbar1Delete();
                    }
                    if(TwGetBarByName("Customize Primjer 2") != NULL){
                        TWbar2Delete();
                    }
                    if(TwGetBarByName("Customize Primjer 5") != NULL){
                        TWbar5Delete();
                    }
                    if(TwGetBarByName("Customize Primjer 6") != NULL){
                        TWbar6Delete();
                    }
                    if(TwGetBarByName("Frames per second ") != NULL){
                        TWbar7Delete();
                    }
                    if(TwGetBarByName("Customize Primjer 4") == NULL){
                        TWbar4();
                    }

                    if(pause!=false){
                        if(SDL_GetTicks()-old>=1.0){

                            if(crtaj2 == true){
                                for(int i=0; i<tmp2; i++){
                                    LastUsedParticleSystems[i] = unusedParticleSystem(i);
                                    Size[i] = size;
                                    Systems[i][LastUsedParticleSystems[i]].createParticle(life,PosX[i],PosY[i],Size[i]);

                                }
                                for(int j=0; j<Smax; j++){
                                    for(int i=0; i<MAX; i++){
                                        if(Systems[j][i].isDead()==false){
                                            Systems[j][i].updateParticle(1);
                                        }
                                    }
                                }
                            }

                            old=SDL_GetTicks();
                        }
                    }


                    while(SDL_PollEvent(&event)){

                            handled = TwEventSDL(&event, SDL_MAJOR_VERSION, SDL_MINOR_VERSION);

                            if(!handled){

                                switch(event.type)
                                {
                                    case SDL_QUIT:
                                        running=false;
                                        break;
                                    case SDL_MOUSEBUTTONDOWN:
                                        if(event.button.button == SDL_BUTTON_LEFT){
                                            PosX[tmp2] = event.button.x;
                                            PosY[tmp2] = event.button.y;
                                            Size[tmp2] = 5;
                                            tmp2++;
                                            if(tmp2>5)tmp2=0;
                                            crtaj2 = true;

                                        }
                                        break;
                                    case SDL_KEYDOWN:
                                        switch(event.key.keysym.sym)
                                        {
                                            case SDLK_ESCAPE:
                                                running=false;
                                                break;
                                        }
                                        break;
                                }
                            }
                    }
            break;
            case 5:
                    crtaj = false;
                    crtaj2 = false;
                    tmp2=0;

                    if(TwGetBarByName("Customize Primjer 3") != NULL){
                        TWbar3Delete();
                    }
                    if(TwGetBarByName("Customize Primjer 1") != NULL){
                        TWbar1Delete();
                    }
                    if(TwGetBarByName("Customize Primjer 2") != NULL){
                        TWbar2Delete();
                    }
                    if(TwGetBarByName("Customize Primjer 4") != NULL){
                        TWbar4Delete();
                    }
                    if(TwGetBarByName("Customize Primjer 6") != NULL){
                        TWbar6Delete();
                        circle[0].deleteParticle();
                    }
                    if(TwGetBarByName("Frames per second ") != NULL){
                        TWbar7Delete();
                    }
                    if(TwGetBarByName("Customize Primjer 5") == NULL){
                        TWbar5();
                    }

                    if(pause!=false){
                        if(SDL_GetTicks()-old>=1.0){
                            LastUsedParticle = unusedParticle();
                            p[LastUsedParticle].createParticle(life,posX,posY,size);

                            for(int i=0; i<MAX; i++){
                                if(p[i].isDead()==false){
                                        p[i].updateParticle(1);
                                }
                            }
                            LastUsedParticleBox = unusedParticleBox();
                            box[LastUsedParticleBox].createParticle(life,posX,posY,size,b2_dynamicBody);

                            for(int i=0; i<MAX; i++){
                                if(box[i].isDead()==false){
                                        box[i].updateParticle(1);
                                }
                            }


                            old=SDL_GetTicks();
                        }
                    }
                    while(SDL_PollEvent(&event)){

                            handled = TwEventSDL(&event, SDL_MAJOR_VERSION, SDL_MINOR_VERSION);

                            if(!handled){

                                switch(event.type)
                                {
                                    case SDL_QUIT:
                                        running=false;
                                        break;
                                    case SDL_KEYDOWN:
                                        switch(event.key.keysym.sym)
                                        {
                                            case SDLK_ESCAPE:
                                                running=false;
                                                break;
                                        }
                                        break;
                                }
                            }
                    }
            break;
            case 6:
                    crtaj = false;
                    crtaj2 = false;
                    tmp2=0;

                    if(TwGetBarByName("Customize Primjer 3") != NULL){
                        TWbar3Delete();
                    }
                    if(TwGetBarByName("Customize Primjer 1") != NULL){
                        TWbar1Delete();
                    }
                    if(TwGetBarByName("Customize Primjer 2") != NULL){
                        TWbar2Delete();
                    }
                    if(TwGetBarByName("Customize Primjer 4") != NULL){
                        TWbar4Delete();
                    }
                    if(TwGetBarByName("Customize Primjer 5") != NULL){
                        TWbar5Delete();    
                    }
                    if(TwGetBarByName("Frames per second ") != NULL){
                        TWbar7Delete();
                    }
                    if(TwGetBarByName("Customize Primjer 6") == NULL){
                        TWbar6();
                        getWorld()->SetGravity( b2Vec2(0.0,9.81) );
                        circle[0].createParticle(400,300,50,b2_staticBody);
                        size = 5.0;
                        alpha = 1.0;
                    }

                    if(pause!=false){
                        if(SDL_GetTicks()-old>=1.0){
                            LastUsedParticle = unusedParticle();
                            p[LastUsedParticle].createParticle(life,posX,posY,size);

                            for(int i=0; i<MAX; i++){
                                if(p[i].isDead()==false){
                                        p[i].updateParticle(1);
                                }
                            }

                            old=SDL_GetTicks();
                        }
                    }
                    while(SDL_PollEvent(&event)){

                            handled = TwEventSDL(&event, SDL_MAJOR_VERSION, SDL_MINOR_VERSION);

                            if(!handled){

                                switch(event.type)
                                {
                                    case SDL_QUIT:
                                        running=false;
                                        break;
                                    case SDL_KEYDOWN:
                                        switch(event.key.keysym.sym)
                                        {
                                            case SDLK_ESCAPE:
                                                running=false;
                                                break;
                                        }
                                        break;
                                }
                            }
                    }
            break;
            case 7:
                    crtaj = false;
                    crtaj2 = false;
                    tmp2=0;


                    if(TwGetBarByName("Customize Primjer 3") != NULL){
                        TWbar3Delete();
                    }
                    if(TwGetBarByName("Customize Primjer 1") != NULL){
                        TWbar1Delete();
                    }
                    if(TwGetBarByName("Customize Primjer 2") != NULL){
                        TWbar2Delete();
                    }
                    if(TwGetBarByName("Customize Primjer 4") != NULL){
                        TWbar4Delete();
                    }
                    if(TwGetBarByName("Customize Primjer 5") != NULL){
                        TWbar5Delete();
                    }
                    if(TwGetBarByName("Customize Primjer 6") != NULL){
                        TWbar6Delete();
                        circle[0].deleteParticle();
                        myglu=LoadTexture("data/cloud.png",&textw,&texth);
                        getWorld()->SetGravity( b2Vec2(0.0,0.0) );
                        alpha = 1.0;
                        size = 10.0;
                        tmp3=0;
                    }
                    if(TwGetBarByName("Frames per second ") == NULL){
                        TWbar7();
                    }

                    if(pause!=false){

                        if(SDL_GetTicks()-old>=6.0){

                            if(tmp3<100){
                            LastUsedParticleTexture = unusedParticleTexture();
                            cloud[LastUsedParticleTexture].createParticle(100,randFromInt(390, 410),randFromInt(190, 210),5.0);
                            }else if(tmp3>=200){
                                tmp3=0;
                                alpha=1.0;
                                size=10.0;
                            }
                            for(int i=0; i<MAX; i++){
                                if(cloud[i].isDead()==false){
                                        cloud[i].updateParticle(1);
                                }
                            }
                            updateAlphaSize();
                            old=SDL_GetTicks();
                            tmp3++;
                        }

                    }
                    while(SDL_PollEvent(&event)){

                            handled = TwEventSDL(&event, SDL_MAJOR_VERSION, SDL_MINOR_VERSION);

                            if(!handled){

                                switch(event.type)
                                {
                                    case SDL_QUIT:
                                        running=false;
                                        break;
                                    case SDL_KEYDOWN:
                                        switch(event.key.keysym.sym)
                                        {
                                            case SDLK_ESCAPE:
                                                running=false;
                                                break;
                                        }
                                        break;
                                }
                            }
                    }
            break;
            default:
                printf("Primjer Error\n");
            break;

        }

        if(pause!=false){
            display();
            getWorld()->Step(1.0/60.0,8,3);
        }

        TwDraw();
        SDL_GL_SwapWindow(screen);

        if(1000.0/FPS>SDL_GetTicks()-start){
            SDL_Delay(1000.0/FPS-(SDL_GetTicks()-start));
            fps = 1000/(SDL_GetTicks()-start);
        }


    }
    TwTerminate();
    SDL_Quit();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDisable(GL_DEPTH_TEST);
    glLoadIdentity();

    b2Body* tmp=getWorld()->GetBodyList();
    while(tmp)
    {
        switch(primjer){
            case 1:
                    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
                    if(tmp->GetFixtureList()->GetShape()->GetType()==0){
                            b2CircleShape* c=((b2CircleShape*)tmp->GetFixtureList()->GetShape());
                            drawParticle(tmp->GetWorldCenter(), c->m_radius, tmp->GetAngle(), red, green, blue, alpha);
                    }
            break;
            case 2:
                    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
                    if(tmp->GetFixtureList()->GetShape()->GetType()==0){
                            b2CircleShape* c=((b2CircleShape*)tmp->GetFixtureList()->GetShape());
                            drawParticle(tmp->GetWorldCenter(), c->m_radius, tmp->GetAngle(), red, green, blue, alpha);
                    }
            break;
            case 3:
                    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
                    if(tmp->GetFixtureList()->GetShape()->GetType()==0){
                            b2CircleShape* c=((b2CircleShape*)tmp->GetFixtureList()->GetShape());
                            drawParticle(tmp->GetWorldCenter(), c->m_radius, tmp->GetAngle(), red, green, blue, alpha);
                    }
            break;
            case 4:
                    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
                    if(tmp->GetFixtureList()->GetShape()->GetType()==0){
                            b2CircleShape* c=((b2CircleShape*)tmp->GetFixtureList()->GetShape());
                            drawParticle(tmp->GetWorldCenter(), c->m_radius, tmp->GetAngle(), red, green, blue, alpha);
                    }
            break;
            case 5:
                    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
                    if(tmp->GetFixtureList()->GetShape()->GetType()==0){
                        b2CircleShape* c=((b2CircleShape*)tmp->GetFixtureList()->GetShape());
                        drawParticle(tmp->GetWorldCenter(), c->m_radius, tmp->GetAngle(), red, green, blue, alpha);
                    }else{
                        for(int i=0; i<4; i++){
                            points[i] = ((b2PolygonShape*)tmp->GetFixtureList()->GetShape())->GetVertex(i);

                        }
                        drawBox(points, tmp->GetWorldCenter(), tmp->GetAngle(), red, green, blue, alpha);
                    }
            break;
            case 6:
                    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
                    if(tmp->GetFixtureList()->GetShape()->GetType()==0){
                        b2CircleShape* c=((b2CircleShape*)tmp->GetFixtureList()->GetShape());
                        int a= *((int*)tmp->GetUserData());
                        if(a==2){
                            drawCircle(tmp->GetWorldCenter(), c->m_radius, tmp->GetAngle(), red, green, blue, alpha);
                        }else{
                            drawParticle(tmp->GetWorldCenter(), c->m_radius, tmp->GetAngle(), red, green, blue, alpha);
                        }
                    }else{
                        for(int i=0; i<4; i++){
                            points[i] = ((b2PolygonShape*)tmp->GetFixtureList()->GetShape())->GetVertex(i);
                        }
                        drawBox(points, tmp->GetWorldCenter(), tmp->GetAngle(), red, green, blue, alpha);
                    }
            break;
            case 7:
                    glClearColor(0.20f, 0.30f, 0.60f, 1.0f);
                    if(tmp->GetFixtureList()->GetShape()->GetType()==0){

                        b2CircleShape* c=((b2CircleShape*)tmp->GetFixtureList()->GetShape());
                        int a= *((int*)tmp->GetUserData());
                        if(a==3){
                            b2Vec2 position = tmp->GetPosition();
                            glColor4f(1.0,1.0,1.0,alpha);
                            DrawTexture(position.x*M2P-5,position.y*M2P-5,myglu,size*4.0,size*4.0);

                        }
                    }

            break;
            default:
            break;
        }

        tmp=tmp->GetNext();
    }

}
