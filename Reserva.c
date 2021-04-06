/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Data.h"
#include "Reserva.h"
#include "Hospede.h"
#include "SalvametoBD.h"
#include "SalvametoBD.h"
#include <stdio.h>
#include <stdlib.h>
#include <String.h>

int cadastrarReservaBIN(Reserva *aco, int quantidade) {
    FILE *cad;
    cad = fopen("arquivos\\ReservaBIN.bin", "ab");
    if (cad == NULL) {
        cad = fopen("arquivos\\ReservaBIN.bin", "wb");
        return 0;
    } else {
        //strlen()-> informa o tamanho de uma string 
        /*grava toda struct de categoria no arquivo*/
        fwrite(aco, sizeof (Reserva), quantidade, cad);
        fflush(cad);
        /*fecha o arquivo*/
        fclose(cad);
        /*libera mémoria*/
        free(cad);
    }
    return 1;
}

int cadastrarReservaTXT(Reserva aco) {
    FILE *arq;
    aco.status = 0;
    // abre o arquivo com o cursor no final
    arq = fopen("arquivos\\ReservaTXT.txt", "a");
    if (arq == NULL) {

        // se ele não existir cria um
        arq = fopen("arquivos\\ReservaTXT.txt", "w");
        if (arq == NULL) {
            printf("\nErro ao acessar arquivo\n");
            return 0;
        }
    }
    // salva arqa campo em uma linha
    fprintf(arq, "%d\r\n%d\r\n%d\r\n%d\r\n%d\r\n%d\r\n%d\r\n%d\r\n%d\n%s\n%d\n%s\n%d\r\n%s\r\n%s\r\n%s\r\n%s\r\n%c\r\n%s\r\n%d\r\n%d\r\n%d\r\n%d\r\n%s\r\n%s\r\n%s\r\n%s\r\n%d\r\n%s\r\n", aco.codigo, aco.status, aco.DataIn.dia, aco.DataIn.mes, aco.DataIn.ano, aco.DataFin.dia, aco.DataFin.mes, aco.DataFin.ano, aco.acomodacao.codigo, aco.acomodacao.descricao, aco.acomodacao.categoria.codigo, aco.acomodacao.status, aco.hospede.codigo, aco.hospede.nome, aco.hospede.cpf, aco.hospede.telefone, aco.hospede.email, aco.hospede.sexo, aco.hospede.esCivil, aco.hospede.dataNascimento.dia, aco.hospede.dataNascimento.mes, aco.hospede.dataNascimento.ano, aco.hospede.endereco.codigo, aco.hospede.endereco.bairro, aco.hospede.endereco.cep, aco.hospede.endereco.cidade, aco.hospede.endereco.logradouro, aco.hospede.endereco.numero, aco.hospede.endereco.uf); // f
    //fecha o arquivo
    fclose(arq);
    //libera memoria
    free(arq);
    //printf("DEBUG: ENTROU AQUI\n");
    return 1;
}
//metodo salva, sobrescrevendo o array de tamanho num

int salvarReservaTXT(Reserva *aco, int num) {
    FILE *arq;
    // w pra substituir o arquivo
    arq = fopen("arquivos\\ReservaTXT.txt", "w");
    if (arq == NULL) {
        printf("\nErro ao abrir arquivo!!");
        return 0;
    } else {
        int i;
        // grava todos os dados do vetor no arquivo
        for (i = 0; i < num; i++) {
            fprintf(arq, "%d\r\n%d\r\n%d\r\n%d\r\n%d\r\n%d\r\n%d\r\n%d\r\n%d\n%s\n%d\n%s\n%d\r\n%s\r\n%s\r\n%s\r\n%s\r\n%c\r\n%s\r\n%d\r\n%d\r\n%d\r\n%d\r\n%s\r\n%s\r\n%s\r\n%s\r\n%d\r\n%s\r\n", aco[i].codigo, aco[i].status, aco[i].DataIn.dia, aco[i].DataIn.mes, aco[i].DataIn.ano, aco[i].DataFin.dia, aco[i].DataFin.mes, aco[i].DataFin.ano, aco[i].acomodacao.codigo, aco[i].acomodacao.descricao, aco[i].acomodacao.categoria.codigo, aco[i].acomodacao.status, aco[i].hospede.codigo, aco[i].hospede.nome, aco[i].hospede.cpf, aco[i].hospede.telefone, aco[i].hospede.email, aco[i].hospede.sexo, aco[i].hospede.esCivil, aco[i].hospede.dataNascimento.dia, aco[i].hospede.dataNascimento.mes, aco[i].hospede.dataNascimento.ano, aco[i].hospede.endereco.codigo, aco[i].hospede.endereco.bairro, aco[i].hospede.endereco.cep, aco[i].hospede.endereco.cidade, aco[i].hospede.endereco.logradouro, aco[i].hospede.endereco.numero, aco[i].hospede.endereco.uf); // f
        }
    }
    // força salvar arquivo
    fflush(arq);
    //fecha arquivo
    fclose(arq);
    //libera memoria
    free(arq);
    //free(aco);
    return 1;
}

