/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <String.h>
#include "Hora.h"

Hora getHoraAtual() {
    char hh[3], mm[3], ss[3];
    strcpy(hh, "");
    strcpy(mm, "");
    strcpy(ss, "");
    strncat(hh, __TIME__, 2);
    strncat(mm, __TIME__ + 3, 2);
    strncat(ss, __TIME__ + 6, 2);
    Hora hora;
    hora.hh = atoi(hh);
    hora.mm = atoi(mm);
    hora.ss = atoi(ss);
    return hora;
}