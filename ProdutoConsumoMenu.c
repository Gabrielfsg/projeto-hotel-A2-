/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "Produto.h"
#include "ProdutoConsumoMenu.h"
#include "Principal.h"
#include "SalvametoBD.h"
#include "Hospede.h"

void menuCRUDProdConsumo() {
    int sair = 0;
    int opc;
    while (sair == 0) {
        printf("******* GESTÃO DE DADOS - PRODUTOS DOS HÓSPEDES **********\n");
        printf("Opções: \n");
        printf("1.Cadastrar Produto. \n");
        printf("2.Alterar Dados do Produto. \n");
        printf("3.Visualizar Produtos. \n");
        printf("4.Visualizar Produtos por Codigo. \n");
        printf("5.Excluir Produto. \n");
        printf("6.Voltar. \n");
        printf("Digite a opção desejada: \n");
        scanf("%d%*c", &opc);
        switch (opc) {
            case 1:
                cadastrarProdConsumoControl();
                break;
            case 2:
                atualizarProdConsumoControl();
                break;
            case 3:
                listarProdConsumoControl();
                break;
            case 4:
                getProdConsumoByCodControl();
                break;
            case 5:
                deletarProdConsumoControl();
                break;
            case 6:
                sair = 1;
                subCadastros();
                break;
            default:
                printf("OPÇÃO INVÁLIDA!\n");

                break;
        }

    }
}

/*
 * FUNÇÃO: cadastrarProdConsumoControl 
 * 
 * Cadastra um Produto, validando o código e verificando a extensão do arquivo 
 * 
 * PARÂMETROS: nenhum
 * 
 * RETORNO: Void
 */
void cadastrarProdConsumoControl() {
    printf("***** CADASTRAR PRODUTO *****\n");
    Produto p;
    int cod;
    int ext = listar(); //pega a extensão do arquivo

    printf("Digite o cod do Produto \n");
    scanf("%d%*c", &cod);
    //valida para ver se já existe
    if (validarCodProdConsumo(cod, ext) == 0) {
        return;
    } else {
        p.codigo = cod;


        //PEGA OS DADOS
        printf("Digite a descrição do Produto \n");
        //scanf("%[^\n]s%*c", &p.descricao); 
        fgets(p.descricao, 101, stdin);
        strtok(p.descricao, "\n"); // Esse comando serve para retirar o \n que o fgets coloca no final da string lida

        printf("Digite o estoque do Produto\n");
        scanf("%d%*c", &p.estoque);

        printf("Digite o estoque mínimo do Produto \n");
        scanf("%d%*c", &p.estoqueMinimo);

        setbuf(stdin, NULL);
        printf("Digite o preço de custo do Produto \n");
        scanf("%f%*c", &p.precoCusto);

        printf("Digite o preço de venda do Produto\n");
        scanf("%f%*c", &p.precoVenda);

        //TESTE
        /*printf("#############\n");
        printf("COD: %d\n",p.codigo);
        printf("DESC: %s\n",p.descricao);
        printf("ES: %d\n",p.estoque);
        printf("ESM: %d\n",p.estoqueMinimo);
        printf("PC: %.2f\n",p.precoCusto);
        printf("PV: %.2f\n",p.precoVenda);
        printf("#############\n");
         */

        //VERIFICAR EXTENSÃO DO ARQUIVO
        if (ext == 2) {
            //BIN
            int retorno = cadastrarProdutoBIN(p);
            if (retorno == 1) {
                printf("\nPRODUTO CADASTRADO COM SUCESSO\n");
            } else {
                printf("\nERRO AO CADASTRAR PRODUTO\n");
            }

        }
        if (ext == 1) {
            //TXT
            int retorno = cadastrarProdutoTXT(p);
            if (retorno > 0) {
                printf("\nPRODUTO CADASTRADO COM SUCESSO\n");
            } else {
                printf("\nERRO AO CADASTRAR PRODUTO\n");
            }
        }
    }
}

/*
 * FUNÇÃO: atualizarProdConsumoControl 
 * 
 * Atualiza os dados de um Produto específico, na extensão escolhida.
 * 
 * PARÂMETROS: nenhum
 * 
 * RETORNO: void
 */
void atualizarProdConsumoControl() {
    printf("***** ALTERAR DADOS DO PRODUTO *****\n");
    int cod;
    Produto novoProduto;
    int ext = listar(); //pega a extensão do arquivo
    printf("Digite o cod do Produto \n");
    scanf("%d%*c", &cod);

    if (validarCodProdConsumo(cod, ext) == 1) {
        printf("CÓDIGO NÃO CADASTRADO\n");
        return;
    } else {
        novoProduto.codigo = cod;

        //pega os dados
        printf("Digite a nova descrição do produto\n");
        fgets(novoProduto.descricao, 101, stdin);
        strtok(novoProduto.descricao, "\n");

        printf("Digite o novo estoque do Produto \n");
        scanf("%d%*c", &novoProduto.estoque);
        printf("Digite o novo estoque minimo do Produto \n");
        scanf("%d%*c", &novoProduto.estoqueMinimo);
        printf("Digite o novo preco de custo do Produto \n");
        scanf("%f%*c", &novoProduto.precoCusto);
        printf("Digite o novo preco de venda do Produto \n");
        scanf("%f%*c", &novoProduto.precoVenda);

        if (ext == 2) {
            //BIN
            atualizarProdutoBIN(novoProduto);
        }
        if (ext == 1) {
            //TXT
            atualizarProdutoTXT(novoProduto);
        }
    }
}

