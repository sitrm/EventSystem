#pragma once

#include "event.h"

namespace Core {

	class WindowResizedEvent : public Event{
	private:
		int width, height;
	public:
		WindowResizedEvent(int width, int height) :
			Event("Window_resizedEvent", Event::EventType::WINDOW_RESIZED_EVENT),
			width(width),
			height(height)  {}

	public:
		std::string format() const override {
			std::string formatted = name + ": " + std::to_string(width) + ", " + std::to_string(height);
			return formatted;
		}
	}; // class WindowEvent

	class WindowClosedEvent : public Event {
	private:
		int width, height;
	public:
		WindowClosedEvent() :
			Event("Window_clossed_event", Event::EventType::WINDOW_CLOSED_EVENT) {}

	public:
		std::string format() const override {
			std::string formatted = name;
			return formatted;
		}
	}; // class WindowEvent
	
} // namespace Core