//
// Created by Administrator on 2024/3/29.
//
#include <iostream>
#include "system_env.hpp"
#include "scene.h"
#include "input.h"

int main(int argc, char **argv)
{
#if _TEST_
    test_case1();
    getchar();
#else
    SetSystemEnv();
    Scene scene;
    int needEraseGrids = inputDifficulty();
    scene.generate();
}