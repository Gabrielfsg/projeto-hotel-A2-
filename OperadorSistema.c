/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include"Hotel.h"
typedef struct operadorSistema {
    int codigo;
    char nome[100];
    char usuario[100];
    char senha[100];
    int permicao;
    Hotel *hotel;
} OperadorSistema;