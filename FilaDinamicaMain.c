#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "FilaDinamica.h"

int main() {
    FILA filas[4];
    inicializarFila(&filas[0]);
    inicializarFila(&filas[1]);
    inicializarFila(&filas[2]);
    inicializarFila(&filas[3]);

    srand(time(NULL));

    int contadorClientesEntraram = 0, maiorTempoEspera = 0, contadorClientesAtendidos = 0, contadorNaoClienteAtendidos = 0;

    int tempoSimulacao = 0, tempo = 0;
    printf("Digite tempo simulacao: ");
    scanf("%d", &tempoSimulacao);

    char *nome = (char*) malloc(30 * sizeof(char));

    while (tempo < tempoSimulacao) {
        int clienteAleatorio = rand() % 2;
        printf("Adicionou: %d\n", clienteAleatorio);
        if (clienteAleatorio == 1) {
            strcpy(nome, nomeAleatorio());
            int operacao = rand() % 2;
            int afiliacao = rand() % 2;
            int tempoChegada = tempo;
            int filaAleatoria = rand() % 4;

            inserirFila(&filas[filaAleatoria], nome, operacao, afiliacao, tempoChegada);
            contadorClientesEntraram++;
        }

        if(estaVazia(&filas[0]) == 0 && filas[0].tempoAtendimento == 0){
            NOFILA cliente;
                removerFila(&filas[0], &cliente);

                if (cliente.afiliacao == 1) {
                    contadorClientesAtendidos++;
                } else {
                    contadorNaoClienteAtendidos++;
                }

                int tempoNaFila = tempo - cliente.tempoChegada;
                filas[0].somaTempos += tempoNaFila;

                if (tempoNaFila > maiorTempoEspera) {
                    maiorTempoEspera = tempoNaFila;
                }

                printf("Cliente atendido fila 0\n");

                filas[0].clientesAtendidos++;
                filas[0].tempoAtendimento = 5;
        }
        if(filas[0].tempoAtendimento != 0){
            filas[0].tempoAtendimento--;
        }

        if(estaVazia(&filas[1]) == 0 && filas[1].tempoAtendimento == 0){
            NOFILA cliente;
                removerFila(&filas[1], &cliente);

                if (cliente.afiliacao == 1) {
                    contadorClientesAtendidos++;
                } else {
                    contadorNaoClienteAtendidos++;
                }

                int tempoNaFila = tempo - cliente.tempoChegada;
                filas[1].somaTempos += tempoNaFila;

                if (tempoNaFila > maiorTempoEspera) {
                    maiorTempoEspera = tempoNaFila;
                }

                printf("Cliente atendido fila 1\n");

                filas[1].clientesAtendidos++;
                filas[1].tempoAtendimento = 5;
        }
        if(filas[1].tempoAtendimento != 0){
            filas[1].tempoAtendimento--;
        }

        if(estaVazia(&filas[2]) == 0 && filas[2].tempoAtendimento == 0){
            NOFILA cliente;
                removerFila(&filas[2], &cliente);

                if (cliente.afiliacao == 1) {
                    contadorClientesAtendidos++;
                } else {
                    contadorNaoClienteAtendidos++;
                }

                int tempoNaFila = tempo - cliente.tempoChegada;
                filas[2].somaTempos += tempoNaFila;

                if (tempoNaFila > maiorTempoEspera) {
                    maiorTempoEspera = tempoNaFila;
                }

                printf("Cliente atendido fila 2\n");

                filas[2].clientesAtendidos++;
                filas[2].tempoAtendimento = 5;
        }
        if(filas[2].tempoAtendimento != 0){
            filas[2].tempoAtendimento--;
        }

        if(estaVazia(&filas[3]) == 0 && filas[3].tempoAtendimento == 0){
            NOFILA cliente;
                removerFila(&filas[3], &cliente);

                if (cliente.afiliacao == 1) {
                    contadorClientesAtendidos++;
                } else {
                    contadorNaoClienteAtendidos++;
                }

                int tempoNaFila = tempo - cliente.tempoChegada;
                filas[3].somaTempos += tempoNaFila;

                if (tempoNaFila > maiorTempoEspera) {
                    maiorTempoEspera = tempoNaFila;
                }

                printf("Cliente atendido fila 3\n");

                filas[3].clientesAtendidos++;
                filas[3].tempoAtendimento = 5;
        }
        if(filas[3].tempoAtendimento != 0){
            filas[3].tempoAtendimento--;
        }


        
        printf("Tempo: %d\n", tempo);
        tempo++;
    }

    free(nome);

    if(filas[0].clientesAtendidos != 0){
        filas[0].tempoMedioNaFila = filas[0].somaTempos / filas[0].clientesAtendidos;
    }

    if(filas[1].clientesAtendidos != 0){
        filas[1].tempoMedioNaFila = filas[1].somaTempos / filas[1].clientesAtendidos;
    }

    if(filas[2].clientesAtendidos != 0){
        filas[2].tempoMedioNaFila = filas[2].somaTempos / filas[2].clientesAtendidos;
    }

    if(filas[3].clientesAtendidos != 0){
        filas[3].tempoMedioNaFila = filas[3].somaTempos / filas[3].clientesAtendidos;
    }
    

    int totalClientesAtendidos = filas[0].clientesAtendidos + filas[1].clientesAtendidos + filas[2].clientesAtendidos + filas[3].clientesAtendidos;
    
    int numeroClientesNaoAtendidos = contadorClientesEntraram - totalClientesAtendidos;

    int tempoMedioNasFilas = 0;
    if (totalClientesAtendidos != 0) {
        tempoMedioNasFilas = (filas[0].somaTempos + filas[1].somaTempos + filas[2].somaTempos + filas[3].somaTempos) / totalClientesAtendidos;
    }

    printf("======================================================================================================================================================\n");
    printf("Fila caixa 0: \n");
    exibirFila(&filas[0]);
    printf("Numero de clientes atendidos caixa 0: %d\n", filas[0].clientesAtendidos);
    printf("Tempo medio espera dos clientes caixa 0: %d\n", filas[0].tempoMedioNaFila);

    printf("Fila caixa 1: \n");
    exibirFila(&filas[1]);
    printf("Numero de clientes atendidos caixa 1: %d\n", filas[1].clientesAtendidos);
    printf("Tempo medio espera dos clientes caixa 1: %d\n", filas[1].tempoMedioNaFila);

    printf("Fila caixa 2: \n");
    exibirFila(&filas[2]);
    printf("Numero de clientes atendidos caixa 2: %d\n", filas[2].clientesAtendidos);
    printf("Tempo medio espera dos clientes caixa 2: %d\n", filas[2].tempoMedioNaFila);

    printf("Fila caixa 3: \n");
    exibirFila(&filas[3]);
    printf("Numero de clientes atendidos caixa 3: %d\n", filas[3].clientesAtendidos);
    printf("Tempo medio espera dos clientes caixa 3: %d\n", filas[3].tempoMedioNaFila);

    printf("Quantidade total clientes atendidos: %d\n", contadorClientesAtendidos);
    printf("Quantidade total nao clientes atendidos: %d\n", contadorNaoClienteAtendidos);
    printf("Quantidade clientes nao atendidos: %d\n", numeroClientesNaoAtendidos);
    printf("Tempo medio espera dos clientes: %d\n", tempoMedioNasFilas);
    printf("Maior tempo espera: %d\n", maiorTempoEspera);

    return 0;
}
