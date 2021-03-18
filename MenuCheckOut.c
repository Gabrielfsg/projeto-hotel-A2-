/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include "Principal.h"
#include "Reserva.h"
#include "Data.h"
#include "Hora.h"
#include "CheckIn.h"
#include "CheckOut.h"
#include "ContaReceber.h"
#include "ProdutoReserva.h"
#include "Caixa.h"
CheckIn getCheckIN(Reserva res, int bd);
float valorCheckOut(Reserva res, int bd);
void geraComprovanteOut(CheckOut c);

void menuCheckOut() {
    int opc = 0;

    while (opc >= 0) {
        printf("***** CHECK IN ***** \n");
        printf("1.CheckOut Hospede. \n");
        printf("2.Listar checkOut. \n");
        printf("3.Voltar. \n");
        scanf("%d*c", &opc);

        switch (opc) {
            case 1:
                checkOutHospede();
                break;
            case 2:
                pintCheckOut();
                break;
            case 3:
                opc = -1;
                break;
        }
    }

}

void checkOutHospede() {
    Data data = getDataHoje();
    int caixa = getCaixaAtual(data);
    if (caixa > 0) {
        ContaReceber cr;
        CheckOut c;
        int bd = listar();
        int cod, i;
        int num, aux;
        Data *dataIn;
        Reserva *res;
        res = listarReservasOcupadas(&num);
        if (num > 0) {
            listarHospedesControl();
            printf("********************************************************************\n");
            printf("Digite o (COD) Do HOPEDE:");
            scanf("%d*C", &cod);
            for (i = 0; i < num; i++) {
                if (res[i].hospede.codigo == cod) {
                    printf("COD: %d \n", res[i].codigo);
                    printf("DATA INI: %d /%d /%d\n", res[i].DataIn.dia, res[i].DataIn.mes, res[i].DataIn.ano);
                    printf("DATA FIM: %d /%d /%d\n", res[i].DataFin.dia, res[i].DataFin.mes, res[i].DataFin.ano);
                    printf("HOSPEDES: (%d) - %s - %s\n", res[i].hospede.codigo, res[i].hospede.nome, res[i].hospede.telefone);
                    printf("Acomodação: %s \n", res[i].acomodacao.descricao);
                    printf("Categoria:  %d \n", res[i].acomodacao.categoria.codigo);
                    printf("*******************************************************************\n");
                    aux = 1;
                }
            }
            if (aux == 1) {
                aux = 0;
                printf("Digite o (COD) da Reserva:");
                scanf("%d*c", &cod);
                for (i = 0; i < num;) {
                    if (res[i].codigo == cod) {
                        aux = 1;
                        c.codigo = res[i].codigo;
                        c.saida = data;
                        c.valorTotal = valorCheckOut(res[i], bd);
                        c.checkin = getCheckIN(res[i], bd);
                        c.hospede = res[i].hospede.codigo;
                        break;
                    }
                    i++;
                }
                if (aux == 1) {
                    printf("O pagamento sera feito : 1-Dinheiro 2-Cartão :");
                    int opc;
                    scanf("%d%*c", &opc);
                    if (opc == 1) {
                        printf("O valor Total é de %f \n", c.valorTotal);
                        // busca o cod do caixa de hoje
                        c.caixa = caixa;
                        printf("Deseja Imprimir o comprovante (1-Sim/2-Não):");
                        scanf("%d%*c", &opc);
                        // verifica e gera comprovante
                    } else if (opc == 2) {
                        c.caixa = 0;
                        printf("O valor Total é de %f \n", c.valorTotal);
                        // Cadastra em contas a receber
                        printf("Digite a Data de Vencmento do cartão:\n");
                        int dia, mes, ano;
                        aux = 0;
                        while (aux == 0) {
                            printf("Digita o dia :\n");
                            scanf("%d%*c", &dia);
                            printf("Digita o mes :\n");
                            scanf("%d%*c", &mes);
                            printf("Digita o ano :\n");
                            scanf("%d%*c", &ano);
                            dataIn = newData(dia, mes, ano);
                            if (dataIn != NULL) {
                                break;
                            }
                        }
                        cr.codigo = maiorCodContaReceber() + 1;
                        cr.caixa = 0;
                        cr.data = *dataIn;
                       strcpy(cr.pagamento, "Cartão");
                        strcpy(cr.status, "Agendado");
                        cr.valor = c.valorTotal;
                        aux = 1;
                        if (bd == 1)
                            cadastrarContaReceberTXT(cr);
                        else
                            cadastrarContaReceberBIN(&cr, 1);

                    }
                    if (aux = 1) {
                        if (bd == 1) {
                            cadastrarCheckOutTXT(c);
                        } else {
                            cadastrarCheckOutBIN(&c, 1);
                        }
                        printf("Cadastro realizado com sucesso!!\n");
                        editarReservaOut(bd, res[i]);
                        printf("Deseja Imprimir o comprovante (1-Sim/2-Não):");
                        scanf("%d%*c", &opc);
                        if (opc == 1) {
                            geraComprovanteOut(c);
                        }
                    }
                } else {
                    printf("Nenhuma Reserva encontrada!!\n");
                }
            } else {
                printf("Nenhum reserva deste Hospede encontrada!!\n");
            }
        } else {
            printf("Nenhuma Reserva encontrada!!\n");
        }
        free(res);
    } else {
        printf("Caixa fechado!!, favor abrilo\n");

    }
}

