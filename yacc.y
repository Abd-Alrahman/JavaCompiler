%output ="yacc.cpp"
%{
	#include <iostream>
	using namespace std;
	#include <FlexLexer.h>
	#include "SymbolTable/MyParser.h"
	#include<io.h>
	#include<vector>
	#include<string>
	#include <fstream>

	int yylex(void);
	int yyparse();
	void yyerror(char *);
	
	FlexLexer* lexer = new yyFlexLexer();
	ErrorRecovery* err = new ErrorRecovery();

	class Parser
	{
		public:
		int	parse()
		{
			return yyparse();
		}
	};

	MyParser * p = new MyParser();
	Modifier * modifier = new Modifier();
	Modifier * m;
	Type * type;


	int numo = 0;
	int numc = 0;

%}



%union{
	struct R {
		int i;
		float f;
		char c;
		char* str;
		int myLineNo;
		int myColNo;
		int mynumopen;
		int mynumclose;
		}r;
		class YaccSimpleType * yaccSimpleType;
		class Variable * variable;
		class DataMember * dm;
		class Function * function;
		class Type * type;
		class Parameter * param;


	}

%token ABSTRACT ASSERT
%token BREAK BYVALUE
%token CASE CAST CLASS CONST CONTINUE
%token DEFAULT DO
%token ENUM EXTENDS
%token FINAL FOR FUTURE
%token GENERIC GOTO
%token IF IMPLEMENTS IMPORT INNER INSTANCEOF INTERFACE
%token NATIVE
%token OPERATOR OUTER
%token PACKAGE PRIVATE PROTECTED PUBLIC
%token REST RETURN
%token STATIC SWITCH SYNCHRONIZED
%token THIS THROW THROWS TRANSIENT TRY
%token VAR VOLATILE
%token WHILE
%token OP_INC OP_DEC
%token OP_SHL OP_SHR OP_SHRR
%token OP_GE OP_LE OP_EQ OP_NE
%token OP_LAND OP_LOR
%token ASS_MUL ASS_DIV ASS_MOD ASS_ADD ASS_SUB
%token ASS_SHL ASS_SHR ASS_SHRR ASS_AND ASS_XOR ASS_OR
%token CLOSE_B OPEN CLOSE COLON COMMA
%token PLUS MINUS MULT DIV AND OR QUES_MARK MODULE ASSIGN
%token XOR LESS GREATER
%token N_ID 

%nonassoc e1
%nonassoc e15
%nonassoc ELSE
%nonassoc e4
%nonassoc e2
%nonassoc e3 
%nonassoc ABSTRACT CLASS FINAL INTERFACE NATIVE PRIVATE PROTECTED PUBLIC STATIC SYNCHRONIZED TRANSIENT  VOLATILE CLOSE_D 
%nonassoc e5
%nonassoc e6
%nonassoc e7
%nonassoc POINT
%nonassoc e8
%nonassoc e9
%nonassoc e10
%nonassoc BOOLEAN NEW JNULL SUPER THIS VOID OPEN_B EXC_MARK DURA INT STRING SHORT LONG FLOAT DOUBLE CHAR BYTE 
%nonassoc INTEGER_VALUE LONG_VALUE FLOAT_VALUE CHAR_VALUE STRING_VALUE BOOLLIT LITERAL
%nonassoc e11
%nonassoc e16 e21
%nonassoc SEMICOLON
%nonassoc e12 e13
%nonassoc OPEN_D
%nonassoc IDENTIFIER OP_DIM
%nonassoc e14 
%nonassoc e17
%nonassoc e18
%nonassoc e19
%nonassoc FINALLY CATCH 

%start CompilationUnit

%%

TypeSpecifier
	: TypeName %prec e14  	{ cout << "TypeSpecifier 1\n"; }
	| TypeName Dims { cout << "TypeSpecifier 2\n"; }
	;

TypeName
	: PrimitiveType { cout << "TypeName 1\n"; }
	| QualifiedName %prec e5 { cout << "TypeName 2\n"; if (modifier->getReturnType() && !modifier->getReturnType()[0]) modifier->setReturnType($<r.str>1); }
	;

ClassNameList
    : QualifiedName { cout << "ClassNameList\n"; }
    | ClassNameList COMMA QualifiedName
	;

PrimitiveType
	: BOOLEAN { cout << "PrimitiveType BOOLEAN\n"; modifier->setReturnType("boolean"); }
	| CHAR	  { cout << "PrimitiveType CHAR\n"; modifier->setReturnType("char"); }
	| BYTE	  { cout << "PrimitiveType BYTE\n"; modifier->setReturnType("byte"); }
	| SHORT	  { cout << "PrimitiveType SHORT\n"; modifier->setReturnType("short"); }
	| INT	  { cout << "PrimitiveType INT\n"; modifier->setReturnType("int"); }
	| LONG	  { cout << "PrimitiveType LONG\n";modifier->setReturnType("long"); }
	| FLOAT	  { cout << "PrimitiveType FLOAT\n"; modifier->setReturnType("float"); }
	| DOUBLE  { cout << "PrimitiveType DOUBLE\n";modifier->setReturnType("double"); }
	| VOID	  { cout << "PrimitiveType VOID\n"; modifier->setReturnType("void"); }
	| STRING  { cout << "PrimitiveType STRING\n"; modifier->setReturnType("String"); }
	;

SemiColons
	: SEMICOLON { cout << "SemiColons\n"; }
    | SemiColons SEMICOLON
    ;

CompilationUnit
	: ProgramFile {
					if( numo != numc ){
						err->errQ->enqueue($<r.myLineNo>1,$<r.myColNo>1,"Error in brackets", "" );
					}else{
						cout << "brackets amazing" << endl;
					}
					cout <<"-----------\nTHE END !\n";
					YYABORT;
				  }

