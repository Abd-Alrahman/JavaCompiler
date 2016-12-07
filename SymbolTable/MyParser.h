#pragma once
#ifndef __My_Parser__
#define __My_Parser__
#include "SymbolTable.h"
#include "../ErrorRecovery/ErrorRecovery.h"
//===================== Data Structures From Help in Yacc ==============


//======================================================================
class MyParser
{
public:
	SymbolTable * st;
	ErrorRecovery * errRecovery;
	MyParser(void);
	~MyParser(void);
	Variable* insertVar(char* n, int lineNo, int colNo);
	Variable* addVariableToCurrentScope(Variable* v);
	Type * createType(char* name, int lineno, int colno);
	Type * finishTypeDeclaration(Type* t);

};
#endif