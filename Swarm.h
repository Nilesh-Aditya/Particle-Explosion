#pragma once
#include "particle.h"

namespace first
{
    class Swarm
    {
    public:
        const static int NPARTICLES = 5000;

    private:
        particle *m_pParticles;
        int lastTime;

    public:
        Swarm();
        ~Swarm();
        const particle *const getparticles() { return m_pParticles; };
        // void update();
        void update(int elapsed);
    };

    Swarm::Swarm() : lastTime(0)
    {
        m_pParticles = new particle[NPARTICLES];
    }

    Swarm::~Swarm()
    {
        delete[] m_pParticles;
    }

    // void Swarm::update()
    // {
    //     for (int i = 0; i < Swarm::NPARTICLES; i++)
    //     {
    //         m_pParticles[i].update();
    //     }
    // }

    void Swarm::update(int elapsed)
    {
        int interval = elapsed - lastTime;
        for (int i = 0; i < Swarm::NPARTICLES; i++)
        {
            m_pParticles[i].update(interval);
        }
        lastTime = elapsed;
    };

} // namespace first