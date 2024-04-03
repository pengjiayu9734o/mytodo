//
// Created by Administrator on 2024/3/29.
//

#include "block.h"
#include "common.h"
#include "display_symbol.h"
#include <iostream>

void Block::print() const
{
  std::cout << PIPE;
  for (int column = 0; column < _count; ++column) {
    point_value_t pointValue = *_numbers[column];
    if (pointValue.value == 0)
      std::cout << ' ' << " " <<PIPE;
    else
    {
      if (pointValue.state == State::ERASE)
      {

      }
    }
  }
}
