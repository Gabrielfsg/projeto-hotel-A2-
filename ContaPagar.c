/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Fornecedor.h"
#include"Caixa.h"
#include"Data.h"
typedef struct contaPagar{
    int codigo;
    char descricao;
    float valor;
    Data *data;
    char status;
    Caixa *caixa;
    Fornecedor *fornecedor;
}ContaPagar;