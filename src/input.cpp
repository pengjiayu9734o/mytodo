//
// Created by Administrator on 2024/3/29.
//
#include "utility.inl"
#include "I18n.h"
#include "common.h"
#include <string>

//返回初始化的格子数量
int inputDifficulty()
{
    cls();
    std::string cmd;
    int need_erase_grids = 0;
    while (true)
    {
        message(I18n::Instance().Get(I18n::Key::ASK_DIFFICULTY));
        std::cin>>cmd;
        try
        {
            Difficulty difficulty = static_cast<Difficulty>(std::stoi(cmd));
            switch (difficulty) {
                case Difficulty::EASY:
                    need_erase_grids = 20;
                    break;
                case Difficulty::NORMAL:
                    need_erase_grids = 35;
                    break;
                case Difficulty::HARD:
                    need_erase_grids = 50;
                    break;
            }
        }
        catch(...)
        {
            need_erase_grids = 0;
        }
        if (need_erase_grids > 0)
            break;
        message(I18n::Instance().Get(I18n::Key::INPUT_ERROR));
    }
    return need_erase_grids;
}
