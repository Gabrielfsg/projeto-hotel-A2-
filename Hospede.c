/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"Data.h"
#include"Endereco.h"
#include"Hospede.h"
#include "HospedeControl.h"

void cadastrarHospedesTXT(Hospede h) {
    FILE* listaHospedes;
    listaHospedes = fopen(".\\persist\\hospedes.txt", "a");
    if (listaHospedes == NULL) {
        printf("ERRO DE ABERTURA\n");
    } else {
        fprintf(listaHospedes, "Cod: %d\r\nNome: %s\r\nCPF: %s\r\nTelefone: %s\r\nEmail: %s\r\nSexo: %c\r\nEstadoCivil: %s\r\n", h.codigo, h.nome, h.cpf, h.telefone, h.email, h.sexo, h.esCivil);
        printf("\nHOSPEDE CADASTRADO COM SUCESSO\n");

        fclose(listaHospedes);
    }
}

Hospede* getAllHospedes() {
    int index = 0; //PARA ARMAZENAR O TAMANHO DO VETOR

    Hospede *arrayHospedes = (Hospede *) malloc(sizeof (Hospede)); //PONTEIRO DE HÓSPEDE VIRA UM VETOR AO CHAMAR MALLOC
    if (arrayHospedes == NULL) {
        printf("ERRO DE ALOCAÇÃO");
    }

    //pega a lista de hóspedes do arquivo
    FILE *scanHospedes;

    scanHospedes = fopen(".\\persist\\hospedes.txt", "r");
    if (scanHospedes == NULL) {
        printf(" ERRO DE LEITURA ");
    } else {
        while (!feof(scanHospedes)) { //enquanto não for o final do arquivo
            Hospede h;
            char text[20];

            //FSCANF PARA PEGAR OS VALORES DO ARQUIVO. "TEXT[20]" É APENAS PARA ARMAZENAR A STRING QUE VEM ANTES DO VALOR.
            fscanf(scanHospedes, "%s %d", text, &h.codigo);
            fscanf(scanHospedes, "%s %[^\n]s", text, h.nome);
            fscanf(scanHospedes, "%s %s", text, h.cpf);
            fscanf(scanHospedes, "%s %s", text, h.telefone);
            fscanf(scanHospedes, "%s %s", text, h.email);
            fscanf(scanHospedes, "%s %c", text, &h.sexo);
            //ENDEREÇO
            //DATA NASC
            fscanf(scanHospedes, "%s %s", text, h.esCivil);


            //COLOCA O HOSPEDE NO ARRAY
            arrayHospedes[index] = h;
            index++;

            //REALLOCA O VETOR DE HÓSPEDE, ADICIONANDO MAIS UM "ESPAÇO" PARA HOSPEDE
            arrayHospedes = realloc(arrayHospedes, (sizeof (Hospede) + sizeof (arrayHospedes)));

            //teste arrayHospedes = malloc(count*sizeof(Hospede));          
        }
        fclose(scanHospedes);

        /*printf("\n TESTE PARA VER TODOS OS ITENS DO ARRAY \n");
        for (int i = 0; i < index; i++) {
            printf("+++++++++++\n");
            printf("POS: %d -> %d\n", i, arrayHospedes[i].codigo);
            printf("POS: %d -> %s\n", i, arrayHospedes[i].nome);
            printf("POS: %d -> %s\n", i, arrayHospedes[i].cpf);
            printf("POS: %d -> %s\n", i, arrayHospedes[i].telefone);
            printf("POS: %d -> %s\n", i, arrayHospedes[i].email);
            printf("POS: %d -> %c\n", i, arrayHospedes[i].sexo);
            printf("POS: %d -> %s\n", i, arrayHospedes[i].esCivil);
            printf("+++++++++++\n");
        }*/
        return arrayHospedes;
    }
}

