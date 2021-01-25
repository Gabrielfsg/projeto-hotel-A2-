#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include "Hotel.h"

void cadastrarHotel() {
    Hotel h;

    printf("***** CADASTRAR HOTEL *****\n");
    printf("Digite o Cod do Hotel \n");
    scanf("%d%*c", &h.codigo);
    printf("Digite o CNPJ do Hotel \n");
    fgets(h.cnpj, 100, stdin);
    strtok(h.cnpj, "\n");
    setbuf(stdin, NULL);
    printf("Digite o EMAIL do Hotel \n");
    fgets(h.email, 100, stdin);
    strtok(h.email, "\n");
    setbuf(stdin, NULL);
    printf("Digite a incrição estadual do Hotel \n");
    fgets(h.inscricaoEstadual, 100, stdin);
    strtok(h.inscricaoEstadual, "\n");
    setbuf(stdin, NULL);
    printf("Digite o Nome Fantasia do Hotel \n");
    fgets(h.nomeFantazia, 100, stdin);
    strtok(h.nomeFantazia, "\n");
    setbuf(stdin, NULL);
    printf("Digite o nomeResponsavel do Hotel \n");
    fgets(h.nomeResponsavel, 100, stdin);
    strtok(h.nomeResponsavel, "\n");
    setbuf(stdin, NULL);
    printf("Digite o telefone do Hotel \n");
    scanf("%d*c", &h.telefone);
    setbuf(stdin, NULL);
    printf("Digite a margem de lucro \n");
    scanf("%f*c", &h.margemLucro);
    setbuf(stdin, NULL);
    printf("Digite o Horário checkIn \n");
    fgets(h.checkIn, 100, stdin);
    strtok(h.checkIn, "\n");
    setbuf(stdin, NULL);
    printf("Digite o Horário checkOut do Hotel \n");
    fgets(h.checkOut, 100, stdin);
    strtok(h.checkOut, "\n");
    setbuf(stdin, NULL);
    printf("Digite o Telefone do Responsável do Hotel \n");
    fgets(h.teleRes, 100, stdin);
    strtok(h.teleRes, "\n");
    setbuf(stdin, NULL);
    printf("Digite a Razão Social do Hotel do Hotel \n");
    fgets(h.razaoSocial, 100, stdin);
    strtok(h.razaoSocial, "\n");
    setbuf(stdin, NULL);
    printf("Digite o Número do Hotel \n");
    scanf("%d%*c", &h.numero);
    setbuf(stdin, NULL);
    printf("Digite o bairro do Hotel \n");
    fgets(h.bairro, 100, stdin);
    strtok(h.bairro, "\n");
    setbuf(stdin, NULL);
    printf("Digite o cep do Hotel \n");
    scanf("%d*c", &h.cep);
    setbuf(stdin, NULL);
    printf("Digite o logradouro do Hotel \n");
    fgets(h.logradouro, 100, stdin);
    strtok(h.logradouro, "\n");
    setbuf(stdin, NULL);
    printf("Digite o uf do Hotel \n");
    fgets(h.uf, 100, stdin);
    strtok(h.uf, "\n");
    setbuf(stdin, NULL);
    printf("Digite a cidade do Hotel \n");
    fgets(h.cidade, 100, stdin);
    strtok(h.cidade, "\n");
    setbuf(stdin, NULL);

    cadastrarHotelBin(&h, 1);


}

void verHotel() {
    int n;
    Hotel *hot;
    hot = listarHotelBIN(&n);
    int i;
    for (i = 0; i < n; i++) {
        printf("\n*******%d************", i);
        printf("\nCodigo: %d", hot[i].codigo);
        printf("\nCNPJ: %s", hot[i].cnpj);
        printf("\nEMAIL: %s", hot[i].email);
        printf("\nInscrição estadual: %s", hot[i].inscricaoEstadual);
        printf("\nNOME FANTASIA: %s", hot[i].nomeFantazia);
        printf("\nNome Responsável: %s", hot[i].nomeResponsavel);
        printf("\nTelefone: %d", hot[i].telefone);
        printf("\nMargem de lucro: %f", hot[i].margemLucro);
        printf("\nCheck In: %s", hot[i].checkIn);
        printf("\nnCheck Out: %s", hot[i].checkOut);
        printf("\nTelefone Responsável: %s", hot[i].teleRes);
        printf("\nRazao Social: %s", hot[i].razaoSocial);
        printf("\nNumero: %d", hot[i].numero);
        printf("\nBairro: %s", hot[i].bairro);
        printf("\nCep: %d", hot[i].cep);
        printf("\nLogradouro: %s", hot[i].logradouro);
        printf("\nUF: %s", hot[i].uf);
        printf("\nCidade: %s \n", hot[i].cidade);


    }
}

void deletarHotel() {
    int cod;
    printf("***** DELETAR HOTEL *****\n");
    printf("Entre com o código do hotel: ");
    scanf("%d", &cod);
    int x = removerHotelControleBIN(cod);
    if (x == 1) {
        printf("\nExclusão realizada com sucesso!\n");
    } else {
        printf("\nNão foi possivel encontrar categoria de codigo %d \n", cod);
    }
}

