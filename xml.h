/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   xml.h
 * Author: Daniel
 *
 * Created on 2 de Abril de 2021, 10:25
 */

#ifndef XML_H
#define XML_H

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* XML_H */
#include "Acomodacao.h"
#include "Categoria.h"
#include "Caixa.h"
#include "CheckIn.h"
#include "CheckOut.h"
#include "ContaPagar.h"
#include "ContaReceber.h"
#include "Fornecedor.h"
int importarDadosXMLparaTXT(char caminho[], int tab[], int qtd);
Categoria* getCategoriaXML(char local[], int *num);
int printXMLCategoria(Categoria *cat, int num, FILE *cad);
char* geraBackupXML(int tab[], int qtd);
Acomodacao* getAcomodacaoXML(char local[], int *num);
int printXMLAcomodacao(Acomodacao *cat, int num, FILE *cad);
Caixa* getCaixaXML(char local[], int *num);
int printXMLCaixa(Caixa *cat, int num, FILE *cad);
CheckIn* getCheckInXML(char local[], int *num);
int printXMLCheckIn(CheckIn *cat, int num, FILE *cad);
CheckOut* getCheckOutXML(char local[], int *num);
int printXMLCheckOut(CheckOut *cat, int num, FILE *cad);
ContaPagar* getContaPagarXML(char local[], int *num);
int printXMLContaPagar(ContaPagar *cat, int num, FILE *cad);
ContaReceber* getContaReceberXML(char local[], int *num);
int printXMLContaReceber(ContaReceber *cat, int num, FILE *cad);
Fornecedor* getFornecedoXML(char local[], int *num);
int printXMLFornecedor(Fornecedor *cat, int num, FILE *cad);
Hospede* getHospedeXML(char local[], int *num);
int printXMLHospede(Hospede *cat, int num, FILE *cad);
Hotel* getHotelXML(char local[], int *num);
int printXMLHotel(Hotel *cat, int num, FILE *cad);
OperadorSistema* getOperadorSistemaXML(char local[], int *num);
int printXMLOperadorSistema(OperadorSistema *cat, int num, FILE *cad);
ProdutoReserva* getProdutoReservaXML(char local[], int *num);
int printXMLProdutoReserva(ProdutoReserva *cat, int num, FILE *cad);
Produto* getProdutoXML(char local[], int *num) ;
int printXMLProduto(Produto *cat, int num, FILE *cad);
Reserva* getReservaXML(char local[], int *num);
int printXMLReserva(Reserva *cat, int num, FILE *cad);
VendaProduto* getVendaProdutoXML(char local[], int *num);
int printXMLVendaProduto(VendaProduto *cat, int num, FILE *cad);
Venda* getVendaXML(char local[], int *num);
int printXMLVenda(Venda *cat, int num, FILE *cad);

