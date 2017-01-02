#include "MyMap.h"

void MapElem::setName(char* name) {
	this->name = name;
}

char* MapElem::getName() {
	return this->name;
}

void MapElem::setElem(void* elem) {
	this->elem = elem;
}

void* MapElem::getElem() {
	return this->elem;
}

MapElem* MapElem::getNext(){
	return this->next;
}

void MapElem::setNext(MapElem * newMapElem) {
	this->next = newMapElem;
}

void MapElem::setStrc(structure strc) {
	this->strc = strc;
}

structure MapElem::getStrc() {
	return this->strc;
}

//-------------------------//
MyMap::MyMap(void)
{
	for(int i=0; i<this->mapLength; i++) {
		this->arr[i] = 0;
	}
}

MyMap::~MyMap(void)
{
}

int MyMap::hash(char* name){
	unsigned int i;
	int retVal = 0;
	for(i = 0 ; i < strlen(name); i++)
	{		
		retVal <<= 2;
		retVal ^= (int)(*name);		
		name++;
	}
	return (retVal%mapLength);	
}

void MyMap::put(char* name, void* element, enum structure strc) {
	int index = this->hash(name);
	MapElem * newMapElem = new MapElem();
	newMapElem->setName(name);
	newMapElem->setElem(element);
	newMapElem->setNext(0);
	newMapElem->setNext(this->arr[index]);
	newMapElem->setStrc(strc);
	this->arr[index] = newMapElem;
}

void* MyMap::get(char* name) {
	int index = this->hash(name);
	MapElem * temp = this->arr[index];
	while((temp != 0) && (strcmp(temp->getName(), name) != 0)){
		temp = temp->getNext();
	}
	if(temp == 0)
		return 0;
	else
		return temp->getElem();
}
