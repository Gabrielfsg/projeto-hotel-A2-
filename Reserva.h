/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Reserva.h
 * Author: Daniel
 *
 * Created on 7 de Janeiro de 2021, 00:08
 */

#ifndef RESERVA_H
#define RESERVA_H

#include "Data.h"
#include "Acomodacao.h"
#include "Hospede.h"

typedef struct reserva {
    int codigo;
    Data DataIn;
    Data DataFin;
    Acomodacao acomodacao;
    Hospede hospede;
    //int hospede[10];

    int codH;
    int codA;
} Reserva;
// cadastra varias reservas no arquivo binario, o numero de reservas deve ser passado por parametro
int cadastrarReservaBIN(Reserva *aco, int quantidade);
//retorna o ponteiro de reserva com os dados de reserva no arquivo txt
Reserva * listarReservaTXT();
//cadastra reserva no arquivo txt retornado 1 caso tudo ocorrer em e 0 caso não cadastrar
int cadastrarReservaTXT(Reserva aco);
//Retorna o numeros de reservas cadastradas no arquivo txt
int numReserva() ;
// se a reserva existir retorna 1 caso contrario 0
int validarReserva(int cod) ;
Reserva * listarReservaBIN(int *numLinha);
int editarReservaBIN(Reserva aco, int posi);
int validarReservaBIN(int cod);
int removerReservaBIN();
// esse metodo é para poder gravar varias reserva no arquivo txt de uma vez so, e é passado o numero de reservas por parametro
int salvarReservaTXT(Reserva aco, int num) ;
Reserva * listarResBIN(int *numLinha);
Reserva * listarResTXT();
#endif /* RESERVA_H */

