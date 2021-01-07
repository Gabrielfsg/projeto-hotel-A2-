/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include"Data.h"
#include"Endereco.h"
typedef struct hospede {
    int codigo;
    char nome[100];
    char cpf[14];
    char telefone[14];
    char email[100];
    char sexo; //M- masculino F-Feminino
    char esCivil[10];
    Data *dataNascimento;
    Endereco *endereco;
} Hospede;