#include "AST.h"


char* arr[] =
{
	"IfStatmentNode", "WhileNode",
	"DoWhileNode",
	"ForNode",
	"expressionNode", "SwitchStatmentNode",

	"functionListNode", "functionNode",
	"functionHeaderNode", "functionBodyNode", 
	"MethodCall", "MethodAccess", "QualifiedNamePIdentifier",
	
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
	
	"ElseStatementNode", "IfElseStatment",

	"classHeader", "classNode",
	"classListNode", "ClassBody",
	"ClassAllocationExpression",




	"FildDeclarationList", "FildDeclarationNode",
	"DataMemberNode", "DataMemberList",


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

TreeNode * AST::createNodeData(DataMember** arr){
	int i = 0;
	int count = 0;
	TreeNode * tn = new TreeNode();
	while (arr[i] != NULL){
		count++;
		i++;
	}
	if (count == 1){
		tn = this->createNode(0, 0, DataMemberList);
		tn = this->addToLastRight(tn, this->createNode(0, 0, DataMemberNode, arr[0]));
	}
	else{
		tn = this->createNode(0, 0, DataMemberList);
		for (int j = 0; j < count; j++){
			tn = this->addToLastRight(tn, this->createNode(0, 0, DataMemberNode, arr[j]));
		}
	}
	return tn;
}

TreeNode * AST::createNodeVar(Variable** arr , TreeNode * t){
	int i = 0;
	int count = 0;
	TreeNode * tn = new TreeNode();
	while (arr[i] != NULL){
		count++;
		i++;
	}
	if (count == 1){
		tn = this->createNode(0, 0, VariableList);
		tn = this->addToLastRight(tn, this->createNode(t, 0, LocalVariableNode, arr[0]));
	}
	else{
		tn = this->createNode(0, 0, VariableList);
		for (int j = 0; j < count; j++){
			tn = this->addToLastRight(tn, this->createNode(0, 0, LocalVariableNode, arr[j]));
		}
		tn->left = t;
	}
	return tn;
}

TreeNode * AST::addToLastRight(TreeNode * basic, TreeNode* newItem){
	if (basic){
		TreeNode * temp = basic;
		while (temp->right)
			temp = temp->right;
		temp->right = newItem;
	}
	return basic;
}

Type * AST::checkMapForType(MyMap * m){
	Type * s = NULL;
	for (int i = 0; i < 71; i++)
	{
		if (m->arr[i])
		{
			if (m->arr[i]->getStrc() == TYPE){
				s = (Type *)m->arr[i]->getElem();
			}
		}
	}
	return s;
}

TreeNode * AST::checkLeft(TreeNode * tn, string s){
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

TreeNode * AST::checkRight(TreeNode * tn, string s){
	TreeNode * res = NULL;
	this->q.push(tn);
	while (!this->q.empty()){
		TreeNode * temp = this->q.front();
		this->q.pop();
		if (arr[temp->nodeType] == s){
			res = temp;
		}
		if (temp->right && temp->visited != 1){
			this->q.push(temp->right);
		}
		temp->visited = 1;
	}
	this->makeVisitedZero(tn);
	return res;
}

bool AST::checkVariable(void * elem , TreeNode * f){

	char * v = (char *) elem;
	Function *fun = (Function *)f->elem;
	Parameter * param = NULL;

	if (!fun->pl->isEmpty()){
		param = fun->pl->find(v);
	}
	if (fun->getScope()->m->get(v) || param != NULL || fun->getScope()->parent->m->get(v)){
		return true;
	}
	else{
		return false;
	}
}

void AST::makeVisitedZero(TreeNode * tn){
	this->q.push(tn);
	while (!this->q.empty()){
		TreeNode * temp = this->q.front();
		this->q.pop();
		if (temp->left){
			this->q.push(temp->left);
		}
		if (temp->right){
			this->q.push(temp->right);
		}
		temp->visited = 0;
	}
}

TreeNode ** AST::getNodes(TreeNode * tn , string s){
	TreeNode ** res = new TreeNode*[20];
	for (int i = 0; i < 20; i++)
	{
		res[i] = NULL;
	}

	int i = 0;
	this->q.push(tn);
	while (!this->q.empty()){
		TreeNode * temp = this->q.front();
		this->q.pop();
		if (arr[temp->nodeType] == s ){
			res[i] = temp;
			i++;
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


void AST::checkFunctionStmtOrVar(TreeNode * tn, TreeNode * func, TreeNode * Exp){
	bool varcheck = false;
	Function * fun = (Function *)func->elem;
	if (tn != NULL){
		TreeNode * variableExp = checkLeft(tn, "UnaryExpressionListNode");
		TreeNode * whileNode = checkLeft(tn, "WhileNode");
		TreeNode * ifStmtNode = checkLeft(tn, "IfStatmentNode");
		if (ifStmtNode){
			TreeNode * ifExpVar = checkLeft(ifStmtNode, "QualifiedName");
			varcheck = this->checkVariable(ifExpVar->elem, func);
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
			varcheck = this->checkVariable(whileExpVar->elem, func);
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
			TreeNode * methodCall = checkLeft(variableExp, "MethodCall");
			if (!checkifVar && !checkWhileVar && !methodCall) {
				
				TreeNode * v = checkLeft(variableExp, "QualifiedName");
				varcheck = this->checkVariable(v->elem, func);
				if (!varcheck){
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
				this->checkFunctionStmtOrVar(tn->right, func, whileNode);
			}
			if (ifStmtNode){
				this->checkFunctionStmtOrVar(tn->right, func, ifStmtNode);
			}
			if (variableExp){
				this->checkFunctionStmtOrVar(tn->right, func, NULL);
			}
		}
		if (whileNode && whileNode->right){
			this->checkFunctionStmtOrVar(whileNode->right, func, whileNode);
		}
		if (ifStmtNode && ifStmtNode->right){
			this->checkFunctionStmtOrVar(ifStmtNode->right, func, ifStmtNode);
		}
		
	}
}

void AST::firstCheckVariableCheck(TreeNode * tn, MyParser * p){
	
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

	temp = this->checkLeft(tn,"ComplexPrimary");

	if (temp){
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
	TreeNode * classNode = this->checkLeft(tn, "classNode");
	if (classNode) {
		TreeNode * classBody = this->checkRight(classNode, "ClassBody");
		TreeNode ** funcList = this->getNodes(classBody, "functionBodyNode");
		int i = 0;
		if (funcList) {
			while (funcList[i] != NULL) {
				TreeNode * classBody = this->checkRight(classNode, "ClassBody");
				TreeNode * methodCall = this->checkLeft(funcList[i], "MethodCall");
				if (methodCall) {
					TreeNode * methodCallFunctionName = this->checkLeft(methodCall, "QualifiedName");
					Type * type = (Type *)classNode->elem;
					if (!type->getScope()->m->get((char*)methodCallFunctionName->elem)) {
						cout << "Error : Function -> " << (char*)methodCallFunctionName->elem << " is not defined" << endl;
					}
				}
				i++;
			}
		}
	}
}


void AST::check(TreeNode * tn,int val,MyParser * p){
	Type * t = this->checkMapForType(p->st->currScope->m);
	this->firstCheckVariableCheck(tn, p);
	this->secondCheckInitVariable(tn, p);
	this->checkMethodCall(tn);
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
