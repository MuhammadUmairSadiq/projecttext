#include "words.h"
#include "paragraph.h"
#include<fstream>
words::words()
{
	arr3 = nullptr;
	size3 = 0;
	count3 = 0;
	count4 = 0;
}
words::words(char*a3, int s3, int c3, int c4)
{
	arr3 = a3;
	size3 = s3;
	count3 = c3;
	count4 = c4;
}
void words::setarr3(char *a3)
{
	arr3 = new char[strlen(a3) + 1];
	strcpy_s(arr3, strlen(a3) + 1, a3);
}
char *words::getarr3()
{
	char *temp = new char[strlen(arr3) + 1];
	strcpy_s(temp, strlen(arr3) + 1, arr3);
	return temp;
}
void words::setsize3(int s3)
{
	size3 = s3;
}
int words::getsize3()
{
	return size3;
}
void words::setcount3(int c3)
{
	count3 = c3;
}
int words::getcount3()
{
	return count3;
}
void words::display2()
{
	ofstream fout1;
	fout1.open("frequency.txt",ios::app);
	for (int i = 0, m = 1, n = 0, k = 0; i < size3; i++)
	{

		if (arr3[i] == ' ' || arr3[i] == '\n')
		{
			count4++;
		}
		if (arr3[i] == '.')
		{
			count4++;
			n++;
			cout << endl;
			cout << "NUMBER OF WORDS IN SENTENCE " << n << " of " << "paragraph " << m << ":" << count4 << endl;
			fout1 << "NUMBER OF WORDS IN SENTENCE " << n << " of " << "paragraph " << m << ":" << count4 << endl;
			count4 = 0;

		}
		if ((arr3[i] == '\n' && arr3[i + 1] == '\n') || (i == size3 - 1))
		{
			i++;
			m++;
			n = 0;
			count4 = 0;
		}

	}
}
words::~words()
{
	delete[]arr3;
	arr3 = nullptr;
	size3 = 0;
	count3 = 0;
}
