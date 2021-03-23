/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Produto.h"
#include "ProdutoConsumoMenu.h"

/*
 * FUNÇÃO: cadastrarProdutoTXT 
 * 
 * Cadastra um Produto, escrevendo seus dados na extensão TXT.
 * 
 * PARÂMETROS: 
 * 
 * p - Struct do Produto que será cadastrado
 * 
 * RETORNO: retorna o número de caracteres gravados, ou um número negativo 
 * se não conseguiu gravar
 */
int cadastrarProdutoTXT(Produto p) {
    FILE* arqProduto;
    //abre o arquivo, ou cria um novo se não conseguir abrir
    arqProduto = fopen(".\\arquivos\\produtos.txt", "a");
    if (arqProduto == NULL) {
        arqProduto = fopen(".\\arquivos\\produtos.txt", "w");
    }
    int retorno;
    retorno = fprintf(arqProduto, "Cod: %d\r\nDESC: %s\r\nESTOQUE: %d\r\nESTOQUE_MIN: %d\r\nPRCUSTO: %f\r\nPRVENDA: %f\r\n", p.codigo, p.descricao, p.estoque, p.estoqueMinimo, p.precoCusto, p.precoVenda);

    fflush(arqProduto);
    fclose(arqProduto);
    return retorno;

}

/*
 * FUNÇÃO: cadastrarProdutoBIN 
 * 
 * Cadastra um Produto, escrevendo seus dados na extensão TXT.
 * 
 * PARÂMETROS: 
 * 
 * p - Struct do Produto que será cadastrado
 * 
 * RETORNO: retorna o número de produtos gravados, ou seja, 1 se conseguiu
 * gravar, ou 0, se não conseguiu
 */
int cadastrarProdutoBIN(Produto p) {
    FILE* arqProduto;
    //abre o arquivo, ou cria um novo se não conseguir abrir
    arqProduto = fopen(".\\arquivos\\produtos.bin", "ab");
    if (arqProduto == NULL) {
        arqProduto = fopen(".\\arquivos\\produtos.bin", "wb");
        if (arqProduto == NULL) {
            printf("ERRO AO LER ARQUIVO DE PRODUTOS\n");
        }

    } else {
        int count = 0;
        count = fwrite(&p, sizeof (Produto), 1, arqProduto);

        fflush(arqProduto);
        /*fecha o arquivo*/
        fclose(arqProduto);
        /*libera mémoria*/
        free(arqProduto);
        fclose(arqProduto);
        return count;
    }
}

/*
 * FUNÇÃO: atualizarProdutoTXT 
 * 
 * Atualiza um Produto cadastrado no arquivo TXT.
 * Este método copia todos os Produtos cadastrados para um arquivo temporário,
 * e quando encontrar o cod do Produto que será alterado, ele grava os dados 
 * novos desse Produto.
 * 
 * PARÂMETROS: 
 * 
 * novoProd - Struct com os novos dados do Produto que será alterado.
 * 
 * RETORNO: void
 * 
 * OBS: No processo de atualização, o cod do Produto não é alterado.
 * 
 */
void atualizarProdutoTXT(Produto novoProd) {
    printf("ENTROU ATUALIZAR PROD\n");
    FILE* arqProduto = fopen(".\\arquivos\\produtos_temp.txt", "w");
    if (arqProduto == NULL) {
        printf("ERRO AO ABRIR ARQUIVO");
    } else {
        //pega a lista de todos os produtos
        int numProdutos = getNumProdConsumo();
        Produto* arrProduto = getAllProdutoTXT(numProdutos);

        for (int i = 0; i < numProdutos; i++) {
            /*
            se o codigo do produto for diferente do codigo do produto que será
            alterado, copia os mesmos dados
             */
            if (arrProduto[i].codigo != novoProd.codigo) {
                //printf("%d != %d\n", arrProduto[i].codigo, novoProd.codigo);
                strtok(novoProd.descricao, "\r");
                fprintf(arqProduto, "Cod: %d\r\nDESC: %s\nESTOQUE: %d\r\nESTOQUE_MIN: %d\r\nPRCUSTO: %f\r\nPRVENDA: %f\r\n", arrProduto[i].codigo, arrProduto[i].descricao, arrProduto[i].estoque, arrProduto[i].estoqueMinimo, arrProduto[i].precoCusto, arrProduto[i].precoVenda);
                fflush(arqProduto);

            } else {
                //printf("ESSE É O QUE VAI ALTERAR: COD = %d\n", novoProd.codigo);
                //se for o produto que vai alterar, copia os novos dados
                fprintf(arqProduto, "Cod: %d\r\nDESC: %s\r\nESTOQUE: %d\r\nESTOQUE_MIN: %d\r\nPRCUSTO: %f\r\nPRVENDA: %f\r\n", novoProd.codigo, novoProd.descricao, novoProd.estoque, novoProd.estoqueMinimo, novoProd.precoCusto, novoProd.precoVenda);
                fflush(arqProduto);
            }
        }

        fclose(arqProduto);
        free(arrProduto);
        /*
        remove o arquivo antigo e renomeia o arquivo temporário, que agora será 
        o arquivo atualizado
         */
        remove(".\\arquivos\\produtos.txt");
        rename(".\\arquivos\\produtos_temp.txt", ".\\arquivos\\produtos.txt");
    }

}

