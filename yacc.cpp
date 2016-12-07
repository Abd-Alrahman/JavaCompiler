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

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 2 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"

	#include <iostream>
	using namespace std;
	#include <FlexLexer.h>
	#include "SymbolTable/MyParser.h"
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


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

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
/* Line 196 of yacc.c.  */
#line 377 "yacc.cpp"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 219 of yacc.c.  */
#line 389 "yacc.cpp"

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T) && (defined (__STDC__) || defined (__cplusplus))
# include <stddef.h> /* INFRINGES ON USER NAME SPACE */
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if defined (__STDC__) || defined (__cplusplus)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     define YYINCLUDED_STDLIB_H
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
#  endif
#  ifdef __cplusplus
extern "C" {
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if (! defined (malloc) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if (! defined (free) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifdef __cplusplus
}
#  endif
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  49
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1808

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  127
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  101
/* YYNRULES -- Number of rules. */
#define YYNRULES  302
/* YYNRULES -- Number of states. */
#define YYNSTATES  466

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   381

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    18,    20,
      22,    24,    26,    28,    30,    32,    34,    36,    38,    41,
      43,    47,    50,    53,    56,    58,    60,    62,    63,    67,
      70,    72,    75,    77,    80,    84,    86,    89,    91,    94,
      96,    99,   103,   109,   111,   115,   120,   124,   127,   130,
     132,   138,   143,   148,   153,   157,   161,   165,   169,   172,
     175,   177,   180,   182,   185,   187,   189,   191,   193,   195,
     197,   199,   201,   203,   205,   207,   209,   211,   214,   216,
     218,   221,   223,   226,   229,   231,   233,   235,   237,   239,
     243,   246,   248,   252,   254,   258,   260,   263,   267,   269,
     273,   276,   282,   287,   292,   296,   301,   305,   308,   310,
     314,   317,   321,   325,   327,   330,   333,   335,   337,   342,
     346,   350,   353,   358,   362,   365,   367,   370,   374,   376,
     380,   383,   385,   388,   390,   392,   396,   401,   403,   405,
     408,   410,   412,   414,   416,   418,   420,   423,   427,   430,
     432,   438,   446,   452,   458,   466,   474,   481,   484,   486,
     488,   491,   493,   495,   497,   501,   505,   508,   512,   515,
     519,   522,   526,   532,   536,   540,   545,   547,   550,   553,
     559,   564,   567,   569,   571,   573,   575,   577,   581,   583,
     585,   587,   589,   591,   593,   595,   597,   599,   601,   603,
     608,   613,   617,   621,   625,   629,   633,   638,   642,   644,
     646,   648,   650,   652,   654,   656,   660,   662,   666,   668,
     670,   674,   678,   683,   688,   694,   699,   704,   708,   712,
     714,   717,   721,   723,   726,   728,   730,   733,   736,   739,
     742,   745,   747,   749,   752,   754,   756,   758,   760,   762,
     767,   772,   777,   779,   782,   785,   787,   791,   795,   799,
     801,   805,   809,   811,   815,   819,   823,   825,   829,   833,
     837,   841,   845,   847,   851,   855,   857,   861,   863,   867,
     869,   873,   875,   879,   881,   885,   887,   893,   895,   899,
     901,   903,   905,   907,   909,   911,   913,   915,   917,   919,
     921,   923,   925
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short int yyrhs[] =
{
     133,     0,    -1,   129,    -1,   129,   203,    -1,   131,    -1,
     140,    -1,   140,    -1,   130,    84,   140,    -1,     5,    -1,
     104,    -1,   105,    -1,   100,    -1,    99,    -1,   101,    -1,
     102,    -1,   103,    -1,    51,    -1,   124,    -1,   132,   124,
      -1,   134,    -1,   135,   138,   136,    -1,   135,   138,    -1,
     135,   136,    -1,   138,   136,    -1,   135,    -1,   138,    -1,
     136,    -1,    -1,    35,   140,   132,    -1,    35,   140,    -1,
      35,    -1,    35,   132,    -1,   132,    -1,   140,   132,    -1,
     140,   140,   132,    -1,   137,    -1,   136,   137,    -1,   141,
      -1,   141,   132,    -1,   139,    -1,   138,   139,    -1,    26,
     140,   132,    -1,    26,   140,   123,    87,   132,    -1,   106,
      -1,   140,   123,   106,    -1,   142,    77,   147,    78,    -1,
     142,    77,    78,    -1,   142,    78,    -1,   142,    77,    -1,
     142,    -1,   143,   145,   106,   166,   146,    -1,   143,   145,
     106,   166,    -1,   143,   145,   106,   146,    -1,   145,   106,
     166,   146,    -1,   143,   145,   106,    -1,   140,   145,   106,
      -1,   145,   106,   166,    -1,   145,   106,   146,    -1,   145,
     106,    -1,   143,   145,    -1,   145,    -1,   145,   166,    -1,
     144,    -1,   143,   144,    -1,     3,    -1,    18,    -1,    38,
      -1,    37,    -1,    36,    -1,    41,    -1,    48,    -1,    52,
      -1,    30,    -1,    44,    -1,    11,    -1,    29,    -1,   128,
      -1,    25,   130,    -1,    25,    -1,   148,    -1,   147,   148,
      -1,   149,    -1,   149,   132,    -1,   150,   124,    -1,   155,
      -1,   162,    -1,   164,    -1,   165,    -1,   141,    -1,   143,
     128,   151,    -1,   128,   151,    -1,   152,    -1,   151,    84,
     152,    -1,   159,    -1,   159,    95,   153,    -1,   226,    -1,
      77,    78,    -1,    77,   154,    78,    -1,   153,    -1,   154,
      84,   153,    -1,   154,    84,    -1,   143,   128,   156,   160,
     161,    -1,   143,   128,   156,   161,    -1,   128,   156,   160,
     161,    -1,   128,   156,   161,    -1,   159,    79,   157,    80,
      -1,   159,    79,    80,    -1,   156,    65,    -1,   158,    -1,
     157,    84,   158,    -1,   128,   159,    -1,   128,   159,    95,
      -1,    18,   128,   159,    -1,   106,    -1,   159,    65,    -1,
      47,   130,    -1,   167,    -1,   124,    -1,   143,   163,   160,
     167,    -1,   143,   163,   167,    -1,   163,   160,   167,    -1,
     163,   167,    -1,   106,    79,   157,    80,    -1,   106,    79,
      80,    -1,    41,   167,    -1,   167,    -1,    17,   129,    -1,
     166,    84,   129,    -1,    17,    -1,    77,   168,    78,    -1,
      77,    78,    -1,   169,    -1,   168,   169,    -1,   170,    -1,
     171,    -1,   128,   151,   124,    -1,    18,   128,   151,   124,
      -1,   172,    -1,   173,    -1,   174,   124,    -1,   175,    -1,
     176,    -1,   181,    -1,   182,    -1,   167,    -1,   124,    -1,
     106,    83,    -1,     8,   227,    83,    -1,    14,    83,    -1,
     226,    -1,    24,    79,   226,    80,   171,    -1,    24,    79,
     226,    80,   171,   116,   171,    -1,    43,    79,   226,    80,
     167,    -1,    53,    79,   226,    80,   171,    -1,    15,   171,
      53,    79,   226,    80,   124,    -1,    20,    79,   177,   178,
     179,    80,   171,    -1,    20,    79,   177,   178,    80,   171,
      -1,   180,   124,    -1,   170,    -1,   124,    -1,   226,   124,
      -1,   124,    -1,   180,    -1,   174,    -1,   180,    84,   174,
      -1,     6,   106,   124,    -1,     6,   124,    -1,    13,   106,
     124,    -1,    13,   124,    -1,    40,   226,   124,    -1,    40,
     124,    -1,    46,   226,   124,    -1,    44,    79,   226,    80,
     171,    -1,    49,   167,   186,    -1,    49,   167,   183,    -1,
      49,   167,   183,   186,    -1,   184,    -1,   183,   184,    -1,
     185,   167,    -1,    10,    79,   128,   106,    80,    -1,    10,
      79,   128,    80,    -1,    19,   167,    -1,   140,    -1,   188,
      -1,   195,    -1,   197,    -1,   189,    -1,    79,   226,    80,
      -1,   190,    -1,   114,    -1,   107,    -1,   110,    -1,   111,
      -1,   108,    -1,   112,    -1,   113,    -1,   191,    -1,   192,
      -1,   193,    -1,   140,    81,   226,    82,    -1,   189,    81,
     226,    82,    -1,   188,   123,   106,    -1,   205,   123,   106,
      -1,   140,   123,    45,    -1,   140,   123,    11,    -1,   131,
     123,    11,    -1,   194,    79,   196,    80,    -1,   194,    79,
      80,    -1,   190,    -1,   195,    -1,   140,    -1,    45,    -1,
      42,    -1,    32,    -1,   226,    -1,   196,    84,   226,    -1,
     198,    -1,   140,   123,   198,    -1,   200,    -1,   199,    -1,
     200,    77,    78,    -1,   199,    77,    78,    -1,   200,    77,
     154,    78,    -1,   199,    77,   147,    78,    -1,    31,   129,
      79,   196,    80,    -1,    31,   129,    79,    80,    -1,    31,
     129,   201,   203,    -1,    31,   129,   201,    -1,    31,   129,
     203,    -1,   202,    -1,   201,   202,    -1,    81,   226,    82,
      -1,    65,    -1,   203,    65,    -1,   187,    -1,   205,    -1,
     204,    54,    -1,   204,    55,    -1,    54,   206,    -1,    55,
     206,    -1,   209,   210,    -1,   207,    -1,   204,    -1,   208,
     206,    -1,    94,    -1,    92,    -1,    85,    -1,    86,    -1,
     206,    -1,    79,   211,    80,   210,    -1,    79,   212,    80,
     210,    -1,    79,   226,    80,   207,    -1,   131,    -1,   131,
     203,    -1,   140,   203,    -1,   210,    -1,   213,    87,   210,
      -1,   213,    88,   210,    -1,   213,    93,   210,    -1,   213,
      -1,   214,    85,   213,    -1,   214,    86,   213,    -1,   214,
      -1,   215,    56,   214,    -1,   215,    57,   214,    -1,   215,
      58,   214,    -1,   215,    -1,   216,    97,   215,    -1,   216,
      98,   215,    -1,   216,    60,   215,    -1,   216,    59,   215,
      -1,   216,    28,   128,    -1,   216,    -1,   217,    61,   216,
      -1,   217,    62,   216,    -1,   217,    -1,   218,    89,   217,
      -1,   218,    -1,   219,    96,   218,    -1,   219,    -1,   220,
      90,   219,    -1,   220,    -1,   221,    63,   220,    -1,   221,
      -1,   222,    64,   221,    -1,   222,    -1,   222,    91,   226,
      83,   223,    -1,   223,    -1,   206,   225,   224,    -1,    95,
      -1,    66,    -1,    67,    -1,    68,    -1,    69,    -1,    70,
      -1,    71,    -1,    72,    -1,    73,    -1,    74,    -1,    75,
      -1,    76,    -1,   224,    -1,   223,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,    96,    96,    97,   101,   102,   106,   107,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   123,   124,   128,
     134,   135,   136,   137,   138,   139,   140,   141,   145,   146,
     147,   148,   149,   150,   151,   156,   157,   161,   162,   166,
     167,   171,   172,   177,   178,   182,   183,   184,   188,   192,
     199,   203,   207,   211,   215,   219,   223,   227,   231,   235,
     239,   243,   250,   251,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   268,   269,   270,   274,   275,   279,
     280,   284,   285,   289,   290,   291,   292,   293,   294,   298,
     299,   306,   307,   311,   312,   316,   317,   318,   322,   323,
     324,   328,   329,   330,   331,   335,   336,   337,   341,   342,
     346,   347,   348,   352,   353,   357,   361,   362,   366,   367,
     368,   369,   373,   374,   378,   382,   386,   387,   388,   392,
     393,   397,   398,   402,   403,   407,   408,   412,   413,   414,
     415,   416,   417,   418,   419,   423,   427,   428,   429,   433,
     437,   438,   439,   443,   444,   445,   446,   450,   451,   452,
     456,   457,   461,   465,   466,   470,   471,   472,   473,   474,
     475,   476,   480,   481,   482,   483,   487,   488,   492,   496,
     497,   501,   505,   506,   510,   511,   512,   516,   517,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   534,
     535,   539,   540,   541,   542,   543,   547,   548,   552,   553,
     554,   558,   559,   560,   564,   565,   569,   570,   574,   575,
     576,   577,   578,   579,   583,   584,   588,   589,   590,   594,
     595,   599,   603,   604,   608,   609,   613,   614,   618,   619,
     620,   621,   625,   626,   630,   631,   635,   636,   640,   641,
     642,   643,   647,   648,   652,   656,   657,   658,   659,   663,
     664,   665,   669,   670,   671,   672,   676,   677,   678,   679,
     680,   681,   685,   686,   687,   691,   692,   696,   697,   701,
     702,   706,   707,   711,   712,   716,   717,   721,   722,   852,
     853,   854,   855,   856,   857,   858,   859,   860,   861,   862,
     863,   867,   871
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ABSTRACT", "ASSERT", "BOOLEAN", "BREAK",
  "BYVALUE", "CASE", "CAST", "CATCH", "CLASS", "CONST", "CONTINUE",
  "DEFAULT", "DO", "ENUM", "EXTENDS", "FINAL", "FINALLY", "FOR", "FUTURE",
  "GENERIC", "GOTO", "IF", "IMPLEMENTS", "IMPORT", "INNER", "INSTANCEOF",
  "INTERFACE", "NATIVE", "NEW", "JNULL", "OPERATOR", "OUTER", "PACKAGE",
  "PRIVATE", "PROTECTED", "PUBLIC", "REST", "RETURN", "STATIC", "SUPER",
  "SWITCH", "SYNCHRONIZED", "THIS", "THROW", "THROWS", "TRANSIENT", "TRY",
  "VAR", "VOID", "VOLATILE", "WHILE", "OP_INC", "OP_DEC", "OP_SHL",
  "OP_SHR", "OP_SHRR", "OP_GE", "OP_LE", "OP_EQ", "OP_NE", "OP_LAND",
  "OP_LOR", "OP_DIM", "ASS_MUL", "ASS_DIV", "ASS_MOD", "ASS_ADD",
  "ASS_SUB", "ASS_SHL", "ASS_SHR", "ASS_SHRR", "ASS_AND", "ASS_XOR",
  "ASS_OR", "OPEN_D", "CLOSE_D", "OPEN_B", "CLOSE_B", "OPEN", "CLOSE",
  "COLON", "COMMA", "PLUS", "MINUS", "MULT", "DIV", "AND", "OR",
  "QUES_MARK", "EXC_MARK", "MODULE", "DURA", "ASSIGN", "XOR", "LESS",
  "GREATER", "INT", "SHORT", "LONG", "FLOAT", "DOUBLE", "CHAR", "BYTE",
  "IDENTIFIER", "INTEGER_VALUE", "LONG_VALUE", "N_ID", "FLOAT_VALUE",
  "CHAR_VALUE", "STRING_VALUE", "BOOLLIT", "LITERAL", "e1", "ELSE", "e4",
  "e2", "e3", "e5", "e6", "e7", "POINT", "SEMICOLON", "e8", "e9",
  "$accept", "TypeSpecifier", "TypeName", "ClassNameList", "PrimitiveType",
  "SemiColons", "CompilationUnit", "ProgramFile", "PackageStatement",
  "TypeDeclarations", "TypeDeclarationOptSemi", "ImportStatements",
  "ImportStatement", "QualifiedName", "TypeDeclaration", "ClassHeader",
  "Modifiers", "Modifier", "ClassWord", "Interfaces", "FieldDeclarations",
  "FieldDeclarationOptSemi", "FieldDeclaration",
  "FieldVariableDeclaration", "VariableDeclarators", "VariableDeclarator",
  "VariableInitializer", "ArrayInitializers", "MethodDeclaration",
  "MethodDeclarator", "ParameterList", "Parameter", "DeclaratorName",
  "Throws", "MethodBody", "ConstructorDeclaration",
  "ConstructorDeclarator", "StaticInitializer", "NonStaticInitializer",
  "Extends", "Block", "LocalVariableDeclarationsAndStatements",
  "LocalVariableDeclarationOrStatement",
  "LocalVariableDeclarationStatement", "Statement", "EmptyStatement",
  "LabelStatement", "ExpressionStatement", "SelectionStatement",
  "IterationStatement", "ForInit", "ForExpr", "ForIncr",
  "ExpressionStatements", "JumpStatement", "GuardingStatement", "Catches",
  "Catch", "CatchHeader", "Finally", "PrimaryExpression", "NotJustName",
  "ComplexPrimary", "ComplexPrimaryNoParenthesis", "ArrayAccess",
  "FieldAccess", "MethodCall", "MethodAccess", "SpecialName",
  "ArgumentList", "NewAllocationExpression",
  "PlainNewAllocationExpression", "ClassAllocationExpression",
  "ArrayAllocationExpression", "DimExprs", "DimExpr", "Dims",
  "PostfixExpression", "RealPostfixExpression", "UnaryExpression",
  "LogicalUnaryExpression", "LogicalUnaryOperator",
  "ArithmeticUnaryOperator", "CastExpression", "PrimitiveTypeExpression",
  "ClassTypeExpression", "MultiplicativeExpression", "AdditiveExpression",
  "ShiftExpression", "RelationalExpression", "EqualityExpression",
  "AndExpression", "ExclusiveOrExpression", "InclusiveOrExpression",
  "ConditionalAndExpression", "ConditionalOrExpression",
  "ConditionalExpression", "AssignmentExpression", "AssignmentOperator",
  "Expression", "ConstantExpression", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,   127,   128,   128,   129,   129,   130,   130,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   132,   132,   133,
     134,   134,   134,   134,   134,   134,   134,   134,   135,   135,
     135,   135,   135,   135,   135,   136,   136,   137,   137,   138,
     138,   139,   139,   140,   140,   141,   141,   141,   141,   141,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   143,   143,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   145,   145,   145,   146,   146,   147,
     147,   148,   148,   149,   149,   149,   149,   149,   149,   150,
     150,   151,   151,   152,   152,   153,   153,   153,   154,   154,
     154,   155,   155,   155,   155,   156,   156,   156,   157,   157,
     158,   158,   158,   159,   159,   160,   161,   161,   162,   162,
     162,   162,   163,   163,   164,   165,   166,   166,   166,   167,
     167,   168,   168,   169,   169,   170,   170,   171,   171,   171,
     171,   171,   171,   171,   171,   172,   173,   173,   173,   174,
     175,   175,   175,   176,   176,   176,   176,   177,   177,   177,
     178,   178,   179,   180,   180,   181,   181,   181,   181,   181,
     181,   181,   182,   182,   182,   182,   183,   183,   184,   185,
     185,   186,   187,   187,   188,   188,   188,   189,   189,   190,
     190,   190,   190,   190,   190,   190,   190,   190,   190,   191,
     191,   192,   192,   192,   192,   192,   193,   193,   194,   194,
     194,   195,   195,   195,   196,   196,   197,   197,   198,   198,
     198,   198,   198,   198,   199,   199,   200,   200,   200,   201,
     201,   202,   203,   203,   204,   204,   205,   205,   206,   206,
     206,   206,   207,   207,   208,   208,   209,   209,   210,   210,
     210,   210,   211,   211,   212,   213,   213,   213,   213,   214,
     214,   214,   215,   215,   215,   215,   216,   216,   216,   216,
     216,   216,   217,   217,   217,   218,   218,   219,   219,   220,
     220,   221,   221,   222,   222,   223,   223,   224,   224,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   226,   227
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       3,     2,     2,     2,     1,     1,     1,     0,     3,     2,
       1,     2,     1,     2,     3,     1,     2,     1,     2,     1,
       2,     3,     5,     1,     3,     4,     3,     2,     2,     1,
       5,     4,     4,     4,     3,     3,     3,     3,     2,     2,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       2,     1,     2,     2,     1,     1,     1,     1,     1,     3,
       2,     1,     3,     1,     3,     1,     2,     3,     1,     3,
       2,     5,     4,     4,     3,     4,     3,     2,     1,     3,
       2,     3,     3,     1,     2,     2,     1,     1,     4,     3,
       3,     2,     4,     3,     2,     1,     2,     3,     1,     3,
       2,     1,     2,     1,     1,     3,     4,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     2,     3,     2,     1,
       5,     7,     5,     5,     7,     7,     6,     2,     1,     1,
       2,     1,     1,     1,     3,     3,     2,     3,     2,     3,
       2,     3,     5,     3,     3,     4,     1,     2,     2,     5,
       4,     2,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     3,     3,     3,     3,     3,     4,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     3,     1,     1,
       3,     3,     4,     4,     5,     4,     4,     3,     3,     1,
       2,     3,     1,     2,     1,     1,     2,     2,     2,     2,
       2,     1,     1,     2,     1,     1,     1,     1,     1,     4,
       4,     4,     1,     2,     2,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     1,     3,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     5,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short int yydefact[] =
{
      27,    64,     8,    74,    65,     0,    75,    72,    30,    68,
      67,    66,    69,    73,    70,    16,    71,    12,    11,    13,
      14,    15,     9,    10,    43,    17,    76,     2,     4,    32,
       0,    19,    24,    26,    35,    25,    39,     5,    37,    49,
       0,    62,    60,     0,    31,    29,   232,     3,    18,     1,
      22,    21,     5,    36,    23,    40,     0,    33,     5,     0,
      38,    48,    47,     5,    63,    59,   128,    58,    61,     0,
      41,    28,   233,    20,    44,    34,    55,    69,     0,    46,
      43,    76,    88,     0,     0,    79,    81,     0,    84,    85,
       0,    86,    87,   125,    54,   126,    78,    57,    56,     0,
       0,   124,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   213,     0,   212,     0,     0,   211,     0,     0,     0,
       0,     0,   130,     0,   246,   247,   245,   244,    43,   190,
     193,   191,   192,   194,   195,   189,   145,     0,     4,   182,
     144,     0,   131,   133,   134,   137,   138,     0,   140,   141,
     142,   143,   234,   183,   186,   188,   196,   197,   198,     0,
     184,   185,   216,   219,   218,   242,   235,   248,   241,     0,
       0,   255,   259,   262,   266,   272,   275,   277,   279,   281,
     283,   285,   287,   301,   149,     0,   113,    90,    91,     0,
      93,    76,     0,    45,    80,    82,    83,     0,     0,   121,
      52,    51,    77,     6,    53,   127,    42,     0,   166,     0,
     182,   248,   302,     0,     0,   168,   148,     0,     0,     0,
       0,     0,   170,     0,     0,     0,     0,     0,     0,     0,
     238,   239,   252,   182,     0,     0,     0,   146,     0,    93,
       0,     0,     0,   129,   132,   139,     0,     0,     0,     0,
       0,   236,   237,     0,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   289,     0,   243,   240,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   123,     0,     0,   108,     0,   107,   117,     0,   104,
     116,   114,     0,     0,    89,     0,     0,   119,   115,   120,
      50,     0,   165,   147,   167,     0,     0,   159,   158,   163,
       0,     0,     0,     0,     0,   227,   229,   228,   169,     0,
       0,   171,     0,     0,   174,   176,     0,   173,     0,     0,
     253,   254,     0,     0,   187,   135,   205,     0,   204,   203,
     217,   201,     0,   207,     0,   214,   221,     0,     0,   220,
      98,     0,    95,   202,   288,   256,   257,   258,   260,   261,
     263,   264,   265,   271,   270,   269,   267,   268,   273,   274,
     276,   278,   280,   282,   284,     0,     0,   110,   122,     0,
      92,   103,   106,     0,    94,     0,   102,   118,     7,     0,
     136,   161,     0,     0,     0,   157,     0,   225,     0,     0,
     230,   226,     0,     0,     0,   181,   177,   175,   178,     0,
     187,   249,   250,   251,   199,   200,   206,     0,   223,    96,
       0,   222,   100,     0,   112,   111,   109,   105,   101,     0,
       0,     0,   162,   160,   164,   150,   224,   231,   152,   172,
       0,   153,   215,    97,    99,   286,     0,   156,     0,     0,
     180,     0,   154,   155,   151,   179
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,    26,    27,   202,   209,    29,    30,    31,    32,    33,
      34,    35,    36,   210,    38,    39,    40,    41,    42,    97,
      84,    85,    86,    87,   187,   188,   360,   361,    88,   189,
     293,   294,   239,   198,   299,    89,    90,    91,    92,    68,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     320,   402,   441,   321,   150,   151,   334,   335,   336,   337,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   354,
     161,   162,   163,   164,   325,   326,    47,   165,   166,   167,
     168,   169,   170,   171,   234,   235,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   266,   184,
     213
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -294
static const short int yypact[] =
{
     391,  -294,  -294,  -294,  -294,   -65,  -294,  -294,    49,  -294,
    -294,  -294,  -294,  -294,  -294,  -294,  -294,  -294,  -294,  -294,
    -294,  -294,  -294,  -294,  -294,  -294,  -294,    12,  -294,    21,
      64,  -294,  1581,  1598,  -294,  1581,  -294,   276,    34,   151,
    1598,  -294,     3,   168,    21,   181,  -294,   112,  -294,  -294,
    1598,  1581,   357,  -294,  1598,  -294,    74,    21,   181,    86,
      21,  1339,  -294,    76,  -294,   110,   577,   154,   142,   -30,
      21,    21,  -294,  1598,  -294,    21,  -294,   164,   499,  -294,
     169,   140,  -294,  1702,  1356,  -294,    34,   119,  -294,  -294,
      41,  -294,  -294,  -294,   154,  -294,   -65,  -294,   -13,   577,
      34,  -294,    62,  1143,    84,   177,   723,   577,   200,   204,
     577,  -294,   807,  -294,   206,   219,  -294,  1143,   164,   233,
    1185,  1185,  -294,  1143,  -294,  -294,  -294,  -294,   190,  -294,
    -294,  -294,  -294,  -294,  -294,  -294,  -294,   140,   187,   -43,
    -294,   611,  -294,  -294,  -294,  -294,  -294,   213,  -294,  -294,
    -294,  -294,  -294,   201,   249,   259,  -294,  -294,  -294,   260,
     262,  -294,  -294,   266,   267,   253,   222,   497,  -294,  1185,
    1143,  -294,   152,   235,   231,   106,   261,   257,   251,   258,
     286,    72,  -294,  -294,  -294,   132,  -294,   269,  -294,    -3,
      75,   140,    41,  -294,  -294,    21,  -294,   -65,   164,  -294,
    -294,   -13,   272,    76,  -294,  -294,    21,   226,  -294,   187,
     -33,  -294,  -294,   268,   236,  -294,  -294,   308,   140,   765,
    1143,   144,  -294,   239,  1143,  1143,   240,   137,  1143,  1143,
    -294,  -294,   -36,    10,   285,   288,   289,  -294,   -31,    47,
     355,  1143,    14,  -294,  -294,  -294,   264,  1143,   975,  1460,
     891,  -294,  -294,   265,  -294,  -294,  -294,  -294,  -294,  -294,
    -294,  -294,  -294,  -294,  -294,  -294,  1143,  -294,  -294,  1143,
    1143,  1143,  1143,  1143,  1143,  1143,  1143,   577,  1143,  1143,
    1143,  1143,  1143,  1143,  1143,  1143,  1143,  1143,  1143,  1143,
     577,  -294,   140,   138,  -294,   140,  -294,  -294,   -56,  -294,
    -294,  -294,   368,  1017,   269,    -3,   164,  -294,   272,  -294,
    -294,   -65,  -294,  -294,  -294,   293,    22,  -294,  -294,  -294,
     849,    27,   294,  1059,  1143,   146,  -294,   112,  -294,   304,
     305,  -294,   314,   164,   137,  -294,   164,  -294,   315,   317,
     112,   112,  1143,  1143,  1227,  -294,  -294,   316,  -294,  -294,
    -294,  -294,   319,  -294,   167,  -294,  -294,  1477,   933,  -294,
    -294,   129,  -294,  -294,  -294,  -294,  -294,  -294,   152,   152,
     235,   235,   235,  -294,   231,   231,   231,   231,   106,   106,
     261,   257,   251,   258,   286,   320,   140,    79,  -294,   569,
    -294,  -294,  -294,   192,  -294,   -56,  -294,  -294,    76,  1143,
    -294,  -294,  1101,   281,  1143,  -294,   723,  -294,   194,   324,
    -294,   112,   164,   723,   577,  -294,  -294,  -294,  -294,   723,
    -294,  -294,  -294,  -294,  -294,  -294,  -294,  1143,  -294,  -294,
     136,  -294,  1017,  1143,   347,  -294,  -294,  -294,  -294,   335,
     723,   338,   339,  -294,  -294,   309,  -294,  -294,  -294,  -294,
     -11,  -294,  -294,  -294,  -294,  -294,   300,  -294,   723,   723,
    -294,   350,  -294,  -294,  -294,  -294
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -294,   -60,   -50,   234,    65,   124,  -294,  -294,  -294,   125,
     148,   401,    57,     0,   -58,  -294,   -54,    -1,    18,   -79,
     185,   -75,  -294,  -294,  -124,   141,  -293,    80,  -294,   246,
     139,    51,   -77,  -175,  -271,  -294,   361,  -294,  -294,   111,
      -5,  -294,   306,   227,  -100,  -294,  -294,  -208,  -294,  -294,
    -294,  -294,  -294,    43,  -294,  -294,  -294,   115,  -294,   116,
    -294,  -294,  -294,  -294,  -294,  -294,  -294,  -294,  -294,   128,
    -294,   211,  -294,  -294,  -294,   130,  -190,  -294,  -294,   -17,
     120,  -294,  -294,  -142,  -294,  -294,    61,    20,    37,    53,
     191,   180,   195,   189,   196,  -294,  -101,   212,  -294,   163,
    -294
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -211
static const short int yytable[] =
{
      37,    81,   212,    82,   190,    43,   217,    83,    45,   194,
     394,   319,    96,   238,   298,   200,    95,   306,   137,   204,
      66,    78,    -5,   191,    81,   348,    82,   391,   268,    46,
      83,   327,    52,    52,   396,    52,  -210,    58,   241,    64,
      63,    24,   340,   341,   197,   110,  -210,   218,   241,   205,
      52,    52,    63,   295,    52,    59,    93,   100,    65,   349,
     221,    52,   296,    -5,    49,    28,    63,   304,   297,   460,
      59,    99,   101,    52,    78,    46,    74,    46,   139,    93,
     242,   137,    64,    63,    52,   199,   211,   240,   197,  -210,
     242,   241,    55,   345,   316,   461,   203,    28,    28,    63,
      28,    65,    28,   230,   231,    28,   295,    63,    55,    67,
      63,   404,   301,   227,   190,    28,    28,    28,    78,    28,
      74,   297,   310,   233,   438,   292,    28,   365,   366,   367,
     395,    28,    44,   242,   277,   411,   288,     2,    28,   454,
     301,   139,   303,   138,   301,    48,   400,   332,    28,    28,
     290,   405,   267,   211,   302,    24,   333,    50,    25,   137,
      54,    57,    60,   289,    28,   278,   279,    70,   207,    71,
     303,    66,    28,    25,   435,    28,    73,    72,    98,    96,
      74,    53,    75,    15,   300,    63,   208,   307,   232,    81,
     214,    82,    76,   309,   319,    83,   444,   203,    53,    56,
     421,   422,    53,   280,   281,   201,   138,   431,   215,    46,
     195,    46,   291,   432,   453,   387,    94,   373,   388,   139,
     432,    53,   389,   323,   206,   324,    99,   324,    61,    62,
     386,    17,    18,    19,    20,    21,    22,    23,    24,   269,
     270,    78,   292,   196,    93,   271,   186,   426,   185,    52,
      28,   427,   211,   211,   211,   211,   211,   211,   211,   211,
     216,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   437,   237,   446,   223,   389,    63,   427,   219,
     226,     2,   194,   220,   138,   224,   236,   274,   275,   276,
      63,    69,    25,   300,   370,   371,   372,    81,   225,    82,
     300,   397,    63,    83,    56,    25,   445,   251,   252,   434,
     240,   398,   228,   449,    28,   374,   375,   376,   377,   451,
     272,   273,   282,   283,   246,   211,   211,    15,   415,   292,
     247,   418,   455,   368,   369,   378,   379,   245,  -208,   248,
     457,  -209,    28,   249,   250,   253,   284,   285,   286,   287,
     312,   313,    93,   295,   450,    28,   311,    52,   463,   464,
     314,   315,     2,   328,   331,   342,   346,    28,   343,   344,
     351,   363,   399,     2,   406,    17,    18,    19,    20,    21,
      22,    23,    24,   322,   412,   413,   290,   329,   330,    63,
     300,   338,   339,   414,     1,   419,     2,   420,   424,    56,
      25,   425,     3,   433,   347,   443,   447,   448,    15,     4,
     352,   355,   301,   362,    63,   456,   211,     5,   458,    15,
       6,     7,    28,   404,   462,   459,     8,     9,    10,    11,
     465,   308,    12,    51,   357,    13,   390,   305,   430,    14,
     436,   393,    15,    16,   192,   442,   318,   244,   392,   416,
     417,   408,   385,   350,    28,   410,    17,    18,    19,    20,
      21,    22,    23,    24,   423,   381,   362,    17,    18,    19,
      20,    21,    22,    23,    24,   380,   383,     0,   364,    28,
      56,   382,     0,   403,   384,     0,   355,   409,     0,     0,
      17,    18,    19,    20,    21,    22,    23,    24,     0,     0,
       0,     0,     0,     0,     2,   102,     0,   103,     0,     0,
       0,     0,   104,   105,   106,    25,     0,   107,     0,   108,
       0,   362,     0,   109,     0,     0,     0,     0,     0,     0,
     110,   111,     0,     0,     0,     0,     0,     0,     0,   112,
       0,   113,   114,   115,   116,   117,     0,     0,   118,     0,
      15,     0,   119,   120,   121,     0,     0,     0,     0,     0,
       0,     0,   439,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,     2,     0,    78,   122,   123,     0,
       0,     0,     2,     0,   124,   125,     0,   290,     0,     0,
     452,   126,   265,   127,     0,   362,     0,     0,    17,    18,
      19,    20,    21,    22,    23,   128,   129,   130,     0,   131,
     132,   133,   134,   135,     0,     0,     2,   102,     0,   103,
      15,     0,     0,   136,   104,   105,   106,     0,    15,   107,
       0,   108,     0,     0,     0,   109,     0,     0,     0,     0,
       0,     0,   110,   111,     0,     0,     0,     0,     0,     0,
       0,   112,     0,   113,   114,   115,   116,   117,     0,     0,
     118,     0,    15,     0,   119,   120,   121,     0,    17,    18,
      19,    20,    21,    22,    23,    24,    17,    18,    19,    20,
      21,    22,    23,    24,     0,     0,     0,     0,    78,   243,
     123,     0,     0,     0,     0,     0,   124,   125,     0,     0,
       0,     0,     0,   126,     0,   127,     0,     0,     0,     0,
      17,    18,    19,    20,    21,    22,    23,   128,   129,   130,
       0,   131,   132,   133,   134,   135,     0,     0,     2,   102,
       0,   103,     0,     0,     0,   136,   104,   105,   106,     0,
       0,     0,     0,   108,     0,     0,     0,   109,     0,     0,
       0,     0,     0,     0,   110,   111,     0,     0,     0,     0,
       0,     0,     0,   112,     0,   113,   114,   115,   116,   117,
       2,     0,   118,     0,    15,     0,   119,   120,   121,     0,
       0,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   110,   111,     0,     0,
      78,     0,   123,     0,     0,     0,     0,   113,   124,   125,
     116,     0,     2,     0,     0,   126,    15,   127,     0,   120,
     121,     0,    17,    18,    19,    20,    21,    22,    23,   128,
     129,   130,     0,   131,   132,   133,   134,   135,   110,   111,
       0,     0,     0,     0,   123,     0,     0,   136,     0,   113,
     124,   125,   116,     0,     2,     0,     0,   126,    15,   127,
       0,   120,   121,     0,    17,    18,    19,    20,    21,    22,
      23,    24,   129,   130,     0,   131,   132,   133,   134,   135,
     110,   111,     0,     0,     0,     0,   123,     0,     0,   317,
       0,   113,   124,   125,   116,     0,     2,     0,     0,   126,
      15,   127,     0,   120,   121,     0,    17,    18,    19,    20,
      21,    22,    23,    24,   129,   130,     0,   131,   132,   133,
     134,   135,   110,   111,     0,     0,     0,     0,   123,     0,
       0,   222,     0,   113,   124,   125,   116,     0,     2,     0,
       0,   126,    15,   127,     0,   120,   121,     0,    17,    18,
      19,    20,    21,    22,    23,    24,   129,   130,     0,   131,
     132,   133,   134,   135,   110,   111,     0,     0,   358,   359,
     123,     0,     0,   401,     0,   113,   124,   125,   116,     0,
       2,     0,     0,   126,    15,   127,     0,   120,   121,     0,
      17,    18,    19,    20,    21,    22,    23,    24,   129,   130,
       0,   131,   132,   133,   134,   135,   110,   111,     0,     0,
     358,   429,   123,     0,     0,     0,     0,   113,   124,   125,
     116,     0,     2,     0,     0,   126,    15,   127,     0,   120,
     121,     0,    17,    18,    19,    20,    21,    22,    23,    24,
     129,   130,     0,   131,   132,   133,   134,   135,   110,   111,
       0,     0,     0,     0,   123,   353,     0,     0,     0,   113,
     124,   125,   116,     0,     2,     0,     0,   126,    15,   127,
       0,   120,   121,     0,    17,    18,    19,    20,    21,    22,
      23,    24,   129,   130,     0,   131,   132,   133,   134,   135,
     110,   111,     0,     0,   358,     0,   123,     0,     0,     0,
       0,   113,   124,   125,   116,     0,     2,     0,     0,   126,
      15,   127,     0,   120,   121,     0,    17,    18,    19,    20,
      21,    22,    23,    24,   129,   130,     0,   131,   132,   133,
     134,   135,   110,   111,     0,     0,     0,     0,   123,   407,
       0,     0,     0,   113,   124,   125,   116,     0,     2,     0,
       0,   126,    15,   127,     0,   120,   121,     0,    17,    18,
      19,    20,    21,    22,    23,    24,   129,   130,     0,   131,
     132,   133,   134,   135,   110,   111,     0,     0,     0,     0,
     123,   440,     0,     0,     0,   113,   124,   125,   116,     0,
       2,     0,     0,   126,    15,   127,     0,   120,   121,     0,
      17,    18,    19,    20,    21,    22,    23,    24,   129,   130,
       0,   131,   132,   133,   134,   135,   110,   111,     0,     0,
       0,     0,   123,     0,     0,     0,     0,   113,   124,   125,
     116,     0,     2,     0,     0,   126,    15,   127,     0,   120,
     121,     0,    17,    18,    19,    20,    21,    22,    23,    24,
     129,   130,     0,   131,   132,   133,   134,   135,   110,   111,
       0,     0,     0,     0,   229,     0,     0,     0,     0,   113,
     124,   125,   116,     0,     0,     0,     0,   126,    15,   127,
       0,     0,     0,     0,    17,    18,    19,    20,    21,    22,
      23,    24,   129,   130,     0,   131,   132,   133,   134,   135,
       0,     0,     0,     0,     0,     0,   229,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   126,
       0,   127,     0,     0,     0,     0,    17,    18,    19,    20,
      21,    22,    23,    24,   129,   130,     0,   131,   132,   133,
     134,   135,     1,     0,     2,     0,     0,     0,     0,     0,
       3,     0,     0,     0,     0,     0,     0,     4,     0,     1,
       0,     2,     0,     0,     0,     0,     0,     3,     6,     7,
       0,     0,     0,     0,     4,     9,    10,    11,     0,     0,
      77,     0,     0,    13,     0,     6,     7,    14,     0,     0,
      15,    16,     9,    10,    11,     0,     0,    77,     0,     0,
      13,     0,     0,     0,    14,     0,     0,    15,    16,     0,
       0,     0,     0,     0,     0,     0,    78,    79,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,   193,     0,     0,     0,    17,    18,
      19,    20,    21,    22,    23,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,    18,    19,    20,    21,
      22,    23,    80,     1,     0,     2,     0,     0,     0,     0,
       0,     3,     0,     0,     0,     0,     0,     0,     4,     0,
       1,     0,     2,     0,     0,     0,     0,     0,     3,     6,
       7,     0,     0,     0,     0,     4,     9,    10,    11,     0,
       0,    77,     0,     0,    13,     0,     6,     7,    14,     0,
       0,    15,    16,     9,    10,    11,     0,     0,    77,     0,
       0,    13,     0,     0,     0,    14,     0,     0,    15,    16,
       0,     0,     0,     0,     0,     0,     0,    78,   356,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    78,   428,     0,     0,     0,    17,
      18,    19,    20,    21,    22,    23,    80,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    17,    18,    19,    20,
      21,    22,    23,    80,     1,     0,     2,     0,     0,     0,
       0,     0,     3,     0,     0,     0,     0,     0,     0,     4,
       0,     1,     0,     2,     0,     0,     0,     5,     0,     3,
       6,     7,     0,     0,     0,     0,     4,     9,    10,    11,
       0,     0,    12,     0,     0,    13,     0,     6,     7,    14,
       0,     0,    15,    16,     9,    10,    11,     0,     0,    12,
       0,     0,    13,     0,     0,     0,    14,     0,     0,    15,
      16,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      17,    18,    19,    20,    21,    22,    23,    24,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    17,    18,    19,
      20,    21,    22,    23,    24,     1,     0,     2,     0,     0,
       0,     0,     0,     3,     0,     0,     0,     0,     0,     0,
       4,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     6,     7,     0,     0,     0,     0,     0,     9,    10,
      11,     0,     0,    12,     0,     0,    13,     0,     0,     0,
      14,     0,     0,    15,    16,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    17,    18,    19,    20,    21,    22,    23,    80
};

static const short int yycheck[] =
{
       0,    61,   103,    61,    81,     5,   106,    61,     8,    84,
     303,   219,    25,   137,   189,    94,    66,   192,    78,    98,
      17,    77,    65,    83,    84,    11,    84,   298,   170,    65,
      84,   221,    32,    33,   305,    35,    79,    37,    81,    40,
      40,   106,   232,   233,    47,    31,    79,   107,    81,    99,
      50,    51,    52,    84,    54,    37,    61,    87,    40,    45,
     110,    61,    65,   106,     0,     0,    66,   191,   124,    80,
      52,    84,    77,    73,    77,    65,   106,    65,    78,    84,
     123,   141,    83,    83,    84,    90,   103,   123,    47,    79,
     123,    81,    35,   124,   218,   106,    96,    32,    33,    99,
      35,    83,    37,   120,   121,    40,    84,   107,    51,   106,
     110,    84,    65,   118,   191,    50,    51,    52,    77,    54,
     106,   124,   201,   123,   395,   185,    61,   269,   270,   271,
     305,    66,     8,   123,    28,   325,    64,     5,    73,   432,
      65,   141,    95,    78,    65,   124,   124,    10,    83,    84,
      18,   124,   169,   170,    79,   106,    19,    32,   124,   219,
      35,    37,    38,    91,    99,    59,    60,    43,   106,    45,
      95,    17,   107,   124,    95,   110,    51,    65,    67,    25,
     106,    33,    58,    51,   189,   185,   124,   192,   123,   249,
     106,   249,   106,   198,   402,   249,   404,   197,    50,   123,
     342,   343,    54,    97,    98,    94,   141,    78,   124,    65,
      86,    65,    80,    84,    78,   292,   106,   277,    80,   219,
      84,    73,    84,    79,   100,    81,    84,    81,    77,    78,
     290,    99,   100,   101,   102,   103,   104,   105,   106,    87,
      88,    77,   302,   124,   249,    93,   106,    80,    79,   249,
     185,    84,   269,   270,   271,   272,   273,   274,   275,   276,
      83,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,    80,    83,    80,   112,    84,   277,    84,    79,
     117,     5,   357,    79,   219,    79,   123,    56,    57,    58,
     290,   123,   124,   298,   274,   275,   276,   357,    79,   357,
     305,   306,   302,   357,   123,   124,   406,    54,    55,   386,
     123,   311,    79,   413,   249,   278,   279,   280,   281,   419,
      85,    86,    61,    62,   123,   342,   343,    51,   333,   389,
      81,   336,   433,   272,   273,   282,   283,   124,    79,    79,
     440,    79,   277,    77,    77,   123,    89,    96,    90,    63,
     124,    83,   357,    84,   414,   290,    84,   357,   458,   459,
     124,    53,     5,   124,   124,    80,    11,   302,    80,    80,
     106,   106,    79,     5,    80,    99,   100,   101,   102,   103,
     104,   105,   106,   220,    80,    80,    18,   224,   225,   389,
     395,   228,   229,    79,     3,    80,     5,    80,    82,   123,
     124,    82,    11,    83,   241,   124,    82,   412,    51,    18,
     247,   248,    65,   250,   414,    80,   433,    26,    80,    51,
      29,    30,   357,    84,   124,   116,    35,    36,    37,    38,
      80,   197,    41,    32,   249,    44,   295,   191,   358,    48,
     389,   302,    51,    52,    83,   402,   219,   141,    80,   334,
     334,   323,   289,   242,   389,   325,    99,   100,   101,   102,
     103,   104,   105,   106,   344,   285,   303,    99,   100,   101,
     102,   103,   104,   105,   106,   284,   287,    -1,   266,   414,
     123,   286,    -1,   320,   288,    -1,   323,   324,    -1,    -1,
      99,   100,   101,   102,   103,   104,   105,   106,    -1,    -1,
      -1,    -1,    -1,    -1,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    13,    14,    15,   124,    -1,    18,    -1,    20,
      -1,   358,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      -1,    42,    43,    44,    45,    46,    -1,    -1,    49,    -1,
      51,    -1,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   399,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,     5,    -1,    77,    78,    79,    -1,
      -1,    -1,     5,    -1,    85,    86,    -1,    18,    -1,    -1,
     427,    92,    95,    94,    -1,   432,    -1,    -1,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,    -1,   110,
     111,   112,   113,   114,    -1,    -1,     5,     6,    -1,     8,
      51,    -1,    -1,   124,    13,    14,    15,    -1,    51,    18,
      -1,    20,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    42,    43,    44,    45,    46,    -1,    -1,
      49,    -1,    51,    -1,    53,    54,    55,    -1,    99,   100,
     101,   102,   103,   104,   105,   106,    99,   100,   101,   102,
     103,   104,   105,   106,    -1,    -1,    -1,    -1,    77,    78,
      79,    -1,    -1,    -1,    -1,    -1,    85,    86,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    94,    -1,    -1,    -1,    -1,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,   110,   111,   112,   113,   114,    -1,    -1,     5,     6,
      -1,     8,    -1,    -1,    -1,   124,    13,    14,    15,    -1,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    42,    43,    44,    45,    46,
       5,    -1,    49,    -1,    51,    -1,    53,    54,    55,    -1,
      -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,
      77,    -1,    79,    -1,    -1,    -1,    -1,    42,    85,    86,
      45,    -1,     5,    -1,    -1,    92,    51,    94,    -1,    54,
      55,    -1,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,    -1,   110,   111,   112,   113,   114,    31,    32,
      -1,    -1,    -1,    -1,    79,    -1,    -1,   124,    -1,    42,
      85,    86,    45,    -1,     5,    -1,    -1,    92,    51,    94,
      -1,    54,    55,    -1,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,    -1,   110,   111,   112,   113,   114,
      31,    32,    -1,    -1,    -1,    -1,    79,    -1,    -1,   124,
      -1,    42,    85,    86,    45,    -1,     5,    -1,    -1,    92,
      51,    94,    -1,    54,    55,    -1,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    -1,   110,   111,   112,
     113,   114,    31,    32,    -1,    -1,    -1,    -1,    79,    -1,
      -1,   124,    -1,    42,    85,    86,    45,    -1,     5,    -1,
      -1,    92,    51,    94,    -1,    54,    55,    -1,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,    -1,   110,
     111,   112,   113,   114,    31,    32,    -1,    -1,    77,    78,
      79,    -1,    -1,   124,    -1,    42,    85,    86,    45,    -1,
       5,    -1,    -1,    92,    51,    94,    -1,    54,    55,    -1,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,   110,   111,   112,   113,   114,    31,    32,    -1,    -1,
      77,    78,    79,    -1,    -1,    -1,    -1,    42,    85,    86,
      45,    -1,     5,    -1,    -1,    92,    51,    94,    -1,    54,
      55,    -1,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,    -1,   110,   111,   112,   113,   114,    31,    32,
      -1,    -1,    -1,    -1,    79,    80,    -1,    -1,    -1,    42,
      85,    86,    45,    -1,     5,    -1,    -1,    92,    51,    94,
      -1,    54,    55,    -1,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,    -1,   110,   111,   112,   113,   114,
      31,    32,    -1,    -1,    77,    -1,    79,    -1,    -1,    -1,
      -1,    42,    85,    86,    45,    -1,     5,    -1,    -1,    92,
      51,    94,    -1,    54,    55,    -1,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    -1,   110,   111,   112,
     113,   114,    31,    32,    -1,    -1,    -1,    -1,    79,    80,
      -1,    -1,    -1,    42,    85,    86,    45,    -1,     5,    -1,
      -1,    92,    51,    94,    -1,    54,    55,    -1,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,    -1,   110,
     111,   112,   113,   114,    31,    32,    -1,    -1,    -1,    -1,
      79,    80,    -1,    -1,    -1,    42,    85,    86,    45,    -1,
       5,    -1,    -1,    92,    51,    94,    -1,    54,    55,    -1,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,   110,   111,   112,   113,   114,    31,    32,    -1,    -1,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    42,    85,    86,
      45,    -1,     5,    -1,    -1,    92,    51,    94,    -1,    54,
      55,    -1,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,    -1,   110,   111,   112,   113,   114,    31,    32,
      -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,    42,
      85,    86,    45,    -1,    -1,    -1,    -1,    92,    51,    94,
      -1,    -1,    -1,    -1,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,    -1,   110,   111,   112,   113,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      -1,    94,    -1,    -1,    -1,    -1,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    -1,   110,   111,   112,
     113,   114,     3,    -1,     5,    -1,    -1,    -1,    -1,    -1,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,     3,
      -1,     5,    -1,    -1,    -1,    -1,    -1,    11,    29,    30,
      -1,    -1,    -1,    -1,    18,    36,    37,    38,    -1,    -1,
      41,    -1,    -1,    44,    -1,    29,    30,    48,    -1,    -1,
      51,    52,    36,    37,    38,    -1,    -1,    41,    -1,    -1,
      44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    78,    -1,    -1,    -1,    99,   100,
     101,   102,   103,   104,   105,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    99,   100,   101,   102,   103,
     104,   105,   106,     3,    -1,     5,    -1,    -1,    -1,    -1,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
       3,    -1,     5,    -1,    -1,    -1,    -1,    -1,    11,    29,
      30,    -1,    -1,    -1,    -1,    18,    36,    37,    38,    -1,
      -1,    41,    -1,    -1,    44,    -1,    29,    30,    48,    -1,
      -1,    51,    52,    36,    37,    38,    -1,    -1,    41,    -1,
      -1,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    78,    -1,    -1,    -1,    99,
     100,   101,   102,   103,   104,   105,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,   102,
     103,   104,   105,   106,     3,    -1,     5,    -1,    -1,    -1,
      -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      -1,     3,    -1,     5,    -1,    -1,    -1,    26,    -1,    11,
      29,    30,    -1,    -1,    -1,    -1,    18,    36,    37,    38,
      -1,    -1,    41,    -1,    -1,    44,    -1,    29,    30,    48,
      -1,    -1,    51,    52,    36,    37,    38,    -1,    -1,    41,
      -1,    -1,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      99,   100,   101,   102,   103,   104,   105,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,
     102,   103,   104,   105,   106,     3,    -1,     5,    -1,    -1,
      -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    -1,    -1,    41,    -1,    -1,    44,    -1,    -1,    -1,
      48,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,   100,   101,   102,   103,   104,   105,   106
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     3,     5,    11,    18,    26,    29,    30,    35,    36,
      37,    38,    41,    44,    48,    51,    52,    99,   100,   101,
     102,   103,   104,   105,   106,   124,   128,   129,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   140,   132,   140,    65,   203,   124,     0,
     136,   138,   140,   137,   136,   139,   123,   132,   140,   145,
     132,    77,    78,   140,   144,   145,    17,   106,   166,   123,
     132,   132,    65,   136,   106,   132,   106,    41,    77,    78,
     106,   128,   141,   143,   147,   148,   149,   150,   155,   162,
     163,   164,   165,   167,   106,   129,    25,   146,   166,    84,
      87,   167,     6,     8,    13,    14,    15,    18,    20,    24,
      31,    32,    40,    42,    43,    44,    45,    46,    49,    53,
      54,    55,    78,    79,    85,    86,    92,    94,   106,   107,
     108,   110,   111,   112,   113,   114,   124,   128,   131,   140,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     181,   182,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   197,   198,   199,   200,   204,   205,   206,   207,   208,
     209,   210,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   226,    79,   106,   151,   152,   156,
     159,   128,   163,    78,   148,   132,   124,    47,   160,   167,
     146,   166,   130,   140,   146,   129,   132,   106,   124,   131,
     140,   206,   223,   227,   106,   124,    83,   171,   128,    79,
      79,   129,   124,   226,    79,    79,   226,   167,    79,    79,
     206,   206,   131,   140,   211,   212,   226,    83,   151,   159,
     123,    81,   123,    78,   169,   124,   123,    81,    79,    77,
      77,    54,    55,   123,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    95,   225,   206,   210,    87,
      88,    93,    85,    86,    56,    57,    58,    28,    59,    60,
      97,    98,    61,    62,    89,    96,    90,    63,    64,    91,
      18,    80,   128,   157,   158,    84,    65,   124,   160,   161,
     167,    65,    79,    95,   151,   156,   160,   167,   130,   167,
     146,    84,   124,    83,   124,    53,   151,   124,   170,   174,
     177,   180,   226,    79,    81,   201,   202,   203,   124,   226,
     226,   124,    10,    19,   183,   184,   185,   186,   226,   226,
     203,   203,    80,    80,    80,   124,    11,   226,    11,    45,
     198,   106,   226,    80,   196,   226,    78,   147,    77,    78,
     153,   154,   226,   106,   224,   210,   210,   210,   213,   213,
     214,   214,   214,   128,   215,   215,   215,   215,   216,   216,
     217,   218,   219,   220,   221,   226,   128,   159,    80,    84,
     152,   161,    80,   157,   153,   160,   161,   167,   140,    79,
     124,   124,   178,   226,    84,   124,    80,    80,   196,   226,
     202,   203,    80,    80,    79,   167,   184,   186,   167,    80,
      80,   210,   210,   207,    82,    82,    80,    84,    78,    78,
     154,    78,    84,    83,   159,    95,   158,    80,   161,   226,
      80,   179,   180,   124,   174,   171,    80,    82,   167,   171,
     128,   171,   226,    78,   153,   223,    80,   171,    80,   116,
      80,   106,   124,   171,   171,    80
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)								\
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (0)
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
              (Loc).first_line, (Loc).first_column,	\
              (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr,					\
                  Type, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      size_t yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

#endif /* YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);


# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()
    ;
#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a look-ahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to look-ahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 96 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "TypeSpecifier 1\n"; ;}
    break;

  case 3:
#line 97 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "TypeSpecifier 2\n"; ;}
    break;

  case 4:
#line 101 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "TypeName 1\n"; ;}
    break;

  case 5:
#line 102 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "TypeName 2\n"; ;}
    break;

  case 6:
#line 106 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ClassNameList\n"; ;}
    break;

  case 8:
#line 111 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "PrimitiveType BOOLEAN\n"; ;}
    break;

  case 9:
#line 112 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "PrimitiveType CHAR\n"; ;}
    break;

  case 10:
#line 113 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "PrimitiveType BYTE\n"; ;}
    break;

  case 11:
#line 114 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "PrimitiveType SHORT\n"; ;}
    break;

  case 12:
#line 115 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "PrimitiveType INT\n"; ;}
    break;

  case 13:
#line 116 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "PrimitiveType LONG\n"; ;}
    break;

  case 14:
#line 117 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "PrimitiveType FLOAT\n"; ;}
    break;

  case 15:
#line 118 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "PrimitiveType DOUBLE\n"; ;}
    break;

  case 16:
#line 119 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "PrimitiveType VOID\n"; ;}
    break;

  case 17:
#line 123 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "SemiColons\n"; ;}
    break;

  case 19:
#line 128 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    {
					cout <<"-----------\nTHE END !\n";
					YYABORT;
				  ;}
    break;

  case 20:
#line 134 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ProgramFile 1 \n"; ;}
    break;

  case 21:
#line 135 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ProgramFile 2 \n"; ;}
    break;

  case 22:
#line 136 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ProgramFile 3 \n"; ;}
    break;

  case 23:
#line 137 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ProgramFile 4 \n"; ;}
    break;

  case 24:
#line 138 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ProgramFile 5 \n"; ;}
    break;

  case 25:
#line 139 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ProgramFile 6 \n"; ;}
    break;

  case 26:
#line 140 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    {err->errQ->enqueue((yyvsp[0].r.myLineNo),(yyvsp[0].r.myColNo),"Error :Missing \'Package Statement \'", "" );;}
    break;

  case 28:
#line 145 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "PackageStatement\n"; ;}
    break;

  case 29:
#line 146 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    {err->errQ->enqueue((yyvsp[0].r.myLineNo),(yyvsp[0].r.myColNo),"Error :Missing \';\'", "" );;}
    break;

  case 30:
#line 147 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    {err->errQ->enqueue((yyvsp[0].r.myLineNo),(yyvsp[0].r.myColNo),"Error :Expected <identifier>", "" );;}
    break;

  case 31:
#line 148 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    {err->errQ->enqueue((yyvsp[0].r.myLineNo),(yyvsp[0].r.myColNo),"Error :Expected <identifier>;", "" );;}
    break;

  case 32:
#line 149 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    {err->errQ->enqueue((yyvsp[0].r.myLineNo),(yyvsp[0].r.myColNo),"Error :Expected packageStatment1", "" );;}
    break;

  case 33:
#line 150 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    {err->errQ->enqueue((yyvsp[0].r.myLineNo),(yyvsp[0].r.myColNo),"Error :Expected packageStatment2", "" );;}
    break;

  case 34:
#line 151 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    {err->errQ->enqueue((yyvsp[-1].r.myLineNo),(yyvsp[-1].r.myColNo),"Error :Expected package put givin", (yyvsp[-2].r.str));;}
    break;

  case 35:
#line 156 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "TypeDeclarations\n"; ;}
    break;

  case 37:
#line 161 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "TypeDeclarationOptSemi\n"; ;}
    break;

  case 39:
#line 166 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ImportStatements\n"; ;}
    break;

  case 41:
#line 171 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ImportStatement 1\n"; ;}
    break;

  case 42:
#line 172 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ImportStatement 2\n"; ;}
    break;

  case 43:
#line 177 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "QualifiedName\n"; ;}
    break;

  case 45:
#line 182 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "TypeDeclaration 1\n"; (yyval.type) = p->finishTypeDeclaration((yyvsp[-3].type)); ;}
    break;

  case 46:
#line 183 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "TypeDeclaration 2\n"; (yyval.type) = p->finishTypeDeclaration((yyvsp[-2].type)); ;}
    break;

  case 47:
#line 184 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { 
														err->errQ->enqueue((yyvsp[0].r.myLineNo),(yyvsp[0].r.myColNo),"Error :expected \'{\'", "" );
														(yyval.type) = p->finishTypeDeclaration((yyvsp[-1].type));
													;}
    break;

  case 48:
#line 188 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { 
														err->errQ->enqueue((yyvsp[0].r.myLineNo),(yyvsp[0].r.myColNo),"Error :expected \'}\'", "" );
														(yyval.type) = p->finishTypeDeclaration((yyvsp[-1].type));
													;}
    break;

  case 49:
#line 192 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { 
														err->errQ->enqueue((yyvsp[0].r.myLineNo),(yyvsp[0].r.myColNo),"Error :expected \'{}\'", "" );
														(yyval.type) = p->finishTypeDeclaration((yyvsp[0].type));
													;}
    break;

  case 50:
#line 199 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { 
															(yyval.type) = p->createType((yyvsp[-2].r.str), yylval.r.myLineNo, yylval.r.myColNo);
															cout << "ClassHeader 1\n"; 
														;}
    break;

  case 51:
#line 203 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { 
															(yyval.type) = p->createType((yyvsp[-1].r.str), yylval.r.myLineNo, yylval.r.myColNo);
															cout << "ClassHeader 2\n"; 
														;}
    break;

  case 52:
