/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Produto.h"
#include "ProdutoConsumoMenu.h"

int cadastrarProdutoTXT(Produto p) {
    FILE* arqProduto;
    arqProduto = fopen(".\\arquivos\\produtos.txt", "a");
    if (arqProduto == NULL) {
        arqProduto = fopen(".\\arquivos\\produtos.txt", "w");
    }
    int retorno;
    retorno = fprintf(arqProduto, "Cod: %d\r\nDESC: %s\r\nESTOQUE: %d\r\nESTOQUE_MIN: %d\r\nPRCUSTO: %f\r\nPRVENDA: %f\r\n", p.codigo, p.descricao, p.estoque, p.estoqueMinimo, p.precoCusto, p.precoVenda);

    fflush(arqProduto);
    fclose(arqProduto);
    return retorno;

}

int cadastrarProdutoBIN(Produto p) {
    FILE* arqProduto;
    arqProduto = fopen(".\\arquivos\\produtos.bin", "ab");
    if (arqProduto == NULL) {
        printf("ERRO DE ABERTURA\n");
    } else {
        int count = 0;
        count = fwrite(&p, sizeof (Produto), 1, arqProduto);

        fflush(arqProduto);
        /*fecha o arquivo*/
        fclose(arqProduto);
        /*libera mémoria*/
        free(arqProduto);
        fclose(arqProduto);
        return count;
    }
}

void atualizarProdutoTXT(Produto novoProd) {
    //printf("ENTROU ATUALIZAR PROD\n");
    FILE* arqProduto = fopen(".\\arquivos\\produtos_temp.txt", "w");
    if (arqProduto == NULL) {
        printf("ERRO AO ABRIR ARQUIVO");
    } else {
        int numProdutos = getNumProdConsumo();
        Produto* arrProduto = getAllProdutoTXT(numProdutos);

        for (int i = 0; i < numProdutos; i++) {
            if (arrProduto[i].codigo != novoProd.codigo) {
                //printf("%d != %d\n", arrProduto[i].codigo, novoProd.codigo);
                strtok(novoProd.descricao, "\r");
                fprintf(arqProduto, "Cod: %d\r\nDESC: %s\nESTOQUE: %d\r\nESTOQUE_MIN: %d\r\nPRCUSTO: %f\r\nPRVENDA: %f\r\n", arrProduto[i].codigo, arrProduto[i].descricao, arrProduto[i].estoque, arrProduto[i].estoqueMinimo, arrProduto[i].precoCusto, arrProduto[i].precoVenda);
                fflush(arqProduto);

            } else {
                //printf("ESSE É O QUE VAI ALTERAR: COD = %d\n", novoProd.codigo);
                //strtok(novoProd.descricao, "\r");
                fprintf(arqProduto, "Cod: %d\r\nDESC: %s\r\nESTOQUE: %d\r\nESTOQUE_MIN: %d\r\nPRCUSTO: %f\r\nPRVENDA: %f\r\n", novoProd.codigo, novoProd.descricao, novoProd.estoque, novoProd.estoqueMinimo, novoProd.precoCusto, novoProd.precoVenda);
                fflush(arqProduto);
            }
        }

        fclose(arqProduto);
        free(arrProduto);
        remove(".\\arquivos\\produtos.txt");
        rename(".\\arquivos\\produtos_temp.txt", ".\\arquivos\\produtos.txt");
    }

}

void atualizarProdutoBIN(Produto novoProd) {
    FILE* arqProduto = fopen(".\\arquivos\\produtos_temp.bin", "wb");
    if (arqProduto == NULL) {
        printf("ERRO AO ABRIR ARQUIVO");
    } else {
        int numProdutos = 0;
        Produto* arrProdutos = getAllProdutoBIN(&numProdutos);

        for (int i = 0; i < numProdutos; i++) {
            if (arrProdutos[i].codigo != novoProd.codigo) {
                //printf("ESSE É O QUE NAO VAI ALTERAR %d != %d\n", arrProdutos[i].codigo, novoProd.codigo);
                fwrite(&arrProdutos[i], sizeof (Produto), 1, arqProduto);
                fflush(arqProduto);

            } else {
                //printf("ESSE É O QUE VAI ALTERAR: COD = %d\n", novoProd.codigo);
                fwrite(&novoProd, sizeof (Produto), 1, arqProduto);
                fflush(arqProduto);
            }
        }

        fclose(arqProduto);
        free(arrProdutos);
        remove(".\\persist\\hospedes.bin");
        rename(".\\persist\\hospedes_temp.bin", ".\\persist\\hospedes.bin");
    }

}

