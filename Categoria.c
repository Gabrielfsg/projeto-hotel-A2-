/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Categoria.c
 * Author: Daniel
 *
 * Created on 6 de Janeiro de 2021, 23:14
 */

typedef struct categoria {
    int codigo;
    char descricao[100];
    float valorDiario;
    int quantidadePessoas;
    char facilidade[];
} Categoria;