Reserva * listarReservaTXT() {
    int numLinha = 0, i = 0, c;
    FILE *arquivo;
    numLinha = numReserva();
    //area arquivo para leitura apenas "r"
    arquivo = fopen("arquivos\\ReservaTXT.txt", "r");
    if (arquivo == NULL) {
        arquivo = fopen("arquivos\\ReservaTXT.txt", "w+");
        if (arquivo == NULL) {
            printf("Erro ao acessar arquivo\n");
            return NULL;
        }
    }
    //instancia vetor com tamanho de numLinha
    Reserva *aco = (Reserva*) calloc(numLinha, sizeof (Reserva));
    i = 0;
    char t[100];
    //printf("linhas %d \n", numLinha);

    for (i = 0; i < numLinha; i++) {
        fgets(t, 100, arquivo);
        aco[i].codigo = atoi(t);
        fgets(t, 100, arquivo);
        aco[i].status = atoi(t);
        //printf("%d,",aco[i].codigo);
        fgets(t, 100, arquivo);

        aco[i].DataIn.dia = atoi(t);
        fgets(t, 100, arquivo);
        aco[i].DataIn.mes = atoi(t);
        fgets(t, 100, arquivo);
        aco[i].DataIn.ano = atoi(t);
        fgets(t, 100, arquivo);
        aco[i].DataFin.dia = atoi(t);
        fgets(t, 100, arquivo);
        aco[i].DataFin.mes = atoi(t);
        fgets(t, 100, arquivo);
        aco[i].DataFin.ano = atoi(t);
        fgets(t, 100, arquivo);
        aco[i].acomodacao.codigo = atoi(t);
        fgets(aco[i].acomodacao.descricao, 100, arquivo);
        strtok(aco[i].acomodacao.descricao, "\r\n");

        fgets(t, 100, arquivo);
        aco[i].acomodacao.categoria.codigo = atoi(t);
        //printf("%s", aco[i].nomeFantazia);
        fgets(aco[i].acomodacao.status, 100, arquivo);
        strtok(aco[i].acomodacao.status, "\r\n");

        // printf("%s", aco[i].razaoSocial);
        fgets(t, 100, arquivo);
        aco[i].hospede.codigo = atoi(t);
        fgets(aco[i].hospede.nome, 100, arquivo);
        strtok(aco[i].hospede.nome, "\r\n");
        //printf("%s", aco[i].inscricaoEstadual);
        fgets(aco[i].hospede.cpf, 100, arquivo);
        strtok(aco[i].hospede.cpf, "\r\n");
        // printf("%s", aco[i].cnpj);
        fgets(aco[i].hospede.telefone, 100, arquivo);
        strtok(aco[i].hospede.telefone, "\r\n");

        //printf("%s", aco[i].telefone);
        fgets(aco[i].hospede.email, 100, arquivo);
        strtok(aco[i].hospede.email, "\r\n");
        aco[i].hospede.sexo = fgetc(arquivo);
        fgetc(arquivo);
        fgetc(arquivo);

        //fgets(aco[i].hospede.sexo, 2, arquivo);
        //strtok(aco[i].hospede.sexo, "\r\n");
        fgets(aco[i].hospede.esCivil, 100, arquivo);
        strtok(aco[i].hospede.esCivil, "\r\n");
        //printf("%s", aco[i].email);
        fgets(t, 100, arquivo);
        aco[i].hospede.dataNascimento.dia = atoi(t);
        fgets(t, 100, arquivo);
        aco[i].hospede.dataNascimento.mes = atoi(t);
        fgets(t, 100, arquivo);
        aco[i].hospede.dataNascimento.ano = atoi(t);
        fgets(t, 100, arquivo);
        aco[i].hospede.endereco.codigo = atoi(t);
        fgets(aco[i].hospede.endereco.bairro, 100, arquivo);
        strtok(aco[i].hospede.endereco.bairro, "\r\n");
        //printf("%s", aco[i].endereco.logradouro);
        //
        fgets(aco[i].hospede.endereco.cep, 100, arquivo);
        strtok(aco[i].hospede.endereco.cep, "\r\n");
        //printf("%s", aco[i].endereco.bairro);
        fgets(aco[i].hospede.endereco.cidade, 100, arquivo);
        strtok(aco[i].hospede.endereco.cidade, "\r\n");
        // printf("%s", aco[i].endereco.cidade);
        fgets(aco[i].hospede.endereco.logradouro, 100, arquivo);
        strtok(aco[i].hospede.endereco.logradouro, "\r\n");
        //printf("%s", aco[i].endereco.cep);
        fgets(t, 5, arquivo);
        fgets(aco[i].hospede.endereco.uf, 4, arquivo);
        strtok(aco[i].hospede.endereco.uf, "\r\n");
        //printf("%s", aco[i].endereco.uf);
        aco[i].hospede.endereco.numero = atoi(t);
        fgetc(arquivo);
    }
    //fecha arquivo
    fclose(arquivo);
    //libera memoria
    free(arquivo);
    return aco;
}

