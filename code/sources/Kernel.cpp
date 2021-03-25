#include <Kernel.hpp>
#include <Script_Task.hpp>
#include <SDL.h>

engine::Kernel::Kernel(Window & win,Scene & scene) : renderer(2, win, scene), input_task(0, win), script_task(1, scene)
{
    exit   = false;
    paused = false;

    add_task(input_task);
    add_task(script_task);
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
