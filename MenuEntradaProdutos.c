/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include "SalvametoBD.h"
#include "MenuEntradaProdutos.h"
#include "Produto.h"
#include "Fornecedor.h"
#include "FornecedorSUB.h"
#include "EntradaProdutos.h"
#include "ProdutoConsumoMenu.h"

void menuEntradaProdutos() {
    int opc = 0;

    while (opc >= 0) {
        printf("***** ENTRADA DE PRODUTOS ***** \n");
        printf("1.Compra de produtos \n");
        printf("2.Voltar. \n");
        scanf("%d*c", &opc);

        switch (opc) {
            case 1:
                ComprarProdutos();
                //ComprarProdutos2();
                break;

            case 2:
                opc = -1;
                break;
            default:
                printf("OPÇÃO INVÁLIDA\n");
                break;
        }
    }
}

/*void ComprarProdutos() {
    NotaFiscalEntrada NotFisc;
    int bd = listar();
    int numForns = 0;
    int numProds = 0;
    Fornecedor* arrayFornecedores;
    Produto* arrayProdutos;
    int qteProdutos = 0;

    NotFisc.arrayQtes = (int*) calloc(NotFisc.arrayQtes, (sizeof (int)));
    NotFisc.produtosComprados = (Produto*) calloc(NotFisc.arrayQtes, (sizeof (Produto)));

    if (bd == 1) {
        //TXT
    }
    if (bd == 2) {
        //BIN

        arrayFornecedores = listarFornecedorBIN(&numForns);
        arrayProdutos = getAllProdutoBIN(&numProds);
    }

    int codForn;
    int valid = 0;
    printf("Digite o codigo do fornecedor:\n");
    //scanf("%d%*c", &codForn);
    codForn=1;

    if (bd == 1) {
        //TXT

    }
    if (bd == 2) {
        //BIN
        valid = validarFornecedor(codForn);
    }

    if (valid == 0) {
        printf("CÓD INVÁLIDO: %d\n", codForn);
        return;
    } else {
        printf("FORNECEDOR ENCONTRADO\n\n");
        //////////VER COM O DANIEL O METODO DELE
        for (int i = 0; i < numForns; i++) {
            if (arrayFornecedores[i].codigo == codForn);

            /////////////NotFisc.nomeForn = arrayFornecedores[i].nomeFantazia;
        }

    }


    //validou o fornecedor, agora vai comprar
    int compraFinalizada = 0;

    while (compraFinalizada <= 1) {
        int codProd;

        printf("Digite o código do produto que deseja comprar\n");
        scanf("%d%*c", &codProd);

        int valid = validarCodProdConsumo(codProd, bd);
        if (valid == 1) {
            printf("COD DO PRODUTO NÃO EXISTE\n");
            printf("Deseja continuar a compra? (1- sim | 2- não) \n");
            scanf("%d%*c", &compraFinalizada);
        } else {
            //ACHOU O PRODUTO
            //////////////////inserirProdutoNaNota();
            qteProdutos++;
            printf("A quantidade de produtos agora é : %d\n",qteProdutos);
            Produto p;
            //pega o produto
            if (bd == 1) {
                //TXT
            }
            if (bd == 2) {
                //BIN
                p = getProdutoByCodBIN(codProd);
            }
            //ALOCA OS VETORES
            NotFisc.arrayQtes = (int*) realloc(NotFisc.arrayQtes, sizeof (int)* qteProdutos);
            NotFisc.produtosComprados = (Produto*) realloc(NotFisc.arrayQtes, sizeof (Produto)*qteProdutos);
            printf("DEBUG: REALOCOU PARA %d (de 0 até %d)?????\n", qteProdutos, qteProdutos - 1);

            NotFisc.produtosComprados[qteProdutos - 1] = p;
            printf("DEBUG NOME: %s\n", NotFisc.produtosComprados[qteProdutos - 1].descricao);
            int qte;
            printf("Digite a quantidade do produto ( %s ) que deseja comprar:\n", p.descricao);
            scanf("%d%*c", &qte);
            NotFisc.arrayQtes[qteProdutos - 1] = qte;
            printf("DEBUG QAUNT: POS:%d = %d\n", (qteProdutos - 1), NotFisc.arrayQtes[qteProdutos - 1]);


            for (int i = 0; i < qteProdutos; i++) {
                printf("\n\n TESTES %d \n\n", i);
                printf("VOCÊ COMPROU %d QTES DO PROD: %s\n\n", NotFisc.arrayQtes[i], NotFisc.produtosComprados[i].descricao);
            }

        }
    }

}
 */

