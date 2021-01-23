/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "OperadorSistema.h"


int salvarOperadorControleTXT(OperadorSistema* opera, int num) {
    return salvarOperadorTXT(opera, num);
}

int removerOperadorControleBIN(int cod) {
    int num;
    OperadorSistema *opera = listarOpBIN(&num);

    int i;
    for (i = 0; i < num; i++) {
        if (opera[i].codigo == cod) {
            int j;
            for (j = i; j < num - 1; j++) {
                opera[i].codigo = opera[i + 1].codigo;
                strcpy(opera[i].nome, opera[i + 1].nome);
                strcpy(opera[i].usuario, opera[i + 1].usuario);
                strcpy(opera[i].senha, opera[i + 1].senha);
                opera = realloc(opera,(num-1)*sizeof(OperadorSistema));
            }
            break;
        }
    }
    //apaga arquivo
    int v = removerOperadorBIN();
    if (v == 1) {
        //se deu certo reescreve arquivo
        salvarOperadorTXT(opera, num - 1);
    }
}
