#pragma once
#include "paragraph.h"
class words:public paragraph
{
private:
	char *arr3;
	int size3;
	int count3;
	int count4;
public:
	words();
	words(char*, int, int, int);
	void setarr3(char*);
	void setsize3(int);
	void setcount3(int);
	char *getarr3();
	int  getsize3();
	int  getcount3();
	void display2();
	~words();
};

