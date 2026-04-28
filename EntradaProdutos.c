/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include "SalvametoBD.h"
#include "EntradaProdutos.h"

int cadastrarNotaFiscalEntradaTXT(NotaFiscalEntrada nota) {
    printf("DEBUG: ENTROU NO CADASTRO NOTA FISCAL TXT\n");
    FILE *arq;
    // abre o arquivo com o cursor no final
    arq = fopen("arquivos\\EntradaProdutos.txt", "a");
    if (arq == NULL) {
        // se ele não existir cria um
        arq = fopen("arquivos\\EntradaProdutos.txt", "w");
        if (arq == NULL) {
            printf("\nErro ao acessar arquivo\n");
            return 0;
        }
    }
    // salva cada campo em uma linha
    fprintf(arq, "%d\r\n%d\r\n%d\r\n%d\r\n%s\r\n%s\r\n%d\r\n%f\r\n%f\r\n%f\r\n",
            nota.dataNota.dia, nota.dataNota.mes, nota.dataNota.ano, nota.codCaixa, nota.nomeForn, nota.cnpjForn,
            nota.qteProds, nota.prFrete, nota.imposto, nota.total);
    for (int i = 0; i < nota.qteProds; i++) {
        fprintf(arq, "%d ", nota.produtosComprados[i].codigo);
    }
    fprintf(arq, "\r\n");
    for (int i = 0; i < nota.qteProds; i++) {
        fprintf(arq, "%d ", nota.arrayQtes[i]);
    }
    fprintf(arq, "\r\n");
    //fecha o arquivo
    fclose(arq);
    //libera memoria
    free(arq);
    return 1;
}

void cadastrarNotaFiscalEntradaBIN(NotaFiscalEntrada nota) {
    printf("DEBUG: ENTROU NO CADASTRO NOTA FISCAL BIN\n");
    FILE* arqEntradaProdutos;
    //abre o arquivo de hospedes.bin
    arqEntradaProdutos = fopen(".\\arquivos\\EntradaProdutos.bin", "ab");
    if (arqEntradaProdutos == NULL) {
        //se não existir, cria um novo.
        arqEntradaProdutos = fopen(".\\arquivos\\EntradaProdutos.bin", "wb");
        if (arqEntradaProdutos == NULL) {
            printf("ERRO DE ABERTURA\n");
        }

    } else {
        int count = 0; //variavel para validar se gravou ou não
        //grava no arquivo binário
        count = fwrite(&nota, sizeof (NotaFiscalEntrada), 1, arqEntradaProdutos);
        fflush(arqEntradaProdutos);
        //fecha o arquivo
        fclose(arqEntradaProdutos);
        //libera mémoria
        free(arqEntradaProdutos);
        fclose(arqEntradaProdutos);
        //return count;
    }
}

NotaFiscalEntrada* listarNotaFiscalEntradaBIN(int* numNotas) {

    int totalLido = 0;
    int index = 0;
    NotaFiscalEntrada *arrayNotas = (NotaFiscalEntrada *) malloc(sizeof (NotaFiscalEntrada) * 1); //PONTEIRO DE PRODUTOS VIRA UM VETOR AO CHAMAR MALLOC
    if (arrayNotas == NULL) {
        printf("ERRO DE ALOCAÇÃO");
        exit(1);
    }

    FILE *arqNotas;
    //abre o arquivo, ou cria um novo se nao conseguir abrir
    arqNotas = fopen(".\\arquivos\\EntradaProdutos.bin", "rb");
    if (arqNotas == NULL) {
        arqNotas = fopen(".\\arquivos\\EntradaProdutos.bin", "wb");
        if (arqNotas == NULL) {
            printf("ERRO DE LEITURA ");
        }
    } else {

        while (!feof(arqNotas)) { //enquanto não for o final do arquivo
            NotaFiscalEntrada nota;
            //lê um produto do arquivo e incrementa o número de produtos
            int conseguiuLer = fread(&nota, sizeof (NotaFiscalEntrada), 1, arqNotas);
            if (conseguiuLer == 1) {
                printf("LEU UMA NOTA\n");
                (*numNotas)++;
            } else {
                //printf("ERRO\n");
            }
            arrayNotas[index] = nota;
            index++;
            //realoca o vetor
            arrayNotas = realloc(arrayNotas, (index + 1) * sizeof (NotaFiscalEntrada));
            //printf("INDEX = %d\n", index);
        }

        fclose(arqNotas);

        return arrayNotas;
    }
}

