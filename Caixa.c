/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "Caixa.h"
#include <string.h>

int maiorCodCaixa() {
    //printf("DEBUG 1  MAIOR COD\n");
    int bd = listar();
    int num;
    Caixa *cr;
    if (bd == 1) {
        //num = numContaReceber();
        num = numCaixa();
        if (num > 0) {
            //cr = listarContaReceberTXT();
            cr = listarCaixaTXT();
        } else {
            return 0;
        }
        //printf("DEBUG 2A \n");
    } else {
        cr = listarCaixaBIN(&num);
        if (num == 0) {
            return 0;
        }
    }
    int i, aux = 0;
    //printf("DEBUG 3A \n");
    for (i = 0; i < num; i++) {
        if (cr[i].codigo > aux) {
            aux = cr[i].codigo;
        }
    }
    return aux;
}

int getCaixaAtual(Data dataHoje) {
    Caixa *cai;
    int num;
    int bd = listar();
    if (bd == 1) {
        cai = listarCaixaTXT();
        num = numCaixa();
    } else {
        cai = listarCaixaBIN(&num);
    }
    int i;
    for (i = 0; i < num; i++) {
        if ((compararDatas(cai[i].data, dataHoje) == 1 && strcmp(cai[i].status, "aberto") == 0) || strcmp(cai[i].status, "aberto") == 0) {
            return cai[i].codigo;
        }
    }
    return 0;
}

Caixa caixaAberto() {
    Caixa *cai;
    int num = 0;
    int bd = listar();
    if (bd == 1) {
        num = numCaixa();
        if (num > 0) {
            cai = listarCaixaTXT();
        }
    } else {
        cai = listarCaixaBIN(&num);
    }
    int i;
    if (num > 0) {
        for (i = 0; i < num; i++) {
            if (strcmp(cai[i].status, "aberto") == 0) {
                return cai[i];
            }
        }
    } else {
        Caixa c;
        c.codigo = 0;
        return c;
    }

}

int cadastrarCaixaTXT(Caixa aco) {
    FILE *arq;
    // abre o arquivo com o cursor no final
    arq = fopen("arquivos\\CaixaTXT.txt", "a");
    if (arq == NULL) {
        // se ele não existir cria um
        arq = fopen("arquivos\\CaixaTXT.txt", "w");
        if (arq == NULL) {
            printf("\nErro ao acessar arquivo\n");
            return 0;
        }
    }
    // salva arqa campo em uma linha
    fprintf(arq, "%d\n%d\n%d\n%d\n%f\n%f\n%s\n", aco.codigo, aco.data.dia, aco.data.mes, aco.data.ano, aco.valorIn, aco.valorFin, aco.status); // f
    //fecha o arquivo
    fclose(arq);
    //libera memoria
    free(arq);

    return 1;
}
//metodo salva, sobrescrevendo o array de tamanho num

int salvarCaixaTXT(Caixa *aco, int num) {
    FILE *cad;
    // w pra substituir o arquivo
    cad = fopen("arquivos\\CaixaTXT.txt", "w");
    if (cad == NULL) {
        printf("\nErro ao abrir arquivo!!");
        return 0;
    } else {
        int i;
        // grava todos os dados do vetor no arquivo
        for (i = 0; i < num; i++) {
            fprintf(cad, "%d\n%d\n%d\n%d\n%f\n%f\n%s\n", aco[i].codigo, aco[i].data.dia, aco[i].data.mes, aco[i].data.ano, aco[i].valorIn, aco[i].valorFin, aco[i].status); // f
        }
    }
    // força salvar arquivo
    fflush(cad);
    //fecha arquivo
    fclose(cad);
    //libera memoria
    free(cad);
    free(aco);
    return 1;
}

