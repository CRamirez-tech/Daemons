// thread example
#include <iostream>
#include <thread>

void foo()
{
    for(int i=0;i<10;i++){
        std::cout<<"This is foo."<<std::endl;
    }
}

void bar(int x)
{
    for(int i=0;i<10;i++){
        std::cout<<x<<std::endl;
    }
}

int main()
{
    std::thread first (foo);     // spawn new thread that calls foo()
    std::thread second (bar,0);  // spawn new thread that calls bar(0)

    std::cout << "main, foo and bar now execute concurrently...\n";

    // synchronize threads:
    first.join();                // pauses until first finishes
    second.join();               // pauses until second finishes

    std::cout << "foo and bar completed.\n";

    return 0;
}
