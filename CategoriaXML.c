/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Categoria.h"
#include "CategoriaXML.h"

/*int geraXMLCategoria(Categoria *cat, int num) {
    FILE *cad;
    // w pra substituir o arquivo
    cad = fopen("arquivos\\xml\\CategoriaXML.xml", "w");
    if (cad == NULL) {
        printf("\nErro ao abrir arquivo!!");
        return 0;
    } else {
        fprintf(cad, "<?xml version=\"1.0\" encoding=\"UTF - 8\"?>\n");
        fprintf(cad, "<dados>\n");
        fprintf(cad, "\t<tabela =categoria>\n");
        int i;
        // grava todos os dados do vetor no arquivo
        for (i = 0; i < num; i++) {
            fprintf(cad, "\t\t<registro>\n");
            fprintf(cad, "\t\t\t<codigo>%d</codigo>\n", cat[i].codigo);
            fprintf(cad, "\t\t\t<descricao>%s</descricao>\n", cat[i].descricao);
            fprintf(cad, "\t\t\t<quatidade_pessoas>%d</quatidade_pessoas>\n", cat[i].quantidadePessoas);
            fprintf(cad, "\t\t\t<valor_diaria>%f</valor_diaria>\n", cat[i].valorDiario);
            fprintf(cad, "\t\t\t<facilidade>%s</facilidade>\n", cat[i].facilidade);
            fprintf(cad, "\t\t</registro>\n");
        }
        fprintf(cad, "\t</tabela>\n");
        fprintf(cad, "</dados>\n");
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

/*Categoria* getCategoriaXML(char local[], int *num) {
    FILE *file;
    //abrea arquivo para leitura apenas "r"
    file = fopen(local, "r");
    if (file == NULL) {
        //cria arquivo para leitura/escrita se não houver "w+"
        file = fopen(local, "w+");
        if (file == NULL) {
            printf("\nErro ao acessar arquivo de categoria\n");
            return NULL;
        }
    }
    Categoria *cat = (Categoria*) calloc(1, sizeof (Categoria));
    if (cat == NULL) {
        printf("Erro ao alocar memoria\n");
    }
    char search[100];
    int i = 0;
    //roda ate o fim do arquivo, lendo linha a linha
    while (fgets(search, 100, file) != NULL) {
        //procura a tag <tabela =categoria>
        if (comparaString("	<tabela =categoria>", search) == 1) {
            while (fgets(search, 100, file) != NULL) {
                //procura a tag <registro>
                if (comparaString("		<registro>", search) == 1) {
                    cat = realloc(cat, (i + 1) * sizeof (Categoria));
                    fscanf(file, "			<codigo>%d</codigo>", &cat[i].codigo);
                    fscanf(file, "			<descricao>%s</descricao>", cat[i].descricao);
                    fscanf(file, "			<quatidade_pessoas>%d</quatidade_pessoas>", &cat[i].quantidadePessoas);
                    fscanf(file, "			<valor_diaria>%f</valor_diaria>", &cat[i].valorDiario);
                    fscanf(file, "			<facilidade>%s</facilidade>", cat[i].facilidade);
                    strtok(cat[i].facilidade, "</facilidade>");
                    strtok(cat[i].descricao, "</codigo>");
                    i++;
                }
            }
        }
    }
    *num = i;
    fclose(file);
    //libera memoria
    free(file);
    return cat;
}*/