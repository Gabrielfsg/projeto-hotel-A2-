/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hotel.h"

int cadastrarHotelBin(Hotel *h, int quantidade) {//recebe a struct e a quantidade cadastrada
    FILE *arq;
    //abrea arquivo para escrita e posiciona cursor no final "ab"
    arq = fopen(".\\persist\\hotel.bin", "ab");
    if (arq == NULL) {
        //cria arquivo para escrita se não houver "wb"
        arq = fopen(".\\persist\\hotel.bin", "wb");
        if (arq == NULL) {
            printf("\nERRO ao acessar arquivo\n");
            return 0;
        }
    }
   
    /*grava toda struct 'hotel' no arquivo binário*/
    fwrite(&h, sizeof (Hotel), quantidade, arq);
    fflush(arq);
    /*fecha o arquivo*/
    fclose(arq);
    /*libera mémoria*/
    free(arq);
    return 1;
}

int cadastrarHotelTXT(Hotel h) {
    FILE *arq;
    //abrea arquivo para escrita e posiciona cursor no final "ab"
    arq = fopen(".\\persist\\hotelTXT", "a");
    if (arq == NULL) {
        //cria arquivo para escrita se não houver "wb"
        arq = fopen(".\\persist\\hotelTXT", "w");
        if (arq == NULL) {
            printf("\nERRO ao acessar arquivo\n");
            return 0;
        }
    }
    //grava todos os dados no arquivo de texto
    fprintf(arq, "%d\n%s\n%s\n%s\n%s\n%s\n%d\n%f\n%s\n%s\n%s\n%s\n%d\n%s\n%d\n%s\n%s\n%s\n"
            , h.codigo, h.cnpj, h.email, h.inscricaoEstadual, h.nomeFantazia
            , h.nomeResponsavel, h.telefone, h.margemLucro, h.checkIn
            , h.checkOut, h.teleRes, h.razaoSocial, h.numero
            , h.bairro, h.cep, h.logradouro, h.uf, h.cidade);

    fclose(arq);

    free(arq);
}

Hotel * listarHotelBIN(int *numLinha) {
    FILE *arquivo;
    //abrea arquivo para leitura apenas "rb"
    arquivo = fopen(".\\persist\\hotel.bin", "rb");
    if (arquivo == NULL) {
        //cria arquivo para leitura\escrita se não houver "w+b"
        arquivo = fopen(".\\persist\\hotel.bin", "w+b");
        if (arquivo == NULL) {
            printf("\nERRO ao acessar arquivo\n");
            return NULL;
        }
    }
    *numLinha = 0;

    Hotel h;
    //instancia vetor com tamanho 1 
    Hotel *hot = (Hotel*) calloc(1, sizeof (Hotel));
    //pega a primeira linha se existir
    int r = fread(&h, sizeof (Hotel), 1, arquivo);
    if (r > 0) {
        do {
            //soma a +1 no tamanho do vetor o qual comessa com 0
            *numLinha = (*numLinha) + 1;
            // realoca o vetor com o tamanho numLinha, a arqa interação ele realoca um a mais
            hot = realloc(hot, *numLinha * sizeof (Hotel));
            //adicionar o struct o vetor,(numLinha -1) pois o vetor comessa sempre por 0
            hot[(*numLinha) - 1] = h;
            //pega o proximo indice, se existir
            fread(&h, sizeof (Hotel), 1, arquivo);
            //verifica se chegou no fim do arquivo
        } while (!feof(arquivo));
    } else {
        return NULL;
    }
    //fecha arquivo
    fclose(arquivo);
    //libera memoria
    free(arquivo);
    return hot;
}

int salvarHotelTXT(Hotel *hot, int num) {
    // w pra substituir o arquivo
    FILE *cade = fopen(".\\persist\\hotelTXT", "wb");
    if (cade == NULL) {
        printf("\nErro ao abrir arquivo!!");
        return 0;
    } else {
        int i;
        // grava todos os dados do vetor no arquivo
        for (i = 0; i < num; i++) {
            fprintf(cade, "%d\n%s\n%s\n%s\n%s\n%s\n%d\n%f\n%s\n%s\n%s\n%s\n%d\n%s\n%d\n%s\n%s\n%s\n"
                    , hot[i].codigo, hot[i].cnpj, hot[i].email, hot[i].inscricaoEstadual, hot[i].nomeFantazia
                    , hot[i].nomeResponsavel, hot[i].telefone, hot[i].margemLucro, hot[i].checkIn
                    , hot[i].checkOut, hot[i].teleRes, hot[i].razaoSocial, hot[i].numero
                    , hot[i].bairro, hot[i].cep, hot[i].logradouro, hot[i].uf, hot[i].cidade); // f
        }
    }
    // força salvar arquivo
    fflush(cade);
    //fecha arquivo
    fclose(cade);
    //libera memoria
    free(cade);
    free(hot);
    return 1;
}

