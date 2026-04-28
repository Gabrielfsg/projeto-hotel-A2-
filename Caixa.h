/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Caixa.h
 * Author: Daniel
 *
 * Created on 7 de Janeiro de 2021, 00:05
 */

#ifndef CAIXA_H
#define CAIXA_H
#include "Data.h"

typedef struct caixa {
    int codigo;
    Data data;
    float valorIn;
    float valorFin;
    char status[8];
} Caixa;
int getCaixaAtual(Data dataHoje);
int cadastrarCaixaTXT(Caixa aco);
int fecharCaixaTXT(Caixa c);
Caixa * listarCaixaTXT();
int numCaixa();
int validarCaixa(int cod) ;
int cadastrarCaixaBIN(Caixa *aco, int quantidade);
Caixa * listarCaixaBIN(int *numLinha);
int fecharCaixaBIN(Caixa aco);
int validarCaixaBIN(int cod);
int posicaoCaixaBIN(int cod);
int removerCaixaBIN();
int maiorCodCaixa();
Caixa caixaAberto();
int salvarCaixaTXT(Caixa *aco, int num);
#endif /* CAIXA_H */

