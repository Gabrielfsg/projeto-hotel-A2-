/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Data.h"
#include "Acomodacao.h"
#include "Hospede.h"
#include <stdio.h>
#include <stdlib.h>
#include <String.h>

int cadastrarReservaBIN(Acomodacao *aco, int quantidade) {
    FILE *cad;
    cad = fopen("arquivos\\ReservaBIN.bin", "ab");
    if (cad == NULL) {
        cad = fopen("arquivos\\ReservaBIN.bin", "wb");
        return 0;
    } else {
        //strlen()-> informa o tamanho de uma string 
        /*grava toda struct de categoria no arquivo*/
        fwrite(&aco, sizeof (Acomodacao), quantidade, cad);
        fflush(cad);
        /*fecha o arquivo*/
        fclose(cad);
        /*libera mémoria*/
        free(cad);
    }
    return 1;
}