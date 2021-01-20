/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "AcomodacaoSUB.h"
#include "Principal.h"

void menuCRUDAcomodacao() {
    int sair = 0;
    int opc;
    while (sair == 0) {
        printf("******* GESTÃO DE DADOS - ACOMODAÇÃO **********\n");
        printf("Opções: \n");
        printf("1.Cadastrar Acomodação. \n");
        printf("2.Alterar Dados da Acomodação. \n");
        printf("3.Visualizar Acomodação. \n");
        printf("4.Excluir Acomodação. \n");
        printf("5.Voltar. \n");
        printf("Digite a opção desejada: \n");
        scanf("%d%*c", &opc);
        switch (opc) {
            case 1:
                cadastrarAcomodacao();
                break;
            case 2:
                atualizarAcomodacao();
                break;
            case 3:
                listarAcomodacao();
                break;
            case 4:
                deletarAcomodacao();
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
