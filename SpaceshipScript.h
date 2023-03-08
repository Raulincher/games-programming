#pragma once

#include "Script.h"

using namespace std;

class SpaceshipScript : public Script
{

    using Script::Script;

public:

    void startScript() override;

    void tickScript(float deltaTime) override;



private:
    void CheckCollisions();

    glm::vec2 currDir = glm::vec2(0., 1.);
    glm::vec2 limits = glm::vec2(800., 800.);
    int hp = 1;
    bool destroyed = false;

};