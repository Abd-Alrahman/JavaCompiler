#include "MyParser.h"
#include <iostream>

MyParser::MyParser(void)
{
	this->st = new SymbolTable();
	this->errRecovery = new ErrorRecovery();
}

MyParser::~MyParser(void)
{
}


Variable* MyParser::insertVar(char* n, int lineNo, int colNo){
	Variable * v = st->insertVariableInCurrentScope(n);
	if(!v){
		cout << "Error variable " << n << " already defined!";
		this->errRecovery->errQ->enqueue(lineNo, colNo, "Variable is already declared", n);
	}
	cout << "Variable " << n << " has been created\n";
	return v;
}
Variable* MyParser::addVariableToCurrentScope(Variable* v){
	if(v){
		this->st->currScope->m->put(v->getName(), v);
	}
	return v;
}
//========= Types =================
Type * MyParser::createType(char* name, int lineno, int colno){
	Type* t = (Type*)this->st->currScope->m->get(name);
	if(t){
		this->errRecovery->errQ->enqueue(lineno, colno, "Class already exists", name);
		return 0;
	}
	t = new Type();
	t->setName(name);
	t->getScope()->parent = this->st->currScope;
	this->st->currScope->m->put(name, t);
	this->st->currScope = t->getScope();
	cout << "Class " << name << " has been created\n";
	return t;
}
Type * MyParser::finishTypeDeclaration(Type* t){
	this->st->currScope = this->st->currScope->parent;
	cout << "Class " << t->getName() << " has been closed\n";
	return t;
}

//========= Functions =================
Function * MyParser::createFunction(char* name, int lineno, int colno) {
	Function* f = (Function*)this->st->currScope->m->get(name);
	if (f) {
		this->errRecovery->errQ->enqueue(lineno, colno, "Function already exists", name);
		return 0;
	}
	f = new Function();
	f->setName(name);
	/*
	f->setIsStatic(isStatic);
	f->setIsFinal(isFinal);
	f->setModifier(modifier);
	f->setReturnType(returnType);
	*/
	f->getScope()->parent = this->st->currScope;
	this->st->currScope->m->put(name, f);
	this->st->currScope = f->getScope();
	cout << "Function " << name << " has been created\n";
	return f;
}
Function * MyParser::finishFunctionDeclaration(Function* f) {
	this->st->currScope = this->st->currScope->parent;
	cout << "Function " << f->getName() << " has been closed\n";
	return f;
}