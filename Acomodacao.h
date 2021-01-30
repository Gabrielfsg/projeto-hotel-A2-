/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Acomodacao.h
 * Author: Daniel
 *
 * Created on 7 de Janeiro de 2021, 00:05
 */

#ifndef ACOMODACAO_H
#define ACOMODACAO_H
#include "Categoria.h"
typedef struct acomodacao {
    int codigo;
    char descricao[100];
    Categoria categoria;
    char status[50];
} Acomodacao;

int cadastrarAcomodacaoTXT(Acomodacao aco);
int salvarAcomodacaoTXT(Acomodacao *aco, int num);
Acomodacao* listarAcomodacaoTXT();
int numLinhasAcomodacao();
int validarAcomodacao(int cod);
int cadastrarAcomodacaoBIN(Acomodacao *aco, int quantidade);
Acomodacao* listarAcomodacaoBIN(int *numLinha);
int editarAcomodacaoBIN(Acomodacao aco, int posi);
int validarAcomodacaoBIN(int cod);
int removerAcomodacaoBIN();


#endif /* ACOMODACAO_H */

