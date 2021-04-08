/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"Data.h"
#include"Produto.h"
#include"ProdutoConsumoMenu.h"

void gerarCSVProdConsumo(Produto* arrayFiltrado, int qteProdFiltro) {
    printf("ENTROU GERAR CSV Acomodação\n");

    FILE* arqProduto;

    //APENAS FILTRA POR FAIXA DE COD

    arqProduto = fopen(".\\relatorios\\Produto_Faixa_Cod.txt", "w");

    for (int i = 0; i < qteProdFiltro; i++) {
        //printf("DENTRO DO FOR\n");
        
        fprintf(arqProduto, "%d,%s,%d,%d,%f,%f", arrayFiltrado[i].codigo, arrayFiltrado[i].descricao, arrayFiltrado[i].estoque, arrayFiltrado[i].estoqueMinimo, arrayFiltrado[i].precoCusto, arrayFiltrado[i].precoVenda);
        fprintf(arqProduto, "\n");
    }

    fflush(arqProduto);
    fclose(arqProduto);

}