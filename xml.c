/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   xml.c
 * Author: Daniel
 *
 * Created on 31 de Março de 2021, 23:29
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Acomodacao.h"
#include "Categoria.h"
#include "Tag.h"
#include "Caixa.h"
#include "CheckIn.h"
#include "CheckOut.h"
#include "ContaPagar.h"
#include "ContaReceber.h"
#include "Fornecedor.h"
#include "SalvametoBD.h"
#include "FornecedorSUB.h"
#include "xml.h"

int importarDadosXMLparaTXT(char caminho[], int tab[], int qtd) {
    Acomodacao *aco;
    Categoria *cat;
    Caixa *cai;
    ContaPagar *cp;
    ContaReceber *cr;
    CheckIn *ci;
    CheckOut *cu;
    Fornecedor *f;
    int numACO, numCAT, numCAI, numCP, numCR, numCI, numCU, numF;
    int i;
    for (i = 0; i < qtd; i++) {
        switch (tab[i]) {
            case 1:
                aco = getAcomodacaoXML(caminho, &numACO);
                salvarAcomodacaoTXT(aco, numACO);
                break;
            case 2:
                cat = getCategoriaXML(caminho, &numCAT);
                salvarCategoriaTXT(cat, numCAT);
                break;
            case 3:
                cai = getCaixaXML(caminho, &numCAI);
                salvarCaixaTXT(cai, numCAI);
                break;
            case 4:
                ci = getCheckInXML(caminho, &numCI);
                salvarCheckInTXT(ci, numCI);
                break;
            case 5:
                cu = getCheckOutXML(caminho, &numCU);
                salvarCheckOutTXT(cu, numCU);
                break;
            case 6:
                cp = getContaPagarXML(caminho, &numCP);
                salvarContasPagarTXT(cp, numCP);
                break;
            case 7:
                cr = getContaReceberXML(caminho, &numCR);
                salvarContaReceberTXT(cr, numCR);
                break;
            case 8:
                f = getFornecedoXML(caminho, &numF);
                salvarFornecedorTXT(f, numF);
                break;
            case 9:

                break;
            case 10:

                break;
            case 11:

                break;
            case 12:

                break;
            case 13:

                break;
            case 14:

                break;
            case 15:

                break;
            case 16:

                break;
            default:

                break;
        }

    }
}

int importarDadosXMLparaBIN(char caminho[], int tab[], int qtd) {
    Acomodacao *aco;
    Categoria *cat;
    Caixa *cai;
    ContaPagar *cp;
    ContaReceber *cr;
    CheckIn *ci;
    CheckOut *cu;
    Fornecedor *f;
    int numACO, numCAT, numCAI, numCP, numCR, numCI, numCU, numF;
    int i;
    for (i = 0; i < qtd; i++) {
        switch (tab[i]) {
            case 1:
                aco = getAcomodacaoXML(caminho, &numACO);
                cadastrarAcomodacaoBIN(aco, numACO);
                break;
            case 2:
                cat = getCategoriaXML(caminho, &numCAT);
                cadastrarCategoriaBIN(cat, numCAT);
                break;
            case 3:
                cai = getCaixaXML(caminho, &numCAI);
                cadastrarCaixaBIN(cai, numCAI);
                break;
            case 4:
                ci = getCheckIN(caminho, &numCI);
                cadastrarCheckInBIN(ci, numCI);
                break;
            case 5:
                cu = getCheckOutXML(caminho, &numCU);
                cadastrarCheckOutBIN(cu, numCU);
                break;
            case 6:
                cp = getContaPagarXML(caminho, &numCP);
                cadastrarContaPagarBIN(cp, numCP);
                break;
            case 7:
                cr = getContaReceberXML(caminho, &numCR);
                cadastrarContaReceberBIN(cr, numCR);
                break;
            case 8:
                f = getFornecedoXML(caminho, &numF);
                cadastrarFornecedorBIN(f, numF);
                break;
            case 9:

                break;
            case 10:

                break;
            case 11:

                break;
            case 12:

                break;
            case 13:

                break;
            case 14:

                break;
            case 15:

                break;
            case 16:

                break;
            default:

                break;
        }

    }

}

