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

/*
 * 
 */


int main() {

    //menuPrincipal();
    Caixa c = caixaAberto();
    somaVendaCaixa(c.data);
    return (EXIT_SUCCESS);
}

