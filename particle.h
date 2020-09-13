#pragma once
#ifndef PARTICLE_H
#define PARTICLE_H

namespace first
{

    struct particle
    {
        double m_x;
        double m_y;

    private:
        double m_speed;
        double m_direction;

        // double m_xspeed;
        // double m_yspeed;

    public:
        particle();
        virtual ~particle();
        // 1st  void update();
        void update(int interval);

    private:
        void init();
    };
} // namespace first

#endif
