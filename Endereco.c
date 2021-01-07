/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

typedef struct endereco {
    int codigo;
    char logradouro[100];
    char bairro[100];
    char cidade[100];
    char cep[9];
    char uf[2];
    int numero;
} Endereco;