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
    int bd = listar();
    int quant, num, cod, num2;
    int r;
    Acomodacao *aco;
    Categoria *cat;
    int achou = 0;
    int achouD = 0;
    if (bd == 1) {
        num = numLinhasAcomodacao();
        aco = listarAcomodacaoTXT();
        cat = listarCategoriaTXT();
        num2 = numLinhasCategoria();
    } else if (bd == 2) {
        aco = listarAcomodacaoBIN(&num);
        cat = listarCategoriaBIN(&num2);
    } else {
        printf("\nAltere a opção de salvamento em (MENU Principal->9 . Configurações-> 1. Op de BD.)\n");
    }
    if (bd > 0) {
        printf("Entre com a quantidade de pessoas desejada: ");
        scanf("%d*c", &quant);

        int i, j;
        for (i = 0; i < num; i++) {
            if (cat[i].quantidadePessoas == quant) {
                printf("\n**************** %d *****************\n", i);
                printf("COD: %d\n", aco[i].codigo);
                printf("DESCRIÇÃO: %s\n", aco[i].descricao);
                printf("STATUS: %s\n", aco[i].status);
                achou++;
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
                    //onde tu vai pegar os dado
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
}

void reservaPCategoria() {
    int bd = listar();
    int num, cod, num2;
    char opc[20];
    int r;
    Acomodacao *aco;
    Categoria *cat;
    int achou = 0;
    int achouD = 0;
    aco = listarAcomodacaoBIN(&num);
    cat = listarCategoriaBIN(&num2);
    if (bd > 0) {
        printf("Entre com o estilo de categoria de pessoas desejada: \n"
                "1.standart. \n"
                "2.presidecial. \n"
                "3.luxo \n");
        scanf("%s*c", &opc);

        int i, j;
        for (i = 0; i < num; i++) {
            if (strcmp(aco[i].descricao, opc) == 0) {
                printf("\n**************** %d *****************\n", i);
                printf("COD: %d\n", aco[i].codigo);
                printf("DESCRIÇÃO: %s\n", aco[i].descricao);
                printf("STATUS: %s\n", aco[i].status);
                achou++;
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

    }
    free(aco);
}

void reservar() {
    int bd = listar();
    int quant, num, cod, num2;
    int r;
    Acomodacao *aco;
    Categoria *cat;
    int achou = 0;
    int achouD = 0;
    aco = listarAcomodacaoBIN(&num);
    cat = listarCategoriaBIN(&num2);
    int i, j;
        for (i = 0; i < num; i++) {            
                printf("\n**************** %d *****************\n", i);
                printf("COD: %d\n", aco[i].codigo);
                printf("DESCRIÇÃO: %s\n", aco[i].descricao);
                printf("STATUS: %s\n", aco[i].status);
                achou++;
                for (j = 0; j < num2; j++) {
                    if (aco[i].categoria.codigo == cat[j].codigo) {
                        printf("CATEGORIAS: %s\n", cat[j].descricao);
                        printf("FACILIDADES: %s\n", cat[j].facilidade);
                        printf("VALOR DIARIA: %f\n", cat[j].valorDiario);
                        printf("N° PESSOAS: %d\n", cat[j].quantidadePessoas);
                    }

                }
            
        }
     printf("Entre com a quantidade de pessoas desejada: ");
        scanf("%d*c", &quant);

        for (i = 0; i < num; i++) {
            if (cat[i].quantidadePessoas == quant) {
                printf("\n**************** %d *****************\n", i);
                printf("COD: %d\n", aco[i].codigo);
                printf("DESCRIÇÃO: %s\n", aco[i].descricao);
                printf("STATUS: %s\n", aco[i].status);
                achou++;
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
     free(aco);
     free(cat);
}