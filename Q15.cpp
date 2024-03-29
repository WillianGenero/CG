/**
 * Basic usege of OpenGL and GLFW. 
 */

#include <iostream>
#include <GLFW/glfw3.h>

#define WIDTH 500
#define HEIGHT 500

float x = 0.01;
int flag = 1;
int main() {
	GLFWwindow* window;
	int width, height;

	if (!glfwInit()) {
		std::cout << "Problem to initialize GLFW" << std::endl;
		exit(1);
	}
	
	window = glfwCreateWindow(WIDTH, HEIGHT, "Atividade 5", NULL, NULL);

	if (!window) {
		std::cout << "Problem to create GLFW window" << std::endl;
		glfwTerminate();
		exit(1);
	}

	glfwMakeContextCurrent(window);

	while(glfwWindowShouldClose(window) == 0 && glfwGetKey(window, GLFW_KEY_ESCAPE) == 0) {
		glClearColor(1.f, 1.f, 1.f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0, 0, width, height);
		
		if(x>1.25)
			flag = 0;
		else if (x<-0.3)
			flag = 1;
		x += flag ? 0.01 : -0.01;
		glBegin(GL_LINES);
			glColor3f(0.f, 0.f, 1.f);
			glVertex3f(-0.7f + x, 0.2f, 0.f);
			glVertex3f(-0.7f + x, -0.3f, 0.f);
			glVertex3f(-0.7f + x, 0.2f, 0.f);
			glVertex3f(-0.2f + x, 0.2f, 0.f);
			glVertex3f(-0.2f + x, 0.2f, 0.f);
			glVertex3f(-0.2f + x, -0.3f, 0.f);
			glVertex3f(-0.2f + x, -0.3f, 0.f);
			glVertex3f(-0.7f + x, -0.3f, 0.f);

			glColor3f(1.f, 0.f, 0.f);
			glVertex3f(0.2f - x, 0.2f, 0.f);
			glVertex3f(0.2f - x, -0.3f, 0.f);
			glVertex3f(0.2f - x, 0.2f, 0.f);
			glVertex3f(0.7f - x, 0.2f, 0.f);
			glVertex3f(0.7f - x, 0.2f, 0.f);
			glVertex3f(0.7f - x, -0.3f, 0.f);
			glVertex3f(0.7f - x, -0.3f, 0.f);
			glVertex3f(0.2f - x, -0.3f, 0.f);

		glEnd();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

    glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