char* geraBackupXML(int tab[], int qtd) {
    char *local = "arquivos\\xml\\BackupHotelXML.xml";
    FILE *file;
    // w pra substituir o arquivo
    file = fopen("arquivos\\xml\\BackupHotelXML.xml", "w");
    if (file == NULL) {
        printf("\nErro ao abrir arquivo!!");
        return 0;
    } else {
        fprintf(file, "<?xml version=\"1.0\" encoding=\"UTF - 8\"?>\n");
        fprintf(file, "<dados>\n");
        Acomodacao *aco;
        Categoria *cat;
        Caixa *cai;
        ContaPagar *cp;
        ContaReceber *cr;
        CheckIn *ci;
        CheckOut *cu;
        Fornecedor *f;
        int numACO, numCAT, numCAI, numCP, numCR, numCI, numCU, numF;
        int bd = listar();
        int i;
        for (i = 0; i < qtd; i++) {
            switch (tab[i]) {
                case 1:
                    if (bd == 1) {
                        aco = listarAcomodacaoTXT();
                        numACO = numAcomodacao();
                    } else {
                        aco = listarAcomodacaoBIN(&numACO);
                    }
                    printXMLAcomodacao(aco, numACO, file);
                    break;
                case 2:
                    if (bd == 1) {
                        cat = listarCategoriaTXT();
                        numCAT = numCategoria();
                    } else {
                        cat = listarCategoriaBIN(&numCAT);
                    }
                    printXMLCategoria(cat, numCAT, file);
                    break;
                case 3:
                    if (bd == 1) {
                        cai = listarCaixaTXT();
                        numCAI = numCaixa();
                    } else {
                        cai = listarCaixaBIN(&numCAI);
                    }
                    printXMLCaixa(cai, numCAI, file);
                    break;
                case 4:
                    if (bd == 1) {
                        ci = listarCheckInTXT();
                        numCI = numCheckIn();
                    } else {
                        ci = listarCheckInBIN(&numCI);
                    }
                    printXMLCheckIn(ci, numCI, file);
                    break;
                case 5:
                    if (bd == 1) {
                        cu = listarCheckOutTXT();
                        numCU = numCheckOut();
                    } else {
                        cu = listarCheckOutBIN(&numCU);
                    }
                    printXMLCheckOut(cu, numCU, file);
                    break;
                case 6:
                    if (bd == 1) {
                        numCP = getNumContaPagar();
                        cp = listarContaPagarTXT(numCP);
                    } else {
                        cp = listarContaPagarBIN(&numCP);
                    }
                    printXMLContaPagar(cp, numCP, file);
                    break;
                case 7:
                    if (bd == 1) {
                        cr = listarContaReceberTXT();
                        numCR = numContaReceber();
                    } else {
                        cr = listarContaReceberBIN(&numCR);
                    }
                    printXMLContaReceber(cr, numCR, file);
                    break;
                case 8:
                    if (bd == 1) {
                        f = listarFornecedorTXT();
                        numF = numLinhasFornecedor();
                    } else {
                        f = listarFornecedorBIN(&numF);
                    }
                    printXMLFornecedor(f, numF, file);
                    break;
                case 9:

                    break;
                case 10:

                    break;
                case 11:

                    break;
                case 12:

                    break;
                case 13:

                    break;
                case 14:

                    break;
                case 15:

                    break;
                case 16:

                    break;
                default:

                    break;
            }

        }
        fprintf(file, "</dados>\n");
    }
    // força salvar arquivo
    fflush(file);
    //fecha arquivo
    fclose(file);
    //libera memoria
    free(file);
    return local;
}

Acomodacao* getAcomodacaoXML(char local[], int *num) {
    FILE *file;
    //abrea arquivo para leitura apenas "r"
    file = fopen(local, "r");
    if (file == NULL) {
        //cria arquivo para leitura/escrita se não houver "w+"
        file = fopen(local, "w+");
        if (file == NULL) {
            printf("\nErro ao acessar arquivo de acomodacao\n");
            return NULL;
        }
    }
    Acomodacao *cat = (Acomodacao*) calloc(1, sizeof (Acomodacao));
    if (cat == NULL) {
        printf("Erro ao alocar memoria\n");
    }
    char search[100];
    int i = 0;
    //roda ate o fim do arquivo, lendo linha a linha
    while (fgets(search, 100, file) != NULL) {
        //procura a tag <tabela =acomodação>
        if (comparaString("	<tabela =acomodacao>", search) == 1) {
            while (fgets(search, 100, file) != NULL && comparaString("	</tabela>", search) != 1) {
                //procura a tag <registro>
                if (comparaString("		<registro>", search) == 1) {
                    printf("rodou\n");
                    cat = realloc(cat, (i + 1) * sizeof (Acomodacao));
                    fscanf(file, "			<codigo>%d</codigo>", &cat[i].codigo);
                    fscanf(file, "			<descricao>%[A-Z a-z 0-9 </>]s </descricao>\n", cat[i].descricao);
                    fscanf(file, "			<categoria_codigo>%d</categoria_codigo>\n", &cat[i].categoria.codigo);
                    fscanf(file, "			<status>%[A-Z a-z 0-9 </>]s </status>", cat[i].status);
                    strtok(cat[i].status, "</status>");
                    strtok(cat[i].descricao, "</descricao>");
                    i++;
                }
            }
        }
    }
    *num = i;
    fclose(file);
    //libera memoria
    free(file);
    return cat;
}
//aco.codigo, aco.descricao, aco.categoria.codigo, aco.status

