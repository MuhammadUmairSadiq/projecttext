#include "character.h"
#include "paragraph.h"
#include<fstream>
character::character()
{
	arr4 = nullptr;
	size4 = 0;
	count5 = 0;
	count6 = 0;
}
character::character(char*a3, int s3, int c3, int c4)
{
	arr4 = a3;
	size4 = s3;
	count5 = c3;
	count6 = c4;
}
void character::setarr4(char *a4)
{
	arr4 = new char[strlen(a4) + 1];
	strcpy_s(arr4, strlen(a4) + 1, a4);
}
char *character::getarr4()
{
	char *temp = new char[strlen(arr4) + 1];
	strcpy_s(temp, strlen(arr4) + 1, arr4);
	return temp;
}
void character::setsize4(int s4)
{
	size4 = s4;
}
int character::getsize4()
{
	return size4;
}
void character::setcount5(int c5)
{
	count5 = c5;
}
int character::getcount5()
{
	return count5;
}
void character::display3()
{
	ofstream fout1;
	fout1.open("frequency.txt", ios::app);
	for (int i = 0, m = 1, n = 1, c = 0; i < size4; i++)
	{
		if (arr4[i] != ' ' && arr4[i] != '\n')
		{
			count6++;
		}
		if (arr4[i] == ','||arr4[i] == '.')
		{
			count6--;
		}
		if (arr4[i] == ' ' || (arr4[i] == '\n' && arr4[i+1] != '\n') )
		{
				
			c++;
			cout << endl;
		    cout << "NUMBER OF CHARACTERS IN WORD " << c << " OF " << "SENTENCE " << n << " OF paragraph " << m << ": "<< count6 << endl;
			fout1 << "NUMBER OF CHARACTERS IN WORD " << c << " OF " << "SENTENCE " << n << " OF paragraph " << m << ": " << count6 << endl;
			count6 = 0;
		}
			if (arr4[i] == '.')
			{
				n++;
				c = 0;
			}

		if ((arr4[i] == '\n' && arr4[i + 1] == '\n') || (i == size4 - 1))
		{
			i++;
			m++;
			n = 1;
			c = 0;
			count6 = 0;
		}

	}
	
}
character::~character()
{
	delete[]arr4;
	arr4 = nullptr;
	size4 = 0;
	count5 = 0;
}