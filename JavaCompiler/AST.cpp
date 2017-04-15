#include "AST.h"
#include<list>


//==============nodeList==================
nodeList::nodeList() {
	this->root = NULL;
	this->current = this->root;
	this->size = 0;
}

nodeList::nodeList(nodeList* tl) {
	this->root = tl->root;
	this->current = tl->current;
	this->size = tl->size;
	tl->root = NULL;
	tl->current = NULL;
	tl->size = 0;
}

nodeList::~nodeList() {}

Node * nodeList::getRoot(){
	return this->root;
}

void nodeList::add(Node* node) {
		if (!this->root) {
			this->root = node;
			this->root->next = NULL;
			this->current = this->root;
		}
		else {
			this->current->next = node;
			this->current = this->current->next;
			this->current->next = NULL;
		}
		this->size++;
}

void nodeList::print() {
	Node* current = this->root;
	AST * ast  = new AST();
	while (current) {
		cout << "File name :" << current->filename << endl;
		ast->print(current->tn,0);
		if (current->next) {
			cout << "------------------------------------------------------";
			current = current->next;
		}
		else {
			return;
		}
	}
}

//========================================

char* arr[] =
{
	"IfStatmentNode", "WhileNode",
	"DoWhileNode",
	"ForNode",
	"expressionNode", "SwitchStatmentNode",

	"functionListNode", "functionNode",
	"functionHeaderNode", "functionBodyNode",
	"MethodCall", "MethodAccess",
	"QualifiedNamePIdentifier", "FieldAccess",
	"NotJustNameFieldAccess", "SpecialNameThis",


	"VariableList", "parameterNode", "parameterNodeList",
	"VariableDeclaratorListNode", "VariableDeclaratorNode",

	"ConstructorNode", "ConstructorHeaderNode",
	"ConstructorBodyNode", "TryNode",
	"catchNode", "catchHeaderNode",
	"finallyNode", "NotJustName",
	"ComplexPrimary", "Integer_Value",
	"QualifiedName", "Assign",
	"Float_Value", "Char_Value",
	"Long_Value", "String_Value",
	"booleanType", "charType",
	"byteType", "shortType",
	"intType", "longType",
	"floatType", "doubleType",
	"voidType", "StringType",

	"ElseStatementNode", "IfElseStatment",

	"classHeader", "classNode",
	"classListNode", "ClassBody",
	"ClassAllocationExpression", "ArgumentList",
	"TypeName", "NewOfObject",
	"NewAllocationExpression", "classInnerNode",
	"InnerClassHeader",




	"FildDeclarationList", "FildDeclarationNode",
	"DataMemberNode", "DataMemberList",
	"SpecialNameSuper",

	"LocalVariableNode", "LocalVarOrStmtNode",
	"LocalVarOrStmtListNode", "EmptyStatementNode",
	"LabelStatementNode", "EmptyBlock",
	"ArrayAllocationExpression", "DimExprListNode",
	"DimExpr", "PlainNewAllocationExpression",
	"VariableInitializer", "ArrayInitializerListNode",

	"ExpressionNode", "ConditionalExpressionListNode", "ConditionalOrExpressionListNode",
	"ConditionalAndExpressionListNode", "ExclusiveOrExpressionListNode", "AndExpressionListNode",
	"EqualityExpressionListNode", "RelationalExpressionListNode", "ShiftExpressionListNode",
	"AdditiveExpressionListNode", "MultiplicativeExpressionListNode", "CastExpressionListNode",
	"AssignExpressionListNode", "UnaryExpressionListNode", "ArithmeticUnaryOperatorNode",
	"LogicalUnaryExpressionNode", "LogicalUnaryOperatorNode", "PostfixExpressionNode",
	"RealPostfixExpressionNode", "PrimaryExpressionNode", "InclusiveOrExpressionListNode",
	"JumpStatementNode"
};

AST::AST(void)
{
}

AST::~AST(void)
{
}

TreeNode * AST::createNode(TreeNode * l, TreeNode* r, NodeType nt){
	TreeNode * tn = new TreeNode();
	tn->nodeType = nt;
	tn->left = l;
	tn->right = r;
	return tn;
}

TreeNode * AST::createNode(TreeNode * l, TreeNode* r, NodeType nt, void * e){
	TreeNode * tn = new TreeNode();
	tn->nodeType = nt;
	tn->left = l;
	tn->right = r;
	tn->elem = e;
	return tn;
}

TreeNode * AST::createNodeData(DataMember** arr) {
	int count = 0;
	TreeNode * tn = new TreeNode();
	while (arr[count] != NULL) {
		count++;
	}
	tn = this->createNode(0, 0, DataMemberList);
	for (int j = 0; j < count; j++) {
		tn = this->addToLastRight(tn, this->createNode(0, 0, DataMemberNode, arr[j]));
	}
	return tn;
}

