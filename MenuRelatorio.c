/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Acomodacao.h"
#include "Categoria.h"
#include "AcomodacaoSUB.h"
#include "SalvametoBD.h"
#include "Hospede.h"
#include "HospedeMenu.h"
#include "MenuCaixa.h"
#include "csvHospede.h"
#include "Data.h"

void subRelatorios() {
    int opc = 0;
    int aux = 0;
    while (opc >= 0) {
        printf("*******Relatorios********\n");
        printf("1.Listagem de Hospedes.\n");
        printf("2.Listagem de Acomodaçoes.\n");
        printf("3.Listagens de Reservas.\n");
        printf("4.Listagem de produtos de consumo.\n");
        printf("5.Produto em Estoque Minimo.\n");
        printf("6.Vendas.\n");
        printf("7.Contas a Receber.\n");
        printf("8.Contas a Pagar.\n");
        printf("9.Movimentação de Caixa.\n");
        printf("10.Voltar.\n");
        scanf("%d%*c", &opc);

        switch (opc) {
            case 1:
                relatorioHospedes();
                break;
            case 2:
                relatorioAcomodacao();
                break;
            case 3:
                relatorioReservas();
                break;
            case 4:
                relatorioProdCon();
                break;
            case 5:
                relatorioProdRes();
                break;
            case 6:
                relatorioVenda();
                break;
            case 7:
                relatorioContasRec();
                break;
            case 8:
                relatorioContasPag();
                break;
            case 9:
                relatorioCaixa();
                break;
            case 10:
                menuPrincipal();
                break;
            default:
                printf("Valor Invalido!\n");
                break;
        }
    }
}

void relatorioReservas() {
    int opc = 0;
    int bd = listar();
    int cod1, cod2;
    Hospede *arrayHospedes;
    int r;
    int dia1, dia2, mes1, mes2, ano;
    int opc1 = 0, opc2 = 0, opcV = 0, opcV2 = 0;
    while (opc == 0) {
        printf("*******Relatorios********\n");
        printf("1.Dado do hospede (Código).\n");
        printf("2.Dado da acomodação(Código).\n");
        printf("3.Periodo Reservado.\n");
        printf("4.Voltar.\n");
        scanf("%d%*c", &opc);
        switch (opc) {
            case 1:
                printf("Digite o código do hospede: ");
                scanf("%d", &cod1);
                opc1 = 0;
                while (opc1 == 0) {
                    printf("Deseja: \n"
                            "1. Listar na Tela. \n"
                            "2. Gravar Arquivo CSV. \n");
                    scanf("%d", &opcV);
                    if (opcV == 1) {
                        relaRescodH(cod1);
                        opc1 = 2;
                    } else if (opcV == 2) {
                        filtrarReservaCodHosp(cod1);
                        opc1 = 2;
                    } else {
                        printf("Digite uma opção válida. \n");
                    }
                }
                break;

            case 2:
                printf("Digite o código da acomodação: ");
                scanf("%d", &cod2);
                opc2 = 0;
                while (opc2 == 0) {
                    printf("Deseja: \n"
                            "1. Listar na Tela. \n"
                            "2. Gravar Arquivo CSV. \n");
                    scanf("%d", &opcV);
                    if (opcV == 1) {
                        relaRescodA(cod2);
                        opc2 = 2;
                    } else if (opcV == 2) {
                        filtrarReservaCodAco(cod2);
                        opc2 = 2;
                    } else {
                        printf("Digite uma opção válida. \n");
                    }
                }
                break;

            case 3:
                printf("Digite o dia inicial: ");
                scanf("%d", &dia1);
                printf("Digite o dia final: ");
                scanf("%d", &dia2);
                printf("Digite o mes inicial: ");
                scanf("%d", &mes1);
                printf("Digite o mes final: ");
                scanf("%d", &mes2);
                printf("Digite o ano: ");
                scanf("%d", &ano);
                opc2 = 0;
                while (opc2 == 0) {
                    printf("Deseja: \n"
                            "1. Listar na Tela. \n"
                            "2. Gravar Arquivo CSV. \n");
                    scanf("%d", &opcV);
                    if (opcV == 1) {
                        relaResData(dia1, dia2, mes1, mes2, ano);
                        opc2 = 2;
                    } else if (opcV == 2) {
                        FiltrarResData(dia1, dia2, mes1, mes2, ano);
                        opc2 = 2;
                    } else {
                        printf("Digite uma opção válida. \n");
                    }
                }

                break;

            case 4:
                subRelatorios();
                break;

            default:
                printf("Valor Invalido!\n");
                break;
        }
    }
}