/*
 * FUNÇÃO: listarProdConsumoControl 
 * 
 * Mostra os dados completos de todos os Produtos cadastrados
 * na extensão escolhida. 
 * 
 * PARÂMETROS: nenhum
 * 
 * RETORNO: Void
 */
void listarProdConsumoControl() {
    //VERIFICAR EXTENSÃO DO ARQUIVO
    int ext = listar();
    int numProdutos;
    Produto* arrayProdutos;
    if (ext == 2) {
        //BIN
        numProdutos = 0;
        arrayProdutos = getAllProdutoBIN(&numProdutos);
        //printf("NUM PROD = %d\n", numProdutos);
    }
    if (ext == 1) {
        //TXT
        numProdutos = getNumProdConsumo();
        arrayProdutos = getAllProdutoTXT(numProdutos);

    }
    printf("***** LISTA DE TODOS OS PRODUTOS*****\n");
    for (int i = 0; i < numProdutos; i++) {
        //lista os produtos

        printf("***************\n");
        printf("COD: %d\n", arrayProdutos[i].codigo);
        printf("DESC: %s\n", arrayProdutos[i].descricao);
        printf("ESTOQUE: %d\n", arrayProdutos[i].estoque);
        printf("ESTOQUE MINIMO: %d\n", arrayProdutos[i].estoqueMinimo);
        printf("PREÇO DE CUSTO: %.2f\n", arrayProdutos[i].precoCusto);
        printf("PREÇO DE VENDA: %.2f\n", arrayProdutos[i].precoVenda);
        printf("***************\n");
    }
    printf("\n FIM DA LISTA DE PRODUTOS \n");
}

/*
 * FUNÇÃO: getProdConsumoByCodControl 
 * 
 * Busca um Produto específico por código, na extensão escolhida
 * 
 * PARÂMETROS: nenhum
 * 
 * RETORNO: retorna o Produto, se encontrado, ou termina a função, se não encontrado
 */
Produto getProdConsumoByCodControl() {

    Produto prod;
    int cod;
    int numProdutos = 0;
    printf("Digite o código do Produto que deseja procurar:\n");
    scanf("%d%*c", &cod);
    int ext = listar();
    //VALIDAÇÃO DO COD
    if (validarCodProdConsumo(cod, ext) == 1) {
        printf("CÓDIGO NÃO CADASTRADO\n");
        return;
    } else {

        if (ext == 2) {
            //BIN
            prod = getProdutoByCodBIN(cod);
        }
        if (ext == 1) {
            //TXT
            //numProdutos = getNumProdConsumo();
            prod = getProdutoByCodTXT(cod);
        }

        printf("INFORMAÇÕES DO PRODUTO: \n");
        printf("***************\n");
        printf("COD: %d\n", prod.codigo);
        printf("DESC: %s\n", prod.descricao);
        printf("ESTOQUE: %d\n", prod.estoque);
        printf("ESTOQUE MIN: %d\n", prod.estoqueMinimo);
        printf("PREÇO CUSTO: %f\n", prod.precoCusto);
        printf("PREÇO VENDA: %f\n", prod.precoVenda);
        printf("***************\n");

        return prod;
    }
}

/*
 * FUNÇÃO: deletarProdConsumoControl 
 * 
 * Deleta um Produto específico, na extensão escolhida.
 * 
 * PARÂMETROS: nenhum
 * 
 * RETORNO: void
 */
