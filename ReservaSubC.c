/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include "Categoria.h"
#include "Acomodacao.h"
#include "Hospede.h"
#include "HospedeMenu.h"
#include "Reserva.h"
#include "Hotel.h"

#include "SalvametoBD.h"

#include "ReservaSubC.h"


void reservaPQuantidade() {
    int bd = listar();
    Data dataIn;
    Data dataFim;
    int quant, num, cod, num2, hos, num3, num4, n;
    int r;
    int achei, achei2;
    Acomodacao *aco;
    Categoria *cat;
    Reserva *res;
    //n = contarLinhasResTXT();
    //res = listarResTXT();
    Hospede *arrayHospedes;
    int achou = 0;
    int achouD = 0, achouR = 0;
    Reserva reserva;
    int codReserva;
    if (bd == 1) {
        n = contarLinhasResTXT();
        res = listarResTXT();       
        aco = listarAcomodacaoTXT();
        cat = listarCategoriaTXT();
    } else if (bd == 2) {
        aco = listarAcomodacaoBIN(&num);
        cat = listarCategoriaBIN(&num2);
        arrayHospedes = getAllHospedesBIN(&num3);
        res = listarResBIN(&num4);
    }
    if (bd > 0) {
        printf("Entre com a quantidade de pessoas desejada: ");
        scanf("%d*c", &quant);

        int i, j;
        for (i = 0; i < num; i++) {
            if (cat[i].quantidadePessoas == quant) {
                printf("\n**************** %d *****************\n", i);
                printf("COD: %d\n", aco[i].codigo);
                printf("DESCRIÇÃO: %s\n", aco[i].descricao);
                printf("STATUS: %s\n", aco[i].status);
                achou++;
                for (j = 0; j < num2; j++) {
                    if (aco[i].categoria.codigo == cat[j].codigo) {
                        printf("CATEGORIAS: %s\n", cat[j].descricao);
                        printf("FACILIDADES: %s\n", cat[j].facilidade);
                        printf("VALOR DIARIA: %f\n", cat[j].valorDiario);
                        printf("N° PESSOAS: %d\n", cat[j].quantidadePessoas);
                    }

                }
            }
        }
        if (achou > 0) {
            printf("Quartos encontrados !!! \n");
            printf("Digite o código da acomodação que deseja: ");
            scanf("%d*c", &cod);
            for (i = 0; i < num; i++) {
                if (aco[i].codigo == cod) {
                    achei = 1;
                    break;
                }
            }
            if (achei == 1) {
                reserva.codA = cod;
                printf("Acodação %d selecionada. \n", cod);
                printf("Digite o código do hospede: ");
                scanf("%d*c", &hos);
                achei2 = validarCodHospede(hos, 2);
                if (achei2 == 0) {
                    reserva.codH = hos;
                    printf("Hospede %d selecionado. \n", cod);
                    printf("Digita o dia da data de início da reserva (1-30):\n");
                    scanf("%d%*c", &dataIn.dia);
                    printf("Digita o mes da data de início da reserva (1-12):\n");
                    scanf("%d%*c", &dataIn.mes);
                    printf("Digita o ano da data de início da reserva:\n");
                    scanf("%d%*c", &dataIn.ano);
                    if (bd == 1) {
                        for (i = 0; i < n; i++) {
                            if (res[i].codA == reserva.codA) {
                                if (res[i].DataIn.dia == dataIn.dia && res[i].DataIn.mes == dataIn.mes && res[i].DataIn.ano == dataIn.ano) {
                                    achouD = 1;
                                    break;
                                }
                            }
                        }
                    } else if (bd == 2) {
                        for (i = 0; i < num4; i++) {
                            if (res[i].codA == reserva.codA) {
                                if (res[i].DataIn.dia == dataIn.dia && res[i].DataIn.mes == dataIn.mes && res[i].DataIn.ano == dataIn.ano) {
                                    achouD = 1;
                                    break;
                                }
                            }
                        }
                    }
                    if (achouD > 0) {
                        printf("A acomodação %d ja está alugada esse dia! \n", reserva.codA);
                        cadReserva();
                    }
                    reserva.DataIn = dataIn;
                    printf("Digita o dia da data do fim da reserva: (1-30)\n");
                    scanf("%d%*c", &dataFim.dia);
                    printf("Digita o mes da data do fim da reserva: (1-12)\n");
                    scanf("%d%*c", &dataFim.mes);
                    printf("Digita o ano da data do fim da reserva:\n");
                    scanf("%d%*c", &dataFim.ano);
                    reserva.DataFin = dataFim;
                    printf("Digite o código da Reserva: \n");
                    scanf("%d%*c", &codReserva);
                    reserva.codigo = codReserva;
                    if (bd == 1) {
                        for (i = 0; i < n; i++) {
                            if (res[i].codigo == reserva.codigo) {
                                achouR = 1;
                            }
                        }
                    } else if (bd == 2) {
                        for (i = 0; i < num4; i++) {
                            if (res[i].codigo == reserva.codigo) {
                                achouR = 1;
                            }
                        }
                    }
                    if (achouR == 1) {
                        printf("Código da reserva ja em uso. \n");
                        cadReserva();
                    }
                    printf("########## Reserva #############\n");

                    printf("CÓDIGO DA RESERVA: %d \n", reserva.codigo);
                    printf("DATA INI: %d /%d /%d\n", reserva.DataIn.dia, reserva.DataIn.mes, reserva.DataIn.ano);
                    printf("DATA FIM: %d /%d /%d\n", reserva.DataFin.dia, reserva.DataFin.mes, reserva.DataFin.ano);
                    printf("CÓDIGO HOSPEDE: %d \n", reserva.codH);
                    printf("CÓDIGO ACOMODAÇÃO: %d \n", reserva.codA);

                    printf("##########  #############\n");

                    int teste = 99;
                    if (bd == 1) {
                        FILE *cad;
                        cad = fopen("arquivos\\ReservaTXT", "a");
                        if (cad == NULL) {
                            cad = fopen("arquivos\\ReservaTXT", "w");
                            return 0;
                        } else {
                            fprintf(cad, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", reserva.codigo, reserva.DataIn.dia,
                                    reserva.DataIn.mes, reserva.DataIn.ano, reserva.DataFin.dia,
                                    reserva.DataFin.mes, reserva.DataFin.ano, reserva.codH, reserva.codA);
                            /*fecha o arquivo*/
                            fclose(cad);
                            /*libera mémoria*/
                            free(cad);
                        }
                    } else if (bd == 2) {
                        FILE *cad;
                        cad = fopen("arquivos\\ReservaBIN.bin", "ab");
                        if (cad == NULL) {
                            cad = fopen("arquivos\\ReservaBIN.bin", "wb");
                            return 0;
                        } else {
                            teste = fwrite(&reserva, sizeof (Reserva), 1, cad);
                            fflush(cad);

                            fclose(cad);

                            free(cad);
                        }
                    }
                    printf("GRAVOU RESERVA\n");


                } else {
                    printf("Nenhuma hospede encontrada. \n");

                }
            } else {
                printf("Nenhuma acomodação encontrada. \n");

            }
        } else {
            printf("Nenhum quarto encontrado. \n");

        }





        free(aco);

    }

}

