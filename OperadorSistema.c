/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "OperadorSistema.h"



int salvarOperadorTXT(OperadorSistema *opera, int num) {  
    // w pra substituir o arquivo
    FILE *cade = fopen(".\\persist\\operador.bin", "wb");
    if (cade == NULL) {
        printf("\nErro ao abrir arquivo!!");
        return 0;
    } else {
        int i;
        // grava todos os dados do vetor no arquivo
        for (i = 0; i < num; i++) {
            fprintf(cade, "%d\n%s\n%s\n%s\n", opera[i].codigo,  opera[i].nome,  opera[i].usuario,  opera[i].senha); // f
        }
    }
    // força salvar arquivo
    fflush(cade);
    //fecha arquivo
    fclose(cade);
    //libera memoria
    free(cade);
    free(opera);
    return 1;
}


OperadorSistema* listarOpBIN(int *numLinha) {
    //area arquivo para leitura apenas "rb"
    FILE *arquivo = fopen(".\\persist\\operador.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao acessar arquivo\n");
    }
    *numLinha = 0;
    //instancia vetor com tamanho de numLinha
    OperadorSistema op;
    OperadorSistema *opera = (OperadorSistema*) calloc(1, sizeof (OperadorSistema));
    fread(&op, sizeof (OperadorSistema), 1, arquivo);
    do {
        *numLinha = (*numLinha)+ 1;
        opera = realloc(opera, *numLinha * sizeof (OperadorSistema));
        opera[(*numLinha) - 1] = op;
        fread(&op, sizeof (OperadorSistema), 1, arquivo);
    } while (!feof(arquivo));
    //fecha arquivo
    fclose(arquivo);
    //libera memoria
    free(arquivo);
    return opera;
}

int removerOperadorBIN() {
    int status = remove(".\\persist\\operador.bin");
    if (status != 0) {
        printf("\nErro na remoção do arquivo.\n");
        return 0;
    }
    return 1;
}