void relatorioHospedes() {
    int opc = 0;
    int bd = listar();
    int cod1, cod2;
    int sex;
    char sexxo;
    Hospede* arrayHospedesFiltrado;
    int r;
    int opc1 = 0, opc2 = 0, opcV = 0, opcV2 = 0;
    while (opc == 0) {
        printf("*******Relatorios********\n");
        printf("1.Faixa de Código.\n");
        printf("2.Sexo.\n");
        printf("3.Voltar.\n");
        scanf("%d%*c", &opc);

        switch (opc) {
            case 1:
                printf("Digite o número de início da faixa de código: ");
                scanf("%d", &cod1);

                while (opc1 == 0) {
                    printf("Digite o número final da faixa de código: ");
                    scanf("%d", &cod2);

                    if (cod2 < cod1) {
                        printf("Entre com um valor maior que o valor do código de início. \n");
                    } else {
                        opc1 = 2;
                    }
                }
                opc1 = 0;
                while (opc1 == 0) {
                    printf("Deseja: \n"
                            "1. Listar na Tela. \n"
                            "2. Gravar Arquivo CSV. \n");
                    scanf("%d", &opcV);

                    if (opcV == 1) {
                        listarHospedesFaixaCodControl(cod1, cod2);
                        opc1 = 2;
                    } else if (opcV == 2) {

                        int qteHospedesFiltrados = 0;
                        arrayHospedesFiltrado = filtrarHospedesFaixaCodControl(cod1, cod2, &qteHospedesFiltrados);
                        printf("TESTE MENU\n");
                        printf("QTE MENU = %d\n", qteHospedesFiltrados);
                        for (int i = 0; i < qteHospedesFiltrados; i++) {
                            printf("i = %d | qte = %d\n", i, qteHospedesFiltrados);
                            printf("COD = %d\n", arrayHospedesFiltrado[i].codigo);
                        }


                        gerarCSVHospede(arrayHospedesFiltrado, &qteHospedesFiltrados, 1);
                        opc1 = 2;


                    } else {
                        printf("Digite uma opção válida. \n");
                    }
                }
                break;

            case 2:
                while (opc2 == 0) {
                    printf("Entre com o sexo: \n"
                            "1.Masculino. \n"
                            "2.Feminino. \n"
                            "Opção: ");
                    scanf("%d", &sex);

                    if (sex == 1) {
                        sexxo = 'M';
                        opc2 = 1;
                    } else if (sex == 2) {
                        sexxo = 'F';
                        opc2 = 1;
                    } else {
                        printf("Opção Incorreta. \n");
                    }
                }
                //printf("%c", sexxo);
                opc2 = 0;
                while (opc2 == 0) {
                    printf("Deseja: \n"
                            "1. Listar na Tela. \n"
                            "2. Gravar Arquivo CSV. \n");
                    scanf("%d", &opcV);
                    if (opcV == 1) {
                        listarHospedesSexoControl(sexxo);
                        opc2 = 2;
                    } else if (opcV == 2) {
                        printf("DEBUG 1\n");
                        int qteHospedesFiltrados = 0;
                        printf("DEBUG 2\n");
                        //arrayHospedesFiltrado = filtrarHospedesSexoControl(sexxo, &qteHospedesFiltrados);
                        filtrarHospedesSexoControl(sexxo, &qteHospedesFiltrados);
                        //printf("COD = %d\n", arrayHospedesFiltrado[0].codigo);
                        printf("DEBUG 3\n");
                        printf("TESTE MENU\n");
                        //printf("QTE MENU = %d\n", qteHospedesFiltrados);
                        //for (int i = 0; i < qteHospedesFiltrados; i++) {
                        //   printf("i = %d | qte = %d\n", i, qteHospedesFiltrados);
                        //   printf("COD = %d\n", arrayHospedesFiltrado[i].codigo);
                        // }
                        //gerarCSVHospede(arrayHospedesFiltrado, &qteHospedesFiltrados, 2);

                        opc2 = 2;
                    } else {
                        printf("Digite uma opção válida. \n");
                    }
                }



                break;

            case 3:
                subCadastros();
                break;

            default:
                printf("Valor Invalido!\n");
                break;
        }
    }
}

