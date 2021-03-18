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

void menuContas() {
    int opc = 0;
    while (opc >= 0) {
        printf("*******  Contas **********\n");
        printf("1.Contas a Receber.\n");
        printf("2.Pagar Conta.\n");
        printf("3.Listar Contas.\n");
        printf("4.Voltar.\n");
        scanf("%d%*c", &opc);
        switch (opc) {
            case 1:
                contasRec();
                break;
            case 2:
                //contaPagar();
                break;
            case 3:
                visualizarHistContas();
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
    int bd = listar();
    int aux = 0, aux2 = 0;
    if (bd > 0) {
        printf("### RECEBER CONTAS ### \n");
        printf("Entre com o código da conta: ");
        scanf("%d%*c", &cr.codigo);// validar
        printf("Entre com o valor da conta: ");
        scanf("%f%*c", &cr.valor);
        printf("Entre com o dia de pagamento: ");
        scanf("%d%*c", &cr.data.dia);
        printf("Entre com o mês de pagamento: ");
        scanf("%d%*c", &cr.data.mes);
        printf("Entre com o ano do pagamento: ");
        scanf("%d%*c", &cr.data.ano);
        printf("Digite o status da conta: \n"
                "1.Cocluido. \n"
                "2.Pendente.");
        scanf("%d*c", &aux);
        if (aux == 1) {
            strcpy(cr.status, "Concluido");
             strcpy(cr.pagamento, "Dinheiro");
        } else if (aux == 2) {
            strcpy(cr.status, "Pendente");
            strcpy(cr.pagamento, "Cartão");
        }
        printf("Entre com o código do caixa: ");
        scanf("%d%*c", &cr.caixa);
        //validar
        if (bd == 1) {
            cadastrarContaReceberTXT(cr);
            somaContaReceberCaixa(cr.data);
        } else if (bd == 2) {
            cadastrarContaReceberBIN(&cr, 1);
            somaContaReceberCaixa(cr.data);
        }

    }

}

void visualizarHistContas() {
    int n, aux;
    int bd = listar();
    ContaReceber *cr;
    if (bd == 1) {//verifica o tipo de salvamento
        cr = listarContaReceberTXT();
        n = numContaReceber();
    } else if (bd == 2) {
        cr = listarContaReceberBIN(&n);
    } else {
        printf("\nAltere a opção de salvamento em (MENU Principal->9 . Configurações-> 1. Op de BD.)\n");
    }
    if (bd > 0) {
        int i;
        if (n > 0) {
            for (i = 0; i < n; i++) {// pela contagem de linhas eles mostra os dados
                printf("\n*******%d************", i);
                printf("\nCodigo: %d", cr[i].codigo);
                printf("\nValor: %f", cr[i].valor);
                printf("\nDia Pagamento: %d", cr[i].data.dia);
                printf("\nMes Pagamento: %d", cr[i].data.mes);
                printf("\nAno Pagamento: %d", cr[i].data.ano);
                printf("\nStatus: %s", cr[i].status);
                printf("\nForma de Pagamento: %s", cr[i].pagamento);
                printf("\nCodigo do caixa: %d", cr[i].caixa);
                printf("\n");
            }
        } else {
            printf("Não à operadores cadastrados. \n");
        }
        free(cr);
    }
}

void contasPag() {
    int opc = 0;
    int cod;
    int opcao;
    while (opc >= 0) {
        printf("Entre com o código da conta: ");
        scanf("%d*c", &cod);
        //verf

        for (int i = 0; i < 0; i++) {
            // mostra a conta
        }

        printf("DESEJA PAGAR E DESCONTAR DO CAIXA: \n"
                "1.SIM. \n"
                "2.NÃO. \n"
                "OPÇÃO: ");
        scanf("%d*c", &opcao);
        if (opcao == 1) {

        } else if (opcao == 2) {

        }
    }
}

