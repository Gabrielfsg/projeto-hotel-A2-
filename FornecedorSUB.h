/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FornecedorControl.h
 * Author: Tales
 *
 * Created on 10 de Janeiro de 2021, 18:30
 */

#ifndef FORNECEDORCONTROL_H
#define FORNECEDORCONTROL_H
#include "Fornecedor.h"
void listarFornecedor();
void cadastrarFornecedor();
void atualizarFornecedor();
void deletarFornecedor();
int cadastrarFornecedorControle(Fornecedor cat);
int cadastrarFornecedorControleBIN(Fornecedor *cat, int qtd);
int editarFornecedorControleBIN(Fornecedor cat) ;
int removerFornecedorControleBIN(int cod);
int printCategoria(Fornecedor * a);
#endif /* FORNECEDORCONTROL_H */

