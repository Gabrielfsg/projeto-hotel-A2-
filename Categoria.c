/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Categoria.c
 * Author: Daniel
 *
 * Created on 6 de Janeiro de 2021, 23:14
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//int numLinhas(FILE *arquivo);
//void mostrar(Categoria cat, int numLinha);

typedef struct categoria {
    int codigo;
    char descricao[100];
    float valorDiario;
    int quantidadePessoas;
    char facilidade[];
} Categoria;

Categoria* newCategoria(int codig, char descricao[], float valorDiario, int qtd, char facilidade[]) {
    Categoria* cat = (Categoria *) calloc(1, sizeof (Categoria));
    cat->codigo = codig;
    strcpy(cat->descricao, descricao);
    strcpy(cat->facilidade, facilidade);
    cat->quantidadePessoas = qtd;
    cat->valorDiario = valorDiario;
}

void add(Categoria *cat, int posicao, int codig, char descricao[], float valorDiario, int qtd, char facilidade[]) {
    cat->codigo = codig;
    strcpy(cat->descricao, descricao);
    strcpy(cat->facilidade, facilidade);
    cat->quantidadePessoas = qtd;
    cat->valorDiario = valorDiario;
}

void cadastrarCategoriaTXT(int codig, char descricao[], float valorDiario, int qtd, char facilidade[]) {
    FILE *cad;
    int i;
    cad = fopen("arquivos\\CategoriaTXT.txt", "a");
    if (cad == NULL) {
        cad = fopen("arquivos\\CategoriaTXT.txt", "w");
    } else {
        // escreve cada elemento do vetor no arquivo
        fprintf(cad, "%d\r\n%s\r\n%d\r\n%s\r\n%f\r\n", codig, descricao, qtd, facilidade, valorDiario); // f
        fflush(cad);
        fclose(cad);
    }
}

Categoria* listarCategoriaTXT() {
    int numLinha = 0, i = 0;
    FILE *arquivo;
    //numLinha = numLinhas(arquivo);
    arquivo = fopen("arquivos\\CategoriaTXT.txt", "rt");
    if (arquivo == NULL) {
        printf("Erro ao acessar arquivo\n");
    }
    Categoria *cat = (Categoria*) calloc(numLinha, sizeof (Categoria));
    i = 0;
    //printf("linhas %d \n", numLinha);
    while (fscanf(arquivo, "%d", &cat[i].codigo) == 1) {
        fgetc(arquivo);
        fscanf(arquivo, "%100[a-z A-Z\n]s", cat[i].descricao);
        fscanf(arquivo, "%d", &cat[i].quantidadePessoas);
        fgetc(arquivo);
        fscanf(arquivo, "%100[a-z A-Z\n]s", cat[i].facilidade);
        fscanf(arquivo, "%f", &cat[i].valorDiario);
        i++;
    }
    fclose(arquivo);
    return cat;
}

void mostrar(Categoria *cat, int numLinha) {
    int i;
    for (i = 0; i < numLinha; i++) {
        printf("cod : %d\n", cat[i].codigo);
        printf("descicao :");
        printf("%s", cat[i].descricao);
        printf("facilidade :");
        printf("%s", cat[i].facilidade);
        printf("QUANTIDADE DE PESSOAS : %d\n", cat[i].quantidadePessoas);
        printf("Valor Diaria: %f \n", cat[i].valorDiario);
    }
}

int numLinhas() {
    FILE *arquivo;
    int numLinha = 0, c;
    arquivo = fopen("arquivos\\CategoriaTXT.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao acessar arquivo\n");
    }
    while ((c = fgetc(arquivo)) != EOF) {
        //printf("linhas %d \n",numLinha);
        if (c == '\n') {
            numLinha++;
        }
    }
    fclose(arquivo);
    return numLinha / 5;
}
int validar(int cod) {
    Categoria *cat = listarCategoriaTXT();
    int lin = numLinhas();
    int i;
    for (i = 0; i < lin; i++) {
        if (cod == cat[i].codigo) {
            return 1;
        }
    }
    return 0;
}

