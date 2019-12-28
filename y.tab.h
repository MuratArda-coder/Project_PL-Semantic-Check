#define OR 257
#define SEMICOLON 258
#define OPEN 259
#define CLOSE 260
#define ARROW 261
#define RULES 262
#define NUMBER 263
#define NONTERMINAL 264
#define TYPE 265
#define OPERATOR 266
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union
{
int number;
char *string;
char letter;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
