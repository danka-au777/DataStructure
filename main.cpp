#include "Game.h"

int main(){
    Game test;
    try
    {
        test.Run();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout<<"Bye!";
    return 0;
}