int numReserva() {

    FILE *arquivo;
    int numLinha = 0, c;
    //abre arquivo para leitura "r"
    arquivo = fopen("arquivos\\ReservaTXT.txt", "r");
    if (arquivo == NULL) {
        arquivo = fopen("arquivos\\CategoriaTXT.txt", "w+");
        if (arquivo == NULL) {
            printf("\nErro ao acessar arquivo\n");
            return 0;
        }
    }
    //roda ate que ache o final do arquivo "EOF"
    while ((c = fgetc(arquivo)) != EOF) {
        if (c == '\n') {
            numLinha++;
        }
    }
    //fecha arquivo
    fclose(arquivo);
    //libera memoria
    free(arquivo);
    return (numLinha / 29);
}

int validarReserva(int cod) {
    // printf("ENTROU VALIDACAO\n");
    Reserva *aco = listarReservaTXT();
    //printf("COD = %d\n",cod);
    int achou = 0;
    if (aco != NULL) {
        //int lin = sizeof (*aco) / sizeof (Reserva);
        int lin = numReserva();
        //printf("LIN = %d\n",lin);
        int i;
        for (i = 0; i <= lin; i++) {
            if (cod == aco[i].codigo) {
                achou = 1;
            }
        }
        free(aco);

    }
    return achou;
}

/*Aruivos binarios*/

/*
int cadastrarReservaBIN(Reserva *aco, int quantidade) {
    FILE *arq;
    //abrea arquivo para escrita e posiciona cursor no final "ab"
    arq = fopen("arquivos\\ReservaBIN.bin", "ab");
    if (arq == NULL) {
        //cria arquivo para escrita se não houver "wb"
        arq = fopen("arquivos\\ReservaBIN.bin", "wb");
        if (arq == NULL) {
            printf("\nERRO ao acessar arquivo\n");
            return 0;
        }
    }
    //strlen()-> informa o tamanho de uma string 
    //grava toda struct de Reserva no arquivo
    fwrite(aco, sizeof (Reserva), quantidade, arq);
    fflush(arq);
    //fecha o arquivo
    fclose(arq);
    //libera mémoria
    free(arq);
    return 1;
}
 */
Reserva * listarReservaBIN(int *numLinha) {
    FILE *arquivo;
    //abrea arquivo para leitura apenas "rb"
    arquivo = fopen("arquivos\\ReservaBIN.bin", "rb");
    if (arquivo == NULL) {
        //cria arquivo para leitura\escrita se não houver "w+b"
        arquivo = fopen("arquivos\\ReservaBIN.bin", "w+b");
        if (arquivo == NULL) {
            printf("\nERRO ao acessar arquivo\n");
            return NULL;
        }
    }
    *numLinha = 0;

    Reserva c;
    //instancia vetor com tamanho 1 
    Reserva *aco = (Reserva*) calloc(1, sizeof (Reserva));
    //pega a primeira linha se existir
    int r = fread(&c, sizeof (Reserva), 1, arquivo);
    if (r > 0) {
        do {
            //soma a +1 no tamanho do vetor o qual comessa com 0
            *numLinha = (*numLinha) + 1;
            // realoca o vetor com o tamanho numLinha, a arqa interação ele realoca um a mais
            aco = realloc(aco, *numLinha * sizeof (Reserva));
            //adicionar o struct o vetor,(numLinha -1) pois o vetor comessa sempre por 0
            aco[(*numLinha) - 1] = c;
            //pega o proximo indice, se existir
            fread(&c, sizeof (Reserva), 1, arquivo);
            //verifica se chegou no fim do arquivo
        } while (!feof(arquivo));
    } else {
        return NULL;
    }
    //fecha arquivo
    fclose(arquivo);
    //libera memoria
    free(arquivo);

    return aco;
}

