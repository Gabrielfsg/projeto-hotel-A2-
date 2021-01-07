/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Data.h"
typedef struct contaReceber{
    int codigo;
    Data *data;
    float calor;
    char status;
    char pagamento[];
}ContaReceber;