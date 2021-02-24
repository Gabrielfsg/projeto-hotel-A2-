/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Acomodacao.h"
#include "Categoria.h"
#include "AcomodacaoSUB.h"
#include "SalvametoBD.h"

void cadastrarAcomodacao() {
    int bd = listar();
    int aux = 0;
    if (bd > 0) {
        Acomodacao a;
        printf("***** CADASTRAR ACOMODAÇÃO *****\n");
        //pega os dados
        printf("Digite o cod da acomodação \n");
        scanf("%d%*c", &a.codigo);
        if (bd == 1) {
            aux = validarAcomodacao(a.codigo);
        } else if (bd == 2) {
            aux = validarAcomodacaoBIN(a.codigo);
        }
        if (aux == 0) {
            printf("Digite a descrição da acomodação \n");
            fgets(a.descricao, 100, stdin);
            strtok(a.descricao, "\n");
            setbuf(stdin, NULL);
            //cadastra acomodação com status de disponiilidade live
            strcpy(a.status, "livre");
            //listar categorias
            int r = printCategoria(&a);
            if (r == 1) {
                if (bd == 1) {
                    r = cadastrarAcomodacaoTXT(a);
                } else if (bd == 2) {
                    r = cadastrarAcomodacaoBIN(&a, 1);
                }
                if (r == 1) {
                    printf("\nAcomodação Cadastrada com SUCESSO!\n");
                }
            }
        } else {
            printf("\n ERRO ao Cadastrar Acomodação, tente outro codigo!\n");
        }
    } else {
        printf("\nAltere a opção de salvamento em (MENU Principal->9 . Configurações-> 1. Op de BD.)\n");
    }


}

void listarAcomodacao() {
    Acomodacao *a;
    Categoria *c;
    int num2, num;
    int bd = listar();
    if (bd == 1) {
        //pega a lista de ACOMODAÇÃO do arquivo
        num = numAcomodacao();
        a = listarAcomodacaoTXT();
        c = listarCategoriaTXT();
        num2 = numCategoria();
    } else if (bd == 2) {
        //lista as acomodaçoes e aponta o tamanho do vetor para num
        a = listarAcomodacaoBIN(&num);
        //lista as categrias e aponta o tamanho do vetor para num2
        c = listarCategoriaBIN(&num2);
    } else {
        printf("\nAltere a opção de salvamento em (MENU Principal->9 . Configurações-> 1. Op de BD.)\n");
    }
    if (bd > 0) {
        //lista ACOMODAÇÃO
        if (num > 0) {
            int i, j;
            for (i = 0; i < num; i++) {
                printf("\n**************** %d *****************\n", i);
                printf("COD: %d\n", a[i].codigo);
                printf("DESCRIÇÃO: %s\n", a[i].descricao);
                printf("STATUS: %s\n", a[i].status);
                //LISTAR FACILIDADES PRECISARÁ DE UM TRATAMENTO ESPECIAL
                for (j = 0; j < num2; j++) {
                    if (a[i].categoria.codigo == c[j].codigo) {
                        printf("CATEGORIAS: %s\n", c[j].descricao);
                        printf("FACILIDADES: %s\n", c[j].facilidade);
                        printf("VALOR DIARIA: %f\n", c[j].valorDiario);
                        printf("N° PESSOAS: %d\n", c[j].quantidadePessoas);
                    }

                }
            }
        } else {
            printf("\n*********NENHUMA ACOMODAÇÃO CADASTRADA*********\n");
        }
    }
}

void atualizarAcomodacao() {
    Acomodacao aco;
    Acomodacao *a;
    int num;
    int i, aux;
    int bd = listar();
    if (bd == 1) {
        //pega a lista de ACOMODAÇÃO do arquivo
        num = numAcomodacao();
        a = listarAcomodacaoTXT();

    } else if (bd == 2) {
        //lista as acomodaçoes e aponta o tamanho do vetor para num
        a = listarAcomodacaoBIN(&num);
    } else {
        printf("\nAltere a opção de salvamento em (MENU Principal->9 . Configurações-> 1. Op de BD.)\n");
    }
    if (bd > 0) {
        if (num > 0) {
            printf("***** ALTERAR DADOS DA ACOMODAÇÃO *****\n");
            printf("Digite o cod da acomodação \n");
            scanf("%d%*c", &aco.codigo);
            aux = 0;
            for (i = 0; i < num;) {
                if (aco.codigo == a[i].codigo) {
                    aux = 1;
                    break;
                }
                i++;
            }
            if (aux == 1) {
                printf("Digite a descrição da acomodação \n");
                fgets(aco.descricao, 100, stdin);
                strtok(aco.descricao, "\n");
                setbuf(stdin, NULL);
                //cadastra acomodação com status de disponiilidade live
                strcpy(aco.status, "livre");
                //listar categorioas
                int r = printCategoria(&aco);
                if (r == 1) {
                    if (bd == 1) {
                        r = editarAcomodacaoTXT(a, aco, num, i);
                    } else if (bd == 2) {
                        r = editarAcomodacaoBIN(aco);
                    }

                    if (r == 1) {
                        printf("\nAcomodação Editada com SUCESSO!\n");
                    } else {
                        printf("\n ERRO ao Cadastrar Acomodação, tente outro codigo!\n");
                    }
                }
            } else {
                printf("\nAcomodação não encontrada!!\n");
            }
        } else {
            printf("\n*********NENHUMA ACOMODAÇÃO CADASTRADA*********\n");
        }
    }
}

