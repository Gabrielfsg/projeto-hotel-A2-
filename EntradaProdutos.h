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


typedef struct notaFiscalEntrada{
    char nomeForn[100];
    char cnpjForn[100];
    int qteProds;
    float prFrete;
    float imposto;
    float total;
    Produto* produtosComprados;
    int* arrayQtes;
    
    
}NotaFiscalEntrada;

#endif /* ENTRADAPRODUTOS_H */

