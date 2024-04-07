#ifndef FILADINAMICA_H
#define FILADINAMICA_H

typedef struct noFila{
    char nome[30];
    int operacao;
    int afiliacao;
    int tempoChegada;
    struct noFila *prox;
}NOFILA;

typedef struct fila{
    NOFILA *inicio;
    NOFILA *fim;
    int clientesAtendidos;
    int somaTempos;
    int tempoMedioNaFila;
    int tempoAtendimento;
}FILA;

void inicializarFila(FILA *fila);
int estaVazia(FILA *fila);
void inserirFila(FILA *fila, char *nome, int operacao, int afiliacao, int tempoChegada);
void removerFila(FILA *fila, NOFILA *cliente);
void exibirFila(FILA *fila);
void exibirNoFila(NOFILA *cliente);
int numeroAleatorioRange(int inicio, int fim);
char* nomeAleatorio();

#include "FilaDinamica.c"
#endif