#include "Mystring.h"
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>

using namespace std;
void Regrow(int*& array, int val, int& size)
{
	int* values = new int[size + 1];
	for (int ri = 0; ri < size; ri++)
	{
		values[ri] = array[ri];
	}
	values[size] = val;
	delete[]array;
	array = values;
	size++;
}
void RegrowChar(char*& array, char val, int& size)
{
	char* values = new char[size + 1];
	for (int ri = 0; ri < size; ri++)
	{
		values[ri] = array[ri];
	}
	values[size] = val;
	delete[]array;
	array = values;
	size++;
}
int Mystring::STRLEN(const char* Astring)
{
	int size = 0;
	for (int ri = 0; Astring[ri] != '\0'; ri++)
	{
		size++;
	}
	return size;
}
void Mystring::DeepCopy(const char* Astring)
{

	int size = STRLEN(Astring);
	this->size = size;

	this->Cs = new char[size + 1];

	for (int ri = 0; ri <= size; ri++)
	{
		this->Cs[ri] = Astring[ri];
	}
}
Mystring::Mystring()
{
	this->Cs = nullptr;
	this->size = 0;
}
Mystring::Mystring(const char* Astring)
{
	DeepCopy(Astring);
}


Mystring::Mystring(const Mystring& S)
{

	DeepCopy(S.Cs);

}
void Mystring::Print()const
{

	cout << this->Cs;
}
int Mystring::length()
{
	int S = STRLEN(Cs);
	return S;
}
bool Mystring::equal(const Mystring& S) const
{
	if (this->size != S.size)
	{
		return false;
	}
	for (int ri = 0; ri < S.size; ri++)
	{
		if (this->Cs[ri] != S.Cs[ri])
		{
			return false;
		}
	}
	return true;
}
int Mystring::CMP(const Mystring& S)
{

	for (int ri = 0; ri < S.size; ri++)
	{
		if (this->Cs[ri] < S.Cs[ri])
		{
			return -1;
		}
		if (this->Cs[ri] > S.Cs[ri])
		{
			return 1;
		}
	}
	if (this->size == S.size)
	{
		return 0;
	}
}
void Mystring::ReplaceFirst(const char ch)const
{
	this->Cs[0] = ch;
}
void Mystring::Trim()
{
	int count = 0;
	int ri = 0;
	if (this->Cs[0] == ' ' or this->Cs[0] == '\t' or this->Cs[0] == '\n')
	{
		count++;
		ri++;
		do
		{
			if ((this->Cs[ri] == ' ' or this->Cs[ri] == '\t' or this->Cs[ri] == '\n') && (!isalpha(this->Cs[ri])))
			{
				count++;
				ri++;
			}
			else
			{
				break;
			}
		} while (true);
	}
	int li = this->size - 1;
	if (this->Cs[li] == ' ' or this->Cs[li] == '\t' or this->Cs[li] == '\n')
	{
		count++;
		li--;
		do
		{
			if ((this->Cs[li] == ' ' or this->Cs[li] == '\t' or this->Cs[li] == '\n') && (!isalpha(this->Cs[li])))
			{
				count++;
				li--;
			}
			else
			{
				break;
			}
		} while (true);
	}
	this->size = this->size - count;
	char* ch = new char[this->size + 1];
	for (int ci = 0; ci < this->size; ci++)
	{
		ch[ci] = this->Cs[ri];
		ri++;
	}
	ch[this->size] = '\0';
	delete[]this->Cs;
	this->Cs = new char[this->size + 1];
	for (int c = 0; c < this->size; c++)
	{
		this->Cs[c] = ch[c];
	}
	this->Cs[this->size] = '\0';
	delete[]ch;
}
const char Mystring::CharCopy(int i)
{
	return (this->Cs[i]);
}
char& Mystring::CharRefAt(int val)
{
	return (this->Cs[val]);

}
Mystring Mystring::str_cat(Mystring s)
{
	Mystring T;
	T.size = this->size + s.size;
	T.Cs = new char[T.size + 1];
	int ri;
	for (ri = 0; ri < this->size; ri++)
	{
		T.Cs[ri] = this->Cs[ri];
	}
	for (int ci = ri, c = 0; ci < T.size; ci++)
	{
		T.Cs[ci] = s.Cs[c];
		c++;
	}
	T.Cs[T.size] = '\0';
	//T.Print();

	return T;
}

