#pragma once

typedef void (*BoxSetA_T)(void* handle, int a);
inline static BoxSetA_T BoxSetA;
typedef void (*BoxSetB_T)(void* handle, int b);
inline static BoxSetB_T BoxSetB;
typedef int (*BoxSum_T)(void* handle);
inline static BoxSum_T BoxSum;