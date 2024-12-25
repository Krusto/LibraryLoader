#pragma once
#if _WIN32
#include <Windows.h>
#endif
#ifndef LOG
#include <stdio.h>
#define LOG printf
#endif
#ifndef LOG_ERROR
#include <stdio.h>
#define LOG_ERROR printf
#endif
#ifndef LOG_DEBUG
#include <stdio.h>
#define LOG_DEBUG printf
#endif
#ifdef __cplusplus
#include <string_view>
#include <expected>

class LibraryLoader
{
public:
    LibraryLoader() = default;
    ~LibraryLoader() = default;

    int Init(std::string_view path);

    int Unload();

    template <typename T>
    T GetSymbol(std::string_view symbol);

private:
#if _WIN32
    HINSTANCE m_hModule = nullptr;
#else
    // TODO:
    // Add Linux support
#endif
};

#include "LibraryLoader.impl.hpp"
#endif
