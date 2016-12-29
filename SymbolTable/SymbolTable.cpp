#include "SymbolTable.h"
#include "MyParser.h"
//============= Scope   ================
Scope::Scope() {
	this->m = new MyMap();
	this->parent = 0;
}
//============ Variable  ================
Variable::Variable() {
	this->name = new char[255];
	this->name[0] = '\0';
	this->type = new char[255];
	this->type[0] = '\0';
	this->isFinal = false;
}

Variable::~Variable() {}

void Variable::setName(char* n) {
	strcat(this->name, n);
}

char* Variable::getName() {
	return this->name;
}

void Variable::setType(char* type) {
	strcat(this->type, type);
}

char* Variable::getType() {
	return this->type;
}

void Variable::setIsFinal(bool isFinal) {
	this->isFinal = isFinal;
}

bool Variable::getIsFinal() {
	return this->isFinal;
}

bool Variable::isPrimitiveType(char* type) {
	char* primitives[] = { "boolean", "char", "byte", "short", "int", "long", "float", "double", "void" };
	for (int i = 0; i < (sizeof(primitives) / sizeof(*primitives)); i++)
	{
		if (strcmp(type, primitives[i]) == 0)
			return true;
	}
	return false;
}

//=======================================
//============ Data Member  ================
DataMember::DataMember() {
	this->name = new char[255];
	this->name[0] = '\0';
	this->type = new char[255];
	this->type[0] = '\0';
}

DataMember::~DataMember() {}

void DataMember::setName(char* n) {
	strcat(this->name, n);
}

char* DataMember::getName() {
	return this->name;
}

void DataMember::setType(char* type) {
	strcat(this->type, type);
}

char* DataMember::getType() {
	return this->type;
}

void DataMember::setIsPublic(bool isPublic) {
	this->isPublic = isPublic;
}

void DataMember::setIsPrivate(bool isPrivate) {
	this->isPrivate = isPrivate;
}

void DataMember::setIsProtected(bool isProtected) {
	this->isProtected = isProtected;
}

void DataMember::setIsFinal(bool isFinal) {
	this->isFinal = isFinal;
}

void DataMember::setIsStatic(bool isStatic) {
	this->isStatic = isStatic;
}

bool DataMember::getIsPublic() {
	return this->isPublic;
}

bool DataMember::getIsPrivate() {
	return this->isPrivate;
}

bool DataMember::getIsProtected() {
	return this->isProtected;
}

bool DataMember::getIsFinal() {
	return this->isFinal;
}

bool DataMember::getIsStatic() {
	return this->isStatic;
}

bool DataMember::illegalCombinationOfModifiers() {
	if ((this->isPublic && this->isPrivate) ||
		(this->isPublic && this->isProtected) ||
		(this->isProtected && this->isPrivate)) {
		return true;
	}
	return false;
}

void DataMember::printDetails() {
	cout << "Data member " << this->name << " has been created\n";
	cout << "With the following modifiers:\n";
	if (this->isFinal) cout << "Final\n";
	if (this->isStatic) cout << "Static\n";
	if (this->isPublic) cout << "Public\n";
	if (this->isPrivate) cout << "Private\n";
	if (this->isProtected) cout << "Protected\n";
	cout << "and return type: " << this->type << endl;
	cout << "==============================================\n";
}

//=======================================
//============== Type ===================
Type::Type() {
	this->name = new char[255];
	this->name[0] = '\0';
	this->scope = new Scope();
}
Type::~Type() {}
void Type::setName(char* n) {
	strcat(this->name,n);
}
char* Type::getName(){
	return this->name;
}
void Type::setInheritedType(Type* e) {
	this->inheritedType = e;
}
Type* Type::getInheritedType() {
	return this->inheritedType;
}
void Type::setScope(Scope * m) {
	this->scope = m;
}
Scope * Type::getScope() {
	return this->scope;
}
//=======================================
//=================Function==============
Function::Function(){
	this->name = new char[255];
	this->name[0] = '\0';
	this->returnType = new char[255];
	this->returnType[0] = '\0';
	this->scope = new Scope();
}

