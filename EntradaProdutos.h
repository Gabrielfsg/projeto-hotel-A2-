/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ENTRADAPRODUTOS_H.h
 * Author: Tales
 *
 * Created on 13 de Março de 2021, 08:37
 */

#ifndef ENTRADAPRODUTOS_H
#define ENTRADAPRODUTOS_H

#include "Produto.h"
#include "Data.h"


typedef struct notaFiscalEntrada{
    Data dataNota;
    int codCaixa;
    char nomeForn[100];
    char cnpjForn[100];
    int qteProds;
    float prFrete;
    float imposto;
    float total;
    Produto* produtosComprados;
    //VendaProdutos vp;
    int* arrayQtes;
    
    
}NotaFiscalEntrada;

void cadastrarNotaFiscalEntradaBIN(NotaFiscalEntrada nota);
#endif /* ENTRADAPRODUTOS_H */

