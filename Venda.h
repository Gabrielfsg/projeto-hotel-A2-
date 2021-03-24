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
    
Venda* listarVendaTXT();
Venda* listarVendaBIN();
//float somaVendaCaixa(Data data);
#endif /* VENDA_H */