void reservaPCategoria() {
    int bd = listar();
    int num, cod, num2;
    char opc[20];
    int r;
    Acomodacao *aco;
    Categoria *cat;
    int achou = 0;
    int achouD = 0;
    aco = listarAcomodacaoBIN(&num);
    cat = listarCategoriaBIN(&num2);
    if (bd > 0) {
        printf("Entre com o estilo de categoria de pessoas desejada: \n"
                "1.standart. \n"
                "2.presidecial. \n"
                "3.luxo \n");
        scanf("%s*c", &opc);

        int i, j;
        for (i = 0; i < num; i++) {
            if (strcmp(aco[i].descricao, opc) == 0) {
                printf("\n**************** %d *****************\n", i);
                printf("COD: %d\n", aco[i].codigo);
                printf("DESCRIÇÃO: %s\n", aco[i].descricao);
                printf("STATUS: %s\n", aco[i].status);
                achou++;
                for (j = 0; j < num2; j++) {
                    if (aco[i].categoria.codigo == cat[j].codigo) {
                        printf("CATEGORIAS: %s\n", cat[j].descricao);
                        printf("FACILIDADES: %s\n", cat[j].facilidade);
                        printf("VALOR DIARIA: %f\n", cat[j].valorDiario);
                        printf("N° PESSOAS: %d\n", cat[j].quantidadePessoas);
                    }

                }
            }
        }

    }
    free(aco);
}

