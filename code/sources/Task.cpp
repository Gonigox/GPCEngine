#include <Task.hpp>

namespace engine
{
    void Task::set_kernel(Kernel* new_kernel)
    {
        kernel = new_kernel;
    }
}