int Mystring::find_first(char ch)
{
	for (int ri = 0; ri < this->size; ri++)
	{
		if (this->Cs[ri] == ch)
		{
			return ri;
		}
	}
}
int Mystring::find_last(char ch)
{
	for (int ri = this->size - 1; ri >= 0; ri--)
	{
		if (this->Cs[ri] == ch)
		{
			return ri;
		}
	}
}
int* Mystring::find_all(char ch, int& Count)
{
	Count = 0;
	int* array = new int[Count];

	for (int ri = 0; ri < this->size; ri++)
	{
		if (this->Cs[ri] == ch)
		{
			Regrow(array, ri, Count);
		}
	}
	return array;
}

void RemoveCh_FIRST(char*& array, int& size, char ch)
{
	bool check = false;
	int ri;

	for (ri = 0; ri < size; ri++)
	{
		if (array[ri] == ch && check == false)
		{
			size--;
			break;
		}
	}
	for (int j = ri + 1; ri < size; j++)
	{
		array[ri] = array[j];
		ri++;
	}
	array[ri] = '\0';
}
void RemoveCh_LAST(char*& array, int& size, char ch)
{
	bool check = false;
	int ri;

	for (ri = size - 1; ri >= 0; ri--)
	{
		if (array[ri] == ch && check == false)
		{
			size--;
			break;
		}
	}
	for (int j = ri + 1; ri < size; j++)
	{
		array[ri] = array[j];
		ri++;
	}
	array[ri] = '\0';
}
void Mystring::remove_first(char ch)
{
	for (int ri = 0; ri < this->size; ri++)
	{
		if (this->Cs[ri] == ch)
		{
			RemoveCh_FIRST(this->Cs, this->size, ch);
			return;
		}

	}
}
void Mystring::remove_last(char ch)
{
	for (int ri = this->size - 1; ri >= 0; ri--)
	{
		if (this->Cs[ri] == ch)
		{
			RemoveCh_LAST(this->Cs, this->size, ch);
			return;
		}

	}

}

void REMOVEALL(char*& array, int ri, int& size)
{
	for (int j = ri + 1; ri < size; j++)
	{
		array[ri] = array[j];
		ri++;
	}
	array[ri] = '\0';

}
void RemoveCh_ALL(char*& array, int& size, char ch)
{
	int ri;

	for (ri = 0; ri < size; ri++)
	{
		if (array[ri] == ch)
		{
			size--;
			REMOVEALL(array, ri, size);

		}
	}

}
void Mystring::remove_all(char ch)
{
	for (int ri = 0; ri < this->size; ri++)
	{
		if (this->Cs[ri] == ch)
		{
			RemoveCh_ALL(this->Cs, this->size, ch);
		}

	}

}
void Mystring::remove_at(int i)
{
	int ri;
	for (ri = 0; ri < this->size; ri++)
	{
		if (ri == i)
		{
			for (int j = ri + 1; j < this->size; j++)
			{
				this->Cs[ri] = this->Cs[j];
				ri++;

			}
			this->Cs[ri] = '\0';
		}
	}
}
void Mystring::insert_at(int i, char ch)
{
	this->size++;
	char* values = new char[this->size + 1];
	for (int ri = 0; ri < this->size; ri++)
	{
		values[ri] = this->Cs[ri];

		if (ri == i)
		{
			for (int j = ri + 1; j < this->size; ri++, j++)
			{
				values[j] = this->Cs[ri];
			}
			values[i] = ch;
			values[this->size] = '\0';
			delete[]this->Cs;
			this->Cs = values;
			return;
		}
	}
}
void Mystring::Insert_At(int i, const Mystring& sub)
{

	int size = this->size + sub.size;

	char* values = new char[size+1];
	for (int ri = 0; ri < this->size; ri++)
	{
		values[ri] = this->Cs[ri];

		if (ri == i)
		{
			for (int j = sub.size + ri; j < size; ri++, j++)
			{
				values[j] = this->Cs[ri];
			}
			for (int k = i, h = 0; h < sub.size; h++, k++)
			{
				values[k] = sub.Cs[h];
			}
			values[size] = '\0';
			delete[]this->Cs;
			this->Cs = values;
			this->size = size;
			return;
		}
	}


}
void Mystring::clear()
{
	this->size = 0;
	this->Cs= nullptr;

}
int*& Mystring::AllSubStrings(const char* sub, int& count)
{
	int* Res;
	int temp = 0;
	int sublength = STRLEN(sub);
	Res = new int[count];
	for (int ri=0;(ri+(sublength-1)) < this->size;ri++)
	{
		temp = 0;
		for (int j=0,k=ri;j<sublength;j++,k++)
		{
			if ((sub[j]==this->Cs[k]))
			{
				temp++;				
			}
			if (temp == 2)
			{
				Regrow(Res,ri,count);
				break;
			}
		}		
	}
	return Res;
}
Mystring*& Mystring::Split(char c, int& count)const
{
	Mystring* values;

	count = 0;
	int temp = 0;
	bool check = true;
    for (int ri=0;ri<this->size;ri++)
	{
		if (this->Cs[ri] != c )
		{                                                                                                                             
			check = true;
		}
		else
		{

			if (check == true)
			{
				count++;
			}
			check = false;
		}
	}
	if (this->Cs[0] == c)
	{
		count--;
	}
	if (this->Cs[this->size-1] == c)
	{
		count--;
	}
	count++;
	values = new Mystring[count];                                                                                   
	int times;
	char newarray=true;                                                   
	int number = 0;
	while (true)
	{
		if (this->Cs[number] == c && newarray == true)
		{
			number++;
			temp++;
		}
		else
		{
			//newarray = false;
			break;
		}
	}	
	for (int ri=0;ri<count;ri++)
	{		
		values[ri].size = 0;
		values[ri].Cs = new char[0];
		
		for (int ci = temp; ci < this->size; ci++)
		{
			
				if (this->Cs[ci] != c)
				{
					check = true;
					RegrowChar(values[ri].Cs, this->Cs[ci], values[ri].size);
				}
				else
				{

					if (check == true)
					{
						int num = ci+1;
						values[ri].Cs[values[ri].size] = '\0';
						while(this->Cs[num]== c)
						{
							num++;
							temp++;
						}
						temp++;
						break;
					}
					check = false;

				}
				temp++;
		}
	}
	values[count - 1].Cs[values[count - 1].size] = '\0';

	cout << &values <<"( "<<(void*) values<<" )==>";
	for (int ri = 0; ri < count; ri++)
	{
		cout <<(void*) &values[ri].Cs << " (" << (void*)values[ri].Cs << " )==>";
		cout << "(";
		for (int ci = 0; ci < values[ri].size; ci++)
		{
			cout << values[ri].Cs[ci];
		}
		cout << ")";
		cout << endl << endl;                         

	}             

	return values;

}

