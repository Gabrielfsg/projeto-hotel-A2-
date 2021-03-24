/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CheckIn.h
 * Author: Daniel
 *
 * Created on 7 de Janeiro de 2021, 00:05
 */

#ifndef CHECKIN_H
#define CHECKIN_H
#include "Reserva.h"
#include "Hora.h"

typedef struct checkIn {
    int codigo;
    float valor;
    Hora hora;
    char status[10];
    Reserva reserva;
    int caixa;
} CheckIn;
#endif /* CHECKIN_H */
int cadastrarCheckInTXT(CheckIn cat);
int salvarCheckInTXT(CheckIn *cat, int num);
CheckIn* listarCheckInTXT();
int numCheckIn();
int validarCheckIn(int cod) ;
int cadastrarCheckInBIN(CheckIn *cat, int quantidade);
CheckIn * listarCheckInBIN(int *numLinha);
int editarCheckInBIN(CheckIn cat);
int validarCheckInBIN(int cod);
int posicaoCheckInBIN(int cod);
int removerCheckInBIN();
//float somaCheckInCaixa(int codigo);

