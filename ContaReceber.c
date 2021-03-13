
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ContaReceber.h"
#include "Hora.h"

int cadastrarContaReceberTXT(ContaReceber cat) {
    FILE *cad;
    // abre o arquivo e posiciona o cursor no final
    cad = fopen("arquivos\\ContaReceberTXT", "a");
    if (cad == NULL) {
        // se ele não existir cria um
        cad = fopen("arquivos\\ContaReceberTXT", "w");
        if (cad == NULL) {
            printf("\nErro: aao cessar arquivo\n");
            return 0;
        }
    }
    // salva cada campo em uma linha
    fprintf(cad, "%d\n%f\n%d\n%d\n%d\n%s\n%s\n%d\n", cat.codigo, cat.valor, cat.data.dia, cat.data.mes, cat.data.ano, cat.status, cat.pagamento, cat.caixa); // f
    //fecha o arquivo
    fclose(cad);
    //libera memoria
    free(cad);

    return 1;
}
//metodo salva, sobrescrevendo o array de tamanho num

int salvarContaReceberTXT(ContaReceber *cat, int num) {
    FILE *cad;
    // w pra substituir o arquivo
    cad = fopen("arquivos\\ContaReceberTXT", "w");
    if (cad == NULL) {
        printf("\nErro ao abrir arquivo!!");
        return 0;
    } else {
        int i;
        // grava todos os dados do vetor no arquivo
        for (i = 0; i < num; i++) {
            fprintf(cad, "%d\n%f\n%d\n%d\n%d\n%s\n%s\n%d\n", cat[i].codigo, cat[i].valor, cat[i].data.dia, cat[i].data.mes, cat[i].data.ano, cat[i].status, cat[i].pagamento, cat[i].caixa); // f
        }
    }
    // força salvar arquivo
    fflush(cad);
    //fecha arquivo
    fclose(cad);
    //libera memoria
    free(cad);
    free(cat);
    return 1;
}

ContaReceber* listarContaReceberTXT() {
    int numLinha = 0, i = 0;
    FILE *arquivo;
    numLinha = numContaReceber(arquivo);
    //abrea arquivo para leitura apenas "r"
    arquivo = fopen("arquivos\\ContaReceberTXT", "r");
    if (arquivo == NULL) {
        //cria arquivo para leitura/escrita se não houver "w+"
        arquivo = fopen("arquivos\\ContaReceberTXT", "w+");
        if (arquivo == NULL) {
            printf("\nErro ao acessar arquivo categoria\n");
            return NULL;
        }
    }
    //instancia vetor com tamanho de numLinha
    ContaReceber *cat = (ContaReceber*) calloc(numLinha, sizeof (ContaReceber));
    i = 0;

    char t[100];
    //printf("linhas %d \n", numLinha);

    for (i = 0; i < numLinha; i++) {
        fgets(t, 100, arquivo);
        cat[i].codigo = atoi(t);
        fgets(t, 100, arquivo);
        cat[i].valor = atof(t);
        fgets(t, 100, arquivo);
        cat[i].data.dia = atoi(t);
        fgets(t, 100, arquivo);
        cat[i].data.mes = atoi(t);
        fgets(t, 100, arquivo);
        cat[i].data.ano = atoi(t);
        fgets(cat[i].status, 100, arquivo);
        strtok(cat[i].status, "\n");
        fgets(cat[i].pagamento, 100, arquivo);
        strtok(cat[i].pagamento, "\n");
        fgets(t, 100, arquivo);
        cat[i].caixa = atoi(t);
    }
    //fecha arquivo
    fclose(arquivo);
    //libera memoria
    free(arquivo);
    return cat;
}

int numContaReceber() {
    FILE *arquivo;
    int numLinha = 0, c;
    //abre arquivo para leitura "r"
    arquivo = fopen("arquivos\\ContaReceberTXT", "r");
    if (arquivo == NULL) {
        arquivo = fopen("arquivos\\ContaReceberTXT", "w+");
        if (arquivo == NULL) {
            printf("Erro ao acessar arquivo\n");
            return 0;
        }
    }
    //roda ate que ache o final do arquivo "EOF"
    while ((c = fgetc(arquivo)) != EOF) {
        if (c == '\n') {
            //soma a quantidade de linhas do TXT, mas não a quantidade de categorias
            numLinha++;
        }
    }
    //fecha arquivo
    fclose(arquivo);
    //libera memoria
    free(arquivo);
    // divide se por 8 pois categoria tem 5 linhas
    return numLinha / 8;
}

int validarContaReceber(int cod) {
    ContaReceber *cat = listarContaReceberTXT();
    //int lin = sizeof (*cat) / sizeof (ContaReceber);
    int lin = numContaReceber();
    int i;
    for (i = 0; i < lin; i++) {
        if (cod == cat[i].codigo) {
            return 1;
        }
    }
    free(cat);
    return 0;
}

/*Aruivos binarios*/

