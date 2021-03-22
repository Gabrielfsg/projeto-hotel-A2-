/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fornecedor.h"
#include"Caixa.h"
#include"Data.h"
#include"ContaPagar.h"
#include "SalvametoBD.h"

int cadastrarContaPagarTXT(ContaPagar cp) {
    FILE* arrContasPagar;

    arrContasPagar = fopen(".\\arquivos\\ContaPagarTXT.txt", "a");
    if (arrContasPagar == NULL) {
        //se não existir, cria um novo.
        arrContasPagar = fopen(".\\arquivos\\ContaPagarTXT.txt", "w");
        if (arrContasPagar == NULL) {
            printf("ERRO DE ABERTURA\n");
        }
    } else {

        int retorno = 0;
        retorno = fprintf(arrContasPagar, "%d\r\n%d\r\n%d\r\n%d\r\n%d\r\n%d\r\n%d\r\n%d\r\n%d\r\n%s\r\n%s\r\n%.2f\r\n", cp.codigo, cp.caixa.codigo, cp.caixa.data.dia, cp.caixa.data.mes, cp.caixa.data.ano, cp.codForn, cp.data.dia, cp.data.mes, cp.data.ano, cp.descricao, cp.status, cp.valor);
        fflush(arrContasPagar);
        fclose(arrContasPagar);
        return retorno;
    }
}

int cadastrarContaPagarBIN(ContaPagar *conta, int quantidade) {
    printf("DEBUG: CAD CONTA PAGAR\n");
    FILE *cad;

    cad = fopen("arquivos\\ContaPagarBIN.bin", "ab");
    if (cad == NULL) {

        cad = fopen("arquivos\\ContaPagarBIN.bin", "wb");
        return 0;
    } else {
        //strlen()-> informa o tamanho de uma string 
        /*grava toda struct de contaPagar no arquivo*/
        fwrite(conta, sizeof (ContaPagar), quantidade, cad);
        fflush(cad);
        /*fecha o arquivo*/
        fclose(cad);
        /*libera mémoria*/
        free(cad);
    }
    return 1;
}

ContaPagar* listarContaPagarTXT(int numContasPagar) {
    int index = 1; //ÍNDICE DO ARRAY

    ContaPagar *arrayContasPagar = (ContaPagar *) malloc(sizeof (ContaPagar) * numContasPagar); //Ponteiro de Hóspedes vira um Array ao chamar malloc
    if (arrayContasPagar == NULL) {
        printf("ERRO DE ALOCAÇÃO");
        exit(EXIT_FAILURE);
    }

    FILE *scanContasPagar;

    scanContasPagar = fopen(".\\arquivos\\ContaPagarTXT.txt", "r");
    if (scanContasPagar == NULL) {
        printf("ERRO DE LEITURA, UM NOVO ARQUIVO SERÁ CRIADO\n");
        scanContasPagar = fopen(".\\arquivos\\ContaPagarTXT.txt", "w");
        if (scanContasPagar == NULL) {
            printf("ERRO DE LEITURA\n");
            return;
        }


    } else {
        //pega os hóspedes do arquivo
        for (int i = 0; i < numContasPagar; i++) {
            ContaPagar cp;

            fscanf(scanContasPagar, "%d", &cp.codigo);
            fscanf(scanContasPagar, "%d", &cp.caixa.codigo);
            fscanf(scanContasPagar, "%d", &cp.caixa.data.dia);
            fscanf(scanContasPagar, "%d", &cp.caixa.data.mes);
            fscanf(scanContasPagar, "%d", &cp.caixa.data.ano);
            fscanf(scanContasPagar, "%d", &cp.codForn);
            fscanf(scanContasPagar, "%d", &cp.data.dia);
            fscanf(scanContasPagar, "%d", &cp.data.mes);
            fscanf(scanContasPagar, "%d", &cp.data.ano);
            fscanf(scanContasPagar, "%s", cp.descricao);
            //strtok(cp.descricao, "\r\n");
            //printf("++++++++++++++ DESCRICAO -> %s\n",cp.descricao);
            fscanf(scanContasPagar, "%s", cp.status);
            //printf("++++++++++++++ STATUS -> %s\n",cp.status);
            //fscanf(scanContasPagar, "[^\n]%s", cp.status);
            //strtok(cp.descricao, "\r\n");
            fscanf(scanContasPagar, "%f", &cp.valor);

            //COLOCA  NO ARRAY
            arrayContasPagar[index - 1] = cp;
            index++;
        }
        fclose(scanContasPagar);

        return arrayContasPagar;
    }
}

