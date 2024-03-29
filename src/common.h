//
// Created by Administrator on 2024/3/29.
//

#ifndef MYTODO_COMMON_H
#define MYTODO_COMMON_H
//数独格子坐标
using point_t = struct point_t{
    int x,y;
};
enum class State: int
{
    INITED = 0,
    ERASE
};
enum class Difficulty: int
{
    EASY = 1,
    NORMAL,
    HARD
};
using point_value_t = struct point_value_t{
    int value;
    State state;
};
struct KeyMap
{
    const char ESC = 0x1B;
    const char U = 0x75;
    char UP;
    char LEFT;
    char DOWN;
    char RIGHT;
    const char ENTER = 0x0D;
};

struct Normal : KeyMap
{
    Normal()
    {
        UP = 0x77;
        LEFT = 0x61;
        DOWN = 0x73;
        RIGHT = 0x64;
    }
};

#endif //MYTODO_COMMON_H
