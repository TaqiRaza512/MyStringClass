#pragma once
#include<fstream>
#include<cstring>

class Mystring
{
private:
	
	static int STRLEN(const char*);
	void DeepCopy(const char* AString);

public:
	char* Cs;
	int size;
	Mystring();
	Mystring(const char*);
	Mystring(const Mystring&);

	int Atoi(Mystring s);
	void Print()const;
	bool equal(const Mystring&)const;
	int length();
	int CMP(const Mystring&);
	void ReplaceFirst(char ch)const;
	void Trim();
	const char CharCopy(int i);
	char& CharRefAt(int val);
	Mystring str_cat(Mystring s2);
	int find_first(char ch);
	int find_last(char ch);
	int* find_all(char ch, int& Count);

	void remove_first(char ch);
	void remove_last(char ch);
	void remove_all(char ch);

	void remove_at(int i);
	void insert_at(int i, char ch);
	void Insert_At(int i, const Mystring& sub);
	int*& AllSubStrings(const char* sub,int &count);
	Mystring*& Split(char c, int& count) const;
	Mystring* Token(const Mystring &c, int& count);

	void clear();


	~Mystring();

};

