#pragma once
#ifndef AST_____
#define AST_____

#include "../SymbolTable/MyParser.h"
#include <iostream>
#include <queue>
using namespace::std;
enum NodeType {
	//statements
	IfStatmentNode, WhileNode, DoWhileNode, ForNode, expressionNode, SwitchStatmentNode,




	//function
	functionListNode, functionNode, functionHeaderNode, functionBodyNode, MethodCall, MethodAccess,
	QualifiedNamePIdentifier,
	VariableList, parameterNode, parameterNodeList, VariableDeclaratorListNode, VariableDeclaratorNode,

	ConstructorNode,
	ConstructorHeaderNode, ConstructorBodyNode, TryNode, catchNode, catchHeaderNode, finallyNode, NotJustName, ComplexPrimary,

	//values
	Integer_Value, QualifiedName, Assign, Float_Value, Char_Value, Long_Value, String_Value,

	ElseStatementNode, IfElseStatment,

	//class
	classHeader, classNode, classListNode, ClassBody, ClassAllocationExpression,
	
	FildDeclarationList, FildDeclarationNode, DataMemberNode, DataMemberList,

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
class TreeNode {
public:
	TreeNode * left;
	TreeNode * right;
	NodeType nodeType;
	void * elem;
	int visited;
};
class AST
{
public:
	queue<TreeNode*> q;
	
	AST(void);
	~AST(void);
	TreeNode * createNode(TreeNode * left, TreeNode* right, NodeType nt);
	TreeNode * createNode(TreeNode * left, TreeNode* right, NodeType nt, void * e);
	TreeNode * createNodeData(DataMember**);
	TreeNode * createNodeVar(Variable** arr, TreeNode * t);
	TreeNode * addToLastRight(TreeNode * basic, TreeNode* newItem);
	Type * checkMapForType(MyMap * m);
	TreeNode ** getNodes(TreeNode * tn, string s);
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
	void check(TreeNode * tn, int val, MyParser * p);
	void print(TreeNode * tn, int lvl);
};
#endif