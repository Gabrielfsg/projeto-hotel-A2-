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

//typedef struct categoria Categoria;

typedef struct categoria {
    int codigo;
    char descricao[100];
    float valorDiario;
    int quantidadePessoas;
    char facilidade[100];
} Categoria;
int cadastrarCategoriaTXT(Categoria cat);

int salvarCategoriaTXT(Categoria *cat, int num);

Categoria* listarCategoriaTXT();
Categoria* newCate(int num);
int numLinhasCategoria();
int validarCategoria(int cod);


int cadastrarCategoriaBIN(Categoria cat, int quantidade);
Categoria* listarCategoriaBIN(int *numLinha);
int contCategoria();
int removerCategoriaBIN();
int validarCategoriaBIN(int cod);
int editarCategoriaBIN(Categoria cat, int posi);

#endif /* CATEGORIA_H */

