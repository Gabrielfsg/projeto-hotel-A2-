/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tag.c
 * Author: Daniel
 *
 * Created on 2 de Abril de 2021, 08:58
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int comparaString(char *s1, char *s2) {
    int i;
    for (i = 0;; i++) {
        if (s1[i] == s2[i]) {
            if (s2[i] == '>') {
                break;
            }
        } else {
            return 0;
        }
    }
    return 1;
}

