
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ContaReceber.h"
#include "Hora.h"
#include "ContaPagar.h"

int cadastrarContaReceberTXT(ContaReceber cat) {
    FILE *cad;
    // abre o arquivo e posiciona o cursor no final
    cad = fopen("arquivos\\ContaReceberTXT.txt", "a");
    if (cad == NULL) {
        // se ele não existir cria um
        cad = fopen("arquivos\\ContaReceberTXT.txt", "w");
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
    cad = fopen("arquivos\\ContaReceberTXT.txt", "w");
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
    arquivo = fopen("arquivos\\ContaReceberTXT.txt", "r");
    if (arquivo == NULL) {
        //cria arquivo para leitura/escrita se não houver "w+"
        arquivo = fopen("arquivos\\ContaReceberTXT.txt", "w+");
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
        strtok(cat[i].status, "\n\r");
        fgets(cat[i].pagamento, 100, arquivo);
        strtok(cat[i].pagamento, "\n\r");
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
    arquivo = fopen("arquivos\\ContaReceberTXT.txt", "r");
    if (arquivo == NULL) {
        arquivo = fopen("arquivos\\ContaReceberTXT.txt", "w+");
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

/*Arquivos binarios*/

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

int atualizarCR() {
    int bd = listar();
    Data datah = getDataHoje();
    ContaReceber* arrayCR;
    ContaReceber cr;
    int aux;
    int r;
    int i;
    float valor = 0;
    int numContas = 0;
    if (bd == 1) {
        numContas = numContaReceber();
        arrayCR = listarContaReceberTXT();
    }
    if (bd == 2) {
        arrayCR = listarContaReceberBIN(&numContas);
    }
    // pega os dados
    for (i = 0; i < numContas; i++) {// verifica se a contas para atualizar o status
        if (arrayCR[i].data.dia == datah.dia && arrayCR[i].data.mes == datah.mes && arrayCR[i].data.ano == datah.ano) {
            if (strcmp(arrayCR[i].status, "Pendente") == 0) {
                cr.codigo = arrayCR[i].codigo;
                strcpy(cr.pagamento, arrayCR[i].pagamento);
                cr.valor = arrayCR[i].valor;
                cr.data.dia = arrayCR[i].data.dia;
                cr.data.mes = arrayCR[i].data.mes;
                cr.data.ano = arrayCR[i].data.ano;
                strcpy(cr.status, "Concluido");// seta status como concluido
                cr.caixa = arrayCR[i].caixa;
                aux = 1;
                break;
            }
        } else {
            aux = 0;
        }
    }
    valor = cr.valor;
    if (aux == 1) {
        if (bd == 1) {
              r = editarContaReceberTXT(arrayCR, cr, numContas);// joga no metodo que edita o status txt
        } else if (bd == 2) {
            r = editarContaReceberBIN(cr);// joga no metodo que edita o status bin
        }
    }

    if (r == 1) {
        printf("Atualizado. \n");
        //somaContaReceberCaixa(cr.data);
    }// else {
      //  printf("Erro ao atualizar. \n");
   // }
    visualizarHistContas();// mostra todas as contas

}

int editarContaReceberTXT(ContaReceber *arrayCR, ContaReceber cr, int num) {// editar status txt das contas
    int i;
    for (i = 0; i < num; i++) {//sobre escreve os dados
        if ((int) (arrayCR[i].codigo) == (int) (cr.codigo)) {
            
            strcpy(arrayCR[i].pagamento, cr.pagamento);
            arrayCR[i].valor = cr.valor;
            arrayCR[i].data.dia = cr.data.dia;
            arrayCR[i].data.mes = cr.data.mes;
            arrayCR[i].data.ano = cr.data.ano;
            strcpy(arrayCR[i].status, cr.status);
            //arrayCR[i].codForn = cr.codForn;
            arrayCR[i].caixa = cr.caixa;
        }
    }

    return salvarContaReceberTXT(arrayCR, num); // chama o metodo que salva de novo os dados no arquivo
}

int editarContaReceberBIN(ContaReceber cat) {// editar status bin das contas
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

/*
float somaContaReceberCaixa(Data data, float* valor) {
    
    ContaReceber *cai;
    Data datah = getDataHoje();
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
        if (datah.dia == cai[i].data.dia && datah.mes == cai[i].data.mes && datah.ano == cai[i].data.ano) {
            //if (22 == cai[i].data.dia && 3 == cai[i].data.mes && 2020 == cai[i].data.ano) {
            *valor += cai[i].valor;
        }
    }

}
*/

float somaContaReceberCaixa(Data data) {// metodo que soma valores ao caixa
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
    for (i = 0; i < num; i++) {// pega a data e ve se é igual ao atual dia se for soma no caixa
        if (compararDatas(cai[i].data, data) == 1) {
            valor += cai[i].valor;
        }
    }
    return valor;// retorna o valor para um método no caixa

}

void visualizarHistContas() {// metodo que lista as contas receber
    int n, aux;
    int bd = listar();
    ContaReceber *cr;
    if (bd == 1) {//verifica o tipo de salvamento
        cr = listarContaReceberTXT();
        n = numContaReceber();
    } else if (bd == 2) {
        cr = listarContaReceberBIN(&n);
    } else {
        printf("\nAltere a opção de salvamento em (MENU Principal->9 . Configurações-> 1. Op de BD.)\n");
    }
    if (bd > 0) {
        int i;
        if (n > 0) {
            for (i = 0; i < n; i++) {// pela contagem de linhas eles mostra os dados
                printf("\n*******%d************", i);
                printf("\nCodigo: %d", cr[i].codigo);
                printf("\nValor: %f", cr[i].valor);
                printf("\nDia Pagamento: %d", cr[i].data.dia);
                printf("\nMes Pagamento: %d", cr[i].data.mes);
                printf("\nAno Pagamento: %d", cr[i].data.ano);
                printf("\nStatus: %s", cr[i].status);
                printf("\nForma de Pagamento: %s", cr[i].pagamento);
                printf("\nCodigo do caixa: %d", cr[i].caixa);
                printf("\n");
            }
        } else {
            printf("Não à operadores cadastrados. \n");
        }
        free(cr);
    }
}

int validarCodContaBIN(int cod) {//pega código  por parâmetro
    int num;
   ContaReceber *arrayCR = listarContaReceberBIN(&num); // lista os operadores bin
    int i, aux = 0;
    for (i = 0; i < num; i++) {
        if (cod == arrayCR[i].codigo) {
            return 1; // faz a validação e retorna 1
        }

    }
    free(arrayCR);
    return 0;
}

int validarCodContaTXT(int cod) {
    ContaReceber *arrayCR = listarContaReceberTXT(); //lista os operadores
    if (arrayCR != NULL) {
        int num = numContaReceber();
        int i, aux = 0;
        for (i = 0; i < num; i++) {//verifica se o cod digitado passado por parametro é o msm no vetor
            if (cod == arrayCR[i].codigo) {
                return 1; //se sim retorna 1 que será usado na validação
            }
        }
        free(arrayCR);
        return 0;
    }
}
