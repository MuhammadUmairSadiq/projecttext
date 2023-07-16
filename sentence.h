#pragma once
#include "paragraph.h"
class sentence :public paragraph
{
private:
	char *arr2;
	int size2;
	int count1;
	int count2;
public:
	sentence();
	sentence(char*, int, int,int,char*, int);
	void setarr2(char*);
	void setsize2(int);
	void setcount1(int);
	char *getarr2();
	int  getsize2();
	int  getcount1();
	void display();
	~sentence();
};

