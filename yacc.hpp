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
     SEMICOLON = 338,
     COLON = 339,
     POINT = 340,
     COMMA = 341,
     PLUS = 342,
     MINUS = 343,
     MULT = 344,
     DIV = 345,
     AND = 346,
     OR = 347,
     QUES_MARK = 348,
     EXC_MARK = 349,
     MODULE = 350,
     DURA = 351,
     ASSIGN = 352,
     XOR = 353,
     LESS = 354,
     GREATER = 355,
     INT = 356,
     SHORT = 357,
     LONG = 358,
     FLOAT = 359,
     DOUBLE = 360,
     CHAR = 361,
     BYTE = 362,
     IDENTIFIER = 363,
     INTEGER_VALUE = 364,
     LONG_VALUE = 365,
     N_ID = 366,
     FLOAT_VALUE = 367,
     CHAR_VALUE = 368,
     STRING_VALUE = 369,
     BOOLLIT = 370,
     LITERAL = 371,
     e1 = 372,
     ELSE = 373
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
#define SEMICOLON 338
#define COLON 339
#define POINT 340
#define COMMA 341
#define PLUS 342
#define MINUS 343
#define MULT 344
#define DIV 345
#define AND 346
#define OR 347
#define QUES_MARK 348
#define EXC_MARK 349
#define MODULE 350
#define DURA 351
#define ASSIGN 352
#define XOR 353
#define LESS 354
#define GREATER 355
#define INT 356
#define SHORT 357
#define LONG 358
#define FLOAT 359
#define DOUBLE 360
#define CHAR 361
#define BYTE 362
#define IDENTIFIER 363
#define INTEGER_VALUE 364
#define LONG_VALUE 365
#define N_ID 366
#define FLOAT_VALUE 367
#define CHAR_VALUE 368
#define STRING_VALUE 369
#define BOOLLIT 370
#define LITERAL 371
#define e1 372
#define ELSE 373




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 28 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
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
#line 285 "yacc.hpp"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



