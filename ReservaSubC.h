/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ReservaSubC.h
 * Author: Daniel
 *
 * Created on 31 de Janeiro de 2021, 12:29
 */

#ifndef RESERVASUBC_H
#define RESERVASUBC_H
#include "Data.h"
#include "Acomodacao.h"
#include "Reserva.h"
Acomodacao* listarAcomodacoesDisponiveis(Data in, Data fin, int *quantidadeAcoDisponiveis) ;
void reservar2();
void mostrarReservas();
void reservar3() ;
void reservaPCategoria();
void reservaPQuantidade();
Reserva * listarResTXT();
#endif /* RESERVASUBC_H */

