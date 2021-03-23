
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
#include "Caixa.h"
#include "ContaPagar.h"
#include "Hotel.h"
#include "MenuCaixa.h"
#include "ContaReceber.h"

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
    NotaFiscalEntrada notFisc;
    int bd = listar();
    int numForns = 0;
    int numProds = 0;
    Fornecedor* arrayFornecedores;
    Produto* arrayProdutos;
    int qteProdutos = 0;

    notFisc.dataNota = getDataHoje();

    notFisc.arrayQtes = (int*) calloc(sizeof (int), 1);
    notFisc.produtosComprados = (Produto*) calloc(sizeof (Produto), 1);
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
    scanf("%d%*c", &codForn);
    //codForn = 2;

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
        //ADICIONA OS DADOS DO FORNECEDOR NA NOTA
        for (int i = 0; i < numForns; i++) {
            if (arrayFornecedores[i].codigo == codForn) {
                strcpy(notFisc.nomeForn, arrayFornecedores[i].nomeFantazia);
                strcpy(notFisc.cnpjForn, arrayFornecedores[i].cnpj);
                //printf("O NOME DO FORN SELECIONADO É %s\n", notFisc.nomeForn);
                //printf("O CNPJ DO FORN SELECIONADO É %s\n", notFisc.cnpjForn);
            }
        }
    }
    //validou o fornecedor, agora vai comprar
    printf("DEBUG ANTES DO MÉTODO INSERIR PRODUTOS\n");
    qteProdutos = inseirProdutosNaNotaDeEntrada(&notFisc);
    printf("DEBUG DEPOIS DO MÉTODO INSERIR PRODUTOS\n");
    /*for (int i = 0; i < qteProdutos; i++) {
        printf("\n TESTES %d \n", i);
        printf("VOCÊ COMPROU %d QTES DO PROD: %s\n", notFisc.arrayQtes[i], notFisc.produtosComprados[i].descricao);
    }*/

    notFisc.qteProds = qteProdutos;
    //printf("DEBUG: A QTE DE ITENS DA COMPRA É: %d\n", notFisc.qteProds);

    //CALCULA O FRETE E IMPOSTO
    printf("DEBUG: ANTES DO CALC FRETE\n");
    calculaFreteImposto(&notFisc);
    printf("DEBUG: DEPOIS DO CALC FRETE\n");


    mostrarNotaDeEntrada(notFisc);
    //METODO DE PAGAMENTO 
    printf("DEBUG: ANTES DO PAGAMENTO\n");
    metodoPagamentoNotaFiscal(notFisc, codForn);
    printf("DEBUG: DEPOIS DO PAGAMENTO\n");

    // atualizar os produtos
    atualizarPrecoEstoque(notFisc);



}

int inseirProdutosNaNotaDeEntrada(NotaFiscalEntrada *notFisc) {
    int bd = listar();
    int qteProdutos = 0;
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
            //printf("A quantidade de produtos agora é : %d\n", qteProdutos);
            Produto p;
            //pega o produto
            if (bd == 1) {
                //TXT
                p = getProdutoByCodTXT(codProd);
            }
            if (bd == 2) {
                //BIN
                p = getProdutoByCodBIN(codProd);
            }
            //ALOCA OS VETORES
            notFisc->arrayQtes = (int*) realloc(notFisc->arrayQtes, sizeof (int)* qteProdutos);
            notFisc->produtosComprados = (Produto*) realloc(notFisc->produtosComprados, sizeof (Produto) * qteProdutos);
            //printf("DEBUG: REALOCOU PARA %d (de 0 até %d)?????\n", qteProdutos, qteProdutos - 1);

            notFisc->produtosComprados[qteProdutos - 1] = p;
            // printf("DEBUG NOME: %s\n", notFisc.produtosComprados[qteProdutos - 1].descricao);
            int qte;
            printf("Digite a quantidade do produto ( %s ) que deseja comprar:\n", p.descricao);
            scanf("%d%*c", &qte);
            notFisc->arrayQtes[qteProdutos - 1] = qte;
            //printf("DEBUG QAUNT: POS:%d = %d\n", (qteProdutos - 1), notFisc.arrayQtes[qteProdutos - 1]);


            /*for (int i = 0; i < qteProdutos; i++) {
                printf("\n TESTES %d \n", i);
                printf("VOCÊ COMPROU %d QTES DO PROD: %s\n", notFisc.arrayQtes[i], notFisc.produtosComprados[i].descricao);
            }*/
            printf("Deseja continuar a compra? (1- sim | 2- não) \n");
            scanf("%d%*c", &compraFinalizada);
        }
    }
    printf("DEBUG MÉTODO: QTEPRODS = %d\n", qteProdutos);
    return qteProdutos;
}

