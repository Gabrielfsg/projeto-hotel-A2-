/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <String.h>

#include "Principal.h"

void cadReserva() {
    int opc = 0;
    while (opc >= 0) {
        printf("***** CADASTRAR RESERVA ***** \n");
        printf("1.Reservar por Data. \n");
        printf("2.Reservar por categoria da acomodação. \n");
        printf("3.Reservar por quantidade de pessoas. \n");
        printf("4.Reservar por tipo de facilidade. \n");
        printf("5.Reservar por combinação de critérios. \n");
        printf("5.Voltar. \n");
        scanf("%d*c", &opc);

        switch (opc) {
            case 1:
                
                break;
            case 2:
                
                break;
            case 3:
                reservaPQuantidade();
                break;
            case 4:
                
                break;
            case 5:
                subReservas();
                break;

        }





    }

}