void alterarHotel() {
    int n, aux;
    Hotel h;
    Hotel *hot = listarHotelBIN(&n);
    printf("***** ALTERAR DADOS DO Hotel *****\n");
    printf("Digite o cod do Hotel \n");
    scanf("%d%*c", &h.codigo);
    int i;
    for (i = 0; i < n;) {
        if (h.codigo == hot[i].codigo) {
            printf("Digite o CNPJ do Hotel \n");
            fgets(h.cnpj, 100, stdin);
            strtok(h.cnpj, "\n");
            setbuf(stdin, NULL);
            printf("Digite o EMAIL do Hotel \n");
            fgets(h.email, 100, stdin);
            strtok(h.email, "\n");
            setbuf(stdin, NULL);
            printf("Digite a incrição estadual do Hotel \n");
            fgets(h.inscricaoEstadual, 100, stdin);
            strtok(h.inscricaoEstadual, "\n");
            setbuf(stdin, NULL);
            printf("Digite o Nome Fantasia do Hotel \n");
            fgets(h.nomeFantazia, 100, stdin);
            strtok(h.nomeFantazia, "\n");
            setbuf(stdin, NULL);
            printf("Digite o nomeResponsavel do Hotel \n");
            fgets(h.nomeResponsavel, 100, stdin);
            strtok(h.nomeResponsavel, "\n");
            setbuf(stdin, NULL);
            printf("Digite o telefone do Hotel \n");
            scanf("%d*c", &h.telefone);
            setbuf(stdin, NULL);
            printf("Digite a margem de lucro \n");
            scanf("%f*c", &h.margemLucro);
            setbuf(stdin, NULL);
            printf("Digite o Horário checkIn \n");
            fgets(h.checkIn, 100, stdin);
            strtok(h.checkIn, "\n");
            setbuf(stdin, NULL);
            printf("Digite o Horário checkOut do Hotel \n");
            fgets(h.checkOut, 100, stdin);
            strtok(h.checkOut, "\n");
            setbuf(stdin, NULL);
            printf("Digite o Telefone do Responsável do Hotel \n");
            fgets(h.teleRes, 100, stdin);
            strtok(h.teleRes, "\n");
            setbuf(stdin, NULL);
            printf("Digite a Razão Social do Hotel do Hotel \n");
            fgets(h.razaoSocial, 100, stdin);
            strtok(h.razaoSocial, "\n");
            setbuf(stdin, NULL);
            printf("Digite o Número do Hotel \n");
            scanf("%d%*c", &h.numero);
            setbuf(stdin, NULL);
            printf("Digite o bairro do Hotel \n");
            fgets(h.bairro, 100, stdin);
            strtok(h.bairro, "\n");
            setbuf(stdin, NULL);
            printf("Digite o cep do Hotel \n");
            scanf("%d*c", &h.cep);
            setbuf(stdin, NULL);
            printf("Digite o logradouro do Hotel \n");
            fgets(h.logradouro, 100, stdin);
            strtok(h.logradouro, "\n");
            setbuf(stdin, NULL);
            printf("Digite o uf do Hotel \n");
            fgets(h.uf, 100, stdin);
            strtok(h.uf, "\n");
            setbuf(stdin, NULL);
            printf("Digite a cidade do Hotel \n");
            fgets(h.cidade, 100, stdin);
            strtok(h.cidade, "\n");
            setbuf(stdin, NULL);
            aux = 1;
            break;
        }
        i++;
    }
    if (aux == 1) {
        int r = editarHotelBin(h, i);
    }
}

int removerHotelControleBIN(int cod) {
    int num;
    Hotel *hot = listarHotelBIN(&num);

    int i;
    for (i = 0; i < num; i++) {
        if (hot[i].codigo == cod) {
            int j;
            for (j = i; j < num - 1; j++) {
                hot[i].codigo = hot[i + 1].codigo;
                strcpy(hot[i].cnpj, hot[i + 1].cnpj);
                strcpy(hot[i].email, hot[i + 1].email);
                strcpy(hot[i].inscricaoEstadual, hot[i + 1].inscricaoEstadual);
                strcpy(hot[i].nomeFantazia, hot[i + 1].nomeFantazia);
                strcpy(hot[i].nomeResponsavel, hot[i + 1].nomeResponsavel);
                hot[i].telefone = hot[i + 1].telefone;
                hot[i].margemLucro = hot[i + 1].margemLucro;
                strcpy(hot[i].checkIn, hot[i + 1].checkIn);
                strcpy(hot[i].checkOut, hot[i + 1].checkOut);
                strcpy(hot[i].teleRes, hot[i + 1].teleRes);
                strcpy(hot[i].razaoSocial, hot[i + 1].razaoSocial);
                hot[i].numero = hot[i + 1].numero;
                strcpy(hot[i].bairro, hot[i + 1].bairro);
                hot[i].cep = hot[i + 1].cep;
                strcpy(hot[i].logradouro, hot[i + 1].logradouro);
                strcpy(hot[i].uf, hot[i + 1].uf);
                strcpy(hot[i].cidade, hot[i + 1].cidade);
                hot = realloc(hot, (num - 1) * sizeof (Hotel));
            }
            break;
        }
    }
    //apaga arquivo
    int r = removerHotelBIN();
    if (r == 1) {
        //se deu certo reescreve arquivo
        return salvarHotelTXT(hot, (num - 1));
    } else {
        return 0;
    }
}