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
    Data *DataIn;
    Data *DataFin;
    Acomodacao *acomodacao;
    Hospede *hospede;
} Reserva;


#endif /* RESERVA_H */

