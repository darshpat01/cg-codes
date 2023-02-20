#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include <math.h>
#include <iostream>
using namespace std;

void init()
{
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-100, 100, -100, 100);
}


void bresenham(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glBegin(GL_POINTS);
    int x1=0, y1=0, x2=50, y2=50;
    int dx, dy, p, x, y;
       dx=x2-x1;
       dy=y2-y1;
       x=x1;
       y=y1;
       p=2*dy-dx;
       while(x<x2)
       {
           if(p>=0)
           {
               glVertex2i(x, y);
               y=y+1;
               p=p+2*dy-2*dx;
           }
           else
           {
               glVertex2i(x, y);
               p=p+2*dy;
           }
x=x+1;
    
    glEnd();
    glFlush();
}
}

int main(int argc, char **argv)
{
   
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bresenham's Line Drawing Algorithm");
    init();
    glutDisplayFunc(bresenham);
    glutMainLoop();
    return 0;
}
