#include "SymbolTable.h"
#include "MyParser.h"
//============= Scope   ================
Scope::Scope() {
	this->m = new MyMap();
	this->parent = 0;
}
//============ ParamList ===============
ParamList::ParamList() {
	this->root = NULL;
	this->current = this->root;
	this->size = 0;
}

ParamList::ParamList(ParamList* pl) {
	this->root = pl->root;
	this->current = pl->current;
	this->size = pl->size;
	pl->root = NULL;
	pl->current = NULL;
	pl->size = 0;
}

ParamList::~ParamList() {}

Parameter* ParamList::find(char* name) {
	Parameter* curr = this->root;
	while (curr) {
		if (strcmp(curr->getName(), name) == 0) {
			return curr;
		}
		curr = curr->next;
	}
	return NULL;
}

Parameter* ParamList::add(Parameter* parameter) {
	if (!this->find(parameter->getName())) {
		if (!this->root) {
			this->root = parameter;
			this->root->next = NULL;
			this->current = this->root;
		}
		else {
			this->current->next = parameter;
			this->current = this->current->next;
			this->current->next = NULL;
		}
		this->size++;
		return this->current;
	}
	return NULL;
}

bool ParamList::remove(char* name) {
	Parameter* curr = this->root;
	Parameter* prev = NULL;
	while (strcmp(curr->getName(), name) != 0) {
		prev = curr;
		curr = curr->next;
	}
	if (curr) {
		prev->next = curr->next;
		if (curr == this->root) {
			this->root = prev;
		}
		delete curr;
		this->size--;
		return true;
	}
	return false;
}

void ParamList::print() {
	Parameter* current = this->root;
	while (current) {
		if (current->getIsFinal()) {
			cout << "final ";
		}
		cout << current->getType() << " " << current->getName();
		if (current->next) {
			cout << ", ";
			current = current->next;
		}
		else {
			return;
		}
	}
}

bool ParamList::equals(ParamList* pl) {
	Parameter* plTemp = pl->root;
	Parameter* thisTemp = this->root;
	while (plTemp || thisTemp) {
		if (plTemp == NULL || thisTemp == NULL)
			return false;
		if (thisTemp && plTemp)
		if (!thisTemp->equals(plTemp))
			return false;
		plTemp = plTemp->next;
		thisTemp = thisTemp->next;
	}
	return true;
}

bool ParamList::isEmpty() {
	return (this->root == NULL);
}
//============ TypeList ===============
TypeList::TypeList() {
	this->root = NULL;
	this->current = this->root;
	this->size = 0;
}

TypeList::TypeList(TypeList* tl) {
	this->root = tl->root;
	this->current = tl->current;
	this->size = tl->size;
	tl->root = NULL;
	tl->current = NULL;
	tl->size = 0;
}

TypeList::~TypeList() {}

Type* TypeList::find(char* name) {
	Type* curr = this->root;
	while (curr) {
		if (strcmp(curr->getName(), name) == 0) {
			return curr;
		}
		curr = curr->next;
	}
	return NULL;
}

Type* TypeList::add(Type* type) {
	if (!this->find(type->getName())) {
		if (!this->root) {
			this->root = type;
			this->root->next = NULL;
			this->current = this->root;
		}
		else {
			this->current->next = type;
			this->current = this->current->next;
			this->current->next = NULL;
		}
		this->size++;
		return this->current;
	}
	return NULL;
}

bool TypeList::remove(char* name) {
	Type* curr = this->root;
	Type* prev = NULL;
	while (strcmp(curr->getName(), name) != 0) {
		prev = curr;
		curr = curr->next;
	}
	if (curr) {
		prev->next = curr->next;
		if (curr == this->root) {
			this->root = prev;
		}
		delete curr;
		this->size--;
		return true;
	}
	return false;
}

void TypeList::print() {
	Type* current = this->root;
	while (current) {
		if (current->getIsFinal()) {
			cout << "final ";
		}
		cout << current->getName();
		if (current->next) {
			cout << ", ";
			current = current->next;
		}
		else {
			return;
		}
	}
}

