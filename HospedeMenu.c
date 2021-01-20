/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
//#include "HospedeControl.h"
#include "Principal.h"
#include "Hospede.h"
#include "HospedeMenu.h"

void menuCRUDHospedes() {
    int sair = 0;
    int opc;
    while (sair == 0) {
        printf("******* GESTÃO DE DADOS - HÓSPEDES **********\n");
        printf("Opções: \n");
        printf("1.Cadastrar Hospede. \n");
        printf("2.Alterar Dados do Hospede. \n");
        printf("3.Visualizar Todos os Hospedes. \n");
        printf("4.Visualizar Hospede por código. \n");
        printf("5.Excluir Hospede. \n");
        printf("6.Voltar. \n");
        printf("Digite a opção desejada: \n");
        scanf("%d%*c", &opc);
        switch (opc) {
            case 1:
                cadastrarHospedesControl();
                break;
            case 2:
                atualizarHospedesControl();
                break;
            case 3:
                listarHospedesControl();
                break;
            case 4:;
                getHospedeByCodControl();
                break;
            case 5:
                deletarHospedesControl();
                break;
            case 6:
                sair = 1;
                subCadastros();
                break;
            default:
                printf("OPÇÃO INVÁLIDA!\n");

                break;
        }

    }
}

void cadastrarHospedesControl() {
    printf("***** CADASTRAR HÓSPEDE *****\n");
    int cod;
    Hospede h;

    //pega os dados
    printf("Digite o cod do hóspede \n");
    scanf("%d%*c", &cod);
    //valida para ver se já existe
    if (validarCod(cod) == 0) {
        return;
    } else {
        h.codigo = cod;
    }

    printf("Digite o nome do hóspede \n");
    //scanf("%[^\n]s%*c", &h.nome); 
    fgets(h.nome, 101, stdin);
    strtok(h.nome, "\n"); // Esse comando serve para retirar o \n que o fgets coloca no final da string lida

    printf("Digite o cpf do hóspede (apenas números) \n");
    fgets(h.cpf, 13, stdin); // tamanho 13 porque tem o \0 e o fgets adciona uma quebra de linha no final(?)
    strtok(h.cpf, "\n");

    //setbuf(stdin, NULL); // limpa o buffer

    printf("Digite o telefone do hóspede \n");
    fgets(h.telefone, 15, stdin);
    strtok(h.telefone, "\n");

    printf("Digite o email do hóspede \n");
    //scanf("%s%*c", &h.email);
    fgets(h.email, 101, stdin);
    strtok(h.email, "\n");
    printf("Digite o sexo do hóspede (M - masculino , F - Feminino) \n");
    scanf("%s%*c", &h.sexo);

    printf("Digite o estado civil do hóspede \n");
    //scanf("%s%*c", &h.esCivil);
    fgets(h.esCivil, 11, stdin);
    strtok(h.esCivil, "\n");
    //printf("Digite a data de nasc do hóspede \n");
    //scanf("%d%*c",&);

    //printf("Digite o endereço do hóspede \n");
    //scanf("%s%*c",&h.end);

    cadastrarHospedesTXT(h);
}

void listarHospedesControl() {
    int numHospedes = getNumHospedes();
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

    if (validacao == 0) {
        printf("INFORMAÇÕES DO HÓSPEDE: \n");
        hos = getHospedeByCod(cod, numHospedes);
        printf("***************\n");
        printf("COD: %d\n", hos.codigo);
        printf("NOME: %s\n", hos.nome);
        printf("CPF: %s\n", hos.cpf);
        printf("EMAIL: %s\n", hos.email);
        printf("SEXO: %c\n", hos.sexo);
        printf("ESCIVIL: %s\n", hos.esCivil);
        printf("TELEFONE: %s\n", hos.telefone);
        printf("***************\n");
        return hos;
    } else {
        printf("CÓDIGO NÃO EXISTE\n");
    }
}

void atualizarHospedesControl() {
    printf("***** ALTERAR DADOS DO HÓSPEDE *****\n");

    printf("Digite o cod do hóspede \n");
    //scanf("%d%*c",&);
}

void deletarHospedesControl() {
    printf("***** DELETAR HÓSPEDE *****\n");
    int cod;
    char confirmacao;

    printf("Digite o cod do hóspede \n");
    scanf("%d%*c", &cod);
    int validacao = validarCod(cod);
    if (validacao == 0) {
        int numHospedes = getNumHospedes();
        Hospede hos = getHospedeByCod(cod,numHospedes);
        
        printf("***************\n");
        printf("COD: %d\n", hos.codigo);
        printf("NOME: %s\n", hos.nome);
        printf("CPF: %s\n", hos.cpf);
        printf("EMAIL: %s\n", hos.email);
        printf("SEXO: %c\n", hos.sexo);
        printf("ESCIVIL: %s\n", hos.esCivil);
        printf("TELEFONE: %s\n", hos.telefone);
        printf("***************\n");
        
        printf("DESEJA RELEMTE DELETAR O HÓSPEDE? (S/N)\n");
        scanf("%c%*c", &confirmacao);
        if (confirmacao == 'S' || confirmacao == 's') {
            deletarHospede(cod);
        } else {
            printf("OPERAÇÃO CANCELADA\n");
            return;
        }

        printf("HOSPEDE DELETADO COM SUCESSO\n");
        //exit(1);


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


    } else {
        printf("CÓDIGO NÃO EXISTE\n");
    }

}

int validarCod(int cod) { //1-> NÃO EXISTE 0 -> JÁ EXISTE
    //printf("ENTROU VALIDAÇÃO\n");
    int codExistente = 1;
    Hospede* arrHospedes = getAllHospedesControl();
    int numHospedes = getNumHospedes();
    int i;
    for (i = 0; i < numHospedes; i++) {
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
    arq = fopen(".\\persist\\hospedes.txt", "r");
    if (arq == NULL) {
        printf("Erro ao acessar arquivo\n");
    }
    while ((c = fgetc(arq)) != EOF) {

        if (c == '\n') {
            numLinhas++;
        }
    }
    numHospedes = numLinhas / 7; //9;

    //printf("O NÚMERO DE LINHAS DO ARQ É: %d\n", numLinhas);
    //printf("O NÚMERO DE HOSPEDES CADASTRADOS É: %d\n", numHospedes);
    fclose(arq);
    free(arq);
    return numHospedes;

}