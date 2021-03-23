/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include "Categoria.h"
#include "Acomodacao.h"
#include "Hospede.h"
#include "HospedeMenu.h"
#include "Reserva.h"
#include "Hotel.h"
#include "Data.h"
#include "ContaReceber.h"
#include "SalvametoBD.h"
#include "ContaPagar.h"
#include "MenuEntradaProdutos.h"
#include "Caixa.h"

void menuContas() {
    int opc = 0;
    int aux = 0;
    while (opc >= 0) {
        printf("*******  Contas **********\n");
        printf("1.Contas a Receber.\n");
        printf("2.Listar Pagar Conta. (Para Atualizar selecione essa opção novamente)\n");
        printf("3.Listar Contas Receber. (Para Atualizar selecione essa opção novamente) \n");
        printf("4.Voltar.\n");
        scanf("%d%*c", &opc);
        switch (opc) {
            case 1:
                contasRec();
                break;
            case 2:
                atualizar();
                break;
            case 3:
                atualizarCR();
                break;
            case 4:
                subCaixa();
                break;
            default:
                printf("Valor Invalido!\n");
                break;
        }
    }

}

void contasRec() {
    ContaReceber cr;
    Data dataH = getDataHoje();
    int bd = listar();
    int aux = 0, aux2 = 0;
    int cod = caixaAberto().codigo;
    int r;
    if (bd > 0) {
        printf("### RECEBER CONTAS ### \n");
        printf("Entre com o código da conta: ");
        scanf("%d%*c", &cr.codigo); // validar
        printf("Entre com o valor da conta: ");
        scanf("%f%*c", &cr.valor);
        printf("Digite o status da conta: \n"
                "1.Cocluido. \n"
                "2.Pendente.");
        scanf("%d*c", &aux);
        if (aux == 1) {
            strcpy(cr.status, "Concluido");
            strcpy(cr.pagamento, "Dinheiro");
            cr.data.dia = dataH.dia;
            cr.data.mes = dataH.mes;
            cr.data.ano = dataH.ano;
        } else if (aux == 2) {
            strcpy(cr.status, "Pendente");
            strcpy(cr.pagamento, "Cartão");
            printf("Entre com o dia de pagamento: ");
            scanf("%d%*c", &cr.data.dia);
            printf("Entre com o mês de pagamento: ");
            scanf("%d%*c", &cr.data.mes);
            printf("Entre com o ano do pagamento: ");
            scanf("%d%*c", &cr.data.ano);
        }
        cr.caixa = cod;
        if (bd == 1) {
            r = cadastrarContaReceberTXT(cr);
        } else if (bd == 2) {
            r = cadastrarContaReceberBIN(&cr, 1);
        }
        if (aux == 1) {
            if (r == 1) {
                somaContaReceberCaixa(cr.data);
            }
        }
    }

}

