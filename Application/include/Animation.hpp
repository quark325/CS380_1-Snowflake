#pragma once

#include <vector>
#include <Snowflake.hpp>

/*
 * Animation class supports continuous animation by changing RenderObject's transform with elasped time in seconds
 */

class Animation
{
private:
    std::vector<Snowflake*> _snowflakes;
public:
    Animation();
    ~Animation();
    void AddSnowflake(Snowflake* snowflake);
    void Animate1(float deltaTime);
};