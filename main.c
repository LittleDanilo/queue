#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    char vet[7];
    int front, rear;
} TFila;

int next(int n) {
    return (n + 1) % 7;
}

void create(TFila *f) {
    f->front = f->rear = 0;
}

void destroy(TFila *f) {
    f->front = f->rear;
}

int isfull(TFila *f) {
    return next(f->rear) == f->front;
}

int isempty(TFila *f) {
    return f->front == f->rear;
}

void store(TFila *f, char x) {
    if(isfull(f)) {
        puts("The queue is full.");
        abort();
    }
    f->vet[f->rear] = x;
    f->rear = next(f->rear);
}

char retrieve(TFila *f) {
    if (isempty(f)) {
        puts("The queue is empty.");
        abort();
    }
    char aux = f->vet[f->front];
    f->front = next(f->front);
    return aux;
}

typedef struct filaprior {
    TFila f1,f2,f3;
} TFilaPrior;

TFilaPrior f;

void incluir(char elem, int prior) {
    switch (prior) {
    case 1:
        store(&f.f1, elem);
        break;
    case 2:
        store(&f.f2, elem);
        break;
    case 3:
        store(&f.f3, elem);
        break;
    default:
        break;
    }
}

char retirar(void) {
    if (!isempty(&f.f1)) {return retrieve(&f.f1);}
    if (!isempty(&f.f2)) {return retrieve(&f.f2);}
    if (!isempty(&f.f3)) {return retrieve(&f.f3);}
    puts("Filas Vazias");
    abort();
}

int main(void) {
    // teste
    incluir('a', 1);
    incluir('c', 2);
    printf("%c \n", retirar());
    printf("%c \n", retirar());
    incluir('b', 1);
    incluir('d', 2);
    incluir('e', 3);
    printf("%c \n", retirar());
    incluir('f', 3);
    printf("%c \n", retirar());
    printf("%c \n", retirar());
    printf("%c \n", retirar());
    return 0;
}