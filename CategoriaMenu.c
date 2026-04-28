/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "CategoriaSUB.h"
#include "Principal.h"

void menuCRUDCategoria() {
    int sair = 0;
    int opc;
    while (sair == 0) {
        printf("******* GESTÃO DE DADOS - CATEGORIA ACOMODAÇÃO **********\n");
        printf("Opções: \n");
        printf("1.Cadastrar Categoria de Acomodação. \n");
        printf("2.Alterar Dados da Categoria de Acomodação. \n");
        printf("3.Visualizar Categoria de Acomodação. \n");
        printf("4.Excluir Categoria de Acomodação. \n");
        printf("5.Voltar. \n");
        printf("Digite a opção desejada: \n");
        scanf("%d%*c", &opc);
        switch (opc) {
            case 1:
                cadastrarCategoriaSUB();
                break;
            case 2:
                atualizarCategoria();
                break;
            case 3:
                listarCategoria();
                break;
            case 4:
                deletarCategoria();
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