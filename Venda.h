/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Venda.h
 * Author: Daniel
 *
 * Created on 7 de Janeiro de 2021, 00:08
 */

#ifndef VENDA_H
#define VENDA_H
#include "Data.h"

typedef struct venda{
    int codVenda;
    float valorTotal;
    Data dataVenda;
    int codCaixa;
}Venda;
    
int cadastrarVendaTXT(Venda v);
int salvarVendaTXT(Venda *ven, int num);
int cadastrarVendaBIN(Venda v);
int salvarVendaBIN(Venda *ven, int quantidade);
int maiorCodVenda();
Venda* listarVendaTXT(int numVendas);
Venda* listarVendaBIN(int *numVendas);
int numVendas();
float somaVendaCaixa(int caixa);
#endif /* VENDA_H */

