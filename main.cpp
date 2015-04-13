
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
//#include <GL/glut.h>
#endif
#include <stdlib.h>
#include<time.h>
#include"fin.h"
#include"projectile.h"
#include"tanks.h"

tank t_left(4), t_right(17);

static void display()
{

    terrain_polygon(xterrain,yterrain);
    t_left.tankDisplay();
    t_right.tankDisplay();
     glColor3d(1,1,1);
            output4(-.88, 0.7, scoreA);
    glColor3d(1,1,1);
            output5(0.88, 0.7, scoreB);
    projectileFunc();

}

void mouse(int button, int state, int x, int y)
{
    switch(button)
    {

    case GLUT_LEFT_BUTTON:
        if(fire2 && state==GLUT_DOWN  && x>607 && x<743 && y>641 && y<675)
        {
            x_proj=0;
            fire1=true;
            mouse_x[0]=(player)? xterrain[t_left.position]:xterrain[t_right.position];
            mouse_y[0]=(player)? yterrain[t_left.position]-0.47:yterrain[t_right.position]-0.47;
            player=!player;
            glutPostRedisplay();
        }
    default:
        break;
    }
}

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27 :
    case 'q':
        exit(0);
        break;
    }
}


static void idle(void)
{
    glutPostRedisplay();
}
int main(int argc, char *argv[])
{

    //getValues();
    assign_coord(yterrain);
    // std::cin>>mouse_x[0]>>mouse_y[0];
    glutInit(&argc, argv);
    for (i = 1; i < argc; i++)
    {
        if (!strcmp(argv[i], "-mono"))
        {
            font = GLUT_BITMAP_9_BY_15;
        }
    }
    glutInitWindowSize(1350,675);
    glutInitWindowPosition(0,0);
    glutCreateWindow("POCKET TANKS");
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    //glutReshapeFunc(resize);
    glClearColor(0,0,0,1);
        //glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    //glutKeyboardFunc(key);
    glutIdleFunc(idle);
    glutMainLoop();
    getch();
}
