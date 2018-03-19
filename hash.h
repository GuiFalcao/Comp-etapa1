/*
 * UFRGS - Compiladores B - Marcelo Johann - 2018/1 - Etapa 1
 * Nomes:
 * Guillermo Falcão Amaya
 * Günter Matheus Hertz
 */
 
#define HASH_SIZE 997

typedef struct hash_node{
 int type;
 char *text;
 struct hash_node *next;
} HASH;

void hashInit(void);
int hashAddress(char *text);
HASH* hashInsert(int type, char *text);
HASH* hashFind(char* text);
void hashPrint(void);
