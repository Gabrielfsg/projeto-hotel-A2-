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
#include "MenuCheckIn.h"
#include "ContaReceber.h"
#include "Caixa.h"

void menuCheckIn() {
    int opc = 0;
    while (opc >= 0) {
        printf("***** CHECK IN ***** \n");
        printf("1.Pesquisar Reserva por Data. \n");
        printf("2.Pesquisar Reserva por Hospede. \n");
        printf("3. listar checkIN. \n");
        printf("4.Voltar. \n");
        scanf("%d*c", &opc);

        switch (opc) {
            case 1:
                checkInPorData();
                break;
            case 2:
                checkInHospede();
                break;
            case 3:
                pintCheckIN();
                break;
            case 4:
                opc = -1;
                break;
        }
    }

}

void checkInPorData() {
    ContaReceber cr;
    CheckIn c;
    Data datah = getDataHoje();
    int caixa = getCaixaAtual(datah);
    if (caixa > 0) {
        int bd = listar();
        int cod, i, aux = 0;
        int num, opc2;
        char opc;
        Data *dataIn;
        Reserva *res;
        res = listarReservasHoje(&num);
        if (num > 0) {
            printReserva(res, num);
            printf("Digite o (COD) da Reserva:");
            scanf("%d*C", &cod);
            for (i = 0; i < num;) {
                if (res[i].codigo == cod) {
                    aux = 1;
                    c.codigo = res[i].codigo;
                    c.hora = getHoraAtual();
                    c.reserva = res[i];
                    c.valor = valorCheckIN(res[i], bd);
                    break;
                }
                i++;
            }
            if (aux == 1) {
                printf("Deseja acertar o valor das diarias agora?(S/N):");
                scanf("%s%*c", &opc);
                if (opc == 'S' || opc == 's') {
                    strcpy(c.status, "pago");
                    printf("O pagamento sera feito : 1-Dinheiro 2-Cartão :");
                    scanf("%d%*c", &opc2);
                    if (opc2 == 2) {
                        c.caixa = 0;
                        printf("O valor Total é de %f \n", c.valor);
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
                        cr.valor = c.valor;
                        aux = 1;
                        if (bd == 1)
                            cadastrarContaReceberTXT(cr);
                        else
                            cadastrarContaReceberBIN(&cr, 1);

                    } else {
                        c.caixa = caixa;
                    }
                } else {
                    strcpy(c.status, "pendente");
                    c.caixa = 0;
                }
                if (aux = 1) {
                    if (bd == 1) {
                        cadastrarCheckInTXT(c);
                    } else {
                        cadastrarCheckInBIN(&c, 1);
                    }
                    printf("Cadastro realizado com sucesso!!\n");
                    editarReserva(bd, res[i]);
                    printf("Deseja Imprimir o comprovante (1-Sim/2-Não):");
                    scanf("%d%*c", &opc2);
                    if (opc2 == 1) {
                        //geraComprovante(c);
                    }
                } else {
                    printf("Nenhuma Reserva encontrada!!\n");
                }
            } else {
                printf("Nenhum reserva deste Hospede encontrada!!\n");
            }
            free(dataIn);
        } else {
            printf("Nenhuma Reserva encontrada!!\n");
        }
        free(res);
    } else {
        printf("Caixa fechado!!, favor abrilo\n");

    }
}

