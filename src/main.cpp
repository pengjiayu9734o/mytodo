//
// Created by Administrator on 2024/3/29.
//
#include <iostream>
#include "system_env.hpp"
#include "scene.h"
#include "input.h"

int main(int argc, char **argv)
{
    SetSystemEnv();
    Scene scene;
    int needEraseGrids = inputDifficulty();
    scene.generate();
    scene.eraseRandomGrids(needEraseGrids);

    scene.play();
}