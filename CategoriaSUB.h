/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CategoriaSUB.h
 * Author: Daniel
 *
 * Created on 14 de Janeiro de 2021, 14:20
 */
#include "Categoria.h"
#ifndef CATEGORIASUB_H
#define CATEGORIASUB_H

void listarCategoriaSUB();
void mostrarCategoria();
void atualizarCategoria();
void deletarCategoria();
//verifica se existe categoria com codigo igual e caso 0 e cadastra
int cadastrarCategoriaControle(Categoria cat) ;
//
//lista o tamanho do vetor de categoria do arquivo txt
int numLinhasCategoria();

int editarCategoriaTXT(Categoria *cat, Categoria c, int num) ;

int excluirCategoria(int cod);

int cadastrarCategoriaControleBIN(Categoria cat, int qtd) ;

int removerCategoriaControleBIN(int cod);

#endif /* CATEGORIASUB_H */

