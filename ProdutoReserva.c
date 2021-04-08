/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "Reserva.h"
#include "Produto.h"
#include "ProdutoReserva.h"
#include "SalvametoBD.h"

void cadastrarProdutoReservaTXT(ProdutoReserva pr) {
    FILE* arqProdutoReserva;
    //abre o arquivo, ou cria um novo se não conseguir abrir
    arqProdutoReserva = fopen(".\\arquivos\\produtos_reserva.txt", "a");
    if (arqProdutoReserva == NULL) {
        arqProdutoReserva = fopen(".\\arquivos\\produtos_reserva.txt", "w");
    }
    int retorno;
    retorno = fprintf(arqProdutoReserva, "%d\r\n%d\r\n%d\r\n%d\r\n%d\r\n%d\r\n", pr.codProd, pr.codRes, pr.data.dia, pr.data.mes, pr.data.ano, pr.quantidade);

    fflush(arqProdutoReserva);
    fclose(arqProdutoReserva);
    return retorno;
}

void cadastrarProdutoReservaBIN(ProdutoReserva pr) {
    FILE* arqProdutoReserva;
    //abre o arquivo, ou cria um novo se não conseguir abrir
    arqProdutoReserva = fopen(".\\arquivos\\produtos_reserva.bin", "ab");
    if (arqProdutoReserva == NULL) {
        arqProdutoReserva = fopen(".\\arquivos\\produtos_reserva.bin", "wb");
        if (arqProdutoReserva == NULL) {
            printf("ERRO AO LER ARQUIVO DE PRODUTOS RESERVA\n");
        }

    } else {
        int count = 0;
        count = fwrite(&pr, sizeof (ProdutoReserva), 1, arqProdutoReserva);

        fflush(arqProdutoReserva);
        /*fecha o arquivo*/
        fclose(arqProdutoReserva);
        /*libera mémoria*/
        free(arqProdutoReserva);
        fclose(arqProdutoReserva);
        return count;
    }
}

ProdutoReserva* getAllProdutoReservaTXT(int numProdutos) {
    //printf("DEBUG: ENTROU GET ALL PROD RESERVA TXT\n");
    int index = 1; //PARA ARMAZENAR O TAMANHO DO VETOR
    ProdutoReserva *arrayProdutos = (ProdutoReserva *) malloc(sizeof (ProdutoReserva) * numProdutos); //PONTEIRO DE HÓSPEDE VIRA UM VETOR AO CHAMAR MALLOC
    if (arrayProdutos == NULL) {
        printf("ERRO DE ALOCAÇÃO");
        exit(1);
    }

    //pega a lista de Produtos do arquivo
    FILE *arqProduto;

    arqProduto = fopen(".\\arquivos\\produtos_reserva.txt", "r");
    if (arqProduto == NULL) {
        printf(" ERRO DE LEITURA ");
    } else {

        for (int i = 0; i < numProdutos; i++) {
            ProdutoReserva p;


            //FSCANF PARA PEGAR OS VALORES DO ARQUIVO. "TEXT[20]" É APENAS PARA ARMAZENAR A STRING QUE VEM ANTES DO VALOR.
            fscanf(arqProduto, "%d", &p.codProd);
            fscanf(arqProduto, "%d", &p.codRes);
            fscanf(arqProduto, "%d", &p.data.dia);
            fscanf(arqProduto, "%d", &p.data.mes);
            fscanf(arqProduto, "%d", &p.data.ano);
            fscanf(arqProduto, "%d", &p.quantidade);

            //COLOCA O PRODUTO NO ARRAY
            arrayProdutos[index - 1] = p;
            index++;
            //printf("DEBUG: LEU UM PROD RESERVA TXT\n");
        }
        fclose(arqProduto);
        return arrayProdutos;
    }
}

