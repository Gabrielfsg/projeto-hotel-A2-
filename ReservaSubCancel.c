/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include "Categoria.h"
#include "Acomodacao.h"
#include "Hospede.h"
#include "HospedeMenu.h"
#include "Reserva.h"
#include "Hotel.h"

#include "SalvametoBD.h"

#include "ReservaSubCancel.h"

void CancelarReserva() {
    int bd = listar();
    int cod;
    int numReservas = 0;
    Reserva* arrayReservas;
    if (bd == 1) {
        //TXT        
        arrayReservas = listarReservaTXT();
        numReservas = numReserva();
    }
    if (bd == 2) {
        //BIN
        arrayReservas = listarReservaBIN(&numReservas);
    }

    if (numReservas == 0) {
        printf("NENHUMA RESERVA CADASTRADA\n");
    } else {

        printf("LISTA DE RESERVAS FEITAS: %d \n", numReservas);
        for (int i = 0; i < numReservas; i++) {
            printf("************************\n");
            printf("COD: %d \n", arrayReservas[i].codigo);
            printf("DATA INI: %d / %d / %d \n", arrayReservas[i].DataIn.dia, arrayReservas[i].DataIn.mes, arrayReservas[i].DataIn.ano);
            printf("DATA FIM: %d / %d / %d \n", arrayReservas[i].DataFin.dia, arrayReservas[i].DataFin.mes, arrayReservas[i].DataFin.ano);
            printf("COD ACOMOD: %d \n", arrayReservas[i].acomodacao.codigo);
            printf("HÓSPEDE: (%d) - %s \n", arrayReservas[i].hospede.codigo, arrayReservas[i].hospede.nome);
            printf("************************\n");
        }

        printf("Digite o código da reserva que deseja cancelar:\n");
        scanf("%d%*c", &cod);

        int validacao = 0;
        if (bd == 1) {
            //TXT
            validacao = validarReserva(cod);
            //printf("VALID TXT == %d\n",validacao);
        }
        if (bd == 2) {
            //BIN
            validacao = validarReservaBIN(cod);
            // printf("VALID BIN == %d\n",validacao);
        }

        if (validacao == 1) {
            //printf("VALID == 1\n");
            int retorno = 0;
            if (bd == 1) {
                //TXT
                retorno = removerReservaTXT(cod);
                
            }
            if (bd == 2) {
                //BIN
                retorno = deletarReservaBIN(cod);
            }

           /* printf("RETORNO É %d\n",retorno);
            if (retorno == 1) {
                printf("RESERVA CANCELADA COM SUCESSO\n");
            } else {
                printf("ERRO AO CANCELAR RESERVA\n");
            }
            */
        } else {
            printf("CÓDIGO INVÁLIDO \n");
        }
    }
}