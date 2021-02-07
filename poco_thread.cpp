#include "Poco/Thread.h"
#include "Poco/Runnable.h"
#include <iostream>

struct HelloThread :  Poco::Runnable
{
    void run()
    {
        for (int i = 0; i < 10; i++)
        {
            std::cout << "Hello, world!" << std::endl;
        }
    }
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[])
{
    Poco::Thread thread;
    HelloThread hello;
    thread.start(hello);
    thread.join();

    return 0;
}