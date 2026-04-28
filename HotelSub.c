#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include "Hotel.h"
#include "SalvametoBD.h"

void cadastrarHotel() {
    Hotel h;
    int bd = listar();
    int aux, x,x2;
    if (bd > 0) {
        printf("***** CADASTRAR HOTEL *****\n");
        if (bd == 1) {//verifica se esta usando txt
            x = contarLinhasHotelTXT();// se ja tiver um hotel cadastrado n cadastra mais
            if (x > 0) {
                printf("Já existe um hotel cadastrado! \n");
                menuCrudHotel();
            }
        } else if (bd == 2) {//verifica se ta usando bin
            x2 = contarLinhasH();
            if (x2 > 10) {
                printf("Já existe um hotel cadastrado! \n");
                menuCrudHotel();
            }

        }
        //faz a coleta dos dados
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

        if (bd == 1) {// verifica em qual arquivo deve cadastrar
            cadastrarHotelTXT(h);
        } else if (bd == 2) {
            cadastrarHotelBin(&h, 1);
        }


        // se n houver opção selecionada avisa para trocar no menu
    } else {
        printf("\nAltere a opção de salvamento em (MENU Principal->9 . Configurações-> 1. Op de BD.)\n");
    }
}

void verHotel() {
    int n;
    int bd = listar();
    Hotel *hot;
    if (bd == 1) {//verifica o arquivo usado e chama os metodos de listagem
        n = contarLinhasHotelTXT();
        hot = listarHTXT();
    } else if (bd == 2) {
        hot = listarHotelBIN(&n);
    } else {
        printf("\nAltere a opção de salvamento em (MENU Principal->9 . Configurações-> 1. Op de BD.)\n");
    }
    if (bd > 0) {
        if (n > 0) {//se o numero de linhas do arquivo não for maior que 0 
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
            }//lista todos os dados do hotel

        } else {
            printf("Hotel não cadastrado \n");
        }
    }
}

void deletarHotel() {
    int cod;
    int bd = listar();
    int n, m;
    printf("***** DELETAR HOTEL *****\n");
    if (bd > 0) {
        if (bd == 1) {//verifica o tipo do arquivo e faz a xclusão
            n = contarLinhasHotelTXT();
            if (n > 0) {
                removerHotelTXT();
            } else {
                printf("Não tem hotel cadastrado. \n");
            }
        } else {
            n = contarLinhasH();
            if (n > 0) {
                removerHotelB();
            } else {
                printf("Não tem hotel cadastrado. \n");
            }
        }
    }

    
}

void alterarHotel() {
    int n, aux;
    Hotel h;
    Hotel *hot;
    int bd = listar();
    if (bd == 1) {//txt
        hot = listarHTXT();//lista hotel em arquivo txt
        n = contarLinhasHotelTXT();//contas as linhas arquivo txt
    } else if (bd == 2) {//bin
        hot = listarHotelBIN(&n);//lista hotel em arquivo bin usando n como parametro
    } else {
        printf("\nAltere a opção de salvamento em (MENU Principal->9 . Configurações-> 1. Op de BD.)\n");
    }
    if (bd > 0) {
        if (n > 0) {
            printf("***** ALTERAR DADOS DO Hotel *****\n");
            printf("Digite o cod do Hotel \n");
            scanf("%d%*c", &h.codigo);
            int i;
            for (i = 0; i < n;) {
                if (h.codigo == hot[i].codigo) {// ve se o cod existe e pega os novos dadoss
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
                if(bd == 1){
                     int r = editarHotelTXT(hot, h, n);// chama o metodo que faz a edição em txt
                }else if(bd == 2){
                    int r = editarHotelBin(h, i);// chama o metodo que faz a edição em bin
                }
                printf("Atualização Efetuada com sucesso! \n");              
            }else{
                printf("Hotel não cadastrado \n");
            }
        } else {
            printf("\n  Nenhum operador cadastrado  \n");
        }
    }
}

/*int removerHotelControleBIN(int cod) {// metodo que remove n hoteis
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
        } else {
            return 1;
        }
    }
    //apaga arquivo
    int r = removerHotelBIN();
    if (r == 1) {
        //se deu certo reescreve arquivo
        return cadastrarHotelBin(hot, (num - 1));
    } else {
        return 0;
    }
}
*/
int contarLinhasH() {//contador linhas arq binario

    FILE *arq;

    char c, letra = '\n';

    int vezes, numl = 0;

    arq = fopen(".\\persist\\hotel.bin", "rb");

    //Lendo o arquivo 1 por 1
    while (fread(&c, sizeof (char), 1, arq)) {
        if (c == letra) {
            vezes++;
        }
    }

    //printf("\nLinhas: %i\n", vezes);
    fclose(arq);
    free(arq);
    numl = vezes;
    return numl;

}

int contarLinhasHotelTXT() {// contar linhas arq txt

    FILE *listOperador;
    int numOL = 0, c, numF;

    listOperador = fopen(".\\persist\\hotelTXT", "r");
    if (listOperador == NULL) {
        listOperador = fopen(".\\persist\\hotelTXT", "w+");
        if (listOperador == NULL) {
            printf("Erro ao acessar arquivo\n");
            return 0;
        }
    }
    //Lendo o arquivo 1 por 1
    while ((c = fgetc(listOperador)) != EOF) {
        if (c == '\n') {
            //soma a quantidade de linhas do TXT
            numOL++;
        }
    }
    numF = numOL / 18;//divide por 18 que é o número de dados do hotel
    fclose(listOperador);
    free(listOperador);

    return numF;

}

int removerHotelTXT() {//remove todos os dados do hotel txt

    FILE *arq;

    arq = fopen(".\\persist\\hotelTXT", "w");
    if (arq == NULL) {
        printf("Erro");
    } else {
        printf("Hotel deletado com sucesso. \n");
    }

}

int removerHotelB() {//remove todos os dados do hotel bin

    FILE *arq;

    arq = fopen(".\\persist\\hotel.bin", "wb");
    if (arq == NULL) {
        printf("Erro");
    } else {
        printf("Hotel deletado com sucesso. \n");
    }

}