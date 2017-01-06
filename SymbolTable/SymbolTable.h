#pragma once
#ifndef __Symbol_Table__
#define __Symbol_Table__
#include "MyMap.h"

enum structure {
	TYPE = 0,
	FUNCTION,
	DATAMEMBER,
	LOCALVARIABLE,
	PARAMETER
};

class Scope {
public:
	Scope();
	Scope * parent;
	MyMap * m;
};
class Parameter {
private:
	char* name;
	char* type;
	bool isFinal;
public:
	enum structure strc;
	Parameter* next;
	Parameter();
	Parameter(Parameter* parameter);
	~Parameter();
	void setName(char* n);
	char* getName();
	void setType(char* type);
	char* getType();
	void setIsFinal(bool isFinal);
	bool getIsFinal();
	bool isPrimitiveType(char* type);
	bool equals(Parameter* p);
};

template <class T>
class List {
private:
	T* current;
	T* root;
public:
	int size;

	List<T>::List() {
		this->root = NULL;
		this->current = this->root;
		this->size = 0;
	}

	List<T>::List(List<T>* l) {
		this->root = l->root;
		this->current = l->current;
		this->size = l->size;
		l->root = NULL;
		l->current = NULL;
		l->size = 0;
	}

	List<T>::~List() {}

	T* List<T>::find(char* name) {
		T* curr = this->root;
		while (curr) {
			if (strcmp(curr->getName(), name) == 0) {
				return curr;
			}
			curr = curr->next;
		}
		return NULL;
	}

	T* List<T>::add(T* t) {
		if (!this->find(t->getName())) {
			if (!this->root) {
				this->root = t;
				this->root->next = NULL;
				this->current = this->root;
			}
			else {
				this->current->next = t;
				this->current = current->next;
				this->current->next = NULL;
			}
			this->size++;
			return this->current;
		}
		return NULL;
	}

	bool List<T>::remove(char* name) {
		T* curr = this->root;
		T* prev = NULL;
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

	bool List<T>::equals(List<T>* l) {
		T* plTemp = l->root;
		T* thisTemp = this->root;
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

	bool List<T>::isEmpty() {
		return (this->root == NULL);
	}

	void List<T>::print() {
		T* current = this->root;
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
};

class Variable {
private: 
	char* name;
	char* type;
	bool isFinal;
public:
	enum structure strc;
	Variable();
	~Variable();
	void setName(char* n);
	char* getName();
	void setType(char* type);
	char* getType();
	void setIsFinal(bool isFinal);
	bool getIsFinal();
	bool isPrimitiveType(char* type);
};
class DataMember {
private:
	char* name;
	char* type;
	bool isFinal;
	bool isStatic;
	bool isPublic;
	bool isPrivate;
	bool isProtected;
	void initModifiers();
public:
	enum structure strc;
	DataMember();
	~DataMember();
	void setName(char* n);
	char* getName();
	void setType(char* type);
	char* getType();
	void setIsPublic(bool isPublic);
	bool getIsPublic();
	void setIsPrivate(bool isPrivate);
	bool getIsPrivate();
	void setIsProtected(bool isProtected);
	bool getIsProtected();
	void setIsFinal(bool isFinal);
	bool getIsFinal();
	void setIsStatic(bool isStatic);
	bool getIsStatic();
	bool illegalCombinationOfModifiers();
	void printDetails();
};
class Type {
private:
	char* name;
	char* parentName;
	bool isPublic;
	bool isPrivate;
	bool isProtected;
	bool isFinal;
	bool isAbstract;
	Type* inheritedType;
	Scope * scope;
public:
	enum structure strc;
	Type();
	~Type();
	void checkForAbstraction();
	void setName(char* n);
	char* getName();
	void setParentName(char* n);
	char* getParentName();
	void setInheritedType(Type* e);
	Type* getInheritedType();
	void setIsFinal(bool isFinal);
	bool getIsFinal();
	void setIsPublic(bool isPublic);
	bool getIsPublic();
	void setIsPrivate(bool isPrivate);
	bool getIsPrivate();
	void setIsProtected(bool isProtected);
	bool getIsProtected();
	void setIsAbstract(bool isAbstract);
	bool getIsAbstract();
	bool illegalCombinationOfModifiers();
	void setScope(Scope * m);
	Scope * getScope();
	void printDetails();
};
class Function {
private:
	char* name;
	bool isPublic;
	bool isPrivate;
	bool isProtected;
	bool isStatic;
	bool isFinal;
	bool isAbstract;
	bool isNative;
	bool isSynchronized;
	bool isTransient;
	bool isVolatile;
	bool isConstructor;
	Scope * scope;
	char* returnType;
	void initModifiers();
public:
	enum structure strc;
	List<Parameter>* pl;
	Parameter** parameters;
	Function();
	~Function();
	bool equals(Function* f);
	void printDetails();
	int checkMethodBody(bool methodBody);
	bool isOverloadingState(Function* f);
	bool constructorModifiersError();
	bool illegalCombinationOfModifiers();
	void setName(char* name);
	char* getName();
	void setIsPublic(bool isPublic);
	bool getIsPublic();
	void setIsPrivate(bool isPrivate);
	bool getIsPrivate();
	void setIsProtected(bool isProtected);
	bool getIsProtected();
	void setIsStatic(bool isStatic);
	bool getIsStatic();
	void setIsFinal(bool isFinal);
	bool getIsFinal();
	void setIsAbstract(bool isAbstract);
	bool getIsAbstract();
	void setIsNative(bool isNative);
	bool getIsNative();
	void setIsSynchronized(bool isSynchronized);
	bool getIsSynchronized();
	void setIsTransient(bool isTransient);
	bool getIsTransient();
	void setIsVolatile(bool isVolatile);
	bool getIsVolatile();
	void setReturnType(char* returnType);
	char* getReturnType();
	void setScope(Scope* m);
	bool getIsConstructor();
	void setIsConstructor(bool isConstructor);
	Scope* getScope();
};
//=============================
class Modifier;
class SymbolTable
{
private:
	void checkAtTheEnd(Scope* scope, int index);
	void checkMethodOverriding(Scope* scope, int i, int index);
	void checkTypeInheritance(Scope* scope, int index);
	void checkCyclicInheritance(Scope* scope, int index);
	void checkMainMethod(Scope* scope, int i, int index);
public:
	Scope * currScope;
	Scope * rootScope;
	bool hasMainMethod;
	Type* getTypeParent(char* name);
	Type* getTypeParentByScope(Scope* scope, char* name);
	Variable * insertVariableInCurrentScope(char* name, Modifier* m);
	Variable * getVariableFromCurrentScope(char* name);
	Parameter * createParam(char* name, Modifier* m);
	Parameter * getParameterFromCurrentFunction(char* name);
	DataMember * insertDataMemberInCurrentScope(char* name, Modifier* m);
	DataMember * getDataMemberFromCurrentScope(char* name);
	void print(Scope* scope);
	SymbolTable(void);
	~SymbolTable(void);
};
#endif