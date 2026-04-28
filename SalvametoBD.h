/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SalvametoBD.h
 * Author: Daniel
 *
 * Created on 20 de Janeiro de 2021, 15:52
 */

#ifndef SALVAMETOBD_H
#define SALVAMETOBD_H
/*pra retorno = 2 utilizar salvamento em arquivos BIN caso seja 1 utilizar TXT*/
int listar();
/*Cadastre apenas 1 ou 2 1 = TXT e 2 = BIN*/
/*Retorno == 0 erro ao alterar*/
int alterar(int opc) ;

#endif /* SALVAMETOBD_H */

