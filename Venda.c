/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Data.h"
#include "Caixa.h"
#include "ContaReceber.h"

typedef struct venda {
    int codigo;
    float valTotal;
    Data *data;
    Caixa *caixa;
    ContaReceber *contaReceber;
} Venda;