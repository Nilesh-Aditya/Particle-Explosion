#include <iostream>
#include "SDL2/SDL.h"
#include <math.h>
#include "screen.h"
#include <stdlib.h>
#include <time.h>
#include "Swarm.h"

using std::cout;
using std::endl;
using namespace first;

int main()
{
    srand(time(NULL));

    Screen screen;

    if (screen.init() == false)
    {
        cout << "Error initialist SDL." << endl;
    }

    Swarm swarm;

    bool quit = false;
    while (true)
    {
        int elapsed = SDL_GetTicks();

        // screen.clear();

        swarm.update(elapsed);

        unsigned char green = (1 + sin(elapsed * 0.0001)) * 128;
        unsigned char red = (1 + sin(elapsed * 0.0002)) * 128;
        unsigned char blue = (1 + sin(elapsed * 0.0003)) * 128;

        const particle *const pParticles = swarm.getparticles();

        for (int i = 0; i < Swarm::NPARTICLES; i++)
        {
            particle particles = pParticles[i];

            int x = (particles.m_x + 1) * (Screen::SCREEN_WIDTH / 2);
            int y = particles.m_y * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT / 2;

            screen.setPixel(x, y, red, green, blue);
        }

        screen.boxBlur();

        // int elapsed = SDL_GetTicks();

        // unsigned char green = (1 + sin(elapsed * 0.0001)) * 128;
        // unsigned char red = (1 + sin(elapsed * 0.0002)) * 128;
        // unsigned char blue = (1 + sin(elapsed * 0.0003)) * 128;

        // for (int x = 0; x < Screen::SCREEN_WIDTH; x++)
        // {
        //     for (int y = 0; y < Screen::SCREEN_HEIGHT; y++)
        //     {
        //         screen.setPixel(x, y, red, green, blue);
        //     }
        // }

        // Draw the Screen
        screen.update();

        if (screen.processEvents() == false)
        {
            break;
        }
    }

    screen.close();

    return 0;
}