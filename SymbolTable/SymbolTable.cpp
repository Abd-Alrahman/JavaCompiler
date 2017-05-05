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
		cout << "[" << current->getId() << "]";
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

//============ Variable ===============
int Variable::lastId = 0;

Variable::Variable() {
	this->id = 0;
	this->colNo = 0;
	this->rowNo = 0;
	this->name = new char[255];
	this->type = new char[255];
	this->alternativeType = new char[255];
	this->name[0] = '\0';
	this->type[0] = '\0';
	this->alternativeType[0] = '\0';
	this->isFinal = false;
	this->strc = LOCALVARIABLE;
	Variable::lastIdInc();
}

Variable::~Variable() {}

void Variable::setId(int id) {
	this->id = id;
}

int Variable::getId() {
	return this->id;
}

void Variable::setName(char* n) {
	strcat(this->name, n);
}

char* Variable::getName() {
	return this->name;
}

int Variable::lastIdInc() {
	return ++Variable::lastId;
}

void Variable::setLastId(int lastId) {
	Variable::lastId = lastId;
}

int Variable::getLastId() {
	return Variable::lastId;
}

void Variable::setType(char* type) {
	strcat(this->type, type);
}

char* Variable::getType() {
	return this->type;
}

void Variable::setAlternativeType(char* alternativeType) {
	strcat(this->alternativeType, alternativeType);
}

char* Variable::getAlternativeType() {
	return this->alternativeType;
}

void Variable::setIsFinal(bool isFinal) {
	this->isFinal = isFinal;
}

bool Variable::getIsFinal() {
	return this->isFinal;
}

bool Variable::isPrimitiveType(char* type) {
	char* primitives[] = { "boolean", "char", "byte", "short", "int", "long", "float", "double", "void", "String" };
	for (int i = 0; i < (sizeof(primitives) / sizeof(*primitives)); i++)
	{
		if (strcmp(type, primitives[i]) == 0)
			return true;
	}
	return false;
}

//============= Parameter =================
int Parameter::lastId = 0;

Parameter::Parameter() {
	this->id = 0;
	this->name = new char[255];
	this->name[0] = '\0';
	this->type = new char[255];
	this->type[0] = '\0';
	this->isFinal = false;
	this->next = NULL;
	this->strc = PARAMETER;
	Parameter::lastIdInc();
}

