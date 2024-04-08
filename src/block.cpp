//
// Created by Administrator on 2024/3/29.
//

#include "block.h"
#include "common.h"
#include "display_symbol.h"
#include "color.h"
#include <iostream>
Block::~Block(){}
Block::Block():_count(0) {}
void Block::print() const
{
  std::cout << PIPE;
  for (int column = 0; column < _count; ++column) {
    point_value_t pointValue = *_numbers[column];
    if (pointValue.value == 0)
      std::cout << "   " <<PIPE;
    else
    {
      if (pointValue.state == State::ERASE)
      {
        std::cout << " " << Color::Modifier(Color::FG_GREEN)
        << pointValue.value
        << Color::Modifier(Color::RESET)
        << " " << PIPE;
      }
      else
      {
        std::cout << " " <<pointValue.value << " " << PIPE;
      }
    }
  }
  std::cout<<std::endl;
}
bool Block::isValid() const
{
    for (int i = 0; i < _count - 1; ++i)
    {
        for (int j = i + 1; j < _count; ++j)
        {
            if (0 == _numbers[i]->value || 0 == _numbers[j]->value)
                continue;

            if (_numbers[i]->value == _numbers[j]->value)
                return false;
        }
    }

    return true;
}

void Block::push_back(point_value_t *point)
{
  _numbers[_count++] = point;
}
