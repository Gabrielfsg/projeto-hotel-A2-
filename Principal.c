/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include "Login.h"
#include "Principal.h"
#include "Menus.h"
#include "SalvametoBD.h"

void subArquivo();
void subCadastros();
void subListagem();
void subCaixa();
void subReservas();
void subVisualizarReservas();
void subRelatorios();
void subConfiguracoes();

void menuPrincipal() {
    int opc = 0;
    while (opc >= 0) {
        printf("******* MENU PRINCIPAL **********\n");
        //printf("*******    HOTEL    **********\n");
        printf("\n");
        printf("1.Cadastros e Gestão de dados.\n");
        printf("2.Cadastros Hotel (ADM).\n");
        printf("3.Caixa.\n");
        printf("4.Reservas.\n");
        printf("5.Relatórios.\n");
        printf("6.Check In.\n");
        printf("7.Check Out.\n");
        printf("8.Entrada de Produtos Industrializados.\n");
        printf("9.Configurações.\n");
        printf("10.Sair.\n");
        printf("Opção: ");
        scanf("%d%*c", &opc);
        printf("\n");
        switch (opc) {
            case 1:
                subCadastros();
                break;
            case 2:
                subArquivo();
                break;
            case 3:
                subCaixa();
                break;
            case 4:
                subReservas();
                break;
            case 5:
                subReservas();
                break;
            case 6:
                subRelatorios();
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                subConfiguracoes();
                break;
            case 10:
                exit(0);
                break;
            default:
                printf("Valor Invalido!\n");
                break;
        }
    }
}

void subCadastros() {
    int opc = 0;
    while (opc >= 0) {
        printf("*******Cadastros e Gestão de dados********\n");
        printf("1.Hospedes.\n");
        printf("2.Acomodações .\n");
        printf("3.Categoria de Acomodações .\n");
        printf("4.Produtos disponíveis para consumo dos hóspedes.\n");
        printf("5.Fornecedores .\n");
        printf("6.Operadores de Sistema .\n");
        printf("7.Voltar.\n");
        scanf("%d%*c", &opc);
        switch (opc) {
            case 1:
                menuCRUDHospedes();
                break;
            case 2:
                menuCRUDAcomodacao();
                break;
            case 3:
                menuCRUDCategoria();
                break;
            case 4:
                menuCRUDProdConsumo();
                break;
            case 5:
                menuCRUDFornecedor();
                break;
            case 6:
                menuCRUDOperador();
                break;
            case 7:
                menuPrincipal();
                //exit(0);
                break;
            default:
                printf("Valor Invalido!\n");
                //menuPrincipal();
                break;
        }
    }

}

void subListagem() {
    int opc = 0;
    while (opc >= 0) {
        printf("******* LISTAGEM ********\n");
        //printf("******* LER DADOS ********\n");
        printf("1.Hospedes.\n");
        printf("2.Acomodações .\n");
        printf("3.Categoria de Acomodações .\n");
        printf("4.Produtos disponíveis para consumo dos hóspedes.\n");
        printf("5.Fornecedores .\n");
        printf("6.Operadores de Sistema .\n");
        printf("7.Voltar.\n");
        scanf("%d%*c", &opc);
        switch (opc) {
            case 1:
                //lista os hóspedes
                //listarHospedes();
                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:

                break;
            case 7:
                //exit(0);
                menuPrincipal();
                break;
            default:
                printf("Valor Invalido!\n");

                break;
        }
    }
}

void subArquivo() {
    int opc = 0;
    while (opc >= 0) {
        printf("*******Cadastros Hotel (ADM)********\n");
        printf("1.Trocar de Usuario.\n");
        printf("2.Dados  Empresa.\n");
        printf("3.Voltar.\n");
        scanf("%d%*c", &opc);
        switch (opc) {
            case 1:
                menuLogin();
                break;
            case 2:
                menuCrudHotel();
                break;
            case 3:
                menuPrincipal();
                break;
            default:
                printf("Valor Invalido!\n");
                menuPrincipal();
                break;
        }
    }
}