bool IsStringEqual(char c[],char array[],int ri,int sizec)
{
	sizec = 0;
	int count = 0;

	for (int ci=0;c[ci]!='\0';ci++)
	{
		sizec++;
	}
	for(int i=ri,j=0;j<sizec;i++,j++)
	{
		if (array[i]==c[j])
		{
			count++;
		}
	}
	if (count == sizec)
	{
		return true;
	}
	return false;
}
Mystring* Mystring::Token(const Mystring &c, int& count)
{
	Mystring* values;
	int csize = 0;
	count = 0;
	int temp = 0;
	bool check = true;
	for (int ri = 0; ri < this->size; ri++)
	{
		if (IsStringEqual(c.Cs,this->Cs, ri,c.size))
		{
			check = true;
		}
		else
		{

			if (check == true)
			{
				count++;
			}
			check = false;
		}
	}
	
	values = new Mystring[count];
	int times;
	int number = 0;
	while (true)
	{
	
		if (IsStringEqual(c.Cs, this->Cs, number,c.size))
		{
			number++;
			temp=temp+c.size;
		}
		else
		{
			break;
		}
	}

	for (int ri = 0; ri < count; ri++)
	{
		values[ri].size = 0;
		values[ri].Cs = new char[0];

		for (int ci = temp; ci < this->size; ci++)
		{

			if (!IsStringEqual(c.Cs, this->Cs, ci, csize))
			{
				check = true;
				RegrowChar(values[ri].Cs, this->Cs[ci], values[ri].size);
			}
			else
			{

				if (check == true)
				{
					int num = ci + 1;
					values[ri].Cs[values[ri].size] = '\0';
					
					while (IsStringEqual(c.Cs, this->Cs, num, c.size))
					{
						num++;
						temp=temp+c.size;
					}
					temp=temp+c.size;
					break;
				}
				check = false;

			}
			temp++;
		}
	}
	values[count - 1].Cs[values[count - 1].size] = '\0';

	cout << &values << "( " << (void*)values << " )==>";
	for (int ri = 0; ri < count; ri++)
	{
		cout << (void*)&values[ri].Cs << " (" << (void*)values[ri].Cs << " )==>";
		cout << "(";
		for (int ci = 0; ci < values[ri].size; ci++)
		{
			cout << values[ri].Cs[ci];
		}
		cout << ")";
		cout << endl << endl;

	}

	return values;

}
int Mystring::Atoi(Mystring S)
{
	int temp=0;
	for (int ri=0;ri<S.size;ri++)
	{
		 int num=(int(S.Cs[ri]));
		 num = num - 48;
		 temp = temp * pow(10,1) + num;
	}
	return temp;
}


Mystring::~Mystring()
{
	delete[] Cs;
	Cs = nullptr;
}