ProgramFile
	: PackageStatement ImportStatements TypeDeclarations { cout << "ProgramFile 1 \n"; }
	| PackageStatement ImportStatements			         { cout << "ProgramFile 2 \n"; }
	| PackageStatement                  TypeDeclarations { cout << "ProgramFile 3 \n"; }
	|                  ImportStatements TypeDeclarations { cout << "ProgramFile 4 \n"; }
	| PackageStatement									 { cout << "ProgramFile 5 \n"; }
	|                  ImportStatements					 { cout << "ProgramFile 6 \n"; }
	|                                   TypeDeclarations { err->errQ->enqueue($<r.myLineNo>1,$<r.myColNo>1,"Error :Missing \'Package Statement \'", "" );}
	|													 { err->errQ->enqueue(0, 0, "Error: file is empty!", ""); }
	;

PackageStatement
	: PACKAGE QualifiedName SemiColons { cout << "PackageStatement\n"; }
	| PACKAGE QualifiedName {err->errQ->enqueue($<r.myLineNo>2,$<r.myColNo>2,"Error :Missing \';\'", "" );}
	| PACKAGE %prec e6 {err->errQ->enqueue($<r.myLineNo>1,$<r.myColNo>1,"Error :Expected <identifier>", "" );}
	| PACKAGE SemiColons {err->errQ->enqueue($<r.myLineNo>2,$<r.myColNo>2,"Error :Expected <identifier>;", "" );}
	| SemiColons {err->errQ->enqueue($<r.myLineNo>1,$<r.myColNo>1,"Error :Expected packageStatment1", "" );}
	| QualifiedName SemiColons {err->errQ->enqueue($<r.myLineNo>2,$<r.myColNo>2,"Error :Expected packageStatment2", "" );}
	| QualifiedName QualifiedName SemiColons {err->errQ->enqueue($<r.myLineNo>2,$<r.myColNo>2,"Error :Expected package put givin", $<r.str>1);}
	;


TypeDeclarations
	: TypeDeclarationOptSemi { cout << "TypeDeclarations\n"; }
	| TypeDeclarations TypeDeclarationOptSemi
	;

TypeDeclarationOptSemi
    : TypeDeclaration { cout << "TypeDeclarationOptSemi\n"; }
    | TypeDeclaration SemiColons
    ;

ImportStatements
	: ImportStatement { cout << "ImportStatements\n"; }
	| ImportStatements ImportStatement
	;

ImportStatement
	: IMPORT QualifiedName SemiColons			 { cout << "ImportStatement 1\n"; }
	| IMPORT QualifiedName POINT MULT SemiColons { cout << "ImportStatement 2\n"; }
	;


QualifiedName
	: IDENTIFIER { cout << "QualifiedName\n"; }
	| QualifiedName POINT IDENTIFIER
	;

TypeDeclaration
	: ClassHeader OPEN_D FieldDeclarations CLOSE_D { cout << "TypeDeclaration 1\n"; 
													 numo += $<r.mynumopen>4;
													 numc += $<r.mynumclose>4;														
													 type = $<type>1 = p->finishTypeDeclaration($<type>1); 
													 
												   }
	| ClassHeader OPEN_D CLOSE_D				   { cout << "TypeDeclaration 2\n";
														numo += $<r.mynumopen>3 ;
														numc += $<r.mynumclose>3;
													 type = $<type>1 = p->finishTypeDeclaration($<type>1); 
												   }

	| ClassHeader CLOSE_D						   { 
														err->errQ->enqueue($<r.myLineNo>2,$<r.myColNo>2,"Error :expected \'{\'", "" );
													}
	| ClassHeader OPEN_D  %prec e2					{ 
														err->errQ->enqueue($<r.myLineNo>2,$<r.myColNo>2,"Error :expected \'}\'", "" );
													}
	| ClassHeader %prec e4							{ 
														err->errQ->enqueue($<r.myLineNo>1,$<r.myColNo>1,"Error :expected \'{}\'", "" );
													}
	;

ClassHeader
	: Modifiers ClassWord IDENTIFIER Extends Interfaces { 
															type = $<type>$ = p->createType($<r.str>3, yylval.r.myLineNo, yylval.r.myColNo, modifier, $<r.str>4);
															cout << "ClassHeader 1\n"; 
														}
	| Modifiers ClassWord IDENTIFIER Extends			{
															type = $<type>$ = p->createType($<r.str>3, yylval.r.myLineNo, yylval.r.myColNo, modifier, $<r.str>4);
															cout << "ClassHeader 2\n"; 
														}
	| Modifiers ClassWord IDENTIFIER       Interfaces	{ 
															type = $<type>$ = p->createType($<r.str>3, yylval.r.myLineNo, yylval.r.myColNo, modifier, "");
															cout << "ClassHeader 3\n"; 
														}
	|           ClassWord IDENTIFIER Extends Interfaces { 
															type = $<type>$ = p->createType($<r.str>2, yylval.r.myLineNo, yylval.r.myColNo, modifier, $<r.str>3);
															cout << "ClassHeader 4\n"; 
														}
	| Modifiers ClassWord IDENTIFIER					{ 
															type = $<type>$ = p->createType($<r.str>3, yylval.r.myLineNo, yylval.r.myColNo, modifier, "");
															cout << "ClassHeader 5\n"; 
														}
	| QualifiedName ClassWord IDENTIFIER				{ 
															err->errQ->enqueue($<r.myLineNo>1,$<r.myColNo>1,"Error :expected \'Modifier\' but given ",$<r.str>1);
														}
	|           ClassWord IDENTIFIER Extends			{ 
															type = $<type>$ = p->createType($<r.str>2, yylval.r.myLineNo, yylval.r.myColNo, modifier, $<r.str>3);
															cout << "ClassHeader 6\n"; 
														}
	|           ClassWord IDENTIFIER       Interfaces	{ 
															type = $<type>$ = p->createType($<r.str>2, yylval.r.myLineNo, yylval.r.myColNo, modifier, "");
															cout << "ClassHeader 7\n"; 
														}
	|           ClassWord IDENTIFIER					{ 
															type = $<type>$ = p->createType($<r.str>2, yylval.r.myLineNo, yylval.r.myColNo, modifier, "");
															cout << "ClassHeader 8\n"; 
														}
	| Modifiers ClassWord %prec e7			            { 
															err->errQ->enqueue($<r.myLineNo>1,$<r.myColNo>1,"Error :expected <identifier> 1","" );
														}
	|		    ClassWord %prec e7			            { 
															err->errQ->enqueue($<r.myLineNo>1,$<r.myColNo>1,"Error :expected <identifier> 2","" );
														}
	|           ClassWord Extends						{ 
															err->errQ->enqueue($<r.myLineNo>2,$<r.myColNo>2,"illegal start class","" );
														}
	;

