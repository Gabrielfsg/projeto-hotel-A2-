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
#include "Categoria.h"

int cadastrarCategoriaTXT(Categoria cat) {
    FILE *cad;
    cad = fopen("arquivos\\CategoriaTXT.txt", "a");
    if (cad == NULL) {
        cad = fopen("arquivos\\CategoriaTXT.txt", "w");
        return 0;
    } else {
        fprintf(cad, "%d\n%s\n%d\n%s\n%f\n", cat.codigo, cat.descricao, cat.quantidadePessoas, cat.facilidade, cat.valorDiario); // f
        fclose(cad);
        free(cad);
    }
    return 1;
}

int salvarCategoriaTXT(Categoria *cat, int num) {
    FILE *cad;
    // w pra substituir o arquivo
    cad = fopen("arquivos\\CategoriaTXT.txt", "w");
    if (cad == NULL) {
        printf("\nErro ao abrir arquivo!!");
        return 0;
    } else {
        int i;
        // grava todos os dados do vetor no arquivo
        for (i = 0; i < num; i++) {
            fprintf(cad, "%d\n%s\n%d\n%s\n%f\n", cat[i].codigo, cat[i].descricao, cat[i].quantidadePessoas, cat[i].facilidade, cat[i].valorDiario); // f
        }
    }
    // força salvar arquivo
    fflush(cad);
    //fecha arquivo
    fclose(cad);
    //libera memoria
    free(cad);
    free(cat);
    return 1;
}

Categoria* listarCategoriaTXT() {
    int numLinha = 0, i = 0;
    FILE *arquivo;
    numLinha = numLinhas(arquivo);
    //area arquivo para leitura apenas "r"
    arquivo = fopen("arquivos\\CategoriaTXT.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao acessar arquivo\n");
    }
    //instancia vetor com tamanho de numLinha
    Categoria *cat = (Categoria*) calloc(numLinha, sizeof (Categoria));
    i = 0;
    //printf("linhas %d \n", numLinha);
    while (fscanf(arquivo, "%d", &cat[i].codigo) == 1) {
        fgetc(arquivo);
        fscanf(arquivo, "%100[a-z A-Z\n]s", cat[i].descricao);
        strtok(cat[i].descricao, "\n");
        fscanf(arquivo, "%d", &cat[i].quantidadePessoas);
        fgetc(arquivo);
        fscanf(arquivo, "%100[a-z A-Z\n]s", cat[i].facilidade);
        strtok(cat[i].facilidade, "\n");
        fscanf(arquivo, "%f", &cat[i].valorDiario);
        i++;
    }
    //fecha arquivo
    fclose(arquivo);
    //libera memoria
    free(arquivo);
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
    //libera memoria
    free(cat);
    //free(numLinha);
}

int numLinhas() {
    FILE *arquivo;
    int numLinha = 0, c;
    //abre arquivo para leitura "r"
    arquivo = fopen("arquivos\\CategoriaTXT.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao acessar arquivo\n");
    }
    //roda ate que ache o final do arquivo "EOF"
    while ((c = fgetc(arquivo)) != EOF) {
        if (c == '\n') {
            //soma a quantidade de linhas do TXT, mas não a quantidade de categorias
            numLinha++;
        }
    }
    //fecha arquivo
    fclose(arquivo);
    //libera memoria
    free(arquivo);
    // divide se por 5 pois categoria tem 5 linhas
    return numLinha / 5;
}

int validar(int cod) {
    Categoria *cat = listarCategoriaTXT();
    int lin = sizeof (*cat) / sizeof (Categoria);
    int i;
    for (i = 0; i < lin; i++) {
        if (cod == cat[i].codigo) {
            return 1;
        }
    }
    free(cat);
    return 0;
}

/*Aruivos binarios*/

int cadastrarCategoriaBIN(Categoria cat, int quantidade) {
    FILE *cad;
    cad = fopen("arquivos\\CategoriaBIN.bin", "ab");
    if (cad == NULL) {
        cad = fopen("arquivos\\CategoriaBIN.bin", "wb");
        return 0;
    } else {
        //strlen()-> informa o tamanho de uma string 
        /*grava toda struct de categoria no arquivo*/
        fwrite(&cat, sizeof (Categoria), quantidade, cad);
        fflush(cad);
        /*fecha o arquivo*/
        fclose(cad);
        /*libera mémoria*/
        free(cad);
    }
    return 1;
}

Categoria* listarCategoriaBIN(int *numLinha) {
    FILE *arquivo;
    //area arquivo para leitura apenas "rb"
    arquivo = fopen("arquivos\\CategoriaBIN.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao acessar arquivo\n");
    }
    *numLinha = 0;
    //instancia vetor com tamanho de numLinha
    Categoria c;
    Categoria *cat = (Categoria*) calloc(1, sizeof (Categoria));
    fread(&c, sizeof (Categoria), 1, arquivo);
    do {
        *numLinha = (*numLinha)+ 1;
        cat = realloc(cat, *numLinha * sizeof (Categoria));
        cat[(*numLinha) - 1] = c;
        fread(&c, sizeof (Categoria), 1, arquivo);
    } while (!feof(arquivo));
    //fecha arquivo
    fclose(arquivo);
    //libera memoria
    free(arquivo);
    return cat;
}

int editarCategoriaBIN(Categoria cat, int posi) {
    FILE *arquivo;
    //abre arquivo para leitura e escrita "wb"
    arquivo = fopen("arquivos\\CategoriaBIN.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao acessar arquivo\n");
        return 0;
    }
    //Posiciona na (posi) posição do struct
    fseek(arquivo, (posi * sizeof (Categoria)), SEEK_SET);
    //Substitui o struct de posição posi
    fwrite(&cat, sizeof (Categoria), 1, arquivo);
    //fecha arquivo 
    fclose(arquivo);
    //fclose(&cat);
    //libera memoria
    free(arquivo);
    return 1;
}
int validarCategoriaBIN(int cod) {
    int num;
    Categoria *cat = listarCategoriaBIN(&num);
    int i;
    for (i = 0; i < num; i++) {
        if (cod == cat[i].codigo) {
            return i;
        }
    }
    free(cat);
    return 0;
}

int removerCategoriaBIN() {
    int status = remove("arquivos\\CategoriaBIN.bin");
    if (status != 0) {
        printf("\nErro na remoção do arquivo.\n");
        return 0;
    }
    return 1;
}