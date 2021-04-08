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
#include "Endereco.h"
#include "Data.h"

typedef struct hospede {
    int codigo;
    char nome[100];
    char cpf[14];
    char telefone[14];
    char email[100];
    char sexo; //M- masculino F-Feminino
    char esCivil[10];
    Data dataNascimento;
    Endereco endereco;
} Hospede;

int cadastrarHospedesTXT(Hospede h);
int cadastrarHospedesBIN(Hospede h);
int cadastrarHospedeBIN(Hospede *hos, int quantidade);
int salvarHospedeTXT(Hospede *hos, int num);
void atualizarHospedeTXT(Hospede novoHosp);
void atualizarHospedeBIN(Hospede novoHosp);
Hospede* getAllHospedesTXT(int numHospedes);
Hospede* getAllHospedesBIN(int* numHospedes);
Hospede getHospedeByCodTXT(int cod);
Hospede getHospedeByCodBIN(int cod);
void deletarHospedeTXT(int cod);
void deletarHospedeBIN(int cod);
int getNumHospedes();
#endif /* HOSPEDE_H */

