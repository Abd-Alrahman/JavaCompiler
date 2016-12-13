#pragma once
#ifndef __My_Parser__
#define __My_Parser__
#include "SymbolTable.h"
#include "../ErrorRecovery/ErrorRecovery.h"
//===================== Data Structures From Help in Yacc ==============
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
	char* returnType;
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
	void setReturnType(char* returnType);
	char* getReturnType();
	void reset();
};

class Helper {
private:
	int bracketsCount;
public:
	Helper();
	~Helper();
	void setBracketsCount(int brktsCount);
	int getBracketsCount();
	void brcktsCountInc();
	void brcktsCountDec();
};
//======================================================================
class MyParser
{
public:
	SymbolTable * st;
	ErrorRecovery * errRecovery;
	Helper * helper;
	MyParser(void);
	~MyParser(void);
	void checkBrcktsEquality(int lineNo, int colNo);
	Variable* insertVar(char* n, int lineNo, int colNo);
	Variable* addVariableToCurrentScope(Variable* v);
	/*
	DataMember* insertMem(char* n, int lineNo, int colNo, Modifier* m);
	DataMember* addDataMemberToCurrentScope(DataMember* d);*/
	Type * createType(char* name, int lineno, int colno);
	Type * finishTypeDeclaration(Type* t);
	Function * createFunction(char* name, int lineno, int colno);
	Function * finishFunctionDeclaration(Function* f, Modifier* m);
};
#endif