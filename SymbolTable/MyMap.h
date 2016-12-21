#pragma once
#define MAX_LENGTH 71
#include <iostream>
class MapElem {
private:
	char* name;
	void * elem;
	MapElem * next;
	enum structure strc;
public:
	void setName(char* name);
	char* getName();
	void setElem(void* elem);
	void* getElem();
	MapElem* getNext();
	void setNext(MapElem * newMapElem);
	void setStrc(structure strc);
	structure getStrc();
};

class MyMap
{
private:
	static const int mapLength = MAX_LENGTH;
	int hash(char* name);
public:
	MapElem * arr[mapLength];
	MyMap(void);
	~MyMap(void);
	void put(char* name, void* item, enum structure strc);
	void* get(char* name);
};
