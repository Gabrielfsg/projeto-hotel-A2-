/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ProdutoConsumoMenu.h"
#include "ContaReceber.h"
#include "Caixa.h"
#include "MenuCaixa.h"
#include "Venda.h"
#include "VendaProduto.h"

void menuVenderProdutos() {
    int opc = 0;
    while (opc >= 0) {
        printf("******* VENDA DE PRODUTOS **********\n");
        printf("1.Venda a Vista.\n");
        printf("2.Venda para Hóspede de uma Reserva.\n");
        printf("3.Sair.\n");
        scanf("%d%*c", &opc);
        switch (opc) {
            case 1:
                //Vender Produto para hóspedes ou outra pessoa que passe no hotel
                //neste caso, registros nao sao necessários
                menuVendaAVista();
                break;
            case 2:
                menuVendaHospedeReserva();
                break;
            case 3:
                subCaixa();
                break;
            default:
                printf("Valor Invalido!\n");
                break;
        }
    }

}

void menuVendaHospedeReserva() {
    //    Reserva r;
}

void menuVendaAVista() {
    printf("DEBUG: ENTROU VENDA VISTA \n");
    int bd = listar();
    int qteItensDaVenda = 0;
    Produto p;
    Produto* prodVendidos;
    int* arrQte;
    int codProd;
    int qteDigitada;
    int sair = 1;
    prodVendidos = (Produto*) calloc(sizeof (Produto), 1);
    arrQte = (int*) calloc(sizeof (int), 1);

    while (sair == 1) {
        printf("Digite o cód do produto: \n");
        scanf("%d%*c", &codProd);
        if (validarCodProdConsumo(codProd, bd) == 1) {
            printf("NÃO EXISTE PRODUTO COM ESSE COD\n");
            return;
        } else {
            qteItensDaVenda++;
            printf("DEBUG: QTE ITENS AGORA É %d \n", qteItensDaVenda);
            if (bd == 1) {
                p = getProdutoByCodTXT(codProd);
            }
            if (bd == 2) {
                p = getProdutoByCodBIN(codProd);
            }

            printf("Digite a qte do produto: \n");
            scanf("%d%*c", &qteDigitada);

            if (p.estoque < qteDigitada) {
                printf("SEM ESTOQUE SUFICIENTE DO PRODUTO\n");
                return;
            } else {
                printf("DEBUG 1 \n");
                //REALOCA O VETOR
                arrQte = realloc(arrQte, sizeof (int) * qteItensDaVenda);
                printf("DEBUG 2 \n");
                prodVendidos = (Produto*) realloc(prodVendidos, sizeof (Produto) * qteItensDaVenda);
                printf("DEBUG 3 \n");
                prodVendidos[qteItensDaVenda - 1] = p;
                printf("DEBUG 4 \n");
                arrQte[qteItensDaVenda - 1] = qteDigitada;
                printf("DEBUG 5 \n");
            }

            printf("DESEJA CONTINUAR A VENDA? (1-SIM  2-NÃO)\n");
            scanf("%d%*c", &sair);
        }
    }


    printf("TESTES \n");
    printf("QTE ITENS = %d\n", qteItensDaVenda);

    for (int i = 0; i < qteItensDaVenda; i++) {
        printf("VOCE VENDEU O PRODUTO %s (%d) \n", prodVendidos[i].descricao, arrQte[i]);
    }

    float precoTotal = 0.0;
    for (int i = 0; i < qteItensDaVenda; i++) {
        precoTotal += arrQte[i] * prodVendidos[i].precoVenda;
        printf("PR TOTAL = %f\n", precoTotal);
    }
    printf("\n PR TOTAL FINAL = %f\n", precoTotal);
    for (int i = 0; i < qteItensDaVenda; i++) {
        printf("ESTOQUE DO PROD %s ANTES: %d\n", prodVendidos[i].descricao, prodVendidos[i].estoque);
        prodVendidos[i].estoque -= arrQte[i];
        printf("ESTOQUE DO PROD %s DEPOIS: %d\n", prodVendidos[i].descricao, prodVendidos[i].estoque);

        //ATUALIZAR ESTOQUE
        if (bd == 1) {
            printf("ANTES DE ATUALIZAR ESTOQUE\n");
            strtok(prodVendidos[i].descricao, "\r");
            atualizarProdutoTXT(prodVendidos[i]);
            printf("DEPOIS DE ATUALIZAR ESTOQUE\n");
        }
        if (bd == 2) {
            atualizarProdutoBIN(prodVendidos[i]);
        }
    }
    //CADASTRA A VENDA
    Venda v;
    //v.codVenda = maiorCodVenda();
    v.codVenda = 1;
    v.codCaixa = caixaAberto().codigo;
    v.dataVenda = getDataHoje();
    v.valorTotal = precoTotal;

    if (bd == 1) {
        cadastrarVendaTXT(v);
        printf("DEBUG: DEPOIS DO CADASTRO??\n");
    }
    if (bd == 2) {
        cadastrarVendaBIN(v);
    }

    //CADASTRA OS PRODUTOAS DA VENDA
    VendaProduto vp;
    vp.codVenda = v.codVenda;
    printf("\nTESTE  VENDA PRODUTOS\n");
    printf("COD %d = %d \n", vp.codVenda, v.codVenda);

    for (int i = 0; i < qteItensDaVenda; i++) {
        vp.codProduto = prodVendidos[i].codigo;
        vp.quantidade = arrQte[i];
        printf("COD PROD %d | QTE = %d \n", vp.codProduto, vp.quantidade);
        //CADASTRAR PRODUTOS DA VENDA TXT OU BIN
        bd =2;
        if (bd == 1) {
            cadastrarVendaProdutoTXT(vp);
        }
        if (bd == 2) {
            cadastrarVendaProdutoBIN(vp);
        }
    }
    /////////////////////////////////////////
    /*   printf("Digite o cód do produto: \n");
       scanf("%d%*c", &codProd);
       if (validarCodProdConsumo(codProd, bd) == 1) {
           printf("NÃO EXISTE PRODUTO COM ESSE COD\n");
           return;
       } else {

           if (bd == 1) {
               p = getProdutoByCodTXT(codProd);
           }
           if (bd == 2) {
               p = getProdutoByCodBIN(codProd);
           }
       }

       printf("DEBUG: O PROD É %s \n", p.descricao);

       printf("Digite a qte do produto: \n");
       scanf("%d%*c", &qteDigitada);

       if (p.estoque < qteDigitada) {
           printf("SEM ESTOQUE SUFICIENTE DO PRODUTO\n");
           return;
       } else {
           float prTotal = p.precoVenda * qteDigitada;
           printf("O PREÇO TOTAL É: %.2f * %d = %.2f\n", p.precoVenda, qteDigitada, prTotal);

           printf("DEBUG: ESTOQUE ANTES = %d \n", p.estoque);
           p.estoque -= qteDigitada;
           printf("DEBUG: ESTOQUE DEPOIS = %d \n", p.estoque);
           if (bd == 1) {
               printf("DEBUG: ANTES DE ATUALIZAR \n");
               atualizarProdutoTXT(p);
               printf("DEBUG: DEPOIS DE ATUALIZAR \n");
           }
           if (bd == 2) {
               atualizarProdutoBIN(p);
           }

           ContaReceber cr;
           cr.caixa = caixaAberto().codigo;
           cr.codigo = maiorCodContaReceber() + 1;
           cr.data = getDataHoje();
           //cr.pagamento = "A_Vista";
           strcpy(cr.pagamento, "A_Vista");
           cr.valor = prTotal;
           //cr.status = "Pago";
           strcpy(cr.status, "Pago");
           printf("DEBUG: CRIOU CONTA\n");
           if (bd == 1) {
               printf("DEBUG: ANTES DE CADASTRAR CONTA\n");
               cadastrarContaReceberTXT(cr);
               printf("DEBUG: DEPOIS DE CADASTRAR CONTA\n");
           }
           if (bd == 2) {
               cadastrarContaReceberBIN(&cr, 1);
           }



       }
     */
}

