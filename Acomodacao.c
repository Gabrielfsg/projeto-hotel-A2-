/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "Categoria.h"
typedef struct acomodacao {
    int codigo;
    char descricao[100];
    char status[50];
    Categoria *categoria;
} Acomodacao;