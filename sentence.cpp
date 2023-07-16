#include "sentence.h"
#include "paragraph.h"
#include<fstream>

sentence::sentence() :paragraph()
{
	arr2 = nullptr;
	size2 = 0;
	count1 = 0;
	count2 = 0;
}
sentence::sentence(char*a2, int s2, int c1,int c2,char* a1, int s1) :paragraph(a1,s1)
{
	arr2 = a2;
	size2 = s2;
	count1 = c1;
	count2 = c2;
}
void sentence::setarr2(char *a2)
{
	arr2 = new char[strlen(a2)+ 1];
	strcpy_s(arr2, strlen(a2) + 1, a2);
}
char *sentence::getarr2()
{
	char *temp = new char[strlen(arr2) + 1];
	strcpy_s(temp, strlen(arr2) + 1, arr2);
	return temp;
}
void sentence::setsize2(int s2)
{
	size2 =s2;
}
int sentence::getsize2()
{
	return size2;
}
void sentence::setcount1(int c1)
{
	count1 = c1;
}
int sentence::getcount1()
{
	return count1;
}
void sentence::display()
{
	ofstream fout1;
	fout1.open("frequency.txt",ios::app);
	for (int i = 0; i < size2; i++)
	{
		if (arr2[i] == '\n' && arr2[i + 1] == '\n' || (i == size2 - 1))
		{
			count2++;
		}
	}
	cout << endl;
	cout << endl;
	cout << "NUMBER OF paragraph:" << count2 << endl;
	fout1 << "NUMBER OF paragraph:" << count2 << endl;
	
	for (int i = 0,m=0; i < size2; i++)
	{
		if (arr2[i] == '.')
		{
			count1++;
		}
		if ((arr2[i] == '\n' && arr2[i + 1] == '\n') || (i==size2-1))
		{
			m++;
			cout << endl;
			cout << "NUMBER OF SENTENCE IN paragraph " << m << ":" << count1 << endl;
			fout1 << "NUMBER OF SENTENCE IN paragraph " << m << ":" << count1 << endl;
			count1 = 0;
		}
			
	}
}
sentence::~sentence()
{
	delete[]arr2;
	arr2 = nullptr;
	size2 = 0;
	count1 = 0;
}
