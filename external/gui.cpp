#include "gui.h"
#include "utils.h"
#include "particle.h"

TwBar *bar;
TwBar *primjer_1;
TwBar *primjer_2;
TwBar *primjer_3;
TwBar *primjer_4;
TwBar *primjer_5;
TwBar *primjer_6;
TwBar *primjer_7;
TwBar *fpsBar;

void TWbar1(){
    primjer_1 = TwNewBar("Customize Primjer 1");
    TwDefine(" 'Customize Primjer 1' position='10 120'");
    TwDefine(" 'Customize Primjer 1' size='200 180'");

    TwAddVarRW(primjer_1, "PosX", TW_TYPE_INT32, &posX, " min=1 max=800 step=1 group='Particle position' label='Position X' ");
    TwAddVarRW(primjer_1, "PosY", TW_TYPE_INT32, &posY, " min=1 max=600 step=1 group='Particle position' label='Position Y' ");

    TwAddVarRW(primjer_1, "Size", TW_TYPE_FLOAT, &size, " min=1.0 max=10.0 step=0.5 label='Particle size' ");

    TwAddVarRW(primjer_1, "Red", TW_TYPE_FLOAT, &red, " min=0.0 max=1.0 step=0.01 group='Particle color' label='Red' ");
    TwAddVarRW(primjer_1, "Green", TW_TYPE_FLOAT, &green, " min=0.0 max=1.0 step=0.01 group='Particle color' label='Green' ");
    TwAddVarRW(primjer_1, "Blue", TW_TYPE_FLOAT, &blue, " min=0.0 max=1.0 step=0.01 group='Particle color' label='Blue' ");
    //TwAddVarRW(primjer_1, "Alpha", TW_TYPE_FLOAT, &alpha, " min=0.0 max=1.0 step=0.01 group='Particle color' label='Alpha' ");

    fpsBar = TwNewBar("Frames per second");
    TwDefine(" 'Frames per second' position='10 310'");
    TwDefine(" 'Frames per second' size='200 20'");
    TwAddVarRO(fpsBar, "FPS", TW_TYPE_INT32, &fps, " label='FPS' ");
}
void TWbar2(){
    primjer_2 = TwNewBar("Customize Primjer 2");
    TwDefine(" 'Customize Primjer 2' position='10 120'");
    TwDefine(" 'Customize Primjer 2' size='200 180'");

    TwAddVarRW(primjer_2, "PosX", TW_TYPE_INT32, &posX, " min=1 max=800 step=1 group='Particle system position' label='Position X' ");
    TwAddVarRW(primjer_2, "PosY", TW_TYPE_INT32, &posY, " min=1 max=600 step=1 group='Particle system position' label='Position Y' ");

    TwAddVarRW(primjer_2, "Size", TW_TYPE_FLOAT, &size, " min=1.0 max=10.0 step=0.5 label='Particle size' ");

    TwAddVarRW(primjer_2, "Red", TW_TYPE_FLOAT, &red, " min=0.0 max=1.0 step=0.01 group='Particle system color' label='Red' ");
    TwAddVarRW(primjer_2, "Green", TW_TYPE_FLOAT, &green, " min=0.0 max=1.0 step=0.01 group='Particle system color' label='Green' ");
    TwAddVarRW(primjer_2, "Blue", TW_TYPE_FLOAT, &blue, " min=0.0 max=1.0 step=0.01 group='Particle system color' label='Blue' ");
    //TwAddVarRW(primjer_1, "Alpha", TW_TYPE_FLOAT, &alpha, " min=0.0 max=1.0 step=0.01 group='Particle Color' label='Alpha' ");

    fpsBar = TwNewBar("Frames per second");
    TwDefine(" 'Frames per second' position='10 310'");
    TwDefine(" 'Frames per second' size='200 20'");
    TwAddVarRO(fpsBar, "FPS", TW_TYPE_INT32, &fps, " label='FPS' ");
}
void TWbar3(){
    primjer_3 = TwNewBar("Customize Primjer 3");
    TwDefine(" 'Customize Primjer 3' position='10 120'");
    TwDefine(" 'Customize Primjer 3' size='200 180'");

    TwAddVarRW(primjer_3, "PosX", TW_TYPE_INT32, &posX, " min=1 max=800 step=1 group='Particle system position' label='Position X' ");
    TwAddVarRW(primjer_3, "PosY", TW_TYPE_INT32, &posY, " min=1 max=600 step=1 group='Particle system position' label='Position Y' ");

    TwAddVarRW(primjer_3, "Size", TW_TYPE_FLOAT, &size, " min=1.0 max=10.0 step=0.5 label='Particle size' ");

    TwAddVarRW(primjer_3, "Red", TW_TYPE_FLOAT, &red, " min=0.0 max=1.0 step=0.01 group='Particle system color' label='Red' ");
    TwAddVarRW(primjer_3, "Green", TW_TYPE_FLOAT, &green, " min=0.0 max=1.0 step=0.01 group='Particle system color' label='Green' ");
    TwAddVarRW(primjer_3, "Blue", TW_TYPE_FLOAT, &blue, " min=0.0 max=1.0 step=0.01 group='Particle system color' label='Blue' ");
    //TwAddVarRW(primjer_1, "Alpha", TW_TYPE_FLOAT, &alpha, " min=0.0 max=1.0 step=0.01 group='Particle Color' label='Alpha' ");

    fpsBar = TwNewBar("Frames per second");
    TwDefine(" 'Frames per second' position='10 310'");
    TwDefine(" 'Frames per second' size='200 20'");
    TwAddVarRO(fpsBar, "FPS", TW_TYPE_INT32, &fps, " label='FPS' ");
}
void TWbar4(){
    primjer_4 = TwNewBar("Customize Primjer 4");
    TwDefine(" 'Customize Primjer 4' position='10 120'");
    TwDefine(" 'Customize Primjer 4' size='200 130'");


    TwAddVarRW(primjer_4, "Size", TW_TYPE_FLOAT, &size, " min=1.0 max=10.0 step=0.5 label='Particle size' ");

    TwAddVarRW(primjer_4, "Red", TW_TYPE_FLOAT, &red, " min=0.0 max=1.0 step=0.01 group='Particle system color' label='Red' ");
    TwAddVarRW(primjer_4, "Green", TW_TYPE_FLOAT, &green, " min=0.0 max=1.0 step=0.01 group='Particle system color' label='Green' ");
    TwAddVarRW(primjer_4, "Blue", TW_TYPE_FLOAT, &blue, " min=0.0 max=1.0 step=0.01 group='Particle system color' label='Blue' ");
    //TwAddVarRW(primjer_1, "Alpha", TW_TYPE_FLOAT, &alpha, " min=0.0 max=1.0 step=0.01 group='Particle Color' label='Alpha' ");

    fpsBar = TwNewBar("Frames per second");
    TwDefine(" 'Frames per second' position='10 260'");
    TwDefine(" 'Frames per second' size='200 20'");
    TwAddVarRO(fpsBar, "FPS", TW_TYPE_INT32, &fps, " label='FPS' ");
}
void TWbar5(){
    primjer_5 = TwNewBar("Customize Primjer 5");
    TwDefine(" 'Customize Primjer 5' position='10 120'");
    TwDefine(" 'Customize Primjer 5' size='200 120'");

    TwAddVarRW(primjer_5, "PosX", TW_TYPE_INT32, &posX, " min=1 max=800 step=1 group='Particle position' label='Position X' ");
    TwAddVarRW(primjer_5, "PosY", TW_TYPE_INT32, &posY, " min=1 max=600 step=1 group='Particle position' label='Position Y' ");

    TwAddVarRW(primjer_5, "Size", TW_TYPE_FLOAT, &size, " min=1.0 max=10.0 step=0.5 label='Particle size' ");

    fpsBar = TwNewBar("Frames per second");
    TwDefine(" 'Frames per second' position='10 250'");
    TwDefine(" 'Frames per second' size='200 20'");
    TwAddVarRO(fpsBar, "FPS", TW_TYPE_INT32, &fps, " label='FPS' ");
}
void TWbar6(){
    primjer_6 = TwNewBar("Customize Primjer 6");
    TwDefine(" 'Customize Primjer 6' position='10 120'");
    TwDefine(" 'Customize Primjer 6' size='200 120'");

    TwAddVarRW(primjer_6, "PosX", TW_TYPE_INT32, &posX, " min=1 max=800 step=1 group='Particle position' label='Position X' ");
    TwAddVarRW(primjer_6, "PosY", TW_TYPE_INT32, &posY, " min=1 max=600 step=1 group='Particle position' label='Position Y' ");

    TwAddVarRW(primjer_6, "Size", TW_TYPE_FLOAT, &size, " min=1.0 max=10.0 step=0.5 label='Particle size' ");

    fpsBar = TwNewBar("Frames per second");
    TwDefine(" 'Frames per second' position='10 250'");
    TwDefine(" 'Frames per second' size='200 20'");
    TwAddVarRO(fpsBar, "FPS", TW_TYPE_INT32, &fps, " label='FPS' ");
}
void TWbar7(){
    fpsBar = TwNewBar("Frames per second ");
    TwDefine(" 'Frames per second ' position='10 120'");
    TwDefine(" 'Frames per second ' size='200 20'");
    TwAddVarRO(fpsBar, "FPS", TW_TYPE_INT32, &fps, " label='FPS' ");
}
void TWbar1Delete(){
    TwDeleteBar(primjer_1);
    TwDeleteBar(fpsBar);
}
void TWbar2Delete(){
    TwDeleteBar(primjer_2);
    TwDeleteBar(fpsBar);
}
void TWbar3Delete(){
    TwDeleteBar(primjer_3);
    TwDeleteBar(fpsBar);
}
void TWbar4Delete(){
    TwDeleteBar(primjer_4);
    TwDeleteBar(fpsBar);
}
void TWbar5Delete(){
    TwDeleteBar(primjer_5);
    TwDeleteBar(fpsBar);
}
void TWbar6Delete(){
    TwDeleteBar(primjer_6);
    TwDeleteBar(fpsBar);
}
void TWbar7Delete(){
    TwDeleteBar(fpsBar);
}
void TWinit(){

    // Initialize AntTweakBar
    TwInit(TW_OPENGL, NULL);

    // Tell the window size to AntTweakBar
    TwWindowSize(WIDTH, HEIGHT);

    // Create a tweak bar
    bar = TwNewBar("Options");

    TwDefine(" GLOBAL help='Particle system with physics simulation.\nPress [Esc] to quit the program.\n' "); // Message added to the help bar.
    TwDefine(" Options help='These properties defines the color of a particle' ");
    TwDefine(" Options position='10 10'");
    TwDefine(" Options size='200 100'");
    TwAddVarRW(bar, "Pause", TW_TYPE_BOOL32, &pause, " label='Start/Pause ' true='Start' false='Pause' help='Start/Pause' ");
    TwAddVarRW(bar, "Primjer", TW_TYPE_INT32, &primjer, " min=1 max=7 step=1 label='Primjer' ");
    TwAddVarRW(bar, "Quit", TW_TYPE_BOOL32, &running, " label='Quit ' true='Yes' false='No' key='ESC' help='Exit' ");

}
