#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "FilaDinamica.h"

void inicializarFila(FILA *fila){
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->clientesAtendidos = 0;
    fila->somaTempos = 0;
    fila->tempoMedioNaFila = 0;
    fila->tempoAtendimento = 0;
}

int estaVazia(FILA *fila){
    if(fila->inicio == NULL){
        return 1;
    }
    return 0;
}

void inserirFila(FILA *fila, char *nome, int operacao, int afiliacao, int tempoChegada){
    NOFILA *novoNo = (NOFILA*) malloc(sizeof(NOFILA));
    strcpy(novoNo->nome, nome);
    novoNo->operacao = operacao;
    novoNo->afiliacao = afiliacao;
    novoNo->tempoChegada = tempoChegada;

    if(estaVazia(fila)){
        fila->inicio = novoNo;
        novoNo->prox = NULL;
    }
    else{
        fila->fim->prox = novoNo;
        novoNo->prox = NULL;
    }

    fila->fim = novoNo;
}

void removerFila(FILA *fila, NOFILA *cliente){
    if(estaVazia(fila)){
        printf("Fila vazia\n");
        return;
    }

    NOFILA *aux = fila->inicio;
    
    cliente->operacao = aux->operacao;
    cliente->afiliacao = aux->afiliacao;
    cliente->tempoChegada = aux->tempoChegada;

    fila->inicio = fila->inicio->prox;
    free(aux);
}

void exibirFila(FILA *fila){
    if(estaVazia(fila)){
        printf("Fila vazia\n");
        return;
    }

    NOFILA *aux = fila->inicio;
    while(aux != NULL){
        printf("Nome: %s\n", aux->nome);
        if(aux->operacao){
            printf("Operacao: Saque\n");
        }
        else{
            printf("Operacao: Deposito\n");
        }
        if(aux->afiliacao){
            printf("Afiliacao: Cliente\n");
        }
        else{
            printf("Afiliacao: Nao cliente\n");
        }
        printf("Tempo chegada: %d\n", aux->tempoChegada);
        aux = aux->prox;
    }
}

void exibirNoFila(NOFILA *cliente){
    printf("Nome: %s\n", cliente->nome);
        if(cliente->operacao){
            printf("Operacao: Saque\n");
        }
        else{
            printf("Operacao: Deposito\n");
        }
        if(cliente->afiliacao){
            printf("Afiliacao: Cliente\n");
        }
        else{
            printf("Afiliacao: Nao cliente\n");
        }
        printf("Tempo chegada: %d\n", cliente->tempoChegada);
        return;
}

int numeroAleatorioRange(int inicio, int fim){
    return rand() % (fim - inicio + 1) + inicio;
}

char* nomeAleatorio(){
    char* nomes[] = {"Ana", "Bruno", "Carla", "Diego", "Erika", "Felipe", "Gabriela", "Hugo", "Isabela", "Joao"};
    char *sobrenomes[] = {"Silva", "Santos", "Pereira", "Oliveira", "Souza", "Ferreira", "Almeida", "Ribeiro", "Gomes", "Costa"};

    int numeroNomes = sizeof(nomes) / sizeof(nomes[0]);
    int numeroSobrenomes = sizeof(sobrenomes) / sizeof(sobrenomes[0]);
    int indexAleatorioNomes = rand() % numeroNomes;
    int indexAleatorioSobrenomes = rand() % numeroSobrenomes;

    char *nomeCompleto = (char*) malloc(30 * sizeof(char));

    strcpy(nomeCompleto, nomes[indexAleatorioNomes]);
    strcat(nomeCompleto, " ");
    strcat(nomeCompleto, sobrenomes[indexAleatorioSobrenomes]);

    return nomeCompleto;
}





