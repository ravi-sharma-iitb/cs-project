#ifndef PROJECTILE_H_INCLUDED
#define PROJECTILE_H_INCLUDED
#include"fin.h"
#include<math.h>
#include"tanks.h"
#include <ctype.h>

float angle,power;
tank t_left1(4), t_right1(17);
float rangle;
//These variables used/called in  projectileFunc, main
//angle check 90
float x_proj=0;
int k=0,k2=0; //for projectile conditions-Ravi.
bool fire1=false;//turns true on mouse click
bool fire2=true;// turns true on projectile completion
bool isFirst=1;
float mouse_x[1]= {0}, mouse_y[1]= {0};//Start point of projectile
float end_x, end_y;

bool player=1; //true for player on left

float score(float xprojfin,float yprojfin)
{
    float dist;
    if (player==0)
    {
        dist=pow((((xterrain[t_right1.position]-xprojfin)*(xterrain[t_right1.position]-xprojfin))+((yterrain[t_right1.position]-0.47-yprojfin)*(yterrain[t_right1.position]-0.47-yprojfin))),0.5);
        std::cout<<xterrain[t_right1.position]<<"   "<<yterrain[t_right1.position]<<std::endl;
    }
    else
    {
        dist=pow((((xterrain[t_left1.position]-xprojfin)*(xterrain[t_left1.position]-xprojfin))+((yterrain[t_left1.position]-0.47-yprojfin)*(yterrain[t_left1.position]-0.47-yprojfin))),0.5);
        std::cout<<xterrain[t_left1.position]<<"   "<<yterrain[t_left1.position]<<std::endl;
    }
    std::cout<<dist<<std::endl;
    if ((0.3-dist)>0)
        return ((0.3-dist)/0.3)*100;

    else
        return 0;
}


void getValues()
{
    try
    {
        do
        {
            std::cout<<"enter the power:"<<std::endl;
            std::cin>>power;
            if(power<0|| power>100)
                std::cout<<"Please enter power between 0 and 100"<<std::endl;
        }
        while(power<0 || power>100);

        std::cout<<"enter the angle"<<std::endl;
        std::cin>>angle;
        power=power/50;
        rangle=1.0*angle/180*3.14;
    }
    catch(...)
    {
        std::cout<<"Please enter a valid power"<<std::endl;
    }
}


void projectileFunc()
{
    if(isFirst)
    {
        getValues();
        isFirst=0;
    }
    int lowx=10*((x_proj+mouse_x[0])+1);
    float t=x_proj+mouse_x[0];
    float ymin=yterrain[lowx]+(t-xterrain[lowx])*(yterrain[lowx+1]-yterrain[lowx])/0.1-0.5;

    // std::cout<<fire2<<"  a ";
    //std::cout<<fire<<std::endl; //equation
    if(fire1 && mouse_y[0]+2.0*((x_proj)*tan(rangle)-(x_proj)*(x_proj)/(power*power*cos(rangle)*cos(rangle)))>ymin) //equation
    {

        //std::cout<<(mouse_y[0]+2.0*((t)*tan(rangle)-(t)*(t)/(power*power*cos(rangle)*cos(rangle)))>ymin)<<" ";
        x_proj+=0.0015*cos(rangle);
        k++;
        k2++;
        glColor3d(0.5,0,0.50);
        //for(float i=0; i<=1; i+=0.1)
        glBegin(GL_POINTS);
        glVertex2f(t,mouse_y[0]+2.0*((x_proj)*tan(rangle)-(x_proj)*(x_proj)/(power*power*cos(rangle)*cos(rangle)))); //equation
        //glVertex2f(i+0.1,i+0.1-(i+0.1)*(i+0.1));
        glEnd();
        glutSwapBuffers();
        glFlush();
        glutPostRedisplay();

    }

    // std::cout<<(mouse_y[0]+2.0*((t)*tan(rangle)-(t)*(t)/(power*power*cos(rangle)*cos(rangle)))>ymin)<<" ";
    // std::cout<<k<<" ";

    if (k!=0)
    {

        if ( mouse_y[0]+2.0*((x_proj)*tan(rangle)-(x_proj)*(x_proj)/(power*power*cos(rangle)*cos(rangle)))>ymin)//equation
            fire2=false;
        else if( mouse_y[0]+2.0*((x_proj)*tan(rangle)-(x_proj)*(x_proj)/(power*power*cos(rangle)*cos(rangle)))>ymin==0)//equation
        {
            fire2=true;
            k=0;

        }
    }
    //bool fire3=!(mouse_y[0]+2.0*((t)*tan(rangle)-(t)*(t)/(power*power*cos(rangle)*cos(rangle)))>ymin);//end of projectile
    if(k2>0 &&k==0)
    {
        end_x=x_proj+mouse_x[0];
        end_y=ymin;
        k2=0;
        std::cout<<end_x<<" , "<<end_y<<std::endl;
        std::cout<<"score is "<<score(end_x,end_y)<<std::endl;
        glClearColor(0,0,0,1);
        glClear(GL_COLOR_BUFFER_BIT);
        glutPostRedisplay();
        getValues();

    }
    //std::cout<<end_x<<end_y;
}

#endif // PROJECTILE_H_INCLUDED
