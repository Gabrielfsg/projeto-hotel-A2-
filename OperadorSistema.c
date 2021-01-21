/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "OperadorSistema.h"

/*FILE *listOperador;

    listOperador = fopen(".\\persist\\operador.bin", "ab");
    if (listOperador == NULL) {
        printf("Erro Arquivo \n");
    } else {
        fprintf(listOperador, "Código do operador: %d \n", op.codigo);
        fprintf(listOperador, "Nome do Operador: %s \n", op.nome);
        fprintf(listOperador, "Usuário do Operador: %s \n", op.usuario);
        fprintf(listOperador, "Senha do Operador: %s \n", op.senha);

        fclose(listOperador);
        printf("Cadastro Efetuado com Sucesso \n");
    }*/

int cadastrarOpSBIN(OperadorSistema *aco, int quantidade) {
    FILE *arq;
    //abrea arquivo para escrita e posiciona cursor no final "ab"
    arq = fopen(".\\persist\\operador.bin", "ab");
    if (arq == NULL) {
        //cria arquivo para escrita se não houver "wb"
        arq = fopen(".\\persist\\operador.bin", "wb");
        if (arq == NULL) {
            printf("\nERRO ao acessar arquivo\n");
            return 0;
        }
    }
    //strlen()-> informa o tamanho de uma string 
    /*grava toda struct de acomodacao no arquivo*/
    fwrite(aco, sizeof (OperadorSistema), quantidade, arq);
    fflush(arq);
    /*fecha o arquivo*/
    fclose(arq);
    /*libera mémoria*/
    free(arq);
    return 1;
}

int salvarOperadorTXT(OperadorSistema *opera, int num) {
    // w pra substituir o arquivo
    FILE *cade = fopen(".\\persist\\operador.txt", "wb");
    if (cade == NULL) {
        printf("\nErro ao abrir arquivo!!");
        return 0;
    } else {
        int i;
        // grava todos os dados do vetor no arquivo
        for (i = 0; i < num; i++) {
            fprintf(cade, "%d\n%s\n%s\n%s\n", opera[i].codigo, opera[i].nome, opera[i].usuario, opera[i].senha); // f
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
OperadorSistema * listarOpBIN(int *numLinha) {
    FILE *arquivo;
    //abrea arquivo para leitura apenas "rb"
    arquivo = fopen(".\\persist\\operador.bin", "rb");
    if (arquivo == NULL) {
        //cria arquivo para leitura\escrita se não houver "w+b"
        arquivo = fopen(".\\persist\\operador.bin", "w+b");
        if (arquivo == NULL) {
            printf("\nERRO ao acessar arquivo\n");
            return NULL;
        }
    }
    *numLinha = 0;

    OperadorSistema c;
    //instancia vetor com tamanho 1 
    OperadorSistema *aco = (OperadorSistema*) calloc(1, sizeof (OperadorSistema));
    //pega a primeira linha se existir
    int r = fread(&c, sizeof (OperadorSistema), 1, arquivo);
    if (r > 0) {
        do {
            //soma a +1 no tamanho do vetor o qual comessa com 0
            *numLinha = (*numLinha) + 1;
            // realoca o vetor com o tamanho numLinha, a arqa interação ele realoca um a mais
            aco = realloc(aco, *numLinha * sizeof (OperadorSistema));
            //adicionar o struct o vetor,(numLinha -1) pois o vetor comessa sempre por 0
            aco[(*numLinha) - 1] = c;
            //pega o proximo indice, se existir
            fread(&c, sizeof (OperadorSistema), 1, arquivo);
            //verifica se chegou no fim do arquivo
        } while (!feof(arquivo));
    } else {
        return NULL;
    }
    //fecha arquivo
    fclose(arquivo);
    //libera memoria
    free(arquivo);
    return aco;
}

int editarOpSBIN(OperadorSistema aco, int posi) {
    FILE *arquivo;
    //abre arquivo para leitura e escrita, ele deve existir "r+b"
    arquivo = fopen(".\\persist\\operador.bin", "r+b");
    if (arquivo == NULL) {
        printf("Erro ao acessar arquivo\n");
        return 0;
    }
    //Posiciona o cursor na posição do struct
    fseek(arquivo, (posi * sizeof (OperadorSistema)), SEEK_SET);
    //Substitui o struct de posição posi
    fwrite(&aco, sizeof (OperadorSistema), 1, arquivo);
    //fecha arquivo 
    fclose(arquivo);
    //fclose(&aco);
    //libera memoria
    free(arquivo);
    return 1;
}

int removerOperadorBIN() {
    int status = remove(".\\persist\\operador.bin");
    if (status != 0) {
        printf("\nErro na remoção do arquivo.\n");
        return 0;
    }
    return 1;
}