/*
 * FUNÇÃO: atualizarProdutoBIN 
 * 
 * Atualiza um Produto cadastrado no arquivo BIN.
 * Este método copia todos os Produtos cadastrados para um arquivo temporário,
 * e quando encontrar o cod do Produto que será alterado, ele grava os dados 
 * novos desse Produto.
 * 
 * PARÂMETROS: 
 * 
 * novoProd - Struct com os novos dados do Produto que será alterado.
 * 
 * RETORNO: void
 * 
 * OBS: No processo de atualização, o cod do Produto não é alterado.
 * 
 */
void atualizarProdutoBIN(Produto novoProd) {
    FILE* arqProduto = fopen(".\\arquivos\\produtos_temp.bin", "wb");
    if (arqProduto == NULL) {
        printf("ERRO AO ABRIR ARQUIVO");
    } else {
        //pega a lista de todos os produtos
        int numProdutos = 0;
        Produto* arrProdutos = getAllProdutoBIN(&numProdutos);

        for (int i = 0; i < numProdutos; i++) {
            /*
            se o codigo do produto for diferente do codigo do produto que será
            alterado, copia os mesmos dados
             */
            if (arrProdutos[i].codigo != novoProd.codigo) {
                //printf("ESSE É O QUE NAO VAI ALTERAR %d != %d\n", arrProdutos[i].codigo, novoProd.codigo);
                fwrite(&arrProdutos[i], sizeof (Produto), 1, arqProduto);
                fflush(arqProduto);

            } else {
                //printf("ESSE É O QUE VAI ALTERAR: COD = %d\n", novoProd.codigo);
                //se for o produto que vai alterar, copia os novos dados
                fwrite(&novoProd, sizeof (Produto), 1, arqProduto);
                fflush(arqProduto);
            }
        }

        fclose(arqProduto);
        free(arrProdutos);
        remove(".\\arquivos\\produtos.bin");
        rename(".\\arquivos\\produtos_temp.bin", ".\\arquivos\\produtos.bin");
    }

}

/*
 * FUNÇÃO: getAllProdutoTXT 
 * 
 * Pega todos os Produtos cadastrados na extensão TXT.
 * 
 * PARÂMETROS: 
 * 
 * numProdutos - número total de Produtos do arquivo.
 * 
 * RETORNO: Retorna um Ponteiro (Array) de Produtos, contendo todos os Produtos
 * do aquivo.
 * 
 * OBS: numProdutos é necessário pois na grande maioria das vezes voce vai usar 
 * o array de todos os hóspedes num for, então tecnicamente você já teria esse valor
 * disponível
 */
Produto* getAllProdutoTXT(int numProdutos) {
    int index = 1; //PARA ARMAZENAR O TAMANHO DO VETOR

    Produto *arrayProdutos = (Produto *) malloc(sizeof (Produto) * numProdutos); //PONTEIRO DE HÓSPEDE VIRA UM VETOR AO CHAMAR MALLOC
    if (arrayProdutos == NULL) {
        printf("ERRO DE ALOCAÇÃO");
        exit(1);
    }

    //pega a lista de Produtos do arquivo
    FILE *arqProduto;

    arqProduto = fopen(".\\arquivos\\produtos.txt", "r");
    if (arqProduto == NULL) {
        printf(" ERRO DE LEITURA ");
    } else {

        for (int i = 0; i < numProdutos; i++) {
            Produto p;
            char text[20];

            //FSCANF PARA PEGAR OS VALORES DO ARQUIVO. "TEXT[20]" É APENAS PARA ARMAZENAR A STRING QUE VEM ANTES DO VALOR.
            fscanf(arqProduto, "%s %d", text, &p.codigo);
            fscanf(arqProduto, "%s %[^\n]s", text, p.descricao);
            fscanf(arqProduto, "%s %d", text, &p.estoque);
            fscanf(arqProduto, "%s %d", text, &p.estoqueMinimo);
            fscanf(arqProduto, "%s %f", text, &p.precoCusto);
            fscanf(arqProduto, "%s %f", text, &p.precoVenda);

            //COLOCA O PRODUTO NO ARRAY
            arrayProdutos[index - 1] = p;
            index++;
        }
        fclose(arqProduto);

        /*printf("\n TESTE PARA VER TODOS OS ITENS DO ARRAY \n");
        for (int i = 0; i < index - 1; i++) {
            printf("+++++++++++\n");
            printf("POS: %d -> %d\n", i, arrayProdutos[i].codigo);
            printf("POS: %d -> %s\n", i, arrayProdutos[i].descricao);
            printf("POS: %d -> %d\n", i, arrayProdutos[i].estoque);
            printf("POS: %d -> %d\n", i, arrayProdutos[i].estoqueMinimo);
            printf("POS: %d -> %f\n", i, arrayProdutos[i].precoCusto);
            printf("POS: %d -> %f\n", i, arrayProdutos[i].precoVenda);
            printf("+++++++++++\n");
        }*/
        return arrayProdutos;
    }
}