int editarReservaBIN(Reserva aco, int posi) {
    FILE *arquivo;
    //abre arquivo para leitura e escrita, ele deve existir "r+b"
    arquivo = fopen("arquivos\\ReservaBIN.bin", "r+b");
    if (arquivo == NULL) {
        printf("Erro ao acessar arquivo\n");
        return 0;
    }
    //Posiciona o cursor na posição do struct
    printf("posi %d \n", posi);
    fseek(arquivo, (posi * sizeof (Reserva)), SEEK_SET);
    //Substitui o struct de posição posi
    fwrite(&aco, sizeof (Reserva), 1, arquivo);
    //fecha arquivo 
    fclose(arquivo);
    //fclose(&aco);
    //libera memoria
    free(arquivo);
    return 1;
}

int validarReservaBIN(int cod) {
    int num;
    Reserva *aco = listarReservaBIN(&num);
    int i;
    for (i = 0; i < num; i++) {
        if (cod == aco[i].codigo) {
            // retorna o indice se achar
            //return i;
            return 1;
        }
    }
    free(aco);
    return 0;
}

/*int removerReservaBIN() {
    int status = remove("arquivos\\ReservaBIN.bin");
    if (status != 0) {
        printf("\nErro na remoção do arquivo.\n");
        return 0;
    }
    return 1;
}*/

//Tales

int removerReservaBIN(int cod) {
    int retorno = 0;
    FILE* arqReserva = fopen(".\\arquivos\\reserva_temp.bin", "wb");
    if (arqReserva == NULL) {
        printf("ERRO AO ABRIR ARQUIVO");
    } else {
        int numReservas = 0;
        Reserva* arrayReservas = listarReservaBIN(&numReservas);

        for (int i = 0; i < numReservas; i++) {
            if (arrayReservas[i].codigo != cod) {
                Reserva r = arrayReservas[i];

                fwrite(&r, sizeof (Reserva), 1, arqReserva);

            } else {
                //Reserva r2 = arrayReservas[i];
                //printf("É ESSE AQUI QUE VAI DELETAR: COD %d == %d\n", arrayReservas[i].codigo, r2.codigo);
            }

        }

        fclose(arqReserva);
        free(arrayReservas);
        remove(".\\arquivos\\ReservaBIN.bin");
        rename(".\\arquivos\\reserva_temp.bin", ".\\arquivos\\ReservaBIN.bin");
    }

    return retorno;
}

int removerReservaTXT(int cod) {
    int retorno = 0;
    FILE* arqReserva = fopen(".\\arquivos\\reserva_temp.txt", "w");
    if (arqReserva == NULL) {
        printf("ERRO AO ABRIR ARQUIVO");
        return 0;
    } else {
        Reserva* arrayReservas = listarReservaTXT();
        int numRes = numReserva();

        for (int i = 0; i < numRes; i++) {
            if (arrayReservas[i].codigo != cod) {
                fprintf(arqReserva, "%d\r\n%d\r\n%d\r\n%d\r\n%d\r\n%d\r\n%d\r\n%d\n%s\n%d\n%s\n%d\r\n%s\r\n%s\r\n%s\r\n%s\r\n%c\r\n%s\r\n%d\r\n%d\r\n%d\r\n%d\r\n%s\r\n%s\r\n%s\r\n%s\r\n%d\r\n%s\r\n", arrayReservas[i].codigo, arrayReservas[i].DataIn.dia, arrayReservas[i].DataIn.mes, arrayReservas[i].DataIn.ano, arrayReservas[i].DataFin.dia, arrayReservas[i].DataFin.mes, arrayReservas[i].DataFin.ano, arrayReservas[i].acomodacao.codigo, arrayReservas[i].acomodacao.descricao, arrayReservas[i].acomodacao.categoria.codigo, arrayReservas[i].acomodacao.status, arrayReservas[i].hospede.codigo, arrayReservas[i].hospede.nome, arrayReservas[i].hospede.cpf, arrayReservas[i].hospede.telefone, arrayReservas[i].hospede.email, arrayReservas[i].hospede.sexo, arrayReservas[i].hospede.esCivil, arrayReservas[i].hospede.dataNascimento.dia, arrayReservas[i].hospede.dataNascimento.mes, arrayReservas[i].hospede.dataNascimento.ano, arrayReservas[i].hospede.endereco.codigo, arrayReservas[i].hospede.endereco.bairro, arrayReservas[i].hospede.endereco.cep, arrayReservas[i].hospede.endereco.cidade, arrayReservas[i].hospede.endereco.logradouro, arrayReservas[i].hospede.endereco.numero, arrayReservas[i].hospede.endereco.uf); // f
                fflush(arqReserva);
            }
        }
        fclose(arqReserva);
        free(arrayReservas);
        remove(".\\arquivos\\ReservaTXT.txt");
        rename(".\\arquivos\\reserva_temp.txt", ".\\arquivos\\ReservaTXT.txt");
        return retorno;
    }
}