int cadastrarContaReceberBIN(ContaReceber *cat, int quantidade) {
    FILE *cad;
    //cad = fopen("arquivos\\ReservaQBIN.bin", "ab");
    cad = fopen("arquivos\\ContaReceberBIN.bin", "ab");
    if (cad == NULL) {
        //cad = fopen("arquivos\\ReservaQBIN.bin", "wb");
        cad = fopen("arquivos\\ContaReceberBIN.bin", "wb");
        return 0;
    } else {
        //strlen()-> informa o tamanho de uma string 
        /*grava toda struct de categoria no arquivo*/
        fwrite(cat, sizeof (ContaReceber), quantidade, cad);
        fflush(cad);
        /*fecha o arquivo*/
        fclose(cad);
        /*libera mémoria*/
        free(cad);
    }
    return 1;
}

ContaReceber * listarContaReceberBIN(int *numLinha) {
    FILE *arquivo;
    //area arquivo para leitura apenas "rb"
    arquivo = fopen("arquivos\\ContaReceberBIN.bin", "rb");
    if (arquivo == NULL) {
        //cria arquivo para leitura\escrita se não houver "w+b"
        arquivo = fopen("arquivos\\ContaReceberBIN.bin", "w+b");
        if (arquivo == NULL) {
            printf("\nERRO ao acessar arquivo\n");
            return NULL;
        }
    }
    *numLinha = 0;

    ContaReceber c;
    //instancia vetor com tamanho 1 
    ContaReceber *cat = (ContaReceber*) calloc(1, sizeof (ContaReceber));
    //pega a primeira linha se existir
    int r = fread(&c, sizeof (ContaReceber), 1, arquivo);
    if (r > 0) {
        do {
            //soma a +1 no tamanho do vetor o qual comessa com 0
            *numLinha = (*numLinha) + 1;
            // realoca o vetor com o tamanho numLinha, a cada interação ele realoca um a mais
            cat = realloc(cat, *numLinha * sizeof (ContaReceber));
            //adicionar o struct o vetor,(numLinha -1) pois o vetor comessa sempre por 0
            cat[(*numLinha) - 1] = c;
            //pega o proximo indice, se existir
            fread(&c, sizeof (ContaReceber), 1, arquivo);
            //verifica se chegou no fim do arquivo
        } while (!feof(arquivo));
    } else {
        return NULL;
    }
    //fecha arquivo
    fclose(arquivo);
    //libera memoria
    free(arquivo);
    return cat;
}

int editarContaReceberBIN(ContaReceber cat) {
    FILE *arquivo;
    //abre arquivo para leitura e escrita "r+b"
    arquivo = fopen("arquivos\\ContaReceberBIN.bin", "r+b");
    if (arquivo == NULL) {
        printf("Erro ao acessar arquivo\n");
        return 0;
    }
    int posi = posicaoContaReceberBIN(cat.codigo);
    //Posiciona o cursor na posição do struct
    fseek(arquivo, (posi * sizeof (ContaReceber)), SEEK_SET);
    //Substitui o struct de posição posi
    fwrite(&cat, sizeof (ContaReceber), 1, arquivo);
    //fecha arquivo 
    fclose(arquivo);
    //fclose(&cat);
    //libera memoria
    free(arquivo);
    return 1;
}

int validarContaReceberBIN(int cod) {
    int num;
    ContaReceber *cat = listarContaReceberBIN(&num);
    int i;
    for (i = 0; i < num; i++) {
        if (cod == cat[i].codigo) {
            // retorna um se achar
            return 1;
        }
    }
    free(cat);
    return 0;
}

int posicaoContaReceberBIN(int cod) {
    int num;
    ContaReceber *cat = listarContaReceberBIN(&num);
    int i;
    for (i = 0; i < num;) {
        if (cod == cat[i].codigo) {
            // retorna um se achar
            return i;
        }
        i++;
    }
    free(cat);
    return 0;
}

int removerContaReceberBIN() {
    int status = remove("arquivos\\ContaReceberBIN.bin");
    if (status != 0) {
        printf("\nErro na remoção do arquivo.\n");
        return 0;
    }
    return 1;
}

int maiorCodContaReceber() {
    int bd = listar();
    int num;
    ContaReceber *cr;
    if (bd == 1) {
        num = numContaReceber();
        if (num > 0) {
            cr = listarContaReceberTXT();
        } else {
            return 0;
        }
    } else {
        cr = listarContaReceberBIN(&num);
        if (num == 0) {
            return 0;
        }
    }
    int i, aux = 0;
    for (i = 0; i < num; i++) {
        if (cr[i].codigo > aux) {
            aux = cr[i].codigo;
        }
    }
    return aux;
}

float somaContaReceberCaixa(Data data) {
    float valor = 0;
    ContaReceber *cai;
    int num;
    int bd = listar();
    if (bd == 1) {
        cai = listarContaReceberTXT();
        num = numContaReceber();
    } else {
        cai = listarContaReceberBIN(&num);
    }
    int i;
    for (i = 0; i < num; i++) {
        if (compararDatas(cai[i].data, data) == 1) {
            valor += cai[i].valor;
        }
    }
    return valor;

}