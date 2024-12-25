#pragma once

#include "LibraryLoader.h"

int LibraryLoader::Init(std::string_view path)
{
    LOG("LibraryLoader::Init %s\n", path.data());
    m_hModule = LoadLibraryA(path.data());
    if (!m_hModule)
    {
        LOG_ERROR("could not load the dynamic library\n");
        return 0;
    }
    return 1;
}

int LibraryLoader::Unload()
{
    if (m_hModule)
    {
        LOG("LibraryLoader::Unload\n");

        auto result = FreeLibrary(m_hModule);

        if (!result) { return 0; }
        m_hModule = 0;
    }
    return 1;
}

template <typename T>
T LibraryLoader::GetSymbol(std::string_view symbol)
{
    LOG("LibraryLoader::GetSymbol %s\n", symbol.data());
    auto result = (T) GetProcAddress(m_hModule, symbol.data());
    if (!result) { return {}; }
    return result;
}
