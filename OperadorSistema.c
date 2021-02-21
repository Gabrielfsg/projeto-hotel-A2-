/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "OperadorSistema.h"

int cadastrarOpBin(OperadorSistema op, int quantidade) {
    FILE *arq;
    //abrea arquivo para escrita e posiciona cursor no final "ab"
    arq = fopen(".\\persist\\operador.bin", "ab");
    if (arq == NULL) {
        //cria arquivo para escrita se não houver "wb"
        arq = fopen(".\\persist\\operador.bin", "wb");
        if (arq == NULL) {
            printf("\nERRO ao acessar arquivo\n");
            return 0;
        }
    }
    //strlen()-> informa o tamanho de uma string 
    /*grava toda struct de operador no arquivo*/
    fwrite(&op, sizeof (OperadorSistema), quantidade, arq);
    fflush(arq);
    /*fecha o arquivo*/
    fclose(arq);
    /*libera mémoria*/
    free(arq);
    return 1;
}

int cadastrarOpTXT(OperadorSistema opera) {
    printf("ENTROU CADASTRAR\n");
    printf("COD = %d\n",opera.codigo);
    printf("SENHA = %s\n",opera.senha);
    
    FILE *arq;
    //abrea arquivo para escrita e posiciona cursor no final "ab"
    arq = fopen(".\\persist\\operadorTXT", "a");
    if (arq == NULL) {
        //cria arquivo para escrita se não houver "wb"
        arq = fopen(".\\persist\\operadorTXT", "w");
        if (arq == NULL) {
            printf("\nERRO ao acessar arquivo\n");
            return 0;
        }
    }

    fprintf(arq, "%d\n%s\n%s\n%s\n", opera.codigo, opera.nome, opera.usuario, opera.senha, opera.permicao);

    fclose(arq);

    free(arq);
    return 1;
}

int salvarOperadorTXT(OperadorSistema *opera, int num) {
    // w pra substituir o arquivo
    FILE *cade = fopen(".\\persist\\operadorTXT", "w");
    if (cade == NULL) {
        printf("\nErro ao abrir arquivo!!");
        return 0;
    } else {
        int i;
        // grava todos os dados do vetor no arquivo
        for (i = 0; i < num; i++) {
            fprintf(cade, "%d\n%s\n%s\n%s\n", opera[i].codigo, opera[i].nome, opera[i].usuario, opera[i].senha, opera[i].permicao); // f
        }
    }
    // força salvar arquivo
    fflush(cade);
    //fecha arquivo
    fclose(cade);
    //libera memoria
    free(cade);
    free(opera);
    return 1;
}

OperadorSistema * listarOpBIN(int *numLinha) {
    FILE *arquivo;
    //abrea arquivo para leitura apenas "rb"
    arquivo = fopen(".\\persist\\operador.bin", "rb");
    if (arquivo == NULL) {
        //cria arquivo para leitura\escrita se não houver "w+b"
        arquivo = fopen(".\\persist\\operador.bin", "w+b");
        if (arquivo == NULL) {
            printf("\nERRO ao acessar arquivo\n");
            return NULL;
        }
    }
    *numLinha = 0;

    OperadorSistema op;
    //instancia vetor com tamanho 1 
    OperadorSistema *opera = (OperadorSistema*) calloc(1, sizeof (OperadorSistema));
    //pega a primeira linha se existir
    int r = fread(&op, sizeof (OperadorSistema), 1, arquivo);
    if (r > 0) {
        do {
            //soma a +1 no tamanho do vetor o qual comessa com 0
            *numLinha = (*numLinha) + 1;
            // realoca o vetor com o tamanho numLinha, a arqa interação ele realoca um a mais
            opera = realloc(opera, *numLinha * sizeof (OperadorSistema));
            //adicionar o struct o vetor,(numLinha -1) pois o vetor comessa sempre por 0
            opera[(*numLinha) - 1] = op;
            //pega o proximo indice, se existir
            fread(&op, sizeof (OperadorSistema), 1, arquivo);
            //verifica se chegou no fim do arquivo
        } while (!feof(arquivo));
    } else {
        return NULL;
    }
    //fecha arquivo
    fclose(arquivo);
    //libera memoria
    free(arquivo);
    return opera;
}

