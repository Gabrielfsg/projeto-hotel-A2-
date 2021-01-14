/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Daniel
 *
 * Created on 2 de Janeiro de 2021, 15:34
 */

#include <stdio.h>
#include <stdlib.h>
#include "CatAcomod.h"
#include "Principal.h"
#include "Login.h"
#include "CategoriaControl.h"
//#include "Categoria.h"
/*
 * 
 */

typedef struct categoria {
    int codigo;
    char descricao[100];
    float valorDiario;
    int quantidadePessoas;
    char facilidade[];
} Categoria;

int main() {
//teste commit
    /*teste();
    //Teste *c1;
    Teste c2;
    //c2.DescCatAcomod="DESC";
    c2.codCatAcomod =1;
    c2.qtePessoas =4;
    c2.valorDiaria = 10.0;*/
    
    //printf("%d \n %d \n %f \n",c2.codCatAcomod, c2.qtePessoas, c2.valorDiaria);
    
    //menuLogin();
    //menuPrincipal();
    //cadastrarHospedes();
    cadastrarCategoriaControle(3,"TESTE",99.5,99,"FACILIDADES");
    Categoria *catPointer = listarCategoriaControle();
    printf("%d\n",catPointer[2].codigo);
    return (EXIT_SUCCESS);
}

