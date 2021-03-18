/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MenuCheckOut.h
 * Author: Daniel
 *
 * Created on 11 de Março de 2021, 21:13
 */

#ifndef MENUCHECKOUT_H
#define MENUCHECKOUT_H
#include "Reserva.h"
#include "Data.h"
#include "CheckIn.h"
#include "CheckOut.h"

#endif /* MENUCHECKIN_H */
void menuCheckOut();
void checkOutHospede();
void printReservaOut(Reserva *res, int num);
void checkInHospede();
void editarReservaOut(int bd, Reserva r);
void pintCheckOut();
void geraComprovanteOut(CheckOut c);

