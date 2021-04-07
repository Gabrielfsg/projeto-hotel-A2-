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
    printf("ENTROU GERAR CSV\n");
/*
    printf("\n\nFOR DENTRO DO CSV\n");
    for (int i = 0; i < qte; i++) {
        printf("\n*******%d************", i);
        printf("\nCodigo: %d", arrayFiltrado[i].codigo);
        printf("\nValor: %f", arrayFiltrado[i].valor);
        printf("\nDia Pagamento: %d", arrayFiltrado[i].data.dia);
        printf("\nMes Pagamento: %d", arrayFiltrado[i].data.mes);
        printf("\nAno Pagamento: %d", arrayFiltrado[i].data.ano);
        printf("\nStatus: %s", arrayFiltrado[i].status);
        printf("\nForma de Pagamento: %s", arrayFiltrado[i].pagamento);
        printf("\nCodigo do caixa: %d", arrayFiltrado[i].caixa);
        printf("\n");
    }
*/

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
        fflush(arContasRec);
        rewind(arContasRec);
        fprintf(arContasRec, "%d,%f,%d,%d,%d,%s,%s,%d", arrayFiltrado[i].codigo, arrayFiltrado[i].valor, arrayFiltrado[i].data.dia, arrayFiltrado[i].data.mes, arrayFiltrado[i].data.ano, arrayFiltrado[i].status, arrayFiltrado[i].pagamento, arrayFiltrado[i].caixa);
        fprintf(arContasRec, "\n");
         
    }


}