void ComprarProdutos() {
    NotaFiscalEntrada NotFisc;
    int bd = listar();
    int numForns = 0;
    int numProds = 0;
    Fornecedor* arrayFornecedores;
    Produto* arrayProdutos;
    int qteProdutos = 0;

    NotFisc.arrayQtes = (int*) calloc(sizeof (int), 1);
    NotFisc.produtosComprados = (Produto*) calloc(sizeof (Produto), 1);
    //Produto * arrProd = (Produto*) calloc((sizeof (Produto)),1);
    //int* arrQte = (int*) calloc((sizeof (int)),1);

    if (bd == 1) {
        //TXT
    }
    if (bd == 2) {
        //BIN

        arrayFornecedores = listarFornecedorBIN(&numForns);
        arrayProdutos = getAllProdutoBIN(&numProds);
    }

    int codForn;
    int valid = 0;
    printf("Digite o codigo do fornecedor:\n");
    //scanf("%d%*c", &codForn);
    codForn = 2;

    if (bd == 1) {
        //TXT

    }
    if (bd == 2) {
        //BIN
        valid = validarFornecedor(codForn);
    }

    if (valid == 0) {
        printf("CÓD DO FORNECEDOR INVÁLIDO: %d\n", codForn);
        return;
    } else {
        printf("FORNECEDOR ENCONTRADO\n\n");
        //////////VER COM O DANIEL O METODO DELE
        for (int i = 0; i < numForns; i++) {
            if (arrayFornecedores[i].codigo == codForn) {
                strcpy(NotFisc.nomeForn, arrayFornecedores[i].nomeFantazia);
                strcpy(NotFisc.cnpjForn, arrayFornecedores[i].cnpj);
                printf("O NOME DO FORN SELECIONADO É %s\n", NotFisc.nomeForn);
                printf("O CNPJ DO FORN SELECIONADO É %s\n", NotFisc.cnpjForn);
            }

            ///NotFisc.nomeForn = arrayFornecedores[i].nomeFantazia;

        }

    }


    //validou o fornecedor, agora vai comprar
    int compraFinalizada = 0;

    while (compraFinalizada <= 1) {
        int codProd;

        printf("Digite o código do produto que deseja comprar\n");
        scanf("%d%*c", &codProd);

        int valid = validarCodProdConsumo(codProd, bd);
        if (valid == 1) {
            printf("COD DO PRODUTO NÃO EXISTE\n");
            printf("Deseja continuar a compra? (1- sim | 2- não) \n");
            scanf("%d%*c", &compraFinalizada);
        } else {
            //ACHOU O PRODUTO
            //////////////////inserirProdutoNaNota();
            qteProdutos++;
            printf("A quantidade de produtos agora é : %d\n", qteProdutos);
            Produto p;
            //pega o produto
            if (bd == 1) {
                //TXT
            }
            if (bd == 2) {
                //BIN
                p = getProdutoByCodBIN(codProd);
            }
            //ALOCA OS VETORES
            NotFisc.arrayQtes = (int*) realloc(NotFisc.arrayQtes, sizeof (int)* qteProdutos);
            NotFisc.produtosComprados = (Produto*) realloc(NotFisc.produtosComprados, sizeof (Produto) * qteProdutos);
            printf("DEBUG: REALOCOU PARA %d (de 0 até %d)?????\n", qteProdutos, qteProdutos - 1);

            NotFisc.produtosComprados[qteProdutos - 1] = p;
            printf("DEBUG NOME: %s\n", NotFisc.produtosComprados[qteProdutos - 1].descricao);
            int qte;
            printf("Digite a quantidade do produto ( %s ) que deseja comprar:\n", p.descricao);
            scanf("%d%*c", &qte);
            NotFisc.arrayQtes[qteProdutos - 1] = qte;
            printf("DEBUG QAUNT: POS:%d = %d\n", (qteProdutos - 1), NotFisc.arrayQtes[qteProdutos - 1]);


            for (int i = 0; i < qteProdutos; i++) {
                printf("\n TESTES %d \n", i);
                printf("VOCÊ COMPROU %d QTES DO PROD: %s\n", NotFisc.arrayQtes[i], NotFisc.produtosComprados[i].descricao);
            }

        }
    }

    NotFisc.qteProds = qteProdutos;
    printf("DEBUG: A QTE DE ITENS DA COMPRA É: %d\n", NotFisc.qteProds);

    //CALCULA O FRETE E IMPOSTO
    printf("\nCALCULA O FRETE\n");
    float somaQuantiades = 0.0;
    float somaPrecos = 0.0;
    for (int i = 0; i < NotFisc.qteProds; i++) {
        //printf("A QTE DO PRODUTO %d É %d\n",i,NotFisc.arrayQtes[i]);
        //printf("A PREÇO DE CUSTO DO PRODUTO %d É %f\n\n",i,NotFisc.produtosComprados[i].precoCusto);
        somaQuantiades += NotFisc.arrayQtes[i];
        somaPrecos += NotFisc.produtosComprados[i].precoCusto * NotFisc.arrayQtes[i];
    }
    NotFisc.prFrete = 100 / somaQuantiades;
    NotFisc.imposto = 30 / somaQuantiades;
    printf("O FRETE É %.2f\n", NotFisc.prFrete);
    printf("O IMPOSTO É %.2f\n", NotFisc.imposto);
    printf("A SOMA DOS PRODUTOS É %.2f\n", somaPrecos);

    //CALCULA O TOTAL DA NOTA
    NotFisc.total = NotFisc.prFrete+ NotFisc.imposto + somaPrecos;
    
    mostrarNotaDeEntrada(NotFisc);
    
    //METODO DE PAGAMENTO 
    int opcPagamento;
    printf("COMO DESEJA PAGAR OS PRODUTOS?\n");
    printf("1- A VISTA\n");
    printf("2- A PRAZO\n");
    printf("Digite a opção desejada:\n");
    scanf("%d%*c",opcPagamento);
    //VALIDAR A OPÇÃO    
    
    if(opcPagamento ==1){
        //SE TEM DINHEIRO NO CAIXA, CADASTRA A NOTA
    }
    if(opcPagamento ==2){
        
    }
    
}