bool TypeList::equals(TypeList* pl) {
	Type* plTemp = pl->root;
	Type* thisTemp = this->root;
	while (plTemp || thisTemp) {
		if (plTemp == NULL || thisTemp == NULL)
			return false;
		if (thisTemp && plTemp)
		if (!thisTemp->equals(plTemp))
			return false;
		plTemp = plTemp->next;
		thisTemp = thisTemp->next;
	}
	return true;
}

bool TypeList::isEmpty() {
	return (this->root == NULL);
}

//============ Variable ================
Variable::Variable() {
	this->name = new char[255];
	this->name[0] = '\0';
	this->type = new char[255];
	this->type[0] = '\0';
	this->isFinal = false;
	this->strc = LOCALVARIABLE;
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

//============= Parameter =================
Parameter::Parameter() {
	this->name = new char[255];
	this->name[0] = '\0';
	this->type = new char[255];
	this->type[0] = '\0';
	this->isFinal = false;
	this->next = NULL;
	this->strc = PARAMETER;
}

Parameter::Parameter(Parameter* parameter) {
	this->name = new char[255];
	this->name[0] = '\0';
	this->type = new char[255];
	this->type[0] = '\0';
	this->next = parameter->next;
	strcat(this->name, parameter->name);
	strcat(this->type, parameter->type);
	this->isFinal = parameter->isFinal;
	this->strc = parameter->strc;
}

Parameter::~Parameter() {}

bool Parameter::equals(Parameter* p) {
	if ((strcmp(this->type, p->type) == 0) && (this->isFinal == p->isFinal) &&
		(this->strc == PARAMETER && p->strc == PARAMETER)) {
		return true;
	}
	return false;
}

void Parameter::setName(char* n) {
	strcat(this->name, n);
}

char* Parameter::getName() {
	return this->name;
}

void Parameter::setType(char* type) {
	strcat(this->type, type);
}

char* Parameter::getType() {
	return this->type;
}

void Parameter::setIsFinal(bool isFinal) {
	this->isFinal = isFinal;
}

bool Parameter::getIsFinal() {
	return this->isFinal;
}

bool Parameter::isPrimitiveType(char* type) {
	char* primitives[] = { "boolean", "char", "byte", "short", "int", "long", "float", "double", "void" };
	for (int i = 0; i < (sizeof(primitives) / sizeof(*primitives)); i++)
	{
		if (strcmp(type, primitives[i]) == 0)
			return true;
	}
	return false;
}

//============ Data Member  ================
DataMember::DataMember() {
	this->name = new char[255];
	this->name[0] = '\0';
	this->type = new char[255];
	this->type[0] = '\0';
	this->strc = DATAMEMBER;
	this->initModifiers();
}

DataMember::~DataMember() {}

void DataMember::initModifiers() {
	this->isFinal = false;
	this->isStatic = false;
	this->isPublic = false;
	this->isPrivate = false;
	this->isProtected = false;
}

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
	this->parentName = new char[255];
	this->parentName[0] = '\0';
	this->next = NULL;
	this->scope = new Scope();
	this->inheritedType = NULL;
	this->strc = TYPE;
	this->isPublic = false;
	this->isPrivate = false;
	this->isProtected = false;
	this->isFinal = false;
	this->isAbstract = false;
}

Type::~Type() {}

void Type::checkForAbstraction() {
	// There is parent class
	if (!this->inheritedType) {
		return;
	}
	// Parent class is abstract
	// This class is not abstract
	if (!this->inheritedType->isAbstract || this->isAbstract) {
		return;
	}
	else {
		for each (MapElem* elem in this->inheritedType->scope->m->arr)
		{
			if (elem && elem->getStrc() == FUNCTION) {
				Function* parentFunc = (Function*)elem->getElem();
				// Get parent class functions and check if each one is abstract
				if (parentFunc && parentFunc->getIsAbstract()) {
					Function* thisFunc = (Function*)this->getScope()->m->get(parentFunc->getName());
					// This class doesn't override parent class functions! (Abstract class overriden state)
					if (!thisFunc) {
						cout << "Error: " << this->name << " doesn't override abstract method " << parentFunc->getName() << endl;
					}
				}
			}
		}
	}
}