TreeNode * AST::createNodeVar(Variable** arr , TreeNode * t) {

	int count = 0;
	TreeNode * tn = new TreeNode();
	while (arr[count] != NULL) {
		count++;
	}
	if (count == 1) {
		tn = this->createNode(0, 0, VariableList);
		tn = this->addToLastRight(tn, this->createNode(t, 0, LocalVariableNode, arr[0]));
	}
	else{
		tn = this->createNode(0, 0, VariableList);
		for (int j = 0; j < count; j++) {
			tn = this->addToLastRight(tn, this->createNode(0, 0, LocalVariableNode, arr[j]));
		}
		tn->left = t;
	}
	return tn;
}

TreeNode * AST::addToLastRight(TreeNode * basic, TreeNode* newItem) {
	if (basic) {
		TreeNode * temp = basic;
		while (temp->right)
			temp = temp->right;
		temp->right = newItem;
	}
	return basic;
}

Type * AST::checkMapForType(MyMap * m) {
	Type * s = NULL;
	for (int i = 0; i < 71; i++)
	{
		if (m->arr[i])
		{
			if (m->arr[i]->getStrc() == TYPE) {
				s = (Type *)m->arr[i]->getElem();
			}
		}
	}
	return s;
}

TreeNode * AST::checkLeft(TreeNode * tn, string s) {
	TreeNode * res = NULL;
	this->q.push(tn);
	while (!this->q.empty()) {
		TreeNode * temp = this->q.front();
		this->q.pop();
		if (arr[temp->nodeType] == s) {
			res = temp;
		}
		if (temp->left && temp->visited != 1) {
			this->q.push(temp->left);
		}
		temp->visited = 1;
	}
	this->makeVisitedZero(tn);
	return res;
}

TreeNode * AST::checkall(TreeNode * tn, string s){
	TreeNode * res = NULL;
	this->q.push(tn);
	while (!this->q.empty()){
		TreeNode * temp = this->q.front();
		this->q.pop();
		if (arr[temp->nodeType] == s){
			res = temp;
		}
		if (temp->left && temp->visited != 1){
			this->q.push(temp->left);
		}
		if (temp->right && temp->visited != 1){
			this->q.push(temp->right);
		}
		temp->visited = 1;
	}
	this->makeVisitedZero(tn);
	return res;
}

TreeNode * AST::checkRight(TreeNode * tn, string s) {
	TreeNode * res = NULL;
	this->q.push(tn);
	while (!this->q.empty()) {
		TreeNode * temp = this->q.front();
		this->q.pop();
		if (arr[temp->nodeType] == s) {
			res = temp;
		}
		if (temp->right && temp->visited != 1) {
			this->q.push(temp->right);
		}
		temp->visited = 1;
	}
	this->makeVisitedZero(tn);
	return res;
}

bool AST::checkVariable(void * elem , TreeNode * f) {

	char * v = (char *) elem;
	Function *fun = (Function *)f->elem;
	Parameter * param = NULL;

	bool check = false;
	Scope * p = fun->getScope()->parent->parent;
	while (p != NULL) {
		if (p->m->get(v)) {
			check = true;
			DataMember * datamember = (DataMember *)p->m->get(v);
			Type * t = (Type *)fun->getScope()->parent->scopeOwner;
			Type * datamemberClass = (Type *)p->scopeOwner;
			if (t->getIsStatic()) {
				if (!datamember->getIsStatic()) {
					cout << "Error : Class " << t->getName() << " is static " << "DataMember " << datamember->getName() << " non static in class " << datamemberClass->getName() << endl;
				}
			}
		}
		p = p->parent;
	}

	if (!fun->pl->isEmpty()){
		param = fun->pl->find(v);
	}
	if (fun->getScope()->m->get(v) || param != NULL || fun->getScope()->parent->m->get(v)) {
		check = true;
	}


	return check;
}

Variable * AST::getVariable(void * elem, TreeNode * f) {

	char * v = (char *) elem;
	Function* fun = (Function *)f->elem;
	Parameter * param = NULL;

	Variable * var = NULL;

	if (!fun->pl->isEmpty()) {
		param = fun->pl->find(v);
	}
	if (fun->getScope()->m->get(v) || param != NULL || fun->getScope()->parent->m->get(v)) {
		if (fun->getScope()->m->get(v)) {
			var = (Variable *)fun->getScope()->m->get(v);
		}
		else if (param) {
			var->setName(param->getName());
			var->setType(param->getType());
			var->setIsFinal(param->getIsFinal());
		}
		else if (fun->getScope()->parent->m->get(v)) {
			var = (Variable *)fun->getScope()->parent->m->get(v);
		}
	}
	return var;
}

void AST::makeVisitedZero(TreeNode * tn) {
	this->q.push(tn);
	while (!this->q.empty()) {
		TreeNode * temp = this->q.front();
		this->q.pop();
		if (temp->left) {
			this->q.push(temp->left);
		}
		if (temp->right) {
			this->q.push(temp->right);
		}
		temp->visited = 0;
	}
}