void calculaFreteImposto(NotaFiscalEntrada *notFisc) {
    printf("\nCALCULA O FRETE\n");
    printf("DEBUG CALCULA FRETE 1\n");
    float somaQuantiades = 0.0;
    float somaPrecos = 0.0;
    printf("DEBUG: QTE PRODS = %d\n", notFisc->qteProds);
    for (int i = 0; i < notFisc->qteProds; i++) {
        //printf("A QTE DO PRODUTO %d É %d\n",i,NotFisc.arrayQtes[i]);
        //printf("A PREÇO DE CUSTO DO PRODUTO %d É %f\n\n",i,NotFisc.produtosComprados[i].precoCusto);
        somaQuantiades += notFisc->arrayQtes[i];
        somaPrecos += notFisc->produtosComprados[i].precoCusto * notFisc->arrayQtes[i];
        printf("DEBUG FRETE : SOMA PREÇOS = %f\n", somaPrecos);
    }
    printf("DEBUG CALCULA FRETE 2\n");
    printf("DIGITE O PREÇO DO FRETE DOS PRODUTOS:\n");
    float freteProds;
    scanf("%f%*c", &freteProds);
    printf("DIGITE O IMPOSTO DOS PRODUTOS:\n");
    float impProds;
    scanf("%f%*c", &impProds);

    printf("DEBUG CALCULA FRETE 3\n");
    notFisc->prFrete = freteProds / somaQuantiades;
    notFisc->imposto = impProds / somaQuantiades;
    printf("O FRETE É %.2f\n", notFisc->prFrete);
    printf("O IMPOSTO É %.2f\n", notFisc->imposto);
    printf("A SOMA DOS PRODUTOS É %.2f\n", somaPrecos);

    //CALCULA O TOTAL DA NOTA
    printf("DEBUG CALCULA FRETE 4\n");
    notFisc->total = notFisc->prFrete + notFisc->imposto + somaPrecos;
    printf("DEBUG CALCULA FRETE 5\n");
    printf("DEBUG: O TOTAL É %f + %f = %f\n", notFisc->prFrete, notFisc->imposto, notFisc->total);
}