void deletarAcomodacao() {
    int cod, r;
    int bd = listar();
    if (bd > 0) {
        printf("***** DELETAR ACOMODAÇÃO *****\n");
        printf("Digite o cod da acomodação \n");
        scanf("%d%*c", &cod);
        if (bd == 1) {
            r = excluirAcomodacao(cod);
        } else {
            r = removerAcomodacaoControleBIN(cod);
        }

        if (r == 1) {
            printf("\nExclusão realizada com Sucesso!!\n");
        } else {
            printf("\nNÃO foi possivel Excluir!!\n");
        }
    } else {
        printf("\nAltere a opção de salvamento em (MENU Principal->9 . Configurações-> 1. Op de BD.)\n");
    }
}

/****Metodos controle*****/

int cadastrarAcomodacaoControle(Acomodacao cat) {
    int n = numAcomodacao();
    if (n > 0) {
        int v = validarAcomodacao(cat.codigo);
        if (v == 0) {
            return cadastrarAcomodacaoTXT(cat);
        } else {
            return 0;
        }
    }
    return cadastrarAcomodacaoTXT(cat);
}

int editarAcomodacaoTXT(Acomodacao *cat, Acomodacao c, int num, int i) {

    strcpy(cat[i].descricao, c.descricao);
    cat[i].categoria.codigo = c.categoria.codigo;
    strcpy(cat[i].status, c.status);
    return salvarAcomodacaoTXT(cat, num);
}

int excluirAcomodacao(int cod) {
    int num = numAcomodacao();
    Acomodacao *cat = listarAcomodacaoTXT();
    int i, aux = 0;
    for (i = 0; i < num; i++) {
        if (cat[i].codigo == cod) {
            aux = 1;
            int j;
            for (; i < num - 1; i++) {
                cat[i] = cat[i + 1];
            }
            cat = realloc(cat, (num - 1) * sizeof (Acomodacao));
            break;
        }
    }
    if (aux == 1) {
        //salva no arquivo txt com uma categoria a menos
        // retorna 1, se editou com sucesso e 0 se não achou o codigo;
        return salvarAcomodacaoTXT(cat, num - 1);
    } else {
        return 0;
    }
}

/*arquivo binario*/

// remove a categoria do vetor, realoca ele e reecreve o arquivo

int removerAcomodacaoControleBIN(int cod) {
    int num;
    Acomodacao *cat = listarAcomodacaoBIN(&num);
    int i, aux = 0;
    for (i = 0; i < num; i++) {
        if (cat[i].codigo == cod) {
            aux = 1;
            //realoca o vetor
            for (; i < num - 1; i++) {
                cat[i] = cat[i + 1];
            }
            cat = realloc(cat, (num - 1) * sizeof (Acomodacao));
            break;
        }
    }
    if (aux == 1) {
        //apaga arquivo
        int r = removerAcomodacaoBIN();
        if (r == 1) {
            //se deu certo reescreve arquivo
            return cadastrarAcomodacaoBIN(cat, (num - 1));
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

int printCategoria(Acomodacao *a) {
    int bd = listar();
    Categoria *c;
    int num;
    int i;
    if (bd == 1) {
        //pega a lista de ACOMODAÇÃO do arquivo
        num = numCategoria();
        c = listarCategoriaTXT();
    } else if (bd == 2) {
        //lista as acomodaçoes e aponta o tamanho do vetor para num
        c = listarCategoriaBIN(&num);
    } else {
        printf("\nAltere a opção de salvamento em (MENU Principal->9 . Configurações-> 1. Op de BD.)\n");
    }
    if (bd > 0) {
        for (;;) {
            for (i = 0; i < num; i++) {
                printf("\n COD: %d , DESCRIÇÃO: %s , FACILIDADE: %s, VALOR DIARIA : %f , N° PESSOAS: %d .\n", c[i].codigo, c[i].descricao, c[i].facilidade, c[i].valorDiario, c[i].quantidadePessoas);
            }
            printf("Digite o Cod categoria da acomodação \n");
            scanf("%d%*c", &a->categoria.codigo);
            //printf("%d", a->categoria.codigo);
            int aux = 0;
            for (i = 0; i < num; i++) {
                if (a->categoria.codigo == c[i].codigo) {
                    aux = 1;
                }
            }
            if (aux == 1) {
                //liera memoria
                free(c);
                return 1;
            } else {
                printf("Cod da categoria Invalido!! tente novamente");
            }
        }

    }
    return 0;
}