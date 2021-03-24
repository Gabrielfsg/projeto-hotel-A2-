
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

    if (bd == 1) {
        //TXT      
        numForns = numLinhasFornecedor();
        arrayFornecedores = listarFornecedorTXT();
        arrayProdutos = getAllProdutoTXT(getNumProdConsumo());
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
        valid = validarFornecedor(codForn);
    }
    if (bd == 2) {
        //BIN
        valid = validarFornecedorBIN(codForn);
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
                printf("O nome do fornecedor selecionado é: %s\n", notFisc.nomeForn);
                printf("O CNPJ do fornecedor selecionado é: %s\n", notFisc.cnpjForn);
            }
        }
    }

    //validou o fornecedor, agora vai comprar
    qteProdutos = inseirProdutosNaNotaDeEntrada(&notFisc);
    /*for (int i = 0; i < qteProdutos; i++) {
        printf("\n TESTES %d \n", i);
        printf("VOCÊ COMPROU %d QTES DO PROD: %s\n", notFisc.arrayQtes[i], notFisc.produtosComprados[i].descricao);
    }*/

    notFisc.qteProds = qteProdutos;
    //printf("DEBUG: A QTE DE ITENS DA COMPRA É: %d\n", notFisc.qteProds);

    //CALCULA O FRETE E IMPOSTO
    calculaFreteImposto(&notFisc);

    //PRINTA NA TELA A NOTA
    mostrarNotaDeEntrada(notFisc);

    //METODO DE PAGAMENTO 
    metodoPagamentoNotaFiscal(notFisc, codForn);


    // atualizar os produtos
    atualizarPrecoEstoque(notFisc);

    free(arrayFornecedores);
    free(arrayProdutos);

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
            qteProdutos++;
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
    //printf("\nCALCULA O FRETE\n");
    float somaQuantiades = 0.0;
    float somaPrecos = 0.0;
    for (int i = 0; i < notFisc->qteProds; i++) {
        //printf("A QTE DO PRODUTO %d É %d\n",i,NotFisc.arrayQtes[i]);
        //printf("A PREÇO DE CUSTO DO PRODUTO %d É %f\n\n",i,NotFisc.produtosComprados[i].precoCusto);
        somaQuantiades += notFisc->arrayQtes[i];
        somaPrecos += notFisc->produtosComprados[i].precoCusto * notFisc->arrayQtes[i];

    }

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
    notFisc->total = notFisc->prFrete + notFisc->imposto + somaPrecos;
    //printf("DEBUG: O TOTAL É %f + %f = %f\n", notFisc->prFrete, notFisc->imposto, notFisc->total);
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

    if (opcPagamento == 1) {

        //printf("VALOR DO CAIXA: %f, VALOR DA NOTA: %f\n", somaValores(), notFisc.total);
        //valida o saldo do caixa
        if (somaValores() < notFisc.total) {
            printf("ERRO!\n");
            printf("VALOR DO CAIXA: %f, VALOR DA NOTA: %f\n", somaValores(), notFisc.total);
            exit(1);
        }
        ContaPagar cp;
        cp.caixa = caixaAberto();
        cp.codForn = codForn;
        cp.codigo = maiorCodContasPagar() + 1;
        cp.data = getDataHoje();
        strcpy(cp.descricao, "Pagamento_a_vista");
        strcpy(cp.status, "Concluido");
        cp.valor = notFisc.total;

        if (bd == 1) {
            cadastrarContaPagarTXT(cp);
            printf("Conta cadastrada com sucesso\n");
        }
        if (bd == 2) {
            cadastrarContaPagarBIN(&cp, 1);
            printf("Conta cadastrada com sucesso\n");
        }


        notFisc.codCaixa = getCaixaAtual(getDataHoje());
        //printf("DEBUG: O CAIXA É %d\n", notFisc.codCaixa);

        //CADASTRA NOTA
        if (bd == 1) {
            cadastrarNotaFiscalEntradaTXT(notFisc);
            //printf("DEPOIS DO CADASTRO NOTA FISC TXT\n");
            printf("Nota Fiscal cadastrada com sucesso\n");
        }
        if (bd == 2) {
            cadastrarNotaFiscalEntradaBIN(notFisc);
            //printf("DEPOIS DO CADASTRO NOTA FISC BIN\n");
            printf("Nota Fiscal cadastrada com sucesso\n");
        }


    }
    if (opcPagamento == 2) {
        ContaPagar cp;
        float entrada = 0.0;
        int opc = 0;
        printf("Deseja dar um valor de entada? (1- SIM | 2- NÃO)\n");
        scanf("%d%*c", &opc);
        if (opc == 1) {

            printf("Digite o valor da entrada:\n");
            scanf("%f%*c", &entrada);
            //VALIDA O SALDO DO CAIXA
            if (somaValores() < entrada) {
                printf("ERRO!\n");
                printf("VALOR DO CAIXA: %f, VALOR DA NOTA: %f\n", somaValores(), notFisc.total);
                exit(1);
            }

            cp.caixa = caixaAberto();
            cp.codForn = codForn;
            cp.codigo = maiorCodContasPagar() + 1;
            cp.data = getDataHoje();
            strcpy(cp.descricao, "Entrada");
            strcpy(cp.status, "Concluido");
            cp.valor = entrada;


            notFisc.codCaixa = getCaixaAtual(getDataHoje());
            //CADASTRA A CONTA DA ENTRADA
            if (bd == 1) {
                cadastrarContaPagarTXT(cp);
                printf("Conta cadastrada com sucesso\n");
            }
            if (bd == 2) {
                cadastrarContaPagarBIN(&cp, 1);
                printf("Conta cadastrada com sucesso\n");
            }


        }

        int parcelas;
        printf("Digite o número de parcelas:\n");
        scanf("%d%*c", &parcelas);
        //CADASTRA UMA CONTA PARA CADA PARCELA

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
        somaDias(&(cp.data), 30);

        strcpy(cp.descricao, "Parcela_Nota_Fiscal");
        cp.codForn = codForn;
        cp.valor = ((notFisc.total - entrada) / parcelas);
        strcpy(cp.status, "Pendente");

        for (int i = 0; i < parcelas; i++) {
            //CADASTRA A CONTA
            if (bd == 1) {
                cadastrarContaPagarTXT(cp);
            }
            if (bd == 2) {
                cadastrarContaPagarBIN(&cp, 1);
            }

            //printf("DEBUG: NO FOR (%d) MES = %d\n", i, cp.data.mes);
            somaDias(&(cp.data), 30);
        }

        //CADASTRA NOTA
        if (bd == 1) {
            cadastrarNotaFiscalEntradaTXT(notFisc);
        }
        if (bd == 2) {
            cadastrarNotaFiscalEntradaBIN(notFisc);
        }


    }

    if (opcPagamento != 1 && opcPagamento != 2) {
        printf("OPÇÃO INVÁLIDA\n");
        menuEntradaProdutos();
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

/*void ComprarProdutos2() {
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
 */