int fecharCaixaTXT(Caixa c) {
    FILE *arq;
    Caixa *aco = listarCaixaTXT();
    int num = numCaixa();
    int i;
    for (i = 0; i < num; i++) {
        if (aco[i].codigo == c.codigo) {
            aco[i] = c;
        }
    }
    // w pra substituir o arquivo
    arq = fopen("arquivos\\CaixaTXT.txt", "w");
    if (arq == NULL) {
        printf("\nErro ao abrir arquivo!!");
        return 0;
    } else {
        int i;
        // grava todos os dados do vetor no arquivo
        for (i = 0; i < num; i++) {
            fprintf(arq, "%d\n%d\n%d\n%d\n%f\n%f\n%s\n", aco[i].codigo, aco[i].data.dia, aco[i].data.mes, aco[i].data.ano, aco[i].valorIn, aco[i].valorFin, aco[i].status); // f
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

Caixa * listarCaixaTXT() {
    int numLinha = 0, i = 0;
    FILE *arquivo;
    numLinha = numCaixa(arquivo);
    //area arquivo para leitura apenas "r"
    arquivo = fopen("arquivos\\CaixaTXT.txt", "r");
    if (arquivo == NULL) {
        arquivo = fopen("arquivos\\CaixaTXT.txt", "w+");
        if (arquivo == NULL) {
            printf("Erro ao acessar arquivo\n");
            return NULL;
        }
    }
    //instancia vetor com tamanho de numLinha
    Caixa *aco = (Caixa*) calloc(numLinha, sizeof (Caixa));
    i = 0;
    char t[100];
    for (i = 0; i < numLinha; i++) {
        fgets(t, 100, arquivo);
        aco[i].codigo = atoi(t);
        fgets(t, 100, arquivo);
        aco[i].data.dia = atoi(t);
        fgets(t, 100, arquivo);
        aco[i].data.mes = atoi(t);
        fgets(t, 100, arquivo);
        aco[i].data.ano = atoi(t);
        fgets(t, 100, arquivo);
        aco[i].valorIn = atof(t);
        fgets(t, 100, arquivo);
        aco[i].valorFin = atof(t);
        fgets(aco[i].status, 100, arquivo);
        strtok(aco[i].status, "\n\r");
        strtok(aco[i].status, "\n\r");
    }
    //fecha arquivo
    fclose(arquivo);
    //libera memoria
    free(arquivo);

    return aco;
}

int numCaixa() {
    //printf("num linhas");
    FILE *arquivo;
    int numLinha = 0, c;
    //abre arquivo para leitura "r"
    arquivo = fopen("arquivos\\CaixaTXT.txt", "r");
    if (arquivo == NULL) {
        arquivo = fopen("arquivos\\CaixaTXT.txt", "w+");
        if (arquivo == NULL) {
            printf("\nErro ao acessar arquivo\n");
            return 0;
        }
    }
    //roda ate que ache o final do arquivo "EOF"
    while ((c = fgetc(arquivo)) != EOF) {
        if (c == '\n') {
            //soma a quantidade de linhas do TXT, mas não a quantidade de acoegorias
            numLinha++;
        }
    }
    //fecha arquivo
    fclose(arquivo);
    //libera memoria
    free(arquivo);
    // divide se por 4 pois acomodação tem 4 linhas
    if (numLinha == 0) {
        return 0;
    }

    return numLinha / 7;
}

int validarCaixa(int cod) {
    Caixa *aco = listarCaixaTXT();
    if (aco != NULL) {
        int lin = numCaixa();
        int i;
        for (i = 0; i < lin; i++) {
            if (cod == aco[i].codigo) {
                return 1;
            }
        }
        free(aco);

        return 0;
    }
    return 0;
}

/*Aruivos binarios*/

int cadastrarCaixaBIN(Caixa *aco, int quantidade) {
    FILE *arq;
    //abrea arquivo para escrita e posiciona cursor no final "ab"
    arq = fopen("arquivos\\CaixaBIN.bin", "ab");
    if (arq == NULL) {
        //cria arquivo para escrita se não houver "wb"
        arq = fopen("arquivos\\CaixaBIN.bin", "wb");
        if (arq == NULL) {
            printf("\nERRO ao acessar arquivo\n");
            return 0;
        }
    }
    //strlen()-> informa o tamanho de uma string 
    /*grava toda struct de acomodacao no arquivo*/
    fwrite(aco, sizeof (Caixa), quantidade, arq);
    fflush(arq);
    /*fecha o arquivo*/
    fclose(arq);
    /*libera mémoria*/
    free(arq);

    return 1;
}

Caixa * listarCaixaBIN(int *numLinha) {
    FILE *arquivo;
    //abrea arquivo para leitura apenas "rb"
    arquivo = fopen("arquivos\\CaixaBIN.bin", "rb");
    if (arquivo == NULL) {
        //cria arquivo para leitura\escrita se não houver "w+b"
        arquivo = fopen("arquivos\\CaixaBIN.bin", "wb");
        if (arquivo == NULL) {
            printf("\nERRO ao acessar arquivo\n");
            return NULL;
        }
    }
    *numLinha = 0;

    Caixa c;
    //instancia vetor com tamanho 1 
    Caixa *aco = (Caixa*) calloc(1, sizeof (Caixa));
    //pega a primeira linha se existir
    int r = fread(&c, sizeof (Caixa), 1, arquivo);
    if (r > 0) {
        do {
            //soma a +1 no tamanho do vetor o qual comessa com 0
            *numLinha = (*numLinha) + 1;
            // realoca o vetor com o tamanho numLinha, a arqa interação ele realoca um a mais
            aco = realloc(aco, *numLinha * sizeof (Caixa));
            //adicionar o struct o vetor,(numLinha -1) pois o vetor comessa sempre por 0
            aco[(*numLinha) - 1] = c;
            //pega o proximo indice, se existir
            fread(&c, sizeof (Caixa), 1, arquivo);
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

int fecharCaixaBIN(Caixa aco) {
    FILE *arquivo;
    //abre arquivo para leitura e escrita, ele deve existir "r+b"
    arquivo = fopen("arquivos\\CaixaBIN.bin", "r+b");
    if (arquivo == NULL) {
        printf("Erro ao acessar arquivo\n");
        return 0;
    }
    int posi = posicaoCaixaBIN(aco.codigo);
    //Posiciona o cursor na posição do struct
    fseek(arquivo, (posi * sizeof (Caixa)), SEEK_SET);
    //Substitui o struct de posição posi
    fwrite(&aco, sizeof (Caixa), 1, arquivo);
    //fecha arquivo 
    fclose(arquivo);
    //fclose(&aco);
    //libera memoria
    free(arquivo);

    return 1;
}

int validarCaixaBIN(int cod) {
    int num;
    Caixa *aco = listarCaixaBIN(&num);
    int i;
    for (i = 0; i < num; i++) {
        if (cod == aco[i].codigo) {
            // retorna 1 se achar 
            return 1;
        }
    }
    free(aco);

    return 0;
}

int posicaoCaixaBIN(int cod) {
    int num;
    Caixa *aco = listarCaixaBIN(&num);
    int i;
    for (i = 0; i < num;) {
        if (cod == aco[i].codigo) {
            // retorna 1 se achar 
            return i;
        }
        i++;
    }
    free(aco);
    return 0;
}

int removerCaixaBIN() {
    int status = remove("arquivos\\CaixaBIN.bin");
    if (status != 0) {
        printf("\nErro na remoção do arquivo.\n");
        return 0;
    }
    return 1;
}