void metodoPagamentoNotaFiscal(NotaFiscalEntrada notFisc, int codForn) {
    int bd = listar();
    //METODO DE PAGAMENTO 
    int opcPagamento;
    printf("COMO DESEJA PAGAR OS PRODUTOS?\n");
    printf("1- A VISTA\n");
    printf("2- A PRAZO\n");
    printf("Digite a opção desejada:\n");
    scanf("%d%*c", &opcPagamento);
    //VALIDAR A OPÇÃO    
    printf("DEBUG: DIGITOU %d\n", opcPagamento);
    if (opcPagamento == 1) {
        //SE TEM DINHEIRO NO CAIXA, CADASTRA A NOTA
        //PRECISO ARMAZENAR O VALOR QUE VAI SER RETIRADO
        printf("DEBUG 1\n");
        //printf("VALOR DO CAIXA: %f, VALOR DA NOTA: %f\n", somaValores(), notFisc.total);
        //valida o saldo do caixa
        if (somaValores() < notFisc.total) {
            printf("ERRO!\n");
            printf("VALOR DO CAIXA: %f, VALOR DA NOTA: %f\n", somaValores(), notFisc.total);
            exit(1);
        }
        printf("DEBUG 2\n");
        ContaPagar cp;
        //cp.caixa.codigo = getCaixaAtual(getDataHoje());
        printf("DEBUG ANTES CAIXA ABERTO\n");
        cp.caixa = caixaAberto();
        printf("DEBUG DEPOIS CAIXA ABERTO\n");
        cp.codForn = codForn;
        cp.codigo = maiorCodContasPagar() + 1;
        cp.data = getDataHoje();
        //cp.descricao = "Pagamento a vista";
        strcpy(cp.descricao, "Pagamento_a_vista");
        //cp.status = "status";
        strcpy(cp.status, "concluido");
        cp.valor = notFisc.total;
        bd = 1;
        printf("\n\n BD ==1\n\n");
        if (bd == 1) {
            printf("ANTES DO CADASTRO TXT\n");
            cadastrarContaPagarTXT(cp);
            printf("DEPOIS DO CADASTRO TXT\n");
        }
        if (bd == 2) {
            cadastrarContaPagarBIN(&cp, 1);
        }


        notFisc.codCaixa = getCaixaAtual(getDataHoje());
        printf("DEBUG: O CAIXA É %d\n", notFisc.codCaixa);
        //CADASTRA NOTA
        if (bd == 1) {

        }
        if (bd == 2) {
            cadastrarNotaFiscalEntradaBIN(notFisc);
            printf("DEBUG: DEPOIS DO CADASTRO?\n");
        }


    }
    if (opcPagamento == 2) {
        int opc = 0;
        printf("Deseja dar um valor de entada? (1- SIM | 2- NÃO)\n");
        scanf("%d%*c", &opc);
        if (opc == 1) {
            float entrada;
            printf("Digite o valor da entrada:\n");
            scanf("%f%*c", &entrada);
            printf("DEBUG: ENTRADA É %f\n", entrada);
            //VALIDA O SALDO DO CAIXA
            if (somaValores() < entrada) {
                printf("ERRO!\n");
                printf("VALOR DO CAIXA: %f, VALOR DA NOTA: %f\n", somaValores(), notFisc.total);
                exit(1);
            }
            ContaPagar cp;
            //cp.caixa.codigo = getCaixaAtual(getDataHoje());
            printf("DEBUG: ANTES DO CAIXA?\n");
            cp.caixa = caixaAberto();
            cp.codForn = codForn;
            cp.codigo = maiorCodContasPagar() + 1;
            cp.data = getDataHoje();
            //cp.descricao = "Entrada";
            strcpy(cp.descricao, "Entrada");
            //cp.status = "status";
            strcpy(cp.status, "concluido");
            cp.valor = entrada;
            printf("DEBUG: DEPOIS DO CAIXA?\n");
            //DEBITAR O VALOR DA ENTRADA
            printf("DEBUG: NOT FISC ANTES: %f\n", notFisc.total);
            notFisc.total -= entrada;
            printf("DEBUG: NOT FISC DEPOIS: %f\n", notFisc.total);
            notFisc.codCaixa = getCaixaAtual(getDataHoje());
            //CADASTRA A CONTA DA ENTRADA
            if (bd == 1) {

            }
            if (bd == 2) {
                printf("DEBUG: VAI CADASTRAR A CONTA PAGAR ENTRADA\n");
                cadastrarContaPagarBIN(&cp, 1);
            }


        }
        // (opc == 2) {
        int parcelas;
        printf("Digite o número de parcelas:\n");
        scanf("%d%*c", &parcelas);
        printf("DEBUG: AS PARCELAS É %d\n", parcelas);

        //CADASTRA UMA CONTA PARA CADA PARCELA
        printf("DEBUG: DEPOIS DO NUM DE PARCELAS\n");
        ContaPagar cp;

        cp.caixa = caixaAberto();
        
        if (opc == 1) {
            //se ele deu uma entrada, ela já está cadastrada
            //o cod das parcelas deve ser o mesmo da entrada (maior cod)
            cp.codigo = maiorCodContasPagar();
        } else {
            cp.codigo = maiorCodContasPagar() + 1;
        }

        cp.data = getDataHoje();
        //como só vai pagar no próximo mes...
        //cp.data.mes++;
        somaDias(&(cp.data), 30);
        //cp.descricao = "Parcela Nota Fiscal";
        strcpy(cp.descricao, "Parcela_Nota_Fiscal");
        cp.codForn = codForn;
        cp.valor = (notFisc.total / parcelas);
        //cp.status = "Status";
        strcpy(cp.status, "Pendente");

        printf("DEBUG: DEPOIS DA STRUCT\n");

        for (int i = 0; i < parcelas; i++) {
            //CADASTRA A CONTA
            cadastrarContaPagarBIN(&cp, 1);
            printf("DEBUG: NO FOR (%d) MES = %d\n", i, cp.data.mes);
            //cp.data.mes++;
            somaDias(&(cp.data), 30);

        }
        //CAIXA DA NOTA A PRAZO

        //MESMO SENDO A PRAZO, CADASTRA A NOTA
        //cadastrarNotaFiscalEntradaBIN(notFisc);
        //CADASTRA NOTA
        if (bd == 1) {

        }
        if (bd == 2) {
            printf("DEBUG: VAI CADASTRAR A NOTA\n");
            cadastrarNotaFiscalEntradaBIN(notFisc);
            printf("DEBUG: DEPOIS DO CADASTRO?\n");
        }
        //}

    }

}