void checkInHospede() {
    ContaReceber cr;
    CheckIn c;
    Data *dataIn;
    Data datah = getDataHoje();
    int caixa = getCaixaAtual(datah);
    if (caixa > 0) {
        int bd = listar();
        int cod, i;
        int num, aux;
        Reserva *res;
        int opc2;
        res = listarReservasPendentes(&num);
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
                    printf("Categoria:  %s \n", res[i].acomodacao.categoria.descricao);
                    printf("*******************************************************************\n");
                    aux = 1;
                }
            }
            if (aux == 1) {
                aux = 0;
                printf("Digite o (COD) da Reserva:");
                scanf("%d*c", &cod);
                Hora a = getHoraAtual();
                for (i = 0; i < num;) {
                    if (res[i].codigo == cod) {
                        aux = 1;
                        c.codigo = res[i].codigo;
                        c.hora = a;
                        c.reserva.codigo = res[i].codigo;
                        c.valor = valorCheckIN(res[i], bd);
                        break;
                    }
                    i++;
                }
                if (aux == 1) {
                    printf("Deseja acertar o valor das diarias agora?(S/N):");
                    char opc;
                    scanf("%s%*c", &opc);
                    if (opc == 'S' || opc == 's') {
                        printf("O valor é de %f \n", c.valor);
                        strcpy(c.status, "pago");
                        printf("O pagamento sera feito : 1-Dinheiro 2-Cartão :");
                        scanf("%d%*c", &opc2);
                        if (opc2 == 2) {
                            c.caixa = 0;
                            printf("O valor Total é de %f \n", c.valor);
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
                            cr.valor = c.valor;
                            aux = 1;
                            if (bd == 1)
                                cadastrarContaReceberTXT(cr);
                            else
                                cadastrarContaReceberBIN(&cr, 1);
                        } else {
                            c.caixa = caixa;
                        }
                    } else {
                        strcpy(c.status, "pendente");
                        c.caixa = 0; // trocar pela variavel caixa
                    }
                    if (aux = 1) {
                        if (bd == 1) {
                            cadastrarCheckInTXT(c);
                        } else {
                            cadastrarCheckInBIN(&c, 1);
                        }
                        printf("Cadastro realizado com sucesso!!\n");
                        editarReserva(bd, res[i]);
                        printf("Deseja Imprimir o comprovante (1-Sim/2-Não):");
                        scanf("%d%*c", &opc2);
                        if (opc2 == 1) {
                            //geraComprovante(c);
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

void printReserva(Reserva *res, int num) {
    int i;
    for (i = 0; i < num; i++) {
        printf("*************Reserva %d ****************\n", i + 1);
        printf("COD: %d \n", res[i].codigo);
        printf("DATA INI: %d /%d /%d\n", res[i].DataIn.dia, res[i].DataIn.mes, res[i].DataIn.ano);
        printf("DATA FIM: %d /%d /%d\n", res[i].DataFin.dia, res[i].DataFin.mes, res[i].DataFin.ano);
        printf("HOSPEDES: (%d) - %s - %s\n", res[i].hospede.codigo, res[i].hospede.nome, res[i].hospede.telefone);
        printf("Acomodação: %s \n", res[i].acomodacao.descricao);
        printf("Categoria:  %d \n", res[i].acomodacao.categoria.codigo);
        printf("\n");
    }
}

float valorCheckIN(Reserva res, int bd) {
    Categoria *cat;
    int num, i;
    float valor;
    if (bd == 1) {
        cat = listarCategoriaTXT();
        num = numCategoria();
    } else {
        cat = listarCheckInBIN(&num);
    }
    for (i = 0; i < num; i++) {
        if (res.acomodacao.categoria.codigo == cat[i].codigo) {
            valor = cat[i].valorDiario;
        }
    }
    int dias = diasEntreDatas(res.DataIn, res.DataFin);
    valor = valor * dias;
    return valor;
}

void editarReserva(int bd, Reserva r) {
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
            res[i].status = 1;
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

void pintCheckIN() {
    int bd = listar();
    CheckIn *c;
    int num;
    if (bd == 1) {
        c = listarCheckInTXT();
        num = numCheckIn();
    } else {
        c = listarCheckInBIN(&num);
    }
    int i;
    for (i = 0; i < num; i++) {
        printf("COD : %d \n", c[i].codigo);
        printf("TIME : %d:%d:%d \n", c[i].hora.hh, c[i].hora.mm, c[i].hora.ss);
        printf("STATUS : %s \n", c[i].status);
        printf("Valor : %f \n", c[i].valor);
        printf("********************************\n");

    }

}