#line 207 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { 
															(yyval.type) = p->createType((yyvsp[-1].r.str), yylval.r.myLineNo, yylval.r.myColNo);
															cout << "ClassHeader 3\n"; 
														;}
    break;

  case 53:
#line 211 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { 
															(yyval.type) = p->createType((yyvsp[-2].r.str), yylval.r.myLineNo, yylval.r.myColNo);
															cout << "ClassHeader 4\n"; 
														;}
    break;

  case 54:
#line 215 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { 
															(yyval.type) = p->createType((yyvsp[0].r.str), yylval.r.myLineNo, yylval.r.myColNo);
															cout << "ClassHeader 5\n"; 
														;}
    break;

  case 55:
#line 219 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { 
															err->errQ->enqueue((yyvsp[-2].r.myLineNo),(yyvsp[-2].r.myColNo),"Error :expected \'Modifier\' put givin ",(yyvsp[-2].r.str));
															(yyval.type) = p->createType((yyvsp[0].r.str), yylval.r.myLineNo, yylval.r.myColNo);
														;}
    break;

  case 56:
#line 223 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { 
															(yyval.type) = p->createType((yyvsp[-1].r.str), yylval.r.myLineNo, yylval.r.myColNo);
															cout << "ClassHeader 6\n"; 
														;}
    break;

  case 57:
