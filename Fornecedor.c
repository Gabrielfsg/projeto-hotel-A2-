/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fornecedor.h"

int cadastrarFornecedorTXT(Fornecedor aco) {
    FILE *arq;
    // abre o arquivo com o cursor no final
    arq = fopen("arquivos\\FornecedorTXT.txt", "a");
    if (arq == NULL) {
        // se ele não existir cria um
        arq = fopen("arquivos\\FornecedorTXT.txt", "w");
        if (arq == NULL) {
            printf("\nErro ao acessar arquivo\n");
            return 0;
        }
    }
    // salva arqa campo em uma linha
    fprintf(arq, "%d\r\n%s\r\n%s\r\n%s\r\n%s\r\n%s\r\n%s\r\n%s\r\n%d\r\n%s\r\n%s\r\n%s\r\n%s\r\n", aco.codigo, aco.nomeFantazia, aco.razaoSocial, aco.inscricaoEstadual,
            aco.cnpj, aco.telefone, aco.email, aco.endereco.logradouro, aco.endereco.numero, aco.endereco.bairro,
            aco.endereco.cidade, aco.endereco.cep, aco.endereco.uf); // f
    //fecha o arquivo
    fclose(arq);
    //libera memoria
    free(arq);
    return 1;
}
//metodo salva, sobrescrevendo o array de tamanho num

int salvarFornecedorTXT(Fornecedor *aco, int num) {
    FILE *arq;
    // w pra substituir o arquivo
    arq = fopen("arquivos\\FornecedorTXT.txt", "w");
    if (arq == NULL) {
        printf("\nErro ao abrir arquivo!!");
        return 0;
    } else {
        int i;
        // grava todos os dados do vetor no arquivo
        for (i = 0; i < num; i++) {
            fprintf(arq, "%d\r\n%s\r\n%s\r\n%s\r\n%s\r\n%s\r\n%s\r\n%s\r\n%d\r\n%s\r\n%s\r\n%s\r\n%s\r\n", aco[i].codigo, aco[i].nomeFantazia,
                    aco[i].razaoSocial, aco[i].inscricaoEstadual,
                    aco[i].cnpj, aco[i].telefone, aco[i].email, aco[i].endereco.logradouro, aco[i].endereco.numero, aco[i].endereco.bairro,
                    aco[i].endereco.cidade, aco[i].endereco.cep, aco[i].endereco.uf); // f
        }
    }
    // força salvar arquivo
    fflush(arq);
    //fecha arquivo
    fclose(arq);
    //libera memoria
    free(arq);
    free(aco);
    return 1;
}

Fornecedor * listarFornecedorTXT() {
    int numLinha = 0, i = 0, c;
    FILE *arquivo;
    numLinha = numLinhasFornecedor();
    //area arquivo para leitura apenas "r"
    arquivo = fopen("arquivos\\FornecedorTXT.txt", "r");
    if (arquivo == NULL) {
        arquivo = fopen("arquivos\\FornecedorTXT.txt", "w+");
        if (arquivo == NULL) {
            printf("Erro ao acessar arquivo\n");
            return NULL;
        }
    }
    //instancia vetor com tamanho de numLinha
    Fornecedor *aco = (Fornecedor*) calloc(numLinha, sizeof (Fornecedor));
    i = 0;
    char t[100];
    //printf("linhas %d \n", numLinha);
    for (i = 0; i < numLinha; i++) {
        fgets(t, 100, arquivo);
        aco[i].codigo = atoi(t);
        fgets(aco[i].nomeFantazia, 100, arquivo);
        strtok(aco[i].nomeFantazia, "\r\n");
        //printf("%s", aco[i].nomeFantazia);
        fgets(aco[i].razaoSocial, 100, arquivo);
        strtok(aco[i].razaoSocial, "\r\n");
       // printf("%s", aco[i].razaoSocial);
        fgets(aco[i].inscricaoEstadual, 100, arquivo);
        strtok(aco[i].inscricaoEstadual, "\r\n");
        //printf("%s", aco[i].inscricaoEstadual);
        fgets(aco[i].cnpj, 100, arquivo);
        strtok(aco[i].cnpj, "\r\n");
       // printf("%s", aco[i].cnpj);
        fgets(aco[i].telefone, 100, arquivo);
        strtok(aco[i].telefone, "\r\n");
        //printf("%s", aco[i].telefone);
        fgets(aco[i].email, 100, arquivo);
        strtok(aco[i].email, "\r\n");
        //printf("%s", aco[i].email);
        fgets(aco[i].endereco.logradouro, 100, arquivo);
        strtok(aco[i].endereco.logradouro, "\r\n");
        //printf("%s", aco[i].endereco.logradouro);
        fgets(t, 5, arquivo);
        fgets(aco[i].endereco.bairro, 100, arquivo);
        strtok(aco[i].endereco.bairro, "\r\n");
        //printf("%s", aco[i].endereco.bairro);
        fgets(aco[i].endereco.cidade, 100, arquivo);
        strtok(aco[i].endereco.cidade, "\r\n");
       // printf("%s", aco[i].endereco.cidade);
        fgets(aco[i].endereco.cep, 14, arquivo);
        strtok(aco[i].endereco.cep, "\r\n");
       //printf("%s", aco[i].endereco.cep);
        fgets(aco[i].endereco.uf, 4, arquivo);
        strtok(aco[i].endereco.uf, "\r\n");
        //printf("%s", aco[i].endereco.uf);
        aco[i].endereco.numero = atoi(t);
        fgetc(arquivo);
    }
    //fecha arquivo
    fclose(arquivo);
    //libera memoria
    free(arquivo);
    return aco;
}

