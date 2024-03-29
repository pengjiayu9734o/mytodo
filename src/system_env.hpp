//
// Created by Administrator on 2024/3/29.
//
#pragma once
#if _WIN32
#include <Windows.h>
#endif

inline void SetWindowsEnv()
{
#if _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
}
inline void SetSystemEnv()
{
    SetWindowsEnv();
}

