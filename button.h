#include <iostream>
#include <cmath>
#include "Windows.h"
#include <gl/glut.h>

class Button
{
public:
	float position[2] = { 0, 0 };
	float size[2] = {0, 0};
	float color[3] = { 0, 0, 0 };
	std::string nameButton;

	void render()
	{
		glBegin(GL_QUADS);
		glColor3f(color[0], color[1], color[2]);
		glVertex2f(position[0] - size[0] / 2, position[1] - size[1] / 2);
		glVertex2f(position[0] - size[0] / 2, position[1] + size[1] / 2);
		glVertex2f(position[0] + size[0] / 2, position[1] + size[1] / 2);
		glVertex2f(position[0] + size[0] / 2, position[1] - size[1] / 2);
		glEnd();
	}
};
