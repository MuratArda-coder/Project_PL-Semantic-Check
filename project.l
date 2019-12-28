%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
int lineNum=1;
%}

digit [0-9]
capitalLetter [A-Z]

%%

{capitalLetter}	{yylval.letter=yytext[0]; return NONTERMINAL;}
"+"|"-"|"*"|"/"	{yylval.letter=yytext[0]; return OPERATOR;}
(-?){digit}+	{yylval.letter=yytext[0]; return NUMBER;}
"int"|"float"	{yylval.letter=yytext[0]; return TYPE;}
"|"		{return OR;}
";"		{return SEMICOLON;}
"("		{return OPEN;}
")"		{return CLOSE;}
"->"		{return ARROW;}
"%rules"	{return RULES;}
\n {lineNum++;}
[ \t]+

%%
