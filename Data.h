/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Data.h
 * Author: Daniel
 *
 * Created on 22 de Dezembro de 2020, 10:36
 */

#ifndef DATA_H
#define DATA_H

typedef struct data {
    int dia;
    int mes;
    int ano;
} Data;

Data* newData(int dia, int mes, int ano);

int anoBissexto(Data *data);

void somaDias(Data *data, int dias);

void printaDataEx(Data *data);

void liberaMemoriaData(Data *data);

#endif /* DATA_H */

