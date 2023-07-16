#include<iostream>
#include<fstream>
#include "paragraph.h"
#include "sentence.h"
#include "words.h"
#include "character.h"
using namespace std;
int main()
{
	cout << endl;
	cout << "-----------------------------------------------TEXT PROCESSOR-----------------------------------------------------------" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;

	paragraph o, obj1, obj4,obj10,obj12;
	char arr[10000] = { '\0' };
	ifstream fin;
	ifstream fin2;
	fin2.open("input1.txt");
	fin.open("input1.txt");

	int i =0;
	while (!fin2.eof())
	{
		fin2 >> arr[i];
		i++;
	}
	o.setsize(i);
	fin2.close();
	fin >> noskipws;
	while (!fin.eof())
	{
		fin >> o;
	}
	fin.close();
	cout << endl;
	cout << o;
	cout << endl;
	sentence o1;
	o1.setarr2(o.getarr());
	o1.setsize2(o.getsize());
	o1.display();

	words o2;
	o2.setarr3(o.getarr());
	o2.setsize3(o.getsize());
	o2.display2();

	character o3;
	o3.setarr4(o.getarr());
	o3.setsize4(o.getsize());
	o3.display3();

		char arr1[10000]{ '\0' };
		ifstream fin3;
		ifstream fin4;
		fin4.open("input2.txt");
		fin3.open("input2.txt");

		fin4 >> noskipws;
		int j = 0;
		while (!fin4.eof())
		{
			fin4 >> arr[j];
			j++;
		}
		obj1.setsize(j);
		fin4.close();
		fin3 >> noskipws;
		while (!fin3.eof())
		{
			fin3>> obj1;
		}
		fin3.close();
		if (o==obj1==1)
		{
			cout << endl;
			cout << "(paragraph are  equal as we have checked two files with two obj of same class)" << endl;
		}
	    if((o!=obj1)==0)
		{
			cout << endl;
			cout << "(paragraph are not  equal as we have checked two files with two obj of same class)" << endl;
		}
		cout << endl;
	cout << "(the list of word not present in dictionay are)" << endl;
	cout << endl;
	o.check_words();
	cout << endl;
	if (o.fontcheck() == 1)
	{
		cout << "(data was in upper case after converting to lower case)" << endl;
		-o;
		cout << o;
	}
	else
	{
		cout << "(data was in lower case after converting to upper case)" << endl;
		+o;
		cout << o;
	}
	cout << endl;
	
	cout << endl;
	cout << endl;
	cout << "(the number of punactuation letters in paragraphs are)" << endl;
	cout << o.Count_Punctuation_Char();
	cout << endl;
	cout << "(the number alphabets in the paragraph)" << endl;
	cout << o.Count_English_Char();
	cout << endl;
	cout << endl;
	cout << "(paragraph after assignment opertor)" << endl;
	cout << endl;
	obj10 = obj1;
	cout << obj10;
	cout << endl;
	if (o.Check_Encrypt_Dycrypt() == 1)
	{
		cout << "(data is dycrpted after data inscription data is)" << endl;
		o % (2);
		cout << o;
		cout << endl;
	}
	else
	{
		cout << endl;
		cout << "(after data incripted after data disscription data is)" << endl;
		o* (2);
		cout << o;
		cout << endl;
	}
	o*(2);
	cout << endl;
	cout << endl;
	cout << "(the paragraph after + uniary operator)" << endl;
	obj12 = o + obj1;
	cout << obj12;
	cout << endl;
	cout << endl;
	if (o.check_cd() == 1)
	{
		cout << "data is in decompressed form" << endl;
	}
	else
	{
		cout << "data is in compressed form" << endl;
	}
	o.show_cd();
}