void relatorioContasRec() {
    int opc = 0;
    int bd = listar();
    int cod1, cod2;
    int dia, mes, ano;
    int r;
    int opc1 = 0, opc2 = 0, opcV = 0, opcV2 = 0;
    while (opc == 0) {
        printf("*******Relatorios********\n");
        printf("1.Faixa de Código.\n");
        printf("2.Data de recebimento.\n");
        printf("3.Voltar.\n");
        scanf("%d%*c", &opc);
        switch (opc) {
            case 1:
                printf("Digite o número de início da faixa de código: ");
                scanf("%d", &cod1);
                while (opc1 == 0) {
                    printf("Digite o número final da faixa de código: ");
                    scanf("%d", &cod2);
                    if (cod2 < cod1) {
                        printf("Entre com um valor maior que o valor do código de início. \n");
                    } else {
                        opc1 = 2;
                    }
                }
                opc1 = 0;
                while (opc1 == 0) {
                    printf("Deseja: \n"
                            "1. Listar na Tela. \n"
                            "2. Gravar Arquivo CSV. \n");
                    scanf("%d", &opcV);
                    if (opcV == 1) {
                        listarContasR(cod1, cod2);
                        opc1 = 2;
                    } else if (opcV == 2) {
                        filtrarContasRecFaixaCodControl(cod1, cod2);
                        opc1 = 2;
                    } else {
                        printf("Digite uma opção válida. \n");
                    }
                }
                break;

            case 2:
                printf("Entre com o dia: ");
                scanf("%d", &dia);
                printf("Entre com o mes: ");
                scanf("%d", &mes);
                printf("Entre com o ano: ");
                scanf("%d", &ano);

                break;

            case 3:;
                subRelatorios();
                break;

            default:;
                printf("Valor Invalido!\n");
                break;


                //printf("%c", sexxo);
                opc2 = 0;
                while (opc2 == 0) {
                    printf("Deseja: \n"
                            "1. Listar na Tela. \n"
                            "2. Gravar Arquivo CSV. \n");
                    scanf("%d", &opcV);
                    if (opcV == 1) {
                        listarContasDia(dia, mes, ano);
                        opc2 = 2;
                    } else if (opcV == 2) {
                        if (bd == 1) {

                        } else if (bd == 2) {

                            if (r == 1) {

                            }
                        }
                        opc2 = 2;
                    } else {
                        printf("Digite uma opção válida. \n");
                    }
                }



                break;

        }
    }
}

void relatorioVenda() {
    int opc = 0;
    int bd = listar();
    int cod1, cod2;

    int r;
    int opc1 = 0, opc2 = 0, opcV = 0, opcV2 = 0;
    while (opc == 0) {
        printf("*******Relatorios********\n");
        printf("1.Cartão ou Dinheiro.\n");
        printf("2.Voltar.\n");
        scanf("%d%*c", &opc);
        switch (opc) {
            case 1:
                printf("Modo: \n"
                        "1.Cartão. \n"
                        "2.Dinheiro. \n"
                        "Opção: ");
                scanf("%d", &r);
                while (opc1 == 0) {
                    printf("Deseja: \n"
                            "1. Listar na Tela. \n"
                            "2. Gravar Arquivo CSV. \n");
                    scanf("%d", &opcV);
                    if (opcV == 1) {
                        listarContasTipo(r);
                        opc1 = 2;
                    } else if (opcV == 2) {

                        opc1 = 2;
                    } else {
                        printf("Digite uma opção válida. \n");
                    }
                }
                break;


            case 2:
                subRelatorios();
                break;

            default:
                printf("Valor Invalido!\n");
                break;
        }
    }
}

