/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CategoriaXML.h
 * Author: Daniel
 *
 * Created on 31 de Março de 2021, 22:19
 */

#ifndef CATEGORIAXML_H
#define CATEGORIAXML_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* CATEGORIAXML_H */
int geraXMLCategoria(Categoria *cat, int num);
void encontacampo(FILE *file, char nome[]);
Categoria* importaCategoriaXML();
//Categoria* getCategoriaXML(char local[], int *num);
int comparaString(char *s1, char *s2);