void reservar() {
    int bd = listar();
    int quant, num, cod, num2;
    int r;
    Acomodacao *aco;
    Categoria *cat;
    int achou = 0;
    int achouD = 0;
    aco = listarAcomodacaoBIN(&num);
    cat = listarCategoriaBIN(&num2);
    int i, j;
    for (i = 0; i < num; i++) {
        printf("\n**************** %d *****************\n", i);
        printf("COD: %d\n", aco[i].codigo);
        printf("DESCRIÇÃO: %s\n", aco[i].descricao);
        printf("STATUS: %s\n", aco[i].status);
        achou++;
        for (j = 0; j < num2; j++) {
            if (aco[i].categoria.codigo == cat[j].codigo) {
                printf("CATEGORIAS: %s\n", cat[j].descricao);
                printf("FACILIDADES: %s\n", cat[j].facilidade);
                printf("VALOR DIARIA: %f\n", cat[j].valorDiario);
                printf("N° PESSOAS: %d\n", cat[j].quantidadePessoas);
            }

        }

    }
    printf("Entre com a quantidade de pessoas desejada: ");
    scanf("%d*c", &quant);

    for (i = 0; i < num; i++) {
        if (cat[i].quantidadePessoas == quant) {
            printf("\n**************** %d *****************\n", i);
            printf("COD: %d\n", aco[i].codigo);
            printf("DESCRIÇÃO: %s\n", aco[i].descricao);
            printf("STATUS: %s\n", aco[i].status);
            achou++;
            for (j = 0; j < num2; j++) {
                if (aco[i].categoria.codigo == cat[j].codigo) {
                    printf("CATEGORIAS: %s\n", cat[j].descricao);
                    printf("FACILIDADES: %s\n", cat[j].facilidade);
                    printf("VALOR DIARIA: %f\n", cat[j].valorDiario);
                    printf("N° PESSOAS: %d\n", cat[j].quantidadePessoas);
                }

            }
        }
    }
    free(aco);
    free(cat);
}

