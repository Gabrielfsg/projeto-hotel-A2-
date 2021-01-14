/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "CategoriaSUB.h"
#include "CategoriaControl.h"

void cadastrarCategoriaSUB() {
    int codigo;
    char descricao[100];
    float valorDiario;
    int quantidadePessoas;
    char facilidade[100];
    printf("***** CADASTRAR  CATEGORIA DA ACOMODAÇÃO *****\n");
    printf("Digite o cod da Categoria da Acomodação \n");
    scanf("%d", &codigo);
    setbuf(stdin, NULL);
    printf("Digite a descrição da Categoria da Acomodação \n");
    scanf("%[a-z A-Z]s", descricao);
    setbuf(stdin, NULL);
    printf("Digite a descrição da Facilidade da Acomodação \n");
    scanf("%[a-z A-Z]s", facilidade);
    setbuf(stdin, NULL);
    printf("Digite o Valor da Diária \n");
    scanf("%f%*c", &valorDiario);
    setbuf(stdin, NULL);
    printf("Digite a Capacidade de Pessoas \n");
    scanf("%d%*c", &quantidadePessoas);
    setbuf(stdin, NULL);
    //Salva no arquivo se não possuir codigo igual
    cadastrarCategoriaControle(codigo, descricao, valorDiario, quantidadePessoas, facilidade);

}

void listarCategoria() {
    //pega a lista de ACOMODAÇÃO do arquivo
    // Categoria *cat = listarCategoriaTXT();

    mostrarCategoriaControle();

    //lista ACOMODAÇÃO
    /*  printf("COD: 123\n");
      printf("DESCRIÇÃO: 123\n");
      //LISTAR FACILIDADES PRECISARÁ DE UM TRATAMENTO ESPECIAL
      printf("DIARIA: 123\n");
      printf("PESSOAS: 123\n");*/

}

void atualizarCategoria() {
    printf("***** ALTERAR DADOS DA CATEGORIA DA ACOMODAÇÃO  *****\n");

    printf("Digite o cod da categoria da acomodação \n");
    //scanf("%d%*c",&);
}

void deletarCategoria() {
    printf("***** DELETAR CATEGORIA DA ACOMODAÇÃO  *****\n");

    printf("Digite o cod da acomodação \n");
    //scanf("%d%*c",&);
}