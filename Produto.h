/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Produto.h
 * Author: Daniel
 *
 * Created on 7 de Janeiro de 2021, 00:07
 */

#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct produto{
    int codigo;
    char descricao[100];
    int estoque;
    int estoqueMinimo;
    float precoCusto;
    float precoVenda;
}Produto;

int cadastrarProdutoTXT(Produto p);
int cadastrarProdutoBIN(Produto p);
void atualizarProdutoTXT(Produto novoProd);
void atualizarProdutoBIN(Produto novoProd);
Produto* getAllProdutoTXT(int numProdutos);
Produto* getAllProdutoBIN(int* numProdutos);
Produto getProdutoByCodTXT(int cod, int numProdutos);
Produto getProdutoByCodBIN(int cod);
void deletarProdutoTXT(int cod);
void deletarProdutoBIN(int cod);

#endif /* PRODUTO_H */