void relatorioContasPag() {
    int opc = 0;
    int bd = listar();
    int cod1, cod2;
    int dia, mes, ano, dia2, mes2;
    int r;
    int opc1 = 0, opc2 = 0, opcV = 0, opcV2 = 0;
    while (opc == 0) {
        printf("*******Relatorios********\n");
        printf("1.Faixa de Código.\n");
        printf("2.Data que vence.\n");
        printf("3.Voltar.\n");
        scanf("%d%*c", &opc);
        switch (opc) {
            case 1:
                printf("Digite o número de início da faixa de código: ");
                scanf("%d", &cod1);
                while (opc1 == 0) {
                    printf("Digite o número final da faixa de código: ");
                    scanf("%d", &cod2);
                    if (cod2 < cod1) {
                        printf("Entre com um valor maior que o valor do código de início. \n");
                    } else {
                        opc1 = 2;
                    }
                }
                opc1 = 0;
                while (opc1 == 0) {
                    printf("Deseja: \n"
                            "1. Listar na Tela. \n"
                            "2. Gravar Arquivo CSV. \n");
                    scanf("%d", &opcV);
                    if (opcV == 1) {
                        mostrarContasPagarCod(cod1, cod2);
                        opc1 = 2;
                    } else if (opcV == 2) {

                        opc1 = 2;
                    } else {
                        printf("Digite uma opção válida. \n");
                    }
                }
                break;

            case 2:
                printf("Entre com o dia 1: ");
                scanf("%d", &dia);
                printf("Entre com o mes 1: ");
                scanf("%d", &mes);
                printf("Entre com o dia 2: ");
                scanf("%d", &dia2);
                printf("Entre com o mes 2: ");
                scanf("%d", &mes2);
                printf("Entre com o ano: ");
                scanf("%d", &ano);


                //printf("%c", sexxo);
                opc2 = 0;
                while (opc2 == 0) {
                    printf("Deseja: \n"
                            "1. Listar na Tela. \n"
                            "2. Gravar Arquivo CSV. \n");
                    scanf("%d", &opcV);
                    if (opcV == 1) {
                        mostrarContasPagarData(dia, dia2, mes, mes2, ano);
                        opc2 = 2;
                    } else if (opcV == 2) {
                        if (bd == 1) {

                        } else if (bd == 2) {

                            if (r == 1) {

                            }
                        }
                        opc2 = 2;
                    } else {
                        printf("Digite uma opção válida. \n");
                    }
                }



                break;

            case 3:
                subRelatorios();
                break;

            default:
                printf("Valor Invalido!\n");
                break;
        }
    }
}

void relatorioAcomodacao() {
    int opc = 0;
    int bd = listar();
    Data *dataIn, *dataFim;
    Acomodacao *aco;
    int cod1, cod2;
    int cod;
    int r;
    int num = 0;
    int dia, mes, ano, dia2, mes2, ano2;
    int opc1 = 0, opc2 = 0, opcV = 0, opcV2 = 0;
    while (opc == 0) {
        printf("*******Relatorios********\n");
        printf("1.Faixa de Código.\n");
        printf("2.Categoria.\n");
        printf("3.Data Disponível.\n");
        printf("4.Voltar.\n");
        scanf("%d%*c", &opc);
        switch (opc) {
            case 1:
                printf("Digite o número de início da faixa de código: ");
                scanf("%d", &cod1);
                while (opc1 == 0) {
                    printf("Digite o número final da faixa de código: ");
                    scanf("%d", &cod2);
                    if (cod2 < cod1) {
                        printf("Entre com um valor maior que o valor do código de início. \n");
                    } else {
                        opc1 = 2;
                    }
                }
                opc1 = 0;
                while (opc1 == 0) {
                    printf("Deseja: \n"
                            "1. Listar na Tela. \n"
                            "2. Gravar Arquivo CSV. \n");
                    scanf("%d", &opcV);
                    if (opcV == 1) {
                        listarAcoFaixaCodControl(cod1, cod2);
                        opc1 = 2;
                    } else if (opcV == 2) {


                        filtrarAcoFaixaCodControl(cod1, cod2);

                        opc1 = 2;
                    } else {
                        printf("Digite uma opção válida. \n");
                    }
                }
                break;

            case 2:
                printf("Entre com o código da categoria: ");
                scanf("%d", &cod);
                opc2 = 0;
                while (opc2 == 0) {
                    printf("Deseja: \n"
                            "1. Listar na Tela. \n"
                            "2. Gravar Arquivo CSV. \n");
                    scanf("%d", &opcV);
                    if (opcV == 1) {
                        listaAcoCat(cod);
                        opc2 = 2;
                    } else if (opcV == 2) {

                        filtrarAcoCat(cod);

                        opc2 = 2;
                    } else {
                        printf("Digite uma opção válida. \n");
                    }
                }



                break;

            case 3:
                printf("Entre com o dia inicial: ");
                scanf("%d", &dia);
                printf("Entre com o mes inicial: ");
                scanf("%d", &mes);
                printf("Entre com o ano inicial: ");
                scanf("%d", &ano);
                dataIn = newData(dia, mes, ano);
                printf("Entre com o dia final: ");
                scanf("%d", &dia2);
                printf("Entre com o ano inicial: ");
                scanf("%d", &mes2);
                printf("Entre com o ano inicial: ");
                scanf("%d", &ano2);
                dataFim = newData(dia, mes, ano);


                opc2 = 0;
                while (opc2 == 0) {
                    printf("Deseja: \n"
                            "1. Listar na Tela. \n"
                            "2. Gravar Arquivo CSV. \n");
                    scanf("%d", &opcV);
                    if (opcV == 1) {
                        aco = listarAcomodacoesDisponiveis(*dataIn, *dataFim, &num);
                        opc2 = 2;
                    } else if (opcV == 2) {

                        filtrarAcomodacoesDisponiveis(*dataIn, *dataFim, &num);

                        opc2 = 2;
                    } else {
                        printf("Digite uma opção válida. \n");
                    }
                }

                break;

            case 4:
                subRelatorios();
                break;
            default:
                printf("Valor Invalido!\n");
                break;
        }
    }
}