OperadorSistema * listarOpTXT() {
    int numOL = 0, i = 0;
    FILE* arq;
    numOL = contarLinhasTXT(arq);
    arq = fopen(".\\persist\\operadorTXT", "r");
    if (arq == NULL) {
        arq = fopen(".\\persist\\operadorTXT", "w+");
        if (arq == NULL) {
            printf("\nERRO ao acessar arquivo\n");
            return 0;
        }
    }
    char t[100];
    OperadorSistema *opera = (OperadorSistema*) calloc(numOL, sizeof (OperadorSistema));
    for (i = 0; i < numOL; i++) {
        fgets(t, 100, arq);
        opera[i].codigo = atoi(t);
        fgets(opera[i].nome, 100, arq);
        strtok(opera[i].nome, "\r\n");
        //printf("%s", aco[i].nomeFantazia);
        fgets(opera[i].usuario, 100, arq);
        strtok(opera[i].usuario, "\r\n");
        // printf("%s", aco[i].razaoSocial);
        fgets(opera[i].senha, 100, arq);
        strtok(opera[i].senha, "\r\n");
        opera[i].permicao = atoi(t);
    }
    //fecha arquivo
    fclose(arq);
    //libera memoria
    free(arq);
    return opera;
}

int editarOpSBIN(OperadorSistema op, int posi) {
    FILE *arquivo;
    //abre arquivo para leitura e escrita, ele deve existir "r+b"
    arquivo = fopen(".\\persist\\operador.bin", "r+b");
    if (arquivo == NULL) {
        printf("Erro ao acessar arquivo\n");
        return 0;
    }
    //Posiciona o cursor na posição do struct
    fseek(arquivo, (posi * sizeof (OperadorSistema)), SEEK_SET);
    //Substitui o struct de posição posi
    fwrite(&op, sizeof (OperadorSistema), 1, arquivo);
    //fecha arquivo 
    fclose(arquivo);
    //fclose(&aco);
    //libera memoria
    free(arquivo);
    return 1;
}

int editarOperadorTXT(OperadorSistema *opera, OperadorSistema op, int num) {
    int i;
    for (i = 0; i < num; i++) {//sobre escreve os dados
        if ((int) (opera[i].codigo) == (int) (op.codigo)) {
            strcpy(opera[i].nome, op.nome);
            strcpy(opera[i].usuario, op.usuario);
            strcpy(opera[i].senha, op.senha);
            opera[i].permicao = op.permicao;
        }
    }

    return salvarOperadorTXT(opera, num);// chama o metodo que salva de novo os dados no arquivo
}

int removerOperadorBIN() {// função que remove o arquivo bin
    int status = remove(".\\persist\\operador.bin");
    if (status != 0) {
        printf("\nErro na remoção do arquivo.\n");
        return 0;
    }
    return 1;
}

int removerOperadorTXT() {// função que remove o arquivo txt
    int status = remove(".\\persist\\operadorTXT");
    if (status != 0) {
        printf("\nErro na remoção do arquivo.\n");
        return 0;
    }
    return 1;
}

int validarOpBIN(int cod) {//pega código  por parâmetro
    int num;
    OperadorSistema *opera = listarOpBIN(&num);// lista os operadores bin
    int i, aux = 0;
    for (i = 0; i < num; i++) {
        if (cod == opera[i].codigo) {
            return 1;// faz a validação e retorna 1
        }
       
    }
     free(opera);
        return 0;
}

int validarOpTXT(int cod) {
    OperadorSistema *opera = listarOpTXT();//lista os operadores
    if (opera != NULL) {
        int num = contarLinhasTXT();
        int i, aux = 0;
        for (i = 0; i < num; i++) {//verifica se o cod digitado passado por parametro é o msm no vetor
            if (cod == opera[i].codigo) {
                return 1;//se sim retorna 1 que será usado na validação
            }
        }
        free(opera);
        return 0;
    }
}
