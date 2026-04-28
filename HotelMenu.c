#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include "Login.h"
#include "Principal.h"

void menuCrudHotel() {
    int opc = 0;
    while (opc >= 0) {
        printf("*******  HOTEL  ********\n");
        printf("1.Cadastrar Dados Hotel.\n");
        printf("2.Alterar Dados Hotel.\n");
        printf("3.Visualizar Dados Hotel.\n");
        printf("4.Excluir Dados Hotel.\n");
        printf("5.Voltar.\n");
        scanf("%d%*c", &opc);
        switch (opc) {
            case 1:
                cadastrarHotel();
                break;
            case 2:
                alterarHotel();
                break;
            case 3:
                verHotel();
                break;
            case 4:
                deletarHotel();
                break;
            case 5:
                menuPrincipal();
                break;
            default:
                printf("Valor Invalido!\n");
                menuPrincipal();
                break;
        }
    }
}

