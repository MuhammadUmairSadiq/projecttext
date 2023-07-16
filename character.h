#pragma once
#include "paragraph.h"
class character :public paragraph
{
private:
	char *arr4;
	int size4;
	int count5;
	int count6;
public:
	character();
	character(char*, int, int, int);
	void setarr4(char*);
	void setsize4(int);
	void setcount5(int);
	char *getarr4();
	int  getsize4();
	int  getcount5();
	void display3();
	~character();
};