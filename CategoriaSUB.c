/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "Categoria.h"
#include "CategoriaControl.h"
//#include "CategoriaSUB.h"

void cadastrarCategoriaSUB() {
    Categoria c;
    printf("***** CADASTRAR  CATEGORIA DA ACOMODAÇÃO *****\n");
    printf("Digite o cod da Categoria da Acomodação \n");
    scanf("%d%*c", &c.codigo);
    printf("Digite a descrição da Categoria da Acomodação \n");
    fgets(c.descricao, 100, stdin);
    strtok(c.descricao, "\n");
    setbuf(stdin, NULL);
    printf("Digite a descrição da Facilidade da Acomodação \n");
    fgets(c.facilidade, 100, stdin);
    strtok(c.facilidade, "\n");
    setbuf(stdin, NULL);
    printf("Digite o Valor da Diária \n");
    scanf("%f%*c", &c.valorDiario);
    printf("Digite a Capacidade de Pessoas \n");
    scanf("%d%*c", &c.quantidadePessoas);
    //Salva no arquivo se não possuir codigo igual
    int r = /*cadastrarCategoriaControle(c);*/ cadastrarCategoriaBIN(c, 1);
    if (r == 1) {
        printf("\nCadastro Realizado com Sucesso!\n");
    } else {
        printf("\nNÂO foi possivel realizar o cadastro,codigo %d já existente!\n", c.codigo);
    }

}

void listarCategoria() {
    //pega a lista de ACOMODAÇÃO do arquivo
    // Categoria *cat = listarCategoriaTXT();
    int num;
    Categoria *cat = /*listarCategoriaControle();*/listarCategoriaBIN(&num);
    printf("%d",num);
    //lista ACOMODAÇÃO
    int i;
    for (i = 0; i < num; i++) {
        printf("\n-----CATEGORIA %d -----------\n", i + 1);
        printf("CODIGO : %d\n", cat[i].codigo);
        printf("DESCRIÇÃO :");
        printf("%s\n", cat[i].descricao);
        printf("FACILIDADE :");
        printf("%s\n", cat[i].facilidade);
        printf("QUANTIDADE DE PESSOAS : %d\n", cat[i].quantidadePessoas);
        printf("Valor Diaria: %f \n", cat[i].valorDiario);

    }
    free(cat);
    /* */
}

void atualizarCategoria() {
    printf("***** ALTERAR DADOS DA CATEGORIA DA ACOMODAÇÃO  *****\n");
    int num;
    Categoria *cat = listarCategoriaControleBIN(&num); //listarCategoriaControle();
    Categoria c;
    //int num = sizeof (cat) / sizeof (Categoria);
    //lista ACOMODAÇÃO
    int i;
    for (i = 0; i < num; i++) {
        printf("\n-----CATEGORIA %d -----------\n", i + 1);
        printf("cod : %d\n", cat[i].codigo);
        printf("DESCRIÇÃO :");
        printf("%s\n", cat[i].descricao);
        printf("FACILIDADE :");
        printf("%s\n", cat[i].facilidade);
        printf("QUANTIDADE DE PESSOAS : %d\n", cat[i].quantidadePessoas);
        printf("Valor Diaria: %f \n", cat[i].valorDiario);
    }
    printf("Digite o cod da categoria da acomodação \n");
    scanf("%d%*c", &c.codigo);
    printf("Digite a descrição da Categoria da Acomodação \n");
    fgets(c.descricao, 100, stdin);
    //scanf("%[^\n]s%*c", c.descricao);
    strtok(c.descricao, "\n");
    setbuf(stdin, NULL);
    printf("Digite a descrição da Facilidade da Acomodação \n");
    fgets(c.facilidade, 100, stdin);
    strtok(c.facilidade, "\n");
    setbuf(stdin, NULL);
    printf("Digite o Valor da Diária \n");
    scanf("%f%*c", &c.valorDiario);
    printf("Digite a Capacidade de Pessoas \n");
    scanf("%d%*c", &c.quantidadePessoas);
    int r = editarCategoriaControleBIN(c); //editarCategoriaTXT(cat, c, num);
    if (r == 1) {
        printf("\nEdição Realizado com Sucesso!\n");
    } else {
        printf("\nNÂO foi possivel realizar a Edição,codigo %d NÃO existente!\n", c.codigo);
    }
}

void deletarCategoria() {
    int cod;
    printf("***** DELETAR CATEGORIA DA ACOMODAÇÃO  *****\n");
    printf("Digite o cod da acomodação \n");
    scanf("%d%*c", &cod);
    int r = removerCategoriaControleBIN(cod); //excluirCategoria(cod);
    if (r == 1) {
        printf("\nExclusão realizada com sucesso!\n");
    } else {
        printf("\nNão foi possivel encontrar categoria de codigo %d \n", cod);
    }
}