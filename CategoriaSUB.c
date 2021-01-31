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
#include "AcomodacaoSUB.h"
//#include "CategoriaSUB.h"

void cadastrarCategoriaSUB() {
    int bd = listar();
    int r;
    if (bd > 0) {
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
        if (bd == 1) {
            r = cadastrarCategoriaControle(c);

        } else {
            r = cadastrarCategoriaControleBIN(c, 1);
        }
        if (r == 1) {
            printf("\nCadastro Realizado com Sucesso!\n");
        } else {
            printf("\nNÂO foi possivel realizar o cadastro,codigo %d já existente!\n", c.codigo);
        }
    } else {
        printf("\nAltere a opção de salvamento em (MENU Principal->9 . Configurações-> 1. Op de BD.)\n");
    }
}

void listarCategoria() {
    int bd = listar();
    int num;
    Categoria *cat;
    if (bd == 1) {
        cat = listarCategoriaTXT();
        num = numLinhasCategoria();
    } else if (bd == 2) {
        cat = listarCategoriaBIN(&num);
    } else {
        printf("\nAltere a opção de salvamento em (MENU Principal->9 . Configurações-> 1. Op de BD.)\n");
    }
    //lista CATEGORIA
    if (bd > 0) {
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
    }
    /* */
}

void atualizarCategoria() {

    int num, r;
    Categoria *cat;
    Categoria c;
    int bd = listar();
    if (bd == 1) {
        cat = listarCategoriaTXT();
        num = numLinhasCategoria();
    } else if (bd == 2) {
        listarCategoriaBIN(&num);
    } else {
        printf("\nAltere a opção de salvamento em (MENU Principal->9 . Configurações-> 1. Op de BD.)\n");
    }
    if (bd > 0) {
        printf("***** ALTERAR DADOS DA CATEGORIA DA ACOMODAÇÃO  *****\n");
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
        if (bd == 1) {
            r = editarCategoriaTXT(cat, c, num);
        } else {
            r = editarCategoriaControleBIN(c);
        }
        if (r == 1) {
            printf("\nEdição Realizado com Sucesso!\n");
        } else {
            printf("\nNÂO foi possivel realizar a Edição,codigo %d NÃO existente!\n", c.codigo);
        }
    }
}

void deletarCategoria() {
    int bd = listar();
    int cod, r;
    if (bd > 0) {
        printf("***** DELETAR CATEGORIA DA ACOMODAÇÃO  *****\n");
        printf("Digite o cod da acomodação \n");
        scanf("%d%*c", &cod);
        if (bd == 1) {
            r = removerCategoriaControleBIN(cod);
        } else if (bd == 2) {
            r = removerCategoriaControleBIN(cod);
        }
        //excluirCategoria(cod);
        if (r == 1) {
            printf("\nExclusão realizada com sucesso!\n");
        } else {
            printf("\nNão foi possivel encontrar categoria de codigo %d \n", cod);
        }
    } else {
        printf("\nAltere a opção de salvamento em (MENU Principal->9 . Configurações-> 1. Op de BD.)\n");
    }
}

//metodos de controle

int cadastrarCategoriaControle(Categoria cat) {
    int v = validarCategoria(cat.codigo);
    if (v == 0) {
        return cadastrarCategoriaTXT(cat);
    } else {
        return 0;
    }
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
    int num = numLinhasCategoria();
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
    int v = validarCategoriaBIN(cat.codigo);
    if (v == 0) {
        return cadastrarCategoriaBIN(cat, qtd);
    } else {
        return 0;
    }
    return 1;
}

int editarCategoriaControleBIN(Categoria cat) {
    int v = validarCategoriaBIN(cat.codigo);
    int r = editarCategoriaBIN(cat, v);
    return r;
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
        return salvarCategoriaTXT(cat, num - 1);
    } else {
        return 0;
    }
}