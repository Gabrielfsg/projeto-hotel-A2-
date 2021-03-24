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
#include "ContaPagar.h"
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
    int valid,valid2;
    if (bd > 0) {
        printf("### RECEBER CONTAS ### \n");
        printf("Entre com o código da conta: ");
        scanf("%d%*c", &cr.codigo);
        if (bd == 1) {// verifica se é arquivo txt 
            valid = validarCodContaTXT(cr.codigo); //passa o código digitado como parametro
            if (valid == 1) {//se resultado retornado 1
                printf("CONTA JÁ CADASTRADA! \n");
                menuContas();
            }
        } else if (bd == 2) {// faz o mesmo com o arquivo bin
            valid2 = validarCodContaBIN(cr.codigo);
            if (valid2 == 1) {
                printf("CONTA JÁ CADASTRADA! \n");
                menuContas();
            }
        }
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

/*void visualizarHistContas() {
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
 */
