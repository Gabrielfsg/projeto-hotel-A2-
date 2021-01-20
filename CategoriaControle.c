/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Categoria.h"
//#include "CategoriaControl.h"

int cadastrarCategoriaControle(Categoria cat) {
    if (validar(cat.codigo) == 0) {
        return cadastrarCategoriaTXT(cat);
    } else {
        return 0;
    }
}

int salvaCategoriaTXT(Categoria *cat, int num) {
    return salvarCategoriaTXT(cat, num);
}

Categoria* listarCategoriaControle() {
    return listarCategoriaTXT();
}

int numLinhasCategoria() {
    return numLinhas();
}

void mostrarCategoriaControle() {
    int linhas = numLinhas();
    mostrar(listarCategoriaTXT(), linhas);
}

int editarCategoriaTXT(Categoria *cat, Categoria c, int num) {
    int i;
    for (i = 0; i < num; i++) {
        printf("cat.codigo = %d, c.codigo = %d \n", cat[i].codigo, c.codigo);
        if ((int) (cat[i].codigo) == (int) (c.codigo)) {
            printf("entrou");
            strcpy(cat[i].descricao, c.descricao);
            strcpy(cat[i].facilidade, c.facilidade);
            cat[i].quantidadePessoas = c.quantidadePessoas;
            cat[i].valorDiario = c.valorDiario;
        }
    }
    printf("---------------------\n");
    for (i = 0; i < num; i++) {
        printf("2. cat.codigo = %d, c.codigo = %d \n", cat[i].codigo, c.codigo);

    }


    return salvaCategoriaTXT(cat, num);
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
                cat = realloc(cat,(num-1)*sizeof(Categoria));
            }
            break;
        }
    }
    //salva no arquivo txt com uma categoria a menos
    // retorna s, se editou com sucesso e f se não achou o codigo;
    return salvaCategoriaTXT(cat, num - 1);

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

Categoria* listarCategoriaControleBIN(int *num) {
    return listarCategoriaBIN(num);
}

int removerCategoriaControleBIN(int cod) {
    int num;
    Categoria *cat = listarCategoriaBIN(&num);
    
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
                cat = realloc(cat,(num-1)*sizeof(Categoria));
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