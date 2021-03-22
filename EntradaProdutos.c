/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include "SalvametoBD.h"
#include "EntradaProdutos.h"

void cadastrarNotaFiscalEntradaBIN(NotaFiscalEntrada nota) {
    printf("DEBUG: ENTROU NO CADASTRO\n");
    FILE* arqEntradaProdutos;
    //abre o arquivo de hospedes.bin
    arqEntradaProdutos = fopen(".\\arquivos\\EntradaProdutos.bin", "ab");
    if (arqEntradaProdutos == NULL) {
        //se não existir, cria um novo.
        arqEntradaProdutos = fopen(".\\arquivos\\EntradaProdutos.bin", "wb");
        if (arqEntradaProdutos == NULL) {
            printf("ERRO DE ABERTURA\n");
        }

    } else {
        int count = 0; //variavel para validar se gravou ou não
        //grava no arquivo binário
        count = fwrite(&nota, sizeof (NotaFiscalEntrada), 1, arqEntradaProdutos);
        fflush(arqEntradaProdutos);
        //fecha o arquivo
        fclose(arqEntradaProdutos);
        //libera mémoria
        free(arqEntradaProdutos);
        fclose(arqEntradaProdutos);
        //return count;
    }
}