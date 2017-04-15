%output ="yacc.cpp"
%{
	#include <iostream>
	using namespace std;
	#include <FlexLexer.h>
	#include "JavaCompiler\AST.h"
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
	DataMember **datamember = new DataMember*[20];
	Variable** vars = new Variable*[20];
	Parameter* parameter = new Parameter();

	class Parser
	{
		public:
		int	parse()
		{
			return yyparse();
		}
	};
	
	AST * ast = new AST();
	MyParser * p = new MyParser();
	Modifier * modifier = new Modifier();
	Modifier * m;
	Type * type = new Type();
	Function * function = new Function();

	int numo = 0;
	int numc = 0;
%}



%union{
	struct R{
		int i;
		float f;
		char c;
		char* str;
		int myLineNo;
		int myColNo;
		int mynumopen;
		int mynumclose;
		}r;
		class TreeNode * tn;
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
%nonassoc BOOLEAN NEW JNULL SUPER THIS VOID OPEN_B EXC_MARK DURA STRING INT SHORT LONG FLOAT DOUBLE CHAR BYTE 
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
	| TypeName Dims			{ cout << "TypeSpecifier 2\n"; }
	;

TypeName
	: PrimitiveType { cout << "TypeName 1\n"; $<tn>$=ast->createNode($<tn>1, 0, TypeName);}
	| QualifiedName %prec e5 {  cout << "TypeName 2\n";
								$<tn>$=ast->createNode($<tn>1, 0, TypeName);
							}
	;




ClassNameList
    : QualifiedName { cout << "ClassNameList\n"; }
    | ClassNameList COMMA QualifiedName
	;

PrimitiveType
	: BOOLEAN { cout << "PrimitiveType BOOLEAN\n"; modifier->setReturnType("boolean"); $<tn>$=ast->createNode($<tn>1, 0, booleanType); }
	| CHAR	  { cout << "PrimitiveType CHAR\n"; modifier->setReturnType("char"); $<tn>$=ast->createNode($<tn>1, 0, charType); }
	| BYTE	  { cout << "PrimitiveType BYTE\n"; modifier->setReturnType("byte");  $<tn>$=ast->createNode($<tn>1, 0, byteType);}
	| SHORT	  { cout << "PrimitiveType SHORT\n"; modifier->setReturnType("short");  $<tn>$=ast->createNode($<tn>1, 0, shortType);}
	| INT	  { cout << "PrimitiveType INT\n"; modifier->setReturnType("int");  $<tn>$=ast->createNode($<tn>1, 0, intType);}
	| LONG	  { cout << "PrimitiveType LONG\n";modifier->setReturnType("long"); $<tn>$=ast->createNode($<tn>1, 0, longType);  }
	| FLOAT	  { cout << "PrimitiveType FLOAT\n"; modifier->setReturnType("float"); $<tn>$=ast->createNode($<tn>1, 0, floatType); }
	| DOUBLE  { cout << "PrimitiveType DOUBLE\n";modifier->setReturnType("double"); $<tn>$=ast->createNode($<tn>1, 0, doubleType); }
	| VOID	  { cout << "PrimitiveType VOID\n"; modifier->setReturnType("void"); $<tn>$=ast->createNode($<tn>1, 0, voidType); }
	| STRING  { cout << "PrimitiveType STRING\n"; modifier->setReturnType("String"); $<tn>$=ast->createNode($<tn>1, 0, StringType); }
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
					cout <<"------------------------------------------------- \n";
					ast->addTree($<tn>1);
					YYABORT;
				  }
	|			  {
				err->errQ->enqueue(0,0,"Empty File", "" );
				}


ProgramFile
	: PackageStatement ImportStatements TypeDeclarations { $<tn>$=$<tn>3;cout << "ProgramFile 1 \n"; }
	| PackageStatement ImportStatements			         { cout << "ProgramFile 2 \n"; }
	| PackageStatement                  TypeDeclarations { $<tn>$=$<tn>2;cout << "ProgramFile 3 \n"; }
	|                  ImportStatements TypeDeclarations { $<tn>$=$<tn>2; cout << "ProgramFile 4 \n"; }
	| PackageStatement									 { cout << "ProgramFile 5 \n"; }
	|                  ImportStatements					 { cout << "ProgramFile 6 \n"; }
	|                                   TypeDeclarations { $<tn>$=$<tn>1; err->errQ->enqueue($<r.myLineNo>1,$<r.myColNo>1,"Error :Missing \'Package Statement \'", "" );}
	|													 { err->errQ->enqueue(0, 0, "Error: file is empty!", ""); }
	| PackageStatement ImportStatements	FieldVariableDeclaration { err->errQ->enqueue($<r.myLineNo>1,$<r.myColNo>1,"Error : illegalVariableDeclaration  \'", "" ); }
	| FieldVariableDeclaration { err->errQ->enqueue($<r.myLineNo>1,$<r.myColNo>1,"Error : illegalVariableDeclaration  \'", "" ); }
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
	: TypeDeclarationOptSemi { cout << "TypeDeclarations\n"; $<tn>$=ast->createNode($<tn>1, 0, classListNode); }
	| TypeDeclarations TypeDeclarationOptSemi {$<tn>$ = ast->addToLastRight($<tn>1, ast->createNode($<tn>2, 0, classListNode));}
	;

TypeDeclarationOptSemi
    : TypeDeclaration  { cout << "TypeDeclarationOptSemi\n"; $<tn>$=$<tn>1; }
    | TypeDeclaration SemiColons  { cout << "TypeDeclarationOptSemi2 \n"; $<tn>$=$<tn>1; }
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
	: IDENTIFIER {  cout << "QualifiedName 1\n"; 
					char* name = $<r.str>1;
					if (modifier->getReturnType() && !modifier->getReturnType()[0]) {
						modifier->setReturnType(name);
						modifier->setReturnAlternativeType(name);
					}
				    $<tn>$=ast->createNode(0, 0, QualifiedName ,name); 
				 }
	| QualifiedName POINT IDENTIFIER {  cout << "QualifiedName 2 \n";
										
										char * name = $<r.str>3;
										
										
										modifier->setReturnType(name);
										
										$<tn>$=ast->createNode($<tn>1, 0, QualifiedNamePIdentifier ,name); 
									 }
	;

TypeDeclaration
	: ClassHeader ClassBody  { cout << "TypeDeclaration 1\n"; 
							   
							   numo += $<r.mynumopen>2;
							   numc += $<r.mynumclose>2;														
							   type = p->finishTypeDeclaration((Type*)($<tn>1)->elem); 
							   $<tn>$=ast->createNode($<tn>1,$<tn>2, classNode,type);   
							 }
	| ClassHeader CLOSE_D                { err->errQ->enqueue($<r.myLineNo>2,$<r.myColNo>2,"Error :expected \'{\'", "" ); $<tn>$=ast->createNode($<tn>1,0 , classNode);}
	| ClassHeader OPEN_D  %prec e2		           { err->errQ->enqueue($<r.myLineNo>2,$<r.myColNo>2,"Error :expected \'}\'", "" ); $<tn>$=ast->createNode($<tn>1,0 , classNode);}
	| ClassHeader %prec e4	                       { err->errQ->enqueue($<r.myLineNo>1,$<r.myColNo>1,"Error :expected \'{}\'", "" ); $<tn>$=ast->createNode($<tn>1,0 , classNode);}
	;

