#pragma once
#ifndef __Symbol_Table__
#define __Symbol_Table__
#include "MyMap.h"
class Scope{
public:
	Scope();
	Scope * parent;
	MyMap * m;
};
//=============================
class Variable{
private: 
	char* name;
public:
	Variable();
	~Variable();
	void setName(char* n);
	char* getName();

};
class Type {
private:
	char* name;
	Type* inheritedType;
	Scope * scope;
public:
	Type();
	~Type();
	void setName(char* n);
	char* getName();
	void setInheritedType(Type* e);
	Type* getInheritedType();
	void setScope(Scope * m);
	Scope * getScope();
};
//=============================

class SymbolTable
{
public:
	Scope * currScope;
	Scope * rootScope;
	Variable * insertVariableInCurrentScope(char* name);
	Variable * getVariableFromCurrentScope(char* name);
	SymbolTable(void);
	~SymbolTable(void);
};
#endif