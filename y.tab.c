/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 1 "project.y"
 
#include<stdio.h>
#include<stdlib.h>
#include "myFunctions.h"
extern FILE *yyin;
extern int lineNum;

char ruleTable[10][2];
int size = 0;

char defRule[10][2];
int def = 0;

char refRule[10];
int ref = 0;

char tokenList[10];
int tok=0;
/*
it is difficult for me to make token string and
use them in the function so that i store them as a character

OPEN='('	CLOSE=')'	int='i'		float='f'
PLUS='+'	MINUS='-'	DIVIDE='/'	TIMES='*'
END='e'
*/
char ruleList[10][20];
int ruleN=-1;
int rule=0;

#line 33 "project.y"
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
#line 66 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

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
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    2,    2,    3,    4,    5,    6,    6,    7,    7,
    9,    9,   12,   11,   11,   10,    8,    8,    1,    1,
};
static const YYINT yylen[] = {                            2,
    2,    3,    2,    2,    2,    2,    2,    3,    2,    4,
    0,    2,    1,    1,    3,    1,    3,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    1,    0,    4,    0,    3,    0,    2,
    0,    6,    0,   19,   20,   18,    5,    0,    0,    0,
    0,   13,   16,    9,    0,    0,   17,    8,    0,    0,
   12,    0,   10,   15,
};
static const YYINT yydgoto[] = {                          2,
   16,    4,    5,   10,   11,   17,   18,   19,   24,   25,
   30,   26,
};
static const YYINT yysindex[] = {                      -258,
 -249,    0, -256,    0, -252,    0, -248,    0, -243,    0,
 -254,    0, -262,    0,    0,    0,    0, -241, -257, -240,
 -248,    0,    0,    0, -254, -254,    0,    0, -247, -236,
    0, -254,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -235,    0,
   22,    0,    0,    0,    0,    0,    0,    0, -244, -235,
    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   11,   20,    0,    5,    0,    0,    1,  -24,   -2,    2,
   -3,    0,
};
#define YYTABLESIZE 31
static const YYINT yytable[] = {                         22,
   29,   14,   15,    1,   13,    7,    6,   29,   23,   14,
   15,    3,   14,   14,    3,    9,   21,   12,   23,   27,
   22,    7,   11,   20,    8,   28,   31,   33,   34,    0,
   32,
};
static const YYINT yycheck[] = {                        257,
   25,  264,  265,  262,  259,  258,  263,   32,  266,  264,
  265,  264,  257,  258,  264,  264,  258,  261,  266,  260,
  257,    0,  258,   13,    5,   21,   26,   30,   32,   -1,
   29,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 266
#define YYUNDFTOKEN 281
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"OR","SEMICOLON","OPEN","CLOSE",
"ARROW","RULES","NUMBER","NONTERMINAL","TYPE","OPERATOR",0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : RULES fillRules",
"fillRules : getRule SEMICOLON continue1",
"fillRules : getRule fillRules",
"getRule : NONTERMINAL NUMBER",
"continue1 : getArrow continue2",
"getArrow : NONTERMINAL ARROW",
"continue2 : writeRule SEMICOLON",
"continue2 : writeRule SEMICOLON continue1",
"writeRule : Xident continueToWrite",
"writeRule : Xident getOperator operation continueToWrite",
"continueToWrite :",
"continueToWrite : getOr writeRule",
"getOr : OR",
"operation : Xident",
"operation : Xident getOperator operation",
"getOperator : OPERATOR",
"Xident : OPEN ident CLOSE",
"Xident : ident",
"ident : NONTERMINAL",
"ident : TYPE",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 196 "project.y"

void yyerror(char *s){
	fprintf(stderr,"error: %d\n",lineNum);
}
int yywrap(){
	return 1;
}
int main(int argc, char *argv[])
{
	yyin=fopen(argv[1],"r");
	yyparse();
	fclose(yyin);
	///C  File Will Be Created Here///
	int i;int j;
	///Check is Tables Are correct///
	/*
	ruleN++;
	for(i=0;i<size;i++) {
		printf("Rules %d is %c and num is %c\n",i,ruleTable[i][0],ruleTable[i][1]);//++
	}
	for(i=0;i<def;i++) {
		printf("Definitions %d is %c and count rules is %c\n",i,defRule[i][0],defRule[i][1]);//++
	}
	for(i=0;i<ref;i++) {
		printf("Referances %d is %c \n",i,refRule[i]);//++
	}
	for(i=0;i<tok;i++) {
		printf("Tokens %d is %c \n",i,tokenList[i]);//++
	}
	for(i=0;i<ruleN;i++) {//++
		printf("rule %d: ",i);
		for(j=0;ruleList[i][j]!='\0';j++) {
			printf("%c",ruleList[i][j]);
		}
		printf("\n");
	}
	*/
	////////////////////////////////

	///////Now Error Checking///////

	int flag = 1;
	for(i=0;i<size;i++) {//Analysis 1++
		for(j=0;j<def;j++) {
			if(ruleTable[i][0]==defRule[j][0]) {
				if(ruleTable[i][1]!=defRule[j][1]) {
					printf("%c ' s rule are not match the #of it's rules!!!\n",ruleTable[i][0]);
					flag=0;
				}				
			}
		}		
	}

	int useRule = 1;
	for(i=0;i<size;i++) {//Analysis 2++
		if(size!=def) {
			printf("Define The Rule!!!\n");
			flag=0;
			break;
		}
		for(j=0;j<def;j++) {
			if(ruleTable[i][0]==defRule[j][0]) {
					useRule=1;
					break;
				}
				else
					useRule=0;				
			}
		if(useRule==0) {
			printf("Define The Rule!!!\n");
			flag=0;
			break;
		}		
	}

	int defFlag=1;
	for(j=0;j<ref;j++) {//Analysis 3++
		for(i=0;i<def;i++) {
			if(defRule[i][0]==refRule[j]) {
				defFlag=1;
				break;
			}
			else
				defFlag=0;				
		}
		if(defFlag==0) {
			printf("Undefined reference/s!!!\n");
			flag=0;
			break;
		}				
	}

	int useDef = 1;
	for(i=1;i<def;i++) {//Analysis 4++
		for(j=0;j<ref;j++) {
			if(defRule[i][0]==refRule[j]) {
				useDef=1;
				break;
			}
			else
				useDef=0;				
		}
		if(useDef==0) {
			printf("Useless Rule/s!!!\n");
			flag=0;
			break;
		}
	}

	////////////////////////////////

	///////Now Create C File////////
	if(flag) {
		FILE * MyCfiLE;
		MyCfiLE=fopen("output.c","w");

		fprintf(MyCfiLE, "#include <stdio.h>\n");
		fprintf(MyCfiLE, "typedef enum {");
		for(i=0;i<tok;i++) {
			if(tokenList[i]=='i')
			fprintf(MyCfiLE, "INT,");
			else if(tokenList[i]=='f')
				fprintf(MyCfiLE, "FLOAT,");
			else if(tokenList[i]=='+')
				fprintf(MyCfiLE, "PLUS,");
			else if(tokenList[i]=='-')
				fprintf(MyCfiLE, "MINUS,");
			else if(tokenList[i]=='*')
				fprintf(MyCfiLE, "TIMES,");
			else if(tokenList[i]=='/')
				fprintf(MyCfiLE, "DIVIDE,");
			else if(tokenList[i]=='(')
				fprintf(MyCfiLE, "OPEN,");
			else if(tokenList[i]==')')
				fprintf(MyCfiLE, "CLOSE,");
		}
		fprintf(MyCfiLE, "END} TOKEN;\n");
		fprintf(MyCfiLE, "TOKEN input[20] = {");
		for(i=0;i<tok;i++) {
			if(tokenList[i]=='i')
				fprintf(MyCfiLE, "INT,");
			else if(tokenList[i]=='f')
				fprintf(MyCfiLE, "FLOAT,");
			else if(tokenList[i]=='(')
				fprintf(MyCfiLE, "OPEN,");
			else if(tokenList[i]==')')
				fprintf(MyCfiLE, "CLOSE,");
		}
		fprintf(MyCfiLE, "END};\n");
		fprintf(MyCfiLE, "TOKEN *next = input;\n\n");
		char count;

		for(i=0;i<def;i++) {
			fprintf(MyCfiLE, "int ");
			putc(defRule[i][0],MyCfiLE);
			fprintf(MyCfiLE, "();");
			for(count='0';count<defRule[i][1];count++) {
				fprintf(MyCfiLE, "int ");
				putc(defRule[i][0],MyCfiLE);
				putc(count+1,MyCfiLE);
				fprintf(MyCfiLE, "();");
			}
		}

		fprintf(MyCfiLE, "\n\nint term(TOKEN tok) {return *next++ == tok;}\n\n");
		int k=0;
		for(i=0;i<def;i++) {
			for(count='0';count<defRule[i][1];count++,k++) {
				fprintf(MyCfiLE, "int ");
				putc(defRule[i][0],MyCfiLE);
				putc(count+1,MyCfiLE);
				fprintf(MyCfiLE, "(){return ");
				for(j=0;ruleList[k][j]!='\0';j++) {
					if(ruleList[k][j]=='+')
						fprintf(MyCfiLE, "term(PLUS)");
					else if(ruleList[k][j]=='-')
						fprintf(MyCfiLE, "term(MINUS)");
					else if(ruleList[k][j]=='*')
						fprintf(MyCfiLE, "term(TIMES)");
					else if(ruleList[k][j]=='/')
						fprintf(MyCfiLE, "term(DIVIDE)");
					else if(ruleList[k][j]=='i')
						{fprintf(MyCfiLE, "term(INT)");j=j+2;}
					else if(ruleList[k][j]=='f')
						{fprintf(MyCfiLE, "term(FLOAT)");j=j+4;}
					else if(ruleList[k][j]=='(')
						fprintf(MyCfiLE, "term(OPEN)");
					else if(ruleList[k][j]==')')
						fprintf(MyCfiLE, "term(CLOSE)");
					else
						{putc(ruleList[k][j],MyCfiLE);fprintf(MyCfiLE, "()");}
				
					if(ruleList[k][j+1]!='\0')
						fprintf(MyCfiLE, "&&");
				}
				fprintf(MyCfiLE, ";}");
				fprintf(MyCfiLE, "\n");
			}
			fprintf(MyCfiLE, "int ");
			putc(defRule[i][0],MyCfiLE);
			fprintf(MyCfiLE, "() {TOKEN *save=next; return ");
			for(count='0';count<defRule[i][1];count++) {
				if(count=='0') {
					putc(defRule[i][0],MyCfiLE);
					putc(count+1,MyCfiLE);
					fprintf(MyCfiLE, "()");
				}
				else {
					fprintf(MyCfiLE, "|| (next=save,");
					putc(defRule[i][0],MyCfiLE);
					putc(count+1,MyCfiLE);
					fprintf(MyCfiLE, "()");
					fprintf(MyCfiLE, ")");
				}
			}
			fprintf(MyCfiLE, ";}");
			fprintf(MyCfiLE, "\n\n");
		}
		fprintf(MyCfiLE, "\n");

		fprintf(MyCfiLE, "int main(void)\n{\n	if( ");
		putc(defRule[0][0],MyCfiLE);
		fprintf(MyCfiLE, "() && term(END))\n");
		fprintf(MyCfiLE, "		printf (\"Accept!\\n\");\n");
		fprintf(MyCfiLE, "	else\n");
		fprintf(MyCfiLE, "		printf (\"Reject!!\\n\");\n");
		fprintf(MyCfiLE, "	return 0;\n}\n");
	

		fclose(MyCfiLE);
	}
	////////////////////////////////
	return 0;
}
#line 472 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 4:
#line 60 "project.y"
	{
			ruleTable[size][0]=yystack.l_mark[-1].letter;
			ruleTable[size][1]=yystack.l_mark[0].letter;
			size++;
		}
break;
case 6:
#line 70 "project.y"
	{
			defRule[def][0] = yystack.l_mark[-1].letter;
			defRule[def][1] = '1';
			def++;
			ruleN++;
			rule=0;
		}
break;
case 13:
#line 93 "project.y"
	{
			defRule[def-1][1]++;ruleN++;rule=0;
		}
break;
case 16:
#line 105 "project.y"
	{
			if(yystack.l_mark[0].letter=='+') 
				{tokenList[tok]='+';tok++;ruleList[ruleN][rule++]='+';}
			else if(yystack.l_mark[0].letter=='-')
				{tokenList[tok]='-';tok++;ruleList[ruleN][rule++]='-';}
			else if(yystack.l_mark[0].letter=='*')
				{tokenList[tok]='*';tok++;ruleList[ruleN][rule++]='*';}
			else if(yystack.l_mark[0].letter=='/')
				{tokenList[tok]='/';tok++;ruleList[ruleN][rule++]='/';}
			tok=removeDublicatedandSize(tokenList,tok);
		}
break;
case 17:
#line 119 "project.y"
	{
			/*printf("ident():%c\n",$2);++*/
			tokenList[tok]='(';
			tok++;
			tokenList[tok]=')';
			tok++;
			tok=removeDublicatedandSize(tokenList,tok);
	
			ruleList[ruleN][rule++]='(';
			if(yystack.l_mark[-1].letter=='i')
			{
				ruleList[ruleN][rule++]='i';
				ruleList[ruleN][rule++]='n';
				ruleList[ruleN][rule++]='t';
				ruleList[ruleN][rule++]=')';
			}
			else if(yystack.l_mark[-1].letter=='f')
			{
				ruleList[ruleN][rule++]='f';
				ruleList[ruleN][rule++]='l';
				ruleList[ruleN][rule++]='o';
				ruleList[ruleN][rule++]='a';
				ruleList[ruleN][rule++]='t';
				ruleList[ruleN][rule++]=')';
			}
			else {
				ruleList[ruleN][rule++]=yystack.l_mark[-1].letter;
				ruleList[ruleN][rule++]=')';
			}
			
		}
break;
case 18:
#line 152 "project.y"
	{
			/*printf("ident:%c\n",$1);++*/
			if(yystack.l_mark[0].letter=='i')
			{
				ruleList[ruleN][rule++]='i';
				ruleList[ruleN][rule++]='n';
				ruleList[ruleN][rule++]='t';
			}
			else if(yystack.l_mark[0].letter=='f')
			{
				ruleList[ruleN][rule++]='f';
				ruleList[ruleN][rule++]='l';
				ruleList[ruleN][rule++]='o';
				ruleList[ruleN][rule++]='a';
				ruleList[ruleN][rule++]='t';
			}
			else {
				ruleList[ruleN][rule++]=yystack.l_mark[0].letter;
			}
		}
break;
case 19:
#line 175 "project.y"
	{
			refRule[ref] = yystack.l_mark[0].letter;
			ref++;
			ref=removeDublicatedandSize(refRule,ref);
			yyval.letter=yystack.l_mark[0].letter;
		}
break;
case 20:
#line 183 "project.y"
	{
			if(yystack.l_mark[0].letter=='i') 
				{tokenList[tok]='i';tok++;}
			else if(yystack.l_mark[0].letter=='f')
				{tokenList[tok]='f';tok++;}
			tok=removeDublicatedandSize(tokenList,tok);
			yyval.letter=yystack.l_mark[0].letter;
		}
break;
#line 789 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
