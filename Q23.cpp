/**
 * Basic usege of OpenGL and GLFW. 
 */

#include <iostream>
#include <GLFW/glfw3.h>

#define WIDTH 500
#define HEIGHT 500
float x = 0.1;
int sentido = 1;
int main() {
	GLFWwindow* window;
	int width, height;

	if (!glfwInit()) {
		std::cout << "Problem to initialize GLFW" << std::endl;
		exit(1);
	}
	
	window = glfwCreateWindow(WIDTH, HEIGHT, "Hello world, GLFW!", NULL, NULL);

	if (!window) {
		std::cout << "Problem to create GLFW window" << std::endl;
		glfwTerminate();
		exit(1);
	}

	glfwMakeContextCurrent(window);

	while(glfwWindowShouldClose(window) == 0 && glfwGetKey(window, GLFW_KEY_ESCAPE) == 0) {
		glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0, 0, width, height);
		if (x >= 0.7)
			sentido *= -1;
		else if (x <= -0.7)
			sentido *= -1;
		x += 0.01 * sentido;
		glBegin(GL_LINES);
			glColor3f(0.f, 0.3f, 0.7f);
			glVertex3f(-0.3f+x, -0.3f, 0.f);
			glVertex3f(-0.3f+x, 0.3f, 0.f);
			glVertex3f(-0.3f+x, 0.3f, 0.f);
			glVertex3f(0.3f+x, 0.3f, 0.f);
			glVertex3f(0.3f+x, 0.3f, 0.f);
			glVertex3f(0.3f+x, -0.3f, 0.f);
			glVertex3f(0.3f+x, -0.3f, 0.f);
			glVertex3f(-0.3f+x, -0.3f, 0.f);

			glColor3f(0.f, 0.7f, 0.3f);
			glVertex3f(-0.3f-x, -0.3f, 0.f);
			glVertex3f(-0.3f-x, 0.3f, 0.f);
			glVertex3f(-0.3f-x, 0.3f, 0.f);
			glVertex3f(0.3f-x, 0.3f, 0.f);
			glVertex3f(0.3f-x, 0.3f, 0.f);
			glVertex3f(0.3f-x, -0.3f, 0.f);
			glVertex3f(0.3f-x, -0.3f, 0.f);
			glVertex3f(-0.3f-x, -0.3f, 0.f);
		glEnd();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

    glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