int printXMLAcomodacao(Acomodacao *cat, int num, FILE *cad) {
    // fprintf(cad, "<?xml version=\"1.0\" encoding=\"UTF - 8\"?>\n");
    // fprintf(cad, "<dados>\n");
    if (num > 0) {
        fprintf(cad, "\t<tabela =acomodacao>\n");
        int i;
        // grava todos os dados do vetor no arquivo
        for (i = 0; i < num; i++) {
            fprintf(cad, "\t\t<registro>\n");
            fprintf(cad, "\t\t\t<codigo>%d</codigo>\n", cat[i].codigo);
            fprintf(cad, "\t\t\t<descricao>%s</descricao>\n", cat[i].descricao);
            fprintf(cad, "\t\t\t<categoria_codigo>%d</categoria_codigo>\n", cat[i].categoria.codigo);
            fprintf(cad, "\t\t\t<status>%s</status>\n", cat[i].status);
            fprintf(cad, "\t\t</registro>\n");
        }
        fprintf(cad, "\t</tabela>\n");
        //fprintf(cad, "</dados>\n");
    } else {
        return 0;
    }
    free(cat);
    return 1;
}

Categoria* getCategoriaXML(char local[], int *num) {
    FILE *file;
    //abrea arquivo para leitura apenas "r"
    file = fopen(local, "r");
    if (file == NULL) {
        //cria arquivo para leitura/escrita se não houver "w+"
        file = fopen(local, "w+");
        if (file == NULL) {
            printf("\nErro ao acessar arquivo de categoria\n");
            return NULL;
        }
    }
    Categoria *cat = (Categoria*) calloc(1, sizeof (Categoria));
    if (cat == NULL) {
        printf("Erro ao alocar memoria\n");
    }
    char search[100];
    int i = 0;
    //roda ate o fim do arquivo, lendo linha a linha
    while (fgets(search, 100, file) != NULL) {
        //procura a tag <tabela =categoria>
        if (comparaString("	<tabela =categoria>", search) == 1) {
            while (fgets(search, 100, file) != NULL && comparaString("	</tabela>", search) != 1) {
                //procura a tag <registro>
                if (comparaString("		<registro>", search) == 1) {
                    cat = realloc(cat, (i + 1) * sizeof (Categoria));
                    fscanf(file, "			<codigo>%d</codigo>", &cat[i].codigo);
                    fscanf(file, "			<descricao>%[A-Z a-z 0-9 </>]s</descricao>", cat[i].descricao);
                    fscanf(file, "			<quatidade_pessoas>%d</quatidade_pessoas>", &cat[i].quantidadePessoas);
                    fscanf(file, "			<valor_diaria>%f</valor_diaria>", &cat[i].valorDiario);
                    fscanf(file, "			<facilidade>%[A-Z a-z 0-9 ,.]s</facilidade>", cat[i].facilidade);
                    strtok(cat[i].descricao, "</descricao>");
                    i++;
                }
            }
        }
    }
    *num = i;
    fclose(file);
    //libera memoria
    free(file);
    return cat;
}

int printXMLCategoria(Categoria *cat, int num, FILE *cad) {
    // fprintf(cad, "<?xml version=\"1.0\" encoding=\"UTF - 8\"?>\n");
    // fprintf(cad, "<dados>\n");
    if (num > 0) {
        fprintf(cad, "\t<tabela =categoria>\n");
        int i;
        // grava todos os dados do vetor no arquivo
        for (i = 0; i < num; i++) {
            fprintf(cad, "\t\t<registro>\n");
            fprintf(cad, "\t\t\t<codigo>%d</codigo>\n", cat[i].codigo);
            fprintf(cad, "\t\t\t<descricao>%s</descricao>\n", cat[i].descricao);
            fprintf(cad, "\t\t\t<quatidade_pessoas>%d</quatidade_pessoas>\n", cat[i].quantidadePessoas);
            fprintf(cad, "\t\t\t<valor_diaria>%f</valor_diaria>\n", cat[i].valorDiario);
            fprintf(cad, "\t\t\t<facilidade>%s</facilidade>\n", cat[i].facilidade);
            fprintf(cad, "\t\t</registro>\n");
        }
        fprintf(cad, "\t</tabela>\n");
        //fprintf(cad, "</dados>\n");
    } else {
        return 0;
    }
    // força salvar arquivo
    // fflush(cad);
    //fecha arquivo
    // fclose(cad);
    //libera memoria
    // free(cad);
    free(cat);
    return 1;
}

//caixa

Caixa* getCaixaXML(char local[], int *num) {
    FILE *file;
    //abrea arquivo para leitura apenas "r"
    file = fopen(local, "r");
    if (file == NULL) {
        //cria arquivo para leitura/escrita se não houver "w+"
        file = fopen(local, "w+");
        if (file == NULL) {
            printf("\nErro ao acessar arquivo de acomodacao\n");
            return NULL;
        }
    }
    Caixa *cat = (Caixa*) calloc(1, sizeof (Caixa));
    if (cat == NULL) {
        printf("Erro ao alocar memoria\n");
    }
    char search[100];
    int i = 0;
    //roda ate o fim do arquivo, lendo linha a linha
    while (fgets(search, 100, file) != NULL) {
        //procura a tag <tabela =acomodacao>
        if (comparaString("	<tabela =caixa>", search) == 1) {
            while (fgets(search, 100, file) != NULL && comparaString("	</tabela>", search) != 1) {
                //procura a tag <registro>
                if (comparaString("		<registro>", search) == 1) {
                    cat = realloc(cat, (i + 1) * sizeof (Caixa));
                    fscanf(file, "			<codigo>%d</codigo>", &cat[i].codigo);
                    fscanf(file, "			<data>%d/%d/%d</data>", &cat[i].data.dia, &cat[i].data.mes, &cat[i].data.ano);
                    fscanf(file, "			<valor_inicial>%f</valor_inicial>", &cat[i].valorIn);
                    fscanf(file, "			<valor_final>%f</valor_final>", &cat[i].valorFin);
                    fscanf(file, "			<status>%[A-Z a-z]s</status>", cat[i].status);
                    // strtok(cat[i].status, "</status>");
                    i++;
                }
            }
        }
    }
    *num = i;
    fclose(file);
    //libera memoria
    free(file);
    return cat;
}
//aco.codigo, aco.data.dia, aco.data.mes, aco.data.ano, aco.valorIn, aco.valorFin, aco.status

