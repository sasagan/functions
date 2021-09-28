#include <iostream>
#include <math.h>
#include <string.h>
#include "Windows.h"

#include <GLFW/glfw3.h>
#include <GL/GL.h>
#include <gl/glut.h>

#pragma comment (lib, "opengl32.lib")

int widthWindow;
int heightWindow;
int* pwidthWindow = &widthWindow;
int* pheightWindow = &heightWindow;

//float pointx[2] = { widthWindow / 2, 0};
//float pointx[2] = { heightWindow / 2, 0};

void coordinatePlane();

void WindowOpen(int a, int h)
{
	if (h == 0)
	{
		h = 1;
	}
	float ratio = 1.0 * a / h;
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, a, h);
	gluPerspective(45, ratio, 0, 1);
	glMatrixMode(GL_MODELVIEW);
}

void point(double x)
{
	float y = 0;
	y = pow(x, x);

	glBegin(GL_POINTS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(x, y);
	glEnd();
}

void coordinatePlane()
{
	glLineWidth(1);
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(*pwidthWindow, 0);
	glVertex2f(-*pwidthWindow, 0);//x-axis
	
	glVertex2f(0, *pheightWindow);
	glVertex2f(0, -*pheightWindow);//y-axis

	glEnd();
}

void quad(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	gluLookAt(0.0f, 0.0f, 10.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);


	for (double i = -6.0; i < 6.0; i += 0.0001)
	{
		coordinatePlane();
		point(i);
	}



	glutPostRedisplay();
	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Window");
	widthWindow = glutGet(GLUT_SCREEN_WIDTH);
	heightWindow = glutGet(GLUT_SCREEN_HEIGHT);

	glutDisplayFunc(quad);
	glutReshapeFunc(WindowOpen); 
	glutMainLoop();

	return 0;
}