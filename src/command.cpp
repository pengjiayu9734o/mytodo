//
// Created by Administrator on 2024/4/3.
//
#include "command.h"
#include "scene.h"
Command::Command(Scene *scene)
{
  _pOwner = scene;
}
Command::Command(const Command &command):_pOwner(command._pOwner), _stPoint(command._stPoint)
                                           ,_nCurValue(command._nCurValue){}
Command::~Command(){}

bool Command::execute(int nInputValue)
{
    if (!_pOwner)
        return false;
    _stPoint = _pOwner -> getCurPoint();
    return _pOwner->setCurValue(nInputValue);
}