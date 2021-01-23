/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fornecedor.h
 * Author: Daniel
 *
 * Created on 7 de Janeiro de 2021, 00:07
 */

#ifndef FORNECEDOR_H
#define FORNECEDOR_H
#include "Endereco.h"

typedef struct fornecedor {
    int codigo;
    char nomeFantazia[100];
    char razaoSocial[100];
    char inscricaoEstadual[100];
    char cnpj[100];
    char telefone[14];
    char email[100];
    Endereco endereco;
} Fornecedor;
int cadastrarFornecedorTXT(Fornecedor aco) ;
int salvarFornecedorTXT(Fornecedor *aco, int num);
Fornecedor * listarFornecedorTXT();
int numLinhasFornecedor() ;
int validarFornecedor(int cod);
int cadastrarFornecedorBIN(Fornecedor *aco, int quantidade) ;
Fornecedor * listarFornecedorBIN(int *numLinha);
int editarFornecedorBIN(Fornecedor aco, int posi);
int validarFornecedorBIN(int cod) ;
int removerFornecedorBIN();
#endif /* FORNECEDOR_H */

