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
	Modifier(Modifier* m);
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
private:
	bool setMethodData(Function* f, char* name, Modifier* m, int lineNo, int colNo);
	void MyParser::initNames();
	void MyParser::initParameters();
public:
	SymbolTable * st;
	ErrorRecovery * errRecovery;
	Helper * helper;
	char** names;
	Parameter** parameters;
	MyParser(void);
	~MyParser(void);
	void insertVar(int lineNo, int colNo, Modifier* m);
	Variable* addVariableToCurrentScope(Variable* v);
	void insertMem(int lineNo, int colNo, Modifier* m);
	DataMember* addDataMemberToCurrentScope(DataMember* d);
	Parameter* createParam(char* name, int lineNo, int colNo, Modifier* m);
	Type * createType(char* name, int lineno, int colno, Modifier* m);
	Type * finishTypeDeclaration(Type* t);
	Function * createFunction(char* name, int lineno, int colno, Modifier* m);
	Function * finishFunctionDeclaration(Function* f);
	Parameter** getParameters();
	void addToParameters(Parameter* parameter, int lineNo, int colNo);
	char** getNames();
	void setNames(char** namesArr);
	void addToNames(char* name);
	void resetNames();
};
#endif