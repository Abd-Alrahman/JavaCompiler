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
     ASSERT = 259,
     BOOLEAN = 260,
     BREAK = 261,
     BYVALUE = 262,
     CASE = 263,
     CAST = 264,
     CATCH = 265,
     CLASS = 266,
     CONST = 267,
     CONTINUE = 268,
     DEFAULT = 269,
     DO = 270,
     ENUM = 271,
     EXTENDS = 272,
     FINAL = 273,
     FINALLY = 274,
     FOR = 275,
     FUTURE = 276,
     GENERIC = 277,
     GOTO = 278,
     IF = 279,
     IMPLEMENTS = 280,
     IMPORT = 281,
     INNER = 282,
     INSTANCEOF = 283,
     INTERFACE = 284,
     NATIVE = 285,
     NEW = 286,
     JNULL = 287,
     OPERATOR = 288,
     OUTER = 289,
     PACKAGE = 290,
     PRIVATE = 291,
     PROTECTED = 292,
     PUBLIC = 293,
     REST = 294,
     RETURN = 295,
     STATIC = 296,
     SUPER = 297,
     SWITCH = 298,
     SYNCHRONIZED = 299,
     THIS = 300,
     THROW = 301,
     THROWS = 302,
     TRANSIENT = 303,
     TRY = 304,
     VAR = 305,
     VOID = 306,
     VOLATILE = 307,
     WHILE = 308,
     OP_INC = 309,
     OP_DEC = 310,
     OP_SHL = 311,
     OP_SHR = 312,
     OP_SHRR = 313,
     OP_GE = 314,
     OP_LE = 315,
     OP_EQ = 316,
     OP_NE = 317,
     OP_LAND = 318,
     OP_LOR = 319,
     OP_DIM = 320,
     ASS_MUL = 321,
     ASS_DIV = 322,
     ASS_MOD = 323,
     ASS_ADD = 324,
     ASS_SUB = 325,
     ASS_SHL = 326,
     ASS_SHR = 327,
     ASS_SHRR = 328,
     ASS_AND = 329,
     ASS_XOR = 330,
     ASS_OR = 331,
     OPEN_D = 332,
     CLOSE_D = 333,
     OPEN_B = 334,
     CLOSE_B = 335,
     OPEN = 336,
     CLOSE = 337,
     COLON = 338,
     COMMA = 339,
     PLUS = 340,
     MINUS = 341,
     MULT = 342,
     DIV = 343,
     AND = 344,
     OR = 345,
     QUES_MARK = 346,
     EXC_MARK = 347,
     MODULE = 348,
     DURA = 349,
     ASSIGN = 350,
     XOR = 351,
     LESS = 352,
     GREATER = 353,
     INT = 354,
     SHORT = 355,
     LONG = 356,
     FLOAT = 357,
     DOUBLE = 358,
     CHAR = 359,
     BYTE = 360,
     IDENTIFIER = 361,
     INTEGER_VALUE = 362,
     LONG_VALUE = 363,
     N_ID = 364,
     FLOAT_VALUE = 365,
     CHAR_VALUE = 366,
     STRING_VALUE = 367,
     BOOLLIT = 368,
     LITERAL = 369,
     e1 = 370,
     ELSE = 371,
     e4 = 372,
     e2 = 373,
     e3 = 374,
     e5 = 375,
     e6 = 376,
     e7 = 377,
     POINT = 378,
     SEMICOLON = 379,
     e8 = 380,
     e9 = 381
   };
#endif
/* Tokens.  */
#define ABSTRACT 258
#define ASSERT 259
#define BOOLEAN 260
#define BREAK 261
#define BYVALUE 262
#define CASE 263
#define CAST 264
#define CATCH 265
#define CLASS 266
#define CONST 267
#define CONTINUE 268
#define DEFAULT 269
#define DO 270
#define ENUM 271
#define EXTENDS 272
#define FINAL 273
#define FINALLY 274
#define FOR 275
#define FUTURE 276
#define GENERIC 277
#define GOTO 278
#define IF 279
#define IMPLEMENTS 280
#define IMPORT 281
#define INNER 282
#define INSTANCEOF 283
#define INTERFACE 284
#define NATIVE 285
#define NEW 286
#define JNULL 287
#define OPERATOR 288
#define OUTER 289
#define PACKAGE 290
#define PRIVATE 291
#define PROTECTED 292
#define PUBLIC 293
#define REST 294
#define RETURN 295
#define STATIC 296
#define SUPER 297
#define SWITCH 298
#define SYNCHRONIZED 299
#define THIS 300
#define THROW 301
#define THROWS 302
#define TRANSIENT 303
#define TRY 304
#define VAR 305
#define VOID 306
#define VOLATILE 307
#define WHILE 308
#define OP_INC 309
#define OP_DEC 310
#define OP_SHL 311
#define OP_SHR 312
#define OP_SHRR 313
#define OP_GE 314
#define OP_LE 315
#define OP_EQ 316
#define OP_NE 317
#define OP_LAND 318
#define OP_LOR 319
#define OP_DIM 320
#define ASS_MUL 321
#define ASS_DIV 322
#define ASS_MOD 323
#define ASS_ADD 324
#define ASS_SUB 325
#define ASS_SHL 326
#define ASS_SHR 327
#define ASS_SHRR 328
#define ASS_AND 329
#define ASS_XOR 330
#define ASS_OR 331
#define OPEN_D 332
#define CLOSE_D 333
#define OPEN_B 334
#define CLOSE_B 335
#define OPEN 336
#define CLOSE 337
#define COLON 338
#define COMMA 339
#define PLUS 340
#define MINUS 341
#define MULT 342
#define DIV 343
#define AND 344
#define OR 345
#define QUES_MARK 346
#define EXC_MARK 347
#define MODULE 348
#define DURA 349
#define ASSIGN 350
#define XOR 351
#define LESS 352
#define GREATER 353
#define INT 354
#define SHORT 355
#define LONG 356
#define FLOAT 357
#define DOUBLE 358
#define CHAR 359
#define BYTE 360
#define IDENTIFIER 361
#define INTEGER_VALUE 362
#define LONG_VALUE 363
#define N_ID 364
#define FLOAT_VALUE 365
#define CHAR_VALUE 366
#define STRING_VALUE 367
#define BOOLLIT 368
#define LITERAL 369
#define e1 370
#define ELSE 371
#define e4 372
#define e2 373
#define e3 374
#define e5 375
#define e6 376
#define e7 377
#define POINT 378
#define SEMICOLON 379
#define e8 380
#define e9 381




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 29 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
typedef union YYSTYPE {
	struct R{
		int i;
		float f;
		char c;
		char* str;
		int myLineNo;
		int myColNo;
		}r;
		class YaccSimpleType * yaccSimpleType;
		class Variable * variable;
		class Function * function;
		class Type * type;
	} YYSTYPE;
/* Line 1447 of yacc.c.  */
#line 305 "yacc.hpp"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



