#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include <math.h>
#include <iostream>
using namespace std;

void myInit()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void reflection(int x, int y, int xc, int yc)
{
    glBegin(GL_POINTS);
    glVertex2i(-x + xc, y + yc);
    glVertex2i(x + xc, y + yc);
    glVertex2i(y + xc, x + yc);
    glVertex2i(y + xc, -x + yc);
    glVertex2i(x + xc, -y + yc);
    glVertex2i(-x + xc, -y + yc);
    glVertex2i(-y + xc, -x + yc);
    glVertex2i(-y + xc, x + yc);
    glEnd();
}

void circle()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(1.0);
    int r = 100, xc = 320, yc = 240;
    int p = 3-2*r;
    int x = 0;
    int y = r;
    reflection(x, y, xc, yc);
    while (x <= y)
    {
        x++;
        if (p < 0)
        {
            p = p + 4 * x + 6;
        }
        else
        {
            y--;
            p = p + 4 * (x - y) + 10;
        }
        reflection(x, y, xc, yc);
    }

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(" Line Drawing using Inbuit Line Function");
    myInit();

    glutDisplayFunc(circle);
    glutMainLoop();
    return 0;
}