/*void menuVendaAVista2() {
    printf("DEBUG: ENTROU VENDA VISTA \n");
    int bd = listar();
    Produto p;
    //Produto* prodVendidos;
    int codProd;
    int qte;
    
    //prodVendidos = (Produto*) calloc(sizeof (Produto), 1);
    
    printf("Digite o cód do produto: \n");
    scanf("%d%*c", &codProd);
    if (validarCodProdConsumo(codProd, bd) == 1) {
        printf("NÃO EXISTE PRODUTO COM ESSE COD\n");
        return;
    } else {
        
        if (bd == 1) {
            p = getProdutoByCodTXT(codProd);
        }
        if (bd == 2) {
            p = getProdutoByCodBIN(codProd);
        }
    }

    printf("DEBUG: O PROD É %s \n", p.descricao);
    
    printf("Digite a qte do produto: \n");
    scanf("%d%*c", &qte);

    if (p.estoque < qte) {
        printf("SEM ESTOQUE SUFICIENTE DO PRODUTO\n");
        return;
    } else {
        float prTotal = p.precoVenda * qte;
        printf("O PREÇO TOTAL É: %.2f * %d = %.2f\n", p.precoVenda, qte, prTotal);

        printf("DEBUG: ESTOQUE ANTES = %d \n",p.estoque);
        p.estoque -= qte;
        printf("DEBUG: ESTOQUE DEPOIS = %d \n",p.estoque);
        if (bd == 1) {
            printf("DEBUG: ANTES DE ATUALIZAR \n");
            atualizarProdutoTXT(p);
            printf("DEBUG: DEPOIS DE ATUALIZAR \n");
        }
        if (bd == 2) {
            atualizarProdutoBIN(p);
        }

        ContaReceber cr;
        cr.caixa = caixaAberto().codigo;
        cr.codigo = maiorCodContaReceber() + 1;
        cr.data = getDataHoje();
        //cr.pagamento = "A_Vista";
        strcpy(cr.pagamento, "A_Vista");
        cr.valor = prTotal;
        //cr.status = "Pago";
        strcpy(cr.status, "Pago");
        printf("DEBUG: CRIOU CONTA\n");
        if (bd == 1) {
            printf("DEBUG: ANTES DE CADASTRAR CONTA\n");
            cadastrarContaReceberTXT(cr);
            printf("DEBUG: DEPOIS DE CADASTRAR CONTA\n");
        }
        if (bd == 2) {
            cadastrarContaReceberBIN(&cr, 1);
        }

        
        
    }
}*/