/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Produto.h"
#include "VendaProduto.h"

int cadastrarVendaProdutoTXT(VendaProduto vp) {
    //printf("DEBUG: ENTROU CADASTRA VENDA PROD TXT\n");
    FILE* arqVendaProduto;
    //abre o arquivo, ou cria um novo se não conseguir abrir
    arqVendaProduto = fopen(".\\arquivos\\vendaProduto.txt", "a");
    if (arqVendaProduto == NULL) {
        arqVendaProduto = fopen(".\\arquivos\\vendaProduto.txt", "w");
    }
    int retorno;
    retorno = fprintf(arqVendaProduto, "%d\r\n%d\r\n%d\r\n", vp.codVenda,vp.codProduto,vp.quantidade);
    fflush(arqVendaProduto);
    fclose(arqVendaProduto);
    return retorno;
}

int cadastrarVendaProdutoBIN(VendaProduto vp) {
    //printf("DEBUG: ENTROU CADASTRA VENDA PROD BIN\n");
    FILE* arqVEndaProduto;
    //abre o arquivo, ou cria um novo se não conseguir abrir
    arqVEndaProduto = fopen(".\\arquivos\\vendaProduto.bin", "ab");
    if (arqVEndaProduto == NULL) {
        arqVEndaProduto = fopen(".\\arquivos\\vendaProduto.bin", "wb");
        if (arqVEndaProduto == NULL) {
            printf("ERRO AO LER ARQUIVO DE PRODUTOS\n");
        }

    } else {
        int count = 0;
        count = fwrite(&vp, sizeof (VendaProduto), 1, arqVEndaProduto);

        fflush(arqVEndaProduto);
        /*fecha o arquivo*/
        fclose(arqVEndaProduto);
        /*libera mémoria*/
        free(arqVEndaProduto);
        fclose(arqVEndaProduto);
        return count;
    }
}

int salvarVendaProdutoTXT(VendaProduto *vpr, int num) {
  FILE *arq;
  // w para substituir o arquivo
  arq = fopen("arquivos\\vendaProduto.txt", "w");
  if (arq == NULL) {
    printf("\nErro ao abrir arquivo!!");
    return 0;
  } else {
    int i;
    // grava todos os dado do vetor no arquivo
    for (i = 0; i < num; i++) {
      fprintf(arq, "%d\r\n%d\r\n%d\r\n", vpr[i].codProduto,
              vpr[i].codVenda, vpr[i].quantidade);
    }
  }
  fflush(arq);
  fclose(arq);
  free(arq);
  free(vpr);
  return 1;
}

int salvarVendaProdutoBIN(VendaProduto *vpr, int quantidade) {
      FILE *arq;
    //abrea arquivo para escrita e posiciona cursor no final "ab"
    arq = fopen("arquivos\\vendaProduto.bin", "ab");
    if (arq == NULL) {
        //cria arquivo para escrita se não houver "wb"
        arq = fopen("arquivos\\vendaProduto.bin", "wb");
        if (arq == NULL) {
            printf("\nERRO ao acessar arquivo\n");
            return 0;
        }
    }
    //strlen()-> informa o tamanho de uma string 
    /*grava toda struct de operador no arquivo*/
    fwrite(&vpr, sizeof (VendaProduto), quantidade, arq);
    fflush(arq);
    /*fecha o arquivo*/
    fclose(arq);
    /*libera mémoria*/
    free(arq);
    return 1;
}

int getNumVendaProduto() {
    FILE *arq;
    int numLinhas = 0, numVendaProduto = 0;
    char c;
    arq = fopen(".\\arquivos\\vendaProduto.txt", "r");
    if (arq == NULL) {
        arq = fopen(".\\arquivos\\vendaProduto.txt", "w");
        if (arq == NULL) {
            printf("ERRO AO ACESSAR ARQUIVO");
            exit(1);
        }

        return 0;
    }
    while ((c = fgetc(arq)) != EOF) {
        if (c == '\n') {
            numLinhas++;
        }
    }
    numVendaProduto = numLinhas / 3; // um produto gasta 6 linhas

    //printf("O NÚMERO DE LINHAS DO ARQ É: %d\n", numLinhas);
    //printf("O NÚMERO DE PRODS CADASTRADOS É: %d\n", numProdutos);
    fclose(arq);
    free(arq);
    return numVendaProduto;

}

VendaProduto* listarVendaProdutoTXT() {
   int numLinha = 0, i = 0;
    FILE *arquivo;
    numLinha = getNumVendaProduto();
    //area arquivo para leitura apenas "r"
    arquivo = fopen("arquivos\\vendaProduto.txt", "r");
    if (arquivo == NULL) {
        arquivo = fopen("arquivos\\vendaProduto.txt", "w+");
        if (arquivo == NULL) {
            printf("Erro ao acessar arquivo\n");
            return NULL;
        }
    }
    //instancia vetor com tamanho de numLinha
    VendaProduto *vpr = (VendaProduto*) calloc(numLinha, sizeof (VendaProduto));
    i = 0;
    char t[100];
    for (i = 0; i < numLinha; i++) {
        fgets(t, 100, arquivo);
        vpr[i].codProduto = atoi(t);
        //fgets(t, 100, arquivo);
        vpr[i].codVenda = atoi(t);
        vpr[i].quantidade = atoi(t);
    }
    //fecha arquivo
    fclose(arquivo);
    //libera memoria
    free(arquivo);
    return vpr;
}

VendaProduto * listarVendaProdutoBIN(int *numLinha) {
    FILE *arquivo;
    //area arquivo para leitura apenas "rb"
    arquivo = fopen("arquivos\\vendaProduto.bin", "rb");
    if (arquivo == NULL) {
        //cria arquivo para leitura\escrita se não houver "w+b"
        arquivo = fopen("arquivos\\vendaProduto.bin", "w+b");
        if (arquivo == NULL) {
            printf("\nERRO ao acessar arquivo\n");
            return NULL;
        }
    }
    *numLinha = 0;

    VendaProduto vpr;
    //instancia vetor com tamanho 1 
    VendaProduto *cat = (VendaProduto*) calloc(1, sizeof (VendaProduto));
    //pega a primeira linha se existir
    int r = fread(&vpr, sizeof (VendaProduto), 1, arquivo);
    if (r > 0) {
        do {
            //soma a +1 no tamanho do vetor o qual comessa com 0
            *numLinha = (*numLinha) + 1;
            // realoca o vetor com o tamanho numLinha, a cada interação ele realoca um a mais
            cat = realloc(cat, *numLinha * sizeof (VendaProduto));
            //adicionar o struct o vetor,(numLinha -1) pois o vetor comessa sempre por 0
            cat[(*numLinha) - 1] = vpr;
            //pega o proximo indice, se existir
            fread(&vpr, sizeof (VendaProduto), 1, arquivo);
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
