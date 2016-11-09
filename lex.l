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

Single_line_comment		(\/\/)+[^\n]*
Integer					[1-9][0-9]*|0
Identifier              ($)[a-zA-Z_][a-zA-Z0-9_]*
Name					[a-zA-Z_][a-zA-Z0-9_]*


%%
"abstract"				{
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return ABSTRACT;}

"assert"     {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return ASSERT;}

"boolean"    {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return BOOLEAN;}

"break"   {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return BREAK;}

"byvalue"    {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return BYVALUE;}

"case"  {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return CASE;}

"cast"  {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return CAST;}

"catch" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  CATCH;}

"class" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  CLASS;}

"const" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  CONST;}

"continue" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  CONTINUE;}

"default" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  DEFAULT;}

"do" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  DO;}

"else" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  ELSE;}


"enum" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  ENUM;}

"extends" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  EXTENDS;}

"final" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  FINAL;}

"finally" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  FINALLY;}

"for" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  FOR;}

"future" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  FUTURE;}

"generic" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  GENERIC;}


"goto" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  GOTO;}

"if" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  IF;}

"implements" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  IMPLEMENTS;}

"import" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  IMPORT;}

"inner" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  INNER;}

"instanceof" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  INSTANCEOF;}

"interface" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  INTERFACE;}

"native" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  NATIVE;}

"new" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return	NEW;}


"jnull" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  JNULL;}

"operator" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  OPERATOR;}

"outer" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  OUTER;}

"package" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  PACKAGE;}

"private" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  PRIVATE;}

"protected" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  PROTECTED;}

"public" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  PUBLIC;}

"rest" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  REST;}

"return" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  RETURN;}

"static" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  STATIC;}

"super" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  SUPER;}

"switch" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  SWITCH;}

"synchronized" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  SYNCHRONIZED;}

"this" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return	THIS;}

"throw" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  THROW;}

"throws" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  THROWS;}

"transient" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  TRANSIENT;}

"try" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  TRY;}
			
"var" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  VAR;}

"void" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  VOID;}

"volatile" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  VOLATILE;}

"while" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  STATIC;}

"++" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  OP_INC;}

"--" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  OP_DEC;}

"<<" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  OP_SHL;}

">>" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  OP_SHR;}

">>>" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  OP_SHRR;}

">=" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  OP_GE;}

"<=" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  OP_LE;}

"==" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  OP_EQ;}

"!=" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  OP_NE;}

"&&" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  OP_LAND;}

"||" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  OP_LOR;}

"*=" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  ASS_MUL;}

"$$" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  OP_DIM;}

"/=" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  ASS_DIV;}

"%=" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  ASS_MOD;}

"+=" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  ASS_ADD;}

"-=" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  ASS_SUB;}

"<<=" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  ASS_SHL;}

">>=" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  ASS_SHR;}

">>>=" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  ASS_SHRR;}

"&=" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  ASS_AND;}

"^=" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  ASS_XOR;}

"|=" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  ASS_OR;}

"int" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo;
                        int i = atoi(yytext);
                        yyval.r.i=i;
                        if(i<=4) 
			return  INT;
                        else 
                        return LONG;}

"short" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
                        int i = atoi(yytext);
                        yyval.r.i=i;
                        return SHORT;}

"long" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
                        int i = atoi(yytext);
                        yyval.r.i=i;
			return  LONG;}

"float" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
                        float f = atof(yytext);
                        yyval.r.i=f;
			return	FLOAT;}

"double" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
                        double d= atof(yytext);
                        yyval.r.d=d;
			return  DOUBLE;}

"char" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  CHAR;}

"byte" {
colNo += strlen(yytext); 
			yylval.r.myLineNo= lineNo; 
			yylval.r.myColno = colNo; 
			return  BYTE;}




\/\*                                        { BEGIN multilinecomment; }
<multilinecomment>[^*\n]*					{;}
<multilinecomment>"*"+[^*/\n]*				{lineNo++;}
<multilinecomment>"*"+"/"                   { BEGIN INITIAL;cout<<"\t it is a Multi Line Comment \n";}

{Identifier}  {
												
		yylval.r.myLineNo = lineNo;
		colNo += strlen(yytext);
		yylval.r.myColno = colNo;
		yylval.r.str = new char[255];
	        yylval.r.str[0] = '\0';
		strcat(yylval.r.str, yytext);
	        cout<<"\t it is id \n";
		return IDENTIFIER;
	}
{Name}	{
	       yylval.r.str = new char[255];
	       yylval.r.str[0] = '\0';
	       strcat(yylval.r.str, yytext);
	       cout<<"\t it is name \n";
	       return NAME;
	}


%%

