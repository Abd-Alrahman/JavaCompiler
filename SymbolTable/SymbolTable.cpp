#include "SymbolTable.h"
//============= Scope   ================
Scope::Scope(){
	this->m = new MyMap();
	this->parent = 0;
}
//============ Variable  ================
Variable::Variable(){
	this->name = new char[255];
	this->name[0] = '\0';
}
Variable::~Variable(){}
void Variable::setName(char* n){
	strcat(this->name, n);
}
char* Variable::getName(){
	return this->name;
}

//=======================================
//============== Type ===================
Type::Type(){
	this->name = new char[255];
	this->name[0] = '\0';
	this->scope = new Scope();
}
Type::~Type(){}
void Type::setName(char* n){
	strcat(this->name,n);
}
char* Type::getName(){
	return this->name;
}
void Type::setInheritedType(Type* e){
	this->inheritedType = e;
}
Type* Type::getInheritedType(){
	return this->inheritedType;
}
void Type::setScope(Scope * m){
	this->scope = m;
}
Scope * Type::getScope(){
	return this->scope;
}
//=======================================
//=================Function==============
Function::Function(){
	this->name = new char[255];
	this->name[0] = '\0';
	this->modifier = new char[255];
	this->modifier[0] = '\0';
	this->isFinal = false;
	this->isStatic = false;
	this->modifier = "public";
	this->returnType = "void";
	this->scope = new Scope();
}

Function::~Function(){}
void Function::setName(char* name){
	this->name = name;
}

char* Function::getName(){
	return this->name;
}

void Function::setIsStatic(char* isStatic) {
	this->isStatic = (isStatic == "static") ? true : false;
}

bool Function::getIsStatic() {
	return this->isStatic;
}

void Function::setIsFinal(char* isFinal) {
	this->isFinal = (isFinal == "final") ? true : false;
}

bool Function::getIsFinal() {
	return this->isFinal;
}

void Function::setReturnType(char* returnType) {
	this->returnType = returnType;
}

char* Function::getReturnType() {
	return this->returnType;
}

void Function::setModifier(char* modifier) {
	if (modifier == "public")
		this->modifier = "public";
	else if (modifier == "private")
		this->modifier = "private";
	else if (modifier == "protected")
		this->modifier = "protected";
	else
		this->modifier = "public";
}

char* Function::getModifier() {
	return this->modifier;
}

void Function::setScope(Scope* m){
	this->scope = m;
}

Scope * Function::getScope(){
	return this->scope;
}
//=======================================
SymbolTable::SymbolTable(void){
	this->rootScope = new Scope();
	this->currScope = this->rootScope;
}

SymbolTable::~SymbolTable(void){

}

Variable * SymbolTable::insertVariableInCurrentScope(char* name){
	Variable * v = this->getVariableFromCurrentScope(name);
	if(v){
		return 0;//item is exist previously
	}
	else{
		v = new Variable();
		v->setName(name);
		this->currScope->m->put(name, v);
	}
	return v;
}
Variable * SymbolTable::getVariableFromCurrentScope(char* name){
	Variable * v = (Variable*)this->currScope->m->get(name);
	if(!v){
		Scope * temp = this->currScope->parent;
		while(temp && !v){
			v = (Variable*)temp->m->get(name);
			temp = temp->parent;
		}
	}
	return v;
}
