/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Categoria.h"
#include "CategoriaSUB.h"
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
    int r = cadastrarCategoriaControleBIN(c,1); /*cadastrarCategoriaControle(c);*/
    if (r == 1) {
        printf("\nCadastro Realizado com Sucesso!\n");
    } else {
        printf("\nNÂO foi possivel realizar o cadastro,codigo %d já existente!\n", c.codigo);
    }

}

void listarCategoria() {
    //pega a lista de ACOMODAÇÃO do arquivo
    // Categoria *cat = listarCategoriaTXT();
    int num; //numLinhas();
    Categoria *cat = /*listarCategoriaControle();*/listarCategoriaBIN(&num);
    printf("%d", num);
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
    Categoria *cat = listarCategoriaBIN(&num); //listarCategoriaControle();
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
    int r = editarCategoriaControleBIN(c); 
    editarCategoriaTXT(cat, c, num);
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
    int r = removerCategoriaControleBIN(cod);
    //excluirCategoria(cod);
    if (r == 1) {
        printf("\nExclusão realizada com sucesso!\n");
    } else {
        printf("\nNão foi possivel encontrar categoria de codigo %d \n", cod);
    }
}

//metodos de controle

int cadastrarCategoriaControle(Categoria cat) {
    if (validar(cat.codigo) == 0) {
        return cadastrarCategoriaTXT(cat);
    } else {
        return 0;
    }
}

int numLinhasCategoria() {
    return numLinhas();
}

int editarCategoriaTXT(Categoria *cat, Categoria c, int num) {
    int i;
    for (i = 0; i < num; i++) {
        if ((int) (cat[i].codigo) == (int) (c.codigo)) {
            printf("entrou");
            strcpy(cat[i].descricao, c.descricao);
            strcpy(cat[i].facilidade, c.facilidade);
            cat[i].quantidadePessoas = c.quantidadePessoas;
            cat[i].valorDiario = c.valorDiario;
        }
    }

    return salvarCategoriaTXT(cat, num);
}

int excluirCategoria(int cod) {
    int num = numLinhas();
    Categoria *cat = listarCategoriaTXT();
    int i;
    for (i = 0; i < num; i++) {
        if (cat[i].codigo == cod) {
            int j;
            for (j = i; j < num - 1; j++) {
                cat[i].codigo = cat[i + 1].codigo;
                strcpy(cat[i].descricao, cat[i + 1].descricao);
                strcpy(cat[i].facilidade, cat[i + 1].facilidade);
                cat[i].quantidadePessoas = cat[i + 1].quantidadePessoas;
                cat[i].valorDiario = cat[i + 1].valorDiario;
                cat = realloc(cat, (num - 1) * sizeof (Categoria));
            }
            break;
        }
    }
    //salva no arquivo txt com uma categoria a menos
    // retorna s, se editou com sucesso e f se não achou o codigo;
    return salvarCategoriaTXT(cat, num - 1);

}

/*arquivo binario*/
int cadastrarCategoriaControleBIN(Categoria cat, int qtd) {
    if (validarCategoriaBIN(cat.codigo) == 0) {
        return cadastrarCategoriaBIN(cat, qtd);
    } else {
        return 0;
    }
    return 1;
}

int editarCategoriaControleBIN(Categoria cat) {
    editarCategoriaBIN(cat, validarCategoriaBIN(cat.codigo));
}

// remove a categoria do vetor, realoca ele e reecreve o arquivo

int removerCategoriaControleBIN(int cod) {
    int num;
    Categoria *cat = listarCategoriaBIN(&num);
    int i;
    for (i = 0; i < num; i++) {
        if (cat[i].codigo == cod) {
            int j;
            //realoca o vetor
            for (j = i; j < num - 1; j++) {
                cat[i].codigo = cat[i + 1].codigo;
                strcpy(cat[i].descricao, cat[i + 1].descricao);
                strcpy(cat[i].facilidade, cat[i + 1].facilidade);
                cat[i].quantidadePessoas = cat[i + 1].quantidadePessoas;
                cat[i].valorDiario = cat[i + 1].valorDiario;
                cat = realloc(cat, (num - 1) * sizeof (Categoria));
            }
            break;
        }
    }
    //apaga arquivo
    int r = removerCategoriaBIN();
    if (r == 1) {
        //se deu certo reescreve arquivo
        salvarCategoriaTXT(cat, num - 1);
    }


}