Modifiers
	: Modifier  { cout << "Modifiers\n"; }
	| Modifiers Modifier
	;

Modifier
	: ABSTRACT     { cout << "Modifier ABSTRACT\n";		(!modifier->getIsAbstract())	 ? modifier->setIsAbstract(true)
																						 : err->errQ->enqueue($<r.myLineNo>1, $<r.myColNo>1, "Error :repeated modifier", ""); }
	| FINAL		   { cout << "Modifier FINAL\n";		(!modifier->getIsFinal())		 ? modifier->setIsFinal(true)
																						 : err->errQ->enqueue($<r.myLineNo>1, $<r.myColNo>1, "Error :repeated modifier", ""); }
	| PUBLIC	   { cout << "Modifier PUBLIC\n";		(!modifier->getIsPublic())		 ? modifier->setIsPublic(true)
																						 : err->errQ->enqueue($<r.myLineNo>1, $<r.myColNo>1, "Error :repeated modifier", ""); }
	| PROTECTED	   { cout << "Modifier PROTECTED\n";	(!modifier->getIsProtected())	 ? modifier->setIsProtected(true)
																						 : err->errQ->enqueue($<r.myLineNo>1, $<r.myColNo>1, "Error :repeated modifier", ""); }
	| PRIVATE	   { cout << "Modifier PRIVATE\n";		(!modifier->getIsPrivate())		 ? modifier->setIsPrivate(true)
																						 : err->errQ->enqueue($<r.myLineNo>1, $<r.myColNo>1, "Error :repeated modifier", ""); }
	| STATIC	   { cout << "Modifier STATIC\n";		(!modifier->getIsStatic())		 ? modifier->setIsStatic(true)
																						 : err->errQ->enqueue($<r.myLineNo>1, $<r.myColNo>1, "Error :repeated modifier", ""); }
	| TRANSIENT	   { cout << "Modifier TRANSIENT\n";	(!modifier->getIsTransient())	 ? modifier->setIsTransient(true)
																						 : err->errQ->enqueue($<r.myLineNo>1, $<r.myColNo>1, "Error :repeated modifier", ""); }
	| VOLATILE	   { cout << "Modifier VOLATILE\n";		(!modifier->getIsVolatile())	 ? modifier->setIsVolatile(true)
																						 : err->errQ->enqueue($<r.myLineNo>1, $<r.myColNo>1, "Error :repeated modifier", ""); }
	| NATIVE	   { cout << "Modifier NATIVE\n";		(!modifier->getIsNative())		 ? modifier->setIsNative(true)
																						 : err->errQ->enqueue($<r.myLineNo>1, $<r.myColNo>1, "Error :repeated modifier", ""); }
	| SYNCHRONIZED { cout << "Modifier SYNCHRONIZED\n"; (!modifier->getIsSynchronized()) ? modifier->setIsSynchronized(true)
																						 : err->errQ->enqueue($<r.myLineNo>1, $<r.myColNo>1, "Error :repeated modifier", ""); }
	;

ClassWord
	: CLASS		{ cout << "ClassWord CLASS\n"; }
	| INTERFACE { cout << "ClassWord INTERFACE\n"; }
	| TypeSpecifier %prec e3 { err->errQ->enqueue($<r.myLineNo>1,$<r.myColNo>1,"Error :expected \'class\'", $<r.str>1);}
	;

Interfaces
	: IMPLEMENTS ClassNameList { cout << "Interfaces\n"; }
	| IMPLEMENTS %prec e9	   { err->errQ->enqueue($<r.myLineNo>1,$<r.myColNo>1,"Error :illegal start of type", "");}
	;

FieldDeclarations
	: FieldDeclarationOptSemi { cout << "FieldDeclarations\n"; }
    | FieldDeclarations FieldDeclarationOptSemi
	;

FieldDeclarationOptSemi
    : FieldDeclaration { cout << "FieldDeclarationOptSemi\n"; }
    | FieldDeclaration SemiColons
    ;

FieldDeclaration
	: FieldVariableDeclaration SEMICOLON { cout << "FieldDeclaration 1\n"; }
	| FieldVariableDeclaration %prec e11 { err->errQ->enqueue($<r.myLineNo>1,$<r.myColNo>1,"Error :expected semicolon","");}
	| MethodDeclaration					 { bool methodBody = false; 
										   cout << "FieldDeclaration 2\n"; 
										 }
	| ConstructorDeclaration			 { cout << "FieldDeclaration 3\n"; }
	| StaticInitializer					 { cout << "FieldDeclaration 4\n"; }
    | NonStaticInitializer				 { cout << "FieldDeclaration 5\n"; }
    | TypeDeclaration					 { cout << "FieldDeclaration 6\n"; }
	;

FieldVariableDeclaration
	: Modifiers TypeSpecifier VariableDeclarators	{ 
														p->insertMem(yylval.r.myLineNo, yylval.r.myColNo, modifier);
														cout << "FieldVariableDeclaration 1\n";
														p->resetNames();
													}
	|           TypeSpecifier VariableDeclarators	{ 
														p->insertMem(yylval.r.myLineNo, yylval.r.myColNo, modifier);
														cout << "FieldVariableDeclaration 2\n";
														p->resetNames();
													}
	;

