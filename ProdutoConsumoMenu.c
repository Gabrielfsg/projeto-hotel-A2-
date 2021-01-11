/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "ProdutoConsumoControl.h"
#include "Principal.h"

void menuCRUDProdConsumo() {
    int sair = 0;
    int opc;
    while (sair == 0) {
        printf("******* GESTÃO DE DADOS - PRODUTOS DOS HÓSPEDES **********\n");
        printf("Opções: \n");
        printf("1.Cadastrar Produto. \n");
        printf("2.Alterar Dados do Produto. \n");
        printf("3.Visualizar Produtos. \n");
        printf("4.Excluir Produto. \n");
        printf("5.Voltar. \n");
        printf("Digite a opção desejada: \n");
        scanf("%d%*c", &opc);
        switch (opc) {
            case 1:
                cadastrarProdutosConsumo();
                break;
            case 2:
                atualizarProdutosConsumo();
                break;
            case 3:
                listarProdutosConsumo();
                break;
            case 4:
                deletarProdutosConsumo();
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