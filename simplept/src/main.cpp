#include "app/SimplePT.h"

void pause()
{
    system("pause");
}

int main(int argc, char** argv)
{
#ifdef _DEBUG
    atexit(pause);
#endif

    // Instantiate application
    pt::SimplePT app;

    // Main loop
    while (app.isRunning())
    {
        app.run();
    }
}