Hotel * listarHTXT() {
    int numOL = 0, i = 0;
    FILE* arq;
    numOL = contarLinhasHotelTXT(arq);// metodo para contar linhas arq txt
    arq = fopen(".\\persist\\hotelTXT", "r");
    if (arq == NULL) {//validações se o arquivo existe
        arq = fopen(".\\persist\\hotelTXT", "w+");
        if (arq == NULL) {
            printf("\nERRO ao acessar arquivo\n");
            return 0;
        }
    }
    char t[100];// vetor de string para armazenar dados
    Hotel *hot = (Hotel*) calloc(numOL, sizeof (Hotel));//vetor do tamanho do numero de linhas
    for (i = 0; i < numOL; i++) {//pega os dados armazenados no arquivo colocando no vetor
        fgets(t, 100, arq);// retira o \n 
        hot[i].codigo = atoi(t);
        fgets(hot[i].cnpj, 100, arq);
        strtok(hot[i].cnpj, "\r\n");

        fgets(hot[i].email, 100, arq);
        strtok(hot[i].email, "\r\n");

        fgets(hot[i].inscricaoEstadual, 100, arq);
        strtok(hot[i].inscricaoEstadual, "\r\n");

        fgets(hot[i].nomeFantazia, 100, arq);
        strtok(hot[i].nomeFantazia, "\r\n");

        fgets(hot[i].nomeResponsavel, 100, arq);
        strtok(hot[i].nomeResponsavel, "\r\n");
        hot[i].telefone = atoi(t);
        hot[i].margemLucro = atoi(t);
        fgets(hot[i].checkIn, 100, arq);
        strtok(hot[i].checkIn, "\r\n");
        
        fgets(hot[i].checkOut, 100, arq);
        strtok(hot[i].checkOut, "\r\n");

        fgets(hot[i].teleRes, 100, arq);
        strtok(hot[i].teleRes, "\r\n");

        fgets(hot[i].razaoSocial, 100, arq);
        strtok(hot[i].razaoSocial, "\r\n");
        hot[i].numero = atoi(t);
        fgets(t, 5, arq);
        fgets(hot[i].bairro, 100, arq);
        strtok(hot[i].bairro, "\r\n");
        hot[i].cep = atoi(t);
        fgets(hot[i].logradouro, 100, arq);
        strtok(hot[i].logradouro, "\r\n");

        fgets(hot[i].uf, 100, arq);
        strtok(hot[i].uf, "\r\n");

        fgets(hot[i].cidade, 100, arq);
        strtok(hot[i].cidade, "\r\n");
        fgetc(arq);
    }
    //fecha arquivo
    fclose(arq);
    //libera memoria
    free(arq);
    return hot;
}

int editarHotelBin(Hotel h, int posi) {
    FILE *arquivo;
    //abre arquivo para leitura e escrita, ele deve existir "r+b"
    arquivo = fopen(".\\persist\\hotel.bin", "r+b");
    if (arquivo == NULL) {
        printf("Erro ao acessar arquivo\n");
        return 0;
    }
    //Posiciona o cursor na posição do struct
    fseek(arquivo, (posi * sizeof (Hotel)), SEEK_SET);
    //Substitui o struct de posição posi
    fwrite(&h, sizeof (Hotel), 1, arquivo);
    //fecha arquivo 
    fclose(arquivo);
    //fclose(&aco);
    //libera memoria
    free(arquivo);
    return 1;
}

int editarHotelTXT(Hotel *hot, Hotel h, int num) {
    int i;
    for (i = 0; i < num; i++) {
        if ((int) (hot[i].codigo) == (int) (h.codigo)) {// faz a validação e sobrescreve os dados na struct
            strcpy(hot[i].cnpj, h.cnpj);
            strcpy(hot[i].email, h.email);
            strcpy(hot[i].inscricaoEstadual, h.inscricaoEstadual);
            strcpy(hot[i].nomeFantazia, h.nomeFantazia);
            strcpy(hot[i].nomeResponsavel, h.nomeResponsavel);
            hot[i].telefone = h.telefone;
            hot[i].margemLucro = h.margemLucro;
            strcpy(hot[i].checkIn, h.checkIn);
            strcpy(hot[i].checkOut, h.checkOut);
            strcpy(hot[i].teleRes, h.teleRes);
            strcpy(hot[i].razaoSocial, h.razaoSocial);
            hot[i].numero = h.numero;
            strcpy(hot[i].bairro, h.bairro);
            hot[i].cep = h.cep;
            strcpy(hot[i].logradouro, h.logradouro);
            strcpy(hot[i].uf, h.uf);
            strcpy(hot[i].cidade, h.cidade);
        }
    }

    return salvarHotelTXT(hot, num);//chama esse metodo para fazer o salvamento no arquivo
}

int removerHotelBIN() {// metodo que romove o arquivo das pastas
    int status = remove(".\\persist\\hotel.bin");
    if (status != 0) {
        printf("\nErro na remoção do arquivo.\n");
        return 0;
    }
    return 1;
}
