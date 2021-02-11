/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "Acomodacao.h"
#include "AcomodacaoSUB.h"

int cadastrarAcomodacaoTXT(Acomodacao aco) {
    FILE *arq;
    // abre o arquivo com o cursor no final
    arq = fopen("arquivos\\AcomodacaoTXT.txt", "a");
    if (arq == NULL) {
        // se ele não existir cria um
        arq = fopen("arquivos\\AcomodacaoTXT.txt", "w");
        if (arq == NULL) {
            printf("\nErro ao acessar arquivo\n");
            return 0;
        }
    }
    // salva arqa campo em uma linha
    fprintf(arq, "%d\n%s\n%d\n%s\n", aco.codigo, aco.descricao, aco.categoria.codigo, aco.status); // f
    //fecha o arquivo
    fclose(arq);
    //libera memoria
    free(arq);
    return 1;
}
//metodo salva, sobrescrevendo o array de tamanho num

int salvarAcomodacaoTXT(Acomodacao *aco, int num) {
    FILE *arq;
    // w pra substituir o arquivo
    arq = fopen("arquivos\\AcomodacaoTXT.txt", "w");
    if (arq == NULL) {
        printf("\nErro ao abrir arquivo!!");
        return 0;
    } else {
        int i;
        // grava todos os dados do vetor no arquivo
        for (i = 0; i < num; i++) {
            fprintf(arq, "%d\n%s\n%d\n%s\n", aco[i].codigo, aco[i].descricao, aco[i].categoria.codigo, aco[i].status); // f
        }
    }
    // força salvar arquivo
    fflush(arq);
    //fecha arquivo
    fclose(arq);
    //libera memoria
    free(arq);
    free(aco);
    return 1;
}

Acomodacao * listarAcomodacaoTXT() {
    int numLinha = 0, i = 0;
    FILE *arquivo;
    numLinha = numLinhasAcomodacao(arquivo);
    //area arquivo para leitura apenas "r"
    arquivo = fopen("arquivos\\AcomodacaoTXT.txt", "r");
    if (arquivo == NULL) {
        arquivo = fopen("arquivos\\AcomodacaoTXT.txt", "w+");
        if (arquivo == NULL) {
            printf("Erro ao acessar arquivo\n");
            return NULL;
        }
    }
    //instancia vetor com tamanho de numLinha
    Acomodacao *aco = (Acomodacao*) calloc(numLinha, sizeof (Acomodacao));
    i = 0;
    //printf("linhas %d \n", numLinha);
    while (fscanf(arquivo, "%d", &aco[i].codigo) == 1) {
        //retira o \n do inicio  da string
        fgetc(arquivo);
        //fgetc(arquivo);
        //pega a string descrição
        fscanf(arquivo, "%100[a-z A-Z\n]s", aco[i].descricao);
        //retira o \n do fim da descrição
        strtok(aco[i].descricao, "\n");
        fscanf(arquivo, "%d", &aco[i].categoria.codigo);
        //retira o \n do inicio da status
        fgetc(arquivo);
        //fgetc(arquivo);
        fscanf(arquivo, "%100[a-z A-Z\n]s", aco[i].status);
        //retira o \n do fim da status
        strtok(aco[i].status, "\n");
        i++;
    }
    //fecha arquivo
    fclose(arquivo);
    //libera memoria
    free(arquivo);
    return aco;
}

int numLinhasAcomodacao() {
    //printf("num linhas");
    FILE *arquivo;
    int numLinha = 0, c;
    //abre arquivo para leitura "r"
    arquivo = fopen("arquivos\\AcomodacaoTXT.txt", "r");
    if (arquivo == NULL) {
        arquivo = fopen("arquivos\\CategoriaTXT.txt", "w+");
        if (arquivo == NULL) {
            printf("\nErro ao acessar arquivo\n");
            return 0;
        }
    }
    //roda ate que ache o final do arquivo "EOF"
    while ((c = fgetc(arquivo)) != EOF) {
        if (c == '\n') {
            //soma a quantidade de linhas do TXT, mas não a quantidade de acoegorias
            numLinha++;
        }
    }
    //fecha arquivo
    fclose(arquivo);
    //libera memoria
    free(arquivo);
    // divide se por 4 pois acomodação tem 4 linhas
    return numLinha / 4;
}

