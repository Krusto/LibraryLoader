#pragma once
#include <string_view>

class LibraryLoader;

class MyLib
{
public:
    static void LoadSymbols(std::string_view working_directory);
    static void UnloadSymbols();

private:
    static LibraryLoader s_myLibrary;

public:
#include "common/function_pointers.h"
};

#include "Box.hpp"