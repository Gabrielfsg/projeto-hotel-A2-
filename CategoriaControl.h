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
void cadastrarCategoriaControle(int codig, char descricao[], float valorDiario, int qtd, char facilidade[]);
void mostrarCategoriaControle();
/*void atualizarCategoria();
void deletarCategoria();*/
#endif /* CATEGORIACONTROL_H */

