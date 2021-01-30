/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include "Categoria.h"
#include "Acomodacao.h"
#include "Categoria.h"

void reservaPQuantidade() {
    int quant, num, cod, num2;
    int r;
    Acomodacao *aco;
    Categoria *cat;
    int achou = 0;
    int achouD = 0;
    printf("Entre com a quantidade de pessoas desejada: ");
    scanf("%d*c", &quant);
    aco = listarAcomodacaoBIN(&num);
    cat = listarCategoriaBIN(&num2);
    int i, j;
    for (i = 0; i < num; i++) {
        if (cat[i].quantidadePessoas == quant) {
            printf("\n**************** %d *****************\n", i);
            printf("COD: %d\n", aco[i].codigo);
            printf("DESCRIÇÃO: %s\n", aco[i].descricao);
            printf("STATUS: %s\n", aco[i].status);
            achou++;
            //LISTAR FACILIDADES PRECISARÁ DE UM TRATAMENTO ESPECIAL
            for (j = 0; j < num2; j++) {
                if (aco[i].categoria.codigo == cat[j].codigo) {
                    printf("CATEGORIAS: %s\n", cat[j].descricao);
                    printf("FACILIDADES: %s\n", cat[j].facilidade);
                    printf("VALOR DIARIA: %f\n", cat[j].valorDiario);
                    printf("N° PESSOAS: %d\n", cat[j].quantidadePessoas);
                }

            }
        }
    }
    if (achou > 0) {
        printf("Quartos encontrados !!! \n");
        printf("Digite o código da acomodação que deseja: ");
        scanf("%d*c", &cod);
        for (i = 0; i < num; i++) {
            if (aco[i].codigo == cod) {
                r = cadastrarReservaBIN(&aco, 1);
                break;
            }
        }
    } else {
        printf("Nenhum quarto encontrado !!! \n");
    }
    if (r == 1) {
        printf("Reserva Feita com sucesso \n");
    } else {
        printf("Acomodação inexistente. \n");
    }



    free(aco);


}




void verReservasOcupadas() {
    int num;
    Acomodacao *aco;
    aco = listarResBIN(&num);
    int i, j;
    for (i = 0; i < num; i++) {
        printf("\n**************** %d *****************\n", i);
        printf("COD: %d\n", aco[i].codigo);
        printf("DESCRIÇÃO: %s\n", aco[i].descricao);
        printf("STATUS: %s\n", aco[i].status);
    }

    
}



