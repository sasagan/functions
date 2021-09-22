#include <iostream>
#include <math.h>
#include <string.h>

#include <GLFW/glfw3.h>
#include <GL/GL.h>
#include <gl/glut.h>

#pragma comment (lib, "opengl32.lib")


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
	gluPerspective(45, ratio, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
}

void point(double x)
{
	float y = 0;
	y = 5 * x;
	
	//
	glBegin(GL_POINTS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(x, y);
	glEnd();
}

void coordinatePlane()
{
	glLineWidth(1);
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 1.0);
	glVertex2f(-400, 0);
	glVertex2f(400, 0);
	glEnd();
}

/*void pointCenter()
{
	glPointSize(4);
	glBegin(GL_POINT);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0, 0, 0);
	glEnd();
	
}*/

void quad(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	gluLookAt(0.0f, 0.0f, 10.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);

	//pointCenter();

	//coordinatePlane;

	for (double i = -6.0; i < 6.0; i += 0.0001)
	{
		coordinatePlane;
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