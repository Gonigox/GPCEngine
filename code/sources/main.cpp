#include <Kernel.hpp>
#include <Window.hpp>
#include <Scene.hpp>
#include <Entity.hpp>
#include <iostream>

using namespace engine;

int main()
{
    Scene scene("Prueba", 800, 450, false);

    std::cout << "Scene created";

#ifdef _DEBUG
    Entity* monkey01 = new Entity("../../../Binaries/Assets/monkey.obj");
    Entity* monkey02 = new Entity("../../../Binaries/Assets/monkey.obj");
#endif // DEBUG
#ifdef NDEBUG
    Entity* monkey01 = new Entity("Assets/monkey.obj");
    Entity* monkey02 = new Entity("Assets/monkey.obj");
#endif

    scene.add_Entity("Monkey01", monkey01);    
    scene.add_Entity("Monkey02", monkey02, new Vector3(10, 0, 0), new Vector3(180, 180, 0), new Vector3(3, 3, 3));

    monkey02->set_parent(monkey01);

    scene.start_game();

    return 0;
}