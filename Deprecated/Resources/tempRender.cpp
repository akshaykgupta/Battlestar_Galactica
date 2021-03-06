//This example program is created by thecplusplusuy for demonstration purposes. It's a simple skybox:
//http://www.youtube.com/user/thecplusplusguy
//Free source, modify if you want, LGPL licence (I guess), I would be happy, if you would not delete the link
//so other people can see the tutorial
//this file is functions.cpp, it's contain the actual implementation of the skybox
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <SDL/SDL.h>
#include <cmath>
using namespace std;

float camX=0.0,camY=0.0,camZ=5.0;
float camYaw=0.0;
float camPitch=0.0;
enum {SKY_LEFT=0,SKY_BACK,SKY_RIGHT,SKY_FRONT,SKY_TOP,SKY_BOTTOM};      //constants for the skybox faces, so we don't have to remember so much number
unsigned int skybox[6]; //the ids for the textures
#ifndef M_PI
#define M_PI 3.1415926535
#endif
 unsigned int loadTexture(const char* filename);
//load all of the textures, to the skybox array
void initskybox()
{
        skybox[SKY_LEFT]=loadTexture("le.bmp");
        skybox[SKY_BACK]=loadTexture("ba.bmp");
        skybox[SKY_RIGHT]=loadTexture("ri.bmp");
        skybox[SKY_FRONT]=loadTexture("fr.bmp");
        skybox[SKY_TOP]=loadTexture("to.bmp");
        skybox[SKY_BOTTOM]=loadTexture("bo.bmp");
}
//delete all of the textures from the skybox array (to avoid memory leaks)
void killskybox()
{
        glDeleteTextures(6,&skybox[0]);
}
 
void drawSkybox(float size)
{
        bool b1=glIsEnabled(GL_TEXTURE_2D);     //new, we left the textures turned on, if it was turned on
        glDisable(GL_LIGHTING); //turn off lighting, when making the skybox
        glDisable(GL_DEPTH_TEST);       //turn off depth texting
        glEnable(GL_TEXTURE_2D);        //and turn on texturing
        glBindTexture(GL_TEXTURE_2D,skybox[SKY_BACK]);  //use the texture we want
        glBegin(GL_QUADS);      //and draw a face
                //back face
                glTexCoord2f(0,0);      //use the correct texture coordinate
                glVertex3f(size/2,size/2,size/2);       //and a vertex
                glTexCoord2f(1,0);      //and repeat it...
                glVertex3f(-size/2,size/2,size/2);
                glTexCoord2f(1,1);
                glVertex3f(-size/2,-size/2,size/2);
                glTexCoord2f(0,1);
                glVertex3f(size/2,-size/2,size/2);
        glEnd();
        glBindTexture(GL_TEXTURE_2D,skybox[SKY_LEFT]);
        glBegin(GL_QUADS);     
                //left face
                glTexCoord2f(0,0);
                glVertex3f(-size/2,size/2,size/2);
                glTexCoord2f(1,0);
                glVertex3f(-size/2,size/2,-size/2);
                glTexCoord2f(1,1);
                glVertex3f(-size/2,-size/2,-size/2);
                glTexCoord2f(0,1);
                glVertex3f(-size/2,-size/2,size/2);
        glEnd();
        glBindTexture(GL_TEXTURE_2D,skybox[SKY_FRONT]);
        glBegin(GL_QUADS);     
                //front face
                glTexCoord2f(1,0);
                glVertex3f(size/2,size/2,-size/2);
                glTexCoord2f(0,0);
                glVertex3f(-size/2,size/2,-size/2);
                glTexCoord2f(0,1);
                glVertex3f(-size/2,-size/2,-size/2);
                glTexCoord2f(1,1);
                glVertex3f(size/2,-size/2,-size/2);
        glEnd();
        glBindTexture(GL_TEXTURE_2D,skybox[SKY_RIGHT]);
        glBegin(GL_QUADS);     
                //right face
                glTexCoord2f(0,0);
                glVertex3f(size/2,size/2,-size/2);
                glTexCoord2f(1,0);
                glVertex3f(size/2,size/2,size/2);
                glTexCoord2f(1,1);
                glVertex3f(size/2,-size/2,size/2);
                glTexCoord2f(0,1);
                glVertex3f(size/2,-size/2,-size/2);
        glEnd();
        glBindTexture(GL_TEXTURE_2D,skybox[SKY_TOP]);          
        glBegin(GL_QUADS);                      //top face
                glTexCoord2f(1,0);
                glVertex3f(size/2,size/2,size/2);
                glTexCoord2f(0,0);
                glVertex3f(-size/2,size/2,size/2);
                glTexCoord2f(0,1);
                glVertex3f(-size/2,size/2,-size/2);
                glTexCoord2f(1,1);
                glVertex3f(size/2,size/2,-size/2);
        glEnd();
        glBindTexture(GL_TEXTURE_2D,skybox[SKY_BOTTOM]);               
        glBegin(GL_QUADS);     
                //bottom face
                glTexCoord2f(1,1);
                glVertex3f(size/2,-size/2,size/2);
                glTexCoord2f(0,1);
                glVertex3f(-size/2,-size/2,size/2);
                glTexCoord2f(0,0);
                glVertex3f(-size/2,-size/2,-size/2);
                glTexCoord2f(1,0);
                glVertex3f(size/2,-size/2,-size/2);
        glEnd();
        glEnable(GL_LIGHTING);  //turn everything back, which we turned on, and turn everything off, which we have turned on.
        glEnable(GL_DEPTH_TEST);
        if(!b1)
                glDisable(GL_TEXTURE_2D);
}
 
 
 
 
 
 
void lockCamera()
{
        if(camPitch>90)
                camPitch=90;
        if(camPitch<-90)
                camPitch=-90;
        if(camYaw<0.0)
                camYaw+=360.0;
        if(camYaw>360.0)
                camYaw-=360;
}
 
