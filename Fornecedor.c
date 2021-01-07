/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Endereco.h"
typedef struct fornecedor{
    int codigo;
    char nomeFantazia[100];
    char razaoSocial[100];
    char inscricaoEstadual[100];
    char cnpj[100];
    char telefone[14];
    char email[100];
    Endereco *endereco;
}Fornecedor;