void reservaCombCriterios() {
    Data dataIn;
    Data dataFim;
    Categoria categoriaDaReserva;
    Acomodacao acomodacaoDaReserva;
    Acomodacao* arrayAllAcomod;
    Categoria *arrayAllCat;
    Reserva reserva;
    Hospede* arrayAllhosp;


    int numHospedes = 0, numLinhaAcomod, numLinhaCat;
    int codHosp, codCat, codAcomod = 0;


    int ext = listar();
    if (ext == 2) {
        //BIN        
        arrayAllhosp = getAllHospedesBIN(&numHospedes);
        arrayAllAcomod = listarAcomodacaoBIN(&numLinhaAcomod);
        arrayAllCat = listarCategoriaBIN(&numLinhaCat);
    }
    if (ext == 1) {
        //TXT
        numHospedes = getNumHospedes();
        numLinhaCat = numLinhasCategoria();
        numLinhaAcomod = numLinhasAcomodacao();

        arrayAllhosp = getAllHospedesTXT(numHospedes);
        arrayAllAcomod = listarAcomodacaoTXT();
        arrayAllCat = listarCategoriaTXT();

    }
    int qteHospedes;


    printf("*********** RESERVA ***********\n\n");


    printf("Digite a quantidade de Hospedes:\n");
    scanf("%d%*c", &qteHospedes);


    //int arrayHospedesDaReserva[qteHospedes];


    printf("Digite o código do Hospede Responsável:\n");
    scanf("%d%*c", &codHosp);
    if (validarCodHospede(codHosp, ext) == 1) {
        printf("CÓDIGO DO HÓSPEDE NÃO EXISTE\n");
        return;
    } else {
        printf("NUM HOSPEDES = %d\n", numHospedes);
        for (int i = 0; i < numHospedes; i++) {
            if (codHosp = arrayAllhosp[i].codigo) {
                printf("ACHOU O HOSPEDE NO ARRAY");
                reserva.codH = codHosp;
                reserva.hospede = arrayAllhosp[i];
            }
        }



    }


    printf("************* LISTA DE CATEGORIAS DISPONÍVEIS *************\n");
    for (int i = 0; i < numLinhaCat; i++) {
        if (arrayAllCat[i].quantidadePessoas >= qteHospedes) {
            printf("COD: %d\n", arrayAllCat[i].codigo);
            printf("DESCRIÇÃO: %s\n", arrayAllCat[i].descricao);
            printf("FACILIDADE: %s\n", arrayAllCat[i].facilidade);
            printf("QTE PESSOAS: %d\n", arrayAllCat[i].quantidadePessoas);
            printf("VALOR: %.2f\n", arrayAllCat[i].valorDiario);
        }
    }

    printf("************* FIM DA LISTA DE CATEGORIAS *************\n");
    printf("Digite o código da Categoria:\n");
    scanf("%d%*c", &codCat);

    int achou = 0;
    for (int i = 0; i < numLinhaCat; i++) {
        if (arrayAllCat[i].codigo == codCat) {
            categoriaDaReserva = arrayAllCat[i];
            achou = 1;
        }
    }
    if (achou == 0) {
        printf("CÓDIGO DA CATEGORIA INVÁLIDO\n");
        return;
    }


    /*if (ext == 2) {
        if (validarAcomodacaoBIN(codAcomod) == 0) {
            printf("CÓDIGO DA ACOMODAÇÃO NÃO EXISTE\n");
            return;
        }
    }
    if (ext == 1) {
        if (validarAcomodacao(codAcomod) == 0) {
            printf("CÓDIGO DA ACOMODAÇÃO NÃO EXISTE\n");
            return;
        }
    }
     */
    //PEGA AS DATAS



    printf("Digita o dia da data de início da reserva:\n");
    scanf("%d%*c", &dataIn.dia);
    printf("Digita o mes da data de início da reserva:\n");
    scanf("%d%*c", &dataIn.mes);
    printf("Digita o ano da data de início da reserva:\n");
    scanf("%d%*c", &dataIn.ano);

    printf("Digita o dia da data do fim da reserva:\n");
    scanf("%d%*c", &dataFim.dia);
    printf("Digita o mes da data do fim da reserva:\n");
    scanf("%d%*c", &dataFim.mes);
    printf("Digita o ano da data do fim da reserva:\n");
    scanf("%d%*c", &dataFim.ano);


    printf("************* LISTA DE QUARTOS DISPONÍVEIS *************\n");
    for (int i = 0; i < numLinhaAcomod; i++) {
        if (arrayAllAcomod[i].categoria.codigo == codCat) {
            //VERIFICAR SE "STATUS" = LIVRE
            printf("*****************\n");
            printf("CODIGO: %d\n", arrayAllAcomod[i].codigo);
            printf("DESC: %s\n", arrayAllAcomod[i].descricao);
            printf("*****************\n");

        }
    }
    printf("************* FIM DA LISTA DE QUARTOS *************\n");

    printf("Digite o código do quarto: \n");
    scanf("%d%*c", &codAcomod);

    achou = 0;
    for (int i = 0; i < numLinhaAcomod; i++) {
        if (arrayAllAcomod[i].codigo == codAcomod) {
            acomodacaoDaReserva = arrayAllAcomod[i];
            achou = 1;
        }
    }

    if (achou == 0) {
        printf("CÓDIGO DO QUARTO INVÁLIDO\n");
    }

    int codReserva;
    printf("Digite o código da Reserva: \n");
    scanf("%d%*c", &codReserva);

    reserva.codigo = codReserva;
    reserva.DataFin = dataFim;
    reserva.DataIn = dataIn;
    reserva.acomodacao = acomodacaoDaReserva;
    reserva.codA = acomodacaoDaReserva.codigo;



    printf("########## SCTRUCT #############\n");

    printf("COD: %d \n", reserva.codigo);
    printf("COD ACOMODACAO: %d \n", reserva.acomodacao.codigo);
    printf("COD ACOMODACAO: %d \n", reserva.codA);
    //printf("ACOMODACAO DESC: %s \n", reserva.acomodacao.descricao);
    //printf("CAT COD: %d \n", reserva.acomodacao.categoria.codigo);
    printf("DATA INI: %d /%d /%d\n", reserva.DataIn.dia, reserva.DataIn.mes, reserva.DataIn.ano);
    printf("DATA FIM: %d /%d /%d\n", reserva.DataFin.dia, reserva.DataFin.mes, reserva.DataFin.ano);
    printf("HOSPEDE: %d\n", reserva.hospede.codigo);
    printf("HOSPEDE: %d\n", reserva.codH);

    printf("##########  #############\n");



    if (ext == 2) {
        //BIN
        int retorno = cadastrarReservaBIN(&reserva, 1);
        if (retorno == 1) {
            printf("RESERVA CADASTRADA COM SUCESSO\n");
        } else {
            printf("ERRO AO CADASTRAR RESERVA\n");
        }
    }
    if (ext == 1) {
        //TXT
        int gravou = cadastrarReservaTXT(reserva);
        if (gravou == 1) {
            printf("RESERVA CADASTRADA COM SUCESSO\n");
        } else {
            printf("ERRO AO CADASTRAR RESERVA\n");
        }
    }




    /*
        int teste = 99;
        FILE *cad;
        cad = fopen("arquivos\\ReservaBIN.bin", "ab");
        if (cad == NULL) {
            cad = fopen("arquivos\\ReservaBIN.bin", "wb");
            return 0;
        } else {
            teste = fwrite(&reserva, sizeof (Reserva), 1, cad);
            fflush(cad);
        
            fclose(cad);
        
            free(cad);
        }


        if (teste == 1) {
            printf("GRAVOU RESERVA\n");
        } else {
            printf("ERRO AO GRAVAR RESERVA\n");
        }

     */



    //METODO PARA LER DO BINARIO

    /*

        printf("VOU LER\n");
        Reserva lida;
        FILE *ler;
        ler = fopen("arquivos\\ReservaBIN.bin", "rb");
        if (ler == NULL) {
            printf("ERRO AO LER ARQUIVO");
            return 0;
        } else {
            fread(&lida, sizeof (Reserva), 1, ler);
            fflush(ler);

            fclose(ler);

            free(ler);
        }

        printf("########## LIDA #############\n");

        printf("COD: %d \n", lida.codigo);
        // printf("COD ACOMODACAO: %d \n", lida.acomodacao.codigo);
        // printf("ACOMODACAO DESC: %s \n", lida.acomodacao.descricao);
        // printf("CAT COD: %d \n", lida.acomodacao.categoria.codigo);
        printf("DATA FIM: %d /%d /%d\n", lida.DataFin.dia, lida.DataFin.mes, lida.DataFin.ano);
        printf("HOSPEDES:\n");
        for (int i = 0; i < 10; i++) {
            // if (lida.hospede[i] != 0) {
            // printf("    COD: %d\n", lida.hospede[i]);
        }
     */


    free(arrayAllAcomod);
    free(arrayAllCat);
    free(arrayAllhosp);
}
//}