NotaFiscalEntrada* listarNotaFiscalEntradaTXT(int numNotas) {
    int index = 1; //PARA ARMAZENAR O TAMANHO DO VETOR

    NotaFiscalEntrada *arrayNotas = (NotaFiscalEntrada *) malloc(sizeof (NotaFiscalEntrada) * numNotas); //PONTEIRO DE HÓSPEDE VIRA UM VETOR AO CHAMAR MALLOC
    if (arrayNotas == NULL) {
        printf("ERRO DE ALOCAÇÃO");
        exit(1);
    }

    //pega a lista de Produtos do arquivo
    FILE *arqNotas;

    arqNotas = fopen(".\\arquivos\\EntradaProdutos.txt", "r");
    if (arqNotas == NULL) {
        printf(" ERRO DE LEITURA ");
    } else {

        for (int i = 0; i < numNotas; i++) {
            NotaFiscalEntrada nota;

            fscanf(arqNotas, "%d", &nota.dataNota.dia);
            printf("LEU O DIA: %d\n",nota.dataNota.dia);
            fscanf(arqNotas, "%d", &nota.dataNota.mes);
            printf("LEU O MES: %d\n",nota.dataNota.mes);
            fscanf(arqNotas, "%d", &nota.dataNota.ano);
            printf("LEU O ANO: %d\n",nota.dataNota.ano);
            fscanf(arqNotas, "%d", nota.codCaixa);
            printf("LEU O CAIXA: %d\n",nota.codCaixa);
            fscanf(arqNotas, "%[^\n]s", nota.nomeForn);
            printf("LEU O NOME FORN: %s\n",nota.nomeForn);
            fscanf(arqNotas, "%s", nota.cnpjForn);
            printf("LEU O NOME FORN: %s\n",nota.cnpjForn);
            fscanf(arqNotas, "%d", &nota.qteProds);
            printf("LEU A QTE: %d\n",nota.qteProds);
            fscanf(arqNotas, "%f", &nota.prFrete);
            printf("LEU O FRETE: %f\n",nota.prFrete);
            fscanf(arqNotas, "%f", &nota.imposto);
            printf("LEU O IMPOSTO: %f\n",nota.imposto);
            fscanf(arqNotas, "%f", &nota.total);
            printf("LEU O TOTAL: %f\n",nota.total);

            for (int i = 0; i < nota.qteProds; i++) {
                fscanf(arqNotas, "%d ", &nota.produtosComprados[i].codigo);
            }
            for (int i = 0; i < nota.qteProds; i++) {
                fscanf(arqNotas, "%d ", &nota.arrayQtes[i]);
            }


            arrayNotas[index - 1] = nota;
            index++;
        }
        fclose(arqNotas);


        return arrayNotas;
    }
}


int numLinhasNotaFiscal() {

    FILE *arquivo;
    int numLinha = 0, c;
    //abre arquivo para leitura "r"
    arquivo = fopen("arquivos\\EntradaProdutos.txt", "r");
    if (arquivo == NULL) {
        arquivo = fopen("arquivos\\EntradaProdutos.txt", "w+");
        if (arquivo == NULL) {
            printf("\nErro ao acessar arquivo\n");
            return 0;
        }
    }
    //roda ate que ache o final do arquivo "EOF"
    while ((c = fgetc(arquivo)) != EOF) {
        if (c == '\n') {
            numLinha++;
        }
    }
    //fecha arquivo
    fclose(arquivo);
    //libera memoria
    free(arquivo);
    
    return (numLinha / 12);
}