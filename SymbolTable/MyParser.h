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
	char* alternativeReturnType;
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
	void setReturnAlternativeType(char* alternativeReturnType);
	char* getAlternativeReturnType();
	void reset();
};
//======================================================================
class MyParser
{
private:
	Type* lastType;
	bool setMethodData(Function* f, char* name, Modifier* m, int lineNo, int colNo);
	bool setTypeData(Type* f, char* name, Modifier* m, int lineNo, int colNo, char* inheritedTypeName, bool isInner);
	void MyParser::initNames();
	void MyParser::initParameters();
	static int lastId;
public:
	char* rawClassName;
	SymbolTable * st;
	ErrorRecovery * errRecovery;
	char** names;
	ParamList* pl;
	bool methodBody;
	bool defaultParam;
	bool defaultParamState;
	MyParser(void);
	~MyParser(void);
	Variable** insertVar(int lineNo, int colNo, Modifier* m);
	Variable* addVariableToCurrentScope(Variable* v);
	DataMember** insertMem(int lineNo, int colNo, Modifier* m);
	DataMember* addDataMemberToCurrentScope(DataMember* d);
	Parameter* insertParam(char* name, int lineNo, int colNo, Modifier* m);
	Type * createType(char* name, int lineno, int colno, Modifier* m, char* inheritedTypeName, bool isInner = false);
	Type * finishTypeDeclaration(Type* t, bool isInner = false);
	Function * createFunction(char* name, int lineno, int colno, Modifier* m);
	Function * finishFunctionDeclaration(Function* f, bool methodBody);
	Parameter** getParameters();
	char** getNames();
	void setNames(char** namesArr);
	void addToNames(char* name);
	void resetNames();
	static void setLastId(int lastId);
	static int getLastId();
	static int lastIdInc();
};
#endif