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

void menuVendaAVista() {
    int bd = listar();
    Produto p;
    int codProd;
    int qte;
    printf("Digite o cód do produto: \n");
    scanf("%d%*c", &codProd);
    if (validarCodProdConsumo(codProd, bd) == 1) {
        printf("NÃO EXISTE PRODUTO COM ESSE COD\n");
        return;
    }else{
        if(bd == 1){
            p = getProdutoByCodTXT(codProd);
        }
        if(bd == 2){
            p = getProdutoByCodBIN(codProd);
        }
    }

    printf("Digite a qte do produto: \n");
    scanf("%d%*c", &qte);
    
    if(p.estoque < qte){
        printf("SEM ESTOQUE SUFICIENTE DO PRODUTO\n");
        return;
    }else{
        float prTotal = p.precoVenda * qte;
        printf("O PREÇO TOTAL É: %.2f * %d = %.2f\n",p.precoVenda,qte,prTotal);
        
        p.estoque -= qte;
        if(bd == 1){
            atualizarProdutoTXT(p);
        }
        if(bd == 2){
            atualizarProdutoBIN(p);
        }
        
        ContaReceber cr;
        cr.caixa = caixaAberto().codigo;
        cr.codigo = maiorCodContaReceber()+1;
        cr.data = getDataHoje();
        //cr.pagamento = "A_Vista";
        strcpy(cr.pagamento,"A_Vista");
        cr.valor = prTotal;
        //cr.status = "Pago";
        strcpy(cr.status,"Pago");
        
        if(bd == 1){
            cadastrarContaReceberTXT(cr);
        }
        if(bd == 2){
            cadastrarContaReceberBIN(&cr,1);
        }
        
    }
}