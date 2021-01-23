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
#include "HospedeControl.h"
#include "FornecedorSUB.h"

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

    //VALIDAÇÃO EXTENÇÃO DO ARQUIVO
    //cadastrarHospedesTXT(h);
    cadastrarHospedesBIN(h);
}

void listarHospedesControl() {
    //int numHospedes = getNumHospedes();
    int numHospedes =0;
    printf("LISTA DE TODOS OS HÓSPEDES \n");
    //VALIDAÇÃO EXTENSÃO DO ARQUIVO
    //Hospede* arrayHospedes = getAllHospedesTXT(numHospedes);
    Hospede* arrayHospedes = getAllHospedesBIN(&numHospedes);

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

    //printf("NUMHOSPEDES: %d\n",numHospedes);
    free(arrayHospedes);
}

Hospede* getAllHospedesControl() {
    int numHospedes = getNumHospedes();
    
    //VALIDAR EXTENSÃO
    //Hospede* arrayHospedes = getAllHospedesTXT(numHospedes);
    return getAllHospedesBIN(numHospedes);
}

Hospede getHospedeByCodControl() {
    //TXT
    Hospede hos;
    int cod;
    //VALIDAR EXTENSÃO
    
    int numHospedes = getNumHospedes();

    printf("Digite o código do Hóspede que deseja procurar:\n");
    scanf("%d%*c", &cod);
    int validacao = validarCod(cod);
    setbuf(stdin, NULL);

    if (validacao == 0) {
        printf("INFORMAÇÕES DO HÓSPEDE: \n");
        hos = getHospedeByCodTXT(cod, numHospedes);
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
    //BIN
    /*int cod;
    Hospede h;
    printf("Digite o código do Hóspede que deseja procurar:\n");
    scanf("%d%*c", &cod);
    
    h = getHospedeByCodBIN(cod);
    
    printf("***************\n");
    printf("COD: %d\n", h.codigo);
    //printf("ENDER: 123\n");
    printf("NOME: %s\n", h.nome);
    printf("CPF: %s\n", h.cpf);
    printf("FONE: %s\n", h.telefone);
    printf("EMAIL: %s\n", h.email);
    printf("SEXO: %c\n", h.sexo);
    printf("ESTADO CIVIL: %s\n", h.esCivil);
    //printf("DATA NASC: 123\n");
    printf("***************\n");
     */
}

void atualizarHospedesControl() {
    printf("***** ALTERAR DADOS DO HÓSPEDE *****\n");
    int cod;
    Hospede novoHosp;
    printf("Digite o cod do hóspede \n");
    scanf("%d%*c", &cod);
    //if (validarCod(cod) == 0) {
        novoHosp.codigo = cod;

        //pega os novos dados
        printf("Atualize o nome do hóspede \n");
        //scanf("%[^\n]s%*c", &h.nome); 
        fgets(novoHosp.nome, 101, stdin);
        strtok(novoHosp.nome, "\n"); // Esse comando serve para retirar o \n que o fgets coloca no final da string lida

        printf("Atualize o cpf do hóspede (apenas números) \n");
        fgets(novoHosp.cpf, 13, stdin); // tamanho 13 porque tem o \0 e o fgets adciona uma quebra de linha no final(?)
        strtok(novoHosp.cpf, "\n");

        //setbuf(stdin, NULL); // limpa o buffer

        printf("Atualize o telefone do hóspede \n");
        fgets(novoHosp.telefone, 15, stdin);
        strtok(novoHosp.telefone, "\n");

        printf("Atualize o email do hóspede \n");
        //scanf("%s%*c", &h.email);
        fgets(novoHosp.email, 101, stdin);
        strtok(novoHosp.email, "\n");
        printf("Atualize o sexo do hóspede (M - masculino , F - Feminino) \n");
        scanf("%s%*c", &novoHosp.sexo);

        printf("Atualize o estado civil do hóspede \n");
        //scanf("%s%*c", &h.esCivil);
        fgets(novoHosp.esCivil, 11, stdin);
        strtok(novoHosp.esCivil, "\n");
        //printf("Atualize a data de nasc do hóspede \n");
        //scanf("%d%*c",&);

        //printf("Atualize o endereço do hóspede \n");
        //scanf("%s%*c",&h.end);


        printf("TESTE\n");
        printf("COD: %d\n", novoHosp.codigo);
        printf("NOME: %s\n", novoHosp.nome);
        printf("CPF: %s\n", novoHosp.cpf);
        printf("EMAIL: %s\n", novoHosp.email);
        printf("TELEFONE: %s\n", novoHosp.telefone);
        printf("ESCIVIL: %s\n", novoHosp.esCivil);
        printf("SEXO: %c\n", novoHosp.sexo);

        //VERFICAÇÃO EXTENSÃO DO ARQUIVO
        //atualizarHospedeTXT(novoHosp);
        atualizarHospedeBIN(novoHosp);
        printf("ALTERAÇÃO CONCLUÍDA\n");

    //} else {
    //    printf("CÓDIGO NÃO EXISTE");
    //}
}

void deletarHospedesControl() {
    printf("***** DELETAR HÓSPEDE *****\n");
    /*int cod;
    char confirmacao;

    printf("Digite o cod do hóspede \n");
    scanf("%d%*c", &cod);
    int validacao = validarCod(cod);
    if (validacao == 0) {
        int numHospedes = getNumHospedes();
        Hospede hos = getHospedeByCodTXT(cod, numHospedes);

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


    //} else {
    //  printf("CÓDIGO NÃO EXISTE\n");
    //}
    //VERIFICAR EXT DO ARQUIVO
    
    ////////BIN
    int cod;

    printf("Digite o cod do hóspede \n");
    scanf("%d%*c", &cod);
    Hospede h = getHospedeByCodBIN(cod);
    deletarHospedeBIN(cod);

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