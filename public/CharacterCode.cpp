#include "CharacterCode.h"
#include <string.h>

#ifndef NULL
#define NULL ((void *)0)
#endif

void FullToHalf(char* pStr)
{
	char *pDest	= pStr;
	if (NULL == pStr)
		return;
	for (; *pStr; ++pStr)
	{
		if (((*pStr) & 0xFF) == 0xA3 && (*(pStr + 1) & 0xFF) >= 0xA1 && (*(pStr + 1) & 0xFF) <= 0xFE)
		{
			// ASCII码中其它可显示字符
			*pDest++	= (char)((unsigned char)(*(++pStr)) - 0x80);
		}
		else if ((*pStr & 0xFF == 0xA1) && (*(pStr+1) & 0xFF) == 0xA1)
		{
			// 全角空格
			*pDest++	= 0x20;
		}
		else
 		{
			if (*pStr < 0)
				*pDest++	= *(pStr++);
			*pDest++	= *pStr;
		}
	}
	*pDest	= '\0';
}