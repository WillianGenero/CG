/**
 * This demo shows how to periodically call an update() function to create
 * animations over time. In this case, the animation is to rotate a red square.
 *
 * Author: Fernando Bevilacqua <fernando.bevilacqua@uffs.edu.br>
 * License: MIT
 */

#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>

// Constants to define the width/height of the window
const int WIDTH = 800;
const int HEIGHT = 800;

// Define how many frames per seconds we want our
// applications to run.
const unsigned int FRAMES_PER_SECOND = 45;
const unsigned int UPDATE_INTERVAL_MS = 1000 / FRAMES_PER_SECOND;

// Control the angle to rotate the red square
float angle = 0;
float tam = 0.5f;

float x = .01, y = .01, z = .01;
int sentidoX = 0, sentidoY = 0, sentidoZ = 0;

void WireCube(){
	glBegin(GL_LINES);
	// Frente
		glVertex3f(-tam, -tam, tam);
		glVertex3f(-tam, tam, tam);
		glVertex3f(-tam, tam, tam);
		glVertex3f(tam, tam, tam);
		glVertex3f(tam, tam, tam);
		glVertex3f(tam, -tam, tam);
		glVertex3f(tam, -tam, tam);
		glVertex3f(-tam, -tam, tam);

	// Costa
		glVertex3f(-tam, -tam, -tam);
		glVertex3f(-tam, tam, -tam);
		glVertex3f(-tam, tam, -tam);
		glVertex3f(tam, tam, -tam);
		glVertex3f(tam, tam, -tam);
		glVertex3f(tam, -tam, -tam);
		glVertex3f(tam, -tam, -tam);
		glVertex3f(-tam, -tam, -tam);
		
	// Lado Esq.
		glVertex3f(-tam, -tam, tam);
		glVertex3f(-tam, tam, tam);
		glVertex3f(-tam, tam, tam);
		glVertex3f(-tam, tam, -tam);
		glVertex3f(-tam, tam, -tam);
		glVertex3f(-tam, -tam, -tam);
		glVertex3f(-tam, -tam, -tam);
		glVertex3f(-tam, -tam, tam);

	// Lado Dir.
		glVertex3f(tam, -tam, tam);
		glVertex3f(tam, tam, tam);
		glVertex3f(tam, tam, tam);
		glVertex3f(tam, tam, -tam);
		glVertex3f(tam, tam, -tam);
		glVertex3f(tam, -tam, -tam);
		glVertex3f(tam, -tam, -tam);
		glVertex3f(tam, -tam, tam);
	glEnd();
}

void renderCoordinateAxis()
{
	// X axis - green color
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
		// Left side, negative X
		glVertex2f(-10.0, 0.0);
		glVertex2f(0.0, 0.0);

		// Right side, positive X
		glVertex2f(0.0, 0.0);
		glVertex2f(10.0, 0.0);
	glEnd();

	// Y axis - blue color
	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
		// Top side, positive Y
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, 10.0);

		// Bottom side, negative Y
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, -10.0);
	glEnd();
}

void display()
{
	// Clear the screen painting it with the white color
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	// Inform we want to make changes to the modelview matrix, starting
	// with no transformation at all.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Move the camera away from the origin along the Z axis by 10 pixels.
	glTranslatef(0, 0, -10.0f);

	// Render the X and Y axis to guide ourselves.
	renderCoordinateAxis();

	// Rotate the red square by "angle" degrees.
	// glRotatef(angle, 0.0f, 0.0f, 1.0f);
	// glRotatef(angle, 0.0f, 1.0f, 0.0f);
	// Render a red square
	
	glTranslated(x, y, z);

	//        R  G  B
	glColor3f(0, 0.3, 0.8);
	//        x1    y1    x2     y2

	WireCube();

	// Start the rendering on a new frame
	glutSwapBuffers();
}

void update(int value)
{
	// Update the angle of rotation
	angle += 3;

	x += sentidoX * -1;
	y += sentidoY * -1;
	z += sentidoZ * -1;

	// Request a new frame rendering
	glutPostRedisplay();

	// Re-schedule the update() function to be called after a few
	// milliseconds again.
	glutTimerFunc(UPDATE_INTERVAL_MS, update, 0);
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
	else if (key == 65)
		sentidoZ = 1;
	else if (key == 83)
		sentidoZ = 0;
	else if (key == 24)
		sentidoY = 1;
	else if (key == 25)
		sentidoY = 0;
	else if (key == 26)
		sentidoX = 1;
	else if (key == 27)
		sentidoX = 0;
}

void mouse(int button, int state, int x, int y)
{
	std::cout << "Mouse pressed: button=" << button << ", state=" << state << ", x=" << x << " y=" << y << std::endl;
}

void initView()
{
	// We want a window to the world that is a rectangle starting at (0,0)
	// and ending at (WIDTH, HEIGHT).
	glViewport(0, 0, (GLsizei)WIDTH, (GLsizei)HEIGHT);
	
	// Adjust the global projection (camera)
	glMatrixMode(GL_PROJECTION);
	
	// Reset any existing projection settings and adjust the field-of-view (FOV)
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 200.0);
	
	// From now on, every transformation is to be applied on each object, e.g. modelview.
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Transformation - Simple");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);

	initView();

	// Schedule the update() function to be called after a few
	// milliseconds (calculated as 1000 milliseconds divided by FPS).
	glutTimerFunc(UPDATE_INTERVAL_MS, update, 0);

	glutMainLoop();
	return 0;
}