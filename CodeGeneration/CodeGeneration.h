#pragma once
#ifndef CodeGeneration_H
#define CodeGeneration_H

#include "../SymbolTable/SymbolTable.h"
#include "../JavaCompiler/AST.h"
#include <iostream>
#include <string>


class CodeGeneration {
private:
	FILE * codeGenerationFile;
	void writeStr(char* str);
	void writeInt(int num);

	void pushIntValToReg(int value);

	void generateExpr(TreeNode* treeNode);
public:
	CodeGeneration(void);
	~CodeGeneration();

	void generate(TreeNode* rootNode);
};

#endif