/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "Hospede.h"
#include "HospedeControl.h"
#include "Categoria.h"

void cadastrarHospedes() {
    printf("***** CADASTRAR HÓSPEDE *****\n");
    //pega os dados
    int cod;
    Hospede h;

    printf("Digite o cod do hóspede \n");
    scanf("%d%*c", &cod);
    //valida para ver se já existe

    if (validarCod(cod) == 0) {
        return;
    } else {
        h.codigo = cod;
    }

    printf("Digite o nome do hóspede \n");
    //scanf("%[^\n]s%*c", &h.nome); // [^\n] Para poder aceitar espaços, pois iremos ler o nome completo
    fgets(h.nome,101,stdin);
    strtok(h.nome, "\n");
            
    setbuf(stdin, NULL); // limpa o buffer
    printf("Digite o cpf do hóspede (apenas números) \n");
    fgets(h.cpf, 13, stdin); // tamanho 13 porque tem o \0 e o fgets adciona uma quebra de linha no final(?)
    //Usamos FGETS pois SCANF não consegue ler todos os caracteres de um cpf (11 caracteres)

    strtok(h.cpf, "\n"); // Esse comando serve para retirar o \n que o fgets coloca no final do cpf
    

    setbuf(stdin, NULL); // limpa o buffer

    printf("Digite o telefone do hóspede \n");
    //scanf("%s%*c", &h.telefone);
    fgets(h.telefone,15,stdin);
    strtok(h.telefone, "\n");
    printf("Digite o email do hóspede \n");
    //scanf("%s%*c", &h.email);
    fgets(h.email,101,stdin);
    strtok(h.email, "\n");
    printf("Digite o sexo do hóspede (M - masculino , F - Feminino) \n");
    scanf("%s%*c", &h.sexo);
    //fgets(h.sexo,2,stdin);

    printf("Digite o estado civil do hóspede \n");
    //scanf("%s%*c", &h.esCivil);
    fgets(h.esCivil,11,stdin);
    strtok(h.esCivil, "\n");
    //printf("Digite a data de nasc do hóspede \n");
    //scanf("%d%*c",&);

    //printf("Digite o endereço do hóspede \n");
    //scanf("%s%*c",&h.end);

    /*     //TESTE
            printf("\n NOME: %s \n", h.nome);
            printf("\n CPF: %s \n", h.cpf);
            printf("\n FONE: %s \n", h.telefone);
            printf("\n EMAIL: %s \n", h.email);
            printf("\n SEXO: %c \n", h.sexo);
            printf("\n ESCIVIL: %s \n", h.esCivil);
     */

    cadastrarHospedesTXT(h);
    /*    //salva no arquivo
    //METODO DO MODELO
    FILE *listaHospedes;
    listaHospedes = fopen(".\\persist\\hospedes.txt", "a");
    if (listaHospedes == NULL) {
        printf("ERRO DE ABERTURA\n");
    } else {
        fprintf(listaHospedes, "Cod: %d\r\nNome: %s\r\nCPF: %s\r\nTelefone: %s\r\nEmail: %s\r\nSexo: %c\r\nEstadoCivil: %s\r\n", h.codigo, h.nome, h.cpf, h.telefone, h.email, h.sexo, h.esCivil);
        printf("\nHOSPEDE CADASTRADO COM SUCESSO\n");

        fclose(listaHospedes);
    }

     */

}

void listarHospedes() {
    int numHospedes = getNumHospedes();
    printf("O NUM DE HOSPEDES É: %d\n", numHospedes);
    printf("LISTA DE TODOS OS HÓSPEDES \n");
    Hospede* arrayHospedes = getAllHospedes(numHospedes);

    for (int i = 0; i < numHospedes; i++) {
        //lista os hóspedes
        printf("***************\n");
        printf("COD: %d\n", arrayHospedes[i].codigo);
        //printf("ENDER: 123\n");
        printf("NOME: %s\n", arrayHospedes[i].nome);
        printf("CPF: %s\n", arrayHospedes[i].cpf);
        printf("FONE: %s\n", arrayHospedes[i].telefone);
        printf("EMAIL: %s\n", arrayHospedes[i].email);
        printf("SEXO: %c\n", arrayHospedes[i].sexo);
        printf("ESTADO CIVIL: %s\n", arrayHospedes[i].esCivil);
        //printf("DATA NASC: 123\n");
        printf("***************\n");
    }
    printf("\n FIM DA LISTA DE HÓSPEDES \n");

    free(arrayHospedes);
}

Hospede* getAllHospedesControl() {
    int numHospedes = getNumHospedes();
    //Hospede* arrayHospedes = getAllHospedes(numHospedes);
    return getAllHospedes(numHospedes);
}

Hospede getHospedeByCodControl() {
    Hospede hos;
    int cod;
    int numHospedes = getNumHospedes();

    printf("Digite o código do Hóspede que deseja procurar:\n");
    scanf("%d%*c", &cod);
    int validacao = validarCod(cod);
    setbuf(stdin, NULL);
    //printf("VALIDAÇÃO: %d \n",validacao);
    if (validacao == 0) {
        printf("INFORMAÇÕES DO HÓSPEDE: \n");
        hos = getHospedeByCod(cod, numHospedes);
        printf("COD: %d\n", hos.codigo);
        printf("NOME: %s\n", hos.nome);
        printf("CPF: %s\n", hos.cpf);
        printf("EMAIL: %s\n", hos.email);
        printf("SEXO: %c\n", hos.sexo);
        printf("ESCIVIL: %s\n", hos.esCivil);
        printf("TELEFONE: %s\n", hos.telefone);
        return hos;
    } else {
        printf("CÓDIGO NÃO EXISTE\n");
    }
}

