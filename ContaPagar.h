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

typedef struct contaPagar{
    int codigo;
    char descricao[50];
    float valor;
    Data data;
    char status[50];
    Caixa caixa;
    //Fornecedor *fornecedor;
    int codForn;
}ContaPagar;

#endif /* CONTASPAGAR_H */

