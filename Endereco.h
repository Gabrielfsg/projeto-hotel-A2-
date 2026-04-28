/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Endereco.h
 * Author: Daniel
 *
 * Created on 7 de Janeiro de 2021, 00:04
 */

#ifndef ENDERECO_H
#define ENDERECO_H

typedef struct endereco {
    int codigo;
    char logradouro[100];
    char bairro[100];
    char cidade[100];
    char cep[9];
    char uf[2];
    int numero;
} Endereco;

#endif /* ENDERECO_H */

