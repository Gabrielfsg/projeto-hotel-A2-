/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "HospedeControl.h"
#include "Principal.h"
//#include "Hospede.h"

void menuCRUDHospedes() {
    int sair = 0;
    int opc;
    while (sair == 0) {
        printf("******* GESTÃO DE DADOS - HÓSPEDES **********\n");
        printf("Opções: \n");
        printf("1.Cadastrar Hospede. \n");
        printf("2.Alterar Dados do Hospede. \n");
        printf("3.Visualizar Todos os Hospedes. \n");
        printf("4.Visualizar Hospede por código. \n");
        printf("5.Excluir Hospede. \n");
        printf("6.Voltar. \n");
        printf("Digite a opção desejada: \n");
        scanf("%d%*c", &opc);
        switch (opc) {
            case 1:
                cadastrarHospedes();
                break;
            case 2:
                atualizarHospedes();
                break;
            case 3:
                listarHospedes();
                break;
            case 4:;                
                setbuf(stdout, NULL);
                setbuf(stdin, NULL);
                Hospede hos = getHospedeByCodControl();
                setbuf(stdout, NULL);
                fflush(stdout);  
                break;
            case 5:
                setbuf(stdout, NULL);
                setbuf(stdin, NULL);
                deletarHospedesControl();
                
                break;
            case 6:
                sair = 1;
                subCadastros();
                break;
            default:
                printf("OPÇÃO INVÁLIDA!\n");

                break;
        }

    }
}