int validarAcomodacao(int cod) {
    Acomodacao *aco = listarAcomodacaoTXT();
    if (aco != NULL) {
        int lin = sizeof (*aco) / sizeof (Acomodacao);
        int i;
        for (i = 0; i < lin; i++) {
            if (cod == aco[i].codigo) {
                return 1;
            }
        }
        free(aco);
        return 0;
    }
    return 1;
}

/*Aruivos binarios*/

int cadastrarAcomodacaoBIN(Acomodacao *aco, int quantidade) {
    FILE *arq;
    //abrea arquivo para escrita e posiciona cursor no final "ab"
    arq = fopen("arquivos\\AcomodacaoBIN.bin", "ab");
    if (arq == NULL) {
        //cria arquivo para escrita se não houver "wb"
        arq = fopen("arquivos\\AcomodacaoBIN.bin", "wb");
        if (arq == NULL) {
            printf("\nERRO ao acessar arquivo\n");
            return 0;
        }
    }
    //strlen()-> informa o tamanho de uma string 
    /*grava toda struct de acomodacao no arquivo*/
    fwrite(aco, sizeof (Acomodacao), quantidade, arq);
    fflush(arq);
    /*fecha o arquivo*/
    fclose(arq);
    /*libera mémoria*/
    free(arq);
    return 1;
}

Acomodacao * listarAcomodacaoBIN(int *numLinha) {
    FILE *arquivo;
    //abrea arquivo para leitura apenas "rb"
    arquivo = fopen("arquivos\\AcomodacaoBIN.bin", "rb");
    if (arquivo == NULL) {
        //cria arquivo para leitura\escrita se não houver "w+b"
        arquivo = fopen("arquivos\\AcomodacaoBIN.bin", "w+b");
        if (arquivo == NULL) {
            printf("\nERRO ao acessar arquivo\n");
            return NULL;
        }
    }
    *numLinha = 0;

    Acomodacao c;
    //instancia vetor com tamanho 1 
    Acomodacao *aco = (Acomodacao*) calloc(1, sizeof (Acomodacao));
    //pega a primeira linha se existir
    int r = fread(&c, sizeof (Acomodacao), 1, arquivo);
    if (r > 0) {
        do {
            //soma a +1 no tamanho do vetor o qual comessa com 0
            *numLinha = (*numLinha) + 1;
            // realoca o vetor com o tamanho numLinha, a arqa interação ele realoca um a mais
            aco = realloc(aco, *numLinha * sizeof (Acomodacao));
            //adicionar o struct o vetor,(numLinha -1) pois o vetor comessa sempre por 0
            aco[(*numLinha) - 1] = c;
            //pega o proximo indice, se existir
            fread(&c, sizeof (Acomodacao), 1, arquivo);
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



int editarAcomodacaoBIN(Acomodacao aco, int posi) {
    FILE *arquivo;
    //abre arquivo para leitura e escrita, ele deve existir "r+b"
    arquivo = fopen("arquivos\\AcomodacaoBIN.bin", "r+b");
    if (arquivo == NULL) {
        printf("Erro ao acessar arquivo\n");
        return 0;
    }
    //Posiciona o cursor na posição do struct
    fseek(arquivo, (posi * sizeof (Acomodacao)), SEEK_SET);
    //Substitui o struct de posição posi
    fwrite(&aco, sizeof (Acomodacao), 1, arquivo);
    //fecha arquivo 
    fclose(arquivo);
    //fclose(&aco);
    //libera memoria
    free(arquivo);
    return 1;
}

int validarAcomodacaoBIN(int cod) {
    int num;
    Acomodacao *aco = listarAcomodacaoBIN(&num);
    int i;
    for (i = 0; i < num; i++) {
        if (cod == aco[i].codigo) {
            // retorna o indice se achar
            return i;
        }
    }
    free(aco);
    return 0;
}

int removerAcomodacaoBIN() {
    int status = remove("arquivos\\AcomodacaoBIN.bin");
    if (status != 0) {
        printf("\nErro na remoção do arquivo.\n");
        return 0;
    }
    return 1;
}


