//
// Created by Administrator on 2024/3/29.
//

#ifndef MYTODO_COMMAND_H
#define MYTODO_COMMAND_H
#include "common.h"
#include <memory>

class Scene;
class Command
{
public:
    Command(Scene *scene);
    Command(Scene *scene, const point_t& point, int preValue, int curValue);
    Command(const Command&);
    ~Command();

    bool execute(int nInputValue);
    void undo();
    point_t getPoint() {return _stPoint;}
    int getPreValue() const {return _nPreValue;}
    int getCurValue() const {return _nCurValue;}
    void setPoint(const point_t& point) {_stPoint = point;}
    void setPreValue(int preValue) {_nPreValue = preValue;}
    void setCurValue(int curValue) {_nCurValue = curValue;}

private:
    Scene *_pOwner;
    point_t _stPoint;
    int _nPreValue;
    int _nCurValue;
};
#endif //MYTODO_COMMAND_H
