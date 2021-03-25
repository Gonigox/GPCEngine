#include <Kernel.hpp>
#include <SDL.h>
#include <Input.hpp>
#include <iostream>

engine::Kernel::Kernel(Window & win,Scene & scene) : renderer(1, win, scene), input_task(0, win)
{
    exit   = false;
    paused = false;

    add_task(input_task);
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

    for (auto task : tasks)
    {
        task->initialize();
    }

    float time = 1.f / 60.f;

    while (!exit)
    {
        Timer timer;

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
