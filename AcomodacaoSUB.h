/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HospedeControl.h
 * Author: Tales
 *
 * Created on 8 de Janeiro de 2021, 08:51
 */
#include "Acomodacao.h"
#ifndef ACOMODACAOCONTROL_H
#define ACOMODACAOCONTROL_H

void listarAcomodacao();
void cadastrarAcomodacao();
void atualizarAcomodacao();
void deletarAcomodacao();

int printCategoria(Acomodacao *a);
//verifica se existe categoria com codigo igual e caso 0 e cadastra
int cadastrarAcomodacaoControle(Acomodacao cat) ;
//
//lista o tamanho do vetor de categoria do arquivo txt
int numLinhasAcomodacao();

int editarAcomodacaoTXT(Acomodacao *cat, Acomodacao c, int num, int i) ;

int excluirAcomodacao(int cod);

int cadastrarAcomodacaoControleBIN(Acomodacao *cat, int qtd) ;

int removerAcomodacaoControleBIN(int cod);
#endif /* ACOMODACAOCONTROL_H */

