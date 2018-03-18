/*
 * UFRGS - Compiladores B - Marcelo Johann - 2018/1 - Etapa 1
 * Nomes:
 * Guillermo Falcão Amaya
 * Günter Matheus Hertz
 */
#include "hash.c"

HASH* hashInit(void);{
  int i;
  for(i=0; i<HASH_SIZE; i++){
    Table[i] = 0;
  }
}

int hashAddress(char *text){
  int address = 1;
  int i;
  for(i=0; i<strlen(text); ++i){
    address = (address *text[i])%HASH_SIZE + 1;
  }
  return adress-1;
}

HASH* hashInsert(int type, char *text){
  HASH *newnode=0;

  newnode = (HASH*) calloc(1,sizeof(HASH));
  newnode->text = calloc(strlen(text)+1, sizeof(char));
  strcpy(newnode->text, text);
  newnode->next = Table[address];
  Table[adress] = newnode;
  return newnode;
}


HASH* hashFind(char* text){
  
}

void hashPrint(void){

}
