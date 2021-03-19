#include <Window.hpp>
#include <SDL.h>
#include <OpenGL.hpp>
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