TreeNode ** AST::getNodes(TreeNode * tn , string s) {
	TreeNode ** res = new TreeNode*[20];
	for (int i = 0; i < 20; i++) {
		res[i] = NULL;
	}

	int i = 0;
	this->q.push(tn);
	while (!this->q.empty()) {
		TreeNode * temp = this->q.front();
		this->q.pop();
		if (arr[temp->nodeType] == s ) {
			res[i] = temp;
			i++;
		}
		if (temp->left && temp->visited != 1) {
			this->q.push(temp->left);
		}
		if (temp->right && temp->visited != 1) {
			this->q.push(temp->right);
		}
		temp->visited = 1;
	}
	this->makeVisitedZero(tn);
	return res;
}


void AST::checkFunctionStmtOrVar(TreeNode * tn, TreeNode * funcNode, TreeNode * Exp){
	bool varcheck = false;
	Function * fun = (Function *)funcNode->elem;
	if (tn != NULL){
		TreeNode * variableExp = checkLeft(tn, "UnaryExpressionListNode");
		TreeNode * whileNode = checkLeft(tn, "WhileNode");
		TreeNode * ifStmtNode = checkLeft(tn, "IfStatmentNode");
		if (ifStmtNode){
			TreeNode * ifExpVar = checkLeft(ifStmtNode, "QualifiedName");
			varcheck = this->checkVariable(ifExpVar->elem, funcNode);
			if (!varcheck){
				char * name = (char *)ifExpVar->elem;
				char * var = new char[255];
				var[0] = '\0';
				strcat(var, name);

				cout << "Error : variable " << var << " in Function: " << fun->getName() << " Is not defined" << endl;
			}
		}
		else if (whileNode){
			TreeNode * whileExpVar = checkLeft(whileNode, "QualifiedName");
			varcheck = this->checkVariable(whileExpVar->elem, funcNode);
			if (!varcheck){
				char * name = (char *)whileExpVar->elem;
				char * var = new char[255];
				var[0] = '\0';
				strcat(var, name);

				cout << "Error : variable " << var << " in Function: " << fun->getName() << " Is not defined" << endl;
			}
		}
		else if (variableExp){
			bool checkifVar = false;
			bool checkWhileVar = false;
			char * name = NULL;

			if (Exp){
				if (Exp->nodeType == IfStatmentNode){
					TreeNode * ifStmt = Exp;
					TreeNode ** varList = this->getNodes(ifStmt, "LocalVariableNode");
					int j = 0;

					if (varList){
						while (varList[j] != NULL){
							Variable * var = (Variable *)varList[j]->elem;
							if (name == var->getName()){
								checkifVar = true;
								break;
							}
							j++;
						}
					}
				}
				else if (Exp->nodeType == WhileNode){
					TreeNode * whileStmt = Exp;
					TreeNode ** varList = this->getNodes(whileStmt, "LocalVariableNode");

					TreeNode * whileRight = checkRight(whileStmt,"LocalVarOrStmtListNode");
					TreeNode * whilevar = checkLeft(whileRight,"QualifiedName");
					if (whilevar){
						name = (char *)whilevar->elem;
						int j = 0;
						if (varList){
							while (varList[j] != NULL){
								
								Variable * var = (Variable *)varList[j]->elem;
								if (name == var->getName()){
									checkWhileVar = true;
									break;
								}
								j++;
							}
						}
					}
				}
			}
			TreeNode * v = checkLeft(variableExp, "QualifiedName");
			TreeNode * thisBeforVar = checkLeft(variableExp,"NotJustNameFieldAccess");
			TreeNode * methodCall = checkLeft(variableExp, "MethodCall");
			if (methodCall) {
				TreeNode * objectBeforMethodCall = this->checkLeft(methodCall, "QualifiedNamePIdentifier");
				if (objectBeforMethodCall) {
					TreeNode * objectName = this->checkLeft(methodCall, "QualifiedName");
					varcheck = this->checkVariable(objectName->elem, funcNode);
					if (!varcheck){
						name = (char*)objectName->elem;
						Variable * classOfObject = this->getVariable(name, funcNode);

						cout << "Error : variable " << classOfObject->getName() << " in Function: " << fun->getName() << " Is not defined" << endl;
					}
				}
			}
			if (!checkifVar && !checkWhileVar && !thisBeforVar && v && !methodCall) {
				varcheck = this->checkVariable(v->elem, funcNode);
				bool inheritanceParent = false;
				if (!fun->getIsStatic()) {
					Type * type = (Type*)fun->getScope()->parent->scopeOwner;
					char * name = (char*)v->elem;
					inheritanceParent = this->existInParent(type, name);
				}
				if (!varcheck && !inheritanceParent){
					name = (char*)v->elem;
					char * var = new char[255];
					var[0] = '\0';
					strcat(var, name);

					cout << "Error : variable " << var << " in Function: " << fun->getName() << " Is not defined" << endl;
				}
			}
		}
		if (tn->right != NULL){
			TreeNode * variableExp = NULL;
			TreeNode * whileNode = checkLeft(tn->right, "WhileNode");
			TreeNode * ifStmtNode = checkLeft(tn->right, "IfStatmentNode");
			if (!whileNode && !ifStmtNode){
				variableExp = checkLeft(tn->right, "UnaryExpressionListNode");;
			}
			if (whileNode){
				this->checkFunctionStmtOrVar(tn->right, funcNode, whileNode);
			}
			if (ifStmtNode){
				this->checkFunctionStmtOrVar(tn->right, funcNode, ifStmtNode);
			}
			if (variableExp){
				this->checkFunctionStmtOrVar(tn->right, funcNode, NULL);
			}
		}
		if (whileNode && whileNode->right){
			this->checkFunctionStmtOrVar(whileNode->right, funcNode, whileNode);
		}
		if (ifStmtNode && ifStmtNode->right){
			this->checkFunctionStmtOrVar(ifStmtNode->right, funcNode, ifStmtNode);
		}
		
	}
}

