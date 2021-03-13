/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Acomodacao.h"
#include "Categoria.h"
#include "AcomodacaoSUB.h"
#include "SalvametoBD.h"

void relatarAcomodacao() {
    Acomodacao *a;
    Categoria *c;
    int num2, num;
    int i, j;
    int bd = listar();
    if (bd == 1) {
        //pega a lista de ACOMODAÇÃO do arquivo
        num = numAcomodacao();
        a = listarAcomodacaoTXT();
        c = listarCategoriaTXT();
        num2 = numCategoria();
    } else if (bd == 2) {
        //lista as acomodaçoes e aponta o tamanho do vetor para num
        a = listarAcomodacaoBIN(&num);
        //lista as categrias e aponta o tamanho do vetor para num2
        c = listarCategoriaBIN(&num2);
    } else {
        printf("\nAltere a opção de salvamento em (MENU Principal->9 . Configurações-> 1. Op de BD.)\n");
    }
    if (bd > 0) {
        int opc;
        int aux = 0;
        int cod;
        while (aux == 0) {
            printf("Entre com a opção de filtro: \n"
                    "1.FAIXA DE CÓDIGOS. \n"
                    "2.CATEGORIA. \n"
                    "3.DATA DISPONÍVEL. \n"
                    "OPÇÃO: ");
            scanf("%d*c", &opc);

            switch (opc) {
                case 1:
                    if (num > 0) {
                        printf("\n********* RELATORIO *********\n");
                        for (i = 0; i < num; i++) {
                            printf("\n**************** %d *****************\n", i);
                            printf("COD: %d\n", a[i].codigo);
                            printf("DESCRIÇÃO: %s\n", a[i].descricao);
                            printf("STATUS: %s\n", a[i].status);
                            //LISTAR FACILIDADES PRECISARÁ DE UM TRATAMENTO ESPECIAL
                            for (j = 0; j < num2; j++) {
                                if (a[i].categoria.codigo == c[j].codigo) {
                                    printf("CATEGORIAS: %s\n", c[j].descricao);
                                    printf("FACILIDADES: %s\n", c[j].facilidade);
                                    printf("VALOR DIARIA: %f\n", c[j].valorDiario);
                                    printf("N° PESSOAS: %d\n", c[j].quantidadePessoas);
                                    printf("\n      ******************\n");
                                }

                            }
                        }
                    } else {
                        printf("\n*********NENHUMA ACOMODAÇÃO CADASTRADA*********\n");
                    }
                    break;

                case 2:

                    printf("Entre com o código da categoria: ");
                    scanf("%d*c", &cod);

                    if (num > 0) {
                        printf("\n********* RELATORIO *********\n");
                        for (i = 0; i < num; i++) {
                            if (a[i].categoria.codigo == cod) {
                                printf("\n**************** %d *****************\n", i);
                                printf("COD: %d\n", a[i].codigo);
                                printf("DESCRIÇÃO: %s\n", a[i].descricao);
                                printf("STATUS: %s\n", a[i].status);
                                
                                //LISTAR FACILIDADES PRECISARÁ DE UM TRATAMENTO ESPECIAL
                                for (j = 0; j < num2; j++) {
                                    if (a[i].categoria.codigo == c[j].codigo) {
                                        printf("CATEGORIAS: %s\n", c[j].descricao);
                                        printf("FACILIDADES: %s\n", c[j].facilidade);
                                        printf("VALOR DIARIA: %f\n", c[j].valorDiario);
                                        printf("N° PESSOAS: %d\n", c[j].quantidadePessoas);
                                        printf("\n          ******************\n");
                                    }

                                }
                            }

                        }
                    } else {
                        printf("\n*********NENHUMA ACOMODAÇÃO CADASTRADA*********\n");
                    }
                    break;

                case 3:

                    break;
            }

        }
    }
}