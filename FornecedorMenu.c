/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "FornecedorSUB.h"
#include "Principal.h"

void menuCRUDFornecedor() {
    int sair = 0;
    int opc;
    while (sair == 0) {
        printf("******* GESTÃO DE DADOS - HÓSPEDES **********\n");
        printf("Opções: \n");
        printf("1.Cadastrar Fornecedor. \n");
        printf("2.Alterar Dados do Fornecedor. \n");
        printf("3.Visualizar Fornecedor. \n");
        printf("4.Excluir Fornecedor. \n");
        printf("5.Voltar. \n");
        printf("Digite a opção desejada: \n");
        scanf("%d%*c", &opc);
        switch (opc) {
            case 1:
                cadastrarFornecedor();
                break;
            case 2:
                atualizarFornecedor();
                break;
            case 3:
                listarFornecedor();
                break;
            case 4:
                deletarFornecedor();
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

