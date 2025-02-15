#pragma once

#include "GLFW/glfw3.h"
#include "event.h"
#include <functional>
#include <string>

namespace Core {

	class Window final {
	private:
		std::string name;
		int width, height;
		GLFWwindow* window = nullptr;     // �++11
		std::function<void(Event&)> fnCallback;
	public:
		// copy constructor
		// singleton)!!!
		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;

	private:
		Window(const std::string& name, int width, int height);

	private:
		~Window();            // = default

	public:
	
		static Window& getInstanse() {
			static Window instanse("window", 1280, 720); return instanse;
		}

	public:
		void init(const std::string&  name, int width, int height);
		__forceinline GLFWwindow* getGLFWindow() const { return window; }   //  inline
		void setfnCallback(const std::function<void(Event&)>& fn) { fnCallback = fn; }  // init fnCallBack

	public:
		//for callback
		static void mouseMovedCallback(GLFWwindow* window, double x, double y);
		static void mouseScrollCallback(GLFWwindow* window, double x, double y);
		static void moudeButtonCallback(GLFWwindow* window, int button, int action, int mods);
		static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void windowResizeCallback(GLFWwindow* window, int width, int height);
		static void windowCloseCallback(GLFWwindow* window);

	}; // class Window

} // namespace Core