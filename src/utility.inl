//
// Created by Administrator on 2024/3/29.
//

#ifndef MYTODO_UTILITY_INL
#define MYTODO_UTILITY_INL
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iostream>

inline int random(int begin, int end)
{
  srand(time(NULL));
  return (unsigned int)rand() % (end - begin + 1) + begin;
}

inline void message(const std::string &msg, bool lf = true)
{
    std::cout<<&msg;
    if (lf)
        std::cout<<std::endl;
}

inline void cls()
{
#ifdef _WIN32
    system("cls");
#else
    system("clean");
#endif
}
#endif //MYTODO_UTILITY_INL
