#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
using namespace std;

// 先算
// 编译器默认的对齐方式为8
// member offset % min(Zp,sizeof(member type)) == 0

// 算完后算
//StructAlign = max(sizeof(member1 type), sizeof(member2 type)···, sizeof(membern type));
//StructAlign = min(Zp, StructAlign);
//sizeof(结构体变量)必须满足
//sizeof(结构体变量) % structAlign == 0;

struct tagPerson
{
	char szName[5]; 			// 0 % min(8,sizeof(char)) == 0 +0 +0
	float fHeight; 				// 5 % min(8,sizeof(float)) != 0 +5 +8
	double dblWeight; 			// 12 % min(8,sizeof(double)) != 0 +12 +16
	char cGender; 				// 24 % min(8,sizeof(char)) == 0 +24 +24
	__int64 i64; 				// 25 % min(8,sizeof(__int64)) != 0 +25 +32
	char c; 					// 40 % min(8,sizeof(char)) == 0 +40 +40
	int nID; 					// 41 % min(8,sizeof(int)) != 0 +41 +44
	unsigned short int wAge; 	// 48 % min(8,sizeof(short int)) == 0 +48 +48
}; 							//offset = 48 + 2 = 50 50 % 8 !=0 size == 56


int _tmain()
{
	cout << sizeof(double) << endl;
	cout << sizeof(__int64) << endl;
	struct tagPerson t1;
	cout << "结构体大小为: " << sizeof(t1) << endl;
	return 0;
}