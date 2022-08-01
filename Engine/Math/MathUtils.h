#pragma once

namespace Math
{
    const float PI = 3.14159265359f; // 180
    const float TWO_PI = 6.28318530718f; // 360
    const float HALF_PI = 1.57079632679f; // 90

    inline float DegToRad(float degrees)
    {
        return degrees * (PI / 180);
    }

    inline float RadToDeg(float radians)
    {
        return radians * (180 / PI);
    }

    int sqr(int v);
    inline int half(int v) { return v / 2; } // use inline for smaller functions
}