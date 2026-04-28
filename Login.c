/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include<String.h>

void login(char nome[], char senha[]);

void menuLogin() {
    char c;
    int i = 0;
    char nome[10];
    char senha[10];
    int opc = 0;
    while (opc >= 0) {
        printf("********************LOGIN*************************\n");
        printf("1.Login do Operador do Sistema.\n");
        printf("2.Cadastrar Empresa.\n");
        printf("3.Sair.\n");
        scanf("%d%*c", &opc);
        switch (opc) {
            case 1:
                printf("**Digite o Dados a Seguir!.\n");
                printf("Usuario : ");
                scanf("%[A-Z a-z]s%*c", nome);
                setbuf(stdin, NULL);
                printf("Senha : ");
                //Esconde Senha
               /* while ((c = getch()) != 13) {// codigo do teclado para 13 = ENTER pela ascii
                    if (c == 8) {
                        i--;
                        senha[i] = '\0';
                    } else {// 8 == backpasse
                        senha[i] = c;
                        i++;
                    }
                }
                senha[i] = '\0';
                i = 0;*/
                // Aqui vai o metodo que verifica o login
                break;
            case 2:

                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Valor Invalido!\n");
                break;
        }
    }
}