void relatorioProdCon() {
    int opc = 0;
    int bd = listar();
    int cod1, cod2;
    int cod;
    int r;
    int opc1 = 0, opc2 = 0, opcV = 0, opcV2 = 0;
    while (opc == 0) {
        printf("*******Relatorios********\n");
        printf("1.Faixa de Código.\n");
        printf("2.Voltar.\n");
        scanf("%d%*c", &opc);
        switch (opc) {
            case 1:
                printf("Digite o número de início da faixa de código: ");
                scanf("%d", &cod1);
                while (opc1 == 0) {
                    printf("Digite o número final da faixa de código: ");
                    scanf("%d", &cod2);
                    if (cod2 < cod1) {
                        printf("Entre com um valor maior que o valor do código de início. \n");
                    } else {
                        opc1 = 2;
                    }
                }
                opc1 = 0;
                while (opc1 == 0) {
                    printf("Deseja: \n"
                            "1. Listar na Tela. \n"
                            "2. Gravar Arquivo CSV. \n");
                    scanf("%d", &opcV);
                    if (opcV == 1) {
                        listarProdFaixa(cod1, cod2);
                        opc1 = 2;
                    } else if (opcV == 2) {
                        filtrarProdFaixa(cod1,cod2);
                        opc1 = 2;
                    } else {
                        printf("Digite uma opção válida. \n");
                    }
                }
                break;

            case 2:
                subRelatorios();
                break;

            default:
                printf("Valor Invalido!\n");
                break;
        }
    }
}

void relatorioProdRes() {
    int opc = 0;
    int bd = listar();
    int cod1, cod2;
    int cod;
    int r;
    int opc1 = 0, opc2 = 0, opcV = 0, opcV2 = 0;
    while (opc == 0) {
        printf("*******Relatorios********\n");
        printf("1.Faixa de Código.\n");
        printf("2.Voltar.\n");
        scanf("%d%*c", &opc);
        switch (opc) {
            case 1:
                printf("Digite o número de início da faixa de código: ");
                scanf("%d", &cod1);
                while (opc1 == 0) {
                    printf("Digite o número final da faixa de código: ");
                    scanf("%d", &cod2);
                    if (cod2 < cod1) {
                        printf("Entre com um valor maior que o valor do código de início. \n");
                    } else {
                        opc1 = 2;
                    }
                }
                opc1 = 0;
                while (opc1 == 0) {
                    printf("Deseja: \n"
                            "1. Listar na Tela. \n"
                            "2. Gravar Arquivo CSV. \n");
                    scanf("%d", &opcV);
                    if (opcV == 1) {
                        listarProdResFaixa(cod1, cod2);
                        opc1 = 2;
                    } else if (opcV == 2) {

                        opc1 = 2;
                    } else {
                        printf("Digite uma opção válida. \n");
                    }
                }
                break;

            case 2:
                subRelatorios();
                break;

            default:
                printf("Valor Invalido!\n");
                break;
        }
    }
}

void relatorioCaixa() {
    int opc = 0;
    int bd = listar();
    int d1, d2, m;
    int cod;
    int r;
    int opc1 = 0, opc2 = 0, opcV = 0, opcV2 = 0;
    while (opc == 0) {
        printf("*******Relatorios********\n");
        printf("1.Data.\n");
        printf("2.Voltar.\n");
        scanf("%d%*c", &opc);
        switch (opc) {
            case 1:
                printf("Digite o dia inicial: ");
                scanf("%d", &d1);
                printf("Digite o dia final: ");
                scanf("%d", &d2);
                printf("Digite o mês: ");
                scanf("%d", &m);
                opc1 = 0;
                while (opc1 == 0) {
                    printf("Deseja: \n"
                            "1. Listar na Tela. \n"
                            "2. Gravar Arquivo CSV. \n");
                    scanf("%d", &opcV);
                    if (opcV == 1) {
                        listarCaixaData(d1, d2, m);
                        opc1 = 2;
                    } else if (opcV == 2) {

                        opc1 = 2;
                    } else {
                        printf("Digite uma opção válida. \n");
                    }
                }
                break;

            case 2:
                subRelatorios();
                break;

            default:
                printf("Valor Invalido!\n");
                break;
        }
    }
}
