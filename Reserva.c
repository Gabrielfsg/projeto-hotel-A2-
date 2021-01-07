/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
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