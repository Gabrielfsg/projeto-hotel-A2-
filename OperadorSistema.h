/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OperadorSistema.h
 * Author: Daniel
 *
 * Created on 7 de Janeiro de 2021, 00:07
 */

#ifndef OPERADORSISTEMA_H
#define OPERADORSISTEMA_H

typedef struct operadorSistema {
    int codigo;
    char nome[100];
    char usuario[100];
    char senha[100];
    //int permicao;
} OperadorSistema;

int salvarOperadorTXT(OperadorSistema* opera, int num);
int cadastrarOpTXT(OperadorSistema opera);
int removerOperadorBIN();
int editarOpSBIN(OperadorSistema aco, int posi);
int cadastrarOpBIN(OperadorSistema op, int quantidade);
OperadorSistema* listarOpBIN(int *numLinha);
OperadorSistema* listarOpTXT();
#endif /* OPERADORSISTEMA_H */