Function::~Function() {}

bool Function::illegalCombinationOfModifiers() {
	if ((this->isPublic && this->isPrivate) ||
		(this->isPublic && this->isProtected) ||
		(this->isProtected && this->isPrivate)) {
		return true;
	}
	return false;
}

void Function::printDetails() {
	// Print function details
	cout << "=============== Function " << this->name << " opened ================" << endl;
	cout << "has been created ";
	cout << "with modifiers list:" << endl;
	if (this->isConstructor) cout << "Constructor" << endl;
	if (this->isPublic) cout << "Public" << endl;
	if (this->isPrivate) cout << "Private" << endl;
	if (this->isProtected) cout << "Protected" << endl;
	if (this->isFinal) cout << "Final" << endl;
	if (this->isStatic) cout << "Static" << endl;
	if (this->isAbstract) cout << "Abstract" << endl;
	if (this->isNative) cout << "Native" << endl;
	if (this->isSynchronized) cout << "Synchronized" << endl;
	if (this->isTransient) cout << "Transient" << endl;
	if (this->isVolatile) cout << "Volatile" << endl;
	cout << "and Return Type: " << this->returnType << endl;
}

void Function::setName(char* name) {
	strcat(this->name, name);
}

void Function::setScope(Scope* m) {
	this->scope = m;
}

void Function::setReturnType(char* returnType) {
	strcat(this->returnType, returnType);
}

void Function::setIsPublic(bool isPublic) {
	this->isPublic = isPublic;
}

void Function::setIsPrivate(bool isPrivate) {
	this->isPrivate = isPrivate;
}

void Function::setIsProtected(bool isProtected) {
	this->isProtected = isProtected;
}

void Function::setIsStatic(bool isStatic) {
	this->isStatic = isStatic;
}

void Function::setIsFinal(bool isFinal) {
	this->isFinal = isFinal;
}

void Function::setIsAbstract(bool isAbstract) {
	this->isAbstract = isAbstract;
}

void Function::setIsNative(bool isNative) {
	this->isNative = isNative;
}

void Function::setIsSynchronized(bool isSynchronized) {
	this->isSynchronized = isSynchronized;
}

void Function::setIsTransient(bool isTransient) {
	this->isTransient = isTransient;
}

void Function::setIsVolatile(bool isVolatile) {
	this->isVolatile = isVolatile;
}

void Function::setIsConstructor(bool isConstructor) {
	this->isConstructor = isConstructor;
}

bool Function::getIsPublic() {
	return this->isPublic;
}

bool Function::getIsPrivate() {
	return this->isPrivate;
}

bool Function::getIsProtected() {
	return this->isProtected;
}

bool Function::getIsStatic() {
	return this->isStatic;
}

bool Function::getIsFinal() {
	return this->isFinal;
}

bool Function::getIsAbstract() {
	return this->isAbstract;
}

bool Function::getIsNative() {
	return this->isNative;
}

bool Function::getIsSynchronized() {
	return this->isSynchronized;
}

bool Function::getIsTransient() {
	return this->isTransient;
}

bool Function::getIsVolatile() {
	return this->isVolatile;
}

char* Function::getReturnType() {
	return this->returnType;
}

char* Function::getName() {
	return this->name;
}

Scope * Function::getScope() {
	return this->scope;
}

bool Function::getIsConstructor() {
	return this->isConstructor;
}
//=======================================
SymbolTable::SymbolTable(void) {
	this->rootScope = new Scope();
	this->currScope = this->rootScope;
}

SymbolTable::~SymbolTable(void) {
}

