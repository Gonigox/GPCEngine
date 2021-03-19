#include <Dispatcher.hpp>

void engine::Dispatcher::multicast(const Message& message)
{
    if (observers.count(message.id) > 0)
    {
        for (auto observer : observers[message.id])
        {
            observer->handle_message(message);
        }
    }
}