void atualizarPrecoEstoque(NotaFiscalEntrada notFisc) {
    int bd = listar();
    int num;
    Hotel *hotel = listarHotelBIN(&num);
    float porcentagemLucro = 1 + (hotel->margemLucro / 100);
    printf("DEBUG: A MARGEM DE LUCRO É:  %f\n", porcentagemLucro);

    for (int i = 0; i < notFisc.qteProds; i++) {
        Produto p = notFisc.produtosComprados[i];
        p.precoVenda = (p.precoCusto + notFisc.prFrete + notFisc.imposto) * porcentagemLucro;
        printf("DEBUG: O ESTOQUE ERA DE %d\n", p.estoque);
        p.estoque += notFisc.arrayQtes[i];
        printf("DEBUG: O NOVO ESTOQUE E DE %d\n", p.estoque);
        //printf("DEBUG: O NOVO PREÇO DE VENDA É (%f + %f + %f) * %f = %f\n",p.precoCusto,notFisc.prFrete,notFisc.imposto,porcentagemLucro,p.precoVenda);
        if (bd == 1) {
            atualizarProdutoTXT(p);
        }
        if (bd == 2) {
            atualizarProdutoBIN(p);
            printf("DEBUG: ATUALIOU \n");
        }

    }
    printf("aAAAAAAAAAAAAAAAAAAAAAA\n");
}

void mostrarNotaDeEntrada(NotaFiscalEntrada nota) {
    printf("*********** NOTA DE ENTRADA ***********\n");

    printf("--------------\n");
    printf("FORNECEDOR: %s\n", nota.nomeForn);
    printf("CNPJ: %s\n", nota.cnpjForn);
    printf("--------------\n");
    printf("----- PRODUTOS -----\n");
    for (int i = 0; i < nota.qteProds; i++) {
        printf("(%d) %s\n", (i + 1), nota.produtosComprados[i].descricao);
        printf("QUANTIDADE: %d\n", nota.arrayQtes[i]);
        printf("PREÇO: %.2f\n", nota.arrayQtes[i] * nota.produtosComprados[i].precoCusto);
    }
    printf("--------------\n");
    printf("FRETE: %.2f\n", nota.prFrete);
    printf("IMPOSTO: %.2f\n", nota.imposto);
    printf("PREÇO PRODUTOS: %.2f\n", nota.total - (nota.prFrete + nota.imposto));

    printf("VALOR TOTAL DA NOTA: %.2f\n", nota.total);
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
