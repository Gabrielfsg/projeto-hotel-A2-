/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProdutoReserva.h
 * Author: Daniel
 *
 * Created on 12 de Março de 2021, 10:56
 */

#ifndef PRODUTORESERVA_H
#define PRODUTORESERVA_H
#include "Data.h"
#include "Produto.h"
#include "Reserva.h"

typedef struct produtoReserva {
    int codProd;
    int codRes;
    int quantidade;
    Data data;
} ProdutoReserva;


float somaProdutosConsumido(int reserva);
ProdutoReserva* getAllProdutoReservaBIN(int* numProdutos);
ProdutoReserva* getAllProdutoReservaTXT(int numProdutos);
#endif /* PRODUTORESERVA_H */