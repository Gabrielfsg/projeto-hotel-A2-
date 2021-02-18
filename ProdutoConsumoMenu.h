/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProdutosMenu.h
 * Author: Tales
 *
 * Created on 10 de Janeiro de 2021, 17:16
 */

#ifndef PRODUTOSCONSUMOMENU_H
#define PRODUTOSCONSUMOMENU_H
#include "Produto.h"

void menuCRUDProdConsumo();
void cadastrarProdConsumoControl();
void listarProdConsumoControl();
Produto getProdConsumoByCodControl();
void atualizarProdConsumoControl();
void deletarProdConsumoControl();
int validarCodProdConsumo(int cod, int ext);

#endif /* PRODUTOSMENU_H */

