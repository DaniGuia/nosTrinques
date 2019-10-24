#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int TIPOCHAVE;
typedef int bool;

#define true 1
#define false 0

typedef struct {
    TIPOCHAVE chave;
    //outros campos;
} REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux* prox;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
    PONT inicio;
    PONT fim;
} FILA;

//Funções de gerenciamento fila
void inicializarFila(FILA* f);
int tamanhoFila(FILA* f);
void exibirFila(FILA* f);
bool inserirElemFila(FILA* f, REGISTRO reg);
bool excluirElemFila(FILA* f, REGISTRO* reg);
void reinicializarFila(FILA* f);

int main()
{
    FILA fila;
    inicializarFila(&fila);

    REGISTRO reg1, reg2, reg3;
    reg1.chave = 12;
    reg2.chave = 5;

    inserirElemFila(&fila, reg1);
    inserirElemFila(&fila, reg2);
    exibirFila(&fila);
    tamanhoFila(&fila);
    excluirElemFila(&fila, &reg3);
    exibirFila(&fila);
    reinicializarFila(&fila);

    return 0;
}

void inicializarFila(FILA* f) {
    f->inicio = NULL;
    f->fim = NULL;
}

int tamanhoFila(FILA* f) {
    PONT end = f->inicio;
    int tam = 0;
    while(end != NULL) {
        tam++;
        end = end->prox;
    }
    return tam;
}

void exibirFila(FILA* f) {
    printf("Fila: ");
    PONT end = f->inicio;
    while(end != NULL) {
        printf("%i ", end->reg.chave);
        end = end->prox;
    }
    printf("\n");
}

bool inserirElemFila(FILA* f, REGISTRO reg) {
    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    novo->prox = NULL;
    if(f->inicio == NULL) {
        f->inicio = novo;
    } else {
        f->fim->prox = novo;
    }
    f->fim = novo;
    return true;
}

bool excluirElemFila(FILA* f, REGISTRO* reg) {
    if(f->inicio == NULL) {
        return false;
    }
    *reg = f->inicio->reg;
    PONT apagar = f->inicio;
    f->inicio = f->inicio->prox;
    free(apagar);
    if(f->inicio == NULL) {
        f->fim = NULL;
    }
    return true;
}

void reinicializarFila(FILA* f) {
    PONT end = f->inicio;
    while(end != NULL) {
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    f->inicio = NULL;
    f->fim = NULL;
    return true;
}