int printXMLCaixa(Caixa *cat, int num, FILE *cad) {
    // fprintf(cad, "<?xml version=\"1.0\" encoding=\"UTF - 8\"?>\n");
    // fprintf(cad, "<dados>\n");
    if (num > 0) {
        fprintf(cad, "\t<tabela =caixa>\n");
        int i;
        // grava todos os dados do vetor no arquivo
        for (i = 0; i < num; i++) {
            fprintf(cad, "\t\t<registro>\n");
            fprintf(cad, "\t\t\t<codigo>%d</codigo>\n", cat[i].codigo);
            fprintf(cad, "\t\t\t<data>%d/%d/%d</data>\n", cat[i].data.dia, cat[i].data.mes, cat[i].data.ano);
            fprintf(cad, "\t\t\t<valor_inicial>%f</valor_inicial>\n", cat[i].valorIn);
            fprintf(cad, "\t\t\t<valor_final>%f</valor_final>\n", cat[i].valorFin);
            fprintf(cad, "\t\t\t<status>%s</status>\n", cat[i].status);
            fprintf(cad, "\t\t</registro>\n");
        }
        fprintf(cad, "\t</tabela>\n");
        //fprintf(cad, "</dados>\n");
    } else {
        return 0;
    }
    free(cat);
    return 1;
}
// checkin

CheckIn* getCheckInXML(char local[], int *num) {
    FILE *file;
    //abrea arquivo para leitura apenas "r"
    file = fopen(local, "r");
    if (file == NULL) {
        //cria arquivo para leitura/escrita se não houver "w+"
        file = fopen(local, "w+");
        if (file == NULL) {
            printf("\nErro ao acessar arquivo de acomodacao\n");
            return NULL;
        }
    }
    CheckIn *cat = (CheckIn*) calloc(1, sizeof (CheckIn));
    if (cat == NULL) {
        printf("Erro ao alocar memoria\n");
    }
    char search[100];
    int i = 0;
    //roda ate o fim do arquivo, lendo linha a linha
    while (fgets(search, 100, file) != NULL) {
        //procura a tag <tabela =acomodacao>
        if (comparaString("	<tabela =checkin>", search) == 1) {
            while (fgets(search, 100, file) != NULL && comparaString("	</tabela>", search) != 1) {
                //procura a tag <registro>
                if (comparaString("		<registro>", search) == 1) {
                    cat = realloc(cat, (i + 1) * sizeof (CheckIn));
                    fscanf(file, "			<codigo>%d</codigo>", &cat[i].codigo);
                    fscanf(file, "			<valor>%f</valor>\n", &cat[i].valor);
                    fscanf(file, "			<hora>%d:%d:%d</hora>\n", &cat[i].hora.hh, &cat[i].hora.mm, &cat[i].hora.ss);
                    fscanf(file, "			<reserva_codigo>%d</reserva_codigo>\n", &cat[i].reserva.codigo);
                    fscanf(file, "			<caixa_codigo>%d</caixa_codigo>\n", &cat[i].caixa);
                    fscanf(file, "			<status>%[A-Z a-z]s</status>", cat[i].status);
                    //strtok(cat[i].status, "</status>");
                    i++;
                }
            }
        }
    }
    *num = i;
    fclose(file);
    //libera memoria
    free(file);
    return cat;
}

/*int codigo;
    float valor;
    Hora hora;
    char status[10];
    Reserva reserva;
    int caixa;*/

int printXMLCheckIn(CheckIn *cat, int num, FILE *cad) {
    // fprintf(cad, "<?xml version=\"1.0\" encoding=\"UTF - 8\"?>\n");
    // fprintf(cad, "<dados>\n");
    if (num > 0) {
        fprintf(cad, "\t<tabela =checkin>\n");
        int i;
        // grava todos os dados do vetor no arquivo
        for (i = 0; i < num; i++) {
            fprintf(cad, "\t\t<registro>\n");
            fprintf(cad, "\t\t\t<codigo>%d</codigo>\n", cat[i].codigo);
            fprintf(cad, "\t\t\t<valor>%f</valor>\n", cat[i].valor);
            fprintf(cad, "\t\t\t<hora>%d:%d:%d</hora>\n", cat[i].hora.hh, cat[i].hora.mm, cat[i].hora.ss);
            fprintf(cad, "\t\t\t<reserva_codigo>%d</reserva_codigo>\n", cat[i].reserva.codigo);
            fprintf(cad, "\t\t\t<caixa_codigo>%d</caixa_codigo>\n", cat[i].reserva.codigo);
            fprintf(cad, "\t\t\t<status>%s</status>\n", cat[i].status);
            fprintf(cad, "\t\t</registro>\n");
        }
        fprintf(cad, "\t</tabela>\n");
        //fprintf(cad, "</dados>\n");
    } else {
        return 0;
    }
    free(cat);
    return 1;
}
// checkOut

