/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HospedeMenu.h
 * Author: Tales
 *
 * Created on 8 de Janeiro de 2021, 10:24
 */

#ifndef HOSPEDEMENU_H
#define HOSPEDEMENU_H
#include "Hospede.h"

void menuCRUDHospedes();
void cadastrarHospedesControl();
void listarHospedesControl();
Hospede* getAllHospedesControl();
Hospede getHospedeByCodControl();
void atualizarHospedesControl();
void deletarHospedesControl();
int validarCodHospede(int cod, int ext);
int getNumHospedes();

#endif /* HOSPEDEMENU_H */

