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
#include"ContaReceber.h"
#include "ContaReceber.h"
#include "ContaPagar.h"
#include "csvContasRec.h"

void gerarCSVContasRec(ContaReceber* arrayFiltrado, int qte, int filtro) {
  
    FILE* arContasRec;

    // 1 -> FAIXA DE CÓDIGO
    // 2 -> DATA RECEBIMENTO

    if (filtro == 1) {
        arContasRec = fopen(".\\relatorios\\ContasRec_FaixaCod.txt", "w");

    } else {
        if (filtro == 2) {
            arContasRec = fopen(".\\relatorios\\ContasRec_Data.txt", "w");
        }
    }


    for (int i = 0; i < qte; i++) {
        printf("DENTRO DO FOR\n");
        fprintf(arContasRec, "%d,%f,%d,%d,%d,%s,%s,%d", arrayFiltrado[i].codigo, arrayFiltrado[i].valor, arrayFiltrado[i].data.dia, arrayFiltrado[i].data.mes, arrayFiltrado[i].data.ano, arrayFiltrado[i].status, arrayFiltrado[i].pagamento, arrayFiltrado[i].caixa);
        fprintf(arContasRec, "\n");

    }
    fflush(arContasRec);
    rewind(arContasRec);

}