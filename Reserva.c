/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Data.h"
#include "Acomodacao.h"
#include "Hospede.h"
#include "Reserva.h"
#include <stdio.h>
#include <stdlib.h>
#include <String.h>

Reserva * listarResBIN(int *numLinha) {
    FILE *arquivo;
    //abrea arquivo para leitura apenas "rb"
    arquivo = fopen("arquivos\\ReservaBIN.bin", "rb");
    if (arquivo == NULL) {
        //cria arquivo para leitura\escrita se não houver "w+b"
        arquivo = fopen("arquivos\\ReservaBIN.bin", "w+b");
        if (arquivo == NULL) {
            printf("\nERRO ao acessar arquivo\n");
            return NULL;
        }
    }
    *numLinha = 0;

    Reserva reserva;
    //instancia vetor com tamanho 1 
    Reserva *res = (Reserva*) calloc(1, sizeof (Reserva));
    //pega a primeira linha se existir
    int r = fread(&reserva, sizeof (Reserva), 1, arquivo);
    if (r > 0) {
        do {
            //soma a +1 no tamanho do vetor o qual comessa com 0
            *numLinha = (*numLinha) + 1;
            // realoca o vetor com o tamanho numLinha, a arqa interação ele realoca um a mais
            res = realloc(res, *numLinha * sizeof (Reserva));
            //adicionar o struct o vetor,(numLinha -1) pois o vetor comessa sempre por 0
            res[(*numLinha) - 1] = reserva;
            //pega o proximo indice, se existir
            fread(&reserva, sizeof (Reserva), 1, arquivo);
            //verifica se chegou no fim do arquivo
        } while (!feof(arquivo));
    } else {
        return NULL;
    }
    //fecha arquivo
    fclose(arquivo);
    //libera memoria
    free(arquivo);
    return res;
}