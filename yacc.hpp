/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ABSTRACT = 258,
     BOOLEAN = 259,
     BREAK = 260,
     BYTE = 261,
     BYVALUE = 262,
     CASE = 263,
     CAST = 264,
     CATCH = 265,
     CHAR = 266,
     CLASS = 267,
     CONST = 268,
     CONTINUE = 269,
     DEFAULT = 270,
     DO = 271,
     DOUBLE = 272,
     EXTENDS = 273,
     FINAL = 274,
     FINALLY = 275,
     FLOAT = 276,
     FOR = 277,
     FUTURE = 278,
     GENERIC = 279,
     GOTO = 280,
     IF = 281,
     IMPLEMENTS = 282,
     IMPORT = 283,
     INNER = 284,
     INSTANCEOF = 285,
     INT = 286,
     INTERFACE = 287,
     LONG = 288,
     NATIVE = 289,
     NEW = 290,
     JNULL = 291,
     OPERATOR = 292,
     OUTER = 293,
     PACKAGE = 294,
     PRIVATE = 295,
     PROTECTED = 296,
     PUBLIC = 297,
     REST = 298,
     RETURN = 299,
     SHORT = 300,
     STATIC = 301,
     SUPER = 302,
     SWITCH = 303,
     SYNCHRONIZED = 304,
     THIS = 305,
     THROW = 306,
     THROWS = 307,
     TRANSIENT = 308,
     TRY = 309,
     VAR = 310,
     VOID = 311,
     VOLATILE = 312,
     WHILE = 313,
     OP_INC = 314,
     OP_DEC = 315,
     OP_SHL = 316,
     OP_SHR = 317,
     OP_SHRR = 318,
     OP_GE = 319,
     OP_LE = 320,
     OP_EQ = 321,
     OP_NE = 322,
     OP_LAND = 323,
     OP_LOR = 324,
     OP_DIM = 325,
     ASS_MUL = 326,
     ASS_DIV = 327,
     ASS_MOD = 328,
     ASS_ADD = 329,
     ASS_SUB = 330,
     ASS_SHL = 331,
     ASS_SHR = 332,
     ASS_SHRR = 333,
     ASS_AND = 334,
     ASS_XOR = 335,
     ASS_OR = 336,
     IDENTIFIER = 337,
     LITERAL = 338,
     BOOLLIT = 339,
     e1 = 340,
     ELSE = 341
   };
#endif
/* Tokens.  */
#define ABSTRACT 258
#define BOOLEAN 259
#define BREAK 260
#define BYTE 261
#define BYVALUE 262
#define CASE 263
#define CAST 264
#define CATCH 265
#define CHAR 266
#define CLASS 267
#define CONST 268
#define CONTINUE 269
#define DEFAULT 270
#define DO 271
#define DOUBLE 272
#define EXTENDS 273
#define FINAL 274
#define FINALLY 275
#define FLOAT 276
#define FOR 277
#define FUTURE 278
#define GENERIC 279
#define GOTO 280
#define IF 281
#define IMPLEMENTS 282
#define IMPORT 283
#define INNER 284
#define INSTANCEOF 285
#define INT 286
#define INTERFACE 287
#define LONG 288
#define NATIVE 289
#define NEW 290
#define JNULL 291
#define OPERATOR 292
#define OUTER 293
#define PACKAGE 294
#define PRIVATE 295
#define PROTECTED 296
#define PUBLIC 297
#define REST 298
#define RETURN 299
#define SHORT 300
#define STATIC 301
#define SUPER 302
#define SWITCH 303
#define SYNCHRONIZED 304
#define THIS 305
#define THROW 306
#define THROWS 307
#define TRANSIENT 308
#define TRY 309
#define VAR 310
#define VOID 311
#define VOLATILE 312
#define WHILE 313
#define OP_INC 314
#define OP_DEC 315
#define OP_SHL 316
#define OP_SHR 317
#define OP_SHRR 318
#define OP_GE 319
#define OP_LE 320
#define OP_EQ 321
#define OP_NE 322
#define OP_LAND 323
#define OP_LOR 324
#define OP_DIM 325
#define ASS_MUL 326
#define ASS_DIV 327
#define ASS_MOD 328
#define ASS_ADD 329
#define ASS_SUB 330
#define ASS_SHL 331
#define ASS_SHR 332
#define ASS_SHRR 333
#define ASS_AND 334
#define ASS_XOR 335
#define ASS_OR 336
#define IDENTIFIER 337
#define LITERAL 338
#define BOOLLIT 339
#define e1 340
#define ELSE 341




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 25 "C:\\Users\\Dell-PC\\documents\\visual studio 2013\\Projects\\JavaCompiler\\yacc.y"
typedef union YYSTYPE {
	struct R{
		int i;
		float f;
		char c;
		char* str;
		int myLineNo;
		int myColno;
		}r;
	} YYSTYPE;
/* Line 1447 of yacc.c.  */
#line 221 "yacc.hpp"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



