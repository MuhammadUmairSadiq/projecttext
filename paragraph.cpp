#include "paragraph.h"
#include<fstream>
#include<iostream>
using namespace std;

paragraph::paragraph()
{
	data = nullptr;
	arr = nullptr;
	size = 0;
}
paragraph::paragraph(char* ar, int s)
{
	arr = ar;
	size = s;
}
paragraph::paragraph(const paragraph&obj)
{
	arr = new char[strlen(obj.arr) + 1];
	strcpy_s(arr, strlen(obj.arr) + 1, obj.arr);

	size = obj.size;
}

void paragraph::setarr(char *ar)
{
	arr = new char[strlen(ar) + 1];
	strcpy_s(arr, strlen(ar) + 1,ar);
	
}
void paragraph::setsize(int s)
{
	size = s;
}
int paragraph::getsize()
{
	return size;
}
char* paragraph::getarr()
{
	char *temp = new char[strlen(arr) + 1];
	strcpy_s(temp, strlen(arr) + 1, arr);
	return temp;
}

istream& operator >>(istream& input, paragraph&obj)
{
	int s = obj.getsize();
	obj.arr = new char[s+1];
	
	for (int i =0;i<s; i++)
	{
		input >> obj.arr[i];
	}
	return input;
}
ostream& operator << (ostream& output, paragraph&obj)
{
	ofstream out;
	out.open("frequency.txt",ios::app);
	for (int i = 0; i <obj.getsize()-1; i++)
	{
		output << obj.arr[i];
		//out << obj.arr[i];
	}
	out << endl;
	out << endl;
	out.close();
	return output;
}
void paragraph::operator=(paragraph const& obj)
{
	int count = 0;
	arr = new char[obj.size+1];
	for (int i = 0; i < obj.size+1; i++)
	{
		arr[i] = obj.arr[i];
	}
	size = obj.size;
}
int paragraph::operator==(paragraph& obj)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == obj.arr[i])
		{
			count++;
		}
	}
	if (size == count)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool paragraph::operator!=(paragraph& obj)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == obj.arr[i])
		{
			count++;
		}
	}
	if (size == count)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void paragraph::operator+()
{
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] >= 'a' && arr[i] <= 'z')
		{
			arr[i] = arr[i] - 32;
		}
	}
}
void paragraph::operator-()
{
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] >= 'A' && arr[i] <= 'Z')
		{
			arr[i] = arr[i] + 32;
		}
	}
}
int paragraph::compdecompcheck()
{
	int aa = 0;
	for (int i = 0; i < size; i++)
	{
		if ((arr[i] >= 'A' && arr[i] <= 'Z') || (arr[i] >= 'a' && arr[i] <= 'z'))
		{
			aa++;
		}
	}
	if (aa > 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	return aa;
}
int paragraph::fontcheck()
{
	int count = 0;
		for (int i = 0; i < size; i++)
		{
			if ((arr[i] >= 'A' && arr[i] <= 'Z'))
			{
				count++;
			}
		}
		if (count > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
  
}
int paragraph::Count_English_Char()
{
	
	int aa = 0;
	for (int i = 0; i < size; i++)
	{
		if ((arr[i] >= 'A' && arr[i] <= 'Z') || (arr[i] >= 'a' && arr[i] <= 'z'))
		{
			aa++;
		}
	}
	sum = sum + aa;
	return aa;
}
int paragraph::Count_Punctuation_Char()
{
	int saz = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == '.' || arr[i] == ',' || arr[i] == ':' || arr[i] == ';' || arr[i] == '?'||arr[i] == '-')
		{
			saz++;
		}
	}
	sum = sum + saz;
	return saz;
}
void paragraph::operator%(int key)
{
	int flag1 = 0;
	int flag2 = 0;
	for (int i = 0; i < this->size-2; i++)
	{
		for (int j = 1; j <= key; j++)
		{
			if (arr[i] == ' ')
			{

			}
			else if ((arr[i] >= 65 && arr[i] <90)||(arr[i] >= 97 && arr[i] < 122))
			{
				arr[i] = arr[i] + 1;
			}
			else 
			{
				if (arr[i] > 90 && arr[i] <= 96)
				{
					arr[i] = 65;
					arr[i] = arr[i] + (key - j);
					break;
				}
				else
				{
					arr[i] = 97;
					arr[i] = arr[i] + (key - j);
					break;
				}
			}
		}
	}
}
void paragraph::operator*(int key)
{
	int flag1 = 0;
	int flag2 = 0;
	for (int i = 0; i < size-2; i++)
	{
		for (int j = 1; j <= key; j++)
		{
			if (arr[i] == ' ')
			{

			}
			 else if ((arr[i] > 65 && arr[i] <= 90) || (arr[i] > 97 && arr[i] <= 122))
			{
				arr[i] = arr[i] - 1;
			}
			else
			{
				if (arr[i] > 90 && arr[i] <= 96)
				{
					arr[i] = 90;
					arr[i] = arr[i] - (key - j);
					break;
				}
				else
				{
					arr[i] = 122;
					arr[i] = arr[i] - (key - j);
					break;
				}
			}
		}
	}
}
paragraph paragraph::operator+(const paragraph& p2)const
{
	paragraph total;

	total.size = (this->size) + (p2.size);
	total.arr = new char[total.size + 1];
	int i = 0;
	for (i = 0; i < this->size - 1; i++)
	{
		total.arr[i] = this->arr[i];
	}
	int j = 0;
	total.arr[i] = ' ';
	i++;
	for (; i < total.size - 1; i++)
	{
		total.arr[i] = p2.arr[j];
		j++;
	}
	total.arr[total.size - 1] = '\0';
	return total;
}

