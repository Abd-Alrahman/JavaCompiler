#include "MyParser.h"
#include <iostream>
//============ Modifier =================
Modifier::Modifier() {
	this->returnType = new char[255];
	this->alternativeReturnType = new char[255];
	this->returnType[0] = '\0';
	this->alternativeReturnType[0] = '\0';
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
	this->alternativeReturnType = new char[255];
	strcpy(this->alternativeReturnType, m->alternativeReturnType);
}

Modifier::~Modifier() {}

void Modifier::reset() {
	this->returnType = new char[255];
	this->alternativeReturnType = new char[255];
	this->returnType[0] = '\0';
	this->alternativeReturnType[0] = '\0';
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

void Modifier::setIsStatic(bool isStatic) {
	this->isStatic = isStatic;
}

void Modifier::setIsFinal(bool isFinal) {
	this->isFinal = isFinal;
}

void Modifier::setIsAbstract(bool isAbstract) {
	this->isAbstract = isAbstract;
}

void Modifier::setIsNative(bool isNative) {
	this->isNative = isNative;
}

void Modifier::setIsSynchronized(bool isSynchronized) {
	this->isSynchronized = isSynchronized;
}

void Modifier::setIsTransient(bool isTransient) {
	this->isTransient = isTransient;
}

void Modifier::setIsVolatile(bool isVolatile) {
	this->isVolatile = isVolatile;
}

void Modifier::setReturnType(char* returnType) {
	this->returnType[0] = '\0';
	strcat(this->returnType, returnType);
}

void Modifier::setReturnAlternativeType(char* alternativeReturnType) {
	this->alternativeReturnType[0] = '\0';
	strcat(this->alternativeReturnType, alternativeReturnType);
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

bool Modifier::getIsFinal() {
	return this->isFinal;
}

bool Modifier::getIsAbstract() {
	return this->isAbstract;
}

bool Modifier::getIsNative() {
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

char* Modifier::getAlternativeReturnType() {
	return this->alternativeReturnType;
}

//============ MyParser =================
int MyParser::lastId = 0;

MyParser::MyParser(void)
{
	this->lastType = NULL;
	this->st = new SymbolTable();
	this->errRecovery = new ErrorRecovery();
	this->names = new char*[20];
	this->pl = new ParamList();
	this->methodBody = false;
	this->defaultParam = false;
	this->defaultParamState = false;
	this->rawClassName = new char[255];
	this->rawClassName[0] = '\0';
	this->initNames();
	Parameter::setLastId(0);
	lastIdInc();
}

MyParser::~MyParser(void) {}

void MyParser::initNames() {
	for (int i = 0; i < (sizeof(this->names) / sizeof(**this->names)); i++)
	{
		this->names[i] = new char[255];
		this->names[i][0] = '\0';
	}
}

int MyParser::lastIdInc() {
	return ++MyParser::lastId;
}

void MyParser::setLastId(int lastId) {
	MyParser::lastId = lastId;
}

int MyParser::getLastId() {
	return MyParser::lastId;
}

//========= Variable =================
Variable** MyParser::insertVar(int lineNo, int colNo, Modifier* m) {
	Variable** vars = new Variable*[20];
	for (int j = 0; j < 20; j++)
	{
		vars[j] = NULL;
	}
	for (int i = 0; i < (sizeof(this->names) / sizeof(**this->names)); i++)
	{
		if (this->names[i] && this->names[i][0]) {
			Variable * v = st->insertVariableInCurrentScope(this->names[i], m, lineNo, colNo, this->errRecovery);
			vars[i] = v;
			cout << "=================================================\n";
			if (!v) {
				this->errRecovery->errQ->enqueue(lineNo, colNo, "Variable is already declared", v->getName());
				return NULL;
			}
			if (m->getReturnType() && !m->getReturnType()[0]) {
				this->errRecovery->errQ->enqueue(lineNo, colNo, "Error: missing return type for variable", v->getName());
			}
			cout << "Variable " << v->getName() << " has been created\n";
			cout << "with return type " << v->getType() << endl;
			if (v->getIsFinal())
				cout << " and it is Final" << endl;
			cout << "=================================================\n";
		}
		else {
			m->reset();
			return vars;
		}
	}
}
Variable* MyParser::addVariableToCurrentScope(Variable* v) {
	if (v) {
		this->st->currScope->m->put(v->getName(), v, LOCALVARIABLE);
	}
	return v;
}

//============== Parameter =================
Parameter* MyParser::insertParam(char* name, int lineNo, int colNo, Modifier* m) {
	if (this->defaultParamState && !this->defaultParam) {
		this->errRecovery->errQ->enqueue(lineNo, colNo, "Error: Argument must have default value", name);
		return NULL;
	}
	if (this->defaultParam) {
		this->errRecovery->stateQ->enqueue(lineNo, colNo, "State: Default parameter state", name);
		this->defaultParamState = true;
	}
	Parameter * p = st->createParam(name, m, errRecovery);
	char* paramName = new char[255];
	if (p && p->strc == PARAMETER) {
		strcpy(paramName, p->getName());
		p = this->pl->add(p);
		if (!p) {
			this->errRecovery->errQ->enqueue(lineNo, colNo, "Error: Parameter is already declared", paramName);
			return NULL;
		}
		else {
			this->errRecovery->stateQ->enqueue(lineNo, colNo, "State: Parameter has been inserted in Symbol Table ", p->getName());
			return p;
		}

	}
	return p;
}

//========= Data Member =================
DataMember** MyParser::insertMem(int lineNo, int colNo, Modifier* m) {
	DataMember** members = new DataMember*[20];
	for (int j = 0; j < 20; j++){
		members[j] = NULL;
	}

	for (int i = 0; i < (sizeof(this->names) / sizeof(**this->names)); i++)
	{
		if (this->names[i] && this->names[i][0]) {
			// Check for native, abstract and synchronized.
			DataMember * d = st->insertDataMemberInCurrentScope(this->names[i], m, lineNo, colNo);
			members[i] = d;
			cout << members[i]->getName();
			if (m->getIsAbstract() || m->getIsNative() || m->getIsSynchronized()) {
				this->errRecovery->errQ->enqueue(lineNo, colNo, "Modifier native, abstract & synchronized are not allowed here", "");
				m->reset();
				return NULL;
			}
			cout << "==============================================\n";
			if (!d) {
				this->errRecovery->errQ->enqueue(lineNo, colNo, "Data member is already declared", this->names[i]);
				m->reset();
				return NULL;
			}
			
			// Checking if function has different modifiers
			if (d->illegalCombinationOfModifiers()) {
				this->errRecovery->errQ->enqueue(lineNo, colNo, "Illegal combination of modifiers", "");
				m->reset();
				return NULL;
			}
			d->printDetails();
		}
		else {
			m->reset();
			return members;
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
Type * MyParser::createType(char* name, int lineNo, int colNo, Modifier* m, char* inheritedTypeName, bool isInner) {
	Type* t = (Type*)this->st->getTypeParent(name);

	// Resetting count id
	Function::setLastId(0);

	if (t && t->strc == TYPE) {
		this->errRecovery->errQ->enqueue(lineNo, colNo, "Class already exists", name);
		return 0;
	}

	t = new Type();

	// Getting last created type
	this->lastType = t;

	// Set class data
	if (!this->setTypeData(t, name, m, lineNo, colNo, inheritedTypeName, isInner)) {
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

Type * MyParser::finishTypeDeclaration(Type* t, bool isInner) {
	if (t && t->strc == TYPE) {
		// Size
		t->setSize(DataMember::getLastId() * 8);
		DataMember::setLastId(0);
		if (!isInner) {
			// Creating default constructor for class if doesn't exist.
			Function* f = (Function*)this->st->currScope->m->get(t->getName());
			if (f && f->strc != FUNCTION) {
				goto constructor;
			}
			if (!f) {
			constructor:Function* f = new Function();
				f->setId(Function::getLastId());
				f->setIsPublic(true);
				f->setIsConstructor(true);
				f->setName(t->getName());
				char* label = new char[255];
				strcpy(label, t->getName());
				strcat(label, "_");
				strcat(label, t->getName());
				f->setLabel(label);
				this->st->currScope->m->put(f->getName(), f, FUNCTION);

				cout << "==========================================================\n";
				cout << "Default constructor has been created with name: " << f->getName() << endl;
				cout << "==========================================================\n";
			}
		}
		if (this->st->currScope && this->st->currScope->parent)
			this->st->currScope = this->st->currScope->parent;
	}
	if (t)
		cout << "=============== Class " << t->getName() << " closed ================" << endl;
	return t;
}

bool MyParser::setTypeData(Type* t, char* name, Modifier* m, int lineNo, int colNo, char* inheritedTypeName, bool isInner) {
	// Setting class modifiers
	t->setName(name); t->setParentName(m->getReturnType());
	t->setFileName(this->rawClassName);
	t->setIsPublic(m->getIsPublic()); t->setIsPrivate(m->getIsPrivate()); t->setIsProtected(m->getIsProtected());
	t->setIsFinal(m->getIsFinal()); t->setIsStatic(m->getIsStatic());
	t->setIsAbstract(m->getIsAbstract());
	t->colNo = colNo; t->rowNo = lineNo;

	// Default inheritance from Object class
	if (t->getParentName() && !t->getParentName()[0] && (strcmp(t->getName(), "Object") != 0)) {
		t->setParentName("Object");
	}

	if (isInner && (m->getIsPublic() || m->getIsPrivate() || m->getIsProtected())) {
		this->errRecovery->errQ->enqueue(lineNo, colNo, "Error: Class can't has access modifiers!", t->getName());
	}

	// Modifiers are not explicitly written
	if (m->getIsPrivate() == false && m->getIsProtected() == false && m->getIsPublic() == false) {
		t->setIsPublic(true);
	}

	// Check File Name
	if (this->st->currScope == this->st->rootScope) {
		if (this->rawClassName && this->rawClassName[0] && t->getIsPublic()) {
			if (strcmp(t->getName(), this->rawClassName) != 0) {
				this->errRecovery->errQ->enqueue(lineNo, colNo, "Error: Class name does not match file name!", t->getName());
			}
		}
	}

	// Check if outer class is public
	if ((this->st->currScope == this->st->rootScope) && !t->getIsPublic()) {
		this->errRecovery->errQ->enqueue(lineNo, colNo, "Modifier private is not allowed here", "");
		cout << "Error: Modifier private/protected is not allowed here\n";
		return false;
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
Function * MyParser::createFunction(char* name, int lineNo, int colNo, Modifier* m) {
	Function* f = new Function();

	Parameter::setLastId(0);

	if (!this->setMethodData(f, name, m, lineNo, colNo)) {
		// Resetting the modifier
		m->reset();
		return 0;
	}

	// Resetting id counting
	Variable::setLastId(f->pl->size);

	f->generateLabel(this->lastType);
	// Check for overloading state
	Function* existedFunc = (Function*)this->st->currScope->m->get(name);
	if (existedFunc && existedFunc->strc == FUNCTION) {
		if (f->isOverloadingState(existedFunc)) {
			char* underWithSize = new char[3];
			char* plSize = new char[2];
			strcpy(underWithSize, "_");
			itoa(f->pl->size, plSize, 10);
			strcat(underWithSize, plSize);

			f->setLabel(underWithSize);
			this->errRecovery->stateQ->enqueue(lineNo, colNo, "State: Overloading state! in method ", name);
			goto jmpOverReturnLbl;
		}
		m->reset();
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

Function * MyParser::finishFunctionDeclaration(Function* f, bool methodBody) {
	if (f) {
		// Size
		f->setSize(Variable::getLastId() * 8);
		cout << "=============== Function " << f->getName() << " closed ================" << endl;
		int methodBodyState = f->checkMethodBody(methodBody, this->errRecovery);
		if (methodBodyState == 0) {
			this->errRecovery->errQ->enqueue(f->rowNo, f->colNo, "Error: Abstracts & native methods can not have a body", f->getName());
		}
		else if (methodBodyState == 1) {
			this->errRecovery->errQ->enqueue(f->rowNo, f->colNo, "Error: Missing method body", f->getName());
		}
		this->st->currScope = this->st->currScope->parent;
	}
	return f;
}

bool MyParser::setMethodData(Function* f, char* name, Modifier* m, int lineNo, int colNo) {
	// Setting function modifiers
	f->setName(name);
	f->setIsPublic(m->getIsPublic()); f->setIsPrivate(m->getIsPrivate()); f->setIsProtected(m->getIsProtected());

	f->colNo = colNo; f->rowNo = lineNo;

	// Modifiers are not explicitly written
	if (m->getIsPrivate() == false && m->getIsProtected() == false && m->getIsPublic() == false) {
		f->setIsPublic(true);
	}
	f->setIsStatic(m->getIsStatic()); f->setIsAbstract(m->getIsAbstract()); f->setIsFinal(m->getIsFinal());
	f->setIsTransient(m->getIsTransient()); f->setIsSynchronized(m->getIsSynchronized()); f->setIsVolatile(m->getIsVolatile());
	f->setIsNative(m->getIsNative());
	f->setReturnType(m->getReturnType());

	// Set Object Method ID
	if (!f->getIsStatic()) {
		f->setId(Function::getLastId());
	}
	else {
		Function::setLastId(Function::getLastId() - 1);
		f->setId(MyParser::getLastId());
		MyParser::lastIdInc();
	}

	// Checking if function has different modifiers
	if (f->illegalCombinationOfModifiers()) {
		this->errRecovery->errQ->enqueue(lineNo, colNo, "Error: Illegal combination of modifiers", f->getName());
		return false;
	}

	// Adding parameters List
	if (!this->pl->isEmpty()) {
		f->pl = new ParamList(this->pl);
	}

	// Resetting MyParser default parameter data members
	this->defaultParam = false;
	this->defaultParamState = false;

	// Checking if function is constructor
	if (this->st->currScope && this->st->currScope->parent) {
		Type* t = (Type*)this->st->currScope->parent->m->get(name);
		if (t && t->strc == TYPE) {
			if (strcmp(t->getName(), name) == 0 && (m->getReturnType() && !m->getReturnType()[0])) {
				if (f->constructorModifiersError()) {
					this->errRecovery->errQ->enqueue(lineNo, colNo, "Error: Illegal combination of Constructor Modifiers", f->getName());
					return false;
				}
				else {
					f->setIsConstructor(true);
				}
			}
			else {
				f->setIsConstructor(false);
			}
		}
		else {
			f->setIsConstructor(false);
		}
	}

	// Missing Return Type
	if (!f->getIsConstructor() && f->getReturnType() && !f->getReturnType()[0]) {
		this->errRecovery->errQ->enqueue(lineNo, colNo, "Error: Missing return type", f->getName());
	}

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