/*
 * FUNÇÃO: getAllProdutoBIN 
 * 
 * Pega todos os Produtos cadastrados na extensão BIN.
 * 
 * PARÂMETROS: 
 * 
 * numProdutos - Ponteiro que contém o endereço de memória da variável
 * que armazena o número total de Produtos do arquivo
 * 
 * RETORNO: Retorna um Ponteiro (Array) de Produtos, contendo todos os Produtos
 * do aquivo.
 * 
 * OBS: Neste caso, *numProdutos deve ser iniciado em 0, pois este método irá
 * incrementá-lo em 1 cada vez que ler um Produto, retornando, no fim, o número
 * total de Produtos do arquivo.
 */
Produto* getAllProdutoBIN(int* numProdutos) {

    int totalLido = 0;
    int index = 0;
    Produto *arrayProdutos = (Produto *) malloc(sizeof (Produto) * 1); //PONTEIRO DE PRODUTOS VIRA UM VETOR AO CHAMAR MALLOC
    if (arrayProdutos == NULL) {
        printf("ERRO DE ALOCAÇÃO");
        exit(1);
    }

    FILE *arqProduto;
    //abre o arquivo, ou cria um novo se nao conseguir abrir
    arqProduto = fopen(".\\arquivos\\produtos.bin", "rb");
    if (arqProduto == NULL) {
        arqProduto = fopen(".\\arquivos\\produtos.bin", "wb");
        if (arqProduto == NULL) {
            printf("ERRO DE LEITURA ");
        }
    } else {

        while (!feof(arqProduto)) { //enquanto não for o final do arquivo
            Produto p;
            //lê um produto do arquivo e incrementa o número de produtos
            int conseguiuLer = fread(&p, sizeof (Produto), 1, arqProduto);
            if (conseguiuLer == 1) {
                //printf("LEU UM PRODUTO\n");
                (*numProdutos)++;
            } else {
                //printf("ERRO\n");
            }
            arrayProdutos[index] = p;
            index++;
            //realoca o vetor
            arrayProdutos = realloc(arrayProdutos, (index + 1) * sizeof (Produto));
            //printf("INDEX = %d\n", index);
        }

        fclose(arqProduto);

        return arrayProdutos;
    }
}

/*
 * FUNÇÃO: getProdutoByCodTXT 
 * 
 * Pega um Produto específico cadastrado na extensão TXT.
 * 
 * PARÂMETROS: 
 * 
 * cod - código do Produto que será retornado
 * 
 * RETORNO: Retorna o Produto encontrado, ou termina a função, se não encontrado.
 * 
 */
Produto getProdutoByCodTXT(int cod) {

    int numProdutos = getNumProdConsumo();
    if (validarCodProdConsumo(cod, 1) == 0) {
        Produto* arrayProdutos = getAllProdutoTXT(numProdutos);
        for (int i = 0; i < numProdutos; i++) {
            if (arrayProdutos[i].codigo == cod) {
                //printf("\nACHOU O COD == AO QUE DIGITOU: %d == %s\n",cod,arrHospedes[i].nome);
                return arrayProdutos[i];
            }
        }
    } else {
        printf("NÃO EXISTE PRODUTO CADASTRADO COM ESSE CODIGO\n");
        return;
    }

}

/*
 * FUNÇÃO: getProdutoByCodBIN 
 * 
 * Pega um Produto específico cadastrados na extensão BIN.
 * 
 * PARÂMETROS: 
 * 
 * cod - código do Hóspede que será retornado
 * numProdutos - número total de hóspedes do arquivo
 * 
 * RETORNO: Retorna o Produto encontrado, ou termina a função, se não encontrado.
 * 
 * OBS: numProdutos é necessário pois na grande maioria das vezes voce vai usar 
 * o array de todos os hóspedes num for, então tecnicamente você já teria esse valor
 * disponível
 */
