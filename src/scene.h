//
// Created by Administrator on 2024/3/29.
//
#ifndef MYTODO_SCENE_H
#define MYTODO_SCENE_H
#include "common.h"
#include "command.h"
#include "block.h"
#include <vector>
class Scene
{
public:
    Scene(int index = 3);
    virtual ~Scene();

    void generate();
    void show() const;

    bool setCurValue(const int nCurValue, int& lastValue);
    bool setPointValue(const point_t&, const int);
    point_t getPoint();

    void eraseRandomGrids(const int count);
    bool isComplete();

    void play();
    bool save(const char *filename);
    bool load(const char *filename);
private:
    void init();//将每个格子的指针放到block里面
    void setValue(const int);
    void setValue(const point_t&, const int);
    void printUnderline(int line_no = -1) const;
private:
    KeyMap *keyMap{};
    int _max_column;
    point_t _cur_point;
    Block _column_block[9];
    Block _row_block[9];
    Block _xy_block[3][3];
    point_value_t _map[81];

    std::vector<Command> _vCommand;
};
#endif //MYTODO_SCENE_H
