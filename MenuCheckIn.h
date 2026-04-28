/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MenuCheckIn.h
 * Author: Daniel
 *
 * Created on 10 de Março de 2021, 10:19
 */

#ifndef MENUCHECKIN_H
#define MENUCHECKIN_H
#include "Acomodacao.h"
#include "Hospede.h"
#include "Reserva.h"
#include "Data.h"

#endif /* MENUCHECKIN_H */
void menuCheckIn();
Reserva* imprimeReservaHoje(int *n);
float valorCheckIN(Reserva res, int bd);
void checkInPorData();
void printReserva(Reserva *res, int num);
void checkInHospede();
void editarReserva(int bd, Reserva r);
void pintCheckIN();
