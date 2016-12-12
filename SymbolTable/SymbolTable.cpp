#include "SymbolTable.h"
//============= Scope   ================
Scope::Scope(){
	this->m = new MyMap();
	this->parent = 0;
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

void Modifier::setIsTransient(bool isTransient ){
	this->isTransient = isTransient;
}

void Modifier::setIsVolatile(bool isVolatile) {
	this->isVolatile = isVolatile;
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
	this->returnType = new char[255];
	this->returnType[0] = '\0';
	this->scope = new Scope();
}

Function::~Function(){}

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