ClassBody
	: OPEN_D FieldDeclarations CLOSE_D {cout<<"ClassBody 1 \n"; $<tn>$=ast->createNode($<tn>2,0 , ClassBody);}
	| OPEN_D CLOSE_D				   {cout<<"ClassBody 2 \n"; $<tn>$=ast->createNode(0,0 , ClassBody);}
	;



ClassHeader
	: Modifiers ClassWord IDENTIFIER Extends Interfaces {   cout << "ClassHeader 1\n";
															type = p->createType($<r.str>3, yylval.r.myLineNo, yylval.r.myColNo, modifier, $<r.str>4);
															$<tn>$=ast->createNode(0,0 , classHeader, type);
														}
	| Modifiers ClassWord IDENTIFIER Extends			{   cout << "ClassHeader 2\n"; 
															type = p->createType($<r.str>3, yylval.r.myLineNo, yylval.r.myColNo, modifier, $<r.str>4);
														    $<tn>$=ast->createNode(0,0 , classHeader,type);
														}

	| Modifiers ClassWord IDENTIFIER       Interfaces	{	cout << "ClassHeader 3\n"; 
															type = p->createType($<r.str>3, yylval.r.myLineNo, yylval.r.myColNo, modifier, "");
 														    $<tn>$=ast->createNode(0,0 , classHeader,type);
														}
	|           ClassWord IDENTIFIER Extends Interfaces { cout << "ClassHeader 4\n"; 
															type = p->createType($<r.str>2, yylval.r.myLineNo, yylval.r.myColNo, modifier, $<r.str>3);
														    $<tn>$=ast->createNode(0,0 , classHeader,type);
														}
	| Modifiers ClassWord IDENTIFIER					{ cout << "ClassHeader 5\n"; 
															type = p->createType($<r.str>3, yylval.r.myLineNo, yylval.r.myColNo, modifier, "");
														    $<tn>$=ast->createNode(0,0 , classHeader,type);
														}
	| QualifiedName ClassWord IDENTIFIER				{ err->errQ->enqueue($<r.myLineNo>1,$<r.myColNo>1,"Error :expected \'Modifier\' put givin ",$<r.str>1);
	                                                      $<tn>$=ast->createNode(0,0 , classHeader,type); 
														}
	|           ClassWord IDENTIFIER Extends			{ cout << "ClassHeader 6\n"; 
															type = p->createType($<r.str>2, yylval.r.myLineNo, yylval.r.myColNo, modifier, $<r.str>3);
														    $<tn>$=ast->createNode(0,0 , classHeader,type);
														}
	|           ClassWord IDENTIFIER       Interfaces	{ 	cout << "ClassHeader 7\n"; 
															type = p->createType($<r.str>2, yylval.r.myLineNo, yylval.r.myColNo, modifier, "");	
															$<tn>$=ast->createNode(0,0 , classHeader,type);
														}
	|           ClassWord IDENTIFIER					{ 	
															type = p->createType($<r.str>2, yylval.r.myLineNo, yylval.r.myColNo, modifier, "");
															cout << "ClassHeader 8\n"; 
															$<tn>$=ast->createNode(0,0 , classHeader,type);
														}
	| Modifiers ClassWord %prec e7			            { err->errQ->enqueue($<r.myLineNo>1,$<r.myColNo>1,"Error :expected <identifier> 1","" );
														  $<tn>$=ast->createNode(0,0 , classHeader,type);
	                                                    }
	|		    ClassWord %prec e7			            { err->errQ->enqueue($<r.myLineNo>1,$<r.myColNo>1,"Error :expected <identifier> 3","" );
	                                                      $<tn>$=ast->createNode(0,0 , classHeader,type);
														}
	|           ClassWord Extends						{ err->errQ->enqueue($<r.myLineNo>2,$<r.myColNo>2,"illegal start class","" );
	                                                      $<tn>$=ast->createNode(0,0 , classHeader,type);
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
	: FieldDeclarationOptSemi { cout << "FieldDeclarations\n"; $<tn>$=ast->createNode($<tn>1,0 , FildDeclarationList);}
    | FieldDeclarations FieldDeclarationOptSemi {$<tn>$ = ast->addToLastRight($<tn>1, ast->createNode($<tn>2, 0, FildDeclarationList));}
	;

FieldDeclarationOptSemi
    : FieldDeclaration { cout << "FieldDeclarationOptSemi 1\n"; $<tn>$=ast->createNode($<tn>1,0 , FildDeclarationNode);}
    | FieldDeclaration SemiColons { cout << "FieldDeclarationOptSemi 2\n"; $<tn>$=ast->createNode($<tn>1,0 , FildDeclarationNode);}
    ;

FieldDeclaration
	: FieldVariableDeclaration SEMICOLON { cout << "FieldDeclaration 1\n"; $<tn>$ = $<tn>1; }
	| FieldVariableDeclaration %prec e11 { err->errQ->enqueue($<r.myLineNo>1,$<r.myColNo>1,"Error :expected semicolon",""); $<tn>$ = $<tn>1;}
	| MethodDeclaration					 { cout << "FieldDeclaration 2\n";
										   $<tn>$ = $<tn>1;
										   bool methodBody = false;   
										 }
	| ConstructorDeclaration			 { cout << "FieldDeclaration 3\n";$<tn>$ = $<tn>1; }
	| StaticInitializer					 { cout << "FieldDeclaration 4\n"; $<tn>$ = $<tn>1;}
    | NonStaticInitializer				 { cout << "FieldDeclaration 5\n"; $<tn>$ = $<tn>1;}
    | TypeDeclaration					 { cout << "FieldDeclaration 6\n"; $<tn>$ = $<tn>1;}
	;

FieldVariableDeclaration
	: Modifiers TypeSpecifier VariableDeclarators { cout << "FieldVariableDeclaration 1\n";
												    datamember = p->insertMem(yylval.r.myLineNo, yylval.r.myColNo, modifier);
													p->resetNames(); 
													$<tn>$=ast->createNodeData(datamember);	
												  }
	|           TypeSpecifier VariableDeclarators { cout << "FieldVariableDeclaration 2\n";
													datamember = p->insertMem(yylval.r.myLineNo, yylval.r.myColNo, modifier);
													p->resetNames(); 
													$<tn>$=ast->createNodeData(datamember);		
												  }
	;

VariableDeclarators
	: VariableDeclarator { cout << "VariableDeclarators\n"; $<tn>$=ast->createNode($<tn>1, 0, VariableDeclaratorListNode);}
	| VariableDeclarators COMMA VariableDeclarator {$<tn>$ = ast->addToLastRight($<tn>1, ast->createNode($<tn>3, 0, VariableDeclaratorListNode));}
	;

VariableDeclarator
	: DeclaratorName							{ p->addToNames($<r.str>1); cout << "VariableDeclarator 1\n"; $<tn>$=ast->createNode(0, 0, VariableDeclaratorNode);}
	| DeclaratorName ASSIGN VariableInitializer { p->addToNames($<r.str>1); cout << "VariableDeclarator 2\n"; $<tn>$=ast->createNode($<tn>3, 0, VariableDeclaratorNode);}
	;

VariableInitializer
	: Expression					   { cout << "VariableInitializer 1\n"; $<tn>$=ast->createNode($<tn>1, 0, VariableInitializer);}
	| OPEN_D CLOSE_D				   { cout << "VariableInitializer 2\n"; $<tn>$=ast->createNode(0, 0, VariableInitializer);}
    | OPEN_D ArrayInitializers CLOSE_D { cout << "VariableInitializer 3\n";  $<tn>$=ast->createNode($<tn>2, 0, VariableInitializer);}
    ;

ArrayInitializers
	: VariableInitializer						  { cout << "ArrayInitializers 1\n"; $<tn>$=ast->createNode($<tn>1, 0, ArrayInitializerListNode);}
	| ArrayInitializers COMMA VariableInitializer { cout << "ArrayInitializers 2\n"; $<tn>$ = ast->addToLastRight($<tn>1, ast->createNode($<tn>3, 0, ArrayInitializerListNode));}
	| ArrayInitializers COMMA					  { cout << "ArrayInitializers 3\n"; $<tn>$ = ast->addToLastRight($<tn>1, ast->createNode(0, 0, ArrayInitializerListNode));}
	;

MethodDeclaration
	: Modifiers TypeSpecifier MethodDeclarator Throws MethodBody {  cout << "MethodDeclaration 1\n";
																	function = p->finishFunctionDeclaration(function, p->methodBody);
																	$<tn>$=ast->createNode($<tn>3,$<tn>5 , functionNode,function);
																 }
	| Modifiers TypeSpecifier Modifiers MethodDeclarator Throws MethodBody { err->errQ->enqueue($<r.myLineNo>6,$<r.myColNo>6,"Error modifier return type", $<r.str>1);
	  																		 function = p->finishFunctionDeclaration(function, p->methodBody);	
																			 $<tn>$=ast->createNode($<tn>4,$<tn>6 , functionNode,function);	
																		   }
	| Modifiers TypeSpecifier MethodDeclarator        MethodBody { cout << "MethodDeclaration 2\n"; 
	                                                               
																   function = p->finishFunctionDeclaration(function, p->methodBody);
																   $<tn>$=ast->createNode($<tn>3,$<tn>4 , functionNode,function);
																   
																 }
	| Modifiers TypeSpecifier Modifiers  MethodDeclarator    MethodBody { err->errQ->enqueue($<r.myLineNo>5,$<r.myColNo>5,"Error modifier return type", $<r.str>1);
																		  function = p->finishFunctionDeclaration(function, p->methodBody);
																		  $<tn>$=ast->createNode($<tn>4,$<tn>5 , functionNode,function);
																		}
	|           TypeSpecifier MethodDeclarator Throws MethodBody { cout << "MethodDeclaration 3\n"; 
	 															   function = p->finishFunctionDeclaration(function, p->methodBody);
																   $<tn>$=ast->createNode($<tn>2,$<tn>4 , functionNode,function);
	 															 }
	|           TypeSpecifier MethodDeclarator        MethodBody { cout << "MethodDeclaration 4\n";
																   function = p->finishFunctionDeclaration(function, p->methodBody);
																   modifier->reset();
																   $<tn>$=ast->createNode($<tn>2,$<tn>3 , functionNode,function);
																 }
	;

MethodDeclarator
	: DeclaratorName OPEN_B { m = new Modifier(modifier); modifier->reset(); }  
	  ParameterList CLOSE_B { cout << "MethodDeclarator 1\n"; 
								function = p->createFunction($<r.str>1, yylval.r.myLineNo, yylval.r.myColNo, m);
	  						  $<tn>$=ast->createNode($<tn>4,0 , functionHeaderNode);
							}
	| DeclaratorName OPEN_B CLOSE_B				  { cout << "MethodDeclarator 2\n"; 
													
													function = p->createFunction($<r.str>1, yylval.r.myLineNo, yylval.r.myColNo, modifier); 
													$<tn>$=ast->createNode(0,0 , functionHeaderNode);
												  }
	| MethodDeclarator OP_DIM					  { cout << "MethodDeclarator 3\n";
												    function = p->createFunction($<r.str>1, yylval.r.myLineNo, yylval.r.myColNo, modifier);
												    $<tn>$=ast->createNode(0,0 , functionHeaderNode);
												  }
	;

ParameterList
	: Parameter { cout << "ParameterList\n"; $<tn>$=ast->createNode($<tn>1, 0, parameterNodeList);}
	| ParameterList COMMA Parameter {$<tn>$ = ast->addToLastRight($<tn>1, ast->createNode($<tn>3, 0, parameterNodeList));}
	;

Parameter
	: TypeSpecifier DeclaratorName		 { cout << "Parameter 1\n"; 
										   p->defaultParam = false;
										   parameter = p->insertParam($<r.str>2, yylval.r.myLineNo, yylval.r.myColNo, modifier);
										   $<tn>$=ast->createNode(0, 0, parameterNode,parameter);
										 }
	| TypeSpecifier DeclaratorName	ASSIGN	Expression { cout << "Parameter default \n"; 
											   p->defaultParam = true;
											   parameter = p->insertParam($<r.str>2, yylval.r.myLineNo, yylval.r.myColNo, modifier);
												$<tn>$=ast->createNode(0, 0, parameterNode,parameter); 
											 }
    | FINAL TypeSpecifier DeclaratorName { cout << "Parameter 2\n"; 
	                                       p->defaultParam = false;
										   parameter = p->insertParam($<r.str>3, yylval.r.myLineNo, yylval.r.myColNo, modifier);
										   $<tn>$=ast->createNode(0, 0, parameterNode,parameter);
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
	: Block		{ cout << "MethodBody 1\n"; $<tn>$=ast->createNode($<tn>1,0 , functionBodyNode);}
	| SEMICOLON { p->methodBody = false; cout << "MethodBody 2\n"; }
	;

ConstructorDeclaration
	: Modifiers ConstructorDeclarator Throws Block { cout << "ConstructorDeclaration 1\n"; 
													 
													 function = p->finishFunctionDeclaration(function, p->methodBody);
													 $<tn>$=ast->createNode($<tn>2,$<tn>4, ConstructorNode,function);
												   }
	| Modifiers ConstructorDeclarator        Block { cout << "ConstructorDeclaration 2\n";                                   
													 function = p->finishFunctionDeclaration(function, p->methodBody);
													 $<tn>$=ast->createNode($<tn>2,$<tn>3, ConstructorNode,function);
												   }
	|           ConstructorDeclarator Throws Block { cout << "ConstructorDeclaration 3\n"; 
												     function = p->finishFunctionDeclaration(function, p->methodBody);
													 $<tn>$=ast->createNode($<tn>1,$<tn>3, ConstructorNode,function);
												   }
	|           ConstructorDeclarator        Block { cout << "ConstructorDeclaration 4\n"; 
													 function = p->finishFunctionDeclaration(function, p->methodBody);
	                                                 $<tn>$=ast->createNode($<tn>1,$<tn>2, ConstructorNode,function);
												   }
	|           ConstructorDeclarator { p->methodBody = false; } SEMICOLON	   {
														function = p->finishFunctionDeclaration(function, p->methodBody);
														cout << "ConstructorDeclaration 5\n";
												   }
	;

ConstructorDeclarator
	: IDENTIFIER OPEN_B                       { m = new Modifier(modifier); modifier->reset(); }
	  ParameterList CLOSE_B                   { cout << "ConstructorDeclarator 1\n";
												function = p->createFunction($<r.str>1, yylval.r.myLineNo, yylval.r.myColNo, m); 
	                                            $<tn>$=ast->createNode(0, 0, ConstructorHeaderNode);
											  }
	| IDENTIFIER OPEN_B CLOSE_B				  { cout << "ConstructorDeclarator 2\n";
												function = p->createFunction($<r.str>1, yylval.r.myLineNo, yylval.r.myColNo, modifier); 
											    $<tn>$=ast->createNode(0, 0, ConstructorHeaderNode);
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
	| Extends COMMA TypeName { cout << "Extends 2\n"; }
	| EXTENDS %prec e8       { err->errQ->enqueue($<r.myLineNo>1,$<r.myColNo>1,"Error :illegal start of type ", "");}
	;

Block
	: OPEN_D LocalVariableDeclarationsAndStatements CLOSE_D { cout << "Block 1\n"; 
															  $<tn>$ = $<tn>2;
															  p->methodBody = true;
															}
	| OPEN_D CLOSE_D										{ cout << "Block 2\n"; 
	                                                          p->methodBody = true;
															  $<tn>$=ast->createNode(0, 0, EmptyBlock);
															}
    ;

LocalVariableDeclarationsAndStatements
	: LocalVariableDeclarationOrStatement { cout << "LocalVariableDeclarationsAndStatements\n"; 
											$<tn>$=ast->createNode($<tn>1, 0, LocalVarOrStmtListNode); 
										  }
	| LocalVariableDeclarationsAndStatements LocalVariableDeclarationOrStatement {
	                                        $<tn>$ = ast->addToLastRight($<tn>1, ast->createNode($<tn>2, 0, LocalVarOrStmtListNode));
											}
	;

LocalVariableDeclarationOrStatement
	: LocalVariableDeclarationStatement { cout << "LocalVariableDeclarationOrStatement 1\n"; 
	                                      $<tn>$=ast->createNode($<tn>1, 0, LocalVarOrStmtNode); 
										}
	| Statement							{ cout << "LocalVariableDeclarationOrStatement 2\n"; 
                                          $<tn>$=ast->createNode($<tn>1, 0, LocalVarOrStmtNode); 
										}
	;

LocalVariableDeclarationStatement
	: TypeSpecifier VariableDeclarators SEMICOLON		{ cout << "LocalVariableDeclarationStatement 1\n"; 
														  
														  vars = p->insertVar(yylval.r.myLineNo, yylval.r.myColNo, modifier);
														  $<tn>$=ast->createNodeVar(vars,$<tn>2);
														  p->resetNames(); 
														}
    | FINAL TypeSpecifier VariableDeclarators SEMICOLON { cout << "LocalVariableDeclarationStatement 2\n"; 
														  vars = p->insertVar(yylval.r.myLineNo, yylval.r.myColNo, modifier);
														  $<tn>$=ast->createNodeVar(vars,$<tn>3);

														  p->resetNames(); 
														}
	;

Statement
	: EmptyStatement				{ cout << "Statement 1\n"; $<tn>$ = $<tn>1; }
	| LabelStatement				{ cout << "Statement 2\n"; $<tn>$ = $<tn>1; }
	| ExpressionStatement SEMICOLON { cout << "Statement 3\n"; $<tn>$ = $<tn>1; }
    | IfElseStatment				{ cout << "Statement 4\n"; $<tn>$ = $<tn>1; }
	| SwitchStatement				{ cout << "Statement 9\n"; $<tn>$ = $<tn>1; }
    | IterationStatement			{ cout << "Statement 5\n"; $<tn>$ = $<tn>1; }
	| JumpStatement					{ cout << "Statement 6\n"; $<tn>$ = $<tn>1; }
	| GuardingStatement				{ cout << "Statement 7\n"; $<tn>$ = $<tn>1; }
	| Block							{ cout << "Statement 8\n"; $<tn>$ = $<tn>1; }
	| InnerClassHeader ClassBody			{
										type = p->finishTypeDeclaration((Type *)$<tn>1->elem, true);
										$<tn>$=ast->createNode($<tn>1,$<tn>2, classInnerNode,type);
									}	
	                       
	;

InnerClassHeader
	: CLASS IDENTIFIER { 
						type = p->createType($<r.str>2, yylval.r.myLineNo, yylval.r.myColNo, modifier, "", true);
						$<tn>$=ast->createNode(0,0 , InnerClassHeader,type);
					   }
	;

EmptyStatement
	: SEMICOLON { cout << "EmptyStatement 8\n"; $<tn>$=ast->createNode(0, 0, EmptyStatementNode); }
    ;

LabelStatement
	: IDENTIFIER COLON				{ cout << "LabelStatement 1\n"; $<tn>$=ast->createNode(0, 0, LabelStatementNode);}
    | CASE ConstantExpression COLON { cout << "LabelStatement 2\n"; $<tn>$=ast->createNode(0, 0, LabelStatementNode);}
	| DEFAULT COLON					{ cout << "LabelStatement 3\n"; $<tn>$=ast->createNode(0, 0, LabelStatementNode);}
    ;

ExpressionStatement
	: Expression { cout << "ExpressionStatement\n"; $<tn>$=$<tn>1; }
	;


IfElseStatment
	: IfStatement %prec e1      {$<tn>$=ast->createNode($<tn>1, 0, IfElseStatment);}
	| IfStatement ElseStatement {$<tn>$=ast->createNode($<tn>1, $<tn>2, IfElseStatment);}
	;


IfStatement
	: IF OPEN_B Expression CLOSE_B Statement		      	   { cout << "SelectionStatement 1\n"; $<tn>$=ast->createNode($<tn>3, $<tn>5, IfStatmentNode);}
	| IF OPEN_B CLOSE_B Statement                              { err->errQ->enqueue($<r.myLineNo>4,$<r.myColNo>4,"Error : if without expression ","");}
    ;

ElseStatement
	:ELSE Statement {cout << "ElseStatement \n"; $<tn>$=ast->createNode($<tn>2, 0, ElseStatementNode); }
	;

SwitchStatement
	: SWITCH OPEN_B Expression CLOSE_B Block	{ cout << "SelectionStatement 3\n"; $<tn>$=ast->createNode($<tn>3, $<tn>5, SwitchStatmentNode); }
	| SWITCH OPEN_B CLOSE_B Block				{ err->errQ->enqueue($<r.myLineNo>4,$<r.myColNo>4,"Error :illegal switch ", "");}
	;

IterationStatement
	: WHILE OPEN_B Expression CLOSE_B Statement				 { cout << "IterationStatement 1\n"; $<tn>$=ast->createNode($<tn>3, $<tn>5, WhileNode); }
	| WHILE OPEN_B CLOSE_B Statement				         { err->errQ->enqueue($<r.myLineNo>4,$<r.myColNo>4,"Error : WHILE without expression ","");}
	| DO Statement WHILE OPEN_B Expression CLOSE_B SEMICOLON { cout << "IterationStatement 2\n"; $<tn>$=ast->createNode($<tn>5, $<tn>2, DoWhileNode);}
	| DO Statement WHILE OPEN_B CLOSE_B SEMICOLON			 { err->errQ->enqueue($<r.myLineNo>6,$<r.myColNo>6,"Error : dowhile without expression ","");}
	| DO Statement WHILE OPEN_B CLOSE_B %prec e16            { err->errQ->enqueue($<r.myLineNo>4,$<r.myColNo>4,"Error : dowhile without expression and missing semicolon ","");}
	| FOR OPEN_B ForInit ForExpr ForIncr CLOSE_B Statement	 { cout << "IterationStatement 3\n"; $<tn>$=ast->createNode(0, 0, ForNode); }
	| FOR OPEN_B ForInit ForExpr         CLOSE_B Statement	 { cout << "IterationStatement 4\n"; $<tn>$=ast->createNode(0, 0, ForNode); }
	| FOR OPEN_B TypeName IDENTIFIER COLON IDENTIFIER CLOSE_B Statement	 { cout << "IterationStatement 5\n"; $<tn>$=ast->createNode(0, 0, ForNode); }
	| DO Statement WHILE OPEN_B Expression CLOSE_B	%prec e21		 { err->errQ->enqueue($<r.myLineNo>6,$<r.myColNo>6,"Error : dowhile missing semicolon ","");}
	;

ForInit
	: ExpressionStatements SEMICOLON	{ cout << "ForInit 1\n"; }
	| LocalVariableDeclarationStatement { cout << "ForInit 2\n";}
	| SEMICOLON							{ cout << "ForInit 3\n"; }
	;

ForExpr
	: Expression SEMICOLON { cout << "ForExpr 1\n"; }
	| SEMICOLON			   { cout << "ForExpr 2\n"; }
	;

ForIncr
	: ExpressionStatements { cout << "ForIncr\n";}
	;

ExpressionStatements
	: ExpressionStatement { cout << "ExpressionStatements\n"; }
	| ExpressionStatements COMMA ExpressionStatement 	{  cout << "ExpressionStatements 2\n";  }
	;

JumpStatement
	: BREAK IDENTIFIER SEMICOLON	{ cout << "JumpStatement 1\n"; $<tn>$=ast->createNode(0, 0, JumpStatementNode);}
	| BREAK            SEMICOLON	{ cout << "JumpStatement 2\n"; $<tn>$=ast->createNode(0, 0, JumpStatementNode);}
    | CONTINUE IDENTIFIER SEMICOLON { cout << "JumpStatement 3\n"; $<tn>$=ast->createNode(0, 0, JumpStatementNode);}
	| CONTINUE            SEMICOLON { cout << "JumpStatement 4\n"; $<tn>$=ast->createNode(0, 0, JumpStatementNode);}
	| RETURN Expression SEMICOLON	{ cout << "JumpStatement 5\n"; $<tn>$=ast->createNode($<tn>2, 0, JumpStatementNode);}
	| RETURN            SEMICOLON	{ cout << "JumpStatement 6\n"; $<tn>$=ast->createNode(0, 0, JumpStatementNode);}
	| THROW Expression SEMICOLON	{ cout << "JumpStatement 7\n"; $<tn>$=ast->createNode(0, 0, JumpStatementNode);}
	;

GuardingStatement
	: SYNCHRONIZED OPEN_B Expression CLOSE_B Statement { cout << "GuardingStatement 1\n"; }
	| TRY Block Finally	%prec e18					   { cout << "GuardingStatement 2\n"; $<tn>$=ast->createNode(0, 0, TryNode); }
	| TRY Block %prec e17                              {err->errQ->enqueue($<r.myLineNo>2,$<r.myColNo>2,"Error :Expected try catch or try finally", "" );}
	| TRY Block Catches	%prec e19					   { cout << "GuardingStatement 3\n"; $<tn>$=ast->createNode(0, 0, TryNode); }
	| CatchHeader								       {err->errQ->enqueue($<r.myLineNo>1,$<r.myColNo>1,"Error :Expected try catch or try catch finally", "" );}
	| TRY Block Catches Finally						   { cout << "GuardingStatement 4\n"; $<tn>$=ast->createNode(0, 0, TryNode); }
	;

Catches
	: Catch { cout << "Catches\n"; }
	| Catches Catch
	;

Catch
	: CatchHeader Block { cout << "Catch\n"; $<tn>$=ast->createNode($<tn>1, $<tn>2, catchNode);}
	;

CatchHeader
	: CATCH OPEN_B TypeSpecifier IDENTIFIER CLOSE_B { cout << "CatchHeader 1\n";$<tn>$=ast->createNode($<tn>1, $<tn>2, catchHeaderNode); }
	| CATCH OPEN_B TypeSpecifier CLOSE_B			{ cout << "CatchHeader 2\n";$<tn>$=ast->createNode($<tn>1, $<tn>2,  catchHeaderNode); }
	| CATCH OPEN_B CLOSE_B							{err->errQ->enqueue($<r.myLineNo>3,$<r.myColNo>3,"Error :illegal catch", "" );}
	;

Finally
	: FINALLY Block { cout << "Finally\n";$<tn>$=ast->createNode(0, $<tn>2, finallyNode); }
	;

PrimaryExpression
	: QualifiedName { cout << "PrimaryExpression 1\n"; $<tn>$=ast->createNode($<tn>1, 0, PrimaryExpressionNode);}
	| NotJustName	{ cout << "PrimaryExpression 2\n"; $<tn>$=ast->createNode($<tn>1, 0, PrimaryExpressionNode);}
	;

NotJustName
	: SpecialName			  { cout << "NotJustName 1\n"; $<tn>$=ast->createNode($<tn>1, 0, NotJustName); }
	| NewAllocationExpression { cout << "NotJustName 2\n"; $<tn>$=ast->createNode($<tn>1, 0, NotJustName); }
	| ComplexPrimary		  { cout << "NotJustName 3\n"; $<tn>$=ast->createNode($<tn>1, 0, NotJustName); }
	;

ComplexPrimary
	: OPEN_B Expression CLOSE_B	%prec e10  { cout << "ComplexPrimary 1\n"; }
	| ComplexPrimaryNoParenthesis { cout << "ComplexPrimary 2\n"; $<tn>$=ast->createNode($<tn>1, 0, ComplexPrimary); }
	;

ComplexPrimaryNoParenthesis
	: LITERAL	  { cout << "ComplexPrimaryNoParenthesis 1\n"; }
	| INTEGER_VALUE  { cout << "ComplexPrimaryNoParenthesis INTEGER_VALUE\n";
					   int * val = &$<r.i>1;
					   $<tn>$=ast->createNode(0, 0, Integer_Value,val); 
					 }
	| FLOAT_VALUE  { cout << "ComplexPrimaryNoParenthesis FLOAT_VALUE\n";
					 float * val = &$<r.f>1;
					 $<tn>$=ast->createNode(0, 0, Float_Value,val);
				   }
	| CHAR_VALUE  { cout << "ComplexPrimaryNoParenthesis CAHR_VALUE\n";
					 char * val = &$<r.c>1;
					 $<tn>$=ast->createNode(0, 0, Char_Value,val); 
				  }
	| LONG_VALUE  { cout << "ComplexPrimaryNoParenthesis LONG_VALUE\n";
					 int * val = &$<r.i>1;
					 $<tn>$=ast->createNode(0, 0, Long_Value,val); 
				  }
	| STRING_VALUE  { cout << "ComplexPrimaryNoParenthesis STRING_VALUE\n";
					 char * val = $<r.str>1;
					 $<tn>$=ast->createNode(0, 0, String_Value,val); 
					}
	| BOOLLIT	  { cout << "ComplexPrimaryNoParenthesis 2\n"; }
	| ArrayAccess { cout << "ComplexPrimaryNoParenthesis 3\n"; }
	| FieldAccess { cout << "ComplexPrimaryNoParenthesis 4\n"; 
					$<tn>$=ast->createNode($<tn>1, 0, FieldAccess);
				  }
	| MethodCall  { cout << "ComplexPrimaryNoParenthesis 5\n"; 
					$<tn>$=ast->createNode($<tn>1, 0, MethodCall);			
				  }
	;

ArrayAccess
	: QualifiedName OPEN Expression CLOSE  { cout << "ArrayAccess 1\n"; }
	| ComplexPrimary OPEN Expression CLOSE { cout << "ArrayAccess 2\n"; }
	;

FieldAccess
	: NotJustName POINT QualifiedName		 { cout << "FieldAccess 1\n"; $<tn>$=ast->createNode($<tn>3, $<tn>1, NotJustNameFieldAccess);}
	| RealPostfixExpression POINT IDENTIFIER { cout << "FieldAccess 2\n"; }
    | QualifiedName POINT THIS				 { cout << "FieldAccess 3\n"; }
    | QualifiedName POINT CLASS				 { cout << "FieldAccess 4\n"; }
    | PrimitiveType POINT CLASS				 { cout << "FieldAccess 5\n"; }
	;

MethodCall
	: MethodAccess OPEN_B ArgumentList CLOSE_B { cout << "MethodCall 1\n"; $<tn>$=ast->createNode($<tn>1, 0, MethodAccess); }
	| MethodAccess OPEN_B CLOSE_B			   { cout << "MethodCall 2\n"; $<tn>$=ast->createNode($<tn>1, 0, MethodAccess);}
	;

MethodAccess
	: ComplexPrimaryNoParenthesis { cout << "MethodAccess 1\n"; }
	| SpecialName				  { cout << "MethodAccess 2\n"; $<tn>$=$<tn>1; }
	| QualifiedName				  { cout << "MethodAccess 3\n"; $<tn>$=$<tn>1; }
	;

SpecialName
	: THIS  { cout << "SpecialName THIS\n"; $<tn>$=ast->createNode(0, 0, SpecialNameThis); }
	| SUPER { cout << "SpecialName SUPER\n"; $<tn>$=ast->createNode(0, 0, SpecialNameSuper);}
	| JNULL { cout << "SpecialName JNULL\n"; }
	;

ArgumentList
	: Expression					{ cout << "ArgumentList 1\n"; $<tn>$=ast->createNode($<tn>1, 0, ArgumentList); }
	| ArgumentList COMMA Expression { cout << "ArgumentList 2\n"; $<tn>$ = ast->addToLastRight($<tn>1, ast->createNode($<tn>3, 0, ArgumentList)); }
	;

NewAllocationExpression
    : PlainNewAllocationExpression					   { cout << "NewAllocationExpression 1\n"; $<tn>$ = $<tn>1; }
    | QualifiedName POINT PlainNewAllocationExpression { cout << "NewAllocationExpression 2\n"; $<tn>$=ast->createNode($<tn>1, $<tn>3, NewAllocationExpression); }
    ;

PlainNewAllocationExpression
    : ArrayAllocationExpression	%prec e13						 { cout << "PlainNewAllocationExpression 1\n"; $<tn>$=ast->createNode($<tn>1, 0, PlainNewAllocationExpression);}
    | ClassAllocationExpression	%prec e12 						 { cout << "PlainNewAllocationExpression 2\n"; $<tn>$=ast->createNode($<tn>1, 0, PlainNewAllocationExpression);}
    | ArrayAllocationExpression OPEN_D CLOSE_D					 { cout << "PlainNewAllocationExpression 3\n"; }
    | ClassAllocationExpression OPEN_D CLOSE_D					 { cout << "PlainNewAllocationExpression 4\n"; }
    | ArrayAllocationExpression OPEN_D ArrayInitializers CLOSE_D { cout << "PlainNewAllocationExpression 5\n"; }
    | ClassAllocationExpression OPEN_D FieldDeclarations CLOSE_D { cout << "PlainNewAllocationExpression 6\n"; }
    ;

ClassAllocationExpression
	: NEW NewOfObject { cout << "ClassAllocationExpression 1\n"; $<tn>$=ast->createNode($<tn>2, 0, ClassAllocationExpression);}
	| NEW POINT  NewOfObject   { cout << "ClassAllocationExpression 2\n"; $<tn>$=ast->createNode($<tn>3, 0, ClassAllocationExpression);}
    ;

NewOfObject
	: TypeName OPEN_B ArgumentList CLOSE_B {cout << "newStatment 1 \n"; $<tn>$=ast->createNode($<tn>1, $<tn>3, NewOfObject);}
	| TypeName OPEN_B              CLOSE_B {cout << "newStatment 2 \n"; $<tn>$=ast->createNode($<tn>1, 0, NewOfObject);}
	;

ArrayAllocationExpression
	: NEW TypeName DimExprs Dims { cout << "ArrayAllocationExpression 1\n"; }
	| NEW TypeName DimExprs		 { cout << "ArrayAllocationExpression 2\n"; $<tn>$=ast->createNode($<tn>3, 0, ArrayAllocationExpression);}
    | NEW TypeName Dims			 { cout << "ArrayAllocationExpression 3\n"; }
	;

DimExprs
	: DimExpr		   { cout << "DimExprs 1\n"; $<tn>$=ast->createNode($<tn>1, 0,DimExprListNode); }
	| DimExprs DimExpr { cout << "DimExprs 2\n"; $<tn>$ = ast->addToLastRight($<tn>1, ast->createNode($<tn>2, 0, DimExprListNode)); }
	;

DimExpr
	: OPEN Expression CLOSE { cout << "DimExpr\n"; $<tn>$=ast->createNode($<tn>2, 0,DimExpr); }
	;

Dims
	: OP_DIM { cout << "Dims\n"; }
	| Dims OP_DIM
	;

PostfixExpression
	: PrimaryExpression		{ cout << "PostfixExpression 1\n"; $<tn>$=ast->createNode($<tn>1, 0, PostfixExpressionNode);}
	| RealPostfixExpression { cout << "PostfixExpression 2\n"; $<tn>$=ast->createNode($<tn>1, 0, PostfixExpressionNode);}
	;

RealPostfixExpression
	: PostfixExpression OP_INC { cout << "RealPostfixExpression 1\n"; $<tn>$=ast->createNode(0, 0, RealPostfixExpressionNode); }
	| PostfixExpression OP_DEC { cout << "RealPostfixExpression 2\n"; $<tn>$=ast->createNode(0, 0, RealPostfixExpressionNode);}
	;

UnaryExpression
	: OP_INC UnaryExpression				 { cout << "UnaryExpression 1\n"; $<tn>$ = ast->addToLastRight($<tn>2, ast->createNode(0, 0, UnaryExpressionListNode)); }
	| OP_DEC UnaryExpression				 { cout << "UnaryExpression 2\n"; $<tn>$ = ast->addToLastRight($<tn>2, ast->createNode(0, 0, UnaryExpressionListNode)); }
	| ArithmeticUnaryOperator CastExpression { cout << "UnaryExpression 3\n"; $<tn>$=ast->createNode($<tn>1, 0, UnaryExpressionListNode);}
	| LogicalUnaryExpression				 { cout << "UnaryExpression 4\n"; $<tn>$=ast->createNode($<tn>1, 0, UnaryExpressionListNode);}
	;

LogicalUnaryExpression
	: PostfixExpression					   { cout << "LogicalUnaryExpression 1\n"; $<tn>$=ast->createNode($<tn>1, 0, LogicalUnaryExpressionNode); }
	| LogicalUnaryOperator UnaryExpression { cout << "LogicalUnaryExpression 2\n"; $<tn>$=ast->createNode($<tn>1, 0, LogicalUnaryExpressionNode); }
	;

LogicalUnaryOperator
	: DURA	   { cout << "LogicalUnaryOperator DURA\n"; $<tn>$=ast->createNode(0, 0, LogicalUnaryOperatorNode); }
	| EXC_MARK { cout << "LogicalUnaryOperator EXC_MARK\n"; $<tn>$=ast->createNode(0, 0, LogicalUnaryOperatorNode); }
	;

ArithmeticUnaryOperator
	: PLUS	{ cout << "ArithmeticUnaryOperator PLUS\n"; $<tn>$=ast->createNode(0, 0, ArithmeticUnaryOperatorNode);}
	| MINUS { cout << "ArithmeticUnaryOperator MINUS\n"; $<tn>$=ast->createNode(0, 0, ArithmeticUnaryOperatorNode); }
	;

CastExpression
	: UnaryExpression										{ cout << "CastExpression 1\n"; $<tn>$ =ast->createNode($<tn>1, 0, CastExpressionListNode); }
	| OPEN_B PrimitiveTypeExpression CLOSE_B CastExpression { cout << "CastExpression 2\n"; $<tn>$ = ast->addToLastRight($<tn>4, ast->createNode(0, 0, CastExpressionListNode));}
	| OPEN_B ClassTypeExpression CLOSE_B CastExpression		{ cout << "CastExpression 3\n"; $<tn>$ = ast->addToLastRight($<tn>4, ast->createNode(0, 0, CastExpressionListNode));}
	| OPEN_B Expression CLOSE_B LogicalUnaryExpression		{ cout << "CastExpression 4\n"; $<tn>$ =ast->createNode(0, 0, CastExpressionListNode);}
	;

PrimitiveTypeExpression
	: PrimitiveType		 { cout << "PrimitiveTypeExpression 1\n"; }
    | PrimitiveType Dims { cout << "PrimitiveTypeExpression 2\n"; }
    ;

ClassTypeExpression
	: QualifiedName Dims { cout << "ClassTypeExpression\n"; }
    ;

MultiplicativeExpression
	: CastExpression								 { cout << "MultiplicativeExpression 1\n"; $<tn>$ =ast->createNode($<tn>1, 0, MultiplicativeExpressionListNode);}
	| MultiplicativeExpression MULT CastExpression	 { cout << "MultiplicativeExpression 2\n";$<tn>$=ast->addToLastRight($<tn>1, ast->createNode($<tn>3, 0, MultiplicativeExpressionListNode)); }
	| MultiplicativeExpression DIV CastExpression	 { cout << "MultiplicativeExpression 3\n";$<tn>$=ast->addToLastRight($<tn>1, ast->createNode($<tn>3, 0, MultiplicativeExpressionListNode)); }
	| MultiplicativeExpression MODULE CastExpression { cout << "MultiplicativeExpression 4\n";$<tn>$=ast->addToLastRight($<tn>1, ast->createNode($<tn>3, 0, MultiplicativeExpressionListNode)); }
	;

AdditiveExpression
	: MultiplicativeExpression							{ cout << "AdditiveExpression 1\n"; $<tn>$ =ast->createNode($<tn>1, 0, AdditiveExpressionListNode);}
    | AdditiveExpression PLUS MultiplicativeExpression	{ cout << "AdditiveExpression 2\n";  $<tn>$=ast->addToLastRight($<tn>1, ast->createNode($<tn>3, 0, AdditiveExpressionListNode));}
	| AdditiveExpression MINUS MultiplicativeExpression { cout << "AdditiveExpression 3\n";  $<tn>$=ast->addToLastRight($<tn>1, ast->createNode($<tn>3, 0, AdditiveExpressionListNode));}
    ;

ShiftExpression
	: AdditiveExpression						 { cout << "ShiftExpression 1\n";$<tn>$ =ast->createNode($<tn>1, 0, ShiftExpressionListNode); }
    | ShiftExpression OP_SHL AdditiveExpression	 { cout << "ShiftExpression 2\n"; $<tn>$=ast->addToLastRight($<tn>1, ast->createNode($<tn>3, 0, ShiftExpressionListNode)); }
    | ShiftExpression OP_SHR AdditiveExpression	 { cout << "ShiftExpression 3\n"; $<tn>$=ast->addToLastRight($<tn>1, ast->createNode($<tn>3, 0, ShiftExpressionListNode)); }
    | ShiftExpression OP_SHRR AdditiveExpression { cout << "ShiftExpression 4\n"; $<tn>$=ast->addToLastRight($<tn>1, ast->createNode($<tn>3, 0, ShiftExpressionListNode)); }
	;

RelationalExpression
	: ShiftExpression								{ cout << "RelationalExpression 1\n"; $<tn>$ =ast->createNode($<tn>1, 0, RelationalExpressionListNode); }
    | RelationalExpression LESS ShiftExpression		{ cout << "RelationalExpression 2\n"; $<tn>$=ast->addToLastRight($<tn>1, ast->createNode($<tn>3, 0, RelationalExpressionListNode)); }
	| RelationalExpression GREATER ShiftExpression	{ cout << "RelationalExpression 3\n"; $<tn>$=ast->addToLastRight($<tn>1, ast->createNode($<tn>3, 0, RelationalExpressionListNode)); }
	| RelationalExpression OP_LE ShiftExpression	{ cout << "RelationalExpression 4\n"; $<tn>$=ast->addToLastRight($<tn>1, ast->createNode($<tn>3, 0, RelationalExpressionListNode)); }
	| RelationalExpression OP_GE ShiftExpression	{ cout << "RelationalExpression 5\n"; $<tn>$=ast->addToLastRight($<tn>1, ast->createNode($<tn>3, 0, RelationalExpressionListNode)); }
	| RelationalExpression INSTANCEOF TypeSpecifier { cout << "RelationalExpression 6\n"; $<tn>$=ast->addToLastRight($<tn>1, ast->createNode(0, 0, RelationalExpressionListNode)); }
	;

EqualityExpression
	: RelationalExpression							{ cout << "EqualityExpression 1\n"; $<tn>$ =ast->createNode($<tn>1, 0, EqualityExpressionListNode);}
    | EqualityExpression OP_EQ RelationalExpression { cout << "EqualityExpression 2\n"; $<tn>$=ast->addToLastRight($<tn>1, ast->createNode($<tn>3, 0, EqualityExpressionListNode));}
    | EqualityExpression OP_NE RelationalExpression { cout << "EqualityExpression 3\n"; $<tn>$=ast->addToLastRight($<tn>1, ast->createNode($<tn>3, 0, EqualityExpressionListNode));}
    ;

AndExpression
	: EqualityExpression				   { cout << "AndExpression 1\n"; $<tn>$ =ast->createNode($<tn>1, 0, AndExpressionListNode);}
    | AndExpression AND EqualityExpression { cout << "AndExpression 2\n";$<tn>$=ast->addToLastRight($<tn>1, ast->createNode($<tn>3, 0, AndExpressionListNode)); }
    ;

ExclusiveOrExpression
	: AndExpression							  { cout << "ExclusiveOrExpression 1\n"; $<tn>$ =ast->createNode($<tn>1, 0, ExclusiveOrExpressionListNode);}
	| ExclusiveOrExpression XOR AndExpression { cout << "ExclusiveOrExpression 2\n";$<tn>$=ast->addToLastRight($<tn>1, ast->createNode($<tn>3, 0,ExclusiveOrExpressionListNode)); }
	;

InclusiveOrExpression
	: ExclusiveOrExpression							 { cout << "InclusiveOrExpression 1\n";$<tn>$ =ast->createNode($<tn>1, 0, InclusiveOrExpressionListNode); }
	| InclusiveOrExpression OR ExclusiveOrExpression { cout << "InclusiveOrExpression 2\n";$<tn>$=ast->addToLastRight($<tn>1, ast->createNode($<tn>3, 0,InclusiveOrExpressionListNode)); }
	;
	
ConditionalAndExpression
	: InclusiveOrExpression									 { cout << "ConditionalAndExpression 1\n"; $<tn>$ =ast->createNode($<tn>1, 0, ConditionalAndExpressionListNode); }
	| ConditionalAndExpression OP_LAND InclusiveOrExpression { cout << "ConditionalAndExpression 2\n"; $<tn>$ = ast->addToLastRight($<tn>1, ast->createNode($<tn>3, 0, ConditionalAndExpressionListNode)); }
	;

ConditionalOrExpression
	: ConditionalAndExpression								  { cout << "ConditionalOrExpression 1\n"; $<tn>$ =ast->createNode($<tn>1, 0, ConditionalOrExpressionListNode);}
	| ConditionalOrExpression OP_LOR ConditionalAndExpression { cout << "ConditionalOrExpression 2\n"; $<tn>$ = ast->addToLastRight($<tn>1, ast->createNode($<tn>3, 0, ConditionalOrExpressionListNode)); }
	;

ConditionalExpression
	: ConditionalOrExpression												   { cout << "ConditionalExpression 1\n"; $<tn>$=ast->createNode($<tn>1,0,ConditionalExpressionListNode);}
	| ConditionalOrExpression QUES_MARK Expression COLON ConditionalExpression { cout << "ConditionalExpression 2\n"; $<tn>$ = ast->addToLastRight($<tn>5, ast->createNode($<tn>1, 0, ConditionalExpressionListNode));}
	;

AssignmentExpression
	: ConditionalExpression									  { cout << "AssignmentExpression 1\n"; $<tn>$=ast->createNode($<tn>1, 0, AssignExpressionListNode);}
	| UnaryExpression AssignmentOperator AssignmentExpression { cout << "AssignmentExpression 2\n"; $<tn>$ = ast->addToLastRight($<tn>1, ast->createNode($<tn>3, $<tn>2, AssignExpressionListNode));} 
	;

AssignmentOperator
	: ASSIGN   { cout << "AssignmentOperator ASSIGN\n"; $<tn>$=ast->createNode(0, 0, Assign); }
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
	: AssignmentExpression { cout << "Expression\n";$<tn>$=ast->createNode($<tn>1, 0,ExpressionNode ); }
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
		ast->check(p);
	}
}
