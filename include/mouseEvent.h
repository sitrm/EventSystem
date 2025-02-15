#pragma once
#include "event.h"

namespace Core {

	class MouseMovedEvent : public Event {

	private:
		int x, y;
	public:
		MouseMovedEvent(int x, int y) :
			Event("Mouse_moved_event", Event::EventType::MOUSE_MOVED_EVENT),
			x(x),
			y(y) {}
	public:
		std::string format() const override {
			std::string formatted = name + ": " + std::to_string(x) + ", " + std::to_string(y);
			return formatted;
		}

	}; // class MouseMovedEvent

	//-------------------------------------------------------------------------------------------------------
	class MouseScrolledEvent : public Event {
	private:
		int offset;
	public:
		MouseScrolledEvent(int offset) :
			Event("Mouse_scrolled_event", Event::EventType::MOUSE_SCROLLED_EVENT),
			offset(offset) {}

	public:
		std::string format() const override {
			std::string formatted = "";

			return (offset < 0) ? formatted = name + ": " + "to botton" : formatted = name + ": " + "to up";
		}
	}; // class MouseScrolledEvent

	//-------------------------------------------------------------------------------------------------------

	class MouseButtonPressed : public Event {
	private:
		int button;
	public:
		MouseButtonPressed(int button) :
			Event("Mouse_button_pressed", Event::EventType::MOUSE_BUTTON_PRESSED_EVENT),
			button(button) {}
	public:
		std::string format() const override {
			std::string formatted = name + ": " + std::to_string(button);
			return formatted;
		}
	}; //class MouseButtonPressed
	//-------------------------------------------------------------------------------------------------------
	class MouseButtonReleased : public Event {
	private:
		int button;
	public:
		MouseButtonReleased(int button) :
			Event("Mouse_button_Released", Event::EventType::MOUSE_BUTTON_RELEASED_EVENT),
			button(button) {}
	public:
		std::string format() const override {
			std::string formatted = name + ": " + std::to_string(button);
			return formatted;
		}
	}; //class MouseButtonReleased

} // namespace Core