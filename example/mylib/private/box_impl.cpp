#include "../common/box.h"
#include "../common/common.h"
#define asTPtr(x, type) ((type*) x)

extern "C" MYLIB_API void myLib_BoxSetA(void* handle, int a) { asTPtr(handle, BoxData)->a = a; }

extern "C" MYLIB_API void myLib_BoxSetB(void* handle, int b) { asTPtr(handle, BoxData)->b = b; }

extern "C" MYLIB_API int myLib_BoxSum(void* handle) { return asTPtr(handle, BoxData)->a + asTPtr(handle, BoxData)->b; }
