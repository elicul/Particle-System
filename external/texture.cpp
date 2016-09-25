#include "texture.h"
#include "utils.h"
#include "particle.h"

SDL_Surface* crop_surface(SDL_Surface* sprite_sheet, int x, int y, int width, int height)
{
    SDL_Surface* surface = SDL_CreateRGBSurface(sprite_sheet->flags, width, height, sprite_sheet->format->BitsPerPixel, sprite_sheet->format->Rmask, sprite_sheet->format->Gmask, sprite_sheet->format->Bmask, sprite_sheet->format->Amask);
    SDL_Rect rect = {x, y, width, height};
    SDL_BlitSurface(sprite_sheet, &rect, surface, 0);
    return surface;
}

GLuint LoadTexture(char const *filename,int *textw,int *texth) {

        SDL_Surface *surface;
        GLuint textureid;
        int mode;

        surface = IMG_Load(filename);

        //surface = crop_surface(surface, 384,640, 128,128);

        // could not load filename
        if (!surface) {

                return 0;

        }

        // work out what format to tell glTexImage2D to use...
        if (surface->format->BytesPerPixel == 3) { // RGB 24bit

                mode = GL_RGB;

        } else if (surface->format->BytesPerPixel == 4) { // RGBA 32bit

                mode = GL_RGBA;

        } else {

                SDL_FreeSurface(surface);
                return 0;

        }

        *textw=surface->w;
        *texth=surface->h;

        // create one texture name
        glGenTextures(1, &textureid);

        // tell opengl to use the generated texture name
        glBindTexture(GL_TEXTURE_2D, textureid);

        // this reads from the sdl surface and puts it into an opengl texture
        glTexImage2D(GL_TEXTURE_2D, 0, mode, surface->w, surface->h, 0, mode, GL_UNSIGNED_BYTE, surface->pixels);

        // these affect how this texture is drawn later on...
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

        // clean up
        SDL_FreeSurface(surface);

        return textureid;

}

void DrawTexture(int x, int y, GLuint textureid,int textw,int texth) {

        // tell opengl to use the generated texture name

        glBindTexture(GL_TEXTURE_2D, textureid);

        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glEnable(GL_TEXTURE_2D);

        // make a rectangle
        glBegin(GL_QUADS);

        // top left
        glTexCoord2i(0, 0);
        glVertex3f(x, y, 0);

        // top right
        glTexCoord2i(1, 0);
        glVertex3f(x+textw, y, 0);

        // bottom right
        glTexCoord2i(1, 1);
        glVertex3f(x+textw, y+texth, 0);

        // bottom left
        glTexCoord2i(0, 1);
        glVertex3f(x, y+texth, 0);

        glEnd();

        glDisable(GL_TEXTURE_2D );
}

