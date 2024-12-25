#pragma once
#include "mylib.hpp"
#include "Box.hpp"

void Box::setA(int a) { MyLib::BoxSetA(&m_data, a); }

void Box::setB(int b) { MyLib::BoxSetB(&m_data, b); }

int Box::sum() const { return MyLib::BoxSum((void*) &m_data); }
