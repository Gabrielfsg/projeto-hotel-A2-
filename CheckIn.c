/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Reserva.h"
#include "Hora.h"
typedef struct checkIn {
    int codigo;
    float valor;
    Hora *hora;
    char status[10];
    Reserva *reserva;
} CheckIn;