#line 227 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { 
															(yyval.type) = p->createType((yyvsp[-1].r.str), yylval.r.myLineNo, yylval.r.myColNo);
															cout << "ClassHeader 7\n"; 
														;}
    break;

  case 58:
#line 231 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { 
															(yyval.type) = p->createType((yyvsp[0].r.str), yylval.r.myLineNo, yylval.r.myColNo);
															cout << "ClassHeader 8\n"; 
														;}
    break;

  case 59:
#line 235 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { 
															err->errQ->enqueue((yyvsp[-1].r.myLineNo),(yyvsp[-1].r.myColNo),"Error :expected <identifier> 1","" );
															(yyval.type) = p->createType("undefined", yylval.r.myLineNo, yylval.r.myColNo);
														;}
    break;

  case 60:
#line 239 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { 
															err->errQ->enqueue((yyvsp[0].r.myLineNo),(yyvsp[0].r.myColNo),"Error :expected <identifier> 2","" );
															(yyval.type) = p->createType("undefined", yylval.r.myLineNo, yylval.r.myColNo);
														;}
    break;

  case 61:
#line 243 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { 
															err->errQ->enqueue((yyvsp[0].r.myLineNo),(yyvsp[0].r.myColNo),"illegal start class","" );
															(yyval.type) = p->createType("undefined", yylval.r.myLineNo, yylval.r.myColNo);
														;}
    break;

  case 62:
#line 250 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "Modifiers\n"; ;}
    break;

  case 64:
#line 255 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "Modifier ABSTRACT\n"; ;}
    break;

  case 65:
#line 256 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "Modifier FINAL\n"; ;}
    break;

  case 66:
#line 257 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "Modifier PUBLIC\n"; ;}
    break;

  case 67:
#line 258 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "Modifier PROTECTED\n"; ;}
    break;

  case 68:
#line 259 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "Modifier PRIVATE\n"; ;}
    break;

  case 69:
#line 260 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "Modifier STATIC\n"; ;}
    break;

  case 70:
#line 261 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "Modifier TRANSIENT\n"; ;}
    break;

  case 71:
#line 262 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "Modifier VOLATILE\n"; ;}
    break;

  case 72:
#line 263 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "Modifier NATIVE\n"; ;}
    break;

  case 73:
#line 264 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "Modifier SYNCHRONIZED\n"; ;}
    break;

  case 74:
#line 268 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ClassWord CLASS\n"; ;}
    break;

  case 75:
#line 269 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ClassWord INTERFACE\n"; ;}
    break;

  case 76:
#line 270 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { err->errQ->enqueue((yyvsp[0].r.myLineNo),(yyvsp[0].r.myColNo),"Error :expected \'class\'", (yyvsp[0].r.str));;}
    break;

  case 77:
#line 274 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "Interfaces\n"; ;}
    break;

  case 78:
#line 275 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { err->errQ->enqueue((yyvsp[0].r.myLineNo),(yyvsp[0].r.myColNo),"Error :illegal start of type", "");;}
    break;

  case 79:
#line 279 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "FieldDeclarations\n"; ;}
    break;

  case 81:
#line 284 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "FieldDeclarationOptSemi\n"; ;}
    break;

  case 83:
#line 289 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "FieldDeclaration 1\n"; ;}
    break;

  case 84:
#line 290 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "FieldDeclaration 2\n"; ;}
    break;

  case 85:
#line 291 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "FieldDeclaration 3\n"; ;}
    break;

  case 86:
#line 292 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "FieldDeclaration 4\n"; ;}
    break;

  case 87:
#line 293 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "FieldDeclaration 5\n"; ;}
    break;

  case 88:
#line 294 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "FieldDeclaration 6\n"; ;}
    break;

  case 89:
#line 298 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "FieldVariableDeclaration 1\n"; ;}
    break;

  case 90:
#line 299 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { 
														(yyval.variable)=p->insertVar((yyvsp[0].r.str), yylval.r.myLineNo, yylval.r.myColNo);
														cout << "FieldVariableDeclaration 2\n";
													;}
    break;

  case 91:
#line 306 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "VariableDeclarators\n"; ;}
    break;

  case 93:
#line 311 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "VariableDeclarator 1\n"; ;}
    break;

  case 94:
#line 312 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "VariableDeclarator 2\n"; ;}
    break;

  case 95:
#line 316 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "VariableInitializer 1\n"; ;}
    break;

  case 96:
#line 317 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "VariableInitializer 2\n"; ;}
    break;

  case 97:
#line 318 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "VariableInitializer 3\n"; ;}
    break;

  case 98:
#line 322 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ArrayInitializers 1\n"; ;}
    break;

  case 99:
#line 323 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ArrayInitializers 2\n"; ;}
    break;

  case 100:
#line 324 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ArrayInitializers 3\n"; ;}
    break;

  case 101:
#line 328 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "MethodDeclaration 1\n"; ;}
    break;

  case 102:
#line 329 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "MethodDeclaration 2\n"; ;}
    break;

  case 103:
#line 330 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "MethodDeclaration 3\n"; ;}
    break;

  case 104:
#line 331 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "MethodDeclaration 4\n"; ;}
    break;

  case 105:
#line 335 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "MethodDeclarator 1\n"; ;}
    break;

  case 106:
#line 336 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "MethodDeclarator 2\n"; ;}
    break;

  case 107:
#line 337 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "MethodDeclarator 3\n"; ;}
    break;

  case 108:
#line 341 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ParameterList\n"; ;}
    break;

  case 110:
#line 346 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "Parameter 1\n"; ;}
    break;

  case 111:
#line 347 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "Parameter heheheh \n"; ;}
    break;

  case 112:
#line 348 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "Parameter 2\n"; ;}
    break;

  case 113:
#line 352 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "DeclaratorName 1\n"; ;}
    break;

  case 114:
#line 353 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "DeclaratorName 2\n"; ;}
    break;

  case 115:
#line 357 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "Throws\n"; ;}
    break;

  case 116:
#line 361 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "MethodBody 1\n"; ;}
    break;

  case 117:
#line 362 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "MethodBody 2\n"; ;}
    break;

  case 118:
#line 366 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ConstructorDeclaration 1\n"; ;}
    break;

  case 119:
#line 367 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ConstructorDeclaration 2\n"; ;}
    break;

  case 120:
#line 368 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ConstructorDeclaration 3\n"; ;}
    break;

  case 121:
#line 369 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ConstructorDeclaration 4\n"; ;}
    break;

  case 122:
#line 373 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ConstructorDeclarator 1\n"; ;}
    break;

  case 123:
#line 374 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ConstructorDeclarator 2\n"; ;}
    break;

  case 124:
#line 378 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "StaticInitializer\n"; ;}
    break;

  case 125:
#line 382 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "NonStaticInitializer\n"; ;}
    break;

  case 126:
#line 386 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "Extends 1\n"; ;}
    break;

  case 127:
#line 387 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "Extends 2\n"; ;}
    break;

  case 128:
#line 388 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { err->errQ->enqueue((yyvsp[0].r.myLineNo),(yyvsp[0].r.myColNo),"Error :illegal start of type ", "");;}
    break;

  case 129:
#line 392 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "Block 1\n"; ;}
    break;

  case 130:
#line 393 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "Block 2\n"; ;}
    break;

  case 131:
#line 397 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "LocalVariableDeclarationsAndStatements\n"; ;}
    break;

  case 133:
#line 402 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "LocalVariableDeclarationOrStatement 1\n"; ;}
    break;

  case 134:
#line 403 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "LocalVariableDeclarationOrStatement 2\n"; ;}
    break;

  case 135:
#line 407 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "LocalVariableDeclarationStatement 1\n"; ;}
    break;

  case 136:
#line 408 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "LocalVariableDeclarationStatement 2\n"; ;}
    break;

  case 137:
#line 412 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "Statement 1\n"; ;}
    break;

  case 138:
#line 413 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "Statement 2\n"; ;}
    break;

  case 139:
#line 414 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "Statement 3\n"; ;}
    break;

  case 140:
#line 415 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "Statement 4\n"; ;}
    break;

  case 141:
#line 416 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "Statement 5\n"; ;}
    break;

  case 142:
#line 417 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "Statement 6\n"; ;}
    break;

  case 143:
#line 418 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "Statement 7\n"; ;}
    break;

  case 144:
#line 419 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "Statement 8\n"; ;}
    break;

  case 145:
#line 423 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "EmptyStatement 8\n"; ;}
    break;

  case 146:
#line 427 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "LabelStatement 1\n"; ;}
    break;

  case 147:
#line 428 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "LabelStatement 2\n"; ;}
    break;

  case 148:
#line 429 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "LabelStatement 3\n"; ;}
    break;

  case 149:
#line 433 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ExpressionStatement\n"; ;}
    break;

  case 150:
#line 437 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "SelectionStatement 1\n"; ;}
    break;

  case 151:
#line 438 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "SelectionStatement 2\n"; ;}
    break;

  case 152:
#line 439 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "SelectionStatement 3\n"; ;}
    break;

  case 153:
#line 443 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "IterationStatement 1\n"; ;}
    break;

  case 154:
#line 444 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "IterationStatement 2\n"; ;}
    break;

  case 155:
#line 445 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "IterationStatement 3\n"; ;}
    break;

  case 156:
#line 446 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "IterationStatement 4\n"; ;}
    break;

  case 157:
#line 450 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ForInit 1\n"; ;}
    break;

  case 158:
#line 451 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ForInit 2\n"; ;}
    break;

  case 159:
#line 452 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ForInit 3\n"; ;}
    break;

  case 160:
#line 456 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ForExpr 1\n"; ;}
    break;

  case 161:
#line 457 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ForExpr 2\n"; ;}
    break;

  case 162:
#line 461 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ForIncr\n"; ;}
    break;

  case 163:
#line 465 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ExpressionStatements\n"; ;}
    break;

  case 165:
#line 470 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "JumpStatement 1\n"; ;}
    break;

  case 166:
#line 471 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "JumpStatement 2\n"; ;}
    break;

  case 167:
#line 472 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "JumpStatement 3\n"; ;}
    break;

  case 168:
#line 473 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "JumpStatement 4\n"; ;}
    break;

  case 169:
#line 474 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "JumpStatement 5\n"; ;}
    break;

  case 170:
#line 475 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "JumpStatement 6\n"; ;}
    break;

  case 171:
#line 476 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "JumpStatement 7\n"; ;}
    break;

  case 172:
#line 480 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "GuardingStatement 1\n"; ;}
    break;

  case 173:
#line 481 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "GuardingStatement 2\n"; ;}
    break;

  case 174:
#line 482 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "GuardingStatement 3\n"; ;}
    break;

  case 175:
#line 483 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "GuardingStatement 4\n"; ;}
    break;

  case 176:
#line 487 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "Catches\n"; ;}
    break;

  case 178:
#line 492 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "Catch\n"; ;}
    break;

  case 179:
#line 496 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "CatchHeader 1\n"; ;}
    break;

  case 180:
#line 497 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "CatchHeader 2\n"; ;}
    break;

  case 181:
#line 501 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "Finally\n"; ;}
    break;

  case 182:
#line 505 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "PrimaryExpression 1\n"; ;}
    break;

  case 183:
#line 506 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "PrimaryExpression 2\n"; ;}
    break;

  case 184:
#line 510 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "NotJustName 1\n"; ;}
    break;

  case 185:
#line 511 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "NotJustName 2\n"; ;}
    break;

  case 186:
#line 512 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "NotJustName 3\n"; ;}
    break;

  case 187:
#line 516 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ComplexPrimary 1\n"; ;}
    break;

  case 188:
#line 517 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ComplexPrimary 2\n"; ;}
    break;

  case 189:
#line 521 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ComplexPrimaryNoParenthesis 1\n"; ;}
    break;

  case 190:
#line 522 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ComplexPrimaryNoParenthesis INTEGER_VALUE\n"; ;}
    break;

  case 191:
#line 523 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ComplexPrimaryNoParenthesis FLOAT_VALUE\n"; ;}
    break;

  case 192:
#line 524 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ComplexPrimaryNoParenthesis CAHR_VALUE\n"; ;}
    break;

  case 193:
#line 525 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ComplexPrimaryNoParenthesis LONG_VALUE\n"; ;}
    break;

  case 194:
#line 526 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ComplexPrimaryNoParenthesis STRING_VALUE\n"; ;}
    break;

  case 195:
#line 527 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ComplexPrimaryNoParenthesis 2\n"; ;}
    break;

  case 196:
#line 528 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ComplexPrimaryNoParenthesis 3\n"; ;}
    break;

  case 197:
#line 529 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ComplexPrimaryNoParenthesis 4\n"; ;}
    break;

  case 198:
#line 530 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ComplexPrimaryNoParenthesis 5\n"; ;}
    break;

  case 199:
#line 534 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ArrayAccess 1\n"; ;}
    break;

  case 200:
#line 535 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ArrayAccess 2\n"; ;}
    break;

  case 201:
#line 539 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "FieldAccess 1\n"; ;}
    break;

  case 202:
#line 540 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "FieldAccess 2\n"; ;}
    break;

  case 203:
#line 541 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "FieldAccess 3\n"; ;}
    break;

  case 204:
#line 542 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "FieldAccess 4\n"; ;}
    break;

  case 205:
#line 543 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "FieldAccess 5\n"; ;}
    break;

  case 206:
#line 547 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "MethodCall 1\n"; ;}
    break;

  case 207:
#line 548 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "MethodCall 2\n"; ;}
    break;

  case 208:
#line 552 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "MethodAccess 1\n"; ;}
    break;

  case 209:
#line 553 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "MethodAccess 2\n"; ;}
    break;

  case 210:
#line 554 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "MethodAccess 3\n"; ;}
    break;

  case 211:
#line 558 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "SpecialName THIS\n"; ;}
    break;

  case 212:
#line 559 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "SpecialName SUPER\n"; ;}
    break;

  case 213:
#line 560 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "SpecialName JNULL\n"; ;}
    break;

  case 214:
#line 564 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ArgumentList 1\n"; ;}
    break;

  case 215:
#line 565 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ArgumentList 2\n"; ;}
    break;

  case 216:
#line 569 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "NewAllocationExpression 1\n"; ;}
    break;

  case 217:
#line 570 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "NewAllocationExpression 2\n"; ;}
    break;

  case 218:
#line 574 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "PlainNewAllocationExpression 1\n"; ;}
    break;

  case 219:
#line 575 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "PlainNewAllocationExpression 2\n"; ;}
    break;

  case 220:
#line 576 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "PlainNewAllocationExpression 3\n"; ;}
    break;

  case 221:
#line 577 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "PlainNewAllocationExpression 4\n"; ;}
    break;

  case 222:
#line 578 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "PlainNewAllocationExpression 5\n"; ;}
    break;

  case 223:
#line 579 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "PlainNewAllocationExpression 6\n"; ;}
    break;

  case 224:
#line 583 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ClassAllocationExpression 1\n"; ;}
    break;

  case 225:
#line 584 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ClassAllocationExpression 2\n"; ;}
    break;

  case 226:
#line 588 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ArrayAllocationExpression 1\n"; ;}
    break;

  case 227:
#line 589 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ArrayAllocationExpression 2\n"; ;}
    break;

  case 228:
#line 590 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ArrayAllocationExpression 3\n"; ;}
    break;

  case 229:
#line 594 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "DimExprs 1\n"; ;}
    break;

  case 230:
#line 595 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "DimExprs 2\n"; ;}
    break;

  case 231:
#line 599 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "DimExpr\n"; ;}
    break;

  case 232:
#line 603 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "Dims\n"; ;}
    break;

  case 234:
#line 608 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "PostfixExpression 1\n"; ;}
    break;

  case 235:
#line 609 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "PostfixExpression 2\n"; ;}
    break;

  case 236:
#line 613 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "RealPostfixExpression 1\n"; ;}
    break;

  case 237:
#line 614 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "RealPostfixExpression 2\n"; ;}
    break;

  case 238:
#line 618 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "UnaryExpression 1\n"; ;}
    break;

  case 239:
#line 619 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "UnaryExpression 2\n"; ;}
    break;

  case 240:
#line 620 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "UnaryExpression 3\n"; ;}
    break;

  case 241:
#line 621 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "UnaryExpression 4\n"; ;}
    break;

  case 242:
#line 625 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "LogicalUnaryExpression 1\n"; ;}
    break;

  case 243:
#line 626 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "LogicalUnaryExpression 2\n"; ;}
    break;

  case 244:
#line 630 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "LogicalUnaryOperator DURA\n"; ;}
    break;

  case 245:
#line 631 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "LogicalUnaryOperator EXC_MARK\n"; ;}
    break;

  case 246:
#line 635 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ArithmeticUnaryOperator PLUS\n"; ;}
    break;

  case 247:
#line 636 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ArithmeticUnaryOperator MINUS\n"; ;}
    break;

  case 248:
#line 640 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "CastExpression 1\n"; ;}
    break;

  case 249:
#line 641 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "CastExpression 2\n"; ;}
    break;

  case 250:
#line 642 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "CastExpression 3\n"; ;}
    break;

  case 251:
#line 643 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "CastExpression 4\n"; ;}
    break;

  case 252:
#line 647 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "PrimitiveTypeExpression 1\n"; ;}
    break;

  case 253:
#line 648 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "PrimitiveTypeExpression 2\n"; ;}
    break;

  case 254:
#line 652 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ClassTypeExpression\n"; ;}
    break;

  case 255:
#line 656 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "MultiplicativeExpression 1\n"; ;}
    break;

  case 256:
#line 657 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "MultiplicativeExpression 2\n"; ;}
    break;

  case 257:
#line 658 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "MultiplicativeExpression 3\n"; ;}
    break;

  case 258:
#line 659 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "MultiplicativeExpression 4\n"; ;}
    break;

  case 259:
#line 663 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "AdditiveExpression 1\n"; ;}
    break;

  case 260:
#line 664 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "AdditiveExpression 2\n"; ;}
    break;

  case 261:
#line 665 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "AdditiveExpression 3\n"; ;}
    break;

  case 262:
#line 669 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ShiftExpression 1\n"; ;}
    break;

  case 263:
#line 670 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ShiftExpression 2\n"; ;}
    break;

  case 264:
#line 671 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ShiftExpression 3\n"; ;}
    break;

  case 265:
#line 672 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ShiftExpression 4\n"; ;}
    break;

  case 266:
#line 676 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "RelationalExpression 1\n"; ;}
    break;

  case 267:
#line 677 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "RelationalExpression 2\n"; ;}
    break;

  case 268:
#line 678 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "RelationalExpression 3\n"; ;}
    break;

  case 269:
#line 679 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "RelationalExpression 4\n"; ;}
    break;

  case 270:
#line 680 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "RelationalExpression 5\n"; ;}
    break;

  case 271:
#line 681 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "RelationalExpression 6\n"; ;}
    break;

  case 272:
#line 685 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "EqualityExpression 1\n"; ;}
    break;

  case 273:
#line 686 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "EqualityExpression 2\n"; ;}
    break;

  case 274:
#line 687 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "EqualityExpression 3\n"; ;}
    break;

  case 275:
#line 691 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "AndExpression 1\n"; ;}
    break;

  case 276:
#line 692 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "AndExpression 2\n"; ;}
    break;

  case 277:
#line 696 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ExclusiveOrExpression 1\n"; ;}
    break;

  case 278:
#line 697 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ExclusiveOrExpression 2\n"; ;}
    break;

  case 279:
#line 701 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "InclusiveOrExpression 1\n"; ;}
    break;

  case 280:
#line 702 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "InclusiveOrExpression 2\n"; ;}
    break;

  case 281:
#line 706 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ConditionalAndExpression 1\n"; ;}
    break;

  case 282:
#line 707 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ConditionalAndExpression 2\n"; ;}
    break;

  case 283:
#line 711 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ConditionalOrExpression 1\n"; ;}
    break;

  case 284:
#line 712 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ConditionalOrExpression 2\n"; ;}
    break;

  case 285:
#line 716 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ConditionalExpression 1\n"; ;}
    break;

  case 286:
#line 717 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ConditionalExpression 2\n"; ;}
    break;

  case 287:
#line 721 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "AssignmentExpression 1\n"; ;}
    break;

  case 288:
#line 722 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "AssignmentExpression 2\n"; ;}
    break;

  case 289:
#line 852 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "AssignmentOperator ASSIGN\n"; ;}
    break;

  case 290:
#line 853 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "AssignmentOperator ASS_MUL\n"; ;}
    break;

  case 291:
#line 854 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "AssignmentOperator ASS_DIV\n"; ;}
    break;

  case 292:
#line 855 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "AssignmentOperator ASS_MOD\n"; ;}
    break;

  case 293:
#line 856 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "AssignmentOperator ASS_ADD\n"; ;}
    break;

  case 294:
#line 857 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "AssignmentOperator ASS_SUB\n"; ;}
    break;

  case 295:
#line 858 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "AssignmentOperator ASS_SHL\n"; ;}
    break;

  case 296:
#line 859 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "AssignmentOperator ASS_SHR\n"; ;}
    break;

  case 297:
#line 860 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "AssignmentOperator ASS_SHRR\n"; ;}
    break;

  case 298:
#line 861 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "AssignmentOperator ASS_AND\n"; ;}
    break;

  case 299:
#line 862 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "AssignmentOperator ASS_XOR\n"; ;}
    break;

  case 300:
#line 863 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "AssignmentOperator ASS_OR\n"; ;}
    break;

  case 301:
#line 867 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "Expression\n"; ;}
    break;

  case 302:
#line 871 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "ConstantExpression\n"; ;}
    break;


      default: break;
    }

/* Line 1126 of yacc.c.  */
#line 3641 "yacc.cpp"

  yyvsp -= yylen;
  yyssp -= yylen;


  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  int yytype = YYTRANSLATE (yychar);
	  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
	  YYSIZE_T yysize = yysize0;
	  YYSIZE_T yysize1;
	  int yysize_overflow = 0;
	  char *yymsg = 0;
#	  define YYERROR_VERBOSE_ARGS_MAXIMUM 5
	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
	  int yyx;

#if 0
	  /* This is so xgettext sees the translatable formats that are
	     constructed on the fly.  */
	  YY_("syntax error, unexpected %s");
	  YY_("syntax error, unexpected %s, expecting %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
#endif
	  char *yyfmt;
	  char const *yyf;
	  static char const yyunexpected[] = "syntax error, unexpected %s";
	  static char const yyexpecting[] = ", expecting %s";
	  static char const yyor[] = " or %s";
	  char yyformat[sizeof yyunexpected
			+ sizeof yyexpecting - 1
			+ ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
			   * (sizeof yyor - 1))];
	  char const *yyprefix = yyexpecting;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 1;

	  yyarg[0] = yytname[yytype];
	  yyfmt = yystpcpy (yyformat, yyunexpected);

	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
		  {
		    yycount = 1;
		    yysize = yysize0;
		    yyformat[sizeof yyunexpected - 1] = '\0';
		    break;
		  }
		yyarg[yycount++] = yytname[yyx];
		yysize1 = yysize + yytnamerr (0, yytname[yyx]);
		yysize_overflow |= yysize1 < yysize;
		yysize = yysize1;
		yyfmt = yystpcpy (yyfmt, yyprefix);
		yyprefix = yyor;
	      }

	  yyf = YY_(yyformat);
	  yysize1 = yysize + yystrlen (yyf);
	  yysize_overflow |= yysize1 < yysize;
	  yysize = yysize1;

	  if (!yysize_overflow && yysize <= YYSTACK_ALLOC_MAXIMUM)
	    yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg)
	    {
	      /* Avoid sprintf, as that infringes on the user's name space.
		 Don't have undefined behavior even if the translation
		 produced a string with the wrong number of "%s"s.  */
	      char *yyp = yymsg;
	      int yyi = 0;
	      while ((*yyp = *yyf))
		{
		  if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		    {
		      yyp += yytnamerr (yyp, yyarg[yyi++]);
		      yyf += 2;
		    }
		  else
		    {
		      yyp++;
		      yyf++;
		    }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    {
	      yyerror (YY_("syntax error"));
	      goto yyexhaustedlab;
	    }
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror (YY_("syntax error"));
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
        }
      else
	{
	  yydestruct ("Error: discarding", yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (0)
     goto yyerrorlab;

yyvsp -= yylen;
  yyssp -= yylen;
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping", yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token. */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK;
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 874 "C:\\Users\\Dell-PC\\Documents\\Visual Studio 2013\\Projects\\JavaCompiler\\yacc.y"




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
	freopen("in.txt","r" ,stdin);
	freopen("out.txt","w" ,stdout);

	Parser* p = new Parser();
	p->parse();
	if(!err->errQ->isEmpty())						   
		err->printErrQueue();
}