Variable * SymbolTable::insertVariableInCurrentScope(char* name, Modifier* m) {
	Variable * v = this->getVariableFromCurrentScope(name);
	if (v) {
		return 0;//item is exist previously
	}
	else {
		if (m->getIsAbstract() || m->getIsNative() || m->getIsPrivate() || m->getIsProtected() || m->getIsPublic() ||
			m->getIsStatic() || m->getIsSynchronized() || m->getIsTransient() || m->getIsVolatile()) {
			cout << "===========================================================\n";
			cout << "Local variable can't has access modifier other than final.\n";
			cout << "===========================================================\n";
		}
		v = new Variable();
		v->setName(name);
		if (v->isPrimitiveType(m->getReturnType())) {
			v->setType(m->getReturnType());
			cout << "Variable type is primitive" << endl;
		}
		else {
			Type* t = (Type*)this->currScope->parent->parent->m->get(m->getReturnType());
			if (t) {
				if (strcmp(t->getName(), m->getReturnType()) == 0) {
					v->setType(m->getReturnType());
					cout << "object has been created\n";
				}
				else {
					cout << "Class doesn't exist\n";
				}
			}
			else {
				cout << "Class doesn't exist\n";
			}
		}

		v->setIsFinal(m->getIsFinal());
		this->currScope->m->put(name, v, LOCALVARIABLE);
	}
	return v;
}

Variable * SymbolTable::getVariableFromCurrentScope(char* name){
	Variable * v = (Variable*)this->currScope->m->get(name);
	if(!v) {
		return 0;
	}
	return v;
}

/*
Variable * SymbolTable::getVariableFromCurrentScope(char* name){
	Variable * v = (Variable*)this->currScope->m->get(name);
	if (!v) {
		Scope * temp = this->currScope->parent;
		while (temp && !v){
			v = (Variable*)temp->m->get(name);
			temp = temp->parent;
		}
	}
	return v;
}*/
//================= Data Member ====================
DataMember * SymbolTable::insertDataMemberInCurrentScope(char* name, Modifier* m) {
	DataMember * d = (DataMember*)this->getDataMemberFromCurrentScope(name);
	if (d) {
		return 0;//item is exist previously
	}
	else {
		d = new DataMember();
		d->setName(name);
		d->setType(m->getReturnType());
		d->setIsStatic(m->getIsStatic());
		d->setIsFinal(m->getIsFinal());
		d->setIsPublic(m->getIsPublic()); d->setIsPrivate(m->getIsPrivate()); d->setIsProtected(m->getIsProtected());
		if (m->getIsPrivate() == false && m->getIsProtected() == false && m->getIsPublic() == false) {
			d->setIsPublic(true);
		}
		
		this->currScope->m->put(name, d, DATAMEMBER);
	}
	return d;
}

DataMember * SymbolTable::getDataMemberFromCurrentScope(char* name) {
	DataMember * d = (DataMember*)this->currScope->m->get(name);
	if (!d) {
		return 0;
	}
	return d;
}

void SymbolTable::print(Scope* scope) {
	if (scope) {
		for (int i = 0; i < 71; i++)
		{
			if (scope->m->arr[i]) {
				switch (scope->m->arr[i]->getStrc())
				{
				case TYPE: {
							   cout << "Class: " << scope->m->arr[i]->getName() << endl;
							   Type* type = (Type*)scope->m->arr[i]->getElem();
							   this->print(type->getScope());
							   break;
				}
				case FUNCTION: {
								   cout << "\tFunction: " << scope->m->arr[i]->getName() << endl;
								   Function* function = (Function*)scope->m->arr[i]->getElem();
								   this->print(function->getScope());
								   break;
				}
				case DATAMEMBER: {
									DataMember* d = (DataMember*)scope->m->arr[i]->getElem();
									cout << "\tData Member: " << d->getName() << endl;
									break;
				}
				case LOCALVARIABLE: {
										Variable* var = (Variable*)scope->m->arr[i]->getElem();
										cout << "\t\tLocal Variable: " << var->getName() << endl;
										break;
				}
				case PARAMETER: {
										break;
				}
				default:
					break;
				}
			}
		}
	}
}