void moveCamera(float dist,float dir)
{
        float rad=(camYaw+dir)*M_PI/180.0;
        camX-=sin(rad)*dist;
        camZ-=cos(rad)*dist;
}
 
void moveCameraUp(float dist,float dir)
{
        float rad=(camPitch+dir)*M_PI/180.0;
        camY+=sin(rad)*dist;   
}
 
void Control(float movevel,float mousevel,bool mi)
{
        if(mi)
        {
                int MidX=320;
                int MidY=240;
                SDL_ShowCursor(SDL_DISABLE);
                int tmpx,tmpy;
                SDL_GetMouseState(&tmpx,&tmpy);
                camYaw+=mousevel*(MidX-tmpx);
                camPitch+=mousevel*(MidY-tmpy);
                lockCamera();
                SDL_WarpMouse(MidX,MidY);
                Uint8* state=SDL_GetKeyState(NULL);
                if(state[SDLK_w])
                {
                        if(camPitch!=90 && camPitch!=-90)
                                moveCamera(movevel,0.0);
                        moveCameraUp(movevel,0.0);
                }else if(state[SDLK_s])
                {
                        if(camPitch!=90 && camPitch!=-90)
                                moveCamera(movevel,180.0);
                        moveCameraUp(movevel,180.0);
                }              
                if(state[SDLK_a])
                        moveCamera(movevel,90.0);
                else if(state[SDLK_d])
                        moveCamera(movevel,270);       
        }
        glRotatef(-camPitch,1.0,0.0,0.0);
        glRotatef(-camYaw,0.0,1.0,0.0);
}
 
void UpdateCamera()
{
        glTranslatef(-camX,-camY,-camZ);
}
 