bool Type::equals(Type* type) {
	if ((strcmp(this->name, type->name) == 0) &&
		(this->isPublic == type->isPublic) && (this->isPrivate == type->isPrivate) &&
		(this->isProtected == type->isProtected) && (this->isAbstract == type->isAbstract) &&
		(this->isFinal == type->isFinal) && (strcmp(this->parentName, type->parentName) == 0)) {
		return true;
	}
	return false;
}

bool Type::isCyclicInheritance() {
	TypeList* typeList = new TypeList();
	Type* temp = this;
	while (temp->inheritedType) {
		if (typeList->add(temp)) {
			if (typeList->find(temp->inheritedType->name)) {
				cout << "Error: Cyclic inheritance in class, " << temp->inheritedType->name << endl;
				//errRecovery->errQ->enqueue(0, 0, "Error: Cyclic inheritance in class", temp->inheritedType->name);
				return true;
			}
			temp = temp->inheritedType;
		}
	}
	return false;
}

void Type::setName(char* n) {
	strcat(this->name, n);
}

char* Type::getName(){
	return this->name;
}

void Type::setParentName(char* n) {
	strcat(this->parentName, n);
}

char* Type::getParentName(){
	return this->parentName;
}

bool Type::illegalCombinationOfModifiers() {
	if ((this->isPublic && this->isPrivate) ||
		(this->isPublic && this->isProtected) ||
		(this->isProtected && this->isPrivate) ||
		(this->isAbstract && this->isFinal)) {
		return true;
	}
	return false;
}

void Type::setInheritedType(Type* e) {
	this->inheritedType = e;
}

Type* Type::getInheritedType() {
	return this->inheritedType;
}

void Type::setIsPublic(bool isPublic) {
	this->isPublic = isPublic;
}

void Type::setIsPrivate(bool isPrivate) {
	this->isPrivate = isPrivate;
}

void Type::setIsProtected(bool isProtected) {
	this->isProtected = isProtected;
}

void Type::setIsFinal(bool isFinal) {
	this->isFinal = isFinal;
}

bool Type::getIsFinal() {
	return this->isFinal;
}

void Type::setIsAbstract(bool isAbstract) {
	this->isAbstract = isAbstract;
}

bool Type::getIsAbstract() {
	return this->isAbstract;
}

bool Type::getIsPublic() {
	return this->isPublic;
}

bool Type::getIsPrivate() {
	return this->isPrivate;
}

bool Type::getIsProtected() {
	return this->isProtected;
}

void Type::setScope(Scope * m) {
	this->scope = m;
}

Scope * Type::getScope() {
	return this->scope;
}

void Type::printDetails() {
	cout << "=============== Class " << this->name << " opened ================" << endl;
	cout << "has been created ";
	cout << "with modifiers list:" << endl;
	if (this->isPublic) cout << "Public" << endl;
	if (this->isPrivate) cout << "Private" << endl;
	if (this->isProtected) cout << "Protected" << endl;
	if (this->isFinal) cout << "Final" << endl;
	if (this->isAbstract) cout << "Abstract" << endl;
	if (this->inheritedType) cout << "Extends from " << this->inheritedType->name << endl;
}
//=======================================
//=================Function==============
Function::Function() {
	this->name = new char[255];
	this->name[0] = '\0';
	this->returnType = new char[255];
	this->returnType[0] = '\0';
	this->scope = new Scope();
	this->pl = new ParamList();
	this->strc = FUNCTION;
	this->initModifiers();
}

Function::~Function() {}

bool Function::equals(Function* f) {
	if ((strcmp(this->name, f->name) == 0) && (strcmp(this->returnType, f->returnType) == 0) &&
		(this->strc == FUNCTION && f->strc == FUNCTION) &&
		((this->isPublic == true && f->isPublic == true) ||
		(this->isProtected == true && f->isProtected == true) ||
		(this->isPrivate == true && f->isPrivate == true))) {
		return true;
	}
	return false;
}

