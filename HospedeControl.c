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
    scanf("%[^\n]s%*c", &h.nome); // [^\n] Para poder aceitar espaços, pois iremos ler o nome completo
    setbuf(stdin, NULL); // limpa o buffer
    printf("Digite o cpf do hóspede (apenas números) \n");
    fgets(h.cpf, 13, stdin); // tamanho 13 porque tem o \0 e o fgets adciona uma quebra de linha no final(?)
    //Usamos FGETS pois SCANF não consegue ler todos os caracteres de um cpf (11 caracteres)

    strtok(h.cpf, "\n"); // Esse comando serve para retirar o \n que o fgets coloca no final do cpf

    setbuf(stdin, NULL); // limpa o buffer

    printf("Digite o telefone do hóspede \n");
    scanf("%s%*c", &h.telefone);

    printf("Digite o email do hóspede \n");
    scanf("%s%*c", &h.email);

    printf("Digite o sexo do hóspede (M - masculino , F - Feminino) \n");
    scanf("%s%*c", &h.sexo);

    printf("Digite o estado civil do hóspede \n");
    scanf("%s%*c", &h.esCivil);

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
    printf("\n LISTA DE TODOS OS HÓSPEDES \n");
    Hospede* arrayHospedes = getAllHospedes();
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

    Hospede* arrayHospedes = getAllHospedes();
    return arrayHospedes;
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
    printf("Digite o cod do hóspede \n");
    scanf("%d%*c", &cod);
    int validacao = validarCod(cod);
    if (validacao == 0) {
        //printf("entrou deletarControl\n");
        setbuf(stdout, NULL);
        fflush(stdout);
        Hospede h = getHospedeByCod(cod, numHospedes);
        //setbuf(stdout, NULL);
        //setlinebuf(stdout);
        printf("+++++++++++++++++++++ \n");
        printf("COD: %d\n", h.codigo);
        printf("NOME: %s\n", h.nome);
        printf("CPF: %s\n", h.cpf);
        printf("EMAIL: %s\n", h.email);
        printf("SEXO: %c\n", h.sexo);
        printf("ESCIVIL: %s\n", h.esCivil);
        printf("TELEFONE: %s\n", h.telefone);
        printf("+++++++++++++++++++++ \n");
        printf("DESEJA DELETAR O HÓSPEDE ACIMA? (S/N)\n");
        
        scanf("%c%*c",&confirmacao);
        if(confirmacao == 'S' || confirmacao == 's'){
            //deleta
            //mandar o obj ou só o cod para um método "sobreescrever"
            sobrescreverHospedesTXT(h.codigo);
            //esse método pega todo o array de hóspedes
            //depois ele escreve todos os hóspedes no aruqivo de novo
            //mas existe um if para ver se o hospede do array tem o mesmo código do cara que ele deletou
            // se tiver, não escreve no arquivo
            
        }else{
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
    //numHospedes = numLinhas / 7; //9;

    printf("\nO NÚMERO DE LINHAS DO ARQ É: %d\n",numLinhas);
    //printf("\nO NÚMERO DE HOSPEDES CADASTRADOS É: %d\n",numHospedes);
    fclose(arq);
    free(arq);
    //return numHospedes;
    return numLinhas;
}