#include "MyParser.h"
#include <iostream>

MyParser::MyParser(void)
{
	this->st = new SymbolTable();
	this->errRecovery = new ErrorRecovery();
	this->helper = new Helper();
}

MyParser::~MyParser(void)
{
}


//============ Modifier =================
Modifier::Modifier() {
	this->isPublic = false;
	this->isPrivate = false;
	this->isProtected = false;
	this->isStatic = false;
	this->isFinal = false;
	this->isAbstract = false;
	this->isSynchronized = false;
	this->isVolatile = false;
	this->isTransient = false;
	this->isNative = false;
	this->returnType = new char[255];
	this->returnType[0] = '\0';
}

Modifier::~Modifier() {}

void Modifier::reset() {
	this->isPublic = false;
	this->isPrivate = false;
	this->isProtected = false;
	this->isStatic = false;
	this->isFinal = false;
	this->isAbstract = false;
	this->isSynchronized = false;
	this->isVolatile = false;
	this->isTransient = false;
	this->isNative = false;
	this->returnType = new char[255];
	this->returnType[0] = '\0';
}

void Modifier::setIsPublic(bool isPublic) {
	this->isPublic = isPublic;
}

void Modifier::setIsPrivate(bool isPrivate) {
	this->isPrivate = isPrivate;
}

void Modifier::setIsProtected(bool isProtected) {
	this->isProtected = isProtected;
}

void Modifier::setIsStatic(bool isStatic){
	this->isStatic = isStatic;
}

void Modifier::setIsFinal(bool isFinal){
	this->isFinal = isFinal;
}

void Modifier::setIsAbstract(bool isAbstract){
	this->isAbstract = isAbstract;
}

void Modifier::setIsNative(bool isNative){
	this->isNative = isNative;
}

void Modifier::setIsSynchronized(bool isSynchronized) {
	this->isSynchronized = isSynchronized;
}

void Modifier::setIsTransient(bool isTransient){
	this->isTransient = isTransient;
}

void Modifier::setIsVolatile(bool isVolatile) {
	this->isVolatile = isVolatile;
}

void Modifier::setReturnType(char* returnType) {
	strcat(this->returnType, returnType);
}

bool Modifier::getIsPublic() {
	return this->isPublic;
}

bool Modifier::getIsPrivate() {
	return this->isPrivate;
}

bool Modifier::getIsProtected() {
	return this->isProtected;
}

bool Modifier::getIsStatic() {
	return this->isStatic;
}

bool Modifier::getIsFinal(){
	return this->isFinal;
}

bool Modifier::getIsAbstract(){
	return this->isAbstract;
}

bool Modifier::getIsNative(){
	return this->isNative;
}

bool Modifier::getIsSynchronized() {
	return this->isSynchronized;
}

bool Modifier::getIsTransient() {
	return this->isTransient;
}

bool Modifier::getIsVolatile() {
	return this->isVolatile;
}

char* Modifier::getReturnType() {
	return this->returnType;
}
//================Helper====================
Helper::Helper() {}
Helper::~Helper() {}

void Helper::brcktsCountInc() {
	this->bracketsCount++;
}

void Helper::brcktsCountDec() {
	this->bracketsCount--;
}

void Helper::setBracketsCount(int brcktsCount) {
	this->bracketsCount = brcktsCount;
}

int Helper::getBracketsCount() {
	return this->bracketsCount;
}