VariableDeclarators
	: VariableDeclarator { cout << "VariableDeclarators\n"; }
	| VariableDeclarators COMMA VariableDeclarator
	;

VariableDeclarator
	: DeclaratorName							{ p->addToNames($<r.str>1); cout << "VariableDeclarator 1\n"; }
	| DeclaratorName ASSIGN VariableInitializer { p-> addToNames($<r.str>1); cout << "VariableDeclarator 2\n"; }
	;

VariableInitializer
	: Expression					   { cout << "VariableInitializer 1\n"; }
	| OPEN_D CLOSE_D				   { cout << "VariableInitializer 2\n"; }
    | OPEN_D ArrayInitializers CLOSE_D { cout << "VariableInitializer 3\n"; }
    ;

ArrayInitializers
	: VariableInitializer						  { cout << "ArrayInitializers 1\n"; }
	| ArrayInitializers COMMA VariableInitializer { cout << "ArrayInitializers 2\n"; }
	| ArrayInitializers COMMA					  { cout << "ArrayInitializers 3\n"; }
	;

MethodDeclaration
	: Modifiers TypeSpecifier MethodDeclarator Throws MethodBody {
																	$<function>$ = p->finishFunctionDeclaration($<function>3, p->methodBody);
																	cout << "MethodDeclaration 1\n";
																 }
	| Modifiers TypeSpecifier Modifiers MethodDeclarator Throws MethodBody { 
																			 $<function>$ = p->finishFunctionDeclaration($<function>4, p->methodBody);
																			 err->errQ->enqueue($<r.myLineNo>6,$<r.myColNo>6,"Error modifier return type", $<r.str>1);
																		   }
	| Modifiers TypeSpecifier MethodDeclarator        MethodBody {
																	$<function>$ = p->finishFunctionDeclaration($<function>3, p->methodBody);
																	cout << "MethodDeclaration 2\n";
																 }
	| Modifiers TypeSpecifier Modifiers  MethodDeclarator    MethodBody {
																		   $<function>$ = p->finishFunctionDeclaration($<function>4, p->methodBody);
																		   err->errQ->enqueue($<r.myLineNo>5,$<r.myColNo>5,"Error modifier return type", $<r.str>1);
																		}
	|           TypeSpecifier MethodDeclarator Throws MethodBody {
																	$<function>$ = p->finishFunctionDeclaration($<function>2, p->methodBody);
																	cout << "MethodDeclaration 3\n";
																 }
	|           TypeSpecifier MethodDeclarator        MethodBody {
																	$<function>$ = p->finishFunctionDeclaration($<function>2, p->methodBody);
																	modifier->reset();
																	cout << "MethodDeclaration 4\n";
																 }
	;

MethodDeclarator
	: DeclaratorName OPEN_B						  { m = new Modifier(modifier); modifier->reset(); } 
	  ParameterList CLOSE_B						  {
													$<function>$ = p->createFunction($<r.str>1, yylval.r.myLineNo, yylval.r.myColNo, m);
													cout << "MethodDeclarator 1\n";
												  }
	| DeclaratorName OPEN_B CLOSE_B				  {
													cout << "MethodDeclarator 2\n";
													$<function>$ = p->createFunction($<r.str>1, yylval.r.myLineNo, yylval.r.myColNo, modifier);
												  }
	| MethodDeclarator OP_DIM					  {
													$<function>$ = p->createFunction($<r.str>1, yylval.r.myLineNo, yylval.r.myColNo, modifier);
													cout << "MethodDeclarator 3\n";
												  }
	;

ParameterList
	: Parameter { cout << "ParameterList\n"; }
	| ParameterList COMMA Parameter
	;

Parameter
	: TypeSpecifier DeclaratorName			 {
												p->defaultParam = false;
												$<param>$ = p->insertParam($<r.str>2, yylval.r.myLineNo, yylval.r.myColNo, modifier);
												cout << "Parameter 1\n";
											 }
	| TypeSpecifier DeclaratorName	ASSIGN	ComplexPrimaryNoParenthesis {
												p->defaultParam = true;
												$<param>$ = p->insertParam($<r.str>2, yylval.r.myLineNo, yylval.r.myColNo, modifier);
												cout << "Parameter 2\n";
											 }
    | Modifiers TypeSpecifier DeclaratorName {
												p->defaultParam = false;
												$<param>$ = p->insertParam($<r.str>3, yylval.r.myLineNo, yylval.r.myColNo, modifier);
												cout << "Parameter 3\n";
											 }
	;

DeclaratorName
	: IDENTIFIER			{ cout << "DeclaratorName 1\n"; }
    | DeclaratorName OP_DIM { cout << "DeclaratorName 2\n"; }
    ;

Throws
	: THROWS ClassNameList { cout << "Throws\n"; }
	;

MethodBody
	: Block		{ cout << "MethodBody 1\n"; }
	| SEMICOLON { p->methodBody = false; cout << "MethodBody 2\n"; }
	;

ConstructorDeclaration
	: Modifiers ConstructorDeclarator Throws Block {
														$<function>$ = p->finishFunctionDeclaration($<function>2, p->methodBody);
														cout << "ConstructorDeclaration 1\n";
												   }
	| Modifiers ConstructorDeclarator Block		   {
														$<function>$ = p->finishFunctionDeclaration($<function>2, p->methodBody);
														cout << "ConstructorDeclaration 2\n";
												   }
	|           ConstructorDeclarator Throws Block {
														$<function>$ = p->finishFunctionDeclaration($<function>1, p->methodBody);
														cout << "ConstructorDeclaration 3\n";
												   }
	|           ConstructorDeclarator Block		   {
														$<function>$ = p->finishFunctionDeclaration($<function>1, p->methodBody);
														cout << "ConstructorDeclaration 4\n";
												   }
	|           ConstructorDeclarator { p->methodBody = false; } SEMICOLON	   {
														$<function>$ = p->finishFunctionDeclaration($<function>1, p->methodBody);
														cout << "ConstructorDeclaration 5\n";
												   }
	;