void deletarProdConsumoControl() {
    printf("***** DELETAR PRODUTO *****\n");

    char confirmacao;
    Produto p;
    int cod;
    printf("Digite o cod do Produto \n");
    scanf("%d%*c", &cod);
    int ext = listar();
    //VALIDAÇÃO DO COD 
    if (validarCodProdConsumo(cod, ext) == 1) {
        printf("CÓDIGO NÃO CADASTRADO\n");
        return;
    }

    //com um código válido, busca o produto.
    if (ext == 2) {
        //BIN
        p = getProdutoByCodBIN(cod);

    }
    if (ext == 1) {
        //TXT
        //int numProdutos = getNumProdConsumo();
        p = getProdutoByCodTXT(cod);
    }

    //mostra o produto e pede uma confirmação do usuário
    printf("INFORMAÇÕES DO PRODUTO: \n");
    printf("***************\n");
    printf("COD: %d\n", p.codigo);
    printf("DESC: %s\n", p.descricao);
    printf("ESTOQUE: %d\n", p.estoque);
    printf("ESTOQUE MIN: %d\n", p.estoqueMinimo);
    printf("PREÇO CUSTO: %f\n", p.precoCusto);
    printf("PREÇO VENDA: %f\n", p.precoVenda);
    printf("***************\n");

    printf("DESEJA REALMENTE DELETAR O PRODUTO? (S / N)\n");
    scanf("%c%*c", &confirmacao);

    if (confirmacao == 'S' || confirmacao == 's') {

        if (ext == 2) {
            //BIN
            deletarProdutoBIN(cod);

        }
        if (ext == 1) {
            //TXT
            deletarProdutoTXT(cod);
        }

    } else {
        printf("OPERAÇÃO CANCELADA\n");
        return;
    }
    printf("PRODUTO DELETADO\n");
}

/*
 * FUNÇÃO: validarCodProdConsumo 
 * 
 * Valida o código de um Produto, na extensão escolhida.
 * 
 * PARÂMETROS: 
 * 
 * cod - o código que será verificado
 * ext - a extensão do arquivo
 * 
 * RETORNO: retorna 1 se o cod não existe, ou 0, se já existe
 */
int validarCodProdConsumo(int cod, int ext) {

    int codExistente = 1;
    Produto* arrayProdutos;
    int numProdutos = 0;
    //pega todos dos produtos, de acordo com a extensão
    if (ext == 2) {
        //BIN
        arrayProdutos = getAllProdutoBIN(&numProdutos);
    }
    if (ext == 1) {
        //TXT
        numProdutos = getNumProdConsumo();
        arrayProdutos = getAllProdutoTXT(numProdutos);
    }

    //verifica se o cod existe
    int i;
    for (i = 0; i < numProdutos; i++) {
        if (cod == arrayProdutos[i].codigo) {
            codExistente = 0;
        }
    }
    free(arrayProdutos);
    if (codExistente == 0) {
        printf("CÓDIGO EXISTENTE\n");
        return 0;
    } else {
        //printf("CÓDIGO NÃO EXISTE\n");
        return 1;
    }
}

void listarProdFaixa(int c1, int c2) {
    //VERIFICAR EXTENSÃO DO ARQUIVO
    int ext = listar();
    int numProdutos;
    Produto* arrayProdutos;
    if (ext == 2) {
        //BIN
        numProdutos = 0;
        arrayProdutos = getAllProdutoBIN(&numProdutos);
        //printf("NUM PROD = %d\n", numProdutos);
    }
    if (ext == 1) {
        //TXT
        numProdutos = getNumProdConsumo();
        arrayProdutos = getAllProdutoTXT(numProdutos);

    }
    printf("***** LISTA DE TODOS OS PRODUTOS*****\n");
    for (int i = 0; i < numProdutos; i++) {
        //lista os produtos
        if (arrayProdutos[i].codigo >= c1 && arrayProdutos[i].codigo <= c2) {
            printf("***************\n");
            printf("COD: %d\n", arrayProdutos[i].codigo);
            printf("DESC: %s\n", arrayProdutos[i].descricao);
            printf("ESTOQUE: %d\n", arrayProdutos[i].estoque);
            printf("ESTOQUE MINIMO: %d\n", arrayProdutos[i].estoqueMinimo);
            printf("PREÇO DE CUSTO: %.2f\n", arrayProdutos[i].precoCusto);
            printf("PREÇO DE VENDA: %.2f\n", arrayProdutos[i].precoVenda);
            printf("***************\n");
        }
    }
    printf("\n FIM DA LISTA DE PRODUTOS \n");
}

void filtrarProdFaixa(int c1, int c2) {
    printf("DEBUG 1\n");
    int bd = listar();
    int n=0;
    Produto *arrayProdutos;
    Produto *arrayFiltrado;
    int qte = 0;
    int index = 0;

    if (bd == 1) {
        n = getNumProdConsumo();
        arrayProdutos = getAllProdutoTXT(n);
    } else if (bd == 2) {
        arrayProdutos = getAllProdutoBIN(&n);
    }


    for (int i = 0; i < n; i++) {
        if (arrayProdutos[i].codigo >= c1 && arrayProdutos[i].codigo <= c2) {
            qte++;
            //printf("QTE: %d \n", qte);
        }
    }

    arrayFiltrado = (Produto *) malloc(sizeof (Produto) * qte);

    for (int i = 0; i < n; i++) {
        if (arrayProdutos[i].codigo >= c1 && arrayProdutos[i].codigo <= c2) {
            arrayFiltrado[index] = arrayProdutos[i];
            index++;
            //printf("ADD PRODUTO: %d \n",arrayFiltrado[index].codigo);
        }
    }

    gerarCSVProdConsumo(arrayFiltrado, qte);
    free(arrayProdutos);
}