void atualizarHospedes() {
    printf("***** ALTERAR DADOS DO HÓSPEDE *****\n");

    printf("Digite o cod do hóspede \n");
    //scanf("%d%*c",&);
}

void deletarHospedesControl() {
    printf("***** DELETAR HÓSPEDE *****\n");
    int cod;
    char confirmacao;
    int numHospedes = getNumHospedes();
    printf("NUMERO DE HOSP É::: %d\n",numHospedes);
    printf("Digite o cod do hóspede \n");
    scanf("%d%*c", &cod);
    int validacao = validarCod(cod);
    if (validacao == 0) {
        //printf("entrou deletarControl\n");
        //setbuf(stdout, NULL);
        //fflush(stdout);
        ////////Hospede h = getHospedeByCod(cod, numHospedes);
        FILE* hosp = fopen(".\\persist\\hospedes_temp.txt", "w");
        if (hosp == NULL) {
            printf("ERRO");
        } else {
            Hospede* arrHosp = getAllHospedes(numHospedes);
            /*printf("DDDDDDDDEEEEELLLLLLLEEEEEETTTTTAAAAAARRRRRR\n");
            printf("COD: %d NOME: %s\n",arrHosp[0].codigo,arrHosp[0].nome);
            printf("COD: %d NOME: %s\n",arrHosp[1].codigo,arrHosp[1].nome);
            printf("COD: %d NOME: %s\n",arrHosp[2].codigo,arrHosp[2].nome);*/
            for (int i = 0; i < numHospedes; i++) {
                if(arrHosp[i].codigo != cod){
                    //fprintf(hosp, "Cod: %d\r\nNome: %s\r\nCPF: %s\r\nTelefone: %s\r\nEmail: %s\r\nSexo: %c\r\nEstadoCivil: %s\r\n", arrHosp[i].codigo, arrHosp[i].nome, arrHosp[i].cpf, arrHosp[i].telefone, arrHosp[i].email, arrHosp[i].sexo, arrHosp[i].esCivil);
                    strtok(arrHosp[i].nome, "\r");
                    fprintf(hosp, "Cod: %d\r\nNome: %s\r\nCPF: %s\r\nTelefone: %s\r\nEmail: %s\r\nSexo: %c\r\nEstadoCivil: %s\r\n", arrHosp[i].codigo, arrHosp[i].nome, arrHosp[i].cpf, arrHosp[i].telefone, arrHosp[i].email, arrHosp[i].sexo, arrHosp[i].esCivil);
                    //fprintf(hosp, "\r\n");
                    fflush(hosp);
                    printf("HOSPEDE CADASTRADO COM SUCESSO\n");
                }
            }
            fclose(hosp);
            free(arrHosp);
            remove(".\\persist\\hospedess.txt");
            rename(".\\persist\\hospedes_temp.txt",".\\persist\\hospedess.txt");
            printf("TERMINOU\n");
            //exit(1);
        }




        //setbuf(stdout, NULL);
        //setlinebuf(stdout);
        /*printf("+++++++++++++++++++++ \n");
        printf("COD: %d\n", h.codigo);
        printf("NOME: %s\n", h.nome);
        printf("CPF: %s\n", h.cpf);
        printf("EMAIL: %s\n", h.email);
        printf("SEXO: %c\n", h.sexo);
        printf("ESCIVIL: %s\n", h.esCivil);
        printf("TELEFONE: %s\n", h.telefone);
        printf("+++++++++++++++++++++ \n");*/
        printf("DESEJA DELETAR O HÓSPEDE ACIMA? (S/N)\n");

        scanf("%c%*c", &confirmacao);
        if (confirmacao == 'S' || confirmacao == 's') {

        } else {
            printf("OPERAÇÃO CANCELADA\n");
            return;
        }
        //setbuf(stdout, NULL);
        //fflush(stdout);

    } else {
        printf("CÓDIGO NÃO EXISTE\n");
    }

}

int validarCod(int cod) { //1-> NÃO EXISTE 0 -> JÁ EXISTE
    //printf("ENTROU VALIDAÇÃO\n");
    int codExistente = 1;
    Hospede* arrHospedes = getAllHospedesControl();
    int numHospedes = getNumHospedes();

    for (int i = 0; i < numHospedes; i++) {
        if (cod == arrHospedes[i].codigo) {
            codExistente = 0;
        }
    }
    free(arrHospedes);
    if (codExistente == 0) {
        printf("CÓDIGO EXISTENTE\n");
        return 0;
    } else {
        return 1;
    }
}

int getNumHospedes() {
    FILE *arq;
    int numLinhas = 0, numHospedes = 0;
    char c;
    arq = fopen(".\\persist\\hospedess.txt", "r");
    if (arq == NULL) {
        printf("Erro ao acessar arquivo\n");
    }
    while ((c = fgetc(arq)) != EOF) {

        if (c == '\n') {
            numLinhas++;
        }
    }
    numHospedes = numLinhas / 7; //9;

    printf("O NÚMERO DE LINHAS DO ARQ É: %d\n", numLinhas);
    printf("O NÚMERO DE HOSPEDES CADASTRADOS É: %d\n", numHospedes);
    fclose(arq);
    free(arq);
    return numHospedes;

}