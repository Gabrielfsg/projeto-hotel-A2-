/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ContaReceber.h
 * Author: Daniel
 *
 * Created on 7 de Janeiro de 2021, 00:06
 */

#ifndef CONTARECEBER_H
#define CONTARECEBER_H
#include "Data.h"

typedef struct contaReceber {
    int codigo;
    float valor;
    Data data;
   // int status;
    char status[100];
    char pagamento[100];
   // int formaPagamento;
    int caixa;
} ContaReceber;
int maiorCodContaReceber();
int removerContaReceberBIN();
int posicaoContaReceberBIN(int cod);
int validarContaReceberBIN(int cod);
int editarContaReceberBIN(ContaReceber cat);
ContaReceber * listarContaReceberBIN(int *numLinha);
int cadastrarContaReceberBIN(ContaReceber *cat, int quantidade);
int validarContaReceber(int cod);
int numContaReceber();
ContaReceber* listarContaReceberTXT();
int salvarContaReceberTXT(ContaReceber *cat, int num);
int cadastrarContaReceberTXT(ContaReceber cat);
//float somaContaReceberCaixa(Data data);
#endif /* CONTARECEBER_H */

