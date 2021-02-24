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

#ifndef CATEGORIASUB_H
#define CATEGORIASUB_H
#include "Categoria.h"

void listarCategoriaSUB();
void mostrarCategoria();
void atualizarCategoria();
void deletarCategoria();
int excluirCategoria(int cod);
int cadastrarCategoriaControle(Categoria cat);
int editarCategoriaTXT(Categoria *cat, Categoria c, int num);
int cadastrarCategoriaControleBIN(Categoria cat, int qtd);
int removerCategoriaControleBIN(int cod);

#endif /* CATEGORIASUB_H */

