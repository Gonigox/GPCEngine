#include <Timer.hpp>
#include <SDL.h>

namespace engine
{
    void Timer::start()
    {
        start_ticks = SDL_GetTicks();
    }

    float Timer::elapsed_seconds() const
    {
        return float(elapsed_milliseconds()) / 1000.f;
    }

    uint32_t Timer::elapsed_milliseconds() const
    {
        return SDL_GetTicks() - start_ticks;
    }
}