Produto* getAllProdutoTXT(int numProdutos) {
    //printf("ENTROU GETALL TXT\n");
    //printf("NUM PROD = %d\n", numProdutos);
    int index = 1; //PARA ARMAZENAR O TAMANHO DO VETOR

    Produto *arrayProdutos = (Produto *) malloc(sizeof (Produto) * numProdutos); //PONTEIRO DE HÓSPEDE VIRA UM VETOR AO CHAMAR MALLOC
    if (arrayProdutos == NULL) {
        printf("ERRO DE ALOCAÇÃO");
        exit(1);
    }

    //pega a lista de hóspedes do arquivo
    FILE *arqProduto;

    arqProduto = fopen(".\\arquivos\\produtos.txt", "r");
    if (arqProduto == NULL) {
        printf(" ERRO DE LEITURA ");
    } else {

        for (int i = 0; i < numProdutos; i++) {
            Produto p;
            char text[20];

            //FSCANF PARA PEGAR OS VALORES DO ARQUIVO. "TEXT[20]" É APENAS PARA ARMAZENAR A STRING QUE VEM ANTES DO VALOR.
            fscanf(arqProduto, "%s %d", text, &p.codigo);
            fscanf(arqProduto, "%s %[^\n]s", text, p.descricao);
            fscanf(arqProduto, "%s %d", text, &p.estoque);
            fscanf(arqProduto, "%s %d", text, &p.estoqueMinimo);
            fscanf(arqProduto, "%s %f", text, &p.precoCusto);
            fscanf(arqProduto, "%s %f", text, &p.precoVenda);

            //COLOCA O PRODUTO NO ARRAY
            arrayProdutos[index - 1] = p;
            index++;
        }
        fclose(arqProduto);

        /*printf("\n TESTE PARA VER TODOS OS ITENS DO ARRAY \n");
        for (int i = 0; i < index - 1; i++) {
            printf("+++++++++++\n");
            printf("POS: %d -> %d\n", i, arrayProdutos[i].codigo);
            printf("POS: %d -> %s\n", i, arrayProdutos[i].descricao);
            printf("POS: %d -> %d\n", i, arrayProdutos[i].estoque);
            printf("POS: %d -> %d\n", i, arrayProdutos[i].estoqueMinimo);
            printf("POS: %d -> %f\n", i, arrayProdutos[i].precoCusto);
            printf("POS: %d -> %f\n", i, arrayProdutos[i].precoVenda);
            printf("+++++++++++\n");
        }*/
        return arrayProdutos;
    }
}

Produto* getAllProdutoBIN(int* numProdutos) {

    int totalLido = 0;
    int index = 0;
    Produto *arrayProdutos = (Produto *) malloc(sizeof (Produto) * 1); //PONTEIRO DE HÓSPEDE VIRA UM VETOR AO CHAMAR MALLOC
    if (arrayProdutos == NULL) {
        printf("ERRO DE ALOCAÇÃO");
        exit(1);
    }

    FILE *arqProduto;

    arqProduto = fopen(".\\arquivos\\produtos.bin", "rb");
    if (arqProduto == NULL) {
        arqProduto = fopen(".\\arquivos\\produtos.bin", "wb");
        if (arqProduto == NULL) {
            printf("ERRO DE LEITURA ");
        }
    } else {

        while (!feof(arqProduto)) { //enquanto não for o final do arquivo
            Produto p;
            int conseguiuLer = fread(&p, sizeof (Produto), 1, arqProduto);
            if (conseguiuLer == 1) {
                //printf("LEU UM PRODUTO\n");
                (*numProdutos)++;
            } else {
                //printf("ERRO\n");
            }
            arrayProdutos[index] = p;
            index++;
            arrayProdutos = realloc(arrayProdutos, (index + 1) * sizeof (Produto));
            //printf("INDEX = %d\n", index);
        }

        fclose(arqProduto);

        return arrayProdutos;
    }
}

Produto getProdutoByCodTXT(int cod, int numProdutos) {

    Produto* arrayProdutos = getAllProdutoTXT(numProdutos);
    for (int i = 0; i < numProdutos; i++) {
        if (arrayProdutos[i].codigo == cod) {
            //printf("\nACHOU O COD == AO QUE DIGITOU: %d == %s\n",cod,arrHospedes[i].nome);
            return arrayProdutos[i];
        }
    }
}

Produto getProdutoByCodBIN(int cod) {
    //printf("ENTROU GETHOSPEDEBYCOD BIN");
    Produto prod;
    int numProdutos = 0;
    Produto* arrayProdutos = getAllProdutoBIN(&numProdutos);
    for (int i = 0; i < numProdutos; i++) {
        if (arrayProdutos[i].codigo == cod) {
            //printf("COD %d == %d\n", arrayProdutos[i].codigo, cod);
            prod = arrayProdutos[i];
            return prod;
        }
    }
}

void deletarProdutoTXT(int cod) {
    FILE* arqProduto = fopen(".\\arquivos\\produtos_temp.txt", "w");
    if (arqProduto == NULL) {
        printf("ERRO");
    } else {
        int numProdutos = getNumProdConsumo();
        Produto* arrayProdutos = getAllProdutoTXT(numProdutos);

        for (int i = 0; i < numProdutos; i++) {
            if (arrayProdutos[i].codigo != cod) {

                strtok(arrayProdutos[i].descricao, "\r");
                fprintf(arqProduto, "Cod: %d\r\nDESC: %s\r\nESTOQUE: %d\r\nESTOQUE_MIN: %d\r\nPRCUSTO: %f\r\nPRVENDA: %f\r\n", arrayProdutos[i].codigo, arrayProdutos[i].descricao, arrayProdutos[i].estoque, arrayProdutos[i].estoqueMinimo, arrayProdutos[i].precoCusto, arrayProdutos[i].precoVenda);
                fflush(arqProduto);

            }
        }

        fclose(arqProduto);
        free(arrayProdutos);
        remove(".\\arquivos\\produtos.txt");
        rename(".\\arquivos\\produtos_temp.txt", ".\\arquivos\\produtos.txt");
    }
}

void deletarProdutoBIN(int cod) {
    FILE* arqProduto = fopen(".\\arquivos\\produtos_temp.bin", "wb");
    if (arqProduto == NULL) {
        printf("ERRO");
    } else {
        int numProdutos = 0;
        Produto* arrayProdutos = getAllProdutoBIN(&numProdutos);

        for (int i = 0; i < numProdutos; i++) {
            if (arrayProdutos[i].codigo != cod) {
                Produto p = arrayProdutos[i];

                fwrite(&p, sizeof (Produto), 1, arqProduto);

            } else {
                //Produto p2 = arrayProdutos[i];

            }

        }

        fclose(arqProduto);
        free(arrayProdutos);
        remove(".\\arquivos\\produtos.bin");
        rename(".\\arquivos\\produtos_temp.bin", ".\\arquivos\\produtos.bin");
    }
}
