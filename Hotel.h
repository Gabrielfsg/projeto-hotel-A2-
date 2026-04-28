/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hotel.h
 * Author: Daniel
 *
 * Created on 7 de Janeiro de 2021, 00:07
 */

#ifndef HOTEL_H
#define HOTEL_H

typedef struct hotel {
    int codigo;
    char cnpj[100];
    char email[100];
    char inscricaoEstadual[100];
    char nomeFantazia[100];
    char nomeResponsavel[100];
    int telefone;
    float margemLucro;
    char checkIn[100];
    char checkOut[100];
    char teleRes[100];
    char razaoSocial[100];
    int numero;
    char bairro[100];
    int cep;
    char logradouro[100];
    char uf[100];
    char cidade[100];
} Hotel;

Hotel* listarHotelBIN(int *numLinha);
//int cadastrarHotelBin(Hotel h, int quantidade);
Hotel * listarHTXT();
int removerHotelBIN() ;
int editarHotelTXT(Hotel *hot, Hotel h, int num);
int cadastrarHotelBin(Hotel *h, int quantidade) ;
int cadastrarHotelTXT(Hotel h);
int salvarHotelTXT(Hotel *hot, int num);
int editarHotelBin(Hotel h, int posi);

#endif /* HOTEL_H */

