#ifndef FIN_H_INCLUDED
#define FIN_H_INCLUDED
#include<iostream>
#include<conio.h>
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include<time.h>


float xterrain[21]= {-1,-.9,-.8,-.7,-.6,-.5,-.4,-.3,-.2,-.1,0,.1,.2,.3,.4,.5,.6,.7,.8,.9,1};
float yterrain[21];
int i,i1;
bool InitTerrain=1;
void *font = GLUT_BITMAP_TIMES_ROMAN_24;
void *fonts[] =
{
    //GLUT_BITMAP_9_BY_15,
    //GLUT_BITMAP_TIMES_ROMAN_10,
    GLUT_BITMAP_TIMES_ROMAN_24
};

void
selectFont(int newfont)
{
    font = fonts[newfont];
    glutPostRedisplay();
}


//void *font = GLUT_BITMAP_TIMES_ROMAN_24;

void output(float x, float y, char *string)
{
    int len, i;

    glRasterPos2f(x, y);
    len = (int) strlen(string);
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(font, string[i]);
    }

void output2(float x, float y, char *string)
{
    int len, i;

    glRasterPos2f(x, y);
    len = (int) strlen(string);
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(font, string[i]);
    }
}

static void assign_coord(float y[])
{
    y[0]=1.0*(rand()%100)/100-0.5;
    int sval;
    time_t t;//t is a time type variable
    sval=time(&t);
    srand(sval);
    for (int i=1; i<21; i++)
    {
        y[i]=y[i-1]+2*(-0.5+(rand()%2))*float((rand()%10))/50;
        while(y[i]-.5>0.75)
        {
            y[i]-=0.1;
        }
        while(y[i]-.5<-0.75)
        {
            y[i]+=0.1;
        }
    }
}

static void terrain_polygon(float x[],float y[])
{/*
 glColor3d(0,0,1);
        glBegin(GL_POLYGON);
        glVertex2f(1,1);
        glVertex2f(1,-1);
        glVertex2f(-1,-1);
        glVertex2f(-1,1);
        glEnd();
        glutSwapBuffers();
            glFlush();*/


    for(int i=0; i<=19; i++)
    {
        if(InitTerrain)
        {
            glutSwapBuffers();
            glFlush();
        }
        glColor3d(0,.5,0);
        glBegin(GL_POLYGON);
        glVertex2f(x[i],y[i]-.5);
        glVertex2f(x[i],-1);
        glVertex2f(x[i+1],-1);
        glVertex2f(x[i+1],y[i+1]-0.5);
        glEnd();
        glColor3d(0,0.4,0);
        glBegin(GL_POLYGON);
        glVertex2f(x[i],y[i]-.5-0.1*(y[i]+1));
        glVertex2f(x[i],-1);
        glVertex2f(x[i+1],-1);
        glVertex2f(x[i+1],y[i+1]-0.5-0.1*(y[i+1]+1));
        glEnd();
        glColor3d(0,0.32,0);
        glBegin(GL_POLYGON);
        glVertex2f(x[i],y[i]-.5-0.2*(y[i]+1));
        glVertex2f(x[i],-1);
        glVertex2f(x[i+1],-1);
        glVertex2f(x[i+1],y[i+1]-0.5-0.2*(y[i+1]+1));
        glEnd();
        glColor3d(0,0.28,0);
        glBegin(GL_POLYGON);
        glVertex2f(x[i],y[i]-.5-0.3*(y[i]+1));
        glVertex2f(x[i],-1);
        glVertex2f(x[i+1],-1);
        glVertex2f(x[i+1],y[i+1]-0.5-0.3*(y[i+1]+1));
        glEnd();
    }
    if(InitTerrain)
    {
        glutSwapBuffers();
        glFlush();
    }
    glColor3d(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
    glVertex2f(-0.1,-.9);
    glVertex2f(-0.1,-1);
    glVertex2f(0.1,-1);
    glVertex2f(0.1,-.9);
    glEnd();
    glColor3d(1,0,0);
    output(-.045, -.97, "FIRE");
    output2(-.0.8, .8, "PLAYER 1");

    glutSwapBuffers();
    glFlush();
    if(InitTerrain)
    {
        InitTerrain=0;
    }

}


/*
static void resize(int width, int height)  //look for it
{
    const float ar = (float) width / (float) height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-ar, ar, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}*/



#endif // FIN_H_INCLUDED