CheckOut* getCheckOutXML(char local[], int *num) {
    FILE *file;
    //abrea arquivo para leitura apenas "r"
    file = fopen(local, "r");
    if (file == NULL) {
        //cria arquivo para leitura/escrita se não houver "w+"
        file = fopen(local, "w+");
        if (file == NULL) {
            printf("\nErro ao acessar arquivo de checkout\n");
            return NULL;
        }
    }
    CheckOut *cat = (CheckOut*) calloc(1, sizeof (CheckOut));
    if (cat == NULL) {
        printf("Erro ao alocar memoria\n");
    }
    char search[100];
    int i = 0;
    //roda ate o fim do arquivo, lendo linha a linha
    while (fgets(search, 100, file) != NULL) {
        //procura a tag <tabela =acomodacao>
        if (comparaString("	<tabela =checkout>", search) == 1) {
            while (fgets(search, 100, file) != NULL && comparaString("	</tabela>", search) != 1) {
                //procura a tag <registro>
                if (comparaString("		<registro>", search) == 1) {
                    cat = realloc(cat, (i + 1) * sizeof (CheckOut));
                    fscanf(file, "			<codigo>%d</codigo>", &cat[i].codigo);
                    //printf("cod %d\n", cat[i].codigo);
                    fscanf(file, "			<valor_total>%f</valor_total>", &cat[i].valorTotal);
                    // printf("cod %f\n", cat[i].valorTotal);
                    fscanf(file, "			<data_saida>%d/%d/%d</data_saida>", &cat[i].saida.dia, &cat[i].saida.mes, &cat[i].saida.ano);
                    // printf(" %d/%d/%d \n", cat[i].saida.dia, cat[i].saida.mes, cat[i].saida.ano);
                    fscanf(file, "			<hospede_codigo>%d</hospede_codigo>", &cat[i].hospede);
                    // printf(" hospede %d \n", cat[i].hospede);
                    fscanf(file, "			<checkin_codigo>%d </checkin_codigo>", &cat[i].checkin.codigo);
                    //printf(" checkin_codigo %d \n", cat[i].checkin.codigo);
                    fscanf(file, "			<checkin_valor>%f</checkin_valor>", &cat[i].checkin.valor);
                    //printf(" checkin valor %f \n", cat[i].checkin.valor);
                    fscanf(file, "			<checkin_status>%[A-Z a-z 0-9 </_>]s</checkin_status>", cat[i].checkin.status);
                    fscanf(file, "			<caixa_codigo>%d</caixa_codigo>", &cat[i].caixa);
                    //printf(" caixa %d \n", cat[i].caixa);
                    strtok(cat[i].checkin.status, "<");
                    i++;
                }
            }
        }
    }
    *num = i;
    fclose(file);
    //libera memoria
    free(file);
    return cat;
}

/*int codigo;
    float valorTotal;
    Data saida;
    int hospede;
    CheckIn checkin;
    int caixa;cat.checkin.valor, cat.checkin.status*/

int printXMLCheckOut(CheckOut *cat, int num, FILE *cad) {
    // fprintf(cad, "<?xml version=\"1.0\" encoding=\"UTF - 8\"?>\n");
    // fprintf(cad, "<dados>\n");
    if (num > 0) {
        fprintf(cad, "\t<tabela =checkout>\n");
        int i;
        // grava todos os dados do vetor no arquivo
        for (i = 0; i < num; i++) {
            fprintf(cad, "\t\t<registro>\n");
            fprintf(cad, "\t\t\t<codigo>%d</codigo>\n", cat[i].codigo);
            fprintf(cad, "\t\t\t<valor_total>%f</valor_total>\n", cat[i].valorTotal);
            fprintf(cad, "\t\t\t<data_saida>%d/%d/%d</data_saida>\n", cat[i].saida.dia, cat[i].saida.mes, cat[i].saida.ano);
            fprintf(cad, "\t\t\t<hospede_codigo>%d</hospede_codigo>\n", cat[i].hospede);
            fprintf(cad, "\t\t\t<checkin_codigo>%d</checkin_codigo>\n", cat[i].checkin.codigo);
            fprintf(cad, "\t\t\t<checkin_valor>%f</checkin_valor>\n", cat[i].checkin.valor);
            fprintf(cad, "\t\t\t<checkin_status>%s</checkin_status>\n", cat[i].checkin.status);
            fprintf(cad, "\t\t\t<caixa_codigo>%d</caixa_codigo>\n", cat[i].caixa);
            fprintf(cad, "\t\t</registro>\n");
        }
        fprintf(cad, "\t</tabela>\n");
        //fprintf(cad, "</dados>\n");
    } else {
        return 0;
    }
    free(cat);
    return 1;
}
//contapagar

