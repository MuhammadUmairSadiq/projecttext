#pragma once
#include<iostream>
using namespace std;
class paragraph
{
private:
	char *arr;
	int size = 0;
	int sum = 0;
	int* data;
public:
	paragraph();
	paragraph(char*, int);
	paragraph(const paragraph&obj);
	void setarr(char *ar);
	void setsize(int);
	int getsize();
	char *getarr();
	friend istream& operator >>(istream& input, paragraph&obj);
	friend ostream& operator << (ostream& output, paragraph&obj);
	int operator==(paragraph&);
	bool operator!=(paragraph&);
	void operator+();
	void operator-();
	int check_cd();
	void show_cd();
	int compdecompcheck();
	void check_words();
	int fontcheck();
	int Count_English_Char();
	int Count_Punctuation_Char();
	int length(char word[]);
	bool is_dictionaryword(char arr[]);
	bool compare(char name[], char dname[]);
	void is_dictionaryword();
	int Check_Encrypt_Dycrypt();
	void operator%(int);
	void operator*(int);
	void fun();
	paragraph operator+(const paragraph& p2)const;
	void operator=(paragraph const&obj);
	paragraph operator==(paragraph const&obj);
	~paragraph();
};