ConstructorDeclarator
	: IDENTIFIER OPEN_B						  { m = new Modifier(modifier); modifier->reset(); }
						ParameterList CLOSE_B {
												$<function>$ = p->createFunction($<r.str>1, yylval.r.myLineNo, yylval.r.myColNo, m);
												cout << "ConstructorDeclarator 1\n";
											  }
	| IDENTIFIER OPEN_B CLOSE_B				  {
												$<function>$ = p->createFunction($<r.str>1, yylval.r.myLineNo, yylval.r.myColNo, modifier);
												cout << "ConstructorDeclarator 2\n";
											  }
	;

StaticInitializer
	: STATIC Block { cout << "StaticInitializer\n"; }
	;

NonStaticInitializer
        : Block { cout << "NonStaticInitializer\n"; }
        ;

Extends
	: EXTENDS TypeName		 { cout << "Extends 1\n"; }
	| Extends COMMA TypeName {
								cout << "Extends 2\n";
								err->errQ->enqueue($<r.myLineNo>2,$<r.myColNo>2, "Class can't extends more than one", "");
							 }
	| EXTENDS %prec e8       { err->errQ->enqueue($<r.myLineNo>1,$<r.myColNo>1,"Error :illegal start of type ", ""); }
	;

Block
	: OPEN_D LocalVariableDeclarationsAndStatements CLOSE_D { p->methodBody = true; cout << "Block 1\n"; }
	| OPEN_D CLOSE_D										{ p->methodBody = true; cout << "Block 2\n"; }
    ;
	
LocalVariableDeclarationsAndStatements
	: LocalVariableDeclarationOrStatement { cout << "LocalVariableDeclarationsAndStatements\n"; }
	| LocalVariableDeclarationsAndStatements LocalVariableDeclarationOrStatement
	;

LocalVariableDeclarationOrStatement
	: LocalVariableDeclarationStatement { cout << "LocalVariableDeclarationOrStatement 1\n"; }
	| Statement							{ cout << "LocalVariableDeclarationOrStatement 2\n"; }
	;

LocalVariableDeclarationStatement
	:			TypeSpecifier VariableDeclarators SEMICOLON		{
																	p->insertVar(yylval.r.myLineNo, yylval.r.myColNo, modifier);
																	cout << "LocalVariableDeclarationStatement 1\n"; 
																	p->resetNames();
																}
    | Modifiers TypeSpecifier VariableDeclarators SEMICOLON		{
																	p->insertVar(yylval.r.myLineNo, yylval.r.myColNo, modifier);
																	cout << "LocalVariableDeclarationStatement 2\n";
																	p->resetNames();
																}
	;
	
Statement
	: EmptyStatement				{ cout << "Statement 1\n"; }
	| LabelStatement				{ cout << "Statement 2\n"; }
	| ExpressionStatement SEMICOLON { cout << "Statement 3\n"; }
    | SelectionStatement			{ cout << "Statement 4\n"; }
    | IterationStatement			{ cout << "Statement 5\n"; }
	| JumpStatement					{ cout << "Statement 6\n"; }
	| GuardingStatement				{ cout << "Statement 7\n"; }
	| Block							{ cout << "Statement 8\n"; }
	;

EmptyStatement
	: SEMICOLON { cout << "EmptyStatement 8\n"; }
    ;

LabelStatement
	: IDENTIFIER COLON				{ cout << "LabelStatement 1\n"; }
    | CASE ConstantExpression COLON { cout << "LabelStatement 2\n"; }
	| DEFAULT COLON					{ cout << "LabelStatement 3\n"; }
    ;

ExpressionStatement
	: Expression { cout << "ExpressionStatement\n"; }
	;

SelectionStatement
	: IF OPEN_B Expression CLOSE_B Statement %prec e1		{ cout << "SelectionStatement 1\n"; }
	| IF OPEN_B CLOSE_B Statement %prec e15                    { err->errQ->enqueue($<r.myLineNo>4,$<r.myColNo>4,"Error : if without expression ","");}
    | IF OPEN_B Expression CLOSE_B Statement ELSE Statement { cout << "SelectionStatement 2\n"; }
	| IF OPEN_B CLOSE_B Statement ELSE Statement     { err->errQ->enqueue($<r.myLineNo>4,$<r.myColNo>4,"Error : ifelse without expression ","");}
    | SWITCH OPEN_B Expression CLOSE_B Block				{ cout << "SelectionStatement 3\n"; }
	| SWITCH OPEN_B CLOSE_B Block				{ err->errQ->enqueue($<r.myLineNo>4,$<r.myColNo>4,"Error :illegal switch ", "");}
    ;

IterationStatement
	: WHILE OPEN_B Expression CLOSE_B Statement				 { cout << "IterationStatement 1\n"; }
	| WHILE OPEN_B CLOSE_B Statement				         { err->errQ->enqueue($<r.myLineNo>4,$<r.myColNo>4,"Error : WHILE without expression ","");}
	| DO Statement WHILE OPEN_B Expression CLOSE_B SEMICOLON { cout << "IterationStatement 2\n"; }
	| DO Statement WHILE OPEN_B CLOSE_B SEMICOLON			 { err->errQ->enqueue($<r.myLineNo>6,$<r.myColNo>6,"Error : dowhile without expression ","");}
	| DO Statement WHILE OPEN_B CLOSE_B %prec e16            { err->errQ->enqueue($<r.myLineNo>4,$<r.myColNo>4,"Error : dowhile without expression and missing semicolon ","");}
	| FOR OPEN_B ForInit ForExpr ForIncr CLOSE_B Statement	 { cout << "IterationStatement 3\n"; }
	| FOR OPEN_B ForInit ForExpr         CLOSE_B Statement	 { cout << "IterationStatement 4\n"; }
	| FOR OPEN_B TypeName IDENTIFIER COLON IDENTIFIER CLOSE_B Statement	 { cout << "IterationStatement 5\n"; }
	| DO Statement WHILE OPEN_B Expression CLOSE_B	%prec e21		 { err->errQ->enqueue($<r.myLineNo>6,$<r.myColNo>6,"Error : dowhile missing semicolon ","");}
	;

