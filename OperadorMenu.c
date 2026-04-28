/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
//#include "OperadorSistemaControl.h"
#include "Principal.h"

void menuCRUDOperador() {
    int sair = 0;
    int opc;
    while (sair == 0) {
        printf("******* GESTÃO DE DADOS - OPERADOR **********\n");
        printf("Opções: \n");
        printf("1.Cadastrar Operador. \n");
        printf("2.Alterar Dados do Operador. \n");
        printf("3.Visualizar Operador. \n");
        printf("4.Excluir Operador. \n");
        printf("5.Voltar. \n");
        printf("Digite a opção desejada: \n");
        scanf("%d%*c", &opc);
        switch (opc) {
            case 1:
               cadastrarOperador();
                break;
            case 2:
                atualizarOperador();
                break;
            case 3:
                listarOperador();
                break;
            case 4:
                deletarOperador();
                break;
            case 5:
                sair = 1;
                subCadastros();
                break;
            default:
                printf("OPÇÃO INVÁLIDA!\n");

                break;
        }

    }
}
