/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CheckOut.h
 * Author: Daniel
 *
 * Created on 7 de Janeiro de 2021, 00:06
 */

#ifndef CHECKOUT_H
#define CHECKOUT_H

#include "Data.h"
#include "CheckIn.h"

typedef struct checkOut {
    int codigo;
    float valorTotal;
    Data saida;
    int hospede;
    CheckIn checkin;
    int caixa;
} CheckOut;
int numCheckOut();
int validarCheckOut(int cod);
int cadastrarCheckOutBIN(CheckOut *cat, int quantidade);
CheckOut * listarCheckOutBIN(int *numLinha);
int editarCheckOutBIN(CheckOut cat);
int validarCheckOutBIN(int cod);
int posicaoCheckOutBIN(int cod);
int removerCheckOutBIN();
CheckOut* listarCheckOutTXT();
int salvarCheckOutTXT(CheckOut *cat, int num);
int cadastrarCheckOutTXT(CheckOut cat);
float somaCheckOutCaixa(int codigo);

#endif /* CHECKOUT_H */

