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
    // abre o arquivo e posiciona o cursor no final
    cad = fopen("arquivos\\CategoriaTXT.txt", "a");
    if (cad == NULL) {
        // se ele não existir cria um
        cad = fopen("arquivos\\CategoriaTXT.txt", "w");
        if (cad == NULL) {
            printf("\nErro: aao cessar arquivo\n");
            return 0;
        }
    }
    // salva cada campo em uma linha
    fprintf(cad, "%d\n%s\n%d\n%s\n%f\n", cat.codigo, cat.descricao, cat.quantidadePessoas, cat.facilidade, cat.valorDiario); // f
    //fecha o arquivo
    fclose(cad);
    //libera memoria
    free(cad);

    return 1;
}
//metodo salva, sobrescrevendo o array de tamanho num

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
    numLinha = numLinhasCategoria(arquivo);
    //abrea arquivo para leitura apenas "r"
    arquivo = fopen("arquivos\\CategoriaTXT.txt", "r");
    if (arquivo == NULL) {
        //cria arquivo para leitura/escrita se não houver "w+"
        arquivo = fopen("arquivos\\CategoriaTXT.txt", "w+");
        if (arquivo == NULL) {
            printf("\nErro ao acessar arquivo categoria\n");
            return NULL;
        }
    }
    //instancia vetor com tamanho de numLinha
    Categoria *cat = (Categoria*) calloc(numLinha, sizeof (Categoria));
    i = 0;
    //printf("linhas %d \n", numLinha);
    while (fscanf(arquivo, "%d", &cat[i].codigo) == 1) {
        //retira o \n do inicio  da string
        fgetc(arquivo);
        //pega a string descrição
        fscanf(arquivo, "%100[a-z A-Z\n]s", cat[i].descricao);
        //retira o \n do fim da descrição
        strtok(cat[i].descricao, "\n");
        fscanf(arquivo, "%d", &cat[i].quantidadePessoas);
        //retira o \n do inicio da facilidade
        fgetc(arquivo);
        fscanf(arquivo, "%100[a-z A-Z\n]s", cat[i].facilidade);
        //retira o \n do fim da facilidade
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

int numLinhasCategoria() {
    FILE *arquivo;
    int numLinha = 0, c;
    //abre arquivo para leitura "r"
    arquivo = fopen("arquivos\\CategoriaTXT.txt", "r");
    if (arquivo == NULL) {
        arquivo = fopen("arquivos\\CategoriaTXT.txt", "w+");
        if (arquivo == NULL) {
            printf("Erro ao acessar arquivo\n");
            return 0;
        }
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

int validarCategoria(int cod) {
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

Categoria * listarCategoriaBIN(int *numLinha) {
    FILE *arquivo;
    //area arquivo para leitura apenas "rb"
    arquivo = fopen("arquivos\\CategoriaBIN.bin", "rb");
    if (arquivo == NULL) {
        //cria arquivo para leitura\escrita se não houver "w+b"
        arquivo = fopen("arquivos\\CategoriaBIN.bin", "w+b");
        if (arquivo == NULL) {
            printf("\nERRO ao acessar arquivo\n");
            return NULL;
        }
    }
    *numLinha = 0;

    Categoria c;
    //instancia vetor com tamanho 1 
    Categoria *cat = (Categoria*) calloc(1, sizeof (Categoria));
    //pega a primeira linha se existir
    int r = fread(&c, sizeof (Categoria), 1, arquivo);
    if (r > 0) {
        do {
            //soma a +1 no tamanho do vetor o qual comessa com 0
            *numLinha = (*numLinha) + 1;
            // realoca o vetor com o tamanho numLinha, a cada interação ele realoca um a mais
            cat = realloc(cat, *numLinha * sizeof (Categoria));
            //adicionar o struct o vetor,(numLinha -1) pois o vetor comessa sempre por 0
            cat[(*numLinha) - 1] = c;
            //pega o proximo indice, se existir
            fread(&c, sizeof (Categoria), 1, arquivo);
            //verifica se chegou no fim do arquivo
        } while (!feof(arquivo));
    }else{
        return NULL;
    }
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
    //Posiciona o cursor na posição do struct
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
            // retorna o indice se achar
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