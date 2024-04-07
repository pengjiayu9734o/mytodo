//
// Created by Administrator on 2024/3/29.
//
/**
 * 游戏场景
 */
#include "scene.h"
#include "block.h"
#include "utility.inl"
#include "display_symbol.h"
#include <cmath>
#include <unordered_map>
#include <memory.h>

//初始化场景
Scene::Scene(int index):
                          _max_column(pow(index, 2))
                          , _cur_point({0, 0})
{
  init();
}
Scene::~Scene(){}

void Scene::init()
{
  //为81个格子初始化值
  memset(_map, 0, sizeof _map);
  /**
   * 这段代码是把每一行每一列每个九宫格的指针都分别放到一个block里面去，每个block代表一行或者一列或者一个九宫格
   * 也就是说，最后一共会生成27个block
   * 我猜测原作者这么做是为了最后的检查通关的方便，不然我实在想不到这么做的理由
   * 如果是我我只会生成九个block来放置九个九宫格，而且九个block之间的内存位置不一定需要连续
   * 只要能检查到每一行每一列就行了
   */

  // column_block 所有列
  for (int col = 0; col < _max_column; ++col)
  {
    Block column_block;

    for (int row = 0; row < _max_column; ++row)
    {
      column_block.push_back(_map + row * 9 + col);
    }
    _column_block[col] = column_block;
  }

  // row_block 所有行
  for (int row = 0; row < _max_column; ++row)
  {
    Block row_block;

    for (int col = 0; col < _max_column; ++col)
    {
      row_block.push_back(_map + row * 9 + col);
    }
    _row_block[row] = row_block;
  }
  // xy_block 所有九宫格, [行][列]
  for (int block_index = 0; block_index < _max_column; ++block_index)
  {
    Block xy_block;

    int xy_begin = block_index / 3 * 27 + block_index % 3 * 3;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        xy_block.push_back(_map + xy_begin + i * 9 + j);
      }
    }
    _xy_block[block_index / 3][block_index % 3] = xy_block;
  }

}

void Scene::eraseRandomGrids(const int count) {
  point_value_t p = {0, State::ERASE};

  std::vector<int> v(81);
  for (int i = 0; i < 81; ++i) {
    v[i] = i;
  }

  for (int i = 0; i < count; ++i) {
    int r = random(0, v.size() - 1);
    _map[v[r]] = p;
    v.erase(v.begin() + r);
  }
}

void Scene::generate()
{
  // XXX: pseudo random
  static char map_pattern[10][10] = {
      "ighcabfde",
      "cabfdeigh",
      "fdeighcab",
      "ghiabcdef",
      "abcdefghi",
      "defghiabc",
      "higbcaefd",
      "bcaefdhig",
      "efdhigbca"};

  std::vector<char> v = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};

  // 产生字母到数字的随机映射
  std::unordered_map<char, int> hash_map;
  for (int i = 1; i <= 9; ++i)
  {
    int r = random(0, v.size() - 1);
    hash_map[v[r]] = i;
    v.erase(v.begin() + r);
  }

  // 填入场景
  for (int row = 0; row < 9; ++row)
  {
    for (int col = 0; col < 9; ++col)
    {
      point_t point = {row, col};
      char key = map_pattern[row][col];
      setValue(point, hash_map[key]);
    }
  }

  //assert(isComplete());
}

void Scene::setValue(const point_t &pointT, const int value)
{
  _map[pointT.x + pointT.y*9].value = value;
}

void Scene::printUnderline(int line_no) const
{
  auto is_curline = _cur_point.y == line_no;
  for (int column = 0; column < 9; ++column) {
    std::cout << CORNER << LINE << (is_curline ? (_cur_point.x == column ? ARROW : LINE) : LINE) << LINE;
  }
  std::cout << CORNER << std::endl;
}

void Scene::show() const
{
  cls();

  printUnderline();

  for (int row = 0; row < _max_column; ++row) {
    Block block =_row_block[row];
    block.print();
    printUnderline(row);
  }
}
bool Scene::setCurValue(const int nCurValue, int &lastValue)
{
  auto point = _map[_cur_point.x + _cur_point.y*9];
  if (point.state == State::ERASE)
  {
    lastValue = point.value;
    setValue(_cur_point, nCurValue);
  }
  else
  {
    return false;
  }
}
point_t Scene::getCurPoint()
{
  return _cur_point;
}

void Scene::play()
{
  show();
}