void drawCube(float size)
{
        float difamb[]={1.0,0.5,0.3,1.0};
        glBegin(GL_QUADS);
                //front face
                glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,difamb);
                glNormal3f(0.0,0.0,1.0);
                glVertex3f(size/2,size/2,size/2);
                glVertex3f(-size/2,size/2,size/2);
                glVertex3f(-size/2,-size/2,size/2);
                glVertex3f(size/2,-size/2,size/2);
 
                //left face
                glNormal3f(-1.0,0.0,0.0);
                glVertex3f(-size/2,size/2,size/2);
                glVertex3f(-size/2,size/2,-size/2);
                glVertex3f(-size/2,-size/2,-size/2);
                glVertex3f(-size/2,-size/2,size/2);
 
                //back face
                glNormal3f(0.0,0.0,-1.0);
                glVertex3f(size/2,size/2,-size/2);
                glVertex3f(-size/2,size/2,-size/2);
                glVertex3f(-size/2,-size/2,-size/2);
                glVertex3f(size/2,-size/2,-size/2);
 
                //right face
                glNormal3f(1.0,0.0,0.0);
                glVertex3f(size/2,size/2,-size/2);
                glVertex3f(size/2,size/2,size/2);
                glVertex3f(size/2,-size/2,size/2);
                glVertex3f(size/2,-size/2,-size/2);
 
                //top face
                glNormal3f(0.0,1.0,0.0);
                glVertex3f(size/2,size/2,size/2);
                glVertex3f(-size/2,size/2,size/2);
                glVertex3f(-size/2,size/2,-size/2);
                glVertex3f(size/2,size/2,-size/2);
 
                //bottom face
                glNormal3f(0.0,-1.0,0.0);
                glVertex3f(size/2,-size/2,size/2);
                glVertex3f(-size/2,-size/2,size/2);
                glVertex3f(-size/2,-size/2,-size/2);
                glVertex3f(size/2,-size/2,-size/2);
        glEnd();
}
 
 
 
 
 
unsigned int loadTexture(const char* filename)  //load the filename named texture
{
        unsigned int num;       //the id for the texture
        glGenTextures(1,&num);  //we generate a unique one
        SDL_Surface* img=SDL_LoadBMP(filename); //load the bmp image
        glBindTexture(GL_TEXTURE_2D,num);       //and use the texture, we have just generated
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); //if the texture is smaller, than the image, we get the avarege of the pixels next to it
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); //same if the image bigger
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);      //we repeat the pixels in the edge of the texture, it will hide that 1px wide line at the edge of the cube, which you have seen in the video
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);      //we do it for vertically and horizontally (previous line)
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,img->w,img->h,0,GL_RGB,GL_UNSIGNED_SHORT_5_6_5,img->pixels);        //we make the actual texture
        SDL_FreeSurface(img);   //we delete the image, we don't need it anymore
        return num;     //and we return the id
}




float angle=0.0;
 
//int cube;
//objloader obj;
bool mousein=false;
void init()
{
        glClearColor(0.5,0.5,0.5,1.0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45,640.0/480.0,1.0,500.0);
        glMatrixMode(GL_MODELVIEW);
        glEnable(GL_DEPTH_TEST);
        //cube=obj.load("test10.obj");
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        float col[]={1.0,1.0,1.0,1.0};
        glLightfv(GL_LIGHT0,GL_DIFFUSE,col);
        initskybox();
}
 
void display()
{
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        Control(0.2,0.2,mousein);       //calculate the position, and rotate the camera
        drawSkybox(50.0); //Draw the skybox here, so we apply the rotation, but we do not apply the translation to it.
        UpdateCamera(); //move the camera to the new location
        float pos[]={-1.0,1.0,-2.0,1.0};
        glLightfv(GL_LIGHT0,GL_POSITION,pos);
        //glCallList(cube);
}
 
 
int main(int argc,char** argv)
{
        SDL_Init(SDL_INIT_EVERYTHING);
        SDL_Surface* screen=SDL_SetVideoMode(640,480,32,SDL_SWSURFACE|SDL_OPENGL);
        bool running=true;
        Uint32 start;
        SDL_Event event;
        init();
        while(running)
        {
                start=SDL_GetTicks();
                while(SDL_PollEvent(&event))
                {
                        switch(event.type)
                        {
                                case SDL_QUIT:
                                        running=false;
                                        break;
                                case SDL_MOUSEBUTTONDOWN:
                                        mousein=true;
                                        SDL_ShowCursor(SDL_DISABLE);
                                        break;
                                case SDL_KEYDOWN:
                                        if(event.key.keysym.sym==SDLK_p)
                                        {
                                                mousein=false;
                                                SDL_ShowCursor(SDL_ENABLE);
                                                break;
                                        }
                                        if(event.key.keysym.sym==SDLK_ESCAPE)
                                        {
                                                running=false;
                                                break;
                                        }
                        }
                }
                display();
                SDL_GL_SwapBuffers();
                angle+=0.5;
                if(angle>360)
                        angle-=360;
                if(1000/30>(SDL_GetTicks()-start))
                        SDL_Delay(1000/30-(SDL_GetTicks()-start));
        }
        SDL_Quit();
        killskybox();
        return 0;      
}