void paragraph::show_cd()
{
	int sarr[2000] = {};
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == 'a' || arr[i] == 'A')
		{
			sarr[i] = '1';
		}
		if (arr[i] == 'b' || arr[i] == 'B')
		{
			sarr[i] = '2';
		}
		if (arr[i] == 'C' || arr[i] == 'c')
		{

			sarr[i] = '3';
		}
		if (arr[i] == 'D' || arr[i] == 'd')
		{
			sarr[i] = '4';
		}
		if (arr[i] == 'E' || arr[i] == 'e')
		{
			sarr[i] = '5';
		}
		if (arr[i] == 'F' || arr[i] == 'f')
		{
			sarr[i] = '6';
		}
		if (arr[i] == 'G' || arr[i] == 'g')
		{
			sarr[i] = '7';
		}
		if (arr[i] == 'H' || arr[i] == 'h')
		{
			sarr[i] = '8';
		}
		if (arr[i] == 'I' || arr[i] == 'i')
		{
			sarr[i] = '9';
		}
		if (arr[i] == 'j' || arr[i] == 'J')
		{
			sarr[i] = '10';
		}
		if (arr[i] == 'K' || arr[i] == 'k')
		{
			sarr[i] = '11';
		}
		if (arr[i] == 'L' || arr[i] == 'l')
		{
			sarr[i] = '12';
		}
		if (arr[i] == 'M' || arr[i] == 'm')
		{
			sarr[i] = '13';
		}
		if (arr[i] == 'N' || arr[i] == 'n')
		{
			sarr[i] = '14';
		}
		if (arr[i] == 'O' || arr[i] == 'o')
		{
			sarr[i] = '15';
		}
		if (arr[i] == 'P' || arr[i] == 'p')
		{
			sarr[i] = '16';
		}
		if (arr[i] == 'Q' || arr[i] == 'q')
		{

			sarr[i] = '17';
		}
		if (arr[i] == 'R' || arr[i] == 'r')
		{
			sarr[i] = '18';
		}
		if (arr[i] == 'S' || arr[i] == 's')
		{
			sarr[i] = '19';
		}
		if (arr[i] == 'T' || arr[i] == 't')
		{
			sarr[i] = '20';
		}
		if (arr[i] == 'U' || arr[i] == 'u')
		{
			sarr[i] = '21';
		}
		if (arr[i] == 'V' || arr[i] == 'v')
		{
			sarr[i] = '22';
		}
		if (arr[i] == 'w' || arr[i] == 'W')
		{
			sarr[i] = '23';
		}
		if (arr[i] == 'X' || arr[i] == 'x')
		{
			sarr[i] = '24';
		}
		if (arr[i] == 'Y' || arr[i] == 'y')
		{
			sarr[i] = '25';
		}
		if (arr[i] == 'z' || arr[i] == 'Z')
		{
			sarr[i] = '26';
		}
		if (arr[i] == ',')
		{
			sarr[i] = '0';
		}
		if (arr[i] == ' ')
		{
			sarr[i] = '00';
		}
		if (arr[i] == '.')
		{
			sarr[i] = '000';
		}
	}
	cout << endl;
	cout << "TEXT AFTER COMPRESION:" << endl;
	for (int l = 0; l < size; l++)
	{
		cout << sarr[l];
	}
}
int paragraph::check_cd()
{
	int c = 0;
	for (int i = 0; i < size; i++)
	{
		if ((arr[i] >= 'A' && arr[i] <= 'Z') || (arr[i] >= 'a' && arr[i] <= 'z'))
		{
			c++;
		}
	}
	if (c > 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int paragraph::length(char word[])//finding length of a char array
{
	int i = 0;
	for (i = 0; word[i] != '\0'; i++);

	return i;
}
bool paragraph::compare(char name[], char dname[])//comparing two arrays with each other
{
	if (length(name) == length(dname))
	{
		int i = 0;
		while (name[i] != '\0')
		{
			if (name[i] != dname[i])
			{
				return false;
			}
			i++;
		}
		return true;
	}
	return false;
}
bool paragraph:: is_dictionaryword(char arr[])
{
	char word[400] = { '\0' };
	ifstream iin;
	iin.open("Dictionary.txt", ios::in);
	while (iin >> word)
	{
		if (compare(word, arr))
		{
			return true;
		}
	}
	return false;
}
void paragraph::check_words()
{
	cout<<"SIZE is: "<<size<<endl;
	char word[400] = { '\0' };
	int i = 0;
	int j = 0;
	arr[size-1] = ' ';
	while (1)
	{
		if (i == size)
		{
			break;
		}
		for (; arr[i]!=' '; i++)
		{
			word[j] = arr[i];
			j++;
		}
		if (is_dictionaryword(word)==false)
		{
			cout << word << endl;
		}
		j = 0;
		for (int k = 0; k < 20; k++)
		{
			word[k] = '\0';
		}
		i++;
	}
}
int paragraph::Check_Encrypt_Dycrypt()
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if ((arr[i] >= 'A' && arr[i] <= 'Z') || (arr[i] >= 'a' && arr[i] <= 'z')||arr[i] == '.' || arr[i] == ',' || arr[i] == ':' || arr[i] == ';' || arr[i] == '?' || arr[i] == '-')
		{
			count++;
		}
	}
	if (count == sum)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
paragraph::~paragraph()
{
	/*delete[]data;
	data = nullptr;*/
	delete[]arr;
	arr = nullptr;
	size = 0;
}