void mostrarNotaDeEntrada(NotaFiscalEntrada nota) {
    printf("*********** NOTA DE ENTRADA ***********\n");
    
    printf("--------------\n");
    printf("FORNECEDOR: %s\n",nota.nomeForn);
    printf("CNPJ: %s\n",nota.cnpjForn);
    printf("--------------\n");
    printf("----- PRODUTOS -----\n");
    for(int i =0;i<nota.qteProds;i++){
        printf("(%d) %s\n",(i+1),nota.produtosComprados[i].descricao);
        printf("QUANTIDADE: %d\n",nota.arrayQtes[i]);
        printf("PREÇO: %.2f\n",nota.arrayQtes[i]* nota.produtosComprados[i].precoCusto);
    }
    printf("--------------\n");
    printf("FRETE: %.2f\n",nota.prFrete);
    printf("IMPOSTO: %.2f\n",nota.imposto);
    printf("PREÇO PRODUTOS: %.2f\n",nota.total - (nota.prFrete + nota.imposto));
    
    printf("VALOR TOTAL DA NOTA: %.2f\n",nota.total);
}

void ComprarProdutos2() {
    NotaFiscalEntrada notFisc;
    int bd = listar();
    int numForns = 0;
    int numProds = 0;
    Fornecedor* arrayFornecedores;
    Produto* arrayProdutos;
    int qteProdutos = 0;

    if (bd == 1) {
        //TXT
    }
    if (bd == 2) {
        //BIN
        arrayFornecedores = listarFornecedorBIN(&numForns);
        arrayProdutos = getAllProdutoBIN(&numProds);
    }

    int codForn;
    int valid = 0;
    printf("Digite o codigo do fornecedor:\n");
    //scanf("%d%*c", &codForn);
    codForn = 1;

    if (bd == 1) {
        //TXT

    }
    if (bd == 2) {
        //BIN
        valid = validarFornecedor(codForn);
    }

    if (valid == 0) {
        printf("CÓD INVÁLIDO: %d\n", codForn);
        return;
    } else {
        printf("FORNECEDOR ENCONTRADO\n\n");
        //////////VER COM O DANIEL O METODO DELE
        for (int i = 0; i < numForns; i++) {
            if (arrayFornecedores[i].codigo == codForn);

            /////////////NotFisc.nomeForn = arrayFornecedores[i].nomeFantazia;
        }

        //validou o fornecedor, agora vai comprar
        int qteDeProdutos;
        printf("Digite a quantidade de produtos da compra:\n");
        scanf("%d%*c", &qteDeProdutos);
        printf("DeBUG: QTE PRODS = %d\n", qteDeProdutos);
        int *arrQte;

        arrQte = (int*) calloc(qteDeProdutos, sizeof (int));
        notFisc.arrayQtes = (int*) calloc(qteDeProdutos, sizeof (int));
        //notFisc.arrayQtes = arrQte;
        printf("DEBUG CALLOC:\n");

        for (int i = 0; i < qteDeProdutos; i++) {
            //printf("(%d) = %d\n",i,arrQte[i]);
            printf("POS: (%d) = %d\n", i, notFisc.arrayQtes[i]);
        }

        int codProd;
        for (int i = 0; i < qteDeProdutos; i++) {
            printf("Digite o Código do produto");
        }
    }

}

void inserirProdutoNaNota() {
    /* NotaFiscalEntrada NotFisc;

     int numProds = 0;
     Produto* allProdutos = getAllProdutoBIN(&numProds);
     Produto* produtosDaNota;
     int qteProdutos = 0;
     Produto p;
     //pega o produto
     if (bd == 1) {
         //TXT
     }
     if (bd == 2) {
         //BIN
         p = getProdutoByCodBIN(codProd);
     }
     printf("Digite a quantidade do produto ( %s ) que deseja comprar:\n", p.descricao);
     */
}