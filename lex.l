%{
		#include "yacc.hpp"
		#include <iostream>
		#include <istream>
		#include <ostream>		
		#include <FlexLexer.h>	
		int lineNo = 1;
		int colNo = 1;
		int i;
        float f;
        double d;
%}
%option c++
%option noyywrap
%x multilinecomment
%x string

Identifier              [a-zA-Z_][a-zA-Z0-9_]*
Integer					[1-9][0-9]*|0	
Not_Identifier			[0-9][a-zA-Z0-9_]*		
Float					([+-]?[0-9]+"."[0-9]+["f"]?)|[0-9]["f"]?		
Single_line_comment		(#)+[^\n]*
Letter					[a-zA-Z_]
CR		[\r]
LF		[\n]
BLANK	[ ]
BLK		[\b]
TAB		[\t]
FF		[\f]
AnyButSlash	[^\/]
AnyButAstr	[^\*]
Comment1        [\/][\*]({AnyButAstr}|[\*]{AnyButSlash})*[\*][\/]
Comment2        [\/][\/].*
Comment		({Comment1}|{Comment2})
Dimension	[\[]({CR}|{LF}|{FF}|{TAB}|{BLK}|{BLANK}|{Comment})*[\]]


%%
"abstract"				{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return ABSTRACT;
						}

"assert"				{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return ASSERT;
						}

"boolean"				{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return BOOLEAN;
						}

"break"					{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return BREAK;
						}

"byvalue"				{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return BYVALUE;
						}

"case"					{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return CASE;
						}

"cast"					{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return CAST;
						}

"catch"					{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  CATCH;
						}

"class"					{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  CLASS;
						}

"const"					{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  CONST;
						}

"continue"				{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  CONTINUE;
						}

"default"				{
                            colNo += strlen(yytext);
                            yylval.r.myLineNo= lineNo; 
                            yylval.r.myColNo = colNo; 
                            return  DEFAULT;
                        }

"do"					{
                            colNo += strlen(yytext);
                            yylval.r.myLineNo= lineNo; 
                            yylval.r.myColNo = colNo; 
                            return  DO;
                        }

"else"					{
                            colNo += strlen(yytext);
                            yylval.r.myLineNo= lineNo; 
                            yylval.r.myColNo = colNo; 
                            return  ELSE;
                        }


"enum"					{
                            colNo += strlen(yytext);
                            yylval.r.myLineNo= lineNo; 
                            yylval.r.myColNo = colNo; 
                            return  ENUM;
                        }

"extends"				{
                            colNo += strlen(yytext); 
                            yylval.r.myLineNo= lineNo; 
                            yylval.r.myColNo = colNo; 
                            return  EXTENDS;
                        }

"final"					{
                            colNo += strlen(yytext);
                            yylval.r.myLineNo= lineNo; 
                            yylval.r.myColNo = colNo; 
                            return  FINAL;
                        }

"finally"				{
                            colNo += strlen(yytext);
                            yylval.r.myLineNo= lineNo; 
                            yylval.r.myColNo = colNo; 
                            return  FINALLY;
                        }

"for"					{
                            colNo += strlen(yytext);
                            yylval.r.myLineNo= lineNo; 
                            yylval.r.myColNo = colNo; 
                            return  FOR;
                        }

"future"				{
                            colNo += strlen(yytext);
                            yylval.r.myLineNo= lineNo; 
                            yylval.r.myColNo = colNo; 
                            return  FUTURE;
                        }

"generic"				{
                            colNo += strlen(yytext);
                            yylval.r.myLineNo= lineNo; 
                            yylval.r.myColNo = colNo; 
                            return  GENERIC;
                        }


"goto"					{
                            colNo += strlen(yytext);
                            yylval.r.myLineNo= lineNo; 
                            yylval.r.myColNo = colNo; 
                            return  GOTO;
                        }

"if"					{
                            colNo += strlen(yytext);
                            yylval.r.myLineNo= lineNo; 
                            yylval.r.myColNo = colNo; 
                            return  IF;
                        }

"implements"			{
                            colNo += strlen(yytext);
                            yylval.r.myLineNo= lineNo; 
                            yylval.r.myColNo = colNo; 
                            return  IMPLEMENTS;
                        }

"import"				{
                            colNo += strlen(yytext);
                            yylval.r.myLineNo= lineNo; 
                            yylval.r.myColNo = colNo; 
                            return  IMPORT;
                        }

"inner"					{
                            colNo += strlen(yytext);
                            yylval.r.myLineNo= lineNo; 
                            yylval.r.myColNo = colNo; 
                            return  INNER;
                        }

"instanceof"			{
                            colNo += strlen(yytext);
                            yylval.r.myLineNo= lineNo; 
                            yylval.r.myColNo = colNo; 
                            return  INSTANCEOF;}
                        

"interface"				{
                            colNo += strlen(yytext);
                            yylval.r.myLineNo= lineNo; 
                            yylval.r.myColNo = colNo; 
                            return  INTERFACE;
                        }

"native"				{
                            colNo += strlen(yytext);
                            yylval.r.myLineNo= lineNo; 
                            yylval.r.myColNo = colNo; 
                            return  NATIVE;
                        }

"new"					{
                            colNo += strlen(yytext);
                            yylval.r.myLineNo= lineNo; 
                            yylval.r.myColNo = colNo; 
                            return	NEW;
                        }


"null"					{
                            colNo += strlen(yytext);
                            yylval.r.myLineNo= lineNo; 
                            yylval.r.myColNo = colNo; 
                            return  JNULL;
                        }

"operator"				{
                            colNo += strlen(yytext);
                            yylval.r.myLineNo= lineNo; 
                            yylval.r.myColNo = colNo; 
                            return  OPERATOR;
                        }

"outer"					{
                            colNo += strlen(yytext);
                            yylval.r.myLineNo= lineNo; 
                            yylval.r.myColNo = colNo; 
                            return  OUTER;
                        }

"package"				{
                            colNo += strlen(yytext);
                            yylval.r.myLineNo= lineNo; 
                            yylval.r.myColNo = colNo; 
                            return  PACKAGE;}
                        

"private"				{
                            colNo += strlen(yytext);
                            yylval.r.myLineNo= lineNo; 
                            yylval.r.myColNo = colNo; 
                            return  PRIVATE;
                        }

"protected"				{
                            colNo += strlen(yytext);
                            yylval.r.myLineNo= lineNo; 
                            yylval.r.myColNo = colNo; 
                            return  PROTECTED;
                        }

"public"				{
                            colNo += strlen(yytext);
                            yylval.r.myLineNo= lineNo; 
                            yylval.r.myColNo = colNo; 
                            return  PUBLIC;
                        }
                        

"rest"					{
                            colNo += strlen(yytext);
                            yylval.r.myLineNo= lineNo; 
                            yylval.r.myColNo = colNo; 
                            return  REST;
                        }

"return"				{
							colNo += strlen(yytext);
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  RETURN;
						}

"static"				{
							colNo += strlen(yytext);
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  STATIC;
						}

"super"					{
							colNo += strlen(yytext);
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  SUPER;
						}

"switch"				{
							colNo += strlen(yytext);
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  SWITCH;
						}

"synchronized"			{
							colNo += strlen(yytext);
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  SYNCHRONIZED;
						}

"this"					{
							colNo += strlen(yytext);
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return	THIS;
						}

"throw"					{
							colNo += strlen(yytext);
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  THROW;
						}

"throws"				{
							colNo += strlen(yytext);
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  THROWS;
						}

"transient"				{
							colNo += strlen(yytext);
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  TRANSIENT;
						}

"try"					{
							colNo += strlen(yytext);
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  TRY;
						}
			
"var"					{
							colNo += strlen(yytext);
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  VAR;
						}

"void"					{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  VOID;
						}

"volatile"				{
							colNo += strlen(yytext);
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  VOLATILE;
						}

"while"					{
							colNo += strlen(yytext);
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  STATIC;
						}

"++"					{
							colNo += strlen(yytext);
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  OP_INC;
						}

"--"					{
							colNo += strlen(yytext);
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  OP_DEC;
						}

"<<"					{
							colNo += strlen(yytext);
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  OP_SHL;
						}

">>"					{
							colNo += strlen(yytext);
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  OP_SHR;
						}

">>>"					{
							colNo += strlen(yytext);
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  OP_SHRR;
						}

">="					{
							colNo += strlen(yytext);
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  OP_GE;
						}

"<="					{
							colNo += strlen(yytext);
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  OP_LE;
						}

"=="					{
							colNo += strlen(yytext);
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  OP_EQ;
						}

"!="					{
							colNo += strlen(yytext);
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  OP_NE;
						}

"&&"					{
							colNo += strlen(yytext);
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  OP_LAND;
						}

"||"					{
							colNo += strlen(yytext);
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  OP_LOR;
						}

"*="					{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  ASS_MUL;
						}

"/="					{
							colNo += strlen(yytext);
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  ASS_DIV;
						}

"%="					{
							colNo += strlen(yytext);
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  ASS_MOD;
						}

"+="					{
							colNo += strlen(yytext);
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  ASS_ADD;
						}

"-="					{
							colNo += strlen(yytext);
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  ASS_SUB;
						}

"<<="					{
							colNo += strlen(yytext);
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  ASS_SHL;
						}

">>="					{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  ASS_SHR;
						}

">>>="					{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  ASS_SHRR;
						}

"&="					{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  ASS_AND;
						}

"^="					{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  ASS_XOR;
						}

"|="					{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  ASS_OR;
						}

\n						{
							lineNo = lineNo+1;
							colNo = 1;
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo;
							//return NEW_LINE;
						}

\t						{
							colNo += 4;
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo;
							//return TAB;
						}

" "						{
							colNo += 1;
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo;
							//return SPACE;
						}

"{"						{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo;
							return OPEN_D;
						}

"}"						{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo;
							return CLOSE_D;
						}

"("						{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo;
							return OPEN_B;
						}

")"						{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo;
							return CLOSE_B;
						}

"["						{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo;
							return OPEN;
						}

"]"						{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo;
							return CLOSE;
						}

";"						{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo;
							return SEMICOLON;
						}

":"						{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo;
							return COLON;
						}

"."						{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo;
							return POINT;
						}

","						{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo;
							return COMMA;
						}

"+"						{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo;
							return PLUS;
						}

"-"						{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo;
							return MINUS;
						}

"*"						{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo;
							return MULT;
						}

"/"						{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo;
							return DIV;
						}

"&"						{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo;
							return AND;
						}

"|"						{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo;
							return OR;
						}

"?"						{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo;
							return QUES_MARK;
						}

"!"						{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo;
							return EXC_MARK;
						}

"%"						{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo;
							return MODULE;
						}

"~"						{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo;
							return DURA;
						}

"="						{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo;
							return ASSIGN;
						}

"^"						{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo;
							return XOR;
						}

"<"						{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo;
							return LESS;
						}

">"						{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo;
							return GREATER;
						}

"int"					{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo;
							int i = atoi(yytext);
							yylval.r.i=i;
							return INT;
						}

"short"					{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							int i = atoi(yytext);
							yylval.r.i=i;
							return SHORT;
						}

"long"					{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							int i = atoi(yytext);
							yylval.r.i=i;
							return  LONG;
						}

"float"					{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							float f = atof(yytext);
							yylval.r.i=f;
							return	FLOAT;
						}

"double"				{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							double d= atof(yytext);
							yylval.r.f = d;
							return  DOUBLE;
						}

"char"					{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  CHAR;
						}

"byte"					{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  BYTE;
						}

"true"					{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  BOOLLIT;
						}

"false"					{
							colNo += strlen(yytext); 
							yylval.r.myLineNo= lineNo; 
							yylval.r.myColNo = colNo; 
							return  BOOLLIT;
						}



\/\*                                        { BEGIN multilinecomment; }
<multilinecomment>[^*\n]*					{lineNo++;}
<multilinecomment>"*"+[^*/\n]*				{lineNo++;}
<multilinecomment>"*"+"/"                   { cout<<"\t it is a Multi Line Comment \n";
				   							yylval.r.myLineNo= lineNo; BEGIN INITIAL;
 }

 {Dimension}	{return OP_DIM;}


{Identifier}			{	
							yylval.r.myColNo = colNo;
							yylval.r.myLineNo = lineNo;
							colNo += strlen(yytext);
							char * x=new char [255];
							x[0] = '\0';
							strcpy(x, yytext);
							yylval.r.str = x;
							return IDENTIFIER;
						}

{Integer}				{
							yylval.r.myColNo = colNo;
							yylval.r.myLineNo = lineNo;
							colNo += strlen(yytext);
							cout<<":Integer value (yytext) ="<<yytext<<"\n";
							int i = atoi(yytext);
							cout<<":Int value as int ="<<i;
							yylval.r.i = i;
							if(strlen(yytext) <= 4)
								return INTEGER_VALUE;
							else
								return LONG_VALUE;
						}

{Not_Identifier}		{
							yylval.r.myColNo = colNo;
							yylval.r.myLineNo = lineNo;
							colNo += strlen(yytext);
							char * x=new char [255];
							x[0] = '\0';
							strcpy(x, yytext);
							yylval.r.str = x;
							return N_ID;
						}

{Float}					{
							yylval.r.myColNo = colNo;
							yylval.r.myLineNo = lineNo;
							colNo += strlen(yytext);
							cout<<":Float value (yytext) ="<<yytext<<"\n";
							float f = atof(yytext);
							cout<<":Float value as float ="<<f;
							yylval.r.f = f;
							return FLOAT_VALUE;
						}

\'(\\.|[^\\'])*\'		{
							yylval.r.myColNo = colNo;
							yylval.r.myLineNo = lineNo;
							colNo += strlen(yytext);

							char * x=new char [strlen(yytext)-2];
							x[0] = '\0';
							strncpy(x, yytext+1 , strlen(yytext) - 2);
							x[strlen(yytext) - 2]= '\0';
							cout << "CHAR: value (yytext) =" <<yytext<<"\n";
							yylval.r.c = *x;
							return CHAR_VALUE;
						}

\"(\\.|[^\\"])*\"		{
							yylval.r.myColNo = colNo;
							yylval.r.myLineNo = lineNo;
							colNo += strlen(yytext);
							char * s=new char [strlen(yytext)-2];
							s[0] = '\0';
							strncpy(s, yytext + 1, strlen(yytext) - 2);
							s[strlen(yytext) - 2] = '\0';
							//strcpy(yylval.r.str,s);
							cout<<":String value (yytext) ="<<yytext<<"\n";
							yylval.r.str = s;
							return	STRING_VALUE;
						}

{Single_line_comment}	{
							yylval.r.myColNo = colNo;
							yylval.r.myLineNo = lineNo;
							colNo += strlen(yytext);
							//cout<<"\t comment\n";
						}


%%

