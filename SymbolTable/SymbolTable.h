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
class Modifier {
private:
	bool isPublic;
	bool isPrivate;
	bool isProtected;
	bool isStatic;
	bool isFinal;
	bool isAbstract;
	bool isNative;
	bool isSynchronized;
	bool isTransient;
	bool isVolatile;
public:
	Modifier();
	~Modifier();
	void setIsPublic(bool isPublic);
	bool getIsPublic();
	void setIsPrivate(bool isPrivate);
	bool getIsPrivate();
	void setIsProtected(bool isProtected);
	bool getIsProtected();
	void setIsStatic(bool isStatic);
	bool getIsStatic();
	void setIsFinal(bool isFinal);
	bool getIsFinal();
	void setIsAbstract(bool isAbstract);
	bool getIsAbstract();
	void setIsNative(bool isNative);
	bool getIsNative();
	void setIsSynchronized(bool isSynchronized);
	bool getIsSynchronized();
	void setIsTransient(bool isTransient);
	bool getIsTransient();
	void setIsVolatile(bool isVolatile);
	bool getIsVolatile();
	void reset();
};
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
class Function {
private:
	char* name;
	bool isPublic;
	bool isPrivate;
	bool isProtected;
	bool isStatic;
	bool isFinal;
	bool isAbstract;
	bool isNative;
	bool isSynchronized;
	bool isTransient;
	bool isVolatile;
	Scope * scope;
	char* returnType;
public:
	Function();
	~Function();
	void setName(char* name);
	char* getName();
	void setIsPublic(bool isPublic);
	bool getIsPublic();
	void setIsPrivate(bool isPrivate);
	bool getIsPrivate();
	void setIsProtected(bool isProtected);
	bool getIsProtected();
	void setIsStatic(bool isStatic);
	bool getIsStatic();
	void setIsFinal(bool isFinal);
	bool getIsFinal();
	void setIsAbstract(bool isAbstract);
	bool getIsAbstract();
	void setIsNative(bool isNative);
	bool getIsNative();
	void setIsSynchronized(bool isSynchronized);
	bool getIsSynchronized();
	void setIsTransient(bool isTransient);
	bool getIsTransient();
	void setIsVolatile(bool isVolatile);
	bool getIsVolatile();
	void setReturnType(char* returnType);
	char* getReturnType();
	void setScope(Scope* m);
	Scope* getScope();
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