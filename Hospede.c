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
    FILE* arHospedes;
    arHospedes = fopen(".\\persist\\hospedes.txt", "a");
    if (arHospedes == NULL) {
        printf("ERRO DE ABERTURA\n");
    } else {
        fprintf(arHospedes, "Cod: %d\r\nNome: %s\r\nCPF: %s\r\nTelefone: %s\r\nEmail: %s\r\nSexo: %c\r\nEstadoCivil: %s\r\n", h.codigo, h.nome, h.cpf, h.telefone, h.email, h.sexo, h.esCivil);

        fflush(arHospedes);
        printf("\nHOSPEDE CADASTRADO COM SUCESSO\n");

        fclose(arHospedes);
    }
}

void cadastrarHospedesBIN(Hospede h) {
    FILE* arqHospedes;
    arqHospedes = fopen(".\\persist\\hospedes.bin", "ab");
    if (arqHospedes == NULL) {
        printf("ERRO DE ABERTURA\n");
    } else {
        int count = 0;
        count = fwrite(&h, sizeof (Hospede), 1, arqHospedes);
        fflush(arqHospedes);
        /*fecha o arquivo*/
        fclose(arqHospedes);
        /*libera mémoria*/
        free(arqHospedes);
        if (count == 1) {
            printf("\nHOSPEDE CADASTRADO COM SUCESSO\n");
        } else {
            printf("\nHOSPEDE CADASTRADO COM SUCESSO\n");
        }
        fclose(arqHospedes);
    }
}

