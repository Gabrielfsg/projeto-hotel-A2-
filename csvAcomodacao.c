/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"Data.h"
#include"Endereco.h"
#include"Acomodacao.h"
#include"AcomodacaoMenu.h"


void gerarCSVAcomodacao(Acomodacao* arrayFiltrado, int qteAcoFiltro, int filtro) {
    //printf("ENTROU GERAR CSV Acomodação\n");

    FILE* arqAco;

    //ABRE O ARQUIVO CORRESPONDENTE AO FILTRO

    // 1 -> FAIXA DE CÓDIGO
    // 2 -> CATEGORIA
    // 3 -> DATA

    if (filtro == 1) {
        arqAco = fopen(".\\relatorios\\Acomodacao_Faixa_Cod.txt", "w");

    } else {
        if (filtro == 2) {
            arqAco = fopen(".\\relatorios\\Acomodacao_Categoria.txt", "w");
        } else {
            if (filtro == 3) {
                arqAco = fopen(".\\relatorios\\Acomodacao_DATA.txt", "w");
            }
        }
    }

    for (int i = 0; i < qteAcoFiltro; i++) {
        //printf("DENTRO DO FOR\n");

        fprintf(arqAco, "%d,%s,%d,%s", arrayFiltrado[i].codigo, arrayFiltrado[i].descricao, arrayFiltrado[i].categoria.codigo, arrayFiltrado[i].status);
        fprintf(arqAco, "\n");
    }

    fflush(arqAco);
    fclose(arqAco);

}