bool Function::isOverloadingState(Function* f) {
	if (strcmp(this->name, f->name) == 0) {
		if (!this->pl->equals(f->pl)) {
			return true;
		}
	}
	return false;
}

bool Function::constructorModifiersError() {
	if ((this->isFinal && this->isConstructor) ||
		(this->isAbstract && this->isConstructor)) {
		return true;
	}
}

bool Function::illegalCombinationOfModifiers() {
	if ((this->isPublic && this->isPrivate) ||
		(this->isPublic && this->isProtected) ||
		(this->isProtected && this->isPrivate) ||
		(this->isFinal && this->isAbstract)) {
		return true;
	}
	return false;
}

int Function::checkMethodBody(bool methodBody) {
	if (!this->isConstructor) {
		if ((this->isAbstract || this->isNative) && methodBody) {
			cout << "Error: " << this->name << " Abstracts & native methods can not have a body\n";
			return 0;
		}
		else if (!this->isAbstract && !this->isNative && !methodBody) {
			cout << "Error: " << this->name << " Missing method body\n";
			return 1;
		}
	}
	return 2;
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

void Function::initModifiers() {
	this->isPublic = false;
	this->isPrivate = false;
	this->isProtected = false;
	this->isStatic = false;
	this->isFinal = false;
	this->isAbstract = false;
	this->isNative = false;
	this->isSynchronized = false;
	this->isTransient = false;
	this->isVolatile = false;
	this->isConstructor = false;
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
	this->hasMainMethod = false;
}

SymbolTable::~SymbolTable(void) {
}


Type * SymbolTable::getTypeParent(char* name) {
	Type * t = (Type*)this->currScope->m->get(name);
	if (!t) {
		Scope * temp = this->currScope->parent;
		while (temp && !t) {
			t = (Type*)temp->m->get(name);
			if (t && t->strc == TYPE) {
				return t;
			}
			temp = temp->parent;
		}
	}
	return t;
}

Type * SymbolTable::getTypeParentByScope(Scope* scope, char* name) {
	Type * t = (Type*)scope->m->get(name);
	if (!t) {
		Scope * temp = scope->parent;
		while (temp && !t) {
			t = (Type*)temp->m->get(name);
			temp = temp->parent;
		}
	}
	return t;
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
			Type* t = this->getTypeParent(m->getReturnType());
			if (t && t->strc == TYPE) {
				// TODO: abstract class can't be instantiated.
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
	if (!v) {
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

//================= Parameter ====================
Parameter * SymbolTable::createParam(char* name, Modifier* m) {
	if (m->getIsAbstract() || m->getIsNative() || m->getIsPrivate() || m->getIsProtected() || m->getIsPublic() ||
		m->getIsStatic() || m->getIsSynchronized() || m->getIsTransient() || m->getIsVolatile()) {
		cout << "=====================================================\n";
		cout << "Parameter can't has access modifier other than final.\n";
		cout << "=====================================================\n";
		return NULL;
	}
	Parameter* p = new Parameter();
	p->setName(name);
	if (p->isPrimitiveType(m->getReturnType())) {
		p->setType(m->getReturnType());
		cout << "Parameter type is primitive" << endl;
	}
	else {
		Type* t = this->getTypeParent(m->getReturnType());
		if (t && t->strc == TYPE) {
			if (strcmp(t->getName(), m->getReturnType()) == 0) {
				p->setType(m->getReturnType());
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

	p->setIsFinal(m->getIsFinal());
	m->reset();
	return p;
}

Parameter * SymbolTable::getParameterFromCurrentFunction(char* name){
	Parameter * p = (Parameter*)this->currScope->m->get(name);
	if (!p) {
		return 0;
	}
	return p;
}
//================= Data Member ====================
DataMember * SymbolTable::insertDataMemberInCurrentScope(char* name, Modifier* m) {
	DataMember * d = (DataMember*)this->getDataMemberFromCurrentScope(name);
	if (d && d->strc == DATAMEMBER) {
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

void SymbolTable::checkAbstractMethod(Scope* scope, int i, MapElem* elem, ErrorRecovery* errRecovery) {
	Function* f = (Function*)scope->m->getElemFromArr(i);
	Type* type = (Type*)elem->getElem();
	if (f->getIsAbstract() && type && !type->getIsAbstract()) {
		errRecovery->errQ->enqueue(0, 0, "Class is not abstract ", type->getName());
		cout << "Error[" << 0 << ", " << 0 << "]: Class " << type->getName() << " is not abstract\n";
	}
}

void SymbolTable::checkMainMethod(Scope* scope, int i, MapElem* elem) {
	Function* function = NULL;
	if (scope->m->arr[i]) {
		function = (Function*)scope->m->getElemFromArr(i);
	}
	if (function && function->strc == FUNCTION) {
		if ((strcmp(function->getName(), "main") == 0) &&
			(function->getIsPublic() && function->getIsStatic())) {
			if (scope->parent && elem->getElem()) {
				Type* type = (Type*)elem->getElem();
				if (type && type->strc == TYPE && type->getIsPublic()) {
					if (this->hasMainMethod) {
						cout << "Error: main method already defined!\n";
					}
					else {
						this->hasMainMethod = true;
						cout << "Main method has been created\n";
					}
					return;
				}
			}
		}
	}
}

void SymbolTable::checkMethodOverriding(Scope* scope, int i, MapElem* elem, ErrorRecovery* errRecovery) {
	Type* type = NULL;
	Function* currFunc = (Function*)scope->m->getElemFromArr(i);

	if (elem->getElem())
		type = (Type*)elem->getElem();

	if (!type->getInheritedType()) {
		this->checkAtTheEnd(currFunc->getScope(), scope->m->getFromArr(i), errRecovery);
		return;
	}
	
	if (type && type->strc == TYPE && type->getInheritedType()) {
		// Check for overriding
		Function* parentFunc = (Function*)type->getInheritedType()->getScope()->m->get(currFunc->getName());
		if (parentFunc && parentFunc->strc == FUNCTION) {
			if (parentFunc->pl->size == currFunc->pl->size && currFunc->pl->equals(parentFunc->pl)) {
				if (parentFunc->getIsFinal()) {
					cout << "================================\n";
					cout << "Error: Overriden method is final\n";
					cout << "================================\n";
				}
				if (currFunc->equals(parentFunc)) {
					cout << "========================================================================================\n";
					cout << "Overriding state between " << currFunc->getName()
						<< " method from this class and " << parentFunc->getName() << " method from parent class\n";
					cout << "========================================================================================\n";
				}
				else {
					cout << "================\n";
					cout << "Overriding error\n";
					cout << "================\n";
				}
			}
		}
	}
	this->checkAtTheEnd(currFunc->getScope(), scope->m->getFromArr(i), errRecovery);
}

void SymbolTable::checkInnerInheritance(Scope* scope, Type* type, ErrorRecovery* errRecovery) {
	if (scope->parent && type->getParentName() && type->getParentName()[0]) {
		// Inner1 in Outer1 extends Inner2 in Outer2 && Outer1 extends Outer2
		for (int i = 0; i < 71; i++)
		{
			if (scope->parent->m->arr[i]) {
				switch (scope->parent->m->getStrc(i)) {
				case TYPE: {
							   // Getting outer2 first
							   Type* outer2 = (Type*)scope->parent->m->getElemFromArr(i);
							   MapElem* elem = NULL;
							   // Checking if outer2 does not have a parent 
							   if (outer2->getParentName() && !outer2->getParentName()[0]) {
								   // Getting next nodes
								   elem = scope->parent->m->getFromArr(i)->getNext();
								   while (elem) {
									   outer2 = (Type*)elem->getElem();
									   if (outer2 && outer2->getParentName() && outer2->getParentName()[0]) {
										   break;
									   }
									   elem = elem->getNext();
								   }
							   }
							   // Checking if outer2 exsits && has a parent
							   if (outer2 && outer2->getParentName() && outer2->getParentName()[0]) {
								   // Checking if outer2 parent (outer1) exists
								   Type* outer1 = (Type*)scope->parent->m->get(outer2->getParentName());
								   if (outer1) {
									   // Getting the inner class from outer1, where inner1 is the name that
									   // type extends
									   Type* inner1 = (Type*)outer1->getScope()->m->get(type->getParentName());
									   if (inner1) {
										   // Error: it's Final!
										   if (inner1->getIsFinal()) {
											   cout << "Error: final class can't be inherited from, " << inner1->getName() << endl;
											   errRecovery->errQ->enqueue(0, 0, "Final class can't be inherited from", inner1->getName());
										   }
										   // Inner inheritance state!
										   else {
											   cout << type->getName() << " extended successfully from " << inner1->getName() << endl;
											   type->setInheritedType(inner1);
											   type->checkForAbstraction();
											   type->isCyclicInheritance();
										   }
									   }
									   else {
										   errRecovery->errQ->enqueue(0, 0, "class does not exist", type->getParentName());
										   cout << "Class " << type->getParentName() << " does not exist.\n";
									   }
								   }
							   }
							   else {
								   cout << "Class " << type->getParentName() << " does not exist or can't be inherited From\n";
								   errRecovery->errQ->enqueue(0, 0, "Class does not exist or can't be inherited", type->getParentName());
								   continue;
							   }
				}
					break;
				}
			}
		}
	}
}

void SymbolTable::checkTypeInheritance(Scope* scope, MapElem* currElem, ErrorRecovery* errRecovery) {
	Type* type = (Type*)currElem->getElem();
	if (type->getParentName() && type->getParentName()[0]) {
		// Outer extends Outer
		Type* inheritedType = (Type*)this->getTypeParentByScope(scope, type->getParentName());
		if (inheritedType && inheritedType->strc == TYPE) {
			if (inheritedType->getIsFinal()) {
				errRecovery->errQ->enqueue(0, 0, "Final class can't be inherited from", inheritedType->getName());
				cout << "Final class can't be inherited from\n";
			}
			else {
				type->setInheritedType(inheritedType);
				type->checkForAbstraction();
				type->isCyclicInheritance();
			}
			
		}
		else {
			cout << "Class doesn't exist.\n";
		}
		this->checkInnerInheritance(scope, type, errRecovery);
	}
	this->checkAtTheEnd(type->getScope(), currElem, errRecovery);
}

void SymbolTable::checkNexts(Scope* scope, int i, ErrorRecovery* errRecovery) {
	if (scope && scope->m->arr[i]) {
		MapElem* elem = scope->m->getFromArr(i)->getNext();
		while (elem) {
			switch (elem->getStrc())
			{
			case TYPE: {
						   Type* type = (Type*)elem->getElem();
						   this->checkTypeInheritance(scope, elem, errRecovery);
						   break;
			}
			case FUNCTION: {
							   Function* function = (Function*)elem->getElem();
							   break;
			}
			case DATAMEMBER: {
								 this->checkNexts(scope, i, errRecovery);
								 break;
			}
			case LOCALVARIABLE: {
									this->checkNexts(scope, i, errRecovery);
									break;
			}
			default:
				break;
			}
			elem = elem->getNext();
		}
	}
}

void SymbolTable::checkAtTheEnd(Scope* scope, MapElem* elem, ErrorRecovery* errRecovery) {
	if (scope) {
		for (int i = 0; i < 71; i++)
		{
			MapElem* rootElem = scope->m->getFromArr(i);
			if (scope->m->getFromArr(i)) {
				switch (scope->m->getStrc(i))
				{
				case TYPE: {
							this->checkTypeInheritance(scope, rootElem, errRecovery);
							this->checkNexts(scope, i, errRecovery);
							break;
				}
				case FUNCTION: {
							this->checkMainMethod(scope, i, elem);
							this->checkAbstractMethod(scope, i, elem, errRecovery);
							this->checkMethodOverriding(scope, i, elem, errRecovery);
							this->checkNexts(scope, i, errRecovery);
							break;
				}
				case DATAMEMBER: {
							this->checkNexts(scope, i, errRecovery);
				}
				case LOCALVARIABLE: {
							this->checkNexts(scope, i, errRecovery);
				}
				default:
					break;
				}
			}
		}
	}
}

void SymbolTable::printNexts(Scope* scope, int index, ErrorRecovery* errRecovery) {
	MapElem* elem = scope->m->getFromArr(index)->getNext();
	while (elem) {
		switch (elem->getStrc())
		{
		case TYPE: {
			Type* type = (Type*)elem->getElem();
			cout << "Class " << type->getName();
			if (type->getInheritedType()) cout << " extends from " << type->getParentName();
			cout << "{ ";
			cout << endl;
			this->print(type->getScope(), errRecovery);
			cout << " }";
			break;
		}
		case FUNCTION: {
			Function* function = (Function*)elem->getElem();
			if (!function->getIsConstructor())
				cout << "\tFunction: ";
			else
				cout << "\tConstructor: ";
			cout << function->getName();
			if (!function->pl->isEmpty()) {
				cout << " with parameters ";
				function->pl->print();
			}
			this->print(function->getScope(), errRecovery);
			break;
		}
		case DATAMEMBER: {
			DataMember* d = (DataMember*)elem->getElem();
			cout << "\tData Member: " << d->getName() << endl;
			break;
		}
		case LOCALVARIABLE: {
			Variable* var = (Variable*)elem->getElem();
			cout << "\t\tLocal Variable: " << var->getName() << endl;
			break;
		}
		default:
			break;
		}
		elem = elem->getNext();
	}
}


void SymbolTable::print(Scope* scope, ErrorRecovery* errRecovery) {
	
	if (scope) {
		for (int i = 0; i < 71; i++)
		{
			if (scope->m->arr[i]) {
				switch (scope->m->getStrc(i))
				{
				case TYPE: {
							   Type* type = this->printTypeHeader(scope, i);
							   this->print(type->getScope(), errRecovery);
							   cout << "\n}\n";
							   this->printNexts(scope, i, errRecovery);
							   break;
				}
				case FUNCTION: {
								Function* function = this->printMethodHeader(scope, i, errRecovery);
								this->printNexts(scope, i, errRecovery);
								break;
				}
				case DATAMEMBER: {
								DataMember* d = this->printDmHeader(scope, i);
								this->printNexts(scope, i, errRecovery);
								break;
				}
				case LOCALVARIABLE: {
								Variable* var = this->printVarHeader(scope, i);
								this->printNexts(scope, i, errRecovery);
								break;
				}
				default:
					break;
				}
			}
		}
	}
	if (scope == this->rootScope && !this->hasMainMethod) {
		cout << "Error: main method is missing from your program.\n";
	}
}

Type* SymbolTable::printTypeHeader(Scope* scope, int index) {
	Type* type = (Type*)scope->m->getElemFromArr(index);
	cout << "Class " << type->getName();
	if (type->getInheritedType()) cout << " extends from " << type->getParentName();
	cout << " {";
	cout << endl;
	return type;
}

Function* SymbolTable::printMethodHeader(Scope* scope, int index, ErrorRecovery* errRecovery) {
	Function* function = (Function*)scope->m->getElemFromArr(index);
	if (!function->getIsConstructor())
		cout << "\tFunction: ";
	else
		cout << "\tConstructor: ";
	cout << scope->m->getFromArr(index)->getName();
	if (!function->pl->isEmpty()) {
		cout << " with parameters ";
		function->pl->print();
	}
	this->print(function->getScope(), errRecovery);
	cout << endl;
	return function;
}

DataMember* SymbolTable::printDmHeader(Scope* scope, int index) {
	DataMember* d = (DataMember*)scope->m->getElemFromArr(index);
	cout << "\tData Member: " << d->getName() << endl;
	return d;
}

Variable* SymbolTable::printVarHeader(Scope* scope, int index) {
	Variable* var = (Variable*)scope->m->getElemFromArr(index);
	cout << "\t\tLocal Variable: " << var->getName() << endl;
	return var;
}