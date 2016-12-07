#include<string.h>
#include <iostream>
using namespace std;
class ErrRecItem {
public:
	int lineNo;
	int colNo;
	char* txt;
	char* var;
	ErrRecItem * next;
}; 

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

class ErrRecQueue {
public:
	ErrRecItem * front;
	ErrRecItem * tail;
	void enqueue(int lineNo, int colNo, char* txt, char* varName)
	{
		ErrRecItem * item = new ErrRecItem();
		item->colNo = colNo;
		item->lineNo = lineNo;
		item->txt = new char[255];
		item->txt[0] = '\0';
		strcat(item->txt, txt);
		item->var = new char[255];
		item->var[0] = '\0';
		strcat(item->var, varName);
		if(front == 0){
			front = tail = item;
		}
		else {
			tail->next = item;
			tail = item;
		}
	}
	ErrRecItem * dequeue()
	{
		ErrRecItem * ret = 0;
		if(front != 0)
		{
			ret = front;
			if(front == tail)
			{
				front = tail = 0;
			}
			else
	     	{
				front = front->next;
		    }
		}
		
		return ret;
	}
	int isEmpty()
	{
		if(front == 0 )
			return 1;
		else
			return 0;
	}
};
class ErrorRecovery
{
public:
	ErrRecQueue * errQ;
	ErrRecQueue * warnQ;
	ErrorRecovery(void)
	{
		this->errQ = new ErrRecQueue();
		this->warnQ = new ErrRecQueue();
	}
	~ErrorRecovery(void);
	void printErrQueue()
	{
		while(!errQ->isEmpty()) {
			ErrRecItem * e = errQ->dequeue();
			cout<<"Error: ["<<e->lineNo<<","<<e->colNo<<"]   "<<e->txt<<",  "<<e->var<<"\n";
		}
		while(!warnQ->isEmpty()) {
			ErrRecItem * e = warnQ->dequeue();
			cout<<"Warning: ["<<e->lineNo<<","<<e->colNo<<"]   "<<e->txt<<",  "<<e->var<<"\n";
		}
	}
};
#endif