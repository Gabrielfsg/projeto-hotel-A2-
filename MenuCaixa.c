/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include "Principal.h"
#include "Caixa.h"
#include "CheckIn.h"
#include "CheckOut.h"
#include "ContaReceber.h"
#include "ContaPagar.h"
#include "Venda.h"
#include "MenuCaixa.h"

void menuCaixa() {
    float total;
    int opc = 0;
    Caixa c;
    Data data = getDataHoje();
    int bd = listar();
    while (opc >= 0) {
        printf("***** CAIXA***** \n");
        printf("Data: %d/%d/%d. \n", data.dia, data.mes, data.ano);
        printf("1.Abrir Caixa. \n");
        printf("2.Saldo Caixa. \n");
        printf("3.Fechar caixa. \n");
        printf("4.Relatorio caixa. \n");
        printf("5.Voltar. \n");
        scanf("%d*c", &opc);
        switch (opc) {
            case 1:
                c.codigo = getCaixaAtual(data);
                if (c.codigo > 0) {
                    printf("Caixa Aberto!!\n");
                } else {
                    printf("Digite o valor inicial do caixa: ");
                    scanf("%f*c", &c.valorIn);
                    printf("DEBUG 1 -> VALOR INI DO CAIXA É: %f \n", c.valorIn);
                    c.codigo = maiorCodCaixa() + 1;
                    c.data = data;
                    strcpy(c.status, "aberto");
                    if (bd == 1) {
                        cadastrarCaixaTXT(c);
                    } else {
                        cadastrarCaixaBIN(&c, 1);
                    }
                    printf("Caixa Aberto!!\n");
                }
                break;
            case 2:
                c.codigo = getCaixaAtual(data);
                if (c.codigo > 0) {
                    total = somaValores();
                    printf("O saldo do caixa é de R$ %f\n", total);
                } else {
                    printf("caixa Fechado!!\n");
                }
                break;
            case 3:
                c.codigo = getCaixaAtual(data);
                if (c.codigo > 0) {
                    printf("Deseja Fechar o caixa Aberto? 1-Sim 2-Não\n");
                    scanf("%d*c", &opc);
                    if (opc == 1) {
                        c = caixaAberto();
                        c.valorFin = somaValores();
                        strcpy(c.status, "fechado");
                        if (bd == 1) {
                            fecharCaixaTXT(c);
                        } else {
                            fecharCaixaBIN(c);
                        }
                        printf("Caixa Fechado com saldo %f\n", c.valorFin);
                        printf("Caixa Fechado com sucesso!!\n");
                    } else {
                        printf("Operação canseada!!\n");
                    }
                } else {
                    printf("caixa Fechado!!\n");
                }
                break;
            case 4:
                c.codigo = getCaixaAtual(data);
                if (c.codigo > 0) {
                    relatorioValoresCaixa();
                } else {
                    printf("Caixa Fechado!!\n");
                }
                break;
            case 5:
                opc = -1;
                break;
        }
    }
}

float somaValores() {
    Caixa c = caixaAberto();
    float checkIn = 0;
    float checkOut = 0;
    float contasRece = 0;
    float prodV = 0;
    float final = 0;
    float retiradas = 0;
    checkIn = somaCheckInCaixa(c.codigo);
    contasRece = somaContaReceberCaixa(c.data);
    retiradas = somaContaPagarCaixa(c.data);
    prodV = somaVendaCaixa(c.codigo);
    printf("Soma valores\n");
    checkOut = somaCheckOutCaixa(c.codigo);
    final = checkIn + checkOut + contasRece + prodV + c.valorIn - retiradas;
    //printf("DEBUG NO SOMA VALORES: RETIRADAS = %f  FINAL = %f:\n", retiradas, final);
    return final;
}

void relatorioValoresCaixa() {
    Caixa c = caixaAberto();
    float checkIn = 0;
    float contasRece = 0;
    float prodV = 0;
    float final = 0;
    float retiradas = 0;
    float checkOut = 0;
    checkIn = somaCheckInCaixa(c.codigo);
    //printf("CheckIn +%f \n", checkIn);
    // printf("CheckOut +%f \n", checkOut);
    contasRece = somaContaReceberCaixa(c.data);
    retiradas = somaContaPagarCaixa(c.data);
    prodV = somaVendaCaixa(c.codigo);
    printf("Valor Inicial %f \n", c.valorIn);
    printf("CheckIn %f \n", checkIn);
    checkOut = somaCheckOutCaixa(c.codigo);
    printf("CheckOut %f \n", checkOut);
    printf("Montante de Cartão %f \n", contasRece);
    printf("Produtos Vendidos %f \n", prodV);
    printf("Dividas pagas -%f \n", retiradas);
    final = checkIn + checkOut + contasRece + prodV + c.valorIn - retiradas;
    printf("SALDO: %f \n", final);
}

