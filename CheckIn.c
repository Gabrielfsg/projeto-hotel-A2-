/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CheckIn.c
 * Author: Daniel
 *
 * Created on 6 de Janeiro de 2021, 23:14
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CheckIn.h"
#include "Hora.h"

int cadastrarCheckInTXT(CheckIn cat) {
    FILE *cad;
    // abre o arquivo e posiciona o cursor no final
    cad = fopen("arquivos\\CheckInTXT.txt", "a");
    if (cad == NULL) {
        // se ele não existir cria um
        cad = fopen("arquivos\\CheckInTXT.txt", "w");
        if (cad == NULL) {
            printf("\nErro: aao cessar arquivo\n");
            return 0;
        }
    }
    // salva cada campo em uma linha
    fprintf(cad, "%d\n%f\n%d\n%d\n%d\n%s\n%d\n%d\n", cat.codigo, cat.valor, cat.hora.hh, cat.hora.mm, cat.hora.ss, cat.status, cat.reserva.codigo, cat.caixa); // f
    //fecha o arquivo
    fclose(cad);
    //libera memoria
    free(cad);

    return 1;
}
//metodo salva, sobrescrevendo o array de tamanho num

int salvarCheckInTXT(CheckIn *cat, int num) {
    FILE *cad;
    // w pra substituir o arquivo
    cad = fopen("arquivos\\CheckInTXT.txt", "w");
    if (cad == NULL) {
        printf("\nErro ao abrir arquivo!!");
        return 0;
    } else {
        int i;
        // grava todos os dados do vetor no arquivo
        for (i = 0; i < num; i++) {
            fprintf(cad, "%d\n%f\n%d\n%d\n%d\n%s\n%d\n%d\n", cat[i].codigo, cat[i].valor, cat[i].hora.hh, cat[i].hora.mm, cat[i].hora.ss, cat[i].status, cat[i].reserva.codigo, cat[i].caixa); // f
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

CheckIn* listarCheckInTXT() {
    int numLinha = 0, i = 0;
    FILE *arquivo;
    numLinha = numCheckIn(arquivo);
    //abrea arquivo para leitura apenas "r"
    arquivo = fopen("arquivos\\CheckInTXT.txt", "r");
    if (arquivo == NULL) {
        //cria arquivo para leitura/escrita se não houver "w+"
        arquivo = fopen("arquivos\\CheckInTXT.txt", "w+");
        if (arquivo == NULL) {
            printf("\nErro ao acessar arquivo categoria\n");
            return NULL;
        }
    }
    //instancia vetor com tamanho de numLinha
    CheckIn *cat = (CheckIn*) calloc(numLinha, sizeof (CheckIn));
    i = 0;

    char t[100];
    //printf("linhas %d \n", numLinha);

    for (i = 0; i < numLinha; i++) {
        fgets(t, 100, arquivo);
        cat[i].codigo = atoi(t);
        fgets(t, 100, arquivo);
        cat[i].valor = atof(t);
        fgets(t, 100, arquivo);
        cat[i].hora.hh = atoi(t);
        fgets(t, 100, arquivo);
        cat[i].hora.mm = atoi(t);
        fgets(t, 100, arquivo);
        cat[i].hora.ss = atoi(t);
        fgets(cat[i].status, 100, arquivo);
        strtok(cat[i].status, "\n");
        fgets(t, 100, arquivo);
        cat[i].reserva.codigo = atoi(t);
        fgets(t, 100, arquivo);
        cat[i].caixa = atoi(t);
    }
    //fecha arquivo
    fclose(arquivo);
    //libera memoria
    free(arquivo);
    return cat;
}

int numCheckIn() {
    FILE *arquivo;
    int numLinha = 0, c;
    //abre arquivo para leitura "r"
    arquivo = fopen("arquivos\\CheckInTXT.txt", "r");
    if (arquivo == NULL) {
        arquivo = fopen("arquivos\\CheckInTXT.txt", "w+");
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
    // divide se por 8 pois categoria tem 5 linhas
    return numLinha / 8;
}

int validarCheckIn(int cod) {
    CheckIn *cat = listarCheckInTXT();
    //int lin = sizeof (*cat) / sizeof (CheckIn);
    int lin = numCheckIn();
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

int cadastrarCheckInBIN(CheckIn *cat, int quantidade) {
    FILE *cad;
    //cad = fopen("arquivos\\ReservaQBIN.bin", "ab");
    cad = fopen("arquivos\\CheckInBIN.bin", "ab");
    if (cad == NULL) {
        //cad = fopen("arquivos\\ReservaQBIN.bin", "wb");
        cad = fopen("arquivos\\CheckInBIN.bin", "wb");
        return 0;
    } else {
        //strlen()-> informa o tamanho de uma string 
        /*grava toda struct de categoria no arquivo*/
        fwrite(cat, sizeof (CheckIn), quantidade, cad);
        fflush(cad);
        /*fecha o arquivo*/
        fclose(cad);
        /*libera mémoria*/
        free(cad);
    }
    return 1;
}

CheckIn * listarCheckInBIN(int *numLinha) {
    FILE *arquivo;
    //area arquivo para leitura apenas "rb"
    arquivo = fopen("arquivos\\CheckInBIN.bin", "rb");
    if (arquivo == NULL) {
        //cria arquivo para leitura\escrita se não houver "w+b"
        arquivo = fopen("arquivos\\CheckInBIN.bin", "w+b");
        if (arquivo == NULL) {
            printf("\nERRO ao acessar arquivo\n");
            return NULL;
        }
    }
    *numLinha = 0;

    CheckIn c;
    //instancia vetor com tamanho 1 
    CheckIn *cat = (CheckIn*) calloc(1, sizeof (CheckIn));
    //pega a primeira linha se existir
    int r = fread(&c, sizeof (CheckIn), 1, arquivo);
    if (r > 0) {
        do {
            //soma a +1 no tamanho do vetor o qual comessa com 0
            *numLinha = (*numLinha) + 1;
            // realoca o vetor com o tamanho numLinha, a cada interação ele realoca um a mais
            cat = realloc(cat, *numLinha * sizeof (CheckIn));
            //adicionar o struct o vetor,(numLinha -1) pois o vetor comessa sempre por 0
            cat[(*numLinha) - 1] = c;
            //pega o proximo indice, se existir
            fread(&c, sizeof (CheckIn), 1, arquivo);
            //verifica se chegou no fim do arquivo
        } while (!feof(arquivo));
    } else {
        return NULL;
    }
    //fecha arquivo
    fclose(arquivo);
    //libera memoria
    free(arquivo);
    //printf("DEBUG NUMLINHA = %d\n",*numLinha);
    /*for(int i =0;i<(*numLinha);i++){
        printf("COD: %d\n",cat[i].codigo);
        printf("DESC: %s\n",cat[i].descricao);
        printf("FAC: %s\n",cat[i].facilidade);
        printf("QTE: %d\n",cat[i].quantidadePessoas);
        printf("VALOR: %.2f\n",cat[i].valorDiario);
        
    }*/
    return cat;
}

int editarCheckInBIN(CheckIn cat) {
    FILE *arquivo;
    //abre arquivo para leitura e escrita "r+b"
    arquivo = fopen("arquivos\\CheckInBIN.bin", "r+b");
    if (arquivo == NULL) {
        printf("Erro ao acessar arquivo\n");
        return 0;
    }
    int posi = posicaoCheckInBIN(cat.codigo);
    //Posiciona o cursor na posição do struct
    fseek(arquivo, (posi * sizeof (CheckIn)), SEEK_SET);
    //Substitui o struct de posição posi
    fwrite(&cat, sizeof (CheckIn), 1, arquivo);
    //fecha arquivo 
    fclose(arquivo);
    //fclose(&cat);
    //libera memoria
    free(arquivo);
    return 1;
}

int validarCheckInBIN(int cod) {
    int num;
    CheckIn *cat = listarCheckInBIN(&num);
    int i;
    for (i = 0; i < num; i++) {
        if (cod == cat[i].codigo) {
            // retorna um se achar
            return 1;
        }
    }
    free(cat);
    return 0;
}

int posicaoCheckInBIN(int cod) {
    int num;
    CheckIn *cat = listarCheckInBIN(&num);
    int i;
    for (i = 0; i < num;) {
        if (cod == cat[i].codigo) {
            // retorna um se achar
            return i;
        }
        i++;
    }
    free(cat);
    return 0;
}

int removerCheckInBIN() {
    int status = remove("arquivos\\CheckInBIN.bin");
    if (status != 0) {
        printf("\nErro na remoção do arquivo.\n");
        return 0;
    }
    return 1;
}

float somaCheckInCaixa(int codigo) {
    float valor = 0;
    CheckIn *cai;
    int num;
    int bd = listar();
    if (bd == 1) {
        cai = listarCheckInTXT();
        num = numCheckIn();
    } else {
        cai = listarCheckInBIN(&num);
    }
    int i;
    for (i = 0; i < num; i++) {
        if (cai[i].caixa == codigo) {
            valor += cai[i].valor;
        }
    }
    return valor;

}