void MyParser::checkBrcktsEquality(int lineNo, int colNo) {
	if (this->helper->getBracketsCount() > 0) {
		this->errRecovery->errQ->enqueue(lineNo, colNo, "Unexpected end of file", "");
	}
	else if (this->helper->getBracketsCount() < 0)
	{
		this->errRecovery->errQ->enqueue(lineNo, colNo, "Unexpected {", "");
	}
}
//========= Variable =================
Variable* MyParser::insertVar(char* n, int lineNo, int colNo, Modifier* m) {
	Variable * v = st->insertVariableInCurrentScope(n, m);
	cout << "=================================================\n";
	if(!v) {
		cout << "Error variable " << n << " already defined!";
		this->errRecovery->errQ->enqueue(lineNo, colNo, "Variable is already declared", n);
	}
	cout << "Variable " << n << " has been created\n";
	cout << "with return type " << v->getType() << endl;
	if (v->getIsFinal())
		cout << "and it is Final" << endl;
	cout << "=================================================\n";
	return v;
}
Variable* MyParser::addVariableToCurrentScope(Variable* v) {
	if(v) {
		this->st->currScope->m->put(v->getName(), v);
	}
	return v;
}
//========= Data Member =================
/*
DataMember* MyParser::insertMem(char* n, int lineNo, int colNo, Modifier* m) {
	DataMember * d = st->insertDataMemberInCurrentScope(n);
	if (!d) {
		cout << "==============================================\n";
		cout << "Error data member " << n << " already defined!";
		this->errRecovery->errQ->enqueue(lineNo, colNo, "Data member is already declared", n);
	}
	cout << "Data member " << n << " has been created\n";
	cout << "With the following modifiers:\n";
	if (d->getIsFinal()) cout << "Final\n";
	if (d->getIsStatic()) cout << "Static\n";
	if (d->getIsPublic()) cout << "Public\n";
	if (d->getIsPrivate()) cout << "Private\n";
	if (d->getIsProtected()) cout << "Protected\n";
	cout << "and return type: " << d->getType() << endl;
	cout << "==============================================\n";
	return d;
}
DataMember* MyParser::addDataMemberToCurrentScope(DataMember* d) {
	if (d) {
		this->st->currScope->m->put(d->getName(), d);
	}
	return d;
}*/
//========= Types =================
Type * MyParser::createType(char* name, int lineno, int colno){
	Type* t = (Type*)this->st->currScope->m->get(name);
	cout << "=============== Class " << name << " opened ================" << endl;
	if(t) {
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
	if (t) {
		cout << "=============== Class " << t->getName() << " closed ================" << endl;
	}
	return t;
}

//========= Functions ===========
Function * MyParser::createFunction(char* name, int lineno, int colno, Modifier* m) {
	Function* f = (Function*)this->st->currScope->m->get(name);
	if (f) {
		cout << "========================================\n";
		cout << "Error[" << lineno << ", " << colno << "]: Function " << name << " already exists\n";
		cout << "========================================\n";
		this->errRecovery->errQ->enqueue(lineno, colno, "Function already exists ", name);
		return 0;
	}
	f = new Function();

	// Setting function modifiers
	f->setName(name);
	f->setIsPublic(m->getIsPublic()); f->setIsPrivate(m->getIsPrivate()); f->setIsProtected(m->getIsProtected());
	// Modifiers are not explicitly written
	if (m->getIsPrivate() == false && m->getIsProtected() == false) {
		f->setIsPublic(true);
	}
	f->setIsStatic(m->getIsStatic()); f->setIsAbstract(m->getIsAbstract()); f->setIsFinal(m->getIsFinal());
	f->setIsTransient(m->getIsTransient()); f->setIsSynchronized(m->getIsSynchronized()); f->setIsVolatile(m->getIsVolatile());
	f->setIsNative(m->getIsNative());
	f->setReturnType(m->getReturnType());

	// Checking if function is constructor
	Type* t = (Type*)this->st->currScope->parent->m->get(name);
	if (t) {
		if (strcmp(t->getName(), name) == 0) {
			f->setIsConstructor(true);
		}
		else {
			f->setIsConstructor(false);
		}
	}
	else {
		f->setIsConstructor(false);
	}

	// Resetting the modifier
	m->reset();

	// Move to new scope
	f->getScope()->parent = this->st->currScope;
	this->st->currScope->m->put(name, f);
	this->st->currScope = f->getScope();

	// Print function details
	cout << "=============== Function " << name << " opened ================" << endl;
	cout << "has been created ";
	cout << "with modifiers list:" << endl;
	if (f->getIsConstructor()) cout << "Constructor" << endl;
	if (f->getIsPublic()) cout << "Public" << endl;
	if (f->getIsPrivate()) cout << "Private" << endl;
	if (f->getIsProtected()) cout << "Protected" << endl;
	if (f->getIsFinal()) cout << "Final" << endl;
	if (f->getIsStatic()) cout << "Static" << endl;
	if (f->getIsAbstract()) cout << "Abstract" << endl;
	if (f->getIsNative()) cout << "Native" << endl;
	if (f->getIsSynchronized()) cout << "Synchronized" << endl;
	if (f->getIsTransient()) cout << "Transient" << endl;
	if (f->getIsVolatile()) cout << "Volatile" << endl;
	cout << "and Return Type: " << f->getReturnType() << endl;

	// Return the function
	return f;
}
Function * MyParser::finishFunctionDeclaration(Function* f) {
	if (f)
		cout << "=============== Function " << f->getName() << " closed ================" << endl;
	this->st->currScope = this->st->currScope->parent;
	return f;
}