Produto getProdutoByCodBIN(int cod) {
    
    Produto prod;
    int numProdutos = 0;
    if (validarCodProdConsumo(cod, 2) == 0) {
        Produto* arrayProdutos = getAllProdutoBIN(&numProdutos);
        for (int i = 0; i < numProdutos; i++) {
            if (arrayProdutos[i].codigo == cod) {
                //printf("COD %d == %d\n", arrayProdutos[i].codigo, cod);
                prod = arrayProdutos[i];
                return prod;
            }
        }
    } else {
        printf("NÃO EXISTE PRODUTO CADASTRADO COM ESSE CODIGO\n");
        return;
    }

}

/*
 * FUNÇÃO: deletarProdutoTXT 
 * 
 * Deleta um Produto específico no arquivo TXT.
 * Este método copia todos os Produtos cadastrados para um arquivo temporário,
 * exceto o Produto que será deletado.
 * PARÂMETROS: 
 * 
 * cod - código do Produto que será deletado.
 * 
 * RETORNO: void
 */
void deletarProdutoTXT(int cod) {
    //cria um arquivo temporário
    FILE* arqProduto = fopen(".\\arquivos\\produtos_temp.txt", "w");
    if (arqProduto == NULL) {
        printf("ERRO");
    } else {
        //pega a lista da todos os produtos
        int numProdutos = getNumProdConsumo();
        Produto* arrayProdutos = getAllProdutoTXT(numProdutos);

        //copia todos os produtos para o arquivo, menos o que será deletado
        for (int i = 0; i < numProdutos; i++) {
            if (arrayProdutos[i].codigo != cod) {

                strtok(arrayProdutos[i].descricao, "\r");
                fprintf(arqProduto, "Cod: %d\r\nDESC: %s\r\nESTOQUE: %d\r\nESTOQUE_MIN: %d\r\nPRCUSTO: %f\r\nPRVENDA: %f\r\n", arrayProdutos[i].codigo, arrayProdutos[i].descricao, arrayProdutos[i].estoque, arrayProdutos[i].estoqueMinimo, arrayProdutos[i].precoCusto, arrayProdutos[i].precoVenda);
                fflush(arqProduto);

            }
        }

        fclose(arqProduto);
        free(arrayProdutos);
        /*
        remove o arquivo antigo e renomeia o arquivo temporário, que agora será 
        o arquivo atualizado
         */
        remove(".\\arquivos\\produtos.txt");
        rename(".\\arquivos\\produtos_temp.txt", ".\\arquivos\\produtos.txt");
    }
}

/*
 * FUNÇÃO: deletarProdutoBIN 
 * 
 * Deleta um Produto específico no arquivo BIN.
 * Este método copia todos os Produtos cadastrados para um arquivo temporário,
 * exceto o Produto que será deletado.
 * PARÂMETROS: 
 * 
 * cod - código do Produto que será deletado.
 * 
 * RETORNO: void
 */
void deletarProdutoBIN(int cod) {
    //cria um arquivo temporário
    FILE* arqProduto = fopen(".\\arquivos\\produtos_temp.bin", "wb");
    if (arqProduto == NULL) {
        printf("ERRO");
    } else {
        //pega a lista da todos os produtos
        int numProdutos = 0;
        Produto* arrayProdutos = getAllProdutoBIN(&numProdutos);

        //copia todos os produtos para o arquivo, menos o que será deletado
        for (int i = 0; i < numProdutos; i++) {
            if (arrayProdutos[i].codigo != cod) {
                Produto p = arrayProdutos[i];
                fwrite(&p, sizeof (Produto), 1, arqProduto);

            }

        }

        fclose(arqProduto);
        free(arrayProdutos);
        /*
        remove o arquivo antigo e renomeia o arquivo temporário, que agora será 
        o arquivo atualizado
         */
        remove(".\\arquivos\\produtos.bin");
        rename(".\\arquivos\\produtos_temp.bin", ".\\arquivos\\produtos.bin");
    }
}

/*
 * FUNÇÃO: getNumProdConsumo 
 * 
 * Calcula o número de Produtos cadastrados no arquivo TXT com base no número
 * de linhas do arquivo
 * 
 * PARÂMETROS: nenhum
 * 
 * RETORNO: Retorna o número de Produtos 
 * 
 * OBS: ESTE MÉTODO É SOMENTE USADO PARA A EXTENSÃO TXT
 */
int getNumProdConsumo() {

    FILE *arq;
    int numLinhas = 0, numProdutos = 0;
    char c;
    arq = fopen(".\\arquivos\\produtos.txt", "r");
    if (arq == NULL) {
        arq = fopen(".\\arquivos\\produtos.txt", "w");
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