int numLinhasFornecedor() {

    FILE *arquivo;
    int numLinha = 0, c;
    //abre arquivo para leitura "r"
    arquivo = fopen("arquivos\\FornecedorTXT.txt", "r");
    if (arquivo == NULL) {
        arquivo = fopen("arquivos\\CategoriaTXT.txt", "w+");
        if (arquivo == NULL) {
            printf("\nErro ao acessar arquivo\n");
            return 0;
        }
    }
    //roda ate que ache o final do arquivo "EOF"
    while ((c = fgetc(arquivo)) != EOF) {
        if (c == '\n') {
            numLinha++;
        }
    }
    //fecha arquivo
    fclose(arquivo);
    //libera memoria
    free(arquivo);
    // divide se por 13 pois acomodação tem 13 linhas
    return (numLinha / 13);
}

int validarFornecedor(int cod) {
    Fornecedor *aco = listarFornecedorTXT();
    if (aco != NULL) {
        int lin = sizeof (*aco) / sizeof (Fornecedor);
        int i;
        for (i = 0; i < lin; i++) {
            if (cod == aco[i].codigo) {
                return 1;
            }
        }
        free(aco);
        return 0;
    }
    return 1;
}

/*Aruivos binarios*/

int cadastrarFornecedorBIN(Fornecedor *aco, int quantidade) {
    FILE *arq;
    //abrea arquivo para escrita e posiciona cursor no final "ab"
    arq = fopen("arquivos\\FornecedorBIN.bin", "ab");
    if (arq == NULL) {
        //cria arquivo para escrita se não houver "wb"
        arq = fopen("arquivos\\FornecedorBIN.bin", "wb");
        if (arq == NULL) {
            printf("\nERRO ao acessar arquivo\n");
            return 0;
        }
    }
    //strlen()-> informa o tamanho de uma string 
    /*grava toda struct de acomodacao no arquivo*/
    fwrite(aco, sizeof (Fornecedor), quantidade, arq);
    fflush(arq);
    /*fecha o arquivo*/
    fclose(arq);
    /*libera mémoria*/
    free(arq);
    return 1;
}

Fornecedor * listarFornecedorBIN(int *numLinha) {
    FILE *arquivo;
    //abrea arquivo para leitura apenas "rb"
    arquivo = fopen("arquivos\\FornecedorBIN.bin", "rb");
    if (arquivo == NULL) {
        //cria arquivo para leitura\escrita se não houver "w+b"
        arquivo = fopen("arquivos\\FornecedorBIN.bin", "w+b");
        if (arquivo == NULL) {
            printf("\nERRO ao acessar arquivo\n");
            return NULL;
        }
    }
    *numLinha = 0;

    Fornecedor c;
    //instancia vetor com tamanho 1 
    Fornecedor *aco = (Fornecedor*) calloc(1, sizeof (Fornecedor));
    //pega a primeira linha se existir
    int r = fread(&c, sizeof (Fornecedor), 1, arquivo);
    if (r > 0) {
        do {
            //soma a +1 no tamanho do vetor o qual comessa com 0
            *numLinha = (*numLinha) + 1;
            // realoca o vetor com o tamanho numLinha, a arqa interação ele realoca um a mais
            aco = realloc(aco, *numLinha * sizeof (Fornecedor));
            //adicionar o struct o vetor,(numLinha -1) pois o vetor comessa sempre por 0
            aco[(*numLinha) - 1] = c;
            //pega o proximo indice, se existir
            fread(&c, sizeof (Fornecedor), 1, arquivo);
            //verifica se chegou no fim do arquivo
        } while (!feof(arquivo));
    } else {
        return NULL;
    }
    //fecha arquivo
    fclose(arquivo);
    //libera memoria
    free(arquivo);
    return aco;
}

int editarFornecedorBIN(Fornecedor aco, int posi) {
    FILE *arquivo;
    //abre arquivo para leitura e escrita, ele deve existir "r+b"
    arquivo = fopen("arquivos\\FornecedorBIN.bin", "r+b");
    if (arquivo == NULL) {
        printf("Erro ao acessar arquivo\n");
        return 0;
    }
    //Posiciona o cursor na posição do struct
    fseek(arquivo, (posi * sizeof (Fornecedor)), SEEK_SET);
    //Substitui o struct de posição posi
    fwrite(&aco, sizeof (Fornecedor), 1, arquivo);
    //fecha arquivo 
    fclose(arquivo);
    //fclose(&aco);
    //libera memoria
    free(arquivo);
    return 1;
}

int validarFornecedorBIN(int cod) {
    int num;
    Fornecedor *aco = listarFornecedorBIN(&num);
    int i;
    for (i = 0; i < num; i++) {
        if (cod == aco[i].codigo) {
            // retorna o indice se achar
            return i;
        }
    }
    free(aco);
    return 0;
}

int removerFornecedorBIN() {
    int status = remove("arquivos\\FornecedorBIN.bin");
    if (status != 0) {
        printf("\nErro na remoção do arquivo.\n");
        return 0;
    }
    return 1;
}
