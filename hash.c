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

HASH_NODE* hashInsert(int type, char* text){
    int address;
    HASH_NODE* newNode = NULL;

    address = hashAddress(text);

    newNode = hashFind(text);
    if (newNode == NULL){
        newNode = (HASH_NODE*) calloc(1, sizeof(HASH_NODE));
        newNode->type = type;
        newNode->text = (char*) calloc(strlen(text)+1, sizeof(char));
        strcpy(newNode->text, text);

        newNode->next = hashTable[address];
        hashTable[address] = newNode;
    }
    return newNode;
}


HASH_NODE* hashFind(char* text){
    int address;
    address = hashAddress(text);

    HASH_NODE* node;

    for (node = hashTable[address]; node != NULL; node = node->next){
        if (!strcmp(text, node->text))
            return node;
    }

    return NULL;
}

void hashPrint(void){
    int i = 0;
    HASH_NODE* node;

    for (i = 0; i < HASH_SIZE; ++i){
        for (node = hashTable[i]; node != NULL; node = node->next){
            fprintf(stderr, "Posicao %d tem: %s do tipo: %d\n",
                    i, node->text, node->type);
        }
    }
}
