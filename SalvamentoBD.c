/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>

int listar() {
    int retorno;
    FILE *arquivo;
    //area arquivo para leitura apenas "rb"
    arquivo = fopen("arquivos\\configuracoes\\bd\\cof.bin", "rb");
    if (arquivo == NULL) {
        //cria arquivo para leitura\escrita se não houver "w+b"
        arquivo = fopen("arquivos\\configuracoes\\bd\\cof.bin", "w+b");
        if (arquivo == NULL) {
            printf("\nERRO ao acessar arquivo\n");
            return 0;
        }
    }
    //pega a primeira linha se existir
    fread(&retorno, sizeof (int), 1, arquivo);
    //fecha arquivo
    fclose(arquivo);
    //libera memoria
    free(arquivo);
    return retorno;
}

int alterar(int opc) {
    FILE *cad;
    cad = fopen("arquivos\\configuracoes\\bd\\cof.bin", "w+b");
    if (cad == NULL) {
        printf("\nErro: ao acessar o arquivo\n");
        return 0;
    } else {
        //strlen()-> informa o tamanho de uma string 
        /*grava toda struct de categoria no arquivo*/
        fwrite(&opc, sizeof (int), 1, cad);
        fflush(cad);
        /*fecha o arquivo*/
        fclose(cad);
        /*libera mémoria*/
        free(cad);
    }
    return 1;
}