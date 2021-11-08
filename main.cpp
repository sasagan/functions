#include <iostream>
#include <cmath>
#include "Windows.h"
#include <gl/glut.h>

#pragma comment (lib, "opengl32.lib")

std::string s;
std::string* ps;

void coordinatePlane();

void WindowOpen(int w, int h)
{
	
	if (h == 0) h = 0;
	if (w == 0) w = 0;
	float ratio = 1.0 * w / h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, w, h);
	gluPerspective(45, ratio, 0, 1);
	glMatrixMode(GL_MODELVIEW);
}

void point(double x)
{
	float y = 0;
	y = cos(pow(x, 2) + abs(x) - 7/x);

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
	glVertex2f(4, 0);
	glVertex2f(-4, 0);//x-axis

	glVertex2f(4, 0);
	glVertex2f(4 - 0.5, 0.2);
	glVertex2f(4, 0);
	glVertex2f(4 - 0.5, -0.2);
	
	glVertex2f(0, 4);
	glVertex2f(0, -4);//y-axis

	glVertex2f(0, 4);
	glVertex2f(0.2, 4 - 0.5);
	glVertex2f(0, 4);
	glVertex2f(-0.2, 4 - 0.5);
	

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

	glutDisplayFunc(quad);
	glutReshapeFunc(WindowOpen);
	glutMainLoop();
	
	return 0;
}