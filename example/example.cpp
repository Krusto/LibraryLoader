#include "mylib/mylib.hpp"
#include <stdio.h>

int main()
{
    MyLib::LoadSymbols("./");
    Box box;

    box.setA(1);
    box.setB(2);

    auto sum = box.sum();

    printf("%d\n", sum);

    MyLib::UnloadSymbols();
    return 0;
}
