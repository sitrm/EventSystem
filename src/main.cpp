#include <iostream>

#include "../include/GLFW/glfw3.h"
#include "../include/window.h"


int main() {

	Core::Window& window = Core::Window::getInstanse();  // reference!!!
	
	while (!glfwWindowShouldClose(window.getGLFWindow())) {
		glfwPollEvents(); 
		glfwSwapBuffers(window.getGLFWindow());
	}
	

	return 0;
}