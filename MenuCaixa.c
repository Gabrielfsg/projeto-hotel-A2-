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
        c = caixaAberto();
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
                // c.codigo = getCaixaAtual(data);
                if (c.codigo > 0) {
                    printf("Caixa Aberto!!\n");
                } else {
                    printf("Digite o valor inicial do caixa: ");
                    scanf("%f*c", &c.valorIn);
                    printf("DEBUG 1 -> VALOR INI DO CAIXA É: %f \n", c.valorIn);
                    c.codigo = maiorCodCaixa() + 1;
                    c.data = data;
                    strcpy(c.status, "aberto");
                    //printf("DEBUG 2 \n");
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
                        c.valorFin = somaValores();
                        strcpy(c.status, "fechado");
                        if (bd == 1) {
                            fecharCaixaTXT(c);
                        } else {
                            fecharCaixaBIN(c);
                        }
                        printf("Caixa Fechado com sucesso!!\n");
                    } else {

                    }
                }
                break;
            case 4:
                if (c.codigo > 0) {
                    printf("entrou!!\n");
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