Parameter::Parameter(Parameter* parameter) {
	this->id = parameter->id;
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

void Parameter::setId(int id) {
	this->id = id;
}

int Parameter::getId() {
	return this->id;
}

int Parameter::lastIdInc() {
	return ++Parameter::lastId;
}

void Parameter::setLastId(int lastId) {
	Parameter::lastId = lastId;
}

int Parameter::getLastId() {
	return Parameter::lastId;
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
	char* primitives[] = { "boolean", "char", "byte", "short", "int", "long", "float", "double", "void", "String" };
	for (int i = 0; i < (sizeof(primitives) / sizeof(*primitives)); i++)
	{
		if (strcmp(type, primitives[i]) == 0)
			return true;
	}
	return false;
}

//============ Data Member  ================
int DataMember::lastId = 0;

DataMember::DataMember() {
	this->id = 0;
	this->name = new char[255];
	this->name[0] = '\0';
	this->type = new char[255];
	this->type[0] = '\0';
	this->strc = DATAMEMBER;
	this->colNo = 0;
	this->rowNo = 0;
	this->initModifiers();
	DataMember::lastIdInc();
}

DataMember::~DataMember() {}

void DataMember::setId(int id) {
	this->id = id;
}

int DataMember::getId() {
	return this->id;
}

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

int DataMember::lastIdInc() {
	return ++DataMember::lastId;
}

void DataMember::setLastId(int lastId) {
	DataMember::lastId = lastId;
}

int DataMember::getLastId() {
	return DataMember::lastId;
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
	this->size = 0;
	this->colNo = 0;
	this->rowNo = 0;
	this->strc = TYPE;
	this->next = NULL;
	this->inheritedType = NULL;
	this->name = new char[255];
	this->fileName = new char[255];
	this->parentName = new char[255];
	this->name[0] = '\0';
	this->fileName[0] = '\0';
	this->parentName[0] = '\0';
	this->scope = new Scope();
	this->scope->scopeOwner = (Type*) this;
	this->isPublic = false;
	this->isPrivate = false;
	this->isProtected = false;
	this->isFinal = false;
	this->isAbstract = false;
	this->isStatic = false;
}

Type::~Type() {}

void Type::setSize(int size) {
	this->size = size;
}

int Type::getSize() {
	return this->size;
}

void Type::checkForAbstraction(ErrorRecovery* errRecovery) {
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
						errRecovery->errQ->enqueue(this->rowNo, this->colNo, "Error: Class doesn't override abstract method", parentFunc->getName());
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

bool Type::isCyclicInheritance(ErrorRecovery* errRecovery) {
	TypeList* typeList = new TypeList();
	Type* temp = this;
	while (temp->inheritedType) {
		if (typeList->add(temp)) {
			if (typeList->find(temp->inheritedType->name)) {
				errRecovery->errQ->enqueue(temp->rowNo, temp->colNo, "Error: Cyclic inheritance in class", temp->name);
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

void Type::setFileName(char* n) {
	strcat(this->fileName, n);
}

char* Type::getFileName(){
	return this->fileName;
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

void Type::setIsStatic(bool isStatic) {
	this->isStatic = isStatic;
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

bool Type::getIsStatic() {
	return this->isStatic;
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
int Function::lastId = 0;

Function::Function() {
	this->size = 0;
	this->id = 0;
	this->colNo = 0;
	this->rowNo = 0;
	this->strc = FUNCTION;
	this->name = new char[255];
	this->label = new char[255];
	this->returnType = new char[255];
	this->name[0] = '\0';
	this->label[0] = '\0';
	this->returnType[0] = '\0';
	this->scope = new Scope();
	this->scope->scopeOwner = (Function*) this;
	this->pl = new ParamList();
	this->varCount = 0;
	this->initModifiers();
	Function::lastIdInc();
}

Function::~Function() {}

void Function::generateLabel(Type* parentType) {
	char* name = new char[255];
	name[0] = '\0';
	strcpy(name, parentType->getName()); strcat(name, "_"); strcat(name, this->name);
	this->setLabel(name);
}

void Function::setSize(int size) {
	this->size = size;
}

int Function::getSize() {
	return this->size;
}

void Function::setId(int id) {
	this->id = id;
}

int Function::getId() {
	return this->id;
}

void Function::setLastId(int lastId) {
	Function::lastId = lastId;
}

int Function::getLastId() {
	return lastId;
}

void Function::lastIdInc() {
	lastId++;
}

bool Function::equals(Function* f) {
	if ((strcmp(this->name, f->name) == 0) && (strcmp(this->returnType, f->returnType) == 0) &&
		(this->strc == FUNCTION && f->strc == FUNCTION) &&
		(this->isFinal == f->isFinal) && (this->isAbstract == f->isAbstract) &&
		(this->isNative == f->isNative) && (this->isVolatile == f->isVolatile) &&
		(this->isTransient == f->isTransient) && (this->isSynchronized == f->isSynchronized) &&
		(this->isStatic == f->isStatic) && (this->isConstructor == f->isConstructor) &&
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
	return false;
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

int Function::checkMethodBody(bool methodBody, ErrorRecovery* errRecovery) {
	if (!this->isConstructor) {
		if ((this->isAbstract || this->isNative) && methodBody) {
			errRecovery->errQ->enqueue(this->rowNo, this->colNo, "Error: Abstracts & native methods can not have a body", this->name);
			return 0;
		}
		else if (!this->isAbstract && !this->isNative && !methodBody) {
			errRecovery->errQ->enqueue(this->rowNo, this->colNo, "Error: Missing method body", this->name);
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

void Function::setLabel(char* label) {
	strcat(this->label, label);
}

void Function::setScope(Scope* m) {
	this->scope = m;
}

void Function::setReturnType(char* returnType) {
	strcat(this->returnType, returnType);
}

void Function::setVarCount(int varCount) {
	this->varCount = varCount;
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

int Function::getVarCount() {
	return this->varCount;
}

void Function::varCountInc() {
	++this->varCount;
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

char* Function::getLabel() {
	return this->label;
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
	if (this->currScope) {
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
		if (t && t->strc == TYPE)
			return t;
		return NULL;
	}
	return NULL;
}

Type * SymbolTable::getTypeParentByScope(Scope* scope, char* name) {
	if (scope) {
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
}

Variable * SymbolTable::insertVariableInCurrentScope(char* name, Modifier* m, int lineNo, int colNo, ErrorRecovery* errRecovery) {
	Variable * v = this->getVariableFromCurrentScope(name);
	if (v) {
		return 0;//item is exist previously
	}
	else {
		if (m->getIsAbstract() || m->getIsNative() || m->getIsPrivate() || m->getIsProtected() || m->getIsPublic() ||
			m->getIsStatic() || m->getIsSynchronized() || m->getIsTransient() || m->getIsVolatile()) {
			errRecovery->errQ->enqueue(v->rowNo, v->colNo, "Error: Local variable can't has access modifier other than final.", v->getName());
		}
		v = new Variable();
		v->setName(name);
		v->colNo = colNo; v->rowNo = lineNo;
		v->setId(Variable::getLastId());
		if (v->isPrimitiveType(m->getReturnType())) {
			v->setType(m->getReturnType());
			errRecovery->stateQ->enqueue(v->rowNo, v->colNo, "State: Variable type is primitive type.", v->getName());
		}
		else {
			Type* t = this->getTypeParent(m->getReturnType());
			if (t && t->strc == TYPE) {
				// TODO: abstract class can't be instantiated.
				if (strcmp(t->getName(), m->getReturnType()) == 0) {
					v->setType(m->getReturnType());
					v->setAlternativeType(m->getAlternativeReturnType());
					cout << "object has been created\n";
				}
				else {
					v->setType(m->getReturnType());
					v->setAlternativeType(m->getAlternativeReturnType());
					errRecovery->errQ->enqueue(0, 0, "Class doesn't exist", m->getReturnType());
				}
			}
			else {
				v->setType(m->getReturnType());
				v->setAlternativeType(m->getAlternativeReturnType());
				errRecovery->errQ->enqueue(0, 0, "Class doesn't exist", m->getReturnType());
			}
		}

		v->setIsFinal(m->getIsFinal());
		if (this->currScope)
			this->currScope->m->put(name, v, LOCALVARIABLE);
	}
	return v;
}

Variable * SymbolTable::getVariableFromCurrentScope(char* name){
	if (this->currScope) {
		Variable * v = (Variable*)this->currScope->m->get(name);
		if (!v) {
			return 0;
		}
		return v;
	}
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
Parameter * SymbolTable::createParam(char* name, Modifier* m, ErrorRecovery* errRecovery) {
	if (m->getIsAbstract() || m->getIsNative() || m->getIsPrivate() || m->getIsProtected() || m->getIsPublic() ||
		m->getIsStatic() || m->getIsSynchronized() || m->getIsTransient() || m->getIsVolatile()) {
		errRecovery->errQ->enqueue(0, 0, "Parameter can't has access modifier other than final.", name);
		return NULL;
	}
	Parameter* p = new Parameter();
	p->setName(name);
	p->setId(Parameter::getLastId());
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
				p->setType(m->getReturnType());
				errRecovery->errQ->enqueue(0, 0, "Class doesn't exist", m->getReturnType());
			}
		}
		else {
			p->setType(m->getReturnType());
			errRecovery->errQ->enqueue(0, 0, "Class doesn't exist", m->getReturnType());
		}
	}

	p->setIsFinal(m->getIsFinal());
	m->reset();
	return p;
}

Parameter * SymbolTable::getParameterFromCurrentFunction(char* name){
	if (this->currScope) {
		Parameter * p = (Parameter*)this->currScope->m->get(name);
		if (!p) {
			return 0;
		}
		return p;
	}
}
//================= Data Member ====================
DataMember * SymbolTable::insertDataMemberInCurrentScope(char* name, Modifier* m, int lineNo, int colNo) {
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
		d->colNo = colNo; d->rowNo = lineNo;
		if (m->getIsPrivate() == false && m->getIsProtected() == false && m->getIsPublic() == false) {
			d->setIsPublic(true);
		}
		if (!d->getIsStatic()) {
			d->setId(DataMember::getLastId());
		}
		else {
			DataMember::setLastId(DataMember::getLastId() - 1);
			d->setId(MyParser::getLastId());
			MyParser::lastIdInc();
		}
		if (this->currScope)
			this->currScope->m->put(name, d, DATAMEMBER);
	}

	
	return d;
}

DataMember * SymbolTable::getDataMemberFromCurrentScope(char* name) {
	if (this->currScope) {
		DataMember * d = (DataMember*)this->currScope->m->get(name);
		if (!d) {
			return 0;
		}
		return d;
	}
	else {
		return 0;
	}
}

void SymbolTable::checkAbstractMethod(Scope* scope, int i, MapElem* elem, ErrorRecovery* errRecovery) {
	if (scope) {
		Function* f = (Function*)scope->m->getElemFromArr(i);
		if (elem) {
			Type* type = (Type*)elem->getElem();
			if (f->getIsAbstract() && type && !type->getIsAbstract()) {
				errRecovery->errQ->enqueue(f->rowNo, f->colNo, "Error: Class is not abstract ", type->getName());
			}
		}
	}
}

void SymbolTable::checkMainMethod(Scope* scope, int i, MapElem* elem, ErrorRecovery* errRecovery) {
	if (scope) {
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
							errRecovery->errQ->enqueue(function->rowNo, function->colNo, "Error: main method already defined", function->getName());
						}
						else {
							this->hasMainMethod = true;
							errRecovery->stateQ->enqueue(function->rowNo, function->colNo, "State: Main method has been created", function->getName());
						}
						return;
					}
				}
			}
		}
	}
}

void SymbolTable::checkMethodOverriding(Scope* scope, int i, MapElem* elem, ErrorRecovery* errRecovery) {
	if (scope) {
		Type* type = NULL;
		Function* currFunc = (Function*)scope->m->getElemFromArr(i);

		if (elem && elem->getElem())
			type = (Type*)elem->getElem();

		if (type && !type->getInheritedType()) {
			this->checkAtTheEnd(currFunc->getScope(), scope->m->getFromArr(i), errRecovery);
			return;
		}

		if (type && type->strc == TYPE && type->getInheritedType()) {
			// Check for overriding
			Function* parentFunc = (Function*)type->getInheritedType()->getScope()->m->get(currFunc->getName());
			if (parentFunc && parentFunc->strc == FUNCTION) {
				if (parentFunc->pl->size == currFunc->pl->size && currFunc->pl->equals(parentFunc->pl)) {
					if (parentFunc->getIsFinal()) {
						errRecovery->errQ->enqueue(currFunc->rowNo, currFunc->colNo, "Error: Overriden method is final", parentFunc->getName());
					}
					if (currFunc->equals(parentFunc)) {
						errRecovery->stateQ->enqueue(currFunc->rowNo, currFunc->colNo, "State: Overriding state", currFunc->getName());
					}
					else {
						errRecovery->stateQ->enqueue(currFunc->rowNo, currFunc->colNo, "State: No Overriding state", currFunc->getName());
					}
				}
			}
		}
		this->checkAtTheEnd(currFunc->getScope(), scope->m->getFromArr(i), errRecovery);
	}
}

void SymbolTable::checkInnerInheritance(Scope* scope, Type* type, ErrorRecovery* errRecovery) {
	if (scope && scope->parent && type->getParentName() && type->getParentName()[0]) {
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
											   errRecovery->errQ->enqueue(inner1->rowNo, inner1->colNo, "Error: Final class can't be inherited from", inner1->getName());
										   }
										   // Inner inheritance state!
										   else {
											   errRecovery->stateQ->enqueue(type->rowNo, type->colNo, "State: Inner inheritance state done successfully", inner1->getName());
											   type->setInheritedType(inner1);
											   type->checkForAbstraction(errRecovery);
											   type->isCyclicInheritance(errRecovery);
										   }
									   }
									   else {
										   errRecovery->errQ->enqueue(type->rowNo, type->colNo, "Error: Class does not exist, or there is no inner inheritance", type->getParentName());
									   }
								   }
							   }
							   else {
								   errRecovery->errQ->enqueue(outer2->rowNo, outer2->colNo, "Error: Class does not exist or can't be inherited, or there is no inner inheritance", type->getParentName());
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
	Type* type = (Type*) currElem->getElem();
	if (type->getParentName() && type->getParentName()[0]) {
		// Outer extends Outer
		Type* inheritedType = (Type*) this->getTypeParentByScope(scope, type->getParentName());
		if (inheritedType && inheritedType->strc == TYPE) {
			// Size: adding parent size to child
			type->setSize(type->getSize() + inheritedType->getSize());
			if (inheritedType->getIsFinal()) {
				errRecovery->errQ->enqueue(type->rowNo, type->colNo, "Error: Final class can't be inherited from", inheritedType->getName());
			}
			else {
				char* chr = new char[255]; chr[0] = '\0';
				strcpy(chr, "State: Outer inheritance ");
				strcat(chr, type->getName());
				strcat(chr, " extends ");
				errRecovery->stateQ->enqueue(type->rowNo, type->colNo, chr, inheritedType->getName());
				type->setInheritedType(inheritedType);
				type->checkForAbstraction(errRecovery);
				type->isCyclicInheritance(errRecovery);
			}
			
		}
		else {
			char* chr = new char[255]; chr[0] = '\0';
			strcpy(chr, "Error: Outer inheritance ");
			strcat(chr, type->getName());
			strcat(chr, ", class doesn't exist");
			errRecovery->errQ->enqueue(type->rowNo, type->colNo, chr, type->getParentName());
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
			}/*
			case DATAMEMBER: {
								 this->checkNexts(scope, i, errRecovery);
								 break;
			}
			case LOCALVARIABLE: {
									this->checkNexts(scope, i, errRecovery);
									break;
			}*/
			default:
				break;
			}
			elem = elem->getNext();
		}
	}
}

void SymbolTable::checkFileClassNames(ErrorRecovery* errRecovery) {
	for (int i = 0; i < 71; i++) {
		if (this->rootScope->m->arr[i]) {
			MapElem * elem = this->rootScope->m->arr[i];
			while (elem && elem->getStrc() != TYPE) {
				elem = elem->getNext();
			}
			if (elem->getStrc() == TYPE) {
				Type* type = (Type*)elem->getElem();
				for (int j = i + 1; j < 71; j++) {
					if (this->rootScope->m->arr[j]) {
						MapElem * elem1 = this->rootScope->m->arr[j];
						while (elem1 && elem1->getStrc() != TYPE) {
							elem1 = elem1->getNext();
						}
						if (elem1->getStrc() == TYPE) {
							Type* type1 = (Type*)elem1->getElem();
							if (strcmp(type->getFileName(), type1->getFileName()) == 0) {
								errRecovery->errQ->enqueue(type1->rowNo, type1->rowNo, "Error: file can't has more than one class", type->getFileName());
							}
						}
					}
				}
			}
		}
	}
}

void SymbolTable::checkAtTheEnd(Scope* scope, MapElem* elem, ErrorRecovery* errRecovery) {
	if (scope) {
		for (int i = 0; i < 71; i++)
		{
			if (scope->m->arr[i]) {
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
									   this->checkMainMethod(scope, i, elem, errRecovery);
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
}

void SymbolTable::printNexts(Scope* scope, int index, ErrorRecovery* errRecovery) {
	if (scope->m->arr[index]) {
		MapElem* elem = scope->m->getFromArr(index)->getNext();
		while (elem) {
			switch (elem->getStrc())
			{
			case TYPE: {
						   Type* type = (Type*)elem->getElem();
						   cout << "Class " << type->getName();
						   if (type->getInheritedType()) cout << " extends from " << type->getParentName();
						   cout << " { ";
						   cout << endl;
						   this->print(type->getScope(), errRecovery);
						   cout << "}\n";
						   break;
			}
			case FUNCTION: {
							   Function* function = (Function*)elem->getElem();
							   if (function) {
								   cout << "\t";
								   if (function->getIsPublic()) cout << "Public ";
								   if (function->getIsPrivate()) cout << "Private ";
								   if (function->getIsProtected()) cout << "Protected ";
								   if (function->getIsStatic()) cout << "Static ";
								   if (function->getIsFinal()) cout << "Final ";
								   if (function->getIsAbstract()) cout << "Abstract ";
								   if (function->getIsNative()) cout << "Native ";
								   if (!function->getIsConstructor())
									   cout << "Function: ";
								   else
									   cout << "Constructor: ";
								   cout << function->getName();
								   cout << "[" << function->getLabel() << ", " << function->getId() << "]";
								   if (!function->pl->isEmpty()) {
									   cout << " with parameters: (";
									   function->pl->print();
									   cout << ")";
								   }
								   cout << " and size = " << function->getSize();
								   cout << " { \n";
								   this->print(function->getScope(), errRecovery);
								   cout << "\t} \n";
							   }
							   break;
			}
			case DATAMEMBER: {
								 DataMember* d = (DataMember*)elem->getElem();
								 if (d && d->strc == DATAMEMBER) {
									 cout << "\t";
									 if (d->getIsPublic()) cout << "Public ";
									 if (d->getIsPrivate()) cout << "Private ";
									 if (d->getIsProtected()) cout << "Protected ";
									 if (d->getIsStatic()) cout << "Static ";
									 if (d->getIsFinal()) cout << "Final ";
									 cout << "Data Member[" << d->getId() << "]: " << d->getName() << " with type " << d->getType() << endl;
								 }
								 break;
			}
			case LOCALVARIABLE: {
									Variable* var = (Variable*)elem->getElem();
									if (var && var->strc == LOCALVARIABLE) {
										cout << "\t\tLocal Variable[" << var->getId() << "]: " << var->getName() << " with type " << var->getType() << endl;
									}
									break;
			}
			default:
				break;
			}
			elem = elem->getNext();
		}
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
							   cout << "}\n";
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
		errRecovery->errQ->enqueue(0, 0, "Error: main method is missing", "");
	}
} 

Type* SymbolTable::printTypeHeader(Scope* scope, int index) {
	Type* type = (Type*)scope->m->getElemFromArr(index);
	cout << "Class " << type->getName();
	if (type->getInheritedType()) cout << " extends from " << type->getParentName();
	cout << " with size = " << type->getSize();
	cout << " {\n";
	return type;
}

Function* SymbolTable::printMethodHeader(Scope* scope, int index, ErrorRecovery* errRecovery) {
	Function* function = (Function*)scope->m->getElemFromArr(index);
	if (function && function->strc == FUNCTION) {
		cout << "\t";
		if (function->getIsPublic()) cout << "Public ";
		if (function->getIsPrivate()) cout << "Private ";
		if (function->getIsProtected()) cout << "Protected ";
		if (function->getIsStatic()) cout << "Static ";
		if (function->getIsFinal()) cout << "Final ";
		if (function->getIsAbstract()) cout << "Abstract ";
		if (function->getIsNative()) cout << "Native ";
		if (!function->getIsConstructor())
			cout << "Function: ";
		else
			cout << "Constructor: ";
		cout << scope->m->getFromArr(index)->getName();
		Function* function = (Function*)scope->m->getElemFromArr(index);
		cout << "[" << function->getLabel() << ", " << function->getId() << "]";
		if (!function->pl->isEmpty()) {
			cout << " with parameters: (";
			function->pl->print();
			cout << ")";
		}
		cout << " and size = " << function->getSize();
		cout << " { \n";
		this->print(function->getScope(), errRecovery);
		cout << "\t} \n";
	}
	return function;
}

DataMember* SymbolTable::printDmHeader(Scope* scope, int index) {
	DataMember* d = (DataMember*)scope->m->getElemFromArr(index);
	if (d && d->strc == DATAMEMBER) {
		cout << "\t";
		if (d->getIsPublic()) cout << "Public ";
		if (d->getIsPrivate()) cout << "Private ";
		if (d->getIsProtected()) cout << "Protected ";
		if (d->getIsStatic()) cout << "Static ";
		if (d->getIsFinal()) cout << "Final ";
		cout << "Data Member" << "[" << d->getId() << "]: " << d->getName() << " with type " << d->getType() << endl;
	}
	return d;
}

Variable* SymbolTable::printVarHeader(Scope* scope, int index) {
	Variable* var = (Variable*)scope->m->getElemFromArr(index);
	if (var && var->strc == LOCALVARIABLE) {
		cout << "\t\tLocal Variable" << "[" << var->getId() << "]: " << var->getName() << " with type " << var->getType() << endl;
	}
	return var;
}