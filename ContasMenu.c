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

void contasRec() {// cadastrar contas que o hotel recebe/ montante cartão
    ContaReceber cr;
    Data dataH = getDataHoje();
    int bd = listar();
    int aux = 0, aux2 = 0;
    int cod = caixaAberto().codigo;
    int r;
    int valid, valid2;
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
                somaContaReceberCaixa(cr.data); // se for concluido ja faz a soma
            }
        }
    }

}

void listarContasR(int c1, int c2) {
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
                if (cr[i].codigo >= c1 && cr[i].codigo <= c2) {
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
            }
        } else {
            printf("Não à operadores cadastrados. \n");
        }
        free(cr);
    }
}

void listarContasDia(int d, int m, int a) {
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
                if (cr[i].data.dia == d && cr[i].data.mes == m && cr[i].data.ano == a) {
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
            }
        } else {
            printf("Não à operadores cadastrados. \n");
        }
        free(cr);
    }
}

void filtrarContasRecFaixaCodControl(int cod1, int cod2) {
    printf("ENTROU AQUI\n");
    int n, aux;
    int bd = listar();
    
    int qte=0;
    int index=0;
    ContaReceber *cr;
    ContaReceber *crFiltrado;
    if (bd == 1) {//verifica o tipo de salvamento
        cr = listarContaReceberTXT();
        n = numContaReceber();
    } else if (bd == 2) {
        cr = listarContaReceberBIN(&n);
    } else {
        printf("\nAltere a opção de salvamento em (MENU Principal->9 . Configurações-> 1. Op de BD.)\n");
    }
        if (n > 0) {
           
/*

            printf("FOR TOTAL  ->   N = %d\n",n);
            for(int i =0;i<n;i++){
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

*/

/*
            
            for (int i = 0; i < n; i++) {
                if (cr[i].codigo >= cod1 && cr[i].codigo <= cod2) {
                    printf("CONTA %d ESTÁ DENTRO DOS COD\n",cr[i].codigo);
                    qte++;
                    printf("QTE++ = %d\n",qte);
                }else{
                    printf("CONTA %d NÃO ESTÁ DENTRO DOS COD\n",cr[i].codigo);
                }
            }
            
*/
            printf("QTE TOTAL = %d\n",qte);
            crFiltrado = (ContaReceber *) malloc(sizeof (Hospede) * qte);
            
            for (int i = 0; i < n; i++) {
                if (cr[i].codigo >= cod1 && cr[i].codigo <= cod2) {
                    crFiltrado[index] = cr[i];
                    index++;
                    //printf("ADD CONTA: %s\n",crFiltrado[index-1].pagamento);
                }
            }
            
/*
            
            printf("FOR PARA VER O ARRAY QUE VAI MANDAR PARA O CSV\n");
            for(int i =0; i<qte;i++){
                printf("\n*******%d************", i);
                    printf("\nCodigo: %d", crFiltrado[i].codigo);
                    printf("\nValor: %f", crFiltrado[i].valor);
                    printf("\nDia Pagamento: %d", crFiltrado[i].data.dia);
                    printf("\nMes Pagamento: %d", crFiltrado[i].data.mes);
                    printf("\nAno Pagamento: %d", crFiltrado[i].data.ano);
                    printf("\nStatus: %s", crFiltrado[i].status);
                    printf("\nForma de Pagamento: %s", crFiltrado[i].pagamento);
                    printf("\nCodigo do caixa: %d", crFiltrado[i].caixa);
                    printf("\n");
            }
            
*/

            gerarCSVContasRec(crFiltrado,qte,1);
            

        } else {
            printf("Não à contas cadastradas. \n");
        }
        free(cr);
    
}