void listarCaixaData(int dia1, int dia2, int mes) {
    //VERIFICAR EXTENSÃO DO ARQUIVO
    int ext = listar();
    int numCaixa;
    Caixa* cai;
    if (ext == 2) {
        //BIN
        cai = listarCaixaBIN(&numCaixa);
        //printf("NUM PROD = %d\n", numProdutos);
    }
    if (ext == 1) {
        //TXT
        cai = listarCaixaTXT();

    }
    printf("***** LISTA Dos Caixas*****\n");
    for (int i = 0; i < numCaixa; i++) {
        //lista os produtos
        if (cai[i].data.mes == mes && cai[i].data.dia >= dia1 && cai[i].data.dia <= dia2) {
            printf("***************\n");
            printf("COD: %d\n", cai[i].codigo);
            printf("DESC: %s\n", cai[i].status);
            printf("Data: /%d/%d/%d/", cai[i].data.dia, cai[i].data.mes, cai[i].data.ano);
            printf("Valor Inicial: %f\n", cai[i].valorIn);
            printf("Valor Final: %f\n", cai[i].valorFin);
            printf("***************\n");
        }
    }
    printf("\n FIM DA LISTA DE PRODUTOS \n");
}

Caixa* filtrarCaixaDataControl(int dia1, int dia2, int mes) {
    int numCaixa = 0; // o valor será atualizado, para poder mostrar todos o caixa;
    int qteCaixaFiltro = 0;
    int index = 0;

    Caixa* arrayCaixa;
    Caixa* arrayFiltrado;


    //pega a extensão do arquivo
    int ext = listar();
    if (ext == 2) {
        //BIN
        arrayCaixa = listarCaixaBIN(&numCaixa);
        //printf("NUM PROD = %d\n", numProdutos);
    }
    if (ext == 1) {
        //TXT
        arrayCaixa = listarCaixaTXT();

    }
    
    for (int i = 0; i < numCaixa; i++) {// faz o filtro pegando apenas os dados que interessa
        if (arrayCaixa[i].data.mes == mes && arrayCaixa[i].data.dia >= dia1 && arrayCaixa[i].data.dia <= dia2) {
            qteCaixaFiltro++;

        }
    }



    arrayFiltrado = (Caixa *) malloc(sizeof (Caixa) * qteCaixaFiltro);// cria o array dinamico com o tamanho correto

    for (int i = 0; i < numCaixa; i++) {
        if (arrayCaixa[i].data.mes == mes && arrayCaixa[i].data.dia >= dia1 && arrayCaixa[i].data.dia <= dia2) {
            arrayFiltrado[index] = arrayCaixa[i];
            //printf("ADD O HOSPEDE (%s) NA POS: %d\n", arrayFiltrado[i].nome, index);
            index++;
        }

    }

    gerarCSVCaixa(arrayFiltrado, qteCaixaFiltro);// chama o arquivo que converte


}

void gerarCSVCaixa(Caixa* arrayF, int qte) {// cria arquivo csv que recebe a struct de caixa e a quantidade
    printf("ENTROU GERAR CSV\n");
    printf("COD = %d\n", arrayF[1].codigo);
    printf("QTE = %d\n", qte);
    FILE* arCaixa;



    arCaixa = fopen(".\\relatorios\\Caixa_Data", "w");// cria arquivo


    for (int i = 0; i < qte; i++) {
        printf("DENTRO DO FOR\n");

        fprintf(arCaixa, "%d,%s,%d,%d,%d,%f,%f)", arrayF[i].codigo, arrayF[i].status, arrayF[i].data.dia, arrayF[i].data.mes, arrayF[i].data.ano, arrayF[i].valorIn, arrayF[i].valorFin);
        fprintf(arCaixa, "\n");// grava os dados
    }


    fflush(arCaixa);
    fclose(arCaixa);

}
