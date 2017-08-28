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
			// ASCII������������ʾ�ַ�
			*pDest++	= (char)((unsigned char)(*(++pStr)) - 0x80);
		}
		else if ((*pStr & 0xFF == 0xA1) && (*(pStr+1) & 0xFF) == 0xA1)
		{
			// ȫ�ǿո�
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