ContaPagar* listarContaPagarBIN(int* numContasPagar) {
    //printf("DEBUG: ENTROU NO LISTAR CONTA PAGAR\n");
    int totalLido = 0;
    int index = 0;
    ContaPagar *arrayContasPagar = (ContaPagar *) malloc(sizeof (ContaPagar) * 1); //PONTEIRO DE PRODUTOS VIRA UM VETOR AO CHAMAR MALLOC
    if (arrayContasPagar == NULL) {
        printf("ERRO DE ALOCAÇÃO");
        exit(1);
    }

    FILE *arqContaspg;
    //abre o arquivo, ou cria um novo se nao conseguir abrir
    arqContaspg = fopen(".\\arquivos\\ContaPagarBIN.bin", "rb");
    if (arqContaspg == NULL) {
        arqContaspg = fopen(".\\arquivos\\ContaPagarBIN.bin", "wb");
        if (arqContaspg == NULL) {
            printf("ERRO DE LEITURA ");
        }
    } else {

        while (!feof(arqContaspg)) { //enquanto não for o final do arquivo
            ContaPagar cp;
            //lê um produto do arquivo e incrementa o número de contas
            int conseguiuLer = fread(&cp, sizeof (ContaPagar), 1, arqContaspg);
            if (conseguiuLer == 1) {
                //printf("LEU UMA CONTA PAGAR\n");
                (*numContasPagar)++;
            } else {
                //printf("ERRO\n");
            }
            arrayContasPagar[index] = cp;
            index++;
            //realoca o vetor
            arrayContasPagar = realloc(arrayContasPagar, (index + 1) * sizeof (ContaPagar));
            //printf("INDEX = %d\n", index);
        }

        fclose(arqContaspg);

        return arrayContasPagar;
    }
}

void mostrarContasPagar() {
    int bd = listar();
    ContaPagar* arrayCP;
    int numContas = 0;
    if (bd == 1) {
        numContas = getNumContaPagar();
        printf("DEBUG: O NUM DE CONTAS A PAGAR É %d\n", numContas);
        arrayCP = listarContaPagarTXT(numContas);
    }
    if (bd == 2) {
        arrayCP = listarContaPagarBIN(&numContas);
    }
    printf("O NÚMERO DE CONTAS É: %d\n", numContas);
    for (int i = 0; i < numContas; i++) {
        printf("********** %d  **********\n", i + 1);
        printf("CÓDIGO: = %d\n", arrayCP[i].codigo);
        printf("CÓDIGO FORNECEDOR: = %d\n", arrayCP[i].codForn);
        printf("DATA: %d / %d / %d \n", arrayCP[i].data.dia, arrayCP[i].data.mes, arrayCP[i].data.ano);
        printf("DESC = %s\n", arrayCP[i].descricao);
        printf("STATUS = %s\n", arrayCP[i].status);
        printf("VALOR = %.2f\n", arrayCP[i].valor);

    }
}

float somaContaPagarCaixa(Data data) {
    printf("DEBUG: ENTROU NO SOMA CONTA\n");
    float valor = 0;
    //ContaReceber *caiaaa;
    ContaPagar *cai;
    int num;
    int bd = listar();
    if (bd == 1) {
        cai = listarContaReceberTXT();
        num = numContaReceber();
    } else {
        printf("DEBUG: ENTROU NO ELSE\n");
        cai = listarContaPagarBIN(&num);
    }
    int i;
    for (i = 0; i < num; i++) {
        if (compararDatas(cai[i].data, data) == 1) {
            valor += cai[i].valor;
        }
    }
    return valor;

}

int maiorCodContasPagar() {
    int bd = listar();
    ContaPagar* arrContaPagar;
    int numContas = 0;
    if (bd == 1) {

    }
    if (bd == 2) {
        arrContaPagar = listarContaPagarBIN(&numContas);
    }

    int maior = 0;

    for (int i = 0; i < numContas; i++) {
        printf("O COD DA CONTA É: %d\n", arrContaPagar[i].codigo);
        if (arrContaPagar[i].codigo > maior) {
            maior = arrContaPagar[i].codigo;
        }
    }

    printf("O MAIR COD É: %d\n", maior);
    return maior;
}

int getNumContaPagar() {
    printf("DEBUG: ENTROU GET NUM CONTA PAGAR\n");

    FILE *arq;
    int numLinhas = 0, numContas = 0;
    char c;
    //tenta abrir o arquivo, se não conseguir cria um novo.
    arq = fopen(".\\arquivos\\ContaPagarTXT.txt", "r");
    if (arq == NULL) {
        arq = fopen(".\\arquivos\\ContaPagarTXT.txt", "w");
        if (arq == NULL) {
            printf("ERRO AO ACESSAR ARQUIVO");
        }
        return 0;
    }
    //enquando nao for o fim do arquivo...
    while ((c = fgetc(arq)) != EOF) {
        //procura pelo caracter de quebra de linha.
        if (c == '\n') {
            numLinhas++;
        }
    }

    numContas = numLinhas / 12; // uma conta Pagar gasta 12 linhas no arquivo

    printf("O NÚMERO DE LINHAS DO ARQ É: %d\n", numLinhas);
    printf("O NÚMERO DE CONTAS CADASTRADOS É: %d\n", numContas);
    fclose(arq);
    free(arq);
    return numContas;

}