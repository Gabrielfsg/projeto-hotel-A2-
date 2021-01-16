/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hospede.h
 * Author: Daniel
 *
 * Created on 7 de Janeiro de 2021, 00:07
 */

#ifndef HOSPEDE_H
#define HOSPEDE_H

//typedef struct hospede Hospede;
typedef struct hospede {
    int codigo;
    char nome[100];
    char cpf[14];
    char telefone[14];
    char email[100];
    char sexo; //M- masculino F-Feminino
    char esCivil[10];
    //Data *dataNascimento;
    //Endereco *endereco;
} Hospede;


#endif /* HOSPEDE_H */

