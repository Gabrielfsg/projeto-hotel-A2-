/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ContasPagar.h
 * Author: Daniel
 *
 * Created on 7 de Janeiro de 2021, 00:06
 */

#ifndef CONTASPAGAR_H
#define CONTASPAGAR_H
#include "Caixa.h"

typedef struct contaPagar {
    int codigo;
    char descricao[50];
    float valor;
    Data data;
    char status[50];
    Caixa caixa;
    //Fornecedor *fornecedor;
    int codForn;
} ContaPagar;
int cadastrarContaPagarTXT(ContaPagar cp);
int cadastrarContaPagarBIN(ContaPagar *conta, int quantidade);
ContaPagar* listarContaPagarTXT(int numContasPagar);
ContaPagar* listarContaPagarBIN(int* numContasPagar);
int atualizar();
void mostrarContasPagar();
int editarStatusBIN(ContaPagar cp, int posi);
int editarStatusTXT(ContaPagar *arrayPC, ContaPagar cp, int num) ;
int salvarContasPagarTXT(ContaPagar *arrayCP, int num);
int maiorCodContasPagar();
int getNumContaPagar();
int maiorCodContasPagar() ;
float somaContaPagarCaixa(Data data);

#endif /* CONTASPAGAR_H */

