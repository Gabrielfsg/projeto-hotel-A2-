/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hotel.h"

int cadastrarHotelBin(Hotel h, int quantidade) {
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
    //strlen()-> informa o tamanho de uma string 
    /*grava toda struct de acomodacao no arquivo*/
    fwrite(&h, sizeof (Hotel), quantidade, arq);
    fflush(arq);
    /*fecha o arquivo*/
    fclose(arq);
    /*libera mémoria*/
    free(arq);
    return 1;
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
    FILE *cade = fopen(".\\persist\\hotelTXT.txt", "wb");
    if (cade == NULL) {
        printf("\nErro ao abrir arquivo!!");
        return 0;
    } else {
        int i;
        // grava todos os dados do vetor no arquivo
        for (i = 0; i < num; i++) {
            fprintf(cade, "%d\n%s\n%s\n%s\n%s\n%s\n%d\n%f\n%s\n%s\n%s\n%s\n%d\n%s\n%d\n%s\n%s\n%s\n"
                    , hot[i].codigo,hot[i].cnpj,hot[i].email,hot[i].inscricaoEstadual,hot[i].nomeFantazia
                    ,hot[i].nomeResponsavel,hot[i].telefone,hot[i].margemLucro,hot[i].checkIn
                    ,hot[i].checkOut,hot[i].teleRes,hot[i].razaoSocial,hot[i].numero
                    ,hot[i].bairro,hot[i].cep,hot[i].logradouro,hot[i].uf,hot[i].cidade); // f
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



int removerHotelBIN() {
    int status = remove(".\\persist\\hotel.bin");
    if (status != 0) {
        printf("\nErro na remoção do arquivo.\n");
        return 0;
    }
    return 1;
}