typedef unsigned int  DWORD;
typedef unsigned char BYTE;
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// 原作者信息中文乱码
DWORD mk_hash_index(DWORD* pstHashKey, DWORD dwHashCount, DWORD dwLen)
{
	DWORD dwi;
	BYTE* pKeyEnd;
	DWORD* pKey;
	DWORD dwKeyLen;
	DWORD dwHashVal = dwHashCount;

	dwKeyLen = dwLen;
	pKey = (DWORD*)(pstHashKey);

	for (dwi = dwKeyLen / sizeof(DWORD); dwi>0; dwi--)
	{
		dwHashVal = ((dwHashVal << 5) + dwHashVal) + *pKey;
		pKey++;
	}
	dwi = sizeof(DWORD)-(dwKeyLen%sizeof(DWORD));
	pKeyEnd = (BYTE*)pKey + 3;
	while (dwi-- > 0)
	{
		*pKeyEnd-- = 0;
	}
	dwHashVal = ((dwHashVal << 5) + dwHashVal) + *pKey;
	dwHashVal = dwHashVal % dwHashCount;
	return dwHashVal;
}

/* 用随机数测试上述hash函数的正确性 */
int main()
{	
	int i = 0;

	srand((unsigned)time(NULL));
	DWORD a = 0;
	DWORD val = 0;
	for (i = 0; i < 383; i++)
	{
		a = rand()%65536;
		val = mk_hash_index(&a, 383, 2) + 128;
		printf("key: %6d value:%6d      \n", a, val);
	}
	
	getchar();
}