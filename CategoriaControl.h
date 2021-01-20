/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HospedeControl.h
 * Author: Tales
 *
 * Created on 8 de Janeiro de 2021, 08:51
 */

#ifndef CATEGORIACONTROL_H
#define CATEGORIACONTROL_H
#include "Categoria.h"
Categoria* listarCategoriaControle();
int cadastrarCategoriaControle(Categoria cat);
void mostrarCategoriaControle();
int numLinhas();
int salvaCategoriaTXT(Categoria *cat, int num);
int editarCategoriaTXT(Categoria *cat, Categoria c, int num);


int cadastrarCategoriaControleBIN(Categoria cat, int qtd);
Categoria* listarCategoriaControleBIN(int *num);
int editarCategoriaControleBIN(Categoria cat);
int removerCategoriaControleBIN(int cod);
#endif /* CATEGORIACONTROL_H */

