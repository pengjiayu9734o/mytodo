//
// Created by Administrator on 2024/3/29.
//

#ifndef MYTODO_BLOCK_H
#define MYTODO_BLOCK_H
#include "common.h"

class Block {
    static const int MAX_COUNT = 9;
public:
    Block();
    bool isValid() const;
    bool isFull() const;
    void print() const;
    void push_back(point_value_t *point);
private:
    int _count;
    point_value_t *_numbers[MAX_COUNT];
};


#endif //MYTODO_BLOCK_H
