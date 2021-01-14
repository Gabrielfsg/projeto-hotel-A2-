/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Categoria.h"

void cadastrarCategoriaControle(int codig, char descricao[], float valorDiario, int qtd, char facilidade[]) {
    if (validar(codig) == 0)
        cadastrarCategoriaTXT(codig, descricao, valorDiario, qtd, facilidade);
    else
        printf("Codigo existente, tente outro!!\n");
}

Categoria* listarCategoriaControle() {
    return listarCategoriaTXT();
}

void mostrarCategoriaControle() {
    int linhas = numLinhas();
    mostrar(listarCategoriaTXT(), linhas);
}