/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "Hospede.c"

void cadastrarHospedes() {
    printf("***** CADASTRAR HÓSPEDE *****\n");
    //pega os dados

    Hospede h;

    printf("Digite o cod do hóspede \n");
    scanf("%d%*c", &h.codigo);
    //valida para ver se já existe

    printf("Digite o nome do hóspede \n");
    scanf("%[^\n]s%*c", &h.nome); // [^\n] Para poder aceitar espaços, pois iremos ler o nome completo
    setbuf(stdin, NULL); // limpa o buffer
    printf("Digite o cpf do hóspede (apenas números) \n");
    fgets(h.cpf, 13, stdin); // tamanho 13 porque tem o \0 e o fgets adciona uma quebra de linha no final(?)
    //Usamos FGETS pois SCANF não consegue ler todos os caracteres de um cpf (11 caracteres)
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

    //salva no arquivo
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



}

void listarHospedes() {
    //pega a lista de hóspedes do arquivo
    printf("\n LISTA DE TODOS OS HÓSPEDES \n");
    FILE *scanHospedes;

    scanHospedes = fopen(".\\persist\\hospedes.txt", "r");
    if (scanHospedes == NULL) {
        printf(" ERRO DE LEITURA ");
    } else {
        while (!feof(scanHospedes)) {
            Hospede h;
            int cod;
            //unsigned long int teste;
            char text[20];
            printf("*****************\n");
            //fscanf(scanHospedes, "%s %d\r\n%s %[^\n]s\r\n%s", text, &h.codigo,t2,h.nome,t3);
            //printf("%s %d\n%s %s\n%s", text, h.codigo,t2,h.nome,t3);
            fscanf(scanHospedes, "%s %d", text, &h.codigo);
            printf("%s %d\n", text, h.codigo);
            fscanf(scanHospedes, "%s %[^\n]s", text, h.nome);
            printf("%s %s\n", text, h.nome);
            fscanf(scanHospedes, "%s %s", text, h.cpf);
            printf("%s %s\n", text, h.cpf);
            fscanf(scanHospedes, "%s %s", text, h.telefone);
            printf("%s %s\n", text, h.telefone);
            fscanf(scanHospedes, "%s %s", text, h.email);
            printf("%s %s\n", text, h.email);
            fscanf(scanHospedes, "%s %c", text, &h.sexo);
            printf("%s %c\n", text, h.sexo);


            fscanf(scanHospedes, "%s %s", text, h.esCivil);
            printf("%s %s\n", text, h.esCivil);


            printf("*****************\n");

        }

        printf("\n FIM DA LISTA DE HÓSPEDES \n");
        fclose(scanHospedes);
    }


    /*    //lista os hóspedes
        printf("COD: 123\n");
        printf("ENDER: 123\n");
        printf("CPF: 123\n");
        printf("FONE: 123\n");
        printf("EMAIL: 123\n");
        printf("SEXO: 123\n");
        printf("ESTADO CIVIL: 123\n");
        printf("DATA NASC: 123\n");
     */
}

//METODO DO MODELO

Hospede* getAllHospedes() {
    int size = 0; //PARA ARMAZENAR O TAMANHO DO VETOR
    //int sizeElement;

    Hospede *arrayHospedes = (Hospede *) malloc(sizeof (Hospede)); //PONTEIRO DE HÓSPEDE VIRA UM VETOR AO CHAMAR MALLOC
    if (arrayHospedes == NULL) {
        printf("ERRO DE ALOCAÇÃO");
    }

    //pega a lista de hóspedes do arquivo
    printf("\n LISTA DE TODOS OS HÓSPEDES \n");
    FILE *scanHospedes;

    scanHospedes = fopen(".\\persist\\hospedes.txt", "r");
    if (scanHospedes == NULL) {
        printf(" ERRO DE LEITURA ");
    } else {
        while (!feof(scanHospedes)) { //enquanto não for o final do arquivo
            Hospede h;
            char text[20];

            printf("*****************\n");
            //FSCANF PARA PEGAR OS VALORES DO ARQUIVO. "TEXT[20]" É APENAS PARA ARMAZENAR A STRING QUE VEM ANTES DO VALOR.
            fscanf(scanHospedes, "%s %d", text, &h.codigo);
            //printf("%s %d\n", text, h.cod);
            fscanf(scanHospedes, "%s %[^\n]s", text, h.nome);
            //printf("%s %s\n", text, h.nome);
            fscanf(scanHospedes, "%s %s", text, h.cpf);
            //printf("%s %s\n", text, h.cpf);
            fscanf(scanHospedes, "%s %s", text, h.telefone);
            //printf("%s %s\n", text, h.telefone);
            fscanf(scanHospedes, "%s %s", text, h.email);
            //printf("%s %s\n", text, h.email);
            fscanf(scanHospedes, "%s %c", text, &h.sexo);
            //printf("%s %c\n", text, h.sexo);
            //ENDEREÇO
            //DATA NASC
            fscanf(scanHospedes, "%s %s", text, h.esCivil);
            //printf("%s %s\n", text, h.esCivil);

            //COLOCA O HOSPEDE NO ARRAY
            arrayHospedes[size] = h;
            size++;
            //sizeElement = sizeof(arrayHospedes)/sizeof(Hospede);

            //REALLOCA O VETOR DE HÓSPEDE, ADICIONANDO MAIS UM "ESPAÇO" PARA HOSPEDE
            arrayHospedes = realloc(arrayHospedes, (sizeof (Hospede) + sizeof (arrayHospedes)));

            //arrayHospedes = malloc(count*sizeof(Hospede));          
            printf("*****************\n");

        }

        printf("\n FIM DA LISTA DE HÓSPEDES \n");
        fclose(scanHospedes);


        /*printf("\n TESTE PARA VER TODOS OS ITENS DO ARRAY \n");
        for (int i = 0; i < size; i++) {
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

//METODO DO MODELO

Hospede getHospedeByCod(int cod) {

}

void atualizarHospedes() {
    printf("***** ALTERAR DADOS DO HÓSPEDE *****\n");

    printf("Digite o cod do hóspede \n");
    //scanf("%d%*c",&);
}

void deletarHospedes() {
    printf("***** DELETAR HÓSPEDE *****\n");

    printf("Digite o cod do hóspede \n");
    //scanf("%d%*c",&);
}
