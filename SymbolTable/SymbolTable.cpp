#include "SymbolTable.h"
#include "MyParser.h"
//============= Scope   ================
Scope::Scope(){
	this->m = new MyMap();
	this->parent = 0;
}
//============ Variable  ================
Variable::Variable(){
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

//=======================================
//============ Data Member  ================
/*
DataMember::DataMember(){
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
*/
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

void Function::setName(char* name){
	strcat(this->name, name);
}

void Function::setScope(Scope* m){
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

void Function::setIsStatic(bool isStatic){
	this->isStatic = isStatic;
}

void Function::setIsFinal(bool isFinal){
	this->isFinal = isFinal;
}

void Function::setIsAbstract(bool isAbstract){
	this->isAbstract = isAbstract;
}

void Function::setIsNative(bool isNative){
	this->isNative = isNative;
}

void Function::setIsSynchronized(bool isSynchronized) {
	this->isSynchronized = isSynchronized;
}

void Function::setIsTransient(bool isTransient){
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

bool Function::getIsFinal(){
	return this->isFinal;
}

bool Function::getIsAbstract(){
	return this->isAbstract;
}

bool Function::getIsNative(){
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

char* Function::getName(){
	return this->name;
}

Scope * Function::getScope(){
	return this->scope;
}

bool Function::getIsConstructor() {
	return this->isConstructor;
}
//=======================================
SymbolTable::SymbolTable(void){
	this->rootScope = new Scope();
	this->currScope = this->rootScope;
}

SymbolTable::~SymbolTable(void) {
}

Variable * SymbolTable::insertVariableInCurrentScope(char* name, Modifier* m) {
	Variable * v = this->getVariableFromCurrentScope(name);
	if(v) {
		return 0;//item is exist previously
	}
	else {
		v = new Variable();
		v->setName(name);
		v->setType(m->getReturnType());
		v->setIsFinal(m->getIsFinal());
		m->reset();
		this->currScope->m->put(name, v);
	}
	return v;
}
Variable * SymbolTable::getVariableFromCurrentScope(char* name){
	Variable * v = (Variable*)this->currScope->m->get(name);
	if(!v) {
		return 0;
	}
	return v;
}/*
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
/*
DataMember * SymbolTable::insertDataMemberInCurrentScope(char* name) {
	DataMember * d = this->getDataMemberFromCurrentScope(name);
	if (d) {
		return 0;//item is exist previously
	}
	else {
		d = new DataMember();
		d->setName(name);
		/*
		d->setType(m->getReturnType());
		d->setIsStatic(m->getIsStatic());
		d->setIsFinal(m->getIsFinal());
		d->setIsPublic(m->getIsPublic()); d->setIsPrivate(m->getIsPrivate()); d->setIsProtected(m->getIsProtected());
		if (m->getIsPrivate() == false && m->getIsProtected() == false) {
			d->setIsPublic(true);
		}
		m->reset();
		
		this->currScope->m->put(name, d);
	}
	return d;
}

DataMember * SymbolTable::getDataMemberFromCurrentScope(char* name) {
	DataMember * d = (DataMember*)this->currScope->m->get(name);
	if (!d) {
		Scope * temp = this->currScope->parent;
		while (temp && !d){
			d = (DataMember*)temp->m->get(name);
			temp = temp->parent;
		}
	}
	return d;
}*/