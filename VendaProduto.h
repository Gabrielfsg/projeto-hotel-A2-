/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VendaProduto.h
 * Author: Daniel
 *
 * Created on 12 de Março de 2021, 10:59
 */

#ifndef VENDAPRODUTO_H
#define VENDAPRODUTO_H
#endif

#include "Produto.h"
#include "Venda.h"

typedef struct vendaProduto {
    //Produto produto;
    int codProduto;
    //Venda venda;
    int codVenda;
    int quantidade;
} VendaProduto;
int cadastrarVendaProdutoTXT(VendaProduto vp);
int cadastrarVendaProdutoBIN(VendaProduto vp);
int salvarVendaProdutoTXT(VendaProduto *vpr, int num);
int salvarVendaProdutoBIN(VendaProduto *vpr, int quantidade);
int getNumVendaProduto();
VendaProduto* listarVendaProdutoTXT();
VendaProduto * listarVendaProdutoBIN(int *numLinha);
