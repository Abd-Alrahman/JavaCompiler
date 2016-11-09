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




/* Copy the first part of user declarations.  */
#line 2 "C:\\Users\\Dell-PC\\documents\\visual studio 2013\\Projects\\JavaCompiler\\yacc.y"

	#include <iostream>
	using namespace std;
	#include <FlexLexer.h>
	int yylex(void);
	int yyparse();
	void yyerror(char *);
	
	FlexLexer* lexer = new yyFlexLexer();
	
	class Parser
	{
		public:
		int	parse()
		{
			return yyparse();
		}
	};
	


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
/* Line 196 of yacc.c.  */
#line 289 "yacc.cpp"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 219 of yacc.c.  */
#line 301 "yacc.cpp"

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
#define YYFINAL  30
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1887

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  111
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  101
/* YYNRULES -- Number of rules. */
#define YYNRULES  279
/* YYNRULES -- Number of states. */
#define YYNSTATES  448

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   341

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   100,     2,     2,     2,   104,   107,     2,
      94,    95,    90,   101,    87,   102,    89,   103,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    96,    88,
     105,    93,   106,   110,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    97,     2,    98,   108,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    91,   109,    92,    99,     2,     2,     2,
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
      85,    86
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    18,    20,
      22,    24,    26,    28,    30,    32,    34,    36,    38,    41,
      43,    47,    50,    53,    56,    58,    60,    62,    66,    68,
      71,    73,    76,    78,    81,    85,    91,    93,    97,   102,
     106,   112,   117,   122,   127,   131,   135,   139,   142,   144,
     147,   149,   151,   153,   155,   157,   159,   161,   163,   165,
     167,   169,   171,   174,   176,   179,   181,   184,   187,   189,
     191,   193,   195,   197,   201,   204,   206,   210,   212,   216,
     218,   221,   225,   227,   231,   234,   240,   245,   250,   254,
     259,   263,   266,   268,   272,   275,   279,   281,   284,   287,
     289,   291,   296,   300,   304,   307,   312,   316,   319,   321,
     324,   328,   332,   335,   337,   340,   342,   344,   348,   353,
     355,   357,   360,   362,   364,   366,   368,   370,   372,   375,
     379,   382,   384,   390,   398,   404,   410,   418,   426,   433,
     436,   438,   440,   443,   445,   447,   449,   453,   457,   460,
     464,   467,   471,   474,   478,   484,   488,   492,   497,   499,
     502,   505,   511,   516,   519,   521,   523,   525,   527,   529,
     533,   535,   537,   539,   541,   543,   545,   550,   555,   559,
     563,   567,   571,   575,   580,   584,   586,   588,   590,   592,
     594,   596,   598,   602,   604,   608,   610,   612,   616,   620,
     625,   630,   636,   641,   646,   650,   654,   656,   659,   663,
     665,   668,   670,   672,   675,   678,   681,   684,   687,   689,
     691,   694,   696,   698,   700,   702,   704,   709,   714,   719,
     721,   724,   727,   729,   733,   737,   741,   743,   747,   751,
     753,   757,   761,   765,   767,   771,   775,   779,   783,   787,
     789,   793,   797,   799,   803,   805,   809,   811,   815,   817,
     821,   823,   827,   829,   835,   837,   841,   843,   845,   847,
     849,   851,   853,   855,   857,   859,   861,   863,   865,   867
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short int yyrhs[] =
{
     117,     0,    -1,   113,    -1,   113,   187,    -1,   115,    -1,
     124,    -1,   124,    -1,   114,    87,   124,    -1,     4,    -1,
      11,    -1,     6,    -1,    45,    -1,    31,    -1,    33,    -1,
      21,    -1,    17,    -1,    56,    -1,    88,    -1,   116,    88,
      -1,   118,    -1,   119,   122,   120,    -1,   119,   122,    -1,
     119,   120,    -1,   122,   120,    -1,   119,    -1,   122,    -1,
     120,    -1,    39,   124,   116,    -1,   121,    -1,   120,   121,
      -1,   125,    -1,   125,   116,    -1,   123,    -1,   122,   123,
      -1,    28,   124,   116,    -1,    28,   124,    89,    90,   116,
      -1,    82,    -1,   124,    89,    82,    -1,   126,    91,   131,
      92,    -1,   126,    91,    92,    -1,   127,   129,    82,   150,
     130,    -1,   127,   129,    82,   150,    -1,   127,   129,    82,
     130,    -1,   129,    82,   150,   130,    -1,   127,   129,    82,
      -1,   129,    82,   150,    -1,   129,    82,   130,    -1,   129,
      82,    -1,   128,    -1,   127,   128,    -1,     3,    -1,    19,
      -1,    42,    -1,    41,    -1,    40,    -1,    46,    -1,    53,
      -1,    57,    -1,    34,    -1,    49,    -1,    12,    -1,    32,
      -1,    27,   114,    -1,   132,    -1,   131,   132,    -1,   133,
      -1,   133,   116,    -1,   134,    88,    -1,   139,    -1,   146,
      -1,   148,    -1,   149,    -1,   125,    -1,   127,   112,   135,
      -1,   112,   135,    -1,   136,    -1,   135,    87,   136,    -1,
     143,    -1,   143,    93,   137,    -1,   210,    -1,    91,    92,
      -1,    91,   138,    92,    -1,   137,    -1,   138,    87,   137,
      -1,   138,    87,    -1,   127,   112,   140,   144,   145,    -1,
     127,   112,   140,   145,    -1,   112,   140,   144,   145,    -1,
     112,   140,   145,    -1,   143,    94,   141,    95,    -1,   143,
      94,    95,    -1,   140,    70,    -1,   142,    -1,   141,    87,
     142,    -1,   112,   143,    -1,    19,   112,   143,    -1,    82,
      -1,   143,    70,    -1,    52,   114,    -1,   151,    -1,    88,
      -1,   127,   147,   144,   151,    -1,   127,   147,   151,    -1,
     147,   144,   151,    -1,   147,   151,    -1,    82,    94,   141,
      95,    -1,    82,    94,    95,    -1,    46,   151,    -1,   151,
      -1,    18,   113,    -1,   150,    87,   113,    -1,    91,   152,
      92,    -1,    91,    92,    -1,   153,    -1,   152,   153,    -1,
     154,    -1,   155,    -1,   112,   135,    88,    -1,    19,   112,
     135,    88,    -1,   156,    -1,   157,    -1,   158,    88,    -1,
     159,    -1,   160,    -1,   165,    -1,   166,    -1,   151,    -1,
      88,    -1,    82,    96,    -1,     8,   211,    96,    -1,    15,
      96,    -1,   210,    -1,    26,    94,   210,    95,   155,    -1,
      26,    94,   210,    95,   155,    86,   155,    -1,    48,    94,
     210,    95,   151,    -1,    58,    94,   210,    95,   155,    -1,
      16,   155,    58,    94,   210,    95,    88,    -1,    22,    94,
     161,   162,   163,    95,   155,    -1,    22,    94,   161,   162,
      95,   155,    -1,   164,    88,    -1,   154,    -1,    88,    -1,
     210,    88,    -1,    88,    -1,   164,    -1,   158,    -1,   164,
      87,   158,    -1,     5,    82,    88,    -1,     5,    88,    -1,
      14,    82,    88,    -1,    14,    88,    -1,    44,   210,    88,
      -1,    44,    88,    -1,    51,   210,    88,    -1,    49,    94,
     210,    95,   155,    -1,    54,   151,   170,    -1,    54,   151,
     167,    -1,    54,   151,   167,   170,    -1,   168,    -1,   167,
     168,    -1,   169,   151,    -1,    10,    94,   112,    82,    95,
      -1,    10,    94,   112,    95,    -1,    20,   151,    -1,   124,
      -1,   172,    -1,   179,    -1,   181,    -1,   173,    -1,    94,
     210,    95,    -1,   174,    -1,    83,    -1,    84,    -1,   175,
      -1,   176,    -1,   177,    -1,   124,    97,   210,    98,    -1,
     173,    97,   210,    98,    -1,   172,    89,    82,    -1,   189,
      89,    82,    -1,   124,    89,    50,    -1,   124,    89,    12,
      -1,   115,    89,    12,    -1,   178,    94,   180,    95,    -1,
     178,    94,    95,    -1,   174,    -1,   179,    -1,   124,    -1,
      50,    -1,    47,    -1,    36,    -1,   210,    -1,   180,    87,
     210,    -1,   182,    -1,   124,    89,   182,    -1,   184,    -1,
     183,    -1,   184,    91,    92,    -1,   183,    91,    92,    -1,
     184,    91,   138,    92,    -1,   183,    91,   131,    92,    -1,
      35,   113,    94,   180,    95,    -1,    35,   113,    94,    95,
      -1,    35,   113,   185,   187,    -1,    35,   113,   185,    -1,
      35,   113,   187,    -1,   186,    -1,   185,   186,    -1,    97,
     210,    98,    -1,    70,    -1,   187,    70,    -1,   171,    -1,
     189,    -1,   188,    59,    -1,   188,    60,    -1,    59,   190,
      -1,    60,   190,    -1,   193,   194,    -1,   191,    -1,   188,
      -1,   192,   190,    -1,    99,    -1,   100,    -1,   101,    -1,
     102,    -1,   190,    -1,    94,   195,    95,   194,    -1,    94,
     196,    95,   194,    -1,    94,   210,    95,   191,    -1,   115,
      -1,   115,   187,    -1,   124,   187,    -1,   194,    -1,   197,
      90,   194,    -1,   197,   103,   194,    -1,   197,   104,   194,
      -1,   197,    -1,   198,   101,   197,    -1,   198,   102,   197,
      -1,   198,    -1,   199,    61,   198,    -1,   199,    62,   198,
      -1,   199,    63,   198,    -1,   199,    -1,   200,   105,   199,
      -1,   200,   106,   199,    -1,   200,    65,   199,    -1,   200,
      64,   199,    -1,   200,    30,   112,    -1,   200,    -1,   201,
      66,   200,    -1,   201,    67,   200,    -1,   201,    -1,   202,
     107,   201,    -1,   202,    -1,   203,   108,   202,    -1,   203,
      -1,   204,   109,   203,    -1,   204,    -1,   205,    68,   204,
      -1,   205,    -1,   206,    69,   205,    -1,   206,    -1,   206,
     110,   210,    96,   207,    -1,   207,    -1,   190,   209,   208,
      -1,    93,    -1,    71,    -1,    72,    -1,    73,    -1,    74,
      -1,    75,    -1,    76,    -1,    77,    -1,    78,    -1,    79,
      -1,    80,    -1,    81,    -1,   208,    -1,   207,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,    69,    69,    70,    74,    75,    79,    80,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    96,    97,   101,
     105,   106,   107,   108,   109,   110,   111,   115,   119,   120,
     124,   125,   129,   130,   134,   135,   139,   140,   144,   145,
     149,   150,   151,   152,   153,   154,   155,   156,   160,   161,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     178,   179,   183,   187,   188,   192,   193,   197,   198,   199,
     200,   201,   202,   206,   207,   211,   212,   216,   217,   221,
     222,   223,   227,   228,   229,   233,   234,   235,   236,   240,
     241,   242,   246,   247,   251,   252,   256,   257,   261,   265,
     266,   270,   271,   272,   273,   277,   278,   282,   286,   290,
     291,   295,   296,   300,   301,   305,   306,   310,   311,   315,
     316,   317,   318,   319,   320,   321,   322,   326,   330,   331,
     332,   336,   340,   341,   342,   346,   347,   348,   349,   353,
     354,   355,   359,   360,   364,   368,   369,   373,   374,   375,
     376,   377,   378,   379,   383,   384,   385,   386,   390,   391,
     395,   399,   400,   404,   408,   409,   413,   414,   415,   419,
     420,   424,   425,   426,   427,   428,   432,   433,   437,   438,
     439,   440,   441,   445,   446,   450,   451,   452,   456,   457,
     458,   462,   463,   467,   468,   472,   473,   474,   475,   476,
     477,   481,   482,   486,   487,   488,   492,   493,   497,   501,
     502,   506,   507,   511,   512,   516,   517,   518,   519,   523,
     524,   528,   529,   533,   534,   538,   539,   540,   541,   545,
     546,   550,   554,   555,   556,   557,   561,   562,   563,   567,
     568,   569,   570,   574,   575,   576,   577,   578,   579,   583,
     584,   585,   589,   590,   594,   595,   599,   600,   604,   605,
     609,   610,   614,   615,   619,   620,   624,   625,   626,   627,
     628,   629,   630,   631,   632,   633,   634,   635,   639,   643
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ABSTRACT", "BOOLEAN", "BREAK", "BYTE",
  "BYVALUE", "CASE", "CAST", "CATCH", "CHAR", "CLASS", "CONST", "CONTINUE",
  "DEFAULT", "DO", "DOUBLE", "EXTENDS", "FINAL", "FINALLY", "FLOAT", "FOR",
  "FUTURE", "GENERIC", "GOTO", "IF", "IMPLEMENTS", "IMPORT", "INNER",
  "INSTANCEOF", "INT", "INTERFACE", "LONG", "NATIVE", "NEW", "JNULL",
  "OPERATOR", "OUTER", "PACKAGE", "PRIVATE", "PROTECTED", "PUBLIC", "REST",
  "RETURN", "SHORT", "STATIC", "SUPER", "SWITCH", "SYNCHRONIZED", "THIS",
  "THROW", "THROWS", "TRANSIENT", "TRY", "VAR", "VOID", "VOLATILE",
  "WHILE", "OP_INC", "OP_DEC", "OP_SHL", "OP_SHR", "OP_SHRR", "OP_GE",
  "OP_LE", "OP_EQ", "OP_NE", "OP_LAND", "OP_LOR", "OP_DIM", "ASS_MUL",
  "ASS_DIV", "ASS_MOD", "ASS_ADD", "ASS_SUB", "ASS_SHL", "ASS_SHR",
  "ASS_SHRR", "ASS_AND", "ASS_XOR", "ASS_OR", "IDENTIFIER", "LITERAL",
  "BOOLLIT", "e1", "ELSE", "','", "';'", "'.'", "'*'", "'{'", "'}'", "'='",
  "'('", "')'", "':'", "'['", "']'", "'~'", "'!'", "'+'", "'-'", "'/'",
  "'%'", "'<'", "'>'", "'&'", "'^'", "'|'", "'?'", "$accept",
  "TypeSpecifier", "TypeName", "ClassNameList", "PrimitiveType",
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
     335,   336,   337,   338,   339,   340,   341,    44,    59,    46,
      42,   123,   125,    61,    40,    41,    58,    91,    93,   126,
      33,    43,    45,    47,    37,    60,    62,    38,    94,   124,
      63
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,   111,   112,   112,   113,   113,   114,   114,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   116,   116,   117,
     118,   118,   118,   118,   118,   118,   118,   119,   120,   120,
     121,   121,   122,   122,   123,   123,   124,   124,   125,   125,
     126,   126,   126,   126,   126,   126,   126,   126,   127,   127,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     129,   129,   130,   131,   131,   132,   132,   133,   133,   133,
     133,   133,   133,   134,   134,   135,   135,   136,   136,   137,
     137,   137,   138,   138,   138,   139,   139,   139,   139,   140,
     140,   140,   141,   141,   142,   142,   143,   143,   144,   145,
     145,   146,   146,   146,   146,   147,   147,   148,   149,   150,
     150,   151,   151,   152,   152,   153,   153,   154,   154,   155,
     155,   155,   155,   155,   155,   155,   155,   156,   157,   157,
     157,   158,   159,   159,   159,   160,   160,   160,   160,   161,
     161,   161,   162,   162,   163,   164,   164,   165,   165,   165,
     165,   165,   165,   165,   166,   166,   166,   166,   167,   167,
     168,   169,   169,   170,   171,   171,   172,   172,   172,   173,
     173,   174,   174,   174,   174,   174,   175,   175,   176,   176,
     176,   176,   176,   177,   177,   178,   178,   178,   179,   179,
     179,   180,   180,   181,   181,   182,   182,   182,   182,   182,
     182,   183,   183,   184,   184,   184,   185,   185,   186,   187,
     187,   188,   188,   189,   189,   190,   190,   190,   190,   191,
     191,   192,   192,   193,   193,   194,   194,   194,   194,   195,
     195,   196,   197,   197,   197,   197,   198,   198,   198,   199,
     199,   199,   199,   200,   200,   200,   200,   200,   200,   201,
     201,   201,   202,   202,   203,   203,   204,   204,   205,   205,
     206,   206,   207,   207,   208,   208,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   210,   211
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       3,     2,     2,     2,     1,     1,     1,     3,     1,     2,
       1,     2,     1,     2,     3,     5,     1,     3,     4,     3,
       5,     4,     4,     4,     3,     3,     3,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     2,     1,     2,     2,     1,     1,
       1,     1,     1,     3,     2,     1,     3,     1,     3,     1,
       2,     3,     1,     3,     2,     5,     4,     4,     3,     4,
       3,     2,     1,     3,     2,     3,     1,     2,     2,     1,
       1,     4,     3,     3,     2,     4,     3,     2,     1,     2,
       3,     3,     2,     1,     2,     1,     1,     3,     4,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     2,     3,
       2,     1,     5,     7,     5,     5,     7,     7,     6,     2,
       1,     1,     2,     1,     1,     1,     3,     3,     2,     3,
       2,     3,     2,     3,     5,     3,     3,     4,     1,     2,
       2,     5,     4,     2,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     4,     4,     3,     3,
       3,     3,     3,     4,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     3,     1,     1,     3,     3,     4,
       4,     5,     4,     4,     3,     3,     1,     2,     3,     1,
       2,     1,     1,     2,     2,     2,     2,     2,     1,     1,
       2,     1,     1,     1,     1,     1,     4,     4,     4,     1,
       2,     2,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     3,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     5,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short int yydefact[] =
{
       0,    50,    60,    51,     0,    61,    58,     0,    54,    53,
      52,    55,    59,    56,    57,     0,    19,    24,    26,    28,
      25,    32,    30,     0,     0,    48,     0,    36,     0,     0,
       1,    22,    21,    29,    23,    33,    17,    31,     0,    49,
       0,    47,     0,    34,     0,    27,    20,    18,     8,    10,
       9,    15,    14,    12,    13,    11,    55,    16,    36,     0,
      39,     0,     2,     4,     5,    72,     0,     0,    63,    65,
       0,    68,    69,     0,    70,    71,   108,    44,     0,     0,
      46,    45,    37,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   190,     0,   189,     0,     0,
     188,     0,     0,     0,     0,     0,    36,   171,   172,   127,
     112,     0,   221,   222,   223,   224,     0,     4,   164,   126,
       0,   113,   115,   116,   119,   120,     0,   122,   123,   124,
     125,   211,   165,   168,   170,   173,   174,   175,     0,   166,
     167,   193,   196,   195,   219,   212,   225,   218,     0,     0,
     232,   236,   239,   243,   249,   252,   254,   256,   258,   260,
     262,   264,   278,   131,    96,    74,    75,     0,    77,   209,
       3,     0,     0,    38,    64,    66,    67,     0,     0,   104,
      42,    41,   109,    62,     6,     0,    43,    35,     0,   106,
       0,     0,    92,     0,   148,     0,   164,   225,   279,     0,
       0,   150,   130,     0,     0,     0,     0,     0,   152,     0,
       0,     0,     0,     0,     0,     0,   215,   216,   128,   229,
     164,     0,     0,     0,     0,    77,     0,     0,     0,   111,
     114,   121,     0,     0,     0,     0,     0,   213,   214,     0,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   266,     0,   220,   217,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    91,   100,     0,
      88,    99,    97,     0,     0,   210,    73,     0,     0,   102,
      98,   103,    40,     0,   110,     0,    94,     0,   105,   147,
     129,   149,     0,     0,   141,   140,   145,     0,     0,     0,
       0,     0,   204,   206,   205,   151,     0,     0,   153,     0,
       0,   156,   158,     0,   155,     0,     0,   230,   231,     0,
       0,   169,   117,   182,   181,   180,   194,     0,   178,     0,
     184,     0,   191,   198,     0,     0,   197,    82,     0,    79,
     179,   265,   233,   234,   235,   237,   238,   240,   241,   242,
     248,   247,   246,   244,   245,   250,   251,   253,   255,   257,
     259,   261,     0,    76,    87,    78,    90,     0,     0,    86,
     101,     7,    95,    93,     0,   118,   143,     0,     0,     0,
     139,     0,   202,     0,     0,   207,   203,     0,     0,     0,
     163,   159,   157,   160,     0,   169,   226,   227,   228,   176,
     177,     0,   183,   200,    80,     0,    84,   199,     0,    89,
      85,     0,     0,     0,   144,   142,   146,   132,   201,   208,
     134,   154,     0,   135,   192,    81,    83,   263,     0,   138,
       0,     0,     0,   162,   136,   137,   133,   161
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,    61,    62,   183,   195,    37,    15,    16,    17,    18,
      19,    20,    21,   196,    22,    23,    24,    25,    26,    80,
      67,    68,    69,    70,   165,   166,   347,   348,    71,   167,
     191,   192,   225,   178,   280,    72,    73,    74,    75,    81,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     307,   387,   423,   308,   129,   130,   321,   322,   323,   324,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   341,
     140,   141,   142,   143,   312,   313,   170,   144,   145,   146,
     147,   148,   149,   150,   221,   222,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   252,   163,
     199
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -271
static const short int yypact[] =
{
    1788,  -271,  -271,  -271,    -6,  -271,  -271,    -6,  -271,  -271,
    -271,  -271,  -271,  -271,  -271,   131,  -271,  1812,  1830,  -271,
    1812,  -271,    57,    56,  1830,  -271,    97,  -271,    24,    71,
    -271,  1830,  1812,  -271,  1830,  -271,  -271,    69,  1536,  -271,
     105,   100,    80,    69,   108,    69,  1830,  -271,  -271,  -271,
    -271,  -271,  -271,  -271,  -271,  -271,   106,  -271,   113,   372,
    -271,   110,   124,  -271,   129,  -271,  1756,  1591,  -271,    57,
     114,  -271,  -271,    -8,  -271,  -271,  -271,   100,   288,    -6,
    -271,    -2,  -271,    57,  -271,  1467,    94,  1320,    98,   139,
     570,   288,   143,   162,   288,  -271,   900,  -271,   164,   172,
    -271,  1320,   106,   173,  1380,  1380,   175,  -271,  -271,  -271,
    -271,  1320,  -271,  -271,  -271,  -271,   110,   183,    55,  -271,
     471,  -271,  -271,  -271,  -271,  -271,   185,  -271,  -271,  -271,
    -271,  -271,   186,   177,   184,  -271,  -271,  -271,   187,   201,
    -271,  -271,   170,   188,    83,   207,   368,  -271,  1380,  1320,
    -271,    64,   103,   171,    27,   133,   190,   192,   189,   233,
     -21,  -271,  -271,  -271,  -271,   215,  -271,    -9,     7,  -271,
     234,   110,    -8,  -271,  -271,    69,  -271,    -6,   106,  -271,
    -271,    -2,  -271,   219,   129,   288,  -271,    69,   288,  -271,
     110,    76,  -271,   220,  -271,   183,    75,  -271,  -271,   217,
     223,  -271,  -271,   256,   110,   656,  1320,   -47,  -271,   230,
    1320,  1320,   232,    86,  1320,  1320,  -271,  -271,  -271,    39,
      59,   227,   228,   229,   161,    47,   313,     6,  1320,  -271,
    -271,  -271,   244,  1320,   960,  1646,   716,  -271,  -271,   245,
    -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,
    -271,  -271,  1320,  -271,  -271,  1320,  1320,  1320,  1320,  1320,
    1320,  1320,  1320,   288,  1320,  1320,  1320,  1320,  1320,  1320,
    1320,  1320,  1320,  1320,  1320,  1320,   110,  -271,  -271,   -39,
    -271,  -271,  -271,  1035,  1505,  -271,   215,    -9,   106,  -271,
     219,  -271,  -271,    -6,  -271,   110,   258,   715,  -271,  -271,
    -271,  -271,   236,   165,  -271,  -271,  -271,  1110,   167,   237,
    1170,  1320,     0,  -271,   234,  -271,   241,   243,  -271,   248,
     106,    86,  -271,   106,  -271,   251,   252,   234,   234,  1320,
    1320,  1420,  -271,  -271,  -271,  -271,  -271,   250,  -271,   253,
    -271,    79,  -271,  -271,  1701,   808,  -271,  -271,   -14,  -271,
    -271,  -271,  -271,  -271,  -271,    64,    64,   103,   103,   103,
    -271,   171,   171,   171,   171,    27,    27,   133,   190,   192,
     189,   233,   235,  -271,  -271,  -271,  -271,    88,   -39,  -271,
    -271,   129,   258,  -271,  1320,  -271,  -271,  1245,   255,  1320,
    -271,   570,  -271,    90,   257,  -271,   234,   106,   570,   288,
    -271,  -271,  -271,  -271,   570,  -271,  -271,  -271,  -271,  -271,
    -271,  1320,  -271,  -271,  -271,   101,  1035,  -271,  1320,  -271,
    -271,   254,   570,   259,   263,  -271,  -271,   270,  -271,  -271,
    -271,  -271,    29,  -271,  -271,  -271,  -271,  -271,   269,  -271,
     570,   570,   264,  -271,  -271,  -271,  -271,  -271
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -271,   -54,   -70,   181,   -27,    25,  -271,  -271,  -271,    78,
      68,   322,    48,    -4,   -32,  -271,   -29,     3,     5,   -55,
     127,   -53,  -271,  -271,   -99,    87,  -270,    21,  -271,   196,
      84,    72,   -51,  -151,  -259,  -271,   305,  -271,  -271,   297,
     -37,  -271,   261,   174,   -88,  -271,  -271,  -198,  -271,  -271,
    -271,  -271,  -271,   -12,  -271,  -271,  -271,    61,  -271,    63,
    -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,    82,
    -271,   158,  -271,  -271,  -271,    85,  -174,  -271,  -271,   -45,
      65,  -271,  -271,  -134,  -271,  -271,     4,   -15,   -26,     8,
     120,   130,   128,   136,   132,  -271,   -83,   150,  -271,    54,
    -271
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -188
static const short int yytable[] =
{
      28,    76,   203,    29,   198,   116,    65,   306,   182,    66,
     168,    63,   171,   375,   174,   254,   279,   224,   334,    84,
     374,   288,   180,   169,   207,    79,   186,    39,   379,    40,
      76,   190,   117,   314,    64,    65,   179,   204,    66,    63,
      63,    94,   197,   177,   177,   327,   328,   310,   274,   278,
     311,    63,    59,    43,    45,   118,   335,   263,    63,   216,
     217,   277,    64,    64,    63,   213,   116,    63,    35,    39,
     169,    40,   286,   416,    64,   184,    27,   282,   417,   278,
      35,    64,    59,    59,   219,   185,    33,    64,    82,   275,
      64,   264,   265,   117,   175,    31,   319,   311,    34,    33,
     283,   284,    33,   253,   197,   303,   320,   220,   187,   169,
      46,   442,    36,    42,    33,   294,   118,   282,    78,   420,
     168,   352,   353,   354,   443,    -5,   292,    79,   226,   169,
     281,    30,   266,   267,   295,   289,   378,    -5,   396,   296,
     283,   291,   237,   238,   227,    36,   436,    38,   227,  -187,
     209,   116,   228,  -187,   255,   212,   228,    47,    63,    36,
      44,    63,    82,   297,   227,   223,   411,   256,   257,  -187,
      83,   298,   228,   184,   412,   297,   193,   411,   117,    41,
     200,    64,   194,   419,    64,   428,   201,    77,   416,   306,
      82,   426,   164,   435,   169,   406,   407,    59,    76,   268,
     269,   118,   176,    65,   258,   259,    66,    85,    63,   360,
     197,   197,   197,   197,   197,   197,   197,   197,    44,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     190,    64,   260,   261,   262,   202,    63,   205,   361,   362,
     363,   364,   281,   190,   382,   357,   358,   359,   276,   332,
     281,   380,   276,   385,   389,   390,   206,    63,   210,    64,
     309,   235,   355,   356,   316,   317,   211,   214,   325,   326,
      63,   218,   226,   231,   233,   232,   365,   366,  -185,   236,
      64,   234,   337,   400,   197,   197,   403,   339,   342,   381,
     349,   174,    48,    64,    49,  -186,   239,   270,   272,    50,
     271,   273,   276,   427,   285,    51,   293,    76,   299,    52,
     431,   301,    65,   300,   302,    66,   433,    63,   315,    53,
     318,    54,   329,   330,   331,   333,   338,   350,   282,   372,
     384,   418,   391,    55,   439,   437,   397,   349,   398,    32,
      64,   281,   399,   425,    57,   432,   404,   405,   409,   438,
     389,   410,   445,   446,   440,   429,   441,   444,   290,   447,
     430,   388,   344,   373,   342,   394,   415,   287,   377,   383,
      27,   172,    63,   197,   181,   424,    48,    86,    49,   305,
      87,   230,   401,    50,   402,   336,    88,    89,    90,    51,
     367,    91,   393,    52,    92,    64,   408,   395,    93,   349,
     369,   368,   351,    53,     0,    54,   371,    94,    95,   370,
       0,     0,     0,     0,     0,     0,    96,    55,     0,    97,
      98,    99,   100,   101,     0,     0,   102,     0,    57,     0,
     103,   104,   105,     0,     0,     0,     0,     0,   421,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
       0,     0,     0,     0,   106,   107,   108,     0,     0,     0,
     109,   251,     0,    59,   110,   434,   111,     0,     0,     0,
     349,   112,   113,   114,   115,    48,    86,    49,     0,    87,
       0,     0,    50,     0,     0,    88,    89,    90,    51,     0,
      91,     0,    52,    92,     0,     0,     0,    93,     0,     0,
       0,     0,    53,     0,    54,     0,    94,    95,     0,     0,
       0,     0,     0,     0,     0,    96,    55,     0,    97,    98,
      99,   100,   101,     0,     0,   102,     0,    57,     0,   103,
     104,   105,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   106,   107,   108,     0,     0,     0,   109,
       0,     0,    59,   229,     0,   111,     0,     0,     0,     0,
     112,   113,   114,   115,    48,    86,    49,     0,    87,     0,
       0,    50,     0,     0,    88,    89,    90,    51,     0,     0,
       0,    52,    92,     0,     0,     0,    93,     0,     0,     0,
       0,    53,     0,    54,     0,    94,    95,     0,     0,     0,
       0,     0,     0,     0,    96,    55,     0,    97,    98,    99,
     100,   101,     0,     0,   102,     0,    57,     0,   103,   104,
     105,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   106,   107,   108,     0,     0,     0,   109,     0,
      48,    59,    49,     0,   111,     0,     0,    50,     0,   112,
     113,   114,   115,    51,     0,    91,     0,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,     0,    54,
       0,    94,    95,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,    97,     0,     0,   100,     0,     0,     0,
       0,     0,    57,     0,     0,   104,   105,     0,     0,    48,
      48,    49,    49,     0,     0,     0,    50,    50,     0,     0,
       0,     0,    51,    51,   188,     0,    52,    52,    27,   107,
     108,     0,     0,     0,   304,     0,    53,    53,    54,    54,
     111,    94,    95,     0,     0,   112,   113,   114,   115,     0,
      55,    55,     0,    97,     0,     0,   100,     0,     0,     0,
       0,    57,    57,     0,     0,   104,   105,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,    27,   107,
     108,     0,     0,     0,     0,     0,     0,   345,   346,     0,
     111,     0,    48,     0,    49,   112,   113,   114,   115,    50,
       0,     0,     0,     0,     0,    51,     0,     0,     0,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
       0,    54,     0,    94,    95,     0,     0,     0,     0,     0,
       0,     0,     0,    55,     0,    97,     0,     0,   100,     0,
       0,     0,     0,     0,    57,     0,     0,   104,   105,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,   107,   108,     0,     0,     0,     0,     0,     0,   345,
     414,     0,   111,     0,    48,     0,    49,   112,   113,   114,
     115,    50,     0,     0,     0,     0,     0,    51,     0,     0,
       0,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,     0,    54,     0,    94,    95,     0,     0,     0,
       0,     0,     0,     0,     0,    55,     0,    97,     0,     0,
     100,     0,     0,     0,     0,     0,    57,     0,     0,   104,
     105,     0,     0,     0,    48,     0,    49,     0,     0,     0,
       0,    50,     0,     0,     0,     0,     0,    51,     0,     0,
       0,    52,    27,   107,   108,     0,     0,     0,   208,     0,
       0,    53,     0,    54,   111,    94,    95,     0,     0,   112,
     113,   114,   115,     0,     0,    55,     0,    97,     0,     0,
     100,     0,     0,     0,     0,     0,    57,     0,     0,   104,
     105,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
       0,    49,    27,   107,   108,     0,    50,     0,     0,     0,
       0,     0,    51,     0,   111,   340,    52,     0,     0,   112,
     113,   114,   115,     0,     0,     0,    53,     0,    54,     0,
      94,    95,     0,     0,     0,     0,     0,     0,     0,     0,
      55,     0,    97,     0,     0,   100,     0,     0,     0,     0,
       0,    57,     0,     0,   104,   105,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,     0,    49,    27,   107,   108,
       0,    50,     0,     0,     0,     0,   345,    51,     0,   111,
       0,    52,     0,     0,   112,   113,   114,   115,     0,     0,
       0,    53,     0,    54,     0,    94,    95,     0,     0,     0,
       0,     0,     0,     0,     0,    55,     0,    97,     0,     0,
     100,     0,     0,     0,     0,     0,    57,     0,     0,   104,
     105,     0,     0,     0,    48,     0,    49,     0,     0,     0,
       0,    50,     0,     0,     0,     0,     0,    51,     0,     0,
       0,    52,    27,   107,   108,     0,     0,     0,   386,     0,
       0,    53,     0,    54,   111,    94,    95,     0,     0,   112,
     113,   114,   115,     0,     0,    55,     0,    97,     0,     0,
     100,     0,     0,     0,     0,     0,    57,     0,     0,   104,
     105,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
       0,    49,    27,   107,   108,     0,    50,     0,     0,     0,
       0,     0,    51,     0,   111,   392,    52,     0,     0,   112,
     113,   114,   115,     0,     0,     0,    53,     0,    54,     0,
      94,    95,     0,     0,     0,     0,     0,     0,     0,     0,
      55,     0,    97,     0,     0,   100,     0,     0,     0,     0,
       0,    57,     0,     0,   104,   105,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,     0,    49,    27,   107,   108,
       0,    50,     0,     0,     0,     0,     0,    51,     0,   111,
     422,    52,     0,     0,   112,   113,   114,   115,     0,     0,
       0,    53,     0,    54,     0,    94,    95,     0,     0,     0,
       0,     0,     0,     0,     0,    55,     0,    97,     0,     0,
     100,     0,     0,     0,     0,     0,    57,     0,     0,   104,
     105,     0,     0,     0,    48,     0,    49,     0,     0,     0,
       0,    50,     0,     0,     0,     0,     0,    51,     0,     0,
       0,    52,    27,   107,   108,     0,     0,     0,     0,     0,
       0,    53,     0,    54,   111,    94,    95,     0,     0,   112,
     113,   114,   115,     0,    48,    55,    49,    97,     0,     0,
     100,    50,     0,     0,     0,     0,    57,    51,     0,   104,
     105,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,     0,    54,     0,    94,    95,     0,     0,     0,
       0,     0,    27,   107,   108,    55,     0,    97,     0,     0,
     100,    48,     0,    49,   215,     0,    57,     0,    50,   112,
     113,   114,   115,     0,    51,     0,   188,     0,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,     0,
      54,     0,    27,   107,   108,     0,     0,     0,     0,    48,
       0,    49,    55,     0,   215,     0,    50,     0,     0,   112,
     113,     0,    51,    57,   188,     0,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,     0,    54,     1,
      48,     0,    49,     0,     0,     0,     0,    50,     2,    27,
      55,     0,     0,    51,     0,     3,     0,    52,     0,     0,
       0,    57,   189,     0,     0,     0,     0,    53,     5,    54,
       6,     0,     0,     0,     0,     0,     8,     9,    10,     0,
       0,    55,    56,     0,     0,    12,     0,    27,     0,    13,
       0,     0,    57,    14,     1,    48,     0,    49,     0,     0,
     376,     0,    50,     2,     0,     0,     0,     0,    51,     0,
       3,     0,    52,     0,     0,     0,     0,     0,    58,     0,
       0,     0,    53,     5,    54,     6,     0,    59,    60,     0,
       0,     8,     9,    10,     0,     0,    55,    56,     0,     0,
      12,     0,     0,     0,    13,     0,     0,    57,    14,     1,
      48,     0,    49,     0,     0,     0,     0,    50,     2,     0,
       0,     0,     0,    51,     0,     3,     0,    52,     0,     0,
       0,     0,     0,    58,     0,     0,     0,    53,     5,    54,
       6,     0,    59,   173,     0,     0,     8,     9,    10,     0,
       0,    55,    56,     0,     0,    12,     0,     0,     0,    13,
       0,     0,    57,    14,     1,    48,     0,    49,     0,     0,
       0,     0,    50,     2,     0,     0,     0,     0,    51,     0,
       3,     0,    52,     0,     0,     0,     0,     0,    58,     0,
       0,     0,    53,     5,    54,     6,     0,    59,   343,     0,
       0,     8,     9,    10,     0,     0,    55,    56,     0,     0,
      12,     0,     0,     0,    13,     0,     0,    57,    14,     1,
      48,     0,    49,     0,     0,     0,     0,    50,     2,     0,
       0,     0,     0,    51,     0,     3,     0,    52,     0,     0,
       0,     0,     0,    58,     0,     0,     0,    53,     5,    54,
       6,     1,    59,   413,     0,     0,     8,     9,    10,     0,
       2,    55,    11,     0,     0,    12,     0,     3,     0,    13,
       0,     0,    57,    14,     0,     1,     4,     0,     0,     0,
       5,     0,     6,     0,     2,     0,     0,     7,     8,     9,
      10,     3,     0,     1,    11,     0,     0,    12,    58,     0,
       4,    13,     2,     0,     5,    14,     6,     0,     0,     3,
       0,     0,     8,     9,    10,     0,     0,     0,    11,     0,
       0,    12,     5,     0,     6,    13,     0,     0,     0,    14,
       8,     9,    10,     0,     0,     0,    11,     0,     0,    12,
       0,     0,     0,    13,     0,     0,     0,    14
};

static const short int yycheck[] =
{
       4,    38,    90,     7,    87,    59,    38,   205,    78,    38,
      61,    38,    66,   283,    67,   149,   167,   116,    12,    56,
     279,   172,    77,    70,    94,    27,    81,    24,   287,    24,
      67,    85,    59,   207,    38,    67,    73,    91,    67,    66,
      67,    35,    87,    52,    52,   219,   220,    94,    69,    88,
      97,    78,    91,    28,    29,    59,    50,    30,    85,   104,
     105,    70,    66,    67,    91,   102,   120,    94,    20,    66,
      70,    66,   171,    87,    78,    79,    82,    70,    92,    88,
      32,    85,    91,    91,   111,    87,    18,    91,    82,   110,
      94,    64,    65,   120,    69,    17,    10,    97,    20,    31,
      93,    94,    34,   148,   149,   204,    20,   111,    83,    70,
      32,    82,    88,    89,    46,   185,   120,    70,    18,   378,
     171,   255,   256,   257,    95,    70,   181,    27,    89,    70,
     167,     0,   105,   106,   188,   172,   287,    82,   312,   190,
      93,   178,    59,    60,    89,    88,   416,    91,    89,    94,
      96,   205,    97,    94,    90,   101,    97,    88,   185,    88,
      89,   188,    82,    87,    89,   111,    87,   103,   104,    94,
      90,    95,    97,   177,    95,    87,    82,    87,   205,    82,
      82,   185,    88,    95,   188,    95,    88,    82,    87,   387,
      82,   389,    82,    92,    70,   329,   330,    91,   235,    66,
      67,   205,    88,   235,   101,   102,   235,    94,   235,   263,
     255,   256,   257,   258,   259,   260,   261,   262,    89,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     284,   235,    61,    62,    63,    96,   263,    94,   264,   265,
     266,   267,   279,   297,   295,   260,   261,   262,    87,    88,
     287,   288,    87,    88,    87,    88,    94,   284,    94,   263,
     206,    91,   258,   259,   210,   211,    94,    94,   214,   215,
     297,    96,    89,    88,    97,    89,   268,   269,    94,    91,
     284,    94,   228,   320,   329,   330,   323,   233,   234,   293,
     236,   344,     4,   297,     6,    94,    89,   107,   109,    11,
     108,    68,    87,   391,    70,    17,    87,   344,    88,    21,
     398,    88,   344,    96,    58,   344,   404,   344,    88,    31,
      88,    33,    95,    95,    95,    12,    82,    82,    70,   275,
      94,    96,    95,    45,   422,   418,    95,   283,    95,    17,
     344,   378,    94,    88,    56,   399,    95,    95,    98,    95,
      87,    98,   440,   441,    95,    98,    86,    88,   177,    95,
     397,   307,   235,   276,   310,   311,   345,   171,   284,   297,
      82,    66,   399,   418,    77,   387,     4,     5,     6,   205,
       8,   120,   321,    11,   321,   227,    14,    15,    16,    17,
     270,    19,   310,    21,    22,   399,   331,   312,    26,   345,
     272,   271,   252,    31,    -1,    33,   274,    35,    36,   273,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    47,
      48,    49,    50,    51,    -1,    -1,    54,    -1,    56,    -1,
      58,    59,    60,    -1,    -1,    -1,    -1,    -1,   384,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      -1,    -1,    -1,    -1,    82,    83,    84,    -1,    -1,    -1,
      88,    93,    -1,    91,    92,   411,    94,    -1,    -1,    -1,
     416,    99,   100,   101,   102,     4,     5,     6,    -1,     8,
      -1,    -1,    11,    -1,    -1,    14,    15,    16,    17,    -1,
      19,    -1,    21,    22,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    31,    -1,    33,    -1,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    47,    48,
      49,    50,    51,    -1,    -1,    54,    -1,    56,    -1,    58,
      59,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    83,    84,    -1,    -1,    -1,    88,
      -1,    -1,    91,    92,    -1,    94,    -1,    -1,    -1,    -1,
      99,   100,   101,   102,     4,     5,     6,    -1,     8,    -1,
      -1,    11,    -1,    -1,    14,    15,    16,    17,    -1,    -1,
      -1,    21,    22,    -1,    -1,    -1,    26,    -1,    -1,    -1,
      -1,    31,    -1,    33,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    -1,    47,    48,    49,
      50,    51,    -1,    -1,    54,    -1,    56,    -1,    58,    59,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    82,    83,    84,    -1,    -1,    -1,    88,    -1,
       4,    91,     6,    -1,    94,    -1,    -1,    11,    -1,    99,
     100,   101,   102,    17,    -1,    19,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    33,
      -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    47,    -1,    -1,    50,    -1,    -1,    -1,
      -1,    -1,    56,    -1,    -1,    59,    60,    -1,    -1,     4,
       4,     6,     6,    -1,    -1,    -1,    11,    11,    -1,    -1,
      -1,    -1,    17,    17,    19,    -1,    21,    21,    82,    83,
      84,    -1,    -1,    -1,    88,    -1,    31,    31,    33,    33,
      94,    35,    36,    -1,    -1,    99,   100,   101,   102,    -1,
      45,    45,    -1,    47,    -1,    -1,    50,    -1,    -1,    -1,
      -1,    56,    56,    -1,    -1,    59,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    82,    83,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    -1,
      94,    -1,     4,    -1,     6,    99,   100,   101,   102,    11,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    33,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    47,    -1,    -1,    50,    -1,
      -1,    -1,    -1,    -1,    56,    -1,    -1,    59,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      92,    -1,    94,    -1,     4,    -1,     6,    99,   100,   101,
     102,    11,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    33,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    47,    -1,    -1,
      50,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    59,
      60,    -1,    -1,    -1,     4,    -1,     6,    -1,    -1,    -1,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      -1,    21,    82,    83,    84,    -1,    -1,    -1,    88,    -1,
      -1,    31,    -1,    33,    94,    35,    36,    -1,    -1,    99,
     100,   101,   102,    -1,    -1,    45,    -1,    47,    -1,    -1,
      50,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    59,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,
      -1,     6,    82,    83,    84,    -1,    11,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    94,    95,    21,    -1,    -1,    99,
     100,   101,   102,    -1,    -1,    -1,    31,    -1,    33,    -1,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    -1,    47,    -1,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    59,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,    -1,     6,    82,    83,    84,
      -1,    11,    -1,    -1,    -1,    -1,    91,    17,    -1,    94,
      -1,    21,    -1,    -1,    99,   100,   101,   102,    -1,    -1,
      -1,    31,    -1,    33,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    47,    -1,    -1,
      50,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    59,
      60,    -1,    -1,    -1,     4,    -1,     6,    -1,    -1,    -1,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      -1,    21,    82,    83,    84,    -1,    -1,    -1,    88,    -1,
      -1,    31,    -1,    33,    94,    35,    36,    -1,    -1,    99,
     100,   101,   102,    -1,    -1,    45,    -1,    47,    -1,    -1,
      50,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    59,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,
      -1,     6,    82,    83,    84,    -1,    11,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    94,    95,    21,    -1,    -1,    99,
     100,   101,   102,    -1,    -1,    -1,    31,    -1,    33,    -1,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    -1,    47,    -1,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    59,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,    -1,     6,    82,    83,    84,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    -1,    94,
      95,    21,    -1,    -1,    99,   100,   101,   102,    -1,    -1,
      -1,    31,    -1,    33,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    47,    -1,    -1,
      50,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    59,
      60,    -1,    -1,    -1,     4,    -1,     6,    -1,    -1,    -1,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      -1,    21,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    33,    94,    35,    36,    -1,    -1,    99,
     100,   101,   102,    -1,     4,    45,     6,    47,    -1,    -1,
      50,    11,    -1,    -1,    -1,    -1,    56,    17,    -1,    59,
      60,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    33,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,    82,    83,    84,    45,    -1,    47,    -1,    -1,
      50,     4,    -1,     6,    94,    -1,    56,    -1,    11,    99,
     100,   101,   102,    -1,    17,    -1,    19,    -1,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      33,    -1,    82,    83,    84,    -1,    -1,    -1,    -1,     4,
      -1,     6,    45,    -1,    94,    -1,    11,    -1,    -1,    99,
     100,    -1,    17,    56,    19,    -1,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    33,     3,
       4,    -1,     6,    -1,    -1,    -1,    -1,    11,    12,    82,
      45,    -1,    -1,    17,    -1,    19,    -1,    21,    -1,    -1,
      -1,    56,    95,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,    -1,
      -1,    45,    46,    -1,    -1,    49,    -1,    82,    -1,    53,
      -1,    -1,    56,    57,     3,     4,    -1,     6,    -1,    -1,
      95,    -1,    11,    12,    -1,    -1,    -1,    -1,    17,    -1,
      19,    -1,    21,    -1,    -1,    -1,    -1,    -1,    82,    -1,
      -1,    -1,    31,    32,    33,    34,    -1,    91,    92,    -1,
      -1,    40,    41,    42,    -1,    -1,    45,    46,    -1,    -1,
      49,    -1,    -1,    -1,    53,    -1,    -1,    56,    57,     3,
       4,    -1,     6,    -1,    -1,    -1,    -1,    11,    12,    -1,
      -1,    -1,    -1,    17,    -1,    19,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    82,    -1,    -1,    -1,    31,    32,    33,
      34,    -1,    91,    92,    -1,    -1,    40,    41,    42,    -1,
      -1,    45,    46,    -1,    -1,    49,    -1,    -1,    -1,    53,
      -1,    -1,    56,    57,     3,     4,    -1,     6,    -1,    -1,
      -1,    -1,    11,    12,    -1,    -1,    -1,    -1,    17,    -1,
      19,    -1,    21,    -1,    -1,    -1,    -1,    -1,    82,    -1,
      -1,    -1,    31,    32,    33,    34,    -1,    91,    92,    -1,
      -1,    40,    41,    42,    -1,    -1,    45,    46,    -1,    -1,
      49,    -1,    -1,    -1,    53,    -1,    -1,    56,    57,     3,
       4,    -1,     6,    -1,    -1,    -1,    -1,    11,    12,    -1,
      -1,    -1,    -1,    17,    -1,    19,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    82,    -1,    -1,    -1,    31,    32,    33,
      34,     3,    91,    92,    -1,    -1,    40,    41,    42,    -1,
      12,    45,    46,    -1,    -1,    49,    -1,    19,    -1,    53,
      -1,    -1,    56,    57,    -1,     3,    28,    -1,    -1,    -1,
      32,    -1,    34,    -1,    12,    -1,    -1,    39,    40,    41,
      42,    19,    -1,     3,    46,    -1,    -1,    49,    82,    -1,
      28,    53,    12,    -1,    32,    57,    34,    -1,    -1,    19,
      -1,    -1,    40,    41,    42,    -1,    -1,    -1,    46,    -1,
      -1,    49,    32,    -1,    34,    53,    -1,    -1,    -1,    57,
      40,    41,    42,    -1,    -1,    -1,    46,    -1,    -1,    49,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    57
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     3,    12,    19,    28,    32,    34,    39,    40,    41,
      42,    46,    49,    53,    57,   117,   118,   119,   120,   121,
     122,   123,   125,   126,   127,   128,   129,    82,   124,   124,
       0,   120,   122,   121,   120,   123,    88,   116,    91,   128,
     129,    82,    89,   116,    89,   116,   120,    88,     4,     6,
      11,    17,    21,    31,    33,    45,    46,    56,    82,    91,
      92,   112,   113,   115,   124,   125,   127,   131,   132,   133,
     134,   139,   146,   147,   148,   149,   151,    82,    18,    27,
     130,   150,    82,    90,   151,    94,     5,     8,    14,    15,
      16,    19,    22,    26,    35,    36,    44,    47,    48,    49,
      50,    51,    54,    58,    59,    60,    82,    83,    84,    88,
      92,    94,    99,   100,   101,   102,   112,   115,   124,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   165,
     166,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     181,   182,   183,   184,   188,   189,   190,   191,   192,   193,
     194,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   210,    82,   135,   136,   140,   143,    70,
     187,   112,   147,    92,   132,   116,    88,    52,   144,   151,
     130,   150,   113,   114,   124,    87,   130,   116,    19,    95,
     112,   141,   142,    82,    88,   115,   124,   190,   207,   211,
      82,    88,    96,   155,   112,    94,    94,   113,    88,   210,
      94,    94,   210,   151,    94,    94,   190,   190,    96,   115,
     124,   195,   196,   210,   135,   143,    89,    89,    97,    92,
     153,    88,    89,    97,    94,    91,    91,    59,    60,    89,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    93,   209,   190,   194,    90,   103,   104,   101,   102,
      61,    62,    63,    30,    64,    65,   105,   106,    66,    67,
     107,   108,   109,    68,    69,   110,    87,    70,    88,   144,
     145,   151,    70,    93,    94,    70,   135,   140,   144,   151,
     114,   151,   130,    87,   113,   112,   143,    87,    95,    88,
      96,    88,    58,   135,    88,   154,   158,   161,   164,   210,
      94,    97,   185,   186,   187,    88,   210,   210,    88,    10,
      20,   167,   168,   169,   170,   210,   210,   187,   187,    95,
      95,    95,    88,    12,    12,    50,   182,   210,    82,   210,
      95,   180,   210,    92,   131,    91,    92,   137,   138,   210,
      82,   208,   194,   194,   194,   197,   197,   198,   198,   198,
     112,   199,   199,   199,   199,   200,   200,   201,   202,   203,
     204,   205,   210,   136,   145,   137,    95,   141,   144,   145,
     151,   124,   143,   142,    94,    88,    88,   162,   210,    87,
      88,    95,    95,   180,   210,   186,   187,    95,    95,    94,
     151,   168,   170,   151,    95,    95,   194,   194,   191,    98,
      98,    87,    95,    92,    92,   138,    87,    92,    96,    95,
     145,   210,    95,   163,   164,    88,   158,   155,    95,    98,
     151,   155,   112,   155,   210,    92,   137,   207,    95,   155,
      95,    86,    82,    95,    88,   155,   155,    95
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
        case 3:
#line 70 "C:\\Users\\Dell-PC\\documents\\visual studio 2013\\Projects\\JavaCompiler\\yacc.y"
    { cout << "TypeSpecifier"; ;}
    break;


      default: break;
    }

/* Line 1126 of yacc.c.  */
#line 2066 "yacc.cpp"

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


#line 646 "C:\\Users\\Dell-PC\\documents\\visual studio 2013\\Projects\\JavaCompiler\\yacc.y"




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
	Parser* p = new Parser();
	p->parse();
	
}

