/*
 * UFRGS - Compiladores B - Marcelo Johann - 2018/1 - Etapa 1
 * Nomes:
 * Guillermo Falcão Amaya
 * Günter Matheus Hertz
*/

%{
#include "tokens.h"
#include "hash.h"

int lineNumber = 1;
int running = 1;

int getLineNumber();
int isRunning();
void initMe();
%}

%%

"char"										{return KW_CHAR;}
"int" 									  {return KW_INT ;}
"float" 									{return KW_FLOAT;}
"if"                      {return KW_IF;}
"then" 										{return KW_THEN;}
"else" 										{return KW_ELSE;}
"while" 									{return KW_WHILE;}
"for" 										{return KW_FOR;}
"read" 										{return KW_READ;}
"print" 									{return KW_PRINT;}
"return" 									{return KW_RETURN;}

[\,\;\:\(\)\[\]\{\}\+\-\*\/\<\>\=\!\&\$\#]	{return yytext[0];}

"<=" 										{return OPERATOR_LE;}
">=" 										{return OPERATOR_GE;}
"==" 										{return OPERATOR_EQ;}
"!=" 										{return OPERATOR_NE;}
"&&" 										{return OPERATOR_AND;}
"||" 										{return OPERATOR_OR;}

[a-zA-Z_][a-zA-Z_0-9]* 		{hashInsert(TK_IDENTIFIER, yytext); return TK_IDENTIFIER;}
[0-9]+ 										{hashInsert(LIT_INTEGER, yytext); return LIT_INTEGER;}
[0-9]+\.[0-9]+ 								{hashInsert(LIT_REAL, yytext); return LIT_REAL;}

[ \t]										{}
"\n" 										{lineNumber++;}
"//".*
"/*" 										{BEGIN(COMMENT);}

. 											{return TOKEN_ERROR;}

%%

int getLineNumber(void)
{
	return lineNumber;
}

int isRunning(void)
{
	return running;
}