int maiorCodReservaTXT() {
    int num = numReserva();
    Reserva * res = listarReservaTXT();
    int i, aux = 0;
    for (i = 0; i < num; i++) {
        if (res[i].codigo > aux) {
            aux = res[i].codigo;
        }
    }
    return aux;
}

int maiorCodReservaBIN() {
    int num;
    Reserva * res = listarReservaBIN(&num);
    int i, aux = 0;
    for (i = 0; i < num; i++) {
        if (res[i].codigo > aux) {
            aux = res[i].codigo;
        }
    }
    return aux;
}

Reserva* listarReservasHoje(int *numAtual) {
    Reserva *res, *aux;
    Data data = getDataHoje();
    aux = (Reserva*) calloc(1, sizeof (Reserva));
    int num;
    *numAtual = 0;
    int bd = listar();
    if (bd == 1) {
        res = listarReservaTXT();
        num = numReserva();
    } else {
        res = listarReservaBIN(&num);
    }
    int i;
    for (i = 0; i < num; i++) {
        if (compararDatas(res[i].DataIn, data) == 1 && res[i].status == 0) {
            (*numAtual)++;
            aux = realloc(aux, *numAtual * sizeof (Reserva));
            if (aux != NULL) {
                aux[(*numAtual) - 1] = res[i];
            } else {
                printf("ERRO: realoc memoria\n");
            }
        }
    }
    //libera memoria
    free(res);
    return aux;
}

Reserva* listarReservasPendentes(int *numAtual) {
    Reserva *res, *aux;
    aux = (Reserva*) calloc(1, sizeof (Reserva));
    int num;
    *numAtual = 0;
    int bd = listar();
    if (bd == 1) {
        res = listarReservaTXT();
        num = numReserva();
    } else {
        res = listarReservaBIN(&num);
    }
    int i;
    for (i = 0; i < num; i++) {
        if (res[i].status == 0) {
            (*numAtual)++;
            aux = realloc(aux, *numAtual * sizeof (Reserva));
            if (aux != NULL) {
                aux[(*numAtual) - 1] = res[i];
            } else {
                printf("ERRO: realoc memoria\n");
            }
        }
    }

    //libera memoria
    free(res);
    return aux;
}

Reserva* listarReservasOcupadas(int *numAtual) {
    Reserva *res, *aux;
    aux = (Reserva*) calloc(1, sizeof (Reserva));
    int num;
    *numAtual = 0;
    int bd = listar();
    if (bd == 1) {
        res = listarReservaTXT();
        num = numReserva();
    } else {
        res = listarReservaBIN(&num);
    }
    int i;
    for (i = 0; i < num; i++) {
        if (res[i].status == 1) {
            (*numAtual)++;
            aux = realloc(aux, *numAtual * sizeof (Reserva));
            if (aux != NULL) {
                aux[(*numAtual) - 1] = res[i];
            } else {
                printf("ERRO: realoc memoria\n");
            }
        }
    }
    for (i = 0; i < *numAtual; i++) {
        printf("cod : %d\n", aux[i].codigo);
        printf("Nome : %s\n", aux[i].hospede.nome);
    }
    //libera memoria
    free(res);
    return aux;
}
