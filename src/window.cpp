#include "../include/window.h"
#include "../include/mouseEvent.h"
#include "../include/keyboardEvent.h"
#include "../include/windowEvent.h"

#include <iostream>


namespace Core {

	Window::Window(const std::string& name, int width, int height) {
		init(name, width, height);
		setfnCallback([this](Event& e) {                                // window = window
			// Dispatchers 
 			if (e.getType() == Event::EventType::WINDOW_CLOSED_EVENT) {
				glfwSetWindowShouldClose(window, GL_TRUE);
			}
			std::cout << e.format() << std::endl;
			});
	}
	//-------------------------------------------------------------------------------------------------
	void Window::init(const std::string& name, int width, int height) {
		this->name = name;
		this->width = width;
		this->height = height;

		
		if (!glfwInit()) {
			__debugbreak(); 
		}

		window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);

		if (!window) {
			__debugbreak(); 
		}

		glfwMakeContextCurrent(window);

		glfwSetWindowUserPointer(window, this);

		glfwSetCursorPosCallback(window, mouseMovedCallback);

		glfwSetScrollCallback(window, mouseScrollCallback);

		glfwSetMouseButtonCallback(window, moudeButtonCallback);

		glfwSetKeyCallback(window, keyCallback);

		glfwSetWindowSizeCallback(window, windowResizeCallback);

		glfwSetWindowCloseCallback(window, windowCloseCallback);
	}
	//-------------------------------------------------------------------------------------------------
	void Window::mouseMovedCallback(GLFWwindow* window, double x, double y) {
		
		auto& handle = *(Window*)glfwGetWindowUserPointer(window);  
		MouseMovedEvent e(x, y);
		handle.fnCallback(e);
	}
	//-------------------------------------------------------------------------------------------------
	void Window::mouseScrollCallback(GLFWwindow* window, double x, double y) {
		auto& handle = *(Window*)glfwGetWindowUserPointer(window);
		MouseScrolledEvent e(y);
		handle.fnCallback(e);

	}
	//-------------------------------------------------------------------------------------------------
	void Window::moudeButtonCallback(GLFWwindow* window, int button, int action, int mods) {
		auto& handle = *(Window*)glfwGetWindowUserPointer(window);
		if (action == GLFW_PRESS) {
			MouseButtonPressed e(button);
			handle.fnCallback(e);
		}
		else {   // action == GLFW_Released
			MouseButtonReleased e(button);
			handle.fnCallback(e);
		}
	}
	//-------------------------------------------------------------------------------------------------
	void Window::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
		auto& handle = *(Window*)glfwGetWindowUserPointer(window);
		if (action == GLFW_PRESS) {
			KeyPressedEvent e(key);
			handle.fnCallback(e);
		}
		else if (action == GLFW_RELEASE){
			KeyReleasedEvent e(key);
			handle.fnCallback(e); 
		}
	}
	//-------------------------------------------------------------------------------------------------
	void Window::windowResizeCallback(GLFWwindow* window, int width, int height) {
		auto& handle = *(Window*)glfwGetWindowUserPointer(window);

		WindowResizedEvent e(width, height);
		handle.height = height;
		handle.width = width;
		handle.fnCallback(e);
	}
	//-------------------------------------------------------------------------------------------------
	void Window::windowCloseCallback(GLFWwindow* window) {
		auto& handle = *(Window*)glfwGetWindowUserPointer(window);
		WindowClosedEvent e;
		handle.fnCallback(e);

	}
	//-------------------------------------------------------------------------------------------------
	Window::~Window() {
		glfwWindowShouldClose(window);
	}
	//-------------------------------------------------------------------------------------------------


} // namespace Core