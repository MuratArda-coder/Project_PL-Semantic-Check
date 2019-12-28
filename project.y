%{ 
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

%}

%union
{
int number;
char *string;
char letter;
}

%token OR SEMICOLON OPEN CLOSE ARROW RULES

%token <letter> NUMBER
%token <letter> NONTERMINAL
%token <letter> TYPE
%token <letter> OPERATOR

%type <letter> ident


%%

program:	RULES fillRules;

fillRules:	getRule SEMICOLON continue1
		|
		getRule fillRules
		;

getRule:	NONTERMINAL NUMBER
		{
			ruleTable[size][0]=$1;
			ruleTable[size][1]=$2;
			size++;
		}
		;

continue1:	getArrow continue2;

getArrow:	NONTERMINAL ARROW
		{
			defRule[def][0] = $1;
			defRule[def][1] = '1';
			def++;
			ruleN++;
			rule=0;
		}
		;
		
continue2:	writeRule SEMICOLON 
		|
		writeRule SEMICOLON continue1
		;

writeRule:	Xident continueToWrite
		|
		Xident getOperator operation continueToWrite;
		
		
continueToWrite	:| 
		 getOr writeRule ;

getOr:		OR
		{
			defRule[def-1][1]++;ruleN++;rule=0;
		}
		;

operation:	Xident
		|
		Xident getOperator operation
		;
		

getOperator:	OPERATOR
		{
			if($1=='+') 
				{tokenList[tok]='+';tok++;ruleList[ruleN][rule++]='+';}
			else if($1=='-')
				{tokenList[tok]='-';tok++;ruleList[ruleN][rule++]='-';}
			else if($1=='*')
				{tokenList[tok]='*';tok++;ruleList[ruleN][rule++]='*';}
			else if($1=='/')
				{tokenList[tok]='/';tok++;ruleList[ruleN][rule++]='/';}
			tok=removeDublicatedandSize(tokenList,tok);
		}
		;

Xident:		OPEN ident CLOSE
		{
			//printf("ident():%c\n",$2);++
			tokenList[tok]='(';
			tok++;
			tokenList[tok]=')';
			tok++;
			tok=removeDublicatedandSize(tokenList,tok);
	
			ruleList[ruleN][rule++]='(';
			if($2=='i')
			{
				ruleList[ruleN][rule++]='i';
				ruleList[ruleN][rule++]='n';
				ruleList[ruleN][rule++]='t';
				ruleList[ruleN][rule++]=')';
			}
			else if($2=='f')
			{
				ruleList[ruleN][rule++]='f';
				ruleList[ruleN][rule++]='l';
				ruleList[ruleN][rule++]='o';
				ruleList[ruleN][rule++]='a';
				ruleList[ruleN][rule++]='t';
				ruleList[ruleN][rule++]=')';
			}
			else {
				ruleList[ruleN][rule++]=$2;
				ruleList[ruleN][rule++]=')';
			}
			
		}
		|
		ident
		{
			//printf("ident:%c\n",$1);++
			if($1=='i')
			{
				ruleList[ruleN][rule++]='i';
				ruleList[ruleN][rule++]='n';
				ruleList[ruleN][rule++]='t';
			}
			else if($1=='f')
			{
				ruleList[ruleN][rule++]='f';
				ruleList[ruleN][rule++]='l';
				ruleList[ruleN][rule++]='o';
				ruleList[ruleN][rule++]='a';
				ruleList[ruleN][rule++]='t';
			}
			else {
				ruleList[ruleN][rule++]=$1;
			}
		}
		;

ident:		NONTERMINAL
		{
			refRule[ref] = $1;
			ref++;
			ref=removeDublicatedandSize(refRule,ref);
			$$=$1;
		}
		|
		TYPE
		{
			if($1=='i') 
				{tokenList[tok]='i';tok++;}
			else if($1=='f')
				{tokenList[tok]='f';tok++;}
			tok=removeDublicatedandSize(tokenList,tok);
			$$=$1;
		}
		;

	

%%

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
