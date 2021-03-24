
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
 * File:   CheckOut.c
 * Author: Daniel
 *
 * Created on 6 de Janeiro de 2021, 23:14
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CheckOut.h"
#include "Hora.h"

int cadastrarCheckOutTXT(CheckOut cat) {
    FILE *cad;
    // abre o arquivo e posiciona o cursor no final
    cad = fopen("arquivos\\CheckOutTXT.txt", "a");
    if (cad == NULL) {
        // se ele não existir cria um
        cad = fopen("arquivos\\CheckOutTXT.txt", "w");
        if (cad == NULL) {
            printf("\nErro: aao cessar arquivo\n");
            return 0;
        }
    }
    // salva cada campo em uma linha
    fprintf(cad, "%d\n%f\n%d\n%d\n%d\n%d\n%d\n%f\n%s\n%d\n", cat.codigo, cat.valorTotal, cat.saida.dia, cat.saida.mes, cat.saida.ano, cat.hospede, cat.checkin.codigo, cat.checkin.valor, cat.checkin.status, cat.caixa); // f
    //fecha o arquivo
    fclose(cad);
    //libera memoria
    free(cad);

    return 1;
}
//metodo salva, sobrescrevendo o array de tamanho num

int salvarCheckOutTXT(CheckOut *cat, int num) {
    FILE *cad;
    // w pra substituir o arquivo
    cad = fopen("arquivos\\CheckOutTXT.txt", "w");
    if (cad == NULL) {
        printf("\nErro ao abrir arquivo!!");
        return 0;
    } else {
        int i;
        // grava todos os dados do vetor no arquivo
        for (i = 0; i < num; i++) {
            fprintf(cad, "%d\n%f\n%d\n%d\n%d\n%d\n%d\n%f\n%s\n%d\n", cat[i].codigo, cat[i].valorTotal, cat[i].saida.dia, cat[i].saida.mes, cat[i].saida.ano, cat[i].hospede, cat[i].checkin.codigo, cat[i].checkin.valor, cat[i].checkin.status, cat[i].caixa); // f
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

CheckOut* listarCheckOutTXT() {
    int numLinha = 0, i = 0;
    FILE *arquivo;
    numLinha = numCheckOut();
    //abrea arquivo para leitura apenas "r"
    arquivo = fopen("arquivos\\CheckOutTXT.txt", "r");
    if (arquivo == NULL) {
        //cria arquivo para leitura/escrita se não houver "w+"
        arquivo = fopen("arquivos\\CheckOutTXT.txt", "w+");
        if (arquivo == NULL) {
            printf("\nErro ao acessar arquivo categoria\n");
            return NULL;
        }
    }
    //instancia vetor com tamanho de numLinha
    CheckOut *cat = (CheckOut*) calloc(numLinha, sizeof (CheckOut));
    i = 0;

    char t[100];
    //printf("linhas %d \n", numLinha);

    for (i = 0; i < numLinha; i++) {
        fgets(t, 100, arquivo);
        cat[i].codigo = atoi(t);
        fgets(t, 100, arquivo);
        cat[i].valorTotal = atof(t);
        printf("DEBUG CHECKOUT: LEU %f\n",cat[i].valorTotal);
        fgets(t, 100, arquivo);
        cat[i].saida.dia = atoi(t);
        fgets(t, 100, arquivo);
        cat[i].saida.mes = atoi(t);
        fgets(t, 100, arquivo);
        cat[i].saida.ano = atoi(t);
        fgets(t, 100, arquivo);
        cat[i].hospede = atoi(t);
        fgets(t, 100, arquivo);
        cat[i].checkin.codigo = atoi(t);
        fgets(t, 100, arquivo);
        cat[i].checkin.valor = atof(t);
        fgets(cat[i].checkin.status, 100, arquivo);
        strtok(cat[i].checkin.status, "\n");
        fgets(t, 100, arquivo);
        cat[i].caixa = atoi(t);

    }
    //fecha arquivo
    fclose(arquivo);
    //libera memoria
    free(arquivo);
    return cat;
}

int numCheckOut() {
    FILE *arquivo;
    int numLinha = 0, c;
    //abre arquivo para leitura "r"
    arquivo = fopen("arquivos\\CheckOutTXT.txt", "r");
    if (arquivo == NULL) {
        arquivo = fopen("arquivos\\CheckOutTXT.txt", "w+");
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
    return numLinha / 10;
}

int validarCheckOut(int cod) {
    CheckOut *cat = listarCheckOutTXT();
    //int lin = sizeof (*cat) / sizeof (CheckOut);
    int lin = numCheckOut();
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

int cadastrarCheckOutBIN(CheckOut *cat, int quantidade) {
    FILE *cad;
    //cad = fopen("arquivos\\ReservaQBIN.bin", "ab");
    cad = fopen("arquivos\\CheckOutBIN.bin", "ab");
    if (cad == NULL) {
        //cad = fopen("arquivos\\ReservaQBIN.bin", "wb");
        cad = fopen("arquivos\\CheckOutBIN.bin", "wb");
        return 0;
    } else {
        //strlen()-> informa o tamanho de uma string 
        /*grava toda struct de categoria no arquivo*/
        fwrite(cat, sizeof (CheckOut), quantidade, cad);
        fflush(cad);
        /*fecha o arquivo*/
        fclose(cad);
        /*libera mémoria*/
        free(cad);
    }
    return 1;
}

CheckOut * listarCheckOutBIN(int *numLinha) {
    FILE *arquivo;
    //area arquivo para leitura apenas "rb"
    arquivo = fopen("arquivos\\CheckOutBIN.bin", "rb");
    if (arquivo == NULL) {
        //cria arquivo para leitura\escrita se não houver "w+b"
        arquivo = fopen("arquivos\\CheckOutBIN.bin", "w+b");
        if (arquivo == NULL) {
            printf("\nERRO ao acessar arquivo\n");
            return NULL;
        }
    }
    *numLinha = 0;

    CheckOut c;
    //instancia vetor com tamanho 1 
    CheckOut *cat = (CheckOut*) calloc(1, sizeof (CheckOut));
    //pega a primeira linha se existir
    int r = fread(&c, sizeof (CheckOut), 1, arquivo);
    if (r > 0) {
        do {
            //soma a +1 no tamanho do vetor o qual comessa com 0
            *numLinha = (*numLinha) + 1;
            // realoca o vetor com o tamanho numLinha, a cada interação ele realoca um a mais
            cat = realloc(cat, *numLinha * sizeof (CheckOut));
            //adicionar o struct o vetor,(numLinha -1) pois o vetor comessa sempre por 0
            cat[(*numLinha) - 1] = c;
            //pega o proximo indice, se existir
            fread(&c, sizeof (CheckOut), 1, arquivo);
            //verifica se chegou no fim do arquivo
        } while (!feof(arquivo));
    } else {
        return NULL;
    }
    //fecha arquivo
    fclose(arquivo);
    //libera memoria
    free(arquivo);
    return cat;
}

int editarCheckOutBIN(CheckOut cat) {
    FILE *arquivo;
    //abre arquivo para leitura e escrita "r+b"
    arquivo = fopen("arquivos\\CheckOutBIN.bin", "r+b");
    if (arquivo == NULL) {
        printf("Erro ao acessar arquivo\n");
        return 0;
    }
    int posi = posicaoCheckOutBIN(cat.codigo);
    //Posiciona o cursor na posição do struct
    fseek(arquivo, (posi * sizeof (CheckOut)), SEEK_SET);
    //Substitui o struct de posição posi
    fwrite(&cat, sizeof (CheckOut), 1, arquivo);
    //fecha arquivo 
    fclose(arquivo);
    //fclose(&cat);
    //libera memoria
    free(arquivo);
    return 1;
}

int validarCheckOutBIN(int cod) {
    int num;
    CheckOut *cat = listarCheckOutBIN(&num);
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

int posicaoCheckOutBIN(int cod) {
    int num;
    CheckOut *cat = listarCheckOutBIN(&num);
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

int removerCheckOutBIN() {
    int status = remove("arquivos\\CheckOutBIN.bin");
    if (status != 0) {
        printf("\nErro na remoção do arquivo.\n");
        return 0;
    }
    return 1;
}

float somaCheckOutCaixa(int codigo, float* valor) {
    
    CheckOut *cai;
    int num;
    int bd = listar();
    if (bd == 1) {
        cai = listarCheckOutTXT();
        num = numCheckOut();
    } else {
        cai = listarCheckOutBIN(&num);
    }
    int i;
    for (i = 0; i < num; i++) {
        if (cai[i].caixa == codigo) {
            *valor += cai[i].valorTotal;
        }
    }

}

