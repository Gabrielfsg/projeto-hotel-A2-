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
