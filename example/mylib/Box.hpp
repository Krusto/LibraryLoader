#pragma once
#include "common/box.h"

class Box
{
public:
    Box() = default;
    ~Box() = default;

    void setA(int a);

    void setB(int b);

    int sum() const;

private:
    BoxData m_data;
};