Hospede getHospedeByCod(int cod, int numHospedes) {
    //printf("ENTROU GETHOSPEDEBYCOD");
    int i;
    setbuf(stdout, NULL);
    Hospede* arrHospedes = getAllHospedes();
    for ( i = 0; i < numHospedes; i++) {
        if (arrHospedes[i].codigo == cod) {
            //printf("\nACHOU O COD == AO QUE DIGITOU: %d == %s\n",cod,arrHospedes[i].nome);
            //printf("&&&&&&&&&&&&&&&&&\n");
            //printf("GETHOSPEDE BY COD  COD: %d NOME: %s\n",arrHospedes[i].codigo,arrHospedes[i].nome);
            //printf("&&&&&&&&&&&&&&&&&\n");
            return arrHospedes[i];
        }
    }
}

/*void atualizarHospedes() {
    printf("***** ALTERAR DADOS DO HÓSPEDE *****\n");

    printf("Digite o cod do hóspede \n");
    //scanf("%d%*c",&);
}*/


void sobrescreverHospedesTXT(int cod) {
    int i = 0;
    printf("O COD QUE VAI SER DELETADO É: %d\n", cod);

    //esse método pega todo o array de hóspedes
    Hospede* arrayHospedes = getAllHospedes();
    int numHospedes = getNumHospedes();

    //depois ele escreve todos os hóspedes no aruqivo de novo
    FILE* arq = fopen(".\\persist\\hospedes.txt", "w"); //W, PARA SOBRESCREVER TUDO, MENOS O QUE FOI DELETADO
    if (arq == NULL) {
        printf("ERRO DE ABERTURA\n");
    } else {

        for (i = 0; i < numHospedes; i++) {
            //mas existe um if para ver se o hospede do array tem o mesmo código do cara que ele deletou
            if (arrayHospedes[i].codigo == cod) {
                //printf("ESSE NÃO SERÁ ESCRITO: %d\n",arrayHospedes[i].cod);
            } else {
                Hospede h = arrayHospedes[i];
                fprintf(arq, "Cod: %d\r\nNome: %s\r\nCPF: %s\r\nTelefone: %s\r\nEmail: %s\r\nSexo: %c\r\nEstadoCivil: %s\r\n", h.codigo, h.nome, h.cpf, h.telefone, h.email, h.sexo, h.esCivil);
                //fprintf(arq, "Cod: %d\r\nNome: %s\r\nCPF: %s\r\nTelefone: %s\r\nEmail: %s\r\nSexo: %c\r\nEstadoCivil: %s\r\n", arrayHospedes[i].codigo, arrayHospedes[i].nome, arrayHospedes[i].cpf, arrayHospedes[i].telefone, arrayHospedes[i].email, arrayHospedes[i].sexo, arrayHospedes[i].esCivil);
                /*fprintf(arq,"Cod: %d\r\n",arrayHospedes[i].codigo);
                fprintf(arq,"Nome: %s",arrayHospedes[i].nome);
                fprintf(arq,"CPF: %s\r\n",arrayHospedes[i].cpf);
                fprintf(arq,"Telefone: %s\r\n",arrayHospedes[i].telefone);
                fprintf(arq,"Email: %s\r\n",arrayHospedes[i].email);
                fprintf(arq,"Sexo: %c\r\n",arrayHospedes[i].sexo);
                fprintf(arq,"EstadoCivil: %s\r\n",arrayHospedes[i].esCivil);*/
            }
        }
        printf("ACABOU DE SOBRESCREVER\n");

        Hospede* ar = getAllHospedes();
        printf("\n DEPOIS DE SOBRESCREVER \n");
        for ( i = 0; i < (numHospedes - 1); i++) {
            printf("+++++++++++\n");
            printf("POS: %d -> %d\n", i, ar[i].codigo);
            printf("POS: %d -> %s\n", i, ar[i].nome);
            printf("POS: %d -> %s\n", i, ar[i].cpf);
            printf("POS: %d -> %s\n", i, ar[i].telefone);
            printf("POS: %d -> %s\n", i, ar[i].email);
            printf("POS: %d -> %c\n", i, ar[i].sexo);
            printf("POS: %d -> %s\n", i, ar[i].esCivil);
            printf("+++++++++++\n");
        }
        fclose(arq);
        free(arrayHospedes);
    }

}
