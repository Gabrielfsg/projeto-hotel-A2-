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
//Retorna um apontador de tipo Data, recebendo como parametro inteiros dia, mes, ano.
//Tais que retornam uma mensagem de erro se essa data não existir.
Data* newData(int dia, int mes, int ano);
//Metodo que verifica se o ano é bissexto
int anoBissexto(Data *data);
//Metodo soma a quantidade de dias no ponteiro de data
void somaDias(Data *data, int dias);
//Mostra a data 
void printaDataEx(Data *data);
//Libera a memoria alocada
void liberaMemoriaData(Data *data);
//Metodo verifica se entre os intervaos de  datas 1 e das datas 2 existe alguma data que estao nas duas.
//retorna 1 verdadeiro e 0 falso
int dataDisponivel(Data in1, Data fin1, Data in2, Data fin2);
// verifica se a data 1 é mais recente que a data 2, 1 verdade, 0 falso
int data1maiordata2(Data data1, Data data2);
//Compara se as duas datas são iguais, 1 verdade e 0 falso.
int compararDatas(Data in1, Data fin1);
#endif /* DATA_H */

