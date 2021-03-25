#include <Window.hpp>
#include <SDL.h>
#include <OpenGL.hpp>
#include <Input_Task.hpp>
//#include <internal/initialize.hpp>


engine::Window::Window(const std::string& title, int width, int height, bool fullscreen)
{
    window = SDL_CreateWindow
    (
        title.c_str(),
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width,
        height,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
    );

    assert(window != nullptr);

    gl_context = SDL_GL_CreateContext(window);

    assert(gl_context != nullptr);

    glt::initialize_opengl_extensions();

    if (fullscreen)
    {
         set_fullscreen();
    }
}

engine::Window::~Window()
{
    SDL_GL_DeleteContext(gl_context);
    SDL_DestroyWindow(window);
}

void engine::Window::set_fullscreen()
{
    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
}

void engine::Window::set_windowed()
{
    SDL_SetWindowResizable(window, SDL_TRUE);
}

void engine::Window::set_position(int new_left_x, int new_top_y)
{
    SDL_SetWindowPosition(window, new_left_x, new_top_y);
}

void engine::Window::set_size(int new_width, int new_height)
{
    SDL_SetWindowSize(window, new_width, new_height);
}

void engine::Window::get_window_dimensions(int* width, int* height)
{
    SDL_GetWindowSize(window, width, height);
}

void engine::Window::clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void engine::Window::swap_buffers()
{
    SDL_GL_SwapWindow(window);
}

bool engine::Window::poll(Event & event)
{
    if (window)     // Aunque sería raro, puede llegar a ocurrir que no se haya conseguido crear la ventana...
    {
        // Se extrae un evento usando SDL y se convierte a un evento propio de
        // nuestro engine:

        SDL_Event sdl_event;

        if (SDL_PollEvent (&sdl_event) > 0)
        {
            switch (sdl_event.type)
            {
                case SDL_QUIT:
                {
                    event.type = Event::CLOSE;
                    break;
                }

                case SDL_KEYDOWN:
                {
                    event.type = Event::KEY_PRESSED;
                    //Input_Task::KeyUp  [sdl_event.key.keysym.scancode] = true;
                    event.data.keyboard.key_code = Input_Task::translate_sdl_to_key_code (sdl_event.key.keysym.scancode);
                    break;
                }

                case SDL_KEYUP:
                {
                    event.type = Event::KEY_RELEASED;
                    //Input_Task::KeyDown[sdl_event.key.keysym.scancode] = false;
                    event.data.keyboard.key_code = Input_Task::translate_sdl_to_key_code (sdl_event.key.keysym.scancode);
                    break;
                }
            }

            return true;
        }
    }

    return false;
}
