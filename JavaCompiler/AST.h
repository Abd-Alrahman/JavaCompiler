#pragma once
#ifndef AST_____
#define AST_____

#include "../SymbolTable/MyParser.h"
#include <iostream>
#include <queue>
#include<list>
using namespace::std;
enum NodeType {
	//statements
	IfStatmentNode, WhileNode, DoWhileNode, ForeachHeaderNode, ForNode, ForHeaderNode, ForInit, ForExpr,
	
	expressionNode, SwitchStatmentNode,




	//function
	functionListNode, functionNode, functionHeaderNode, functionBodyNode, MethodCall, MethodAccess,
	QualifiedNamePIdentifier, FieldAccess, NotJustNameFieldAccess, SpecialNameThis,
	VariableList, parameterNode, parameterNodeList, VariableDeclaratorListNode, VariableDeclaratorNode,

	ConstructorNode,
	ConstructorHeaderNode, ConstructorBodyNode, TryNode, catchNode, catchHeaderNode, finallyNode, NotJustName, ComplexPrimary,

	//values
	Integer_Value, QualifiedName, Assign, Float_Value, Char_Value, Long_Value, String_Value, Boolean_Value,
	booleanType, charType, byteType, shortType, intType, longType, floatType, doubleType, voidType, StringType,

	ElseStatementNode, IfElseStatment,

	//class
	classHeader, classNode, classListNode, ClassBody, ClassAllocationExpression, ArgumentList, TypeName, NewOfObject,
	NewAllocationExpression, classInnerNode, InnerClassHeader,
	
	FildDeclarationList, FildDeclarationNode, DataMemberNode, DataMemberList, SpecialNameSuper,

	//type: Here AST is used as temporoy data structure to hold type to upper grammars
	LocalVariableNode, LocalVarOrStmtNode, LocalVarOrStmtListNode, EmptyStatementNode, LabelStatementNode, EmptyBlock,
	ArrayAllocationExpression, DimExprListNode, DimExpr, PlainNewAllocationExpression, VariableInitializer,
	ArrayInitializerListNode


	, ExpressionNode, ConditionalExpressionListNode, ConditionalOrExpressionListNode, ConditionalAndExpressionListNode
	, ExclusiveOrExpressionListNode
	, AndExpressionListNode, EqualityExpressionListNode, RelationalExpressionListNode, ShiftExpressionListNode, AdditiveExpressionListNode
	, MultiplicativeExpressionListNode, CastExpressionListNode, AssignExpressionListNode, UnaryExpressionListNode, ArithmeticUnaryOperatorNode, LogicalUnaryExpressionNode
	, LogicalUnaryOperatorNode, PostfixExpressionNode, RealPostfixExpressionNode,
	PrimaryExpressionNode, InclusiveOrExpressionListNode, JumpStatementNode
};


class TreeNode{
public:
	TreeNode * left;
	TreeNode * right;
	NodeType nodeType;
	void * elem;
	int visited;

};
class Node{
public:
	TreeNode * tn;
	char * filename;
	Node * next;
};
class nodeList {
private:
	Node* current;
	Node* root;
public:
	int size;
	nodeList();
	nodeList(nodeList* tl);
	~nodeList();
	void add(Node* node);
	bool isEmpty();
	void print();
	Node*getRoot();
};

class AST
{
private:
	void checkUpperCasting(TreeNode* expressionLeftNode, TreeNode* castNode, TreeNode* function);
	void checkDownCasting(TreeNode* expressionLeftNode, TreeNode* castNode, TreeNode* function);
public:
	queue<TreeNode*>q;
	nodeList * list = new nodeList();

	AST(void);
	~AST(void);
	TreeNode * createNode(TreeNode * left, TreeNode* right, NodeType nt);
	TreeNode * createNode(TreeNode * left, TreeNode* right, NodeType nt, void * e);
	TreeNode * createNodeData(DataMember**, TreeNode* t);
	TreeNode * createNodeVar(Variable** arr , TreeNode * t);
	TreeNode * addToLastRight(TreeNode * basic, TreeNode* newItem);
	Type * checkMapForType(MyMap * m);
	TreeNode ** getNodes(TreeNode * tn, string s);
	TreeNode ** getParamNodes(TreeNode * tn, char * functionName);
	void makeVisitedZero(TreeNode * tn);
	TreeNode * checkall(TreeNode * tn, string s);
	TreeNode * checkLeft(TreeNode * tn, string s);
	TreeNode * checkRight(TreeNode * tn, string s);
	bool checkVariable(void * elem, TreeNode * f);
	void checkFunctionStmtOrVar(TreeNode * tn, TreeNode * func, TreeNode * Exp);
	void firstCheckVariableCheck(TreeNode * tn, MyParser * p);
	bool CheckInitVariable(TreeNode * tn);
	void secondCheckInitVariable(TreeNode * tn, MyParser * p);
	void checkMethodCall(TreeNode * tn);
	Variable * getVariable(void * elem, TreeNode * f);
	bool funIsPrivate(Type * reqClass, char * functionName);
	bool varIsPrivate(TreeNode * reqClass, char * datamemberName);
	void checkPrivateFunc(TreeNode * tn);
	void checkPrivateVar(TreeNode * tn);
	void checkAbstraction(TreeNode * tn);
	bool existInParent(Type* type, char *reqfunName);
	void checkConstructerSuper(TreeNode * tn);
	void checkInnerClass(TreeNode * tn);
	void checkLocalInnerClass(TreeNode* tn);
	void checKReturnFunction(TreeNode * tn);
	void checkAssignType(TreeNode * tn);
	bool checkFinalDmInit(DataMember* dm, TreeNode* reqClass);
	bool checkFinalDmInit(TreeNode* valueNode, DataMember* dm);
	void checkParameterFunNumber(TreeNode * tn);
	void checkClasses(TreeNode * tn);
	void checkCastingState(TreeNode * tn);
	Type * getType(char * className);
	void checkConstants(TreeNode* t);
	void check(MyParser * p);
	void addTree(TreeNode * tn);
	void print(TreeNode * tn, int lvl);
};
#endif