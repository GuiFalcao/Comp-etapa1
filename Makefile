#
# UFRGS - Compiladores B - Marcelo Johann - 2018/1 - Etapa 1
# Nomes:
# Guillermo Falcão Amaya
# Günter Matheus Hertz
#

etapa1: lex.yy.c
	gcc -o etapa1 lex.yy.c hash.c

lex.yy.c: scanner.l
	lex scanner.l

clean:
	rm lex.yy.c etapa1