ProdutoReserva* getAllProdutoReservaBIN(int* numProdutos) {
    //printf("DEBUG: ENTROU GET ALL PROD RESERVA BIN\n");
    int totalLido = 0;
    int index = 0;
    ProdutoReserva *arrayProdutos = (ProdutoReserva *) malloc(sizeof (ProdutoReserva) * 1); //PONTEIRO DE PRODUTOS VIRA UM VETOR AO CHAMAR MALLOC
    if (arrayProdutos == NULL) {
        printf("ERRO DE ALOCAÇÃO");
        exit(1);
    }

    FILE *arqProduto;
    //abre o arquivo, ou cria um novo se nao conseguir abrir
    arqProduto = fopen(".\\arquivos\\produtos_reserva.bin", "rb");
    if (arqProduto == NULL) {
        arqProduto = fopen(".\\arquivos\\produtos_reserva.bin", "wb");
        if (arqProduto == NULL) {
            printf("ERRO DE LEITURA ");
        }
    } else {

        while (!feof(arqProduto)) { //enquanto não for o final do arquivo
            ProdutoReserva p;
            //lê um produto do arquivo e incrementa o número de produtos
            int conseguiuLer = fread(&p, sizeof (ProdutoReserva), 1, arqProduto);
            if (conseguiuLer == 1) {
                //printf("DEBUG: LEU UM PROD RESERVA BIN\n");
                (*numProdutos)++;
            } else {
                //printf("ERRO\n");
            }
            arrayProdutos[index] = p;
            index++;
            //realoca o vetor
            arrayProdutos = realloc(arrayProdutos, (index + 1) * sizeof (ProdutoReserva));
            //printf("INDEX = %d\n", index);
        }

        fclose(arqProduto);

        return arrayProdutos;
    }
}

int getNumProdReserva() {

    FILE *arq;
    int numLinhas = 0, numProdutos = 0;
    char c;
    arq = fopen(".\\arquivos\\produtos_reserva.txt", "r");
    if (arq == NULL) {
        arq = fopen(".\\arquivos\\produtos_reserva.txt", "w");
        if (arq == NULL) {
            printf("ERRO AO ACESSAR ARQUIVO");
            exit(1);
        }

        return 0;
    }
    while ((c = fgetc(arq)) != EOF) {

        if (c == '\n') {
            numLinhas++;
        }
    }
    numProdutos = numLinhas / 6; // um produto gasta 6 linhas

    //printf("O NÚMERO DE LINHAS DO ARQ É: %d\n", numLinhas);
    //printf("O NÚMERO DE PRODS CADASTRADOS É: %d\n", numProdutos);
    fclose(arq);
    free(arq);
    return numProdutos;

}

float somaProdutosConsumido(int codReserva) {
    int bd = listar();
    float total = 0;
    ProdutoReserva* produtosDaReserva;
    int numProds = 0;
    if (bd == 1) {
        numProds = getNumProdReserva();
        produtosDaReserva = getAllProdutoReservaTXT(numProds);
    }
    if (bd == 2) {
        produtosDaReserva = getAllProdutoReservaBIN(&numProds);
    }


    for (int i = 0; i < numProds; i++) {
        if (codReserva == produtosDaReserva[i].codRes) {
            Produto p;
            /*printf("+++++++++++\n");
            printf("COD RESERVA: %d\n", produtosDaReserva[i].codRes);
            printf("COD PROD: %d\n", produtosDaReserva[i].codProd);
            printf("QTE: %d\n", produtosDaReserva[i].quantidade);
            printf("+++++++++++++++++++\n");
             */
            if (bd == 1) {
                p = getProdutoByCodTXT(produtosDaReserva[i].codProd);
            }
            if (bd == 2) {
                p = getProdutoByCodBIN(produtosDaReserva[i].codProd);
            }
            //printf("DEBUG: PEGOU O PRODUTO %s\n",p.descricao);
            //printf("DEBUG: A QTE É %d\n",produtosDaReserva[i].quantidade);
            total += p.precoVenda * produtosDaReserva[i].quantidade;
            //printf("DEBUG: SOMA TOTAL =  %.2f\n",total);
        }

    }

    return total;
}

void listarProdResFaixa(int c1, int c2) {
    //VERIFICAR EXTENSÃO DO ARQUIVO
    int ext = listar();
    int numProdutos;
    ProdutoReserva* arrayProdutos;
    if (ext == 2) {
        //BIN
        numProdutos = 0;
        arrayProdutos = getAllProdutoReservaBIN(&numProdutos);
        //printf("NUM PROD = %d\n", numProdutos);
    }
    if (ext == 1) {
        //TXT
        numProdutos = getNumProdReserva();
        arrayProdutos = getAllProdutoReservaTXT(numProdutos);

    }
    printf("***** LISTA DE TODOS OS PRODUTOS*****\n");
    for (int i = 0; i < numProdutos; i++) {
        //lista os produtos
        if (arrayProdutos[i].codProd >= c1 && arrayProdutos[i].codProd <= c2) {
            printf("***************\n");
            printf("COD: %d\n", arrayProdutos[i].codProd);
            printf("COD RES: %d\n", arrayProdutos[i].codRes);
            printf("ESTOQUE: %d\n", arrayProdutos[i].quantidade);
            printf("DATA: /%d/%d/%d ", arrayProdutos[i].data.dia, arrayProdutos[i].data.mes, arrayProdutos[i].data.ano);
            printf("***************\n");
        }
    }
    printf("\n FIM DA LISTA DE PRODUTOS \n");
}