void AST::firstCheckVariableCheck(TreeNode * tn, MyParser * p){
	

	TreeNode * firstClassNode = this->checkLeft(tn, "classNode");
	TreeNode ** funcList = this->getNodes(tn,"functionNode");
	int i = 0;

	if (funcList){
		while (funcList[i] != NULL){
			TreeNode * funcBody = checkRight(funcList[i], "functionBodyNode");
			if (funcBody){
				TreeNode * elements = checkLeft(funcBody, "LocalVarOrStmtListNode");
				this->checkFunctionStmtOrVar(elements, funcList[i], NULL);
			}
			i++;
		}
	}
}

bool AST::CheckInitVariable(TreeNode * tn){
	bool check = false;
	TreeNode * temp;
	TreeNode * checkNewClass;

	temp = this->checkLeft(tn,"ComplexPrimary");
	checkNewClass = this->checkLeft(tn, "ClassAllocationExpression");

	if (temp || checkNewClass){
		check = true;
	}

	return check;
}

void AST::secondCheckInitVariable(TreeNode * tn, MyParser * p){
	bool varcheckInit;
	TreeNode * temp;

	TreeNode ** funcList = this->getNodes(tn,"functionNode");
	int i = 0;
	if (funcList){
		while (funcList[i] != NULL){
			varcheckInit = false;

			TreeNode ** varList = this->getNodes(funcList[i],"LocalVariableNode");
			if (varList){
				int j = 0;
				while (varList[j]){
					varcheckInit = this->CheckInitVariable(varList[j]);
					if (!varcheckInit){
						Function * fun = (Function *)funcList[i]->elem;
						Variable * var = (Variable *)varList[j]->elem;
						cout << "Warning : Variable -> " << var->getName() << " in Function : " << fun->getName() << " not Initialized" << endl;
					}
					j++;

				}
			}
			i++;
		}
	}
}