void listarReserva() {
    int bd = listar();
    int n, aux;
    Reserva *res;
    if (bd == 1) {
        n = contarLinhasResTXT();
        res = listarResTXT();
    } else if (bd == 2) {
        res = listarResBIN(&n);
    }
    if (bd > 0) {
        int i;
        for (i = 0; i < n; i++) {
            printf("COD: %d \n", res[i].codigo);
            printf("DATA INI: %d /%d /%d\n", res[i].DataIn.dia, res[i].DataIn.mes, res[i].DataIn.ano);
            printf("DATA FIM: %d /%d /%d\n", res[i].DataFin.dia, res[i].DataFin.mes, res[i].DataFin.ano);
            printf("HOSPEDES: %d \n", res[i].codH);
            printf("Acomodação: %d \n", res[i].codA);
            printf("\n");
        }

        free(res);

        /*
            FILE *cad;
            char texto[20];
            cad = fopen("arquivos\\ReservaTXT", "r");
            while (fgets(texto, 20, cad) != NULL) {
                printf("%s", texto);
            }
            fclose(cad);
         */
    }
}

int contarLinhasResTXT() {// contar linhas arq txt

    FILE *listOperador;
    int numOL = 0, c, numF;

    listOperador = fopen("arquivos\\ReservaTXT", "r");
    if (listOperador == NULL) {
        listOperador = fopen("arquivos\\ReservaTXT", "w+");
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
    numF = numOL / 9; //divide por 18 que é o número de dados do hotel
    fclose(listOperador);
    free(listOperador);

    return numF;


    
}


//Daniel

void reservar2() {
    Data dataIn, dataFim;
    int bd = listar();
    if (bd > 0) {
        int quant, num = 0, cod, num2, numH;
        int r;
        Acomodacao *aco;
        Categoria *cat;
        Hospede *hos;
        Reserva res;
        int achou = 0;
        int achouD = 0;
        printf("Entre com a data Desejada: ");
        printf("Digita o dia da data de início da reserva:\n");
        scanf("%d%*c", &dataIn.dia);
        printf("Digita o mes da data de início da reserva:\n");
        scanf("%d%*c", &dataIn.mes);
        printf("Digita o ano da data de início da reserva:\n");
        scanf("%d%*c", &dataIn.ano);

        printf("Digita o dia da data do fim da reserva:\n");
        scanf("%d%*c", &dataFim.dia);
        printf("Digita o mes da data do fim da reserva:\n");
        scanf("%d%*c", &dataFim.mes);
        printf("Digita o ano da data do fim da reserva:\n");
        scanf("%d%*c", &dataFim.ano);

        aco = listarAcomodacoesDisponiveis(dataIn, dataFim, &num);
        if (bd == 1) {
            numH = getNumHospedes();
            hos = getAllHospedesTXT(numH);
            cat = listarCategoriaTXT();
            num2 = numLinhasCategoria();
        } else {
            getAllHospedesBIN(&numH);
            listarCategoriaBIN(&num2);
        }
        res.codigo = 1;
        res.DataIn = dataIn;
        res.DataFin = dataFim;
        if (num > 0) {
            int i, j;
            for (i = 0; i < num; i++) {
                printf("\n**************** %d *****************\n", i);
                printf("COD: %d\n", aco[i].codigo);
                printf("DESCRIÇÃO: %s\n", aco[i].descricao);
                printf("STATUS: %s\n", aco[i].status);
                achou++;
                for (j = 0; j < num2; j++) {
                    if (aco[i].categoria.codigo == cat[j].codigo) {
                        printf("CATEGORIAS: %s\n", cat[j].descricao);
                        printf("FACILIDADES: %s\n", cat[j].facilidade);
                        printf("VALOR DIARIA: %f\n", cat[j].valorDiario);
                        printf("N° PESSOAS: %d\n", cat[j].quantidadePessoas);
                    }

                }

            }

            int aux2 = 0;
            while (aux2 == 0) {
                printf("Entre com o codigo da acomodação desejada: ");
                scanf("%d*c", &cod);
                for (i = 0; i < num; i++) {
                    if (aco[i].codigo == cod) {
                        for (j = 0; j < num2; j++) {
                            if (aco[i].categoria.codigo == cat[j].codigo) {
                                aux2 = 1;
                                aco[i].categoria = cat[j];
                                res.acomodacao = aco[i];
                            }
                        }
                    }
                }
                if (aux2 == 0) {
                    printf("\nCodigo não encontrado!!\n");
                }
            }
            listarHospedesControl();
            aux2 = 0;
            while (aux2 == 0) {
                printf("Entre com o codigo do hospede desejado: ");
                scanf("%d*c", &cod);
                for (i = 0; i < numH; i++) {
                    printf("%d \n", hos[i].codigo);
                    if (hos[i].codigo == cod) {
                        aux2 = 1;
                        res.hospede = hos[i];
                    }
                }
                if (aux2 == 0) {
                    printf("\nCodigo não encontrado!!\n");
                }
            }
            int retorno = cadastrarReservaTXT(res);
            if (retorno == 1) {
                printf("Reserva Cadastrada com Sucesso!!\n");
            } else {
                printf("Erro ao cadastrar!\n");
            }
            //teste(&res);

        } else {
            printf("Nenhuma Acomodação disponivel para esta data!!\n");
        }
        free(aco);
        free(cat);
        free(hos);
    } else {
        printf("\nAltere a opção de salvamento em (MENU Principal->9 . Configurações-> 1. Op de BD.)\n");
    }

}
//Tales

void * mostrarReservaBIN(int *numLinha) {

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

    Reserva re;
    //instancia vetor com tamanho 1 printf("DEBUG 2.5\n");
    Reserva *res = (Reserva*) calloc(1, sizeof (Reserva));
    //pega a primeira linha se existir

    int r = fread(&re, sizeof (Reserva), 1, arquivo);
    if (r > 0) {
        do {
            //soma a +1 no tamanho do vetor o qual comessa com 0
            *numLinha = (*numLinha) + 1;
            // realoca o vetor com o tamanho numLinha, a arqa interação ele realoca um a mais
            res = realloc(res, *numLinha * sizeof (Reserva));
            //adicionar o struct o vetor,(numLinha -1) pois o vetor comessa sempre por 0
            res[(*numLinha) - 1] = re;
            //pega o proximo indice, se existir
            fread(&re, sizeof (Reserva), 1, arquivo);
            //verifica se chegou no fim do arquivo
        } while (!feof(arquivo));
    } else {
        return NULL;
    }
    //fecha arquivo
    fclose(arquivo);
    //libera memoria
    free(arquivo);

    return res;
}

void mostrarReservas() {
    int numR = numLinhasReserva();
    Reserva *res = listarReservaTXT();
    int i;
    for (i = 0; i < numR; i++) {
        printf("COD : %d \n", res[i].codigo);
        printf("Data Inicio: %d/%d/%d \n", res[i].DataIn.dia, res[i].DataIn.mes, res[i].DataIn.ano);
        printf("Data Fim: %d/%d/%d \n", res[i].DataFin.dia, res[i].DataFin.mes, res[i].DataFin.ano);
        printf("----Acomodação---\n");
        printf("cod Aco: %d\n", res[i].acomodacao.codigo);
        printf("DESCRIÇÃO: %s\n", res[i].acomodacao.descricao);
        printf("STATUS: %s\n", res[i].acomodacao.status);
        printf("------Hospede--------\n");
        printf("COD: %d\n", res[i].hospede.codigo);
        printf("NOME: %s\n", res[i].hospede.nome);
        printf("CPF: %s\n", res[i].hospede.cpf);
        printf("FONE: %s\n", res[i].hospede.telefone);
        printf("EMAIL: %s\n", res[i].hospede.email);
        printf("SEXO: %c\n", res[i].hospede.sexo);
        printf("ESTADO CIVIL: %s\n", res[i].hospede.esCivil);
        //DATA
        printf("DATA NASC: %d / %d / %d \n", res[i].hospede.dataNascimento.dia, res[i].hospede.dataNascimento.mes, res[i].hospede.dataNascimento.ano);
        //ENDEREÇO
        printf("COD ENDER: %d\n", res[i].hospede.endereco.codigo);
        printf("BAIRRO: %s\n", res[i].hospede.endereco.bairro);
        printf("CEP: %s\n", res[i].hospede.endereco.cep);
        printf("CIDADE: %s\n", res[i].hospede.endereco.cidade);
        printf("LOGRADOURO: %s\n", res[i].hospede.endereco.logradouro);
        printf("NUMERO: %d\n", res[i].hospede.endereco.numero);
        printf("UF: %s\n", res[i].hospede.endereco.uf);


    }

}

Acomodacao* listarAcomodacoesDisponiveis(Data in, Data fin, int *quantidadeAcoDisponiveis) {
    int bd = listar();
    Acomodacao *aco;
    Reserva * res;
    int numA;
    int numR;
    if (bd == 1) {
        aco = listarAcomodacaoTXT();
        res = listarReservaTXT();
        numA = numLinhasAcomodacao();
        numR = numLinhasReserva();
    } else {
        aco = listarAcomodacaoBIN(&numA);
        res = listarReservaBIN(&numR);
    }
    Acomodacao *aco2 = (Acomodacao*) calloc(numA, sizeof (Acomodacao));
    //printf("numA = %d ,numR %d ")
    int i, j = 0, k = 0, aux = 0;
    for (i = 0; i < numA; i++) {
        // aco2 = realloc(aco, *numLinha * sizeof (Acomodacao));
        for (j = 0; j < numR; j++) {
            if (aco[i].codigo == res[j].acomodacao.codigo) {
                aux = 1;
                if (dataDisponivel(in, fin, res[j].DataIn, res[j].DataFin) == 1) {
                    aco2[*quantidadeAcoDisponiveis] = aco[i];
                    *quantidadeAcoDisponiveis = (*quantidadeAcoDisponiveis) + 1;
                }
            }
        }
        if (aux == 0) {
            aco2[*quantidadeAcoDisponiveis] = aco[i];
            *quantidadeAcoDisponiveis = (*quantidadeAcoDisponiveis) + 1;
        }
        aux = 0;
    }
    free(res);
    return aco2;

}
