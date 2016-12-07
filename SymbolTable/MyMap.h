#pragma once
#define MAX_LENGTH 71
#include <iostream>
class MapElem{
private:
	char* name;
	void * elem;
	MapElem * next;
public:
	void setName(char* name);
	char* getName();
	void setElem(void* elem);
	void* getElem();
	MapElem* getNext();
	void setNext(MapElem * newMapElem);
};

class MyMap
{
private:
	static const int mapLength = MAX_LENGTH;
	MapElem * arr[mapLength];
	int hash(char* name);
public:
	MyMap(void);
	~MyMap(void);
	void put(char* name, void* item);
	void* get(char* name);
};