ContaPagar* getContaPagarXML(char local[], int *num) {
    FILE *file;
    //abrea arquivo para leitura apenas "r"
    file = fopen(local, "r");
    if (file == NULL) {
        //cria arquivo para leitura/escrita se não houver "w+"
        file = fopen(local, "w+");
        if (file == NULL) {
            printf("\nErro ao acessar arquivo de checkout\n");
            return NULL;
        }
    }
    ContaPagar *cat = (ContaPagar*) calloc(1, sizeof (ContaPagar));
    if (cat == NULL) {
        printf("Erro ao alocar memoria\n");
    }
    char search[100];
    int i = 0;
    //roda ate o fim do arquivo, lendo linha a linha
    while (fgets(search, 100, file) != NULL) {
        //procura a tag <tabela =acomodacao>
        if (comparaString("	<tabela =conta_pagar>", search) == 1) {
            while (fgets(search, 100, file) != NULL && comparaString("	</tabela>", search) != 1) {
                //procura a tag <registro>
                if (comparaString("		<registro>", search) == 1) {
                    cat = realloc(cat, (i + 1) * sizeof (ContaPagar));
                    fscanf(file, "			<codigo>%d</codigo>", &cat[i].codigo);
                    fscanf(file, "			<caixa_codigo>%d</caixa_codigo>", &cat[i].caixa.codigo);
                    fscanf(file, "			<caixa_data>%d/%d/%d</caixa_data>", &cat[i].caixa.data.dia, &cat[i].caixa.data.mes, &cat[i].caixa.data.ano);
                    fscanf(file, "			<fornecedor_codigo>%d</fornecedor_codigo>", &cat[i].codForn);
                    fscanf(file, "			<data>%d/%d/%d</data>\n", &cat[i].data.dia, &cat[i].data.mes, &cat[i].data.ano);
                    fscanf(file, "			<descricao>%[A-Z a-z 0-9 </_>]s</descricao>", cat[i].descricao);
                    fscanf(file, "			<valor>%f</valor>\n", &cat[i].valor);
                    fscanf(file, "			<status>%[A-Z a-z 0-9 </>]s</status>", cat[i].status);
                    strtok(cat[i].status, "<");
                    strtok(cat[i].descricao, "<");
                    i++;
                }
            }
        }
    }
    *num = i;
    fclose(file);
    //libera memoria
    free(file);
    return cat;
}

/* cp.codigo, cp.caixa.codigo, cp.caixa.data.dia, cp.caixa.data.mes, 
 * cp.caixa.data.ano, cp.codForn, cp.data.dia, cp.data.mes, cp.data.ano,
 *  cp.descricao, cp.status, cp.valor*/

int printXMLContaPagar(ContaPagar *cat, int num, FILE *cad) {
    // fprintf(cad, "<?xml version=\"1.0\" encoding=\"UTF - 8\"?>\n");
    // fprintf(cad, "<dados>\n");
    if (num > 0) {
        fprintf(cad, "\t<tabela =conta_pagar>\n");
        int i;
        // grava todos os dados do vetor no arquivo
        for (i = 0; i < num; i++) {
            fprintf(cad, "\t\t<registro>\n");
            fprintf(cad, "\t\t\t<codigo>%d</codigo>\n", cat[i].codigo);
            fprintf(cad, "\t\t\t<caixa_codigo>%d</caixa_codigo>\n", cat[i].caixa.codigo);
            fprintf(cad, "\t\t\t<caixa_data>%d/%d/%d</caixa_data>\n", cat[i].caixa.data.dia, cat[i].caixa.data.mes, cat[i].caixa.data.ano);
            fprintf(cad, "\t\t\t<fornecedor_codigo>%d</fornecedor_codigo>\n", cat[i].codForn);
            fprintf(cad, "\t\t\t<data>%d/%d/%d</data>\n", cat[i].data.dia, cat[i].data.mes, cat[i].data.ano);
            fprintf(cad, "\t\t\t<descricao>%s</descricao>\n", cat[i].descricao);
            fprintf(cad, "\t\t\t<valor>%f</valor>\n", cat[i].valor);
            fprintf(cad, "\t\t\t<status>%s</status>\n", cat[i].status);
            fprintf(cad, "\t\t</registro>\n");
        }
        fprintf(cad, "\t</tabela>\n");
        //fprintf(cad, "</dados>\n");
    } else {
        return 0;
    }
    free(cat);
    return 1;
}
//contaReceber

