#include <iostream>
#include <fstream>
#include <string>
#include "Mystring.h"
using namespace std;
int main()
{
	Mystring T("Taqi");
	Mystring D("Pakgooistan is good iansk   ");
	Mystring B("123");
	int Count=0;
	/*
	Mystring* val = D.Split('a',Count);
	cout << endl << endl;
	*/

	/*int temp = B.Atoi(B);
	cout << temp;
	*/
	D.Split('s', Count);



}