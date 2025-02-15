#pragma once

#include "event.h"

namespace Core {
	class KeyPressedEvent : public Event {
	private:
		int key;

	public:
		KeyPressedEvent(int key) : 
			Event("Key_pressed_event", Event::EventType::KEY_PRESSED_EVENT),
			key(key) {}

	public:
		std::string format() const override {
			std::string formatted = name + ": " + (char)key;
			return formatted;
		}

	};// class KeyPressedEvent
	//------------------------------------------------------------------------------------------

	class KeyReleasedEvent : public Event {
	private:
		int key;

	public:
		KeyReleasedEvent(int key) :
			Event("Key_released_event", Event::EventType::KEY_RELEASED_EVENT),
			key(key) {}

	public:
		std::string format() const override {
			std::string formatted = name + ": " + (char)key;
			return formatted;
		}

	};// class KeyReleasedEvent

} // namespace Core