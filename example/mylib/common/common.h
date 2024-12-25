#pragma once
#ifdef _MSC_VER
#	ifdef mylib_EXPORTS
#		define MYLIB_API __declspec(dllexport)
#	else
#		define MYLIB_API
#	endif
#endif

#define _LibStr(n) #n
#define LibName _LibStr(myLib_)