Hospede* getAllHospedesTXT(int numHospedes) {
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

Hospede* getAllHospedesBIN(int* numHospedes) {
    //printf("NUMHOSPEDES 1: %d\n",*numHospedes);
    //(*numHospedes)++;
    //printf("NUMHOSPEDES 1: %d\n",*numHospedes);
    int totalLido = 0;
    int index = 0;
    Hospede *arrayHospedes = (Hospede *) malloc(sizeof (Hospede) * 1); //PONTEIRO DE HÓSPEDE VIRA UM VETOR AO CHAMAR MALLOC
    if (arrayHospedes == NULL) {
        printf("ERRO DE ALOCAÇÃO");
        exit(1);
    }

    FILE *fileHospedes;

    fileHospedes = fopen(".\\persist\\hospedes.bin", "rb");
    if (fileHospedes == NULL) {
        printf("ERRO DE LEITURA ");
    } else {
        //rewind(scanHospedes);
        while (!feof(fileHospedes)) { //enquanto não for o final do arquivo
            Hospede h;
            int conseguiuLer = fread(&h, sizeof (Hospede), 1, fileHospedes);
            if (conseguiuLer == 1) {
                //printf("LEU UM HOSPEDE\n");
                (*numHospedes)++;
            } else {
                //printf("ERRO HOSPEDE\n");
            }
            arrayHospedes[index] = h;
            index++;
            arrayHospedes = realloc(arrayHospedes, (index + 1) * sizeof (Hospede));
            //printf("INDEX = %d\n", index);
        }

        fclose(fileHospedes);
        //printf("TOTAL LIDO = %d\n",*numHospedes);

        /*printf("\n TESTE PARA VER TODOS OS ITENS DO ARRAY \n");
        for (int i = 0; i < 3; i++) {
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

Hospede getHospedeByCodTXT(int cod, int numHospedes) {
    //printf("ENTROU GETHOSPEDEBYCOD");

    Hospede* arrHospedes = getAllHospedesTXT(numHospedes);
    for (int i = 0; i < numHospedes; i++) {
        if (arrHospedes[i].codigo == cod) {
            //printf("\nACHOU O COD == AO QUE DIGITOU: %d == %s\n",cod,arrHospedes[i].nome);
            return arrHospedes[i];
        }
    }
}

Hospede getHospedeByCodBIN(int cod) {
    //printf("ENTROU GETHOSPEDEBYCOD BIN");
    Hospede h;
    int numHospedes = 0;
    Hospede* arrayHospedes = getAllHospedesBIN(&numHospedes);
    printf("NUM HOSPEDES = %d\n", numHospedes);
    for (int i = 0; i < numHospedes; i++) {
        if (arrayHospedes[i].codigo == cod) {
            printf("HÓSPEDE ENCONTRADO!!!!!!!!!!!\n");
            printf("COD %d == %d\n", arrayHospedes[i].codigo, cod);
            h = arrayHospedes[i];
            return h;
        }
    }
}

void atualizarHospedeTXT(Hospede novoHosp) {
    FILE* hosp = fopen(".\\persist\\hospedes_temp.txt", "w");
    if (hosp == NULL) {
        printf("ERRO AO ABRIR ARQUIVO");
    } else {
        int numHospedes = getNumHospedes();
        Hospede* arrHosp = getAllHospedesTXT(numHospedes);

        for (int i = 0; i < numHospedes; i++) {
            if (arrHosp[i].codigo != novoHosp.codigo) {
                printf("%d != %d\n", arrHosp[i].codigo, novoHosp.codigo);
                strtok(arrHosp[i].nome, "\r");
                fprintf(hosp, "Cod: %d\r\nNome: %s\r\nCPF: %s\r\nTelefone: %s\r\nEmail: %s\r\nSexo: %c\r\nEstadoCivil: %s\r\n", arrHosp[i].codigo, arrHosp[i].nome, arrHosp[i].cpf, arrHosp[i].telefone, arrHosp[i].email, arrHosp[i].sexo, arrHosp[i].esCivil);
                fflush(hosp);

            } else {
                printf("ESSE É O QUE VAI ALTERAR: COD = %d\n", novoHosp.codigo);
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


void atualizarHospedeBIN(Hospede novoHosp) {
    FILE* hosp = fopen(".\\persist\\hospedes_temp.bin", "wb");
    if (hosp == NULL) {
        printf("ERRO AO ABRIR ARQUIVO");
    } else {
        int numHospedes=0;
        Hospede* arrHosp = getAllHospedesBIN(&numHospedes);

        for (int i = 0; i < numHospedes; i++) {
            if (arrHosp[i].codigo != novoHosp.codigo) {
                printf("ESSE É O QUE NAO VAI ALTERAR %d != %d\n", arrHosp[i].codigo, novoHosp.codigo);
                fwrite(&arrHosp[i], sizeof (Hospede), 1, hosp);
                fflush(hosp);

            } else {
                printf("ESSE É O QUE VAI ALTERAR: COD = %d\n", novoHosp.codigo);
                fwrite(&novoHosp, sizeof (Hospede), 1, hosp);
                fflush(hosp);
            }
        }

        fclose(hosp);
        free(arrHosp);
        remove(".\\persist\\hospedes.bin");
        rename(".\\persist\\hospedes_temp.bin", ".\\persist\\hospedes.bin");
    }

}

void deletarHospede(int cod) {

    FILE* hosp = fopen(".\\persist\\hospedes_temp.txt", "w");
    if (hosp == NULL) {
        printf("ERRO");
    } else {
        int numHospedes = getNumHospedes();
        Hospede* arrHosp = getAllHospedesTXT(numHospedes);

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

void deletarHospedeBIN(int cod) {

    FILE* hosp = fopen(".\\persist\\hospedes_temp.bin", "wb");
    if (hosp == NULL) {
        printf("ERRO");
    } else {
        int numHospedes=0;
        Hospede* arrHosp = getAllHospedesBIN(&numHospedes);
        printf("DEBUG: NUM HOSPEDES = %d\n",numHospedes);
        for (int i = 0; i < numHospedes; i++) {
            if (arrHosp[i].codigo != cod) {
                Hospede h = arrHosp[i];
                printf("NÃO VAI DELETAR: COD %d == %d\n",arrHosp[i].codigo,h.codigo);
                fwrite(&h, sizeof (Hospede), 1, hosp);

            }else{
                Hospede h2 = arrHosp[i];
                printf("É ESSE AQUI QUE VAI DELETAR: COD %d == %d\n",arrHosp[i].codigo,h2.codigo);
            }
            
        }

        fclose(hosp);
        free(arrHosp);
        remove(".\\persist\\hospedes.bin");
        rename(".\\persist\\hospedes_temp.bin", ".\\persist\\hospedes.bin");
    }
}