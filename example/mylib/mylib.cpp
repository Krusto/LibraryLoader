#include "mylib.hpp"
#include "common/common.h"
#include "common/function_pointers.h"
#include <LibraryLoader.h>
#include <string>

LibraryLoader MyLib::s_myLibrary;

#define _LoadSymbol2(funcName, funcNameStr) funcName = s_myLibrary.GetSymbol<decltype(funcName)>(LibName##funcNameStr)
#define _LoadSymbol(funcName) _LoadSymbol2(funcName, #funcName)

void MyLib::LoadSymbols(std::string_view working_directory)
{
    std::string path = std::string(working_directory.data()) + "/mylib.dll";
    if (!s_myLibrary.Init(path)) { return; }
    _LoadSymbol(BoxSetA);
    _LoadSymbol(BoxSetB);
    _LoadSymbol(BoxSum);
}

void MyLib::UnloadSymbols() { s_myLibrary.Unload(); }