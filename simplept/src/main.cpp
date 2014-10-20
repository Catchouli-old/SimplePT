#include "app/SimplePT.h"

int main(int argc, char** argv)
{
    // Instantiate application
    pt::SimplePT app;

    // Main loop
    while (app.isRunning())
    {
        app.run();
    }
}