void subCaixa() {
    int opc = 0;
    while (opc >= 0) {
        printf("*******  Caixa **********\n");
        printf("1.Vender Produto.\n");
        printf("2.Despesas.\n");
        printf("3.Contas a Pagar.\n");
        printf("4.Listar Valor Caixa .\n");
        printf("5.Fechar Caixa.\n");
        printf("6.Sair.\n");
        scanf("%d%*c", &opc);
        switch (opc) {
            case 1:
                // Vender Produto
                break;
            case 2:
                //função Despesas
                break;
            case 3:
                //função Contas a Pagar
                break;
            case 4:
                //função Listar Valor Caixa
                break;
            case 5:
                //função Fechar Caixa
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Valor Invalido!\n");
                break;
        }
    }


}

void subReservas() {
    int opc = 0;
    while (opc >= 0) {
        printf("******* Reservas **********\n");
        printf("1.Cadastrar Reserva.\n");
        printf("2.Alterar Reservas.\n");
        printf("3.Visualizar Reservas Disponiveis.\n");
        printf("4.Visualizar Reservas Não Disponiveis.\n");
        printf("5.Cancelar Reserva.\n");
        printf("6.Voltar.\n");
        scanf("%d%*c", &opc);
        switch (opc) {
            case 1:
                cadReserva();
                break;
            case 2:

                break;
            case 3:
                subVisualizarReservas();
                break;
            case 4:
                
                break;
            case 5:
                CancelarReserva();
                break;
            case 6:
                menuPrincipal();
                break;
            default:
                printf("Valor Invalido!\n");
                menuPrincipal();
                break;
        }
    }


}

void subVisualizarReservas() {
    int opc = 0;
    while (opc >= 0) {
        printf("******* Visualizar Reservas **********\n");
        printf("1.Visualizar Reserva por data.\n");
        printf("2.Visualizar Reservas categoria de acomodação.\n");
        printf("3.Visualizar Reserva quantidade de pessoas,.\n");
        printf("4.Visualizar Reserva tipo de facilidade.\n");
        printf("5.Visualizar Reserva tipo de facilidade.\n");
        printf("6.Sair.\n");
        scanf("%d%*c", &opc);
        switch (opc) {
            case 1:
                break;
            case 2:
                //Visualizar Reservas Disponiveis
                break;
            case 3:

                break;
            case 4:
                //Cancelar Reserva
                break;
            case 5:
                //Cancelar Reserva
                break;
            case 6:
                menuPrincipal();
                break;
            default:
                printf("Valor Invalido!\n");
                break;
        }
    }


}

void subRelatorios() {
    int opc = 0;
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
        printf("12.Sair.\n");
        scanf("%d%*c", &opc);
        switch (opc) {
            case 1:

                break;
            case 2:
                //metodo editar empresa
                break;
            case 3:
                //metodo mostrar dados empresa
                break;
            case 4:

                break;
            case 5:

                break;
            case 6:

                break;
            case 7:

                break;
            case 8:

                break;
            case 9:

                break;
            case 10:

                break;
            case 11:

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

void subConfiguracoes() {
    int opc = 0, r;
    while (opc >= 0) {
        printf("*******Configurações********\n");
        printf("1.Op de BD.\n");
        printf("2.Operador Sistema.\n");
        printf("3.Importar Dados.\n");
        printf("4.Exportar Dados.\n");
        printf("5.Voltar.\n");
        scanf("%d%*c", &opc);
        switch (opc) {
            case 1:
                printf("1.Salvar em Arquivos TXT (1).\n");
                printf("2.Salvar em Arquivos BIN (2).\n");
                printf("\nDigite a opção!:");
                scanf("%d%*c", &opc);
                switch (opc) {
                    case 1:
                        r = alterar(1);
                        if (r = 0) {
                            printf("\nErro :\n");
                        } else {
                            printf("\nBD alterado com SUCESSO!!\n");
                        }
                        break;
                    case 2:
                        r = alterar(2);
                        if (r = 0) {
                            printf("\nErro :\n");
                        } else {
                            printf("\nBD alterado com SUCESSO!!\n");
                        }
                        break;
                    default:
                        printf("\nOPÇÃO INVÁLIDA!!\n");
                        break;
                }
                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:
                menuPrincipal();
                break;
            default:
                printf("Valor Invalido!\n");
                break;
        }
    }

}