void printReservaOut(Reserva *res, int num) {
    int i;
    for (i = 0; i < num; i++) {

        printf("*************Reserva %d ****************\n", i + 1);
        printf("COD: %d \n", res[i].codigo);
        printf("DATA INI: %d /%d /%d\n", res[i].DataIn.dia, res[i].DataIn.mes, res[i].DataIn.ano);
        printf("DATA FIM: %d /%d /%d\n", res[i].DataFin.dia, res[i].DataFin.mes, res[i].DataFin.ano);
        printf("HOSPEDES: (%d) - %s - %s\n", res[i].hospede.codigo, res[i].hospede.nome, res[i].hospede.telefone);
        printf("Acomodação: %s \n", res[i].acomodacao.descricao);
        printf("Categoria:  %s \n", res[i].acomodacao.categoria.descricao);
        printf("\n");
    }
}

float valorCheckOut(Reserva res, int bd) {
    CheckIn *cat;
    int num, i;
    float valor = 0, valor2 = 0;
    if (bd == 1) {
        cat = listarCheckInTXT();
        num = numCheckIn();
    } else {
        cat = listarCheckInBIN(&num);
    }
    for (i = 0; i < num; i++) {
        if (res.codigo == cat[i].codigo && (strcmp(cat[i].status, "pendente") == 0)) {
            valor = cat[i].valor;
        }
    }
    valor2 = somaProdutosConsumido(res.codigo);
    printf("%f", valor2);
    valor = valor + valor2;
    return valor;
    //free(cat);
}

CheckIn getCheckIN(Reserva res, int bd) {
    CheckIn *cat;
    int num, i;
    if (bd == 1) {
        cat = listarCheckInTXT();
        num = numCheckIn();
    } else {
        cat = listarCheckInBIN(&num);
    }
    for (i = 0; i < num; i++) {
        if (res.codigo == cat[i].codigo && (strcmp(cat[i].status, "pendente") == 0)) {
            return cat[i];
            free(cat);
        }
    }
}

void editarReservaOut(int bd, Reserva r) {
    Reserva *res;
    int num;
    if (bd == 1) {
        res = listarReservaTXT();
        num = numReserva();
    } else {
        res = listarReservaBIN(&num);
    }
    int i;
    for (i = 0; i < num;) {
        if (res[i].codigo == r.codigo) {
            res[i].status = 2;
            break;
        }
        i++;
    }
    if (bd == 1) {
        salvarReservaTXT(res, num);
    } else {

        editarReservaBIN(res[i], i);
    }
    free(res);
}

void pintCheckOut() {
    int bd = listar();
    CheckOut *c;
    int num;
    if (bd == 1) {
        c = listarCheckOutTXT();
        num = numCheckOut();
    } else {
        c = listarCheckOutBIN(&num);
    }
    int i;
    for (i = 0; i < num; i++) {
        printf("COD : %d \n", c[i].codigo);
        printf("Data: %d:%d:%d \n", c[i].saida.dia, c[i].saida.mes, c[i].saida.ano);
        printf("Hospede : %d \n", c[i].hospede);
        printf("Valor : %f \n", c[i].valorTotal);
        printf("********************************\n");

    }

}

void geraComprovanteOut(CheckOut c) {

}