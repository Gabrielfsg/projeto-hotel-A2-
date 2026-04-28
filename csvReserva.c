/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"Data.h"
#include"Endereco.h"
#include"Reserva.h"
#include"ReservaSubC.h"

void gerarCSVReserva(Reserva* arrayFiltrado, int qteResFiltro, int filtro) {
    printf("ENTROU GERAR CSV Reserva\n");

    FILE* arqRes;

    //ABRE O ARQUIVO CORRESPONDENTE AO FILTRO

    //1 -> Dados do hóspede
    //2 -> Dados da acomodação
    //3 -> Período reservado

    if (filtro == 1) {
        arqRes = fopen(".\\relatorios\\Reserva_Dados_Hospede.txt", "w");

    } else {
        if (filtro == 2) {
            arqRes = fopen(".\\relatorios\\Reserva_Dados_Acomodacao.txt", "w");
        } else {
            if (filtro == 3) {
                arqRes = fopen(".\\relatorios\\Reserva_Periodo.txt", "w");
            }
        }
    }

    for (int i = 0; i < qteResFiltro; i++) {
        //printf("DENTRO DO FOR\n");
        
        fprintf(arqRes, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%s,%d,%s,%d,%s,%s,%s,%s,%c,%s,%d,%d,%d,%d,%s,%s,%s,%s,%d,%s", arrayFiltrado[i].codigo, arrayFiltrado[i].status, arrayFiltrado[i].DataIn.dia, arrayFiltrado[i].DataIn.mes, arrayFiltrado[i].DataIn.ano, arrayFiltrado[i].DataFin.dia, arrayFiltrado[i].DataFin.mes, arrayFiltrado[i].DataFin.ano, arrayFiltrado[i].acomodacao.codigo, arrayFiltrado[i].acomodacao.descricao, arrayFiltrado[i].acomodacao.categoria.codigo, arrayFiltrado[i].acomodacao.status, arrayFiltrado[i].hospede.codigo, arrayFiltrado[i].hospede.nome, arrayFiltrado[i].hospede.cpf, arrayFiltrado[i].hospede.telefone, arrayFiltrado[i].hospede.email, arrayFiltrado[i].hospede.sexo, arrayFiltrado[i].hospede.esCivil, arrayFiltrado[i].hospede.dataNascimento.dia, arrayFiltrado[i].hospede.dataNascimento.mes, arrayFiltrado[i].hospede.dataNascimento.ano, arrayFiltrado[i].hospede.endereco.codigo, arrayFiltrado[i].hospede.endereco.bairro, arrayFiltrado[i].hospede.endereco.cep, arrayFiltrado[i].hospede.endereco.cidade, arrayFiltrado[i].hospede.endereco.logradouro, arrayFiltrado[i].hospede.endereco.numero, arrayFiltrado[i].hospede.endereco.uf);
        fprintf(arqRes, "\n");
    }

    fflush(arqRes);
    fclose(arqRes);

}