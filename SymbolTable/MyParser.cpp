#include "MyParser.h"
#include <iostream>
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

Modifier::Modifier(Modifier* m) {
	this->isPublic = m->isPublic;
	this->isPrivate = m->isPrivate;
	this->isProtected = m->isProtected;
	this->isStatic = m->isStatic;
	this->isFinal = m->isFinal;
	this->isAbstract = m->isAbstract;
	this->isSynchronized = m->isSynchronized;
	this->isVolatile = m->isVolatile;
	this->isTransient = m->isTransient;
	this->isNative = m->isNative;
	this->returnType = new char[255];
	strcpy(this->returnType, m->returnType);
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


MyParser::MyParser(void)
{
	this->st			= new SymbolTable();
	this->errRecovery	= new ErrorRecovery();
	this->helper		= new Helper();
	this->names			= new char*[20];
	this->parameters	= new Parameter*[];
	this->pl			= new ParamList();
	this->initNames();
}

MyParser::~MyParser(void) {}

void MyParser::initNames() {
	for (int i = 0; i < (sizeof(this->names) / sizeof(**this->names)); i++)
	{
		this->names[i]	  = new char[255];
		this->names[i][0] = '\0';
	}
}

void MyParser::initParameters() {
	for (int i = 0; i < (sizeof(this->parameters) / sizeof(**this->parameters)); i++)
	{
		this->parameters[i] = NULL;
	}
}
//========= Variable =================
void MyParser::insertVar(int lineNo, int colNo, Modifier* m) {
	for (int i = 0; i < (sizeof(this->names) / sizeof(**this->names)); i++)
	{
		if (this->names[i] && this->names[i][0]) {
			Variable * v = st->insertVariableInCurrentScope(this->names[i], m);
			cout << "=================================================\n";
			if (!v) {
				cout << "Error variable " << v->getName() << " already defined!";
				this->errRecovery->errQ->enqueue(lineNo, colNo, "Variable is already declared", v->getName());
				return;
			}
			cout << "Variable " << v->getName() << " has been created\n";
			cout << "with return type " << v->getType() << endl;
			if (v->getIsFinal())
				cout << " and it is Final" << endl;
			cout << "=================================================\n";
		}
		else {
			m->reset();
			return;
		}
	}
}
Variable* MyParser::addVariableToCurrentScope(Variable* v) {
	if(v) {
		this->st->currScope->m->put(v->getName(), v, LOCALVARIABLE);
	}
	return v;
}

//============== Parameter =================
Parameter* MyParser::insertParam(char* name, int lineNo, int colNo, Modifier* m) {
	Parameter * p = st->createParam(name, m);
	char* paramName = new char[255];
	strcpy(paramName, p->getName());
	p = this->pl->add(p);
	if (!p) {
		this->errRecovery->errQ->enqueue(lineNo, colNo, "Parameter is already declared", paramName);
	}
	else {
		cout << "Parameter " << p->getName() << " has been inserted in Parser with type " << p->getType();
		if (p->getIsFinal()) {
			cout << " and it's final";
		}
		cout << endl;
	}
	return p;
}

//========= Data Member =================
void MyParser::insertMem(int lineNo, int colNo, Modifier* m) {
	for (int i = 0; i < (sizeof(this->names) / sizeof(**this->names)); i++)
	{
		if (this->names[i] && this->names[i][0]) {
			DataMember * d = st->insertDataMemberInCurrentScope(this->names[i], m);
			cout << "==============================================\n";
			if (!d) {

				cout << "Error[" << lineNo << ", " << colNo << "]:  data member " << this->names[i] << " already defined!";
				this->errRecovery->errQ->enqueue(lineNo, colNo, "Data member is already declared", this->names[i]);
				return;
			}

			// Checking if function has different modifiers
			if (d->illegalCombinationOfModifiers()) {
				this->errRecovery->errQ->enqueue(lineNo, colNo, "Illegal combination of modifiers", "");
				cout << "==================================================\n";
				cout << "Error[" << lineNo << ", " << colNo << "]: Illegal combination of modifiers\n";
				cout << "==================================================\n";
				return;
			}
			d->printDetails();
		}
		else {
			m->reset();
			return;
		}
	}
}
DataMember* MyParser::addDataMemberToCurrentScope(DataMember* d) {
	if (d) {
		this->st->currScope->m->put(d->getName(), d, DATAMEMBER);
	}
	return d;
}
//========= Types =================
Type * MyParser::createType(char* name, int lineno, int colno, Modifier* m, char* inheritedTypeName) {
	Type* t = (Type*)this->st->currScope->m->get(name);

	if(t && t->strc == TYPE) {
		this->errRecovery->errQ->enqueue(lineno, colno, "Class already exists", name);
		return 0;
	}

	t = new Type();

	// Set class data
	if (!this->setTypeData(t, name, m, lineno, colno, inheritedTypeName)) {
		m->reset();
		return 0;
	}

	// Resetting Modifier
	m->reset();

	// Printing class details
	t->printDetails();

	t->getScope()->parent = this->st->currScope;
	this->st->currScope->m->put(name, t, TYPE);
	this->st->currScope = t->getScope();

	return t;
}

Type * MyParser::finishTypeDeclaration(Type* t) {
	if (t) {
		// Creating default constructor for class if doesn't exist.
		Function* f = (Function*)this->st->currScope->m->get(t->getName());
		if (!f) {
			Function* f = new Function();
			f->setIsPublic(true);
			f->setIsConstructor(true);
			f->setName(t->getName());
			this->st->currScope->m->put(f->getName(), f, FUNCTION);
			cout << "==========================================================\n";
			cout << "Default constructor has been created with name: " << f->getName() << endl;
			cout << "==========================================================\n";
		}
	}
	this->st->currScope = this->st->currScope->parent;
	if (t)
		cout << "=============== Class " << t->getName() << " closed ================" << endl;
	return t;
}

bool MyParser::setTypeData(Type* t, char* name, Modifier* m, int lineNo, int colNo, char* inheritedTypeName) {
	// Setting class modifiers
	t->setName(name); t->setParentName(m->getReturnType());
	t->setIsPublic(m->getIsPublic()); t->setIsPrivate(m->getIsPrivate()); t->setIsProtected(m->getIsProtected());
	t->setIsFinal(m->getIsFinal());
	t->setIsAbstract(m->getIsAbstract());

	// Modifiers are not explicitly written
	if (m->getIsPrivate() == false && m->getIsProtected() == false && m->getIsPublic() == false) {
		t->setIsPublic(true);
	}

	// Checking if class has different modifiers
	if (t->illegalCombinationOfModifiers()) {
		this->errRecovery->errQ->enqueue(lineNo, colNo, "Illegal combination of modifiers", "");
		cout << "==================================================\n";
		cout << "Error[" << lineNo << ", " << colNo << "]: Illegal combination of modifiers\n";
		cout << "==================================================\n";
		return false;
	}

	return true;
}

//========= Functions ===========
Function * MyParser::createFunction(char* name, Type* t, int lineNo, int colNo, Modifier* m) {
	Function* f = new Function();

	if (!this->setMethodData(f, t, name, m, lineNo, colNo)) {
		// Resetting the modifier
		m->reset();
		return 0;
	}

	Function* existedFunc = (Function*)this->st->currScope->m->get(name);
	if (existedFunc && existedFunc->strc == FUNCTION) {
		if (f->isOverloadingState(existedFunc)) {
			cout << "Overloading state!\n";
			goto jmpOverReturnLbl;
		}
		m->reset();
		cout << "========================================\n";
		cout << "Error[" << lineNo << ", " << colNo << "]: Function " << name << " already exists\n";
		cout << "========================================\n";
		this->errRecovery->errQ->enqueue(lineNo, colNo, "Function already exists ", name);
		return 0;
	}

	// Resetting the modifier
	jmpOverReturnLbl:m->reset();

	// Printing function details
	f->printDetails();

	// Move to new scope
	f->getScope()->parent = this->st->currScope;
	this->st->currScope->m->put(name, f, FUNCTION);
	this->st->currScope = f->getScope();

	// Return the function
	return f;
}
Function * MyParser::finishFunctionDeclaration(Function* f) {
	if (f)
		cout << "=============== Function " << f->getName() << " closed ================" << endl;
	this->st->currScope = this->st->currScope->parent;
	return f;
}

bool MyParser::setMethodData(Function* f, Type* type, char* name, Modifier* m, int lineNo, int colNo) {
	// Setting function modifiers
	f->setName(name);
	f->setIsPublic(m->getIsPublic()); f->setIsPrivate(m->getIsPrivate()); f->setIsProtected(m->getIsProtected());

	// Modifiers are not explicitly written
	if (m->getIsPrivate() == false && m->getIsProtected() == false && m->getIsPublic() == false) {
		f->setIsPublic(true);
	}
	f->setIsStatic(m->getIsStatic()); f->setIsAbstract(m->getIsAbstract()); f->setIsFinal(m->getIsFinal());
	f->setIsTransient(m->getIsTransient()); f->setIsSynchronized(m->getIsSynchronized()); f->setIsVolatile(m->getIsVolatile());
	f->setIsNative(m->getIsNative());
	f->setReturnType(m->getReturnType());

	// Checking if function has different modifiers
	if (f->illegalCombinationOfModifiers()) {
		this->errRecovery->errQ->enqueue(lineNo, colNo, "Illegal combination of modifiers", "");
		cout << "==================================================\n";
		cout << "Error[" << lineNo << ", " << colNo << "]: Illegal combination of modifiers\n";
		cout << "==================================================\n";
		return false;
	}

	// Adding parameters List
	if (!this->pl->isEmpty()) {
		f->pl = new ParamList(this->pl);
	}

	// Checking if function is constructor
	Type* t = (Type*)this->st->currScope->parent->m->get(name);
	if (t) {
		if (strcmp(t->getName(), name) == 0 && (m->getReturnType() && !m->getReturnType()[0])) {
			if (f->constructorModifiersError()) {
				cout << "==============================\n";
				cout << "Error in Constructor Modifiers\n";
				cout << "==============================\n";
				this->errRecovery->errQ->enqueue(lineNo, colNo, "Error in Constructor Modifiers", "");
				return false;
			}
			f->setIsConstructor(true);
		}
		else {
			f->setIsConstructor(false);
		}
	}
	else {
		f->setIsConstructor(false);
	}

	// TODO: abstract methods must be in abstract classes.

	return true;
}

char** MyParser::getNames() {
	return this->names;
}

void MyParser::setNames(char** namesArr) {
	this->names = namesArr;
}

void MyParser::addToNames(char* name) {
	for (int i = 0; i < (sizeof(this->names) / sizeof(**this->names)); i++)
	{
		if (this->names && this->names[i] && !this->names[i][0]) {
			strcat(this->names[i], name);
			return;
		}
	}
}

void MyParser::resetNames() {
	for (int i = 0; i < (sizeof(this->names) / sizeof(**this->names)); i++)
	{
		this->names[i][0] = '\0';
	}
}


void MyParser::addToParameters(Parameter* parameter, int lineNo, int colNo) {
}