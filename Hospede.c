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

        fflush(listaHospedes);
        printf("\nHOSPEDE CADASTRADO COM SUCESSO\n");

        fclose(listaHospedes);
    }
}

Hospede* getAllHospedes(int numHospedes) {
    int index = 1; //PARA ARMAZENAR O TAMANHO DO VETOR

    Hospede *arrayHospedes = (Hospede *) malloc(sizeof (Hospede) * numHospedes); //PONTEIRO DE HÓSPEDE VIRA UM VETOR AO CHAMAR MALLOC
    if (arrayHospedes == NULL) {
        printf("ERRO DE ALOCAÇÃO");
        exit(1);
    }

    //pega a lista de hóspedes do arquivo
    FILE *scanHospedes;

    scanHospedes = fopen(".\\persist\\hospedes.txt", "r");
    if (scanHospedes == NULL) {
        printf(" ERRO DE LEITURA ");
    } else {
        //rewind(scanHospedes);
        //while (!feof(scanHospedes)) { //enquanto não for o final do arquivo
        for (int i = 0; i < numHospedes; i++) {
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
            arrayHospedes[index - 1] = h;
            index++;
            //REALLOCA O VETOR DE HÓSPEDE, ADICIONANDO MAIS UM "ESPAÇO" PARA HOSPEDE
            //arrayHospedes = realloc(arrayHospedes, (sizeof (Hospede) + sizeof (arrayHospedes)));
            //arrayHospedes = realloc(arrayHospedes, (sizeof (Hospede)*(index+1)));

            //teste arrayHospedes = malloc(count*sizeof(Hospede));          
        }
        fclose(scanHospedes);

        /*printf("\n TESTE PARA VER TODOS OS ITENS DO ARRAY \n");
        for (int i = 0; i < index - 1; i++) {
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
    
    Hospede* arrHospedes = getAllHospedes(numHospedes);
    for (int i = 0; i < numHospedes; i++) {
        if (arrHospedes[i].codigo == cod) {
            //printf("\nACHOU O COD == AO QUE DIGITOU: %d == %s\n",cod,arrHospedes[i].nome);
            return arrHospedes[i];
        }
    }
}




void atualizarHospedeTXT(Hospede novoHosp) {
    FILE* hosp = fopen(".\\persist\\hospedes_temp.txt", "w");
    if (hosp == NULL) {
        printf("ERRO AO ABRIR ARQUIVO");
    } else {
        int numHospedes = getNumHospedes();
        Hospede* arrHosp = getAllHospedes(numHospedes);

        for (int i = 0; i < numHospedes; i++) {
            if (arrHosp[i].codigo != novoHosp.codigo) {
                printf("%d != %d\n",arrHosp[i].codigo,novoHosp.codigo);
                strtok(arrHosp[i].nome, "\r");
                fprintf(hosp, "Cod: %d\r\nNome: %s\r\nCPF: %s\r\nTelefone: %s\r\nEmail: %s\r\nSexo: %c\r\nEstadoCivil: %s\r\n", arrHosp[i].codigo, arrHosp[i].nome, arrHosp[i].cpf, arrHosp[i].telefone, arrHosp[i].email, arrHosp[i].sexo, arrHosp[i].esCivil);
                fflush(hosp);

            } else {
                printf("ESSE É O QUE VAI ALTERAR: COD = %d\n",novoHosp.codigo);
                strtok(novoHosp.nome, "\r");
                fprintf(hosp, "Cod: %d\r\nNome: %s\r\nCPF: %s\r\nTelefone: %s\r\nEmail: %s\r\nSexo: %c\r\nEstadoCivil: %s\r\n", novoHosp.codigo, novoHosp.nome, novoHosp.cpf, novoHosp.telefone, novoHosp.email, novoHosp.sexo, novoHosp.esCivil);
                fflush(hosp);
            }
        }

        fclose(hosp);
        free(arrHosp);
        remove(".\\persist\\hospedes.txt");
        rename(".\\persist\\hospedes_temp.txt", ".\\persist\\hospedes.txt");
    }
     
}

void deletarHospede(int cod) {

    FILE* hosp = fopen(".\\persist\\hospedes_temp.txt", "w");
    if (hosp == NULL) {
        printf("ERRO");
    } else {
        int numHospedes = getNumHospedes();
        Hospede* arrHosp = getAllHospedes(numHospedes);

        for (int i = 0; i < numHospedes; i++) {
            if (arrHosp[i].codigo != cod) {

                strtok(arrHosp[i].nome, "\r");
                fprintf(hosp, "Cod: %d\r\nNome: %s\r\nCPF: %s\r\nTelefone: %s\r\nEmail: %s\r\nSexo: %c\r\nEstadoCivil: %s\r\n", arrHosp[i].codigo, arrHosp[i].nome, arrHosp[i].cpf, arrHosp[i].telefone, arrHosp[i].email, arrHosp[i].sexo, arrHosp[i].esCivil);
                fflush(hosp);

            }
        }

        fclose(hosp);
        free(arrHosp);
        remove(".\\persist\\hospedes.txt");
        rename(".\\persist\\hospedes_temp.txt", ".\\persist\\hospedes.txt");
    }
}