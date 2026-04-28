/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
 #include "Hora.h"
#include "Caixa.h"
typedef struct retirada{
    int codigo;
    char descricao[100];
    Hora *hora;
    float valor;
    Caixa *caixa;
}Retirada;