ContaReceber* getContaReceberXML(char local[], int *num) {
    FILE *file;
    //abrea arquivo para leitura apenas "r"
    file = fopen(local, "r");
    if (file == NULL) {
        //cria arquivo para leitura/escrita se não houver "w+"
        file = fopen(local, "w+");
        if (file == NULL) {
            printf("\nErro ao acessar arquivo de checkout\n");
            return NULL;
        }
    }
    ContaReceber *cat = (ContaReceber*) calloc(1, sizeof (ContaReceber));
    if (cat == NULL) {
        printf("Erro ao alocar memoria\n");
    }
    char search[100];
    int i = 0;
    //roda ate o fim do arquivo, lendo linha a linha
    while (fgets(search, 100, file) != NULL) {
        //procura a tag <tabela =acomodacao>
        if (comparaString("	<tabela =conta_receber>", search) == 1) {
            while (fgets(search, 100, file) != NULL && comparaString("	</tabela>", search) != 1) {
                //procura a tag <registro>
                if (comparaString("		<registro>", search) == 1) {
                    cat = realloc(cat, (i + 1) * sizeof (ContaReceber));
                    fscanf(file, "			<codigo>%d</codigo>", &cat[i].codigo);
                    fscanf(file, "			<valor>%f</valor>", &cat[i].valor);
                    fscanf(file, "			<data>%d/%d/%d</data>", &cat[i].data.dia, &cat[i].data.mes, &cat[i].data.ano);
                    fscanf(file, "			<caixa_codigo>%d</caixa_codigo>", &cat[i].caixa);
                    fscanf(file, "			<pagamento>%[A-Z a-z 0-9 </_>]s</pagamento>\n", cat[i].pagamento);
                    fscanf(file, "			<status>%[A-Z a-z 0-9 </_>]s</status>\n", cat[i].status);
                    strtok(cat[i].status, "<");
                    strtok(cat[i].pagamento, "<");
                    i++;
                }
            }
        }
    }
    *num = i;
    fclose(file);
    //libera memoria
    free(file);
    return cat;
}

/* cat.codigo, cat.valor, cat.data.dia, cat.data.mes, cat.data.ano, cat.status, cat.pagamento, cat.caixa*/

int printXMLContaReceber(ContaReceber *cat, int num, FILE *cad) {
    // fprintf(cad, "<?xml version=\"1.0\" encoding=\"UTF - 8\"?>\n");
    // fprintf(cad, "<dados>\n");
    if (num > 0) {
        fprintf(cad, "\t<tabela =conta_receber>\n");
        int i;
        // grava todos os dados do vetor no arquivo
        for (i = 0; i < num; i++) {
            fprintf(cad, "\t\t<registro>\n");
            fprintf(cad, "\t\t\t<codigo>%d</codigo>\n", cat[i].codigo);
            fprintf(cad, "\t\t\t<valor>%f</valor>\n", cat[i].valor);
            fprintf(cad, "\t\t\t<data>%d/%d/%d</data>\n", cat[i].data.dia, cat[i].data.mes, cat[i].data.ano);
            fprintf(cad, "\t\t\t<caixa_codigo>%d</caixa_codigo>\n", cat[i].caixa);
            fprintf(cad, "\t\t\t<pagamento>%s</pagamento>\n", cat[i].pagamento);
            fprintf(cad, "\t\t\t<status>%s</status>\n", cat[i].status);
            fprintf(cad, "\t\t</registro>\n");
        }
        fprintf(cad, "\t</tabela>\n");
        //fprintf(cad, "</dados>\n");
    } else {
        return 0;
    }
    free(cat);
    return 1;
}
//contaReceber

/*  forn.nomeFantazia, forn.razaoSocial, forn.inscricaoEstadual,
            forn.cnpj, forn.telefone, forn.email, forn.endereco.logradouro,
 *  forn.endereco.numero, forn.endereco.bairro,
            forn.endereco.cidade, forn.endereco.cep, forn.endereco.uf); // f*/

int printXMLFornecedor(Fornecedor *cat, int num, FILE *cad) {
    // fprintf(cad, "<?xml version=\"1.0\" encoding=\"UTF - 8\"?>\n");
    // fprintf(cad, "<dados>\n");
    if (num > 0) {
        fprintf(cad, "\t<tabela =fornecedor>\n");
        int i;
        // grava todos os dados do vetor no arquivo
        for (i = 0; i < num; i++) {
            fprintf(cad, "\t\t<registro>\n");
            fprintf(cad, "\t\t\t<codigo>%d</codigo>\n", cat[i].codigo);
            fprintf(cad, "\t\t\t<fantazia>%s</fantazia>\n", cat[i].nomeFantazia);
            fprintf(cad, "\t\t\t<razao_social>%s</razao_social>\n", cat[i].razaoSocial);
            fprintf(cad, "\t\t\t<inscricao_estadual>%s</inscricao_estadual>\n", cat[i].inscricaoEstadual);
            fprintf(cad, "\t\t\t<cnpj>%s</cnpj>\n", cat[i].cnpj);
            fprintf(cad, "\t\t\t<telefone>%s</telefone>\n", cat[i].telefone);
            fprintf(cad, "\t\t\t<email>%s</email>\n", cat[i].email);
            fprintf(cad, "\t\t\t<logradouro>%s</logradouro>\n", cat[i].endereco.logradouro);
            fprintf(cad, "\t\t\t<numero>%d</numero>\n", cat[i].endereco.numero);
            fprintf(cad, "\t\t\t<cidade>%s</cidade>\n", cat[i].endereco.cidade);
            fprintf(cad, "\t\t\t<bairro>%s</bairro>\n", cat[i].endereco.bairro);
            fprintf(cad, "\t\t\t<cep>%s</cep>\n", cat[i].endereco.cep);
            fprintf(cad, "\t\t\t<uf>%s</uf>\n", cat[i].endereco.uf);
            fprintf(cad, "\t\t</registro>\n");
        }
        fprintf(cad, "\t</tabela>\n");
        //fprintf(cad, "</dados>\n");
    } else {
        return 0;
    }
    free(cat);
    return 1;
}