ProdutoReserva* filtrarProdutoReservaCodControl(int c1, int c2) {
    int numProdutos=0; // o valor será atualizado, para poder mostrar todos os hóspedes;
    int qteProdResFiltro = 0;
    int index = 0;

    ProdutoReserva* arrayProdutos;
    ProdutoReserva* arrayFiltrado;


    //pega a extensão do arquivo
    int ext = listar();
    if (ext == 2) {
        //BIN
        numProdutos = 0;
        arrayProdutos = getAllProdutoReservaBIN(&numProdutos);
        //printf("NUM PROD = %d\n", numProdutos);
    }
    if (ext == 1) {
        //TXT
        numProdutos = getNumProdReserva();
        arrayProdutos = getAllProdutoReservaTXT(numProdutos);

    }
    //se não existe nenhum hóspede, termina a função

    //calcula quantos hospedes pertencem ao filtro
    for (int i = 0; i < numProdutos; i++) {
        if (arrayProdutos[i].codProd >= c1 && arrayProdutos[i].codProd <= c2) {
            qteProdResFiltro++;

        }
    }



    arrayFiltrado = (ProdutoReserva *) malloc(sizeof (ProdutoReserva) * qteProdResFiltro);

    for (int i = 0; i < numProdutos; i++) {
        if (arrayProdutos[i].codProd >= c1 && arrayProdutos[i].codProd <= c2) {
            arrayFiltrado[index] = arrayProdutos[i];
            //printf("ADD O HOSPEDE (%s) NA POS: %d\n", arrayFiltrado[i].nome, index);
            index++;
        }

    }

    gerarCSVProdRes(arrayFiltrado, qteProdResFiltro);


}

void gerarCSVProdRes(ProdutoReserva* arrayF, int qte) {
    printf("ENTROU GERAR CSV\n");
    printf("COD = %d\n", arrayF[1].codProd);
    printf("QTE = %d\n", qte);
    FILE* arCaixa;



    arCaixa = fopen(".\\relatorios\\ProdutoReserva_FaixaCod", "w");


    for (int i = 0; i < qte; i++) {
        printf("DENTRO DO FOR\n");
        /*
       
                fprintf(arHospedes, "%d,%s,%s,%s,%s,%c,%d,%d,%d,%d,%s,%s,%s,%s,%d,%s", arrayFiltrado[i].codigo, arrayFiltrado[i].nome, arrayFiltrado[i].cpf, arrayFiltrado[i].telefone, arrayFiltrado[i].email, arrayFiltrado[i].sexo, arrayFiltrado[i].esCivil
                        , arrayFiltrado[i].dataNascimento.dia, arrayFiltrado[i].dataNascimento.mes, arrayFiltrado[i].dataNascimento.ano
                        , arrayFiltrado[i].endereco.codigo, arrayFiltrado[i].endereco.bairro,arrayFiltrado[i].endereco.cep,arrayFiltrado[i].endereco.cidade,
                        arrayFiltrado[i].endereco.logradouro,arrayFiltrado[i].endereco.numero,arrayFiltrado[i].endereco.uf);
                fprintf(arHospedes, "\n");
    
    
         */
        fprintf(arCaixa, "%d,%d,%d,%d,%d,%d)", arrayF[i].codProd, arrayF[i].codRes, arrayF[i].data.dia, arrayF[i].data.mes, arrayF[i].data.ano, arrayF[i].quantidade);
        fprintf(arCaixa, "\n");
    }

    //retorno += fprintf(arHospedes, "DiaNasc: %d\r\nMesNasc: %d\r\nAnoNasc: %d\r\n", h.dataNascimento.dia, h.dataNascimento.mes, h.dataNascimento.ano);
    //retorno += fprintf(arHospedes, "CodEnder: %d\r\nBairro: %s\r\nCEP: %s\r\nCidade: %s\r\nLogradouro: %s\r\nNumero: %d\r\nUF: %s\r\n", h.endereco.codigo, h.endereco.bairro, h.endereco.cep, h.endereco.cidade, h.endereco.logradouro, h.endereco.numero, h.endereco.uf);

    fflush(arCaixa);
    fclose(arCaixa);

}