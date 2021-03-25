#include <Kernel.hpp>
#include <SDL.h>

void engine::Kernel::add_task(Task& task)
{
    tasks.insert(&task);
    task.set_kernel(this);
}

void engine::Kernel::execute()
{
    exit = false;
    SDL_Event sdl_event;

    for (auto task : tasks)
    {
        task->initialize();
    }

    float time = 1.f / 60.f;

    while (!exit)
    {
        Timer timer;

        SDL_PollEvent(&sdl_event);

        if(sdl_event.type == SDL_QUIT)
        {
            exit = true;
        }

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