Fornecedor* getFornecedoXML(char local[], int *num) {
    FILE *file;
    //abrea arquivo para leitura apenas "r"
    file = fopen(local, "r");
    if (file == NULL) {
        //cria arquivo para leitura/escrita se não houver "w+"
        file = fopen(local, "w+");
        if (file == NULL) {
            printf("\nErro ao acessar arquivo de checkout\n");
            return NULL;
        }
    }
    Fornecedor *cat = (Fornecedor*) calloc(1, sizeof (Fornecedor));
    if (cat == NULL) {
        printf("Erro ao alocar memoria\n");
    }
    char search[100];
    int i = 0, j;
    //roda ate o fim do arquivo, lendo linha a linha
    while (fgets(search, 100, file) != NULL) {
        //procura a tag <tabela =acomodacao>
        if (comparaString("	<tabela =fornecedor>", search) == 1) {
            while (fgets(search, 100, file) != NULL && comparaString("	</tabela>", search) != 1) {
                //procura a tag <registro>
                if (comparaString("		<registro>", search) == 1) {
                    cat = realloc(cat, (i + 1) * sizeof (Fornecedor));
                    if (cat == NULL) {
                        printf("memoria insuficiente!!");
                    }
                    fscanf(file, "			<codigo>%d</codigo>", &cat[i].codigo);
                    fscanf(file, "			<fantazia>%[A-Z a-z 0-9 . , _</>]s</fantazia>", cat[i].nomeFantazia);
                    fscanf(file, "			<razao_social>%[A-Z a-z _</>]s</razao_social>", cat[i].razaoSocial);
                    fscanf(file, "			<inscricao_estadual>%[A-Z a-z 0-9 . , _</>]s</inscricao_estadual>", cat[i].inscricaoEstadual);
                    fscanf(file, "			<cnpj>%[A-Z a-z 0-9 .,</>]s</cnpj>", cat[i].cnpj);
                    fscanf(file, "			<telefone>%[A-Z a-z 0-9 </>]s</telefone>", cat[i].telefone);
                    fscanf(file, "			<email>%[A-Z a-z 0-9 </>.@]s</email>", cat[i].email);
                    fscanf(file, "			<logradouro>%[A-Z a-z </>]s </logradouro>", cat[i].endereco.logradouro);
                    fscanf(file, "			<numero> %d </numero>", &j);
                    fscanf(file, "			<cidade>%[A-Z a-z </>]s</cidade>", cat[i].endereco.cidade);
                    fscanf(file, "			<bairro>%[A-Z a-z </>]s</bairro>", cat[i].endereco.bairro);
                    fscanf(file, "			<cep> %[a-z 0-9.</>]s</cep>", cat[i].endereco.cep);
                    fscanf(file, "			<uf>%[A-Z </>]s</uf>", cat[i].endereco.uf);
                    strtok(cat[i].nomeFantazia, "<");
                    strtok(cat[i].razaoSocial, "<");
                    // printf("%d\n", cat[i].codigo);
                    // printf("%s\n", cat[i].nomeFantazia);
                    strtok(cat[i].inscricaoEstadual, "<");
                    // printf("%s\n", cat[i].inscricaoEstadual);
                    strtok(cat[i].cnpj, "<");
                    // printf("%s\n", cat[i].cnpj);
                    strtok(cat[i].telefone, "<");
                    // printf("%s\n", cat[i].telefone);
                    strtok(cat[i].email, "<");
                    //printf("%s\n", cat[i].email);
                    strtok(cat[i].endereco.logradouro, "<");
                    //printf("%s\n", cat[i].endereco.logradouro);
                    cat[i].endereco.numero = j;
                    //printf("%d\n", cat[i].endereco.numero);
                    strtok(cat[i].endereco.cidade, "<");
                    //printf("%s\n", cat[i].endereco.cidade);
                    strtok(cat[i].endereco.bairro, "<");
                    //printf("%s\n", cat[i].endereco.bairro);
                    strtok(cat[i].endereco.cep, "<");
                    //printf("%s\n", cat[i].endereco.cep);
                    strtok(cat[i].endereco.uf, "<");
                    //printf("%s\n", cat[i].endereco.uf);
                    i++;
                }
            }
        }
    }
    *num = i;
    fclose(file);
    //libera memoria
    free(file);
    return cat;
}