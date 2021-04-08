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


#include "Hospede.h"
#include "Hotel.h"
#include "OperadorSistema.h"

#include "SalvametoBD.h"
#include "FornecedorSUB.h"
#include "xml.h"
#include "Produto.h"
#include "ProdutoReserva.h"
#include "VendaProduto.h"

int importarDadosXMLparaTXT(char caminho[], int tab[], int qtd) {
    Acomodacao *aco;
    Categoria *cat;
    Caixa *cai;
    ContaPagar *cp;
    ContaReceber *cr;
    CheckIn *ci;
    CheckOut *cu;
    Fornecedor *f;
    
    Hospede *hos;
    Hotel *h;
    OperadorSistema *op;
    Produto *prod;
    ProdutoReserva *pr;
    Reserva *res;
    VendaProduto *vpr;
    Venda *ven;
    
    
    int numACO, numCAT, numCAI, numCP, numCR, numCI, numCU, numF, numHOS, numH, numOP,
            numPROD, numPR, numRES, numVPR, numVEN;
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
                hos = getHospedeXML(caminho, &numHOS);
                salvarHospedeTXT(hos, numHOS);
                break;
            case 10:
                h = getHotelXML(caminho, &numH);
                salvarHotelTXT(h, numH);
                break;
            case 11:
                op = getOperadorSistemaXML(caminho, &numOP);
                salvarOperadorTXT(op, numOP);
                break;
            case 12:
                prod = getProdutoXML(caminho, &numPROD);
                salvarProdutoTXT(prod, numPROD);
                break;
            case 13:
                pr = getProdutoReservaXML(caminho, &numPR);
                salvarProdutoReservaTXT(pr, numPR);
                break;
            case 14:
                res = getReservaXML(caminho, &numRES);
                salvarReservaTXT(res, numRES);
                break;
            case 15:
                vpr = getVendaProdutoXML(caminho, &numVPR);
                salvarVendaProdutoTXT(vpr, numVPR);
                break;
            case 16:
                ven = getVendaXML(caminho, &numVEN);
                salvarVendaTXT(ven, numVEN);
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
    
    Hospede *hos;
    Hotel *h;
    OperadorSistema *op;
    Produto *prod;
    ProdutoReserva *pr;
    Reserva *res;
    VendaProduto *vpr;
    Venda *ven;
    
    int numACO, numCAT, numCAI, numCP, numCR, numCI, numCU, numF, numHOS, numH, numOP,
            numPROD, numPR, numRES, numVPR, numVEN;
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
                hos = getHospedeXML(caminho, &numHOS);
                cadastrarHospedeBIN(hos, numHOS);
                break;
            case 10:
                h = getHotelXML(caminho, &numH);
                cadastrarHotelBin(h, numH);
                break;
            case 11:
                op = getOperadorSistemaXML(caminho, &numOP);
                cadastrarOpBIN(op, numOP);
                break;
            case 12:
                prod = getProdutoXML(caminho, &numPROD);
                cadastrarProdutoBin(prod, numPROD);
                break;
            case 13:
                pr = getProdutoReservaXML(caminho, &numPR);
                salvarProdutoReservaBIN(pr, numPR);
                break;
            case 14:
                res = getReservaXML(caminho, &numRES);
                cadastrarReservaBIN(res, numRES);
                break;
            case 15:
                vpr = getVendaProdutoXML(caminho, &numVPR);
                salvarVendaProdutoBIN(vpr, numVPR);
                break;
            case 16:
                ven = getVendaXML(caminho, &numVEN);
                salvarVendaBIN(ven, numVEN);
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
        
        Hospede *hos;
        Hotel *h;
        OperadorSistema *op;
        Produto *prod;
        ProdutoReserva *pr;
        Reserva *res;
        VendaProduto *vpr;
        Venda *ven;
        
        int numACO, numCAT, numCAI, numCP, numCR, numCI, numCU, numF, numHOS, numH, numOP,
                numPROD, numPR, numRES, numVPR, numVEN;
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
                    if (bd == 1) {
                      numHOS = getNumHospedes();
                      hos = getAllHospedesTXT(numHOS);
                    } else {
                      hos = getAllHospedesBIN(&numHOS);
                    }
                    printXMLHospede(hos, numHOS, file);
                    break;
                case 10:
                    if (bd == 1) {
                      h = listarHTXT();
                      numH = contarLinhasHotelTXT();
                    } else {
                      h = listarHotelBIN(&numH);
                    }
                    printXMLHotel(h, numH, file);
                    break;
                case 11:
                    if (bd == 1) {
                      op = listarOpTXT();
                      numOP = contarLinhasTXT();
                    } else {
                      op = listarOpBIN(&numOP);
                    }
                    printXMLOperadorSistema(op, numOP, file);
                    break;
                case 12:
                    if(bd == 1) {
                      numPROD = getNumProdConsumo();
                      prod = getAllProdutoTXT(numPROD);
                    } else {
                      prod = getAllProdutoBIN(&numPROD);
                    }
                    printXMLProduto(prod, numPROD, file);
                    break;
                case 13:
                    if(bd == 1) {
                      numPR = getNumProdReserva();
                      pr = getAllProdutoReservaTXT(numPR);
                    } else {
                      pr = getAllProdutoReservaBIN(&numPR);
                    }
                    printXMLProdutoReserva(pr, numPR, file);
                    break;
                case 14:
                    if(bd == 1) {
                      numRES = numReserva();
                      res = listarResTXT();
                    } else {
                      res = listarResBIN(&numRES);
                    }
                    printXMLReserva(res, numRES, file);
                    break;
                case 15:
                    if(bd == 1) {
                      numVPR = getNumVendaProduto();
                      vpr = listarVendaProdutoTXT();
                    } else {
                      vpr = listarVendaProdutoBIN(&numVPR);
                    }
                    printXMLVendaProduto(vpr, numVPR, file);
                    break;
                case 16:
                    if(bd == 1) {
                      numVEN = numVendas();
                      ven = listarVendaTXT(numVEN);
                    } else {
                      ven = listarVendaBIN(&numVEN);
                    }
                    printXMLVenda(ven, numVEN, file);
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
            printf("\nErro ao acessar arquivo de caixa\n");
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
            printf("\nErro ao acessar arquivo de checkin\n");
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
            printf("\nErro ao acessar arquivo de conta a pagar\n");
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
            printf("\nErro ao acessar arquivo de conta a receber\n");
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
            printf("\nErro ao acessar arquivo de fornecedor\n");
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
        //procura a tag <tabela =fornecedor>
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

Hospede* getHospedeXML(char local[], int *num) {
  FILE *file;
  //abre arquivo para leitura apenar "r"
  file = fopen(local, "r");
  if (file == NULL) {
    //cria arquivo para leitura/escrita se não houver "w+"
    file = fopen(local, "w+");
    if (file == NULL) {
      printf("\nErro ao acessar arquivo de hospede\n");
      return NULL;
    }
  }
  Hospede *cat = (Hospede*) calloc(1, sizeof (Hospede));
  if (cat == NULL) {
    printf("Erro ao alocar memoria\n");
  }
  char search[100];
  int i = 0, j;
  //roda até o fim do arquivo, lendo linha a linha
  while(fgets(search, 100, file) != NULL) {
    //procura a tag <tabela =hospede>
    if (comparaString("	    <tabela =hospede>", search) == 1) {
      while(fgets(search, 100, file) != NULL && comparaString("  </tabela>", search) != 1) {
        //procura a tag <registro>
        if (comparaString("		<registro>", search) == 1) {
          cat = realloc(cat, (i + 1) * sizeof (Hospede));
          if (cat == NULL) {
            printf("memoria insuficiente!!");
          }
          fscanf(file, "			<codigo>%d</codigo>", &cat[i].codigo);          
          fscanf(file, "			<nome>%[A-Z a-z </>]s</nome>", cat[i].nome);
          fscanf(file, "			<cpf>%[A-Z a-z 0-9 .,</>]s</cpf>", &cat[i].cpf);
          fscanf(file, "			<telefone>%[A-Z a-z 0-9 </>]s</telefone>", cat[i].telefone);
          fscanf(file, "			<email>%[A-Z a-z 0-9 </>.@]s</email>", cat[i].email);
          fscanf(file, "			<sexo>%c</sexo>", &cat[i].sexo);
          fscanf(file, "			<estado_civil>%[A-Z a-z </>]s</estado_civil>", &cat[i].esCivil);
          fscanf(file, "			<dia_nascimento>%d</dia_nascimento>", &cat[i].dataNascimento.dia);
          fscanf(file, "			<mes_nascimento>%d</mes_nascimento>", &cat[i].dataNascimento.mes);
          fscanf(file, "			<ano_nascimento>%d</ano_nascimento>", &cat[i].dataNascimento.ano);
          fscanf(file, "			<logradouro>%[A-Z a-z </>]s </logradouro>", cat[i].endereco.logradouro);
          fscanf(file, "			<numero> %d </numero>", &j);
          fscanf(file, "			<cidade>%[A-Z a-z </>]s</cidade>", cat[i].endereco.cidade);
          fscanf(file, "			<bairro>%[A-Z a-z </>]s</bairro>", cat[i].endereco.bairro);
          fscanf(file, "			<cep> %[a-z 0-9.</>]s</cep>", cat[i].endereco.cep);
          fscanf(file, "			<uf>%[A-Z </>]s</uf>", cat[i].endereco.uf);
          strtok(cat[i].nome, "<");
          //printf("%s\n", cat[i].nome);
          strtok(cat[i].cpf, "<");
          //printf("%s\n", cat[i].cpf);
          strtok(cat[i].telefone, "<");
          //printf("%s\n", cat[i].telefone);
          strtok(cat[i].email, "<");
          //printf("%s\n", cat[i].email);
          strtok(cat[i].esCivil, "<");
          //printf("%s\n", cat[i].esCivil);
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
  //libera memória
  free(file);
  return cat;
}

int printXMLHospede(Hospede *cat, int num, FILE *cad) {
  if (num > 0) {
    fprintf(cad, "\t<tabela =hospede>\n");
    int i;
    // grava todos os dados do vetor no arquivo
    for (i = 0; i< num; i++) {
      fprintf(cad, "\t\t<registro>\n");
      fprintf(cad, "\t\t\t<codigo>%d</codigo>\n", cat[i].codigo);          
      fprintf(cad, "\t\t\t<nome>%s</nome>\n", cat[i].nome);
      fprintf(cad, "\t\t\t<cpf>%s</cpf>\n", cat[i].cpf);
      fprintf(cad, "\t\t\t<telefone>%s</telefone>\n", &cat[i].telefone);
      fprintf(cad, "\t\t\t<email>%s</email>\n", cat[i].email);
      fprintf(cad, "\t\t\t<sexo>%c</sexo>\n", cat[i].sexo);
      fprintf(cad, "\t\t\t<estado_civil>%s</estado_civil>\n", cat[i].esCivil);
      fprintf(cad, "\t\t\t<dia_nascimento>%d</dia_nascimento>\n", cat[i].dataNascimento.dia);
      fprintf(cad, "\t\t\t<mes_nascimento>%d</mes_nascimento>\n", cat[i].dataNascimento.mes);
      fprintf(cad, "\t\t\t<ano_nascimento>%d</ano_nascimento>\n", cat[i].dataNascimento.ano);
      fprintf(cad, "\t\t\t<logradouro>%s</logradouro>\n", cat[i].endereco.logradouro);
      fprintf(cad, "\t\t\t<numero>%d</numero>\n", cat[i].endereco.numero);
      fprintf(cad, "\t\t\t<cidade>%s</cidade>\n", cat[i].endereco.cidade);
      fprintf(cad, "\t\t\t<bairro>%s</bairro>\n", cat[i].endereco.bairro);
      fprintf(cad, "\t\t\t<cep>%s</cep>\n", cat[i].endereco.cep);
      fprintf(cad, "\t\t\t<uf>%s</uf>\n", cat[i].endereco.uf);
      fprintf(cad, "\t\t</registro>\n");
    }
    fprintf(cad, "\t</tabela>\n");
  } else {
    return 0;
  }
  free(cat);
  return 1;
}

Hotel* getHotelXML(char local[], int *num) {
  FILE *file;
  file = fopen(local, "r");
  if (file == NULL) {
    //cria arquivo para leitura/escrita se não houver "w+"
    file = fopen(local, "w+");
    if (file == NULL) {
      printf("\nErro ao acessar arquivo de hotel\n");
      return NULL;
    }
  }
  Hotel *cat = (Hotel*) calloc(1, sizeof (Hotel));
  if (cat == NULL) {
    printf("Erro ao alocar memória\n");
  }
  char search[100];
  int i = 0, j;
  while(fgets(search, 100, file) != NULL) {
    if(comparaString("	    <tabela =hotel>", search) == 1) {
      while(fgets(search, 100, file) != NULL && comparaString("  </tabela>", search) != 1) {
        if (comparaString("		<registro>", search) == 1) {
          cat = realloc(cat, (i + 1) * sizeof (Hotel));
          if (cat == NULL) {
            printf("memoria insuficiente!!!");
          }
          fscanf(file, "			<codigo>%d</codigo>", &cat[i].codigo);
          fscanf(file, "			<cnpj>%[A-Z a-z 0-9 .,</>]s</cnpj>", cat[i].cnpj);
          fscanf(file, "			<email>%[A-Z a-z 0-9 </>.@]s</email>", cat[i].email);
          fscanf(file, "			<inscricao_estadual>%[A-Z a-z 0-9 . , _</>]s</inscricao_estadual>", cat[i].inscricaoEstadual);
          fscanf(file, "			<fantazia>%[A-Z a-z 0-9 . , _</>]s</fantazia>", cat[i].nomeFantazia);
          fscanf(file, "			<nome_responsavel>%[A-Z a-z </>]s</nome_responsavel>", cat[i].nomeResponsavel);
          fscanf(file, "			<telefone>%d</telefone>", &cat[i].telefone);
          fscanf(file, "			<margem_lucro>%f</margem_lucro>\n", &cat[i].margemLucro);
          fscanf(file, "			<checkIn>%[A-Z a-z 0-9 .,</>]s</checkIn>", cat[i].checkIn);
          fscanf(file, "			<checkOut>%[A-Z a-z 0-9 .,</>]s</checkOut>", cat[i].checkOut);
          fscanf(file, "			<tel_res>%[A-Z a-z 0-9 </>]s</tel_res>", cat[i].teleRes);
          fscanf(file, "			<razao_social>%[A-Z a-z 0-9 . , _</>]s</razao_social>", cat[i].razaoSocial);
          fscanf(file, "			<numero>%d</numero>", &j);
          fscanf(file, "			<bairro>%[A-Z a-z </>]s</bairro>", cat[i].bairro);
          fscanf(file, "			<cep>%d</cep>", cat[i].cep);
          fscanf(file, "			<logradouro>%[A-Z a-z </>]s </logradouro>", cat[i].logradouro);
          fscanf(file, "			<uf>%[A-Z </>]s</uf>", cat[i].uf);
          fscanf(file, "			<cidade>%[A-Z a-z </>]s</cidade>", cat[i].cidade);
          
          strtok(cat[i].cnpj, "<");
          strtok(cat[i].email, "<");
          strtok(cat[i].inscricaoEstadual, "<");
          strtok(cat[i].nomeFantazia, "<");
          strtok(cat[i].nomeResponsavel, "<");
          strtok(cat[i].checkIn, "<");
          strtok(cat[i].checkOut, "<");
          strtok(cat[i].teleRes, "<");
          strtok(cat[i].razaoSocial, "<");
          cat[i].numero = j;
          strtok(cat[i].bairro, "<");
          strtok(cat[i].cep, "<");
          strtok(cat[i].logradouro, "<");
          strtok(cat[i].uf, "<");
          strtok(cat[i].cidade, "<");
          i++;
 
        }
      }
    }
  }
  *num = i;
  fclose(file);
  free(file);
  return cat;
}

int printXMLHotel(Hotel *cat, int num, FILE *cad) {
  if (num > 0) {
    fprintf(cad, "\t<tabela =hotel>\n");
    int i;
    for (i = 0; i< num; i++) {
      fprintf(cad, "\t\t<registro>\n");
      fprintf(cad, "\t\t\t<codigo>%d</codigo>\n", cat[i].codigo);
      fprintf(cad, "\t\t\t<cnpj>%s</cnpj>\n", cat[i].cnpj);
      fprintf(cad, "\t\t\t<email>%s</email>\n", cat[i].email);
      fprintf(cad, "\t\t\t<inscricao_estadual>%s</inscricao_estadual>\n", cat[i].inscricaoEstadual);
      fprintf(cad, "\t\t\t<fantazia>%s</fantazia>\n", cat[i].nomeFantazia);
      fprintf(cad, "\t\t\t<nome_responsavel>%s</nome_responsavel>\n", cat[i].nomeResponsavel);
      fprintf(cad, "\t\t\t<telefone>%d</telefone>\n", cat[i].telefone);
      fprintf(cad, "\t\t\t<margem_lucro>%f</margem_lucro>\n", cat[i].margemLucro);
      fprintf(cad, "\t\t\t<checkIn>%s</checkIn>\n", cat[i].checkIn);
      fprintf(cad, "\t\t\t<checkOut>%s</checkOut>\n", cat[i].checkOut);
      fprintf(cad, "\t\t\t<tel_res>%s</tel_res>\n", cat[i].teleRes);
      fprintf(cad, "\t\t\t<razao_social>%s</razao_social>\n", cat[i].razaoSocial);
      fprintf(cad, "\t\t\t<numero>%d</numero>\n", cat[i].numero);
      fprintf(cad, "\t\t\t<bairro>%s</bairro>\n", cat[i].bairro);
      fprintf(cad, "\t\t\t<cep>%d</cep>\n", cat[i].cep);
      fprintf(cad, "\t\t\t<logradouro>%s</logradouro>\n", cat[i].logradouro);
      fprintf(cad, "\t\t\t<uf>%s</uf>\n", cat[i].uf);
      fprintf(cad, "\t\t\t<cidade>%s</cidade>\n", cat[i].cidade);
      fprintf(cad, "\t\t</registro>\n");
    }
    fprintf(cad, "\t</tabela>\n");
  } else {
    return 0;
  }
  free(cat);
  return 1;
}

OperadorSistema* getOperadorSistemaXML(char local[], int *num) {
  FILE *file;
  file = fopen(local, "r");
  if (file == NULL) {
    file = fopen(local, "w+");
    if (file == NULL) {
      printf("\nErro ao acessar arquivo de operadores\n");
      return NULL;
    }
  }
  
  OperadorSistema *cat = (OperadorSistema*) calloc(1, sizeof (OperadorSistema));
    if (cat == NULL) {
      printf("Erro ao alocar memoria\n");
    }
    char search[100];
    int i = 0, j;
    //roda ate o fim do arquivo, lendo linha a linha
    while (fgets(search, 100, file) != NULL) {
      if (comparaString("	<tabela =operador>", search) == 1) {
        while(fgets(search, 100, file) != NULL && comparaString("  </tabela>", search) != 1) {
          if (comparaString("		<registro>", search) == 1) {
            cat = realloc(cat, (i + 1) * sizeof (OperadorSistema));
            if (cat == NULL) {
              printf("memoria insuficiente!!");
            }
            fscanf(file, "			<codigo>%d</codigo>", &cat[i].codigo);
            fscanf(file, "			<nome>%[A-Z a-z </>]s</nome>", cat[i].nome);
            fscanf(file, "			<usuario>%[A-Z a-z 0-9 .,_</>]s</usuario>", &cat[i].usuario);
            fscanf(file, "			<senha>%[A-Z a-z 0-9 .,_</>]s</senha>", &cat[i].senha);
            fscanf(file, "			<permissao>%[0-9 .,_</>]s</permissao>", &cat[i].permicao);

            strtok(cat[i].nome, "<");
            strtok(cat[i].usuario, "<");
            strtok(cat[i].senha, "<");
            strtok(cat[i].permicao, "<");
            i++; 
          }
        }
      }
    }
    *num = i;
    fclose(file);
    free(file);
    return cat;
}

int printXMLOperadorSistema(OperadorSistema *cat, int num, FILE *cad) {
  if (num > 0) {
    fprintf(cad, "\t<tabela =operador>\n");
    int i;
    // grava todos os dados do vetor no arquivo
    for (i = 0; i < num; i++) {
      fprintf(cad, "\t\t<registro>\n");
      fprintf(cad, "\t\t\t<codigo>%d</codigo>\n", cat[i].codigo);
      fprintf(cad, "\t\t\t<nome>%s</nome>\n", cat[i].nome);
      fprintf(cad, "\t\t\t<usuario>%s</usuario>\n", cat[i].usuario);
      fprintf(cad, "\t\t\t<senha>%s</senha>\n", cat[i].senha);
      fprintf(cad, "\t\t\t<permissao>%s</permissao>\n", cat[i].permicao);
      fprintf(cad, "\t\t</registro>\n");
    }
    fprintf(cad, "\t</tabela>\n");
  } else {
    return 0;
  }
  free(cat);
  return 1;
}

Produto* getProdutoXML(char local[], int *num) {
  FILE *file;
  file = fopen(local, "r");
  if (file == NULL) {
    file = fopen(local, "w+");
    if (file == NULL) {
      printf("\nErro ao acessar arquivo de produto\n");
      return NULL;
    }
  }
  Produto *cat = (Produto*) calloc(1, sizeof (Produto));
  if (cat == NULL) {
    printf("Erro ao alocar memoria\n");
  }
  char search[100];
  int i = 0, j;
  //roda até o fim do arquivo, lendo linha a linha
  while(fgets(search, 100, file) != NULL) {
    if (comparaString("	    <tabela =produto>", search) == 1) {
      while(fgets(search, 100, file) != NULL && comparaString("  </tabela>", search) != 1) {
        if (comparaString("		<registro>", search) == 1) {
          cat = realloc(cat, (i + 1) * sizeof (Produto));
          if (cat == NULL) {
            printf("memoria insuficiente!!");
          } 
          fscanf(file, "			<codigo>%d</codigo>", &cat[i].codigo);
          fscanf(file, "			<descricao>%[A-Z a-z 0-9 . , _</>]s</descricao>", cat[i].descricao);
          fscanf(file, "			<estoque>%d</estoque>", &cat[i].estoque);
          fscanf(file, "			<estoque_min>%d</estoque_min>", &cat[i].estoqueMinimo);
          fscanf(file, "			<preco_custo>%f</preco_custo>\n", &cat[i].precoCusto);
          fscanf(file, "			<preco_venda>%f</preco_venda>\n", &cat[i].precoVenda);
          strtok(cat[i].descricao, "<");
          i++;
        }
      }
    }
  }
  *num = i;
  fclose(file);
  free(file);
  return cat;
}

int printXMLProduto(Produto *cat, int num, FILE *cad) {
  if (num > 0) {
    fprintf(cad, "\t<tabela =produto>\n");
    int i;
    // grava todos os dados do vetor no arquivo
    for (i = 0; i < num; i++) {
      fprintf(cad, "\t\t<registro>\n");
      fprintf(cad, "\t\t\t<codigo>%d</codigo>\n", cat[i].codigo);
      fprintf(cad, "\t\t\t<descricao>%s</descricao>\n", cat[i].descricao);
      fprintf(cad, "\t\t\t<estoque>%d</estoque>\n", cat[i].estoque);
      fprintf(cad, "\t\t\t<estoque_min>%d</estoque_min>\n", cat[i].estoqueMinimo);
      fprintf(cad, "\t\t\t<preco_custo>%f</preco_custo>\n", cat[i].precoCusto);
      fprintf(cad, "\t\t\t<preco_venda>%f</preco_venda>\n", cat[i].precoVenda);
      fprintf(cad, "\t\t</registro>\n");
    }
    fprintf(cad, "\t</tabela>\n");
  } else {
    return 0;
  }
  free(cat);
  return 1;
}

ProdutoReserva* getProdutoReservaXML(char local[], int *num) {
  FILE *file;
  file = fopen(local, "r");
  if (file == NULL) {
    file = fopen(local, "w+");
    if (file == NULL) {
      printf("\nErro ao acessar arquivo de produto reserva\n");
      return NULL;
    }
  }
  ProdutoReserva *cat = (ProdutoReserva*) calloc(1, sizeof(ProdutoReserva));
  if (cat == NULL) {
    printf("Erro ao alocar memoria\n");
  }
  char search[100];
  int i = 0;
  while(fgets(search, 100, file) != NULL) {
    if (comparaString("	    <tabela =produto_reserva>", search) == 1) {
      while(fgets(search, 100, file) != NULL && comparaString("  </tabela>", search) != 1) {
        if (comparaString("		<registro>", search) == 1) {
          cat = realloc(cat, (i + 1) * sizeof (Produto));
          if (cat == NULL) {
            printf("memoria insuficiente!!");
          }
          fscanf(file, "			<codigo_prod>%d</codigo_prod>", &cat[i].codProd);
          fscanf(file, "			<codigo_res>%d</codigo_res>", &cat[i].codRes);
          fscanf(file, "			<quantidade>%d</quantidade>", &cat[i].quantidade);
          fscanf(file, "			<data>%d/%d/%d</data>\n", &cat[i].data.dia, &cat[i].data.mes, &cat[i].data.ano);
          i++;
        }
      }  
    }
  }
  *num = i;
  fclose(file);
  free(file);
  return cat;
}
  
int printXMLProdutoReserva(ProdutoReserva *cat, int num, FILE *cad) {
  if (num > 0) {
    fprintf(cad, "\t<tabela =produto_reserva>\n");
    int i;
    for (i = 0; i < num; i++) {
      fprintf(cad, "\t\t<registro>\n");
      fprintf(cad, "\t\t\t<codigo_prod>%d</codigo_prod>\n", cat[i].codProd);
      fprintf(cad, "\t\t\t<codigo_res>%d</codigo_res>\n", cat[i].codRes);
      fprintf(cad, "\t\t\t<quantidade>%d</quantidade>\n", cat[i].quantidade);
      fprintf(cad, "\t\t\t<data>%d/%d/%d</data>\n", cat[i].data.dia, cat[i].data.mes, cat[i].data.ano);
      fprintf(cad, "\t\t</registro>\n");
    }
    fprintf(cad, "\t</tabela>\n");
  } else {
    return 0;
  }
  free(cat);
  return 1;
}

Reserva* getReservaXML(char local[], int *num) {
  FILE *file;
  file = fopen(local, "r");
  if (file == NULL) {
    file = fopen(local, "w+");
    if (file == NULL) {
      printf("\nErro ao acessar arquivo de reserva\n");
      return NULL;
    }
  }
  Reserva *cat = (Reserva*) calloc(1, sizeof(Reserva));
  if (cat == NULL) {
    printf("Erro ao alocar memoria\n");
  }
    char search[100];
  int i = 0;
  while(fgets(search, 100, file) != NULL) {
    if (comparaString("	    <tabela =reserva>", search) == 1) {
      while(fgets(search, 100, file) != NULL && comparaString("  </tabela>", search) != 1) {
        if (comparaString("		<registro>", search) == 1) {
          cat = realloc(cat, (i + 1) * sizeof (Reserva));
          if (cat == NULL) {
            printf("memoria insuficiente!!");
          }
          fscanf(file, "			<codigo>%d</codigo>", &cat[i].codigo);
          fscanf(file, "			<status>%d</status>", &cat[i].status);
          fscanf(file, "			<data_inicial>%d/%d/%d</data_inicial>\n", &cat[i].DataIn.dia, &cat[i].DataIn.mes, &cat[i].DataIn.ano);
          fscanf(file, "			<data_final>%d/%d/%d</data_final>\n", &cat[i].DataFin.dia, &cat[i].DataFin.mes, &cat[i].DataFin.ano);
          fscanf(file, "			<acomodacao_codigo>%d</acomodacao_codigo>", &cat[i].acomodacao.codigo);
          fscanf(file, "			<hospede_codigo>%d</hospede_codigo>", &cat[i].hospede.codigo);
          i++;
        }
      }
    }
  }
  *num = i;
  fclose(file);
  free(file);
  return cat;
}

int printXMLReserva(Reserva *cat, int num, FILE *cad) {
    if (num > 0) {
    fprintf(cad, "\t<tabela =reserva>\n");
    int i;
    for (i = 0; i < num; i++) {
      fprintf(cad, "\t\t<registro>\n");
      fprintf(cad, "\t\t\t<codigo>%d</codigo>\n", cat[i].codigo);
      fprintf(cad, "\t\t\t<status>%d</status>\n", cat[i].status);
      fprintf(cad, "\t\t\t<data_inicial>%d/%d/%d</data_inicial>\n", cat[i].DataIn.dia, cat[i].DataIn.mes, cat[i].DataIn.ano);
      fprintf(cad, "\t\t\t<data_final>%d/%d/%d</data_final>\n", cat[i].DataFin.dia, cat[i].DataFin.mes, cat[i].DataFin.ano);
      fprintf(cad, "\t\t\t<acomodacao_codigo>%d</acomodacao_codigo>\n", cat[i].acomodacao.codigo);
      fprintf(cad, "\t\t\t<hospede_codigo>%d</hospede_codigo>\n", cat[i].hospede.codigo);
      fprintf(cad, "\t\t</registro>\n");
    }
    fprintf(cad, "\t</tabela>\n");
  } else {
    return 0;
  }
  free(cat);
  return 1;
}

VendaProduto* getVendaProdutoXML(char local[], int *num) {
  FILE *file;
  file = fopen(local, "r");
  if (file == NULL) {
    file = fopen(local, "w+");
    if (file == NULL) {
      printf("\nErro ao acessar arquivo de venda produto\n");
      return NULL;
    }
  }
  VendaProduto *cat = (VendaProduto*) calloc(1, sizeof(VendaProduto));
  if (cat == NULL) {
    printf("Erro ao alocar memoria\n");
  }
    char search[100];
  int i = 0;
  while(fgets(search, 100, file) != NULL) {
    if (comparaString("	    <tabela =venda_produto>", search) == 1) {
      while(fgets(search, 100, file) != NULL && comparaString("  </tabela>", search) != 1) {
        if (comparaString("		<registro>", search) == 1) {
          cat = realloc(cat, (i + 1) * sizeof (VendaProduto));
          if (cat == NULL) {
            printf("memoria insuficiente!!");
          }
          fscanf(file, "			<cod_produto>%d</cod_produto>", &cat[i].codProduto);
          fscanf(file, "			<cod_venda>%d</cod_venda>", &cat[i].codVenda);
          fscanf(file, "			<quantidade>%d</quantidade>", &cat[i].quantidade);
          i++;
        }
      }
    }
  }
  *num = i;
  fclose(file);
  free(file);
  return cat;
}

int printXMLVendaProduto(VendaProduto *cat, int num, FILE *cad) {
    if (num > 0) {
    fprintf(cad, "\t<tabela =venda_produto>\n");
    int i;
    for (i = 0; i < num; i++) {
      fprintf(cad, "\t\t<registro>\n");
      fprintf(cad, "\t\t\t<cod_produto>%d</cod_produto>\n", cat[i].codProduto);
      fprintf(cad, "\t\t\t<cod_venda>%d</cod_venda>\n", cat[i].codVenda);
      fprintf(cad, "\t\t\t<quantidade>%d</quantidade>\n", cat[i].quantidade);
      fprintf(cad, "\t\t</registro>\n");
    }
    fprintf(cad, "\t</tabela>\n");
  } else {
    return 0;
  }
  free(cat);
  return 1;
}

Venda* getVendaXML(char local[], int *num) {
  FILE *file;
  file = fopen(local, "r");
  if (file == NULL) {
    file = fopen(local, "w+");
    if (file == NULL) {
      printf("\nErro ao acessar arquivo de venda\n");
      return NULL;
    }
  }
  Venda *ven = (Venda*) calloc(1, sizeof(Venda));
  if(ven = NULL) {
    printf("Erro ao alocar memoria\n");
  }
  char search[100];
  int i = 0;
  while(fgets(search, 100, file) != NULL) {
    if (comparaString("	    <tabela =venda>", search) == 1) {
      while(fgets(search, 100, file) != NULL && comparaString("  </tabela>", search) != 1) {
        if (comparaString("		<registro>", search) == 1) {
          ven = realloc(ven, (i + 1) * sizeof (Venda));
          if (ven == NULL) {
            printf("memoria insuficiente!!");
          }
          fscanf(file, "			<cod_caixa>%d</cod_caixa>", &ven[i].codCaixa);
          fscanf(file, "			<cod_venda>%d</cod_venda>", &ven[i].codVenda);
          fscanf(file, "			<valor_total>%f</valor_total>", &ven[i].valorTotal);
          fscanf(file, "			<data>%d/%d/%d</data>\n", &ven[i].dataVenda.dia, &ven[i].dataVenda.mes, &ven[i].dataVenda.ano);
          i++;
        }
      }
    }
  }
  *num = i;
  fclose(file);
  free(file);
  return ven;
}

int printXMLVenda(Venda *cat, int num, FILE *cad) {
    if (num > 0) {
    fprintf(cad, "\t<tabela =venda>\n");
    int i;
    for (i = 0; i < num; i++) {
      fprintf(cad, "\t\t<registro>\n");
      fprintf(cad, "\t\t\t<cod_caixa>%d</cod_caixa>\n", cat[i].codCaixa);
      fprintf(cad, "\t\t\t<cod_venda>%d</cod_venda>\n", cat[i].codVenda);
      fprintf(cad, "\t\t\t<valor_total>%f</valor_total>\n", cat[i].valorTotal);
      fprintf(cad, "\t\t\t<data>%d/%d/%d</data>\n", cat[i].dataVenda.dia, cat[i].dataVenda.mes, cat[i].dataVenda.ano);
      fprintf(cad, "\t\t</registro>\n");
    }
    fprintf(cad, "\t</tabela>\n");
  } else {
    return 0;
  }
  free(cat);
  return 1;
}
