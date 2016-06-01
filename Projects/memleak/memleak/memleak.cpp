// memleak.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <xdebug>


#ifdef _DEBUG
#define new   new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif


int _tmain(int argc, _TCHAR* argv[])
{
	 _CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

   int* leak = new int[10];
   system("pause");
	return 0;
}

