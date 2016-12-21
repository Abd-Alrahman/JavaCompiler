#pragma once
#ifndef __Symbol_Table__
#define __Symbol_Table__
#include "MyMap.h"

enum structure {
	TYPE = 0,
	FUNCTION,
	DATAMEMBER,
	LOCALVARIABLE,
	PARAMETER
};

class Scope {
public:
	Scope();
	Scope * parent;
	MyMap * m;
};
class Variable {
private: 
	char* name;
	char* type;
	bool isFinal;
public:
	Variable();
	~Variable();
	void setName(char* n);
	char* getName();
	void setType(char* type);
	char* getType();
	void setIsFinal(bool isFinal);
	bool getIsFinal();
	bool isPrimitiveType(char* type);
};
class DataMember {
private:
	char* name;
	char* type;
	bool isFinal;
	bool isStatic;
	bool isPublic;
	bool isPrivate;
	bool isProtected;
public:
	DataMember();
	~DataMember();
	void setName(char* n);
	char* getName();
	void setType(char* type);
	char* getType();
	void setIsPublic(bool isPublic);
	bool getIsPublic();
	void setIsPrivate(bool isPrivate);
	bool getIsPrivate();
	void setIsProtected(bool isProtected);
	bool getIsProtected();
	void setIsFinal(bool isFinal);
	bool getIsFinal();
	void setIsStatic(bool isStatic);
	bool getIsStatic();
	bool illegalCombinationOfModifiers();
	void printDetails();
};
class Type {
private:
	char* name;
	bool isPublic;
	bool isPrivate;
	bool isProtected;
	bool isFinal;
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
	bool isConstructor;
	Scope * scope;
	char* returnType;
public:
	Function();
	~Function();
	void printDetails();
	bool illegalCombinationOfModifiers();
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
	bool getIsConstructor();
	void setIsConstructor(bool isConstructor);
	Scope* getScope();
};
//=============================
class Modifier;
class SymbolTable
{
public:
	Scope * currScope;
	Scope * rootScope;
	Variable * insertVariableInCurrentScope(char* name, Modifier* m);
	Variable * getVariableFromCurrentScope(char* name);
	DataMember * insertDataMemberInCurrentScope(char* name, Modifier* m);
	DataMember * getDataMemberFromCurrentScope(char* name);
	void print(Scope* scope);
	SymbolTable(void);
	~SymbolTable(void);
};
#endif