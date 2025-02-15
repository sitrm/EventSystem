# EventSystem with GLFW

## Описание проекта

Этот проект представляет собой простую систему обработки событий, реализованную с использованием библиотеки GLFW. Проект включает в себя обработку различных типов событий, таких как события мыши, клавиатуры и окна. Основная цель проекта — демонстрация того, как можно организовать обработку событий в приложении, использующем GLFW для создания окон и управления вводом.

### Основные функции:
- **Обработка событий мыши**: перемещение, прокрутка, нажатие и отпускание кнопок мыши.
- **Обработка событий клавиатуры**: нажатие и отпускание клавиш.
- **Обработка событий окна**: изменение размера окна, закрытие окна.

## Зависимости

- **GLFW**: библиотека для создания окон и обработки ввода. Убедитесь, что библиотека GLFW установлена и доступна в вашей системе.

## Сборка проекта

Для сборки проекта требуется CMake версии 3.* или выше.

1. **Создайте директорию для сборки**:
   ```bash
   mkdir build
   cd buil
   cmake --build . --config debug (cmake --build . --config release)
   ```

## Кратко о библиотеке GLFW

**GLFW** — это библиотека для создания окон, контекстов OpenGL и обработки ввода. Она предоставляет простой API для управления окнами, обработки событий мыши и клавиатуры, а также для работы с контекстами OpenGL. GLFW широко используется в приложениях, требующих графического интерфейса и взаимодействия с пользователем.

### Основные особенности GLFW: 

- Поддержка множества платформ (Windows, macOS, Linux).

- Простота использования и интеграции.

- Поддержка OpenGL, OpenGL ES и Vulkan.

- Обработка ввода (мышь, клавиатура, джойстик).