void AST::checkMethodCall(TreeNode * tn) {


	Node * current = this->list->getRoot();
	Type ** classNodes = new Type*[20];
	int count = 0;
	for (int i = 0; i < 20; i++)
	{
		classNodes[i] = NULL;
	}
	while (current) {
		TreeNode * currClass = this->checkLeft(current->tn, "classNode");
		Type * t = (Type*)currClass->elem;
		classNodes[count] = t;
		count++;
		current = current->next;
	}


	TreeNode * classNode = this->checkLeft(tn, "classNode");
	if (classNode) {
		TreeNode * classBody = this->checkRight(classNode, "ClassBody");
		TreeNode ** funcList = this->getNodes(classBody, "functionNode");
		int i = 0;
		if (funcList) {
			while (funcList[i] != NULL) {
				Function * fun = (Function *)funcList[i]->elem;
				TreeNode * funBody = this->checkRight(funcList[i] , "functionBodyNode");
				if (funBody) {
					TreeNode ** elemFunBody = this->getNodes(funBody, "LocalVarOrStmtListNode");
					if (elemFunBody) {
						int j = 0;
						while (elemFunBody[j]) {
							TreeNode * methodCall = this->checkLeft(elemFunBody[j], "MethodCall");
							if (methodCall) {
								bool checkFunctionParent = false;
								char * methodCallName = NULL;
								TreeNode * thisBeforMethodCall = this->checkLeft(methodCall, "NotJustNameFieldAccess");
								TreeNode * objectBeforMethodCall = this->checkLeft(methodCall, "QualifiedNamePIdentifier");
								TreeNode * methodCallFunctionNameNode;
								if (fun->getIsStatic()) {//quastion 17 checkMethodCall
									if (!objectBeforMethodCall) {
										methodCallFunctionNameNode = this->checkLeft(methodCall, "QualifiedName");
										methodCallName = (char*)methodCallFunctionNameNode->elem;
										if (fun->getScope()->parent->m->get(methodCallName)) {
											Function * reqFunction = (Function *)fun->getScope()->parent->m->get(methodCallName);
											if (reqFunction && reqFunction->strc == FUNCTION && !reqFunction->getIsStatic()) {
												cout << "Error : non-static Function " << reqFunction->getName() << " cannot be referenced from a static context" << endl;
											}
										}
									}
								}
								if (thisBeforMethodCall) {
									if (fun->getIsStatic()) {
										cout << "Error : Function " << fun->getName() << " is static illegal use of (this)" << endl;
									}
									methodCallFunctionNameNode = this->checkLeft(methodCall, "QualifiedName");
									methodCallName = (char*)methodCallFunctionNameNode->elem;
									Type * type = (Type *)classNode->elem;
									checkFunctionParent = this->existInParent(type, methodCallName);
									if (methodCallFunctionNameNode && !type->getScope()->m->get(methodCallName) && !checkFunctionParent) {
										cout << "Error : Function -> " << methodCallName << " is not defined" << endl;
									}
								}
								else if (objectBeforMethodCall) {
									methodCallFunctionNameNode = this->checkLeft(methodCall, "QualifiedNamePIdentifier");
									if (methodCallFunctionNameNode) {
										char * className;
										TreeNode * objectName = this->checkLeft(methodCallFunctionNameNode, "QualifiedName");
										char * name = (char*)objectName->elem;
										Variable * var = this->getVariable(name, funcList[i]);
										if (var){
											className = var->getType();
											int k = 0;
											while (classNodes[k]) {
												if (strcmp(classNodes[k]->getName(), className) == 0){
													methodCallName = (char *)methodCallFunctionNameNode->elem;
													checkFunctionParent = this->existInParent(classNodes[k], methodCallName);
													if (!classNodes[k]->getScope()->m->get(methodCallName) && !checkFunctionParent) {
														cout << "Error : Function " << methodCallName << " is not defined in Class " << classNodes[k]->getName() << endl;
													}
													break;
												}
												k++;
											}
										}
									}
								}
								else {
									methodCallFunctionNameNode = this->checkLeft(methodCall, "QualifiedName");
									if (methodCallFunctionNameNode) {
										methodCallName = (char*)methodCallFunctionNameNode->elem;
										Type * type = (Type *)classNode->elem;
										if (!fun->getIsStatic()) {
											checkFunctionParent = this->existInParent(type, methodCallName);
										}
										if (!type->getScope()->m->get(methodCallName) && !checkFunctionParent) {
											cout << "Error : MethodCall -> " << methodCallName << " in Function " << fun->getName() << " is not defined" << endl;
										}
									}
								}

							}
							else { // for quastion number 18
								TreeNode * thisInStatic = this->checkLeft(elemFunBody[j], "NotJustNameFieldAccess");
								if (thisInStatic) {
									TreeNode * dataMemberNameNode = this->checkLeft(thisInStatic, "QualifiedName");
									char * dataMemberName = (char*)dataMemberNameNode->elem;
									if (fun->getIsStatic()) {
										cout << "Error : Function " << fun->getName() << " is static illegal use of (this)" << endl;
									}
									else {
										Type * type = (Type*)fun->getScope()->parent->scopeOwner;
										bool dataMemberParent = this->existInParent(type, dataMemberName);
										if (!type->getScope()->m->get(dataMemberName) && !dataMemberParent) {
											cout << "Error : DataMember " << dataMemberName << " in Function: " << fun->getName() << " Is not defined" << endl;
										}
									}
								}
								if (fun->getIsStatic()) {//quastion 17 checkDatamember 
									TreeNode * varName = this->checkLeft(elemFunBody[j], "QualifiedName");
									if (varName) {
										if (fun->getScope()->parent->m->get((char*)varName->elem)) {
											DataMember * reqDatamember = (DataMember*)fun->getScope()->parent->m->get((char*)varName->elem);
											if (reqDatamember && reqDatamember->strc == DATAMEMBER && !reqDatamember->getIsStatic()) {
												cout << "Error : non-static Variable " << reqDatamember->getName() << " cannot be referenced from a static context" << endl;
											}
										}
									}

								}
							}
							j++;
						}
					}

				}
				i++;
			}
		}
	}
}

bool AST::existInParent(Type* type, char *reqName) {
	
	bool check = false;
	Type * temp = type->getInheritedType();
	while (temp != NULL) {
		if (temp->getScope()->m->get(reqName)) {
			Function * function = (Function*)temp->getScope()->m->get(reqName);
			if (function && function->strc == FUNCTION) {
				check = true;
				if (function->getIsPrivate()){
					cout << "Error : Function " << reqName << " in Class " << temp->getName() << " is Private " << endl;
				}
			}
			else {
				DataMember * dataMember = (DataMember *)temp->getScope()->m->get(reqName);
				if (dataMember && dataMember->strc == DATAMEMBER) {
					check = true;
					if (dataMember->getIsPrivate()){
						cout << "Error : DataMember " << reqName << " in Class " << temp->getName() << " is Private " << endl;
					}
				}
			}
		}
		temp = temp->getInheritedType();
	}

	return check;
}

void AST::addTree(TreeNode * tn) {
	Node * n = new Node() ;
	n->tn = NULL;
	n->filename = NULL;
	if (tn != NULL) {
		n->tn = tn;
		TreeNode * classNode = this->checkLeft(tn, "classNode");
		if (classNode) {
			Type * t = (Type*)classNode->elem;
			n->filename = t->getFileName();
		}
	}
	this->list->add(n);
}

bool AST::funIsPrivate(Type * reqClass, char* functionName) {
	bool res = false;

	if (reqClass->getScope()->m->get(functionName)){
		Function * fun = (Function *)reqClass->getScope()->m->get(functionName);
		if (fun->getIsPrivate()){
			res = true;
		}
	}
	return res;
}

