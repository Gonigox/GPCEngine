#include <Kernel.hpp>
#include <SDL.h>

#include <Input.hpp>
#include <iostream>

engine::Kernel::Kernel(Window & win,Scene & scene) : renderer(0, win, scene)
{
    exit   = false;
    paused = false;
    add_task(renderer);
}

void engine::Kernel::add_task(Task& task)
{
    tasks.insert(&task);
    task.set_kernel(this);
}

void engine::Kernel::execute()
{
    exit = false;

    ////////////// TESTS INPUT MANAGMENT //////////////////////

    SDL_Event sdl_event;


    bool KeyDown[SDL_NUM_SCANCODES];
    bool KeyUp  [SDL_NUM_SCANCODES];

    for (int i = 0; i < SDL_NUM_SCANCODES; ++i)
	{
		KeyDown[i] = false;
        KeyUp  [i] = false;
	}

    ////////////// TESTS INPUT MANAGMENT //////////////////////

    for (auto task : tasks)
    {
        task->initialize();
    }

    float time = 1.f / 60.f;

    while (!exit)
    {
        Timer timer;


        ////////////// TESTS INPUT MANAGMENT //////////////////////

        SDL_PollEvent(&sdl_event);

        if(sdl_event.type == SDL_QUIT)
        {
            exit = true;
        }

        /////// GetKeyDown //////////////////
        if(!KeyDown[SDL_SCANCODE_A] && Input::keystate[SDL_SCANCODE_A])
        {
            KeyDown[SDL_SCANCODE_A] = true;
            KeyUp  [SDL_SCANCODE_A] = true;
            std::cout << "Pulsaste a";
        }
        if(!KeyDown[SDL_SCANCODE_S] && Input::keystate[SDL_SCANCODE_S])
        {
            KeyDown[SDL_SCANCODE_S] = true;
            KeyUp  [SDL_SCANCODE_S] = true;
            std::cout << "Pulsaste s";
        }

        ////// GetKeyUp
        if(KeyUp[SDL_SCANCODE_A] && !Input::keystate[SDL_SCANCODE_A])
        {
            KeyUp[SDL_SCANCODE_A] = false;
            std::cout << "Soltaste a";
        }
        if(KeyUp[SDL_SCANCODE_S] && !Input::keystate[SDL_SCANCODE_S])
        {
            KeyUp[SDL_SCANCODE_S] = false;
            std::cout << "Soltaste s";
        }

        if(sdl_event.type == SDL_KEYUP)
        {
            KeyDown[sdl_event.key.keysym.scancode] = false;
        }
        if(sdl_event.type == SDL_KEYDOWN)
        {
            KeyUp[sdl_event.key.keysym.scancode] = true;
        }

        ////////////// TESTS INPUT MANAGMENT //////////////////////

        for (auto task : tasks)
        {
            task->do_step(time);  // Hacer una barra de carga
        }

        time = timer.elapsed_seconds();
    }

    for (auto task : tasks)
    {
        task->finalize();
    }
}
