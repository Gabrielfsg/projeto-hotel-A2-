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
#include "Data.h"
#include "Hora.h"
#include "Caixa.h"
#include "MenuCaixa.h"
#include "EntradaProdutos.h"

/*
 * 
 */


int main() {
    float v;
    //somaVendaCaixa(getDataHoje());
    //somaVendaCaixa2(getDataHoje(),&v);
    //NotaFiscalEntrada *arr;
    //int num = 0;
    
    //arr = listarNotaFiscalEntradaBIN(&num);
    
    //printf("AAA: %d\n",arr[0].codCaixa);
    somaValores();
    //menuPrincipal();
    //printf("MAIN = %f\n",v);
    return (EXIT_SUCCESS);
}

