/**
 * Simple demonstration of transformations.
 */

#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>

float rotZ = 0, scale = 0, tran = 0, ang = 0, sent = 1, vel = 0;

void renderCoordinateAxis()
{
	// X axis - green color
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
		// Left side, negative X
		glVertex2f(-1.0, 0.0);
		glVertex2f(0.0, 0.0);

		// Right side, positive X
		glVertex2f(0.0, 0.0);
		glVertex2f(1.0, 0.0);
	glEnd();

	// Y axis - blue color
	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
		// Top side, positive Y
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, 1.0);

		// Bottom side, negative Y
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, -1.0);
	glEnd();
}

void display()
{
	// Clear the screen painting it all with the white color
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();

	// Inform OpenGL we want to make changes to the modelview matrix
	glMatrixMode(GL_MODELVIEW);

	// Render the X and Y axis to guide ourselves.
	renderCoordinateAxis();

	// Render a blue square
	glColor3f(0, 0, 1);
	glTranslatef(0, 0+tran, 0);
	glRotatef(0.f+ang, 0.f, 0.f, 0.f+rotZ);
	glScalef(1+scale, 1+scale, 1);
	glRectf(-0.1f+vel, 0.1f, 0.1f+vel, -0.1f);

	glutSwapBuffers();
	ang += 1;
	if (ang > 360)
		ang = 0;
	if (vel >= .7 || vel <= -.7)
			sent *= -1;
		vel += 0.01 * sent;
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
	else if (key == 48) //Zerar
		rotZ = tran = scale = 0;
	else if (key == 49) //ROT Z
		rotZ = ang = 1;
	else if (key == 50) //ROT Y
		scale = 1;
	else if (key == 51) //ROT Z
		tran = 0.2;

}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Transformation - Simple");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutKeyboardFunc(keyboard);

	glutMainLoop();
	return 0;
}