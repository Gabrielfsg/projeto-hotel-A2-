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

void subRelatorios() {
    int opc = 0;
    int aux = 0;
    while (opc >= 0) {
        printf("*******Relatorios********\n");
        printf("1.Listagem de Hospedes.\n");
        printf("2.Listagem de Acomodaçoes.\n");
        printf("3.Listagens de Reservas.\n");
        printf("4.Listagem de Movimentacao de Acomodacao.\n");
        printf("5.Listagem de produtos de consumo.\n");
        printf("6.Produto em Estoque Minimo.\n");
        printf("8.Vendas.\n");
        printf("9.Contas a Receber.\n");
        printf("10.Contas a Pagar.\n");
        printf("11.Movimentação de Caixa.\n");
        printf("12.Voltar.\n");
        scanf("%d%*c", &opc);
        
        switch (opc) {
            case 1:
                relatorioHospedes();
                break;
            case 2:
                relatorioAcomodacao();
                break;
            case 3:

                break;
            case 4:

                break;
            case 5:
                relatorioProdCon();
                break;
            case 6:
                relatorioProdRes();
                break;
            case 7:

                break;
            case 8:

                break;
            case 9:
                relatorioContasRec();
                break;
            case 10:
                mostrarContasPagar();
                break;
            case 11:
                relatorioCaixa();
                break;
            case 12:
                menuPrincipal();
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
                        filtrarContasRecFaixaCodControl(cod1,cod2);
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

        }
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




    }
}

void relatorioAcomodacao() {
    int opc = 0;
    int bd = listar();
    int cod1, cod2;
    int cod;
    int r;
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
