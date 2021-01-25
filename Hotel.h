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
    char nomeFantazia[100];
    char razaoSocial[100];
    char inscricaoEstadual[100];
    char cnpj[100];
    int telefone;
    char email[100];
    char nomeResponsavel[100];
    char teleRes[14];
    char checkIn[100];
    char checkOut[100];
    float margemLucro;
    char logradouro[100];
    char bairro[100];
    char cidade[100];
    int cep;
    char uf[2];
    int numero;
} Hotel;

Hotel* listarHotelBIN(int *numLinha);
//int cadastrarHotelBin(Hotel h, int quantidade);

#endif /* HOTEL_H */

