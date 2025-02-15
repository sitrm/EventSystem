#pragma once
#include <string>

namespace Core {

	class Event {
	public:
		enum class EventType : int8_t {
			MOUSE_MOVED_EVENT = 1,
			MOUSE_SCROLLED_EVENT,
			MOUSE_BUTTON_PRESSED_EVENT,
			MOUSE_BUTTON_RELEASED_EVENT,
			KEY_PRESSED_EVENT,
			KEY_RELEASED_EVENT,
			WINDOW_RESIZED_EVENT,
			WINDOW_CLOSED_EVENT
		};
	protected:
		EventType type;
		std::string name;
	protected:
		Event(const std::string& name, EventType type) :
			name(name),
			type(type) {}
	public:
		virtual ~Event() = default;
	public:
		inline std::string getName() const { return name; }
		inline EventType getType()   const { return type; }

		virtual std::string format() const = 0;       // clear virtual function 

	}; // class Event
} // namespace Core