void AST::checkPrivateFunc(TreeNode * tn){

	Node * current = this->list->getRoot();
	Type ** classNodes = new Type*[20];
	int count = 0;
	for (int i = 0; i < 20; i++)
	{
		classNodes[i] = NULL;
	}
	while (current) {
		TreeNode * currClass = this->checkLeft(current->tn,"classNode");
		Type * t = (Type*)currClass->elem;
		classNodes[count] = t;
		count++;
		current = current->next;
	}


	TreeNode ** funcList = this->getNodes(tn, "functionNode");
	count = 0;
	if (funcList) {
		while (funcList[count] != NULL) {
			TreeNode * funbody = this->checkRight(funcList[count], "functionBodyNode");
			if (funbody){
				char * className;
				bool check = false;
				TreeNode ** elemFunBody = this->getNodes(funbody, "LocalVarOrStmtListNode");
				if (elemFunBody){
					int j = 0;
					while (elemFunBody[j]){
						TreeNode * methodCall = this->checkLeft(elemFunBody[j], "MethodCall");
						if (methodCall) {
							TreeNode * methodCallFunctionName = this->checkLeft(methodCall, "QualifiedNamePIdentifier");
							if (methodCallFunctionName) {
								TreeNode * objectName = this->checkLeft(methodCallFunctionName, "QualifiedName");
								char * name = (char*)objectName->elem;
								Variable * var = this->getVariable(name, funcList[count]);
								if (var){
									className = var->getType();
									int k = 0;
									while (classNodes[k]) {
										if (strcmp(classNodes[k]->getName(), className) == 0){
											check = this->funIsPrivate(classNodes[k], (char*)methodCallFunctionName->elem);
											if (check) {
												cout << "Error : Function " << (char*)methodCallFunctionName->elem << " in Class " << classNodes[k]->getName() << " is Private" << endl;
											}
											break;
										}
										k++;
									}
								}
							}
						}
						j++;
					}
				}
			}
			count++;
		}
	}
}

bool AST::varIsPrivate(TreeNode * reqClass, char * datamemberName){
	bool res = false;

	bool checkDatamember = false;
	//quastion 9
	bool checkDataMemberParent = false;


	DataMember * datamember = NULL;

	TreeNode ** dataList = this->getNodes(reqClass,"DataMemberNode");
	
	//quastion 9
	Type * requiredClass = (Type *)reqClass->elem;
	if (requiredClass && requiredClass->strc == TYPE ) {
		Type * temp = requiredClass->getInheritedType();
		while (temp != NULL) {
			if (temp->getScope()->m->get(datamemberName)) {
				datamember = (DataMember*)temp->getScope()->m->get(datamemberName);
				if (datamember && datamember->strc == DATAMEMBER) {
					checkDataMemberParent = true;
					if (datamember->getIsPrivate()){
						cout << "Error : Datamember " << datamemberName << " in Class " << temp->getName() << " is Private " << endl;
					}
				}
			}
			temp = temp->getInheritedType();
		}
	}


	if (dataList) {
		int i = 0;
		while (dataList[i] != NULL) {
			datamember =(DataMember*) dataList[i]->elem;
			if (strcmp(datamember->getName(), datamemberName) == 0) {
				if (datamember->getIsPrivate()){
					res = true;
				}
				checkDatamember = true;
			}
			i++;
		}
		if (!checkDatamember && !checkDataMemberParent) {
			Type * t = (Type*)reqClass->elem;
			cout << "Error : Datamember " << datamemberName << " in Class " << t->getName() << " is not defined " << endl;
		}
	}
	return res;
}

void AST::checkPrivateVar(TreeNode * tn) {
	Node * current = this->list->getRoot();
//	Type ** classNodes = new Type*[20];
	TreeNode ** classNodes = new TreeNode*[20];
	int count = 0;
	for (int i = 0; i < 20; i++)
	{
		classNodes[i] = NULL;
	}
	while (current) {
		TreeNode * currClass = this->checkLeft(current->tn, "classNode");
//		Type * t = (Type*)currClass->elem;
		classNodes[count] = currClass;
		count++;
		current = current->next;
	}

	TreeNode ** funcList = this->getNodes(tn, "functionNode");
	count = 0;
	if (funcList) {
		while (funcList[count] != NULL) {
			TreeNode * funbody = this->checkRight(funcList[count], "functionBodyNode");
			if (funbody){
				char * className;
				bool check = false;
				TreeNode ** elemFunBody = this->getNodes(funbody, "LocalVarOrStmtListNode");
				if (elemFunBody){
					int j = 0;
					while (elemFunBody[j]){
						TreeNode * methodCall = this->checkLeft(elemFunBody[j], "MethodCall");
						TreeNode * datamemberName = this->checkLeft(elemFunBody[j], "QualifiedNamePIdentifier");
						if (!methodCall){
							if (datamemberName) {
								TreeNode * objectName = this->checkLeft(datamemberName, "QualifiedName");
								char * name = (char*)objectName->elem;
								Variable * var = this->getVariable(name, funcList[count]);
								if (var){
									className = var->getType();
									int k = 0;
									while (classNodes[k]) {
										Type * t = (Type*)classNodes[k]->elem;
										if (strcmp(t->getName(), className) == 0){
											check = this->varIsPrivate(classNodes[k], (char*)datamemberName->elem);
											if (check) {
												cout << "Error : Datamember " << (char*)datamemberName->elem << " in Class " << t->getName() << " is Private" << endl;
											}
											break;
										}
										k++;
									}
								}
							}
						}
						j++;
					}
				}
			}
			count++;
		}
	}
}

void AST::checkAbstraction(TreeNode * tn) {
	Node * current = this->list->getRoot();
	Type ** classNodes = new Type*[20];
	int count = 0;
	for (int i = 0; i < 20; i++)
	{
		classNodes[i] = NULL;
	}
	while (current) {
		TreeNode * currClass = this->checkLeft(current->tn, "classNode");
		Type * t = (Type*)currClass->elem;
		classNodes[count] = t;
		count++;
		current = current->next;
	}

	TreeNode ** funcList = this->getNodes(tn, "functionNode");
	count = 0;
	if (funcList) {
		while (funcList[count] != NULL) {
			TreeNode * funbody = this->checkRight(funcList[count], "functionBodyNode");
			if (funbody){
				char * className;
				bool check = false;
				TreeNode ** elemFunBody = this->getNodes(funbody, "LocalVarOrStmtListNode");
				if (elemFunBody){
					int j = 0;
					while (elemFunBody[j]){
						TreeNode * varNodeList = this->checkLeft(elemFunBody[j], "VariableList");
						if (varNodeList) {
							TreeNode * varNode = this->checkRight(varNodeList, "LocalVariableNode");
							if (varNode) {
								TreeNode * newExp = this->checkLeft(varNode, "ClassAllocationExpression");
								if (newExp) {
									TreeNode * reqClass = this->checkLeft(newExp, "QualifiedName");
									className = (char*)reqClass->elem;
									int k = 0;
									while (classNodes[k]) {
										if (strcmp(classNodes[k]->getName(), className) == 0){
											if (classNodes[k]->getIsAbstract()) {
												cout << "Error : Class " << classNodes[k]->getName() << " is abstract,cannot be instantiated " << endl;
											}
											break;
										}
										k++;
									}

								}
							}
						}
						j++;
					}
				}
			}
			count++;
		}
	}

}

void AST::checkConstructerSuper(TreeNode * tn) {
	TreeNode * classNode = this->checkLeft(tn,"classNode");
	Type * reqClass = (Type *)classNode->elem;
	TreeNode ** constructors = this->getNodes(classNode, "ConstructorNode");
	TreeNode ** functions = this->getNodes(classNode, "functionNode");

	int count = 0;
	while (constructors[count]) {
		Function * constructor = (Function *)constructors[count]->elem;
		if (constructor && constructor->strc == FUNCTION && constructor->getIsConstructor() && reqClass->getScope()->m->get(constructor->getName())) {
			TreeNode ** constructorStmt = this->getNodes(constructors[count],"LocalVarOrStmtNode");
			int j = 0;
			while (constructorStmt[j]) {
				TreeNode * superNode = this->checkLeft(constructorStmt[j],"SpecialNameSuper");
				if (superNode && j != 0) {
					cout << "Error : call to super must be first statement in constructor in class : "<< reqClass->getName() << endl;
				}
				j++;
			}
		}
		count++;
	}

	count = 0;
	while (functions[count]) {
		Function * function = (Function *)functions[count]->elem;
		TreeNode * funBody = this->checkRight(functions[count],"functionBodyNode");
		if (funBody) {
			TreeNode ** funStmt = this->getNodes(funBody,"LocalVarOrStmtNode");
			int j = 0;
			while (funStmt[j]) {
				TreeNode * superNode = this->checkLeft(funStmt[j], "SpecialNameSuper");
				if (superNode) {
					cout << "Error : call to super must be first statement in constructor in class : " << reqClass->getName() << " in function : " << function->getName() << endl;
				}
				j++;
			}
		}
		count++;
	}

}

void AST::checkInnerClass(TreeNode * tn) {
	TreeNode * reqClass = this->checkLeft(tn, "classNode");
	Type * t = (Type*) reqClass->elem;
	TreeNode ** functions = this->getNodes(reqClass, "functionNode");
	int i = 0;

	while (functions[i]) {
		TreeNode* functionBody = this->checkRight(functions[i], "functionBodyNode");
		Function* function = (Function*)functions[i]->elem;

		if (functionBody) {
			TreeNode** functionVariables = this->getNodes(functionBody, "LocalVariableNode");
			int count = 0;

			while (functionVariables[count]) {
				Variable* var = (Variable*)functionVariables[count]->elem;

				if (var && var->getAlternativeType() && var->getAlternativeType()[0]) {
					// If there are two types, outer & inner
					if (strcmp(var->getAlternativeType(), var->getType()) != 0) {
						TreeNode* newAllocationExpressionNode = this->checkLeft(functionVariables[count], "NewAllocationExpression");
						TreeNode* outerObjectNameNode = NULL;
						char* outerObjectName = NULL;

						if (newAllocationExpressionNode) {
							outerObjectNameNode = this->checkLeft(newAllocationExpressionNode, "QualifiedName");
							if (outerObjectNameNode) {
								outerObjectName = (char*)outerObjectNameNode->elem;
							}
						}
						if (outerObjectName && !function->getScope()->m->get(outerObjectName)) {
							cout << "Error: can't find object name " << outerObjectName << "\n";
						}
					}
				}
				count++;
			}
		}
		i++;
	}
}

void AST::checkLocalInnerClass(TreeNode* tn) {
	TreeNode * reqClass = this->checkLeft(tn, "classNode");
	Type * t = (Type*)reqClass->elem;
	TreeNode ** functions = this->getNodes(reqClass, "functionNode");
	int i = 0;

	while (functions[i]) {
		TreeNode* functionBody = this->checkRight(functions[i], "functionBodyNode");
		Function* function = (Function*)functions[i]->elem;
		if (functionBody) {
			TreeNode** functionVariables = this->getNodes(functionBody, "LocalVariableNode");
			int count = 0;

			while (functionVariables[count]) {
				Variable * var = (Variable *)functionVariables[count]->elem;
				
				if (var) {
					char * varTypeName = var->getType();
					Type * check = (Type*)function->getScope()->m->get(varTypeName);
					if (check == NULL){
						int j = 0;
						while (functions[j]) {
							Function * fun = (Function*)functions[j]->elem;
							TreeNode** localInnerClassNodes = this->getNodes(functions[j], "classInnerNode");
							int k = 0;
							while (localInnerClassNodes[k]) {
								Type * type = (Type *)localInnerClassNodes[k]->elem;
								if (type && strcmp(type->getName(), varTypeName) == 0) {
									cout << "Error : inner class can be instantiated only within the method where the inner class is defined. \n";
								}
								k++;
							}
							j++;
						}
					}
				}
				count++;
			}
			
		}
		i++;
	}
}

void AST::checKReturnFunction(TreeNode * tn) {
	TreeNode * reqClass = this->checkLeft(tn, "classNode");
	TreeNode ** functions = this->getNodes(reqClass, "functionNode");
	int i = 0;

	while (functions[i]) {
		TreeNode* functionBody = this->checkRight(functions[i], "functionBodyNode");
		Function* function = (Function*)functions[i]->elem;

		if (functionBody && !(function->getReturnType() == "void")) {
			TreeNode** functionStmts = this->getNodes(functionBody, "LocalVarOrStmtNode");
			int count = 0;
			while (functionStmts[count]) {
				TreeNode * returnNode = this->checkLeft(functionStmts[count], "JumpStatementNode");
				if (returnNode) {
					TreeNode * returnVarNameNode = this->checkLeft(returnNode, "QualifiedName");
					if (returnVarNameNode) {
						char * returnVarName = (char*)returnVarNameNode->elem;
						if (returnVarName) {
							Variable * reqVar = this->getVariable(returnVarName, functions[i]);
							if (reqVar && strcmp(reqVar->getType(),function->getReturnType()) != 0) {
								cout << "Error : incompatible types : " << reqVar->getType() << " cannot be converted to " << function->getReturnType() << endl;
							}
						}
					}
				}
				count++;
			}
		}
		i++;
	}
	
}

void AST::check(MyParser * p){

	TreeNode * tn;
	cout << "\n";
	cout << "-------------------------AST----------------------------\n";
	Node* current = this->list->getRoot();

	while (current){
		if (current->filename && current->tn) {
			cout << "File name : " << current->filename << endl;
			tn = current->tn;
			this->print(tn, 0);
			Type * t = this->checkMapForType(p->st->currScope->m);
			this->firstCheckVariableCheck(tn, p);
			this->secondCheckInitVariable(tn, p);
			this->checkMethodCall(tn);
			this->checkPrivateFunc(tn);
			this->checkPrivateVar(tn);
			this->checkAbstraction(tn);
			this->checkConstructerSuper(tn);
			this->checkInnerClass(tn);
			this->checkLocalInnerClass(tn);
			this->checKReturnFunction(tn);
			/*
			TreeNode * classNode = this->checkLeft(tn, "classNode");
			TreeNode * classBody = this->checkRight(classNode, "ClassBody");

			TreeNode * funNode = this->checkLeft(classBody, "functionNode");
			if (funNode){
			TreeNode * funBode = this->checkRight(funNode, "functionBodyNode");
			if (funBode) {
			TreeNode * varl = this->checkLeft(funBode, "VariableList");
			TreeNode * var = this->checkRight(varl, "LocalVariableNode");
			Variable * v = (Variable *)var->elem;
			cout << "" << endl;
			
			}
			
			}
			*/

			current = current->next;
			cout << "-----------------------------------------------------------\n";
		}
	}
	
}

void AST::print(TreeNode * tn, int lvl){
	if (tn){
		for (int i = 0; i<lvl; i++)
			cout << "  ";
		cout << arr[tn->nodeType] << "\n";
		print(tn->left, lvl + 1);
		print(tn->right, lvl + 1);
	}
}
