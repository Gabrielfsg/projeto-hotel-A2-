/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Data.h"
#include "Caixa.h"
#include "ContaReceber.h"
#include "Venda.h"

int cadastrarVendaTXT(Venda v) {
    printf("DEBUG: ENTROU CADASTRAR VENDA TXT\n");
    FILE* arVenda;
    //abre o arquivo de hospedes.txt
    arVenda = fopen(".\\arquivos\\vendas.txt", "a");
    if (arVenda == NULL) {
        //se não existir, cria um novo.
        arVenda = fopen(".\\arquivos\\vendas.txt", "w");
        if (arVenda == NULL) {
            printf("ERRO DE ABERTURA\n");
        }
    } else {
        int retorno = 1;
        //grava os dados do hóspede no arquivo

        fprintf(arVenda, "%d\r\n%d\r\n%d\r\n%d\r\n%d\r\n%f\r\n", v.codVenda, v.codCaixa, v.dataVenda.dia, v.dataVenda.mes, v.dataVenda.ano, v.valorTotal);

        fflush(arVenda);
        fclose(arVenda);
        return retorno;
    }
}

int cadastrarVendaBIN(Venda v) {
    FILE* arqVendas;
    //abre o arquivo de venda.bin
    arqVendas = fopen(".\\arquivos\\vendas.bin", "ab");
    if (arqVendas == NULL) {
        //se não existir, cria um novo.
        arqVendas = fopen(".\\arquivos\\vendas.bin", "wb");
        if (arqVendas == NULL) {
            printf("ERRO DE ABERTURA\n");
        }

    } else {
        int count = 0; //variavel para validar se gravou ou não
        //grava no arquivo binário
        count = fwrite(&v, sizeof (Venda), 1, arqVendas);
        fflush(arqVendas);
        //fecha o arquivo
        fclose(arqVendas);
        //libera mémoria
        free(arqVendas);
        fclose(arqVendas);
        return count;
    }
}

int maiorCodVenda() {
    int bd = listar();
    int num;
    Venda *venda;
    if (bd == 1) {
        num = numVendas();
        if (num > 0) {
            venda = listarVendaTXT();
        } else {
            return 0;
        }
    } else {
        venda = listarVendaBIN(&num);
        if (num == 0) {
            return 0;
        }
    }
    int i, aux = 0;
    for (i = 0; i < num; i++) {
        if (venda[i].codVenda > aux) {
            aux = venda[i].codVenda;
        }
    }
    return aux;
}

Venda* listarVendaTXT(int numVendas) {
    int index = 1; //PARA ARMAZENAR O TAMANHO DO VETOR

    Venda *arrayVendas = (Venda *) malloc(sizeof (Venda) * numVendas); //PONTEIRO DE HÓSPEDE VIRA UM VETOR AO CHAMAR MALLOC
    if (arrayVendas == NULL) {
        printf("ERRO DE ALOCAÇÃO");
        exit(1);
    }

    //pega a lista de VENDAS do arquivo
    FILE *arqVenda;

    arqVenda = fopen(".\\arquivos\\vendas.txt", "r");
    if (arqVenda == NULL) {
        printf(" ERRO DE LEITURA ");
    } else {
        for (int i = 0; i < numVendas; i++) {
            Venda v;
            
            //FSCANF PARA PEGAR OS VALORES DO ARQUIVO. "TEXT[20]" É APENAS PARA ARMAZENAR A STRING QUE VEM ANTES DO VALOR.
            fscanf(arqVenda, "%d", &v.codVenda);
            fscanf(arqVenda, "%d", &v.codCaixa);
            fscanf(arqVenda, "%d", &v.dataVenda.dia);
            fscanf(arqVenda, "%d", &v.dataVenda.mes);
            fscanf(arqVenda, "%d", &v.dataVenda.ano);
            fscanf(arqVenda, "%f", &v.valorTotal);

            //COLOCA O PRODUTO NO ARRAY
            arrayVendas[index - 1] = v;
            index++;
            
        }
        fclose(arqVenda);
        return arrayVendas;
    }
}

Venda* listarVendaBIN(int *numVendas) {

    int totalLido = 0;
    int index = 0;
    Venda *arrayVenda = (Venda *) malloc(sizeof (Venda) * 1); //PONTEIRO DE PRODUTOS VIRA UM VETOR AO CHAMAR MALLOC
    if (arrayVenda == NULL) {
        printf("ERRO DE ALOCAÇÃO");
        exit(1);
    }

    FILE *arqProduto;
    //abre o arquivo, ou cria um novo se nao conseguir abrir
    arqProduto = fopen(".\\arquivos\\vendas.bin", "rb");
    if (arqProduto == NULL) {
        arqProduto = fopen(".\\arquivos\\vendas.bin", "wb");
        if (arqProduto == NULL) {
            printf("ERRO DE LEITURA ");
        }
    } else {

        while (!feof(arqProduto)) { //enquanto não for o final do arquivo
            Venda v;
            //lê uma venda do arquivo e incrementa o número de vendas
            int conseguiuLer = fread(&v, sizeof (Venda), 1, arqProduto);
            if (conseguiuLer == 1) {
                //printf("LEU UMA VENDA\n");
                (*numVendas)++;
            } else {
                //printf("ERRO\n");
            }
            arrayVenda[index] = v;
            index++;
            //realoca o vetor
            arrayVenda = realloc(arrayVenda, (index + 1) * sizeof (Venda));
            //printf("INDEX = %d\n", index);
        }

        fclose(arqProduto);

        return arrayVenda;
    }

}

int numVendas() {
    //printf("DEBUG: ENTROU NUM VENDA\n");
    FILE *arquivo;
    int numLinha = 0, c;
    //abre arquivo para leitura "r"
    arquivo = fopen("arquivos\\vendas.txt", "r");
    if (arquivo == NULL) {
        arquivo = fopen("arquivos\\vendas.txt", "w+");
        if (arquivo == NULL) {
            printf("\nErro ao acessar arquivo\n");
            return 0;
        }
    }
    //roda ate que ache o final do arquivo "EOF"
    while ((c = fgetc(arquivo)) != EOF) {
        if (c == '\n') {
            //soma a quantidade de linhas do TXT
            numLinha++;
        }
    }
    //fecha arquivo
    fclose(arquivo);
    //libera memoria
    free(arquivo);
    //printf("DEBUG: O NUM DE LINHAS É: %d\n", numLinha);
    //printf("DEBUG: O NUM DE VENDAS É: %d\n", numLinha / 6);
    return numLinha / 6;
}