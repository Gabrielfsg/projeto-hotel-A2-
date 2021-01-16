/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HospedeControl.h
 * Author: Tales
 *
 * Created on 8 de Janeiro de 2021, 08:51
 */

#ifndef HOSPEDECONTROL_H
#define HOSPEDECONTROL_H
#include "Hospede.h"
void listarHospedes();
void cadastrarHospedes();
void atualizarHospedes();
void deletarHospedes();
Hospede* getAllHospedes();
int validarCod(int cod);
int getNumHospedes();
#endif /* HOSPEDECONTROL_H */

