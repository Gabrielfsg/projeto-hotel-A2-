/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Categoria.h
 * Author: Daniel
 *
 * Created on 7 de Janeiro de 2021, 00:05
 */

#ifndef CATEGORIA_H
#define CATEGORIA_H

typedef struct categoria Categoria;
Categoria* newCategoria(int codig, char descricao[], float valorDiario, int qtd, char facilidade[]);
void cadastrarCategoriaTXT(int codig, char descricao[], float valorDiario, int qtd, char facilidade[]);
Categoria* listarCategoriaTXT();
Categoria* newCate(int num) ;
void add(Categoria *cat,int posicao, int codig, char descricao[], float valorDiario, int qtd, char facilidade[]);
void mostrar(Categoria *cat, int numLinha);
int numLinhas();

#endif /* CATEGORIA_H */

