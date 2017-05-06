#include "CodeGeneration.h"
#include <string>
#include <sstream>
#include <cstdint>

template <typename T> string toString(const T& t) {
	ostringstream os; os << t; return os.str();
}

CodeGeneration::CodeGeneration() {
	this->codeGenerationFile = fopen("codeGenerationFile.s", "w");
}

CodeGeneration::~CodeGeneration() {
	fclose(this->codeGenerationFile);
}

/* Printing Methods */
void CodeGeneration::writeInt(int num) {
	fputc(num, this->codeGenerationFile);
}

void CodeGeneration::writeStr(char* str) {
	fputs(str, this->codeGenerationFile);
}

/* Pushing Methods */
void CodeGeneration::pushIntValToReg(int value) {
	this->writeStr("\n\n\t#Begin int value Pushing");
	this->writeStr("\n\tli $t0, ");
	this->writeStr(&toString(value)[0]);
	this->writeStr("\n\tsub $sp, $sp, 8");
	this->writeStr("\n\tsw $t0, ($sp)\n");
	this->writeStr("\t#End int value Pushing");
}

void CodeGeneration::generate(TreeNode* rootNode) {
	TreeNode* tempElem = rootNode;
	if (tempElem) {
		switch (tempElem->nodeType) {
		case classListNode:
			this->generate(tempElem->left);
			break;
		case classNode:
			this->generate(tempElem->left);
			this->generate(tempElem->right);
			break;
		case ClassBody:
			this->generate(tempElem->left);
			break;
		case FildDeclarationList:
			this->generate(tempElem->left);
			break;
		case FildDeclarationNode:
			this->generate(tempElem->left);
			break;
		case functionNode:
			this->generate(tempElem->left);
			this->generate(tempElem->right);
			break;
		case functionBodyNode:
			this->generate(tempElem->left);
			break;
		case LocalVarOrStmtListNode:
			this->generate(tempElem->left);
			this->generate(tempElem->right);
			break;
		case LocalVarOrStmtNode:
			this->generate(tempElem->left);
			break;
		case ExpressionNode:
			this->generate(tempElem->left);
			break;
		case UnaryExpressionListNode:
			this->generate(tempElem->left);
			this->generate(tempElem->right);
			break;
		case QualifiedName:
			this->generate(tempElem->left);
			break;
		case ComplexPrimary:
			this->generate(tempElem->left);
			break;
		case Integer_Value: {
			this->pushIntValToReg(5);
			break;
		}
		default:
			this->generate(tempElem->left);
			this->generate(tempElem->right);
			break;
		}
	}
}

void CodeGeneration::generateExpr(TreeNode* treeNode) {
	switch (treeNode->nodeType) {
		case AssignExpressionListNode: {
		     cout << "shit" << endl;
			 break;
		}
	}
}