ForInit
	: ExpressionStatements SEMICOLON	{ cout << "ForInit 1\n"; }
	| LocalVariableDeclarationStatement { cout << "ForInit 2\n"; }
	| SEMICOLON							{ cout << "ForInit 3\n"; }
	;

ForExpr
	: Expression SEMICOLON { cout << "ForExpr 1\n"; }
	| SEMICOLON			   { cout << "ForExpr 2\n"; }
	;

ForIncr
	: ExpressionStatements { cout << "ForIncr\n"; }
	;

ExpressionStatements
	: ExpressionStatement { cout << "ExpressionStatements\n"; }
	| ExpressionStatements COMMA ExpressionStatement
	;

JumpStatement
	: BREAK IDENTIFIER SEMICOLON	{ cout << "JumpStatement 1\n"; }
	| BREAK            SEMICOLON	{ cout << "JumpStatement 2\n"; }
    | CONTINUE IDENTIFIER SEMICOLON { cout << "JumpStatement 3\n"; }
	| CONTINUE            SEMICOLON { cout << "JumpStatement 4\n"; }
	| RETURN Expression SEMICOLON	{ cout << "JumpStatement 5\n"; }
	| RETURN            SEMICOLON	{ cout << "JumpStatement 6\n"; }
	| THROW Expression SEMICOLON	{ cout << "JumpStatement 7\n"; }
	;

GuardingStatement
	: SYNCHRONIZED OPEN_B Expression CLOSE_B Statement { cout << "GuardingStatement 1\n"; }
	| TRY Block Finally	%prec e18					   { cout << "GuardingStatement 2\n"; }
	| TRY Block %prec e17                              {err->errQ->enqueue($<r.myLineNo>2,$<r.myColNo>2,"Error :Expected try catch or try finally", "" );}
	| TRY Block Catches	%prec e19					   { cout << "GuardingStatement 3\n"; }
	| CatchHeader								       {err->errQ->enqueue($<r.myLineNo>1,$<r.myColNo>1,"Error :Expected try catch or try catch finally", "" );}
	| TRY Block Catches Finally						   { cout << "GuardingStatement 4\n"; }
	;

Catches
	: Catch { cout << "Catches\n"; }
	| Catches Catch
	;

Catch
	: CatchHeader Block { cout << "Catch\n"; }
	;

CatchHeader
	: CATCH OPEN_B TypeSpecifier IDENTIFIER CLOSE_B { cout << "CatchHeader 1\n"; }
	| CATCH OPEN_B TypeSpecifier CLOSE_B			{ cout << "CatchHeader 2\n"; }
	;

Finally
	: FINALLY Block { cout << "Finally\n"; }
	;

PrimaryExpression
	: QualifiedName { cout << "PrimaryExpression 1\n"; }
	| NotJustName	{ cout << "PrimaryExpression 2\n"; }
	;

NotJustName
	: SpecialName			  { cout << "NotJustName 1\n"; }
	| NewAllocationExpression { cout << "NotJustName 2\n"; }
	| ComplexPrimary		  { cout << "NotJustName 3\n"; }
	;

ComplexPrimary
	: OPEN_B Expression CLOSE_B	%prec e10  { cout << "ComplexPrimary 1\n"; }
	| ComplexPrimaryNoParenthesis { cout << "ComplexPrimary 2\n"; }
	;

ComplexPrimaryNoParenthesis
	: LITERAL	  { cout << "ComplexPrimaryNoParenthesis 1\n"; }
	| INTEGER_VALUE  { cout << "ComplexPrimaryNoParenthesis INTEGER_VALUE\n"; }
	| FLOAT_VALUE  { cout << "ComplexPrimaryNoParenthesis FLOAT_VALUE\n"; }
	| CHAR_VALUE  { cout << "ComplexPrimaryNoParenthesis CAHR_VALUE\n"; }
	| LONG_VALUE  { cout << "ComplexPrimaryNoParenthesis LONG_VALUE\n"; }
	| STRING_VALUE  { cout << "ComplexPrimaryNoParenthesis STRING_VALUE\n"; }
	| BOOLLIT	  { cout << "ComplexPrimaryNoParenthesis 2\n"; }
	| ArrayAccess { cout << "ComplexPrimaryNoParenthesis 3\n"; }
	| FieldAccess { cout << "ComplexPrimaryNoParenthesis 4\n"; }
	| MethodCall  { cout << "ComplexPrimaryNoParenthesis 5\n"; }
	;

ArrayAccess
	: QualifiedName OPEN Expression CLOSE  { cout << "ArrayAccess 1\n"; }
	| ComplexPrimary OPEN Expression CLOSE { cout << "ArrayAccess 2\n"; }
	;

FieldAccess
	: NotJustName POINT IDENTIFIER			 { cout << "FieldAccess 1\n"; }
	| RealPostfixExpression POINT IDENTIFIER { cout << "FieldAccess 2\n"; }
    | QualifiedName POINT THIS				 { cout << "FieldAccess 3\n"; }
    | QualifiedName POINT CLASS				 { cout << "FieldAccess 4\n"; }
    | PrimitiveType POINT CLASS				 { cout << "FieldAccess 5\n"; }
	;

MethodCall
	: MethodAccess OPEN_B ArgumentList CLOSE_B { cout << "MethodCall 1\n"; }
	| MethodAccess OPEN_B CLOSE_B			   { cout << "MethodCall 2\n"; }
	;

MethodAccess
	: ComplexPrimaryNoParenthesis { cout << "MethodAccess 1\n"; }
	| SpecialName				  { cout << "MethodAccess 2\n"; }
	| QualifiedName				  { cout << "MethodAccess 3\n"; }
	;

SpecialName
	: THIS  { cout << "SpecialName THIS\n"; }
	| SUPER { cout << "SpecialName SUPER\n"; }
	| JNULL { cout << "SpecialName JNULL\n"; }
	;

ArgumentList
	: Expression					{ cout << "ArgumentList 1\n"; }
	| ArgumentList COMMA Expression { cout << "ArgumentList 2\n"; }
	;

NewAllocationExpression
    : PlainNewAllocationExpression					   { cout << "NewAllocationExpression 1\n"; }
    | QualifiedName POINT PlainNewAllocationExpression { cout << "NewAllocationExpression 2\n"; }
    ;
	
PlainNewAllocationExpression
    : ArrayAllocationExpression	%prec e13					     { cout << "PlainNewAllocationExpression 1\n"; }
    | ClassAllocationExpression	%prec e12						 { cout << "PlainNewAllocationExpression 2\n"; }
    | ArrayAllocationExpression OPEN_D CLOSE_D					 { cout << "PlainNewAllocationExpression 3\n"; }
    | ClassAllocationExpression OPEN_D CLOSE_D					 { cout << "PlainNewAllocationExpression 4\n"; }
    | ArrayAllocationExpression OPEN_D ArrayInitializers CLOSE_D { cout << "PlainNewAllocationExpression 5\n"; }
    | ClassAllocationExpression OPEN_D FieldDeclarations CLOSE_D { cout << "PlainNewAllocationExpression 6\n"; }
    ;

ClassAllocationExpression
	: NEW TypeName OPEN_B ArgumentList CLOSE_B { cout << "ClassAllocationExpression 1\n"; }
	| NEW TypeName OPEN_B              CLOSE_B { cout << "ClassAllocationExpression 2\n"; }
    ;

ArrayAllocationExpression
	: NEW TypeName DimExprs Dims { cout << "ArrayAllocationExpression 1\n"; }
	| NEW TypeName DimExprs		 { cout << "ArrayAllocationExpression 2\n"; }
    | NEW TypeName Dims			 { cout << "ArrayAllocationExpression 3\n"; }
	;

DimExprs
	: DimExpr		   { cout << "DimExprs 1\n"; }
	| DimExprs DimExpr { cout << "DimExprs 2\n"; }
	;

DimExpr
	: OPEN Expression CLOSE { cout << "DimExpr\n"; }
	;

Dims
	: OP_DIM { cout << "Dims\n"; }
	| Dims OP_DIM
	;

PostfixExpression
	: PrimaryExpression		{ cout << "PostfixExpression 1\n"; }
	| RealPostfixExpression { cout << "PostfixExpression 2\n"; }
	;

RealPostfixExpression
	: PostfixExpression OP_INC { cout << "RealPostfixExpression 1\n"; }
	| PostfixExpression OP_DEC { cout << "RealPostfixExpression 2\n"; }
	;

UnaryExpression
	: OP_INC UnaryExpression				 { cout << "UnaryExpression 1\n"; }
	| OP_DEC UnaryExpression				 { cout << "UnaryExpression 2\n"; }
	| ArithmeticUnaryOperator CastExpression { cout << "UnaryExpression 3\n"; }
	| LogicalUnaryExpression				 { cout << "UnaryExpression 4\n"; }
	;

LogicalUnaryExpression
	: PostfixExpression					   { cout << "LogicalUnaryExpression 1\n"; }
	| LogicalUnaryOperator UnaryExpression { cout << "LogicalUnaryExpression 2\n"; }
	;

LogicalUnaryOperator
	: DURA	   { cout << "LogicalUnaryOperator DURA\n"; }
	| EXC_MARK { cout << "LogicalUnaryOperator EXC_MARK\n"; }
	;

ArithmeticUnaryOperator
	: PLUS	{ cout << "ArithmeticUnaryOperator PLUS\n"; }
	| MINUS { cout << "ArithmeticUnaryOperator MINUS\n"; }
	;
	
CastExpression
	: UnaryExpression										{ cout << "CastExpression 1\n"; }
	| OPEN_B PrimitiveTypeExpression CLOSE_B CastExpression { cout << "CastExpression 2\n"; }
	| OPEN_B ClassTypeExpression CLOSE_B CastExpression		{ cout << "CastExpression 3\n"; }
	| OPEN_B Expression CLOSE_B LogicalUnaryExpression		{ cout << "CastExpression 4\n"; }
	;

PrimitiveTypeExpression
	: PrimitiveType		 { cout << "PrimitiveTypeExpression 1\n"; }
    | PrimitiveType Dims { cout << "PrimitiveTypeExpression 2\n"; }
    ;

ClassTypeExpression
	: QualifiedName Dims { cout << "ClassTypeExpression\n"; }
    ;

MultiplicativeExpression
	: CastExpression								 { cout << "MultiplicativeExpression 1\n"; }
	| MultiplicativeExpression MULT CastExpression	 { cout << "MultiplicativeExpression 2\n"; }
	| MultiplicativeExpression DIV CastExpression	 { cout << "MultiplicativeExpression 3\n"; }
	| MultiplicativeExpression MODULE CastExpression { cout << "MultiplicativeExpression 4\n"; }
	;

AdditiveExpression
	: MultiplicativeExpression							{ cout << "AdditiveExpression 1\n"; }
    | AdditiveExpression PLUS MultiplicativeExpression	{ cout << "AdditiveExpression 2\n"; }
	| AdditiveExpression MINUS MultiplicativeExpression { cout << "AdditiveExpression 3\n"; }
    ;

ShiftExpression
	: AdditiveExpression						 { cout << "ShiftExpression 1\n"; }
    | ShiftExpression OP_SHL AdditiveExpression	 { cout << "ShiftExpression 2\n"; }
    | ShiftExpression OP_SHR AdditiveExpression	 { cout << "ShiftExpression 3\n"; }
    | ShiftExpression OP_SHRR AdditiveExpression { cout << "ShiftExpression 4\n"; }
	;

RelationalExpression
	: ShiftExpression								{ cout << "RelationalExpression 1\n"; }
    | RelationalExpression LESS ShiftExpression		{ cout << "RelationalExpression 2\n"; }
	| RelationalExpression GREATER ShiftExpression	{ cout << "RelationalExpression 3\n"; }
	| RelationalExpression OP_LE ShiftExpression	{ cout << "RelationalExpression 4\n"; }
	| RelationalExpression OP_GE ShiftExpression	{ cout << "RelationalExpression 5\n"; }
	| RelationalExpression INSTANCEOF TypeSpecifier { cout << "RelationalExpression 6\n"; }
	;

EqualityExpression
	: RelationalExpression							{ cout << "EqualityExpression 1\n"; }
    | EqualityExpression OP_EQ RelationalExpression { cout << "EqualityExpression 2\n"; }
    | EqualityExpression OP_NE RelationalExpression { cout << "EqualityExpression 3\n"; }
    ;

AndExpression
	: EqualityExpression				   { cout << "AndExpression 1\n"; }
    | AndExpression AND EqualityExpression { cout << "AndExpression 2\n"; }
    ;

ExclusiveOrExpression
	: AndExpression							  { cout << "ExclusiveOrExpression 1\n"; }
	| ExclusiveOrExpression XOR AndExpression { cout << "ExclusiveOrExpression 2\n"; }
	;

InclusiveOrExpression
	: ExclusiveOrExpression							 { cout << "InclusiveOrExpression 1\n"; }
	| InclusiveOrExpression OR ExclusiveOrExpression { cout << "InclusiveOrExpression 2\n"; }
	;

ConditionalAndExpression
	: InclusiveOrExpression									 { cout << "ConditionalAndExpression 1\n"; }
	| ConditionalAndExpression OP_LAND InclusiveOrExpression { cout << "ConditionalAndExpression 2\n"; }
	;

ConditionalOrExpression
	: ConditionalAndExpression								  { cout << "ConditionalOrExpression 1\n"; }
	| ConditionalOrExpression OP_LOR ConditionalAndExpression { cout << "ConditionalOrExpression 2\n"; }
	;

ConditionalExpression
	: ConditionalOrExpression												   { cout << "ConditionalExpression 1\n"; }
	| ConditionalOrExpression QUES_MARK Expression COLON ConditionalExpression { cout << "ConditionalExpression 2\n"; }
	;

AssignmentExpression
	: ConditionalExpression									  { cout << "AssignmentExpression 1\n"; }
	| UnaryExpression AssignmentOperator AssignmentExpression { cout << "AssignmentExpression 2\n"; }
	;

AssignmentOperator
	: ASSIGN   { cout << "AssignmentOperator ASSIGN\n"; }
	| ASS_MUL  { cout << "AssignmentOperator ASS_MUL\n"; }
	| ASS_DIV  { cout << "AssignmentOperator ASS_DIV\n"; }
	| ASS_MOD  { cout << "AssignmentOperator ASS_MOD\n"; }
	| ASS_ADD  { cout << "AssignmentOperator ASS_ADD\n"; }
	| ASS_SUB  { cout << "AssignmentOperator ASS_SUB\n"; }
	| ASS_SHL  { cout << "AssignmentOperator ASS_SHL\n"; }
	| ASS_SHR  { cout << "AssignmentOperator ASS_SHR\n"; }
	| ASS_SHRR { cout << "AssignmentOperator ASS_SHRR\n"; }
	| ASS_AND  { cout << "AssignmentOperator ASS_AND\n"; }
	| ASS_XOR  { cout << "AssignmentOperator ASS_XOR\n"; }
	| ASS_OR   { cout << "AssignmentOperator ASS_OR\n"; }
	;

Expression
	: AssignmentExpression { cout << "Expression\n"; }
    ;

ConstantExpression
	: ConditionalExpression { cout << "ConstantExpression\n"; }
	;

%%



void yyerror(char *s) 
{
	;
}

int yylex()
{
	return lexer->yylex();
}
void main(void)
{
	freopen("out.txt","w" ,stdout);
	Parser* parser = new Parser();
	vector<char*> nameFiles;
	_finddata_t data;
	int ff = _findfirst("Classes/*.java", &data);
	int numFile = sizeof(data.size) / 2;

	if (ff != -1)
	{
		int res = 0;

		while (res != -1)
		{
			char* nna = data.name;
			char * mma = new char[255];
			mma[0] = 0;
			strcpy(mma, nna);
			nameFiles.push_back(mma);
			res = _findnext(ff, &data);
		}

		_findclose(ff);
		ifstream * f = new ifstream();
		char * path;

		for (int i = 0; i < nameFiles.size(); i++)
		{
			char* rawName = new char[255];
			rawName[0] = '\0';
			int dotIndex;
			strcat(rawName, nameFiles[i]);
			for (int j = 0; j < sizeof(rawName) / sizeof(*rawName); j++) {
				if (rawName[j] == '.') {
					dotIndex = j;
				}
			}
			rawName[dotIndex] = '\0';
			cout << rawName << endl;
			strcat(p->rawClassName, rawName);
			path = new char[255];
			strcpy(path, "Classes/");
			strcat(path,nameFiles[i]);
			f->open(path,ifstream::in);
			lexer = new yyFlexLexer(f);
			parser->parse();
			if(!err->errQ->isEmpty())						   
				err->printErrQueue();
				
			if (!p->errRecovery->errQ->isEmpty())
				p->errRecovery->printErrQueue();

			f->close();
			p->rawClassName[0] = '\0';
			cout << "------------------------------\n";
		}
		p->st->checkAtTheEnd(p->st->rootScope, NULL, p->errRecovery);
		if (!p->errRecovery->errQ->isEmpty())
				p->errRecovery->printErrQueue();
		freopen("stFile.txt","w" ,stdout);
		p->st->print(p->st->rootScope, p->errRecovery);
		if (!p->errRecovery->errQ->isEmpty())
				p->errRecovery->printErrQueue();
	}
	
}
