/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fornecedor.h"
#include "FornecedorSUB.h"

void cadastrarFornecedor() {
    int bd = listar();
    int r;
    if (bd > 0) {
        Fornecedor a;
        printf("***** CADASTRAR FORNECEDOR *****\n");
        //pega os dados
        printf("Digite o cod do Fornecedor \n");
        scanf("%d%*c", &a.codigo);
        printf("Digite o nome Fantasia do Fornecedor \n");
        fgets(a.nomeFantazia, 100, stdin);
        strtok(a.nomeFantazia, "\n");
        setbuf(stdin, NULL);
        printf("Digite a Razão Social do Fornecedor \n");
        fgets(a.razaoSocial, 100, stdin);
        strtok(a.razaoSocial, "\n");
        setbuf(stdin, NULL);
        printf("Digite a Inscrição Estadual do Fornecedor \n");
        fgets(a.inscricaoEstadual, 100, stdin);
        strtok(a.inscricaoEstadual, "\n");
        setbuf(stdin, NULL);
        printf("Digite o CNPJ do Fornecedor \n");
        scanf("%[0-9 .-]s%*c", a.cnpj);
        strtok(a.cnpj, "\n");
        setbuf(stdin, NULL);
        printf("Digite o Email do Fornecedor \n");
        fgets(a.email, 100, stdin);
        strtok(a.email, "\n");
        setbuf(stdin, NULL);
        printf("Digite o Telefone do Fornecedor \n");
        scanf("%[0-9.()]%*c", a.telefone);
        printf("Digite o Cep do Endereço do Fornecedor \n");
        scanf("%[0-9]%*c", a.endereco.cep);
        printf("Digite o logradouro do Endereço do Fornecedor \n");
        fgets(a.endereco.logradouro, 100, stdin);
        strtok(a.endereco.logradouro, "\n");
        setbuf(stdin, NULL);
        printf("Digite o Bairro do Endereço do Fornecedor \n");
        fgets(a.endereco.bairro, 100, stdin);
        strtok(a.endereco.bairro, "\n");
        setbuf(stdin, NULL);
        printf("Digite o Cidade do Endereço do Fornecedor \n");
        fgets(a.endereco.cidade, 100, stdin);
        strtok(a.endereco.cidade, "\n");
        setbuf(stdin, NULL);
        printf("Digite o UF do Endereço do Fornecedor \n");
        fgets(a.endereco.uf, 100, stdin);
        strtok(a.endereco.uf, "\n");
        setbuf(stdin, NULL);
        printf("Digite o Numero do Endereço do Fornecedor \n");
        scanf("%d%*c", &a.endereco.numero);
        if (bd == 1) {
            r = cadastrarFornecedorControle(a);
        } else if (bd == 2) {
            r = cadastrarFornecedorBIN(&a, 1);
        }
        if (r == 1) {
            printf("\nFornecedor Cadastrada com SUCESSO!\n");
        }
    } else {
        printf("\nAltere a opção de salvamento em (MENU Principal->9 . Configurações-> 1. Op de BD.)\n");
    }
}

void listarFornecedor() {
    Fornecedor *a;
    int num;
    int bd = listar();
    if (bd == 1) {
        //pega a lista de Fornecedores do arquivo
        num = numLinhasFornecedor();
        a = listarFornecedorTXT();
    } else if (bd == 2) {
        //lista as Fornecedores e aponta o tamanho do vetor para num
        a = listarFornecedorBIN(&num);

    } else {
        printf("\nAltere a opção de salvamento em (MENU Principal->9 . Configurações-> 1. Op de BD.)\n");
    }
    if (bd > 0) {
        //lista ACOMODAÇÃO
        if (num > 0) {
            int i, j;
            for (i = 0; i < num; i++) {
                printf("\n**************** %d *****************\n", i);
                printf("CODIGO : %d\n", a[i].codigo);
                printf("NOME FANTASIA: %s\n", a[i].nomeFantazia);
                printf("RAZÃO SOCIAL: %s\n", a[i].razaoSocial);
                printf("CNPJ: %s\n", a[i].cnpj);
                printf("INSCRIÇÃO ESTADUAL: %s\n", a[i].inscricaoEstadual);
                printf("EMAIL: %s\n", a[i].email);
                printf("TELEFONE: %s\n", a[i].telefone);
                printf("CEP: %s\n", a[i].endereco.cep);
                printf("RUA: %s\n", a[i].endereco.logradouro);
                printf("CIDADE: %s\n", a[i].endereco.cidade);
                printf("UF: %s\n", a[i].endereco.uf);
                printf("BAIRRO: %s\n", a[i].endereco.bairro);
                printf("NUMERO: %d\n", a[i].endereco.numero);
            }
        } else {
            printf("\n*********NENHUMA ACOMODAÇÃO CADASTRADA*********\n");
        }
    }
}

void atualizarFornecedor() {
    Fornecedor a;
    Fornecedor *aco;
    int num;
    int i, aux, r;
    int bd = listar();
    if (bd == 1) {
        //pega a lista de ACOMODAÇÃO do arquivo
        num = numLinhasFornecedor();
        aco = listarFornecedorTXT();

    } else if (bd == 2) {
        //lista as acomodaçoes e aponta o tamanho do vetor para num
        aco = listarFornecedorBIN(&num);
    } else {
        printf("\nAltere a opção de salvamento em (MENU Principal->9 . Configurações-> 1. Op de BD.)\n");
    }
    if (bd > 0) {
        if (num > 0) {
            printf("***** ALTERAR DADOS DO FORNECEDOR *****\n");
            printf("Digite o cod do Fornecedor \n");
            scanf("%d%*c", &a.codigo);
            aux = 0;
            for (i = 0; i < num;) {
                if (a.codigo == aco[i].codigo) {
                    aux = 1;
                    break;
                }
                i++;
            }
            if (aux == 1) {
                printf("Digite o nome Fantasia do Fornecedor \n");
                fgets(a.nomeFantazia, 100, stdin);
                strtok(a.nomeFantazia, "\n");
                setbuf(stdin, NULL);
                printf("Digite a Razão Social do Fornecedor \n");
                fgets(a.razaoSocial, 100, stdin);
                strtok(a.razaoSocial, "\n");
                setbuf(stdin, NULL);
                printf("Digite a Inscrição Estadual do Fornecedor \n");
                fgets(a.inscricaoEstadual, 100, stdin);
                strtok(a.inscricaoEstadual, "\n");
                setbuf(stdin, NULL);
                printf("Digite o CNPJ do Fornecedor \n");
                scanf("%[0-9 .-]s%*c", a.cnpj);
                strtok(a.cnpj, "\n");
                setbuf(stdin, NULL);
                printf("Digite o Email do Fornecedor \n");
                fgets(a.email, 100, stdin);
                strtok(a.email, "\n");
                setbuf(stdin, NULL);
                printf("Digite o Telefone do Fornecedor \n");
                scanf("%[0-9.()]%*c", a.telefone);
                printf("Digite o Cep do Endereço do Fornecedor \n");
                scanf("%[0-9]%*c", a.endereco.cep);
                printf("Digite o logradouro do Endereço do Fornecedor \n");
                fgets(a.endereco.logradouro, 100, stdin);
                strtok(a.endereco.logradouro, "\n");
                setbuf(stdin, NULL);
                printf("Digite o Bairro do Endereço do Fornecedor \n");
                fgets(a.endereco.bairro, 100, stdin);
                strtok(a.endereco.bairro, "\n");
                setbuf(stdin, NULL);
                printf("Digite o Cidade do Endereço do Fornecedor \n");
                fgets(a.endereco.cidade, 100, stdin);
                strtok(a.endereco.cidade, "\n");
                setbuf(stdin, NULL);
                printf("Digite o UF do Endereço do Fornecedor \n");
                fgets(a.endereco.uf, 100, stdin);
                strtok(a.endereco.uf, "\n");
                setbuf(stdin, NULL);
                printf("Digite o Numero do Endereço do Fornecedor \n");
                scanf("%d%*c", &a.endereco.numero);
                if (bd == 1) {
                    r = editarFornecedorTXT(aco, a, num, i);
                } else if (bd == 2) {
                    r = editarFornecedorControleBIN(a);
                }
                if (r == 1) {
                    printf("\nAcomodação Editada com SUCESSO!\n");
                } else {
                    printf("\n ERRO ao Cadastrar Acomodação, tente outro codigo!\n");
                }

            } else {
                printf("\nAcomodação não encontrada!!\n");
            }
        } else {
            printf("\n*********NENHUMA ACOMODAÇÃO CADASTRADA*********\n");
        }
    }

    //scanf("%d%*c",&);
}

void deletarFornecedor() {
    int cod, r;
    int bd = listar();
    if (bd > 0) {
        printf("***** DELETAR FORNECEDR *****\n");
        printf("Digite o cod da fornecedor \n");
        scanf("%d%*c", &cod);
        if (bd == 1) {
            r = excluirFornecedor(cod);
        } else {
            r = removerFornecedorControleBIN(cod);
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

//metodos de crud

int cadastrarFornecedorControle(Fornecedor cat) {
    int n = numLinhasFornecedor();
    if (n > 0) {
        int v = validarFornecedor(cat.codigo);
        if (v == 0) {
            return cadastrarFornecedorTXT(cat);
        } else {
            return 0;
        }
    }
    return cadastrarFornecedorTXT(cat);
}

int editarFornecedorTXT(Fornecedor *cat, Fornecedor c, int num, int i) {

    strcpy(cat[i].nomeFantazia, c.nomeFantazia);
    cat[i].endereco.numero = c.endereco.numero;
    strcpy(cat[i].razaoSocial, c.razaoSocial);
    strcpy(cat[i].inscricaoEstadual, c.inscricaoEstadual);
    strcpy(cat[i].email, c.email);
    strcpy(cat[i].telefone, c.telefone);
    strcpy(cat[i].cnpj, c.cnpj);
    strcpy(cat[i].endereco.logradouro, c.endereco.logradouro);
    strcpy(cat[i].endereco.bairro, c.endereco.bairro);
    strcpy(cat[i].endereco.cep, c.endereco.cep);
    strcpy(cat[i].endereco.cidade, c.endereco.cidade);
    strcpy(cat[i].endereco.uf, c.endereco.uf);
    return salvarFornecedorTXT(cat, num);
}

int excluirFornecedor(int cod) {
    int num = numLinhasFornecedor();
    Fornecedor *cat = listarFornecedorTXT();
    int i;
    for (i = 0; i < num; i++) {
        if (cat[i].codigo == cod) {
            int j;
            for (j = i; j < num - 1; j++) {
                cat[i].codigo = cat[i + 1].codigo;
                strcpy(cat[i].nomeFantazia, cat[i + 1].nomeFantazia);
                cat[i].endereco.numero = cat[i + 1].endereco.numero;
                strcpy(cat[i].razaoSocial, cat[i + 1].razaoSocial);
                strcpy(cat[i].inscricaoEstadual, cat[i + 1].inscricaoEstadual);
                strcpy(cat[i].email, cat[i + 1].email);
                strcpy(cat[i].telefone, cat[i + 1].telefone);
                strcpy(cat[i].cnpj, cat[i + 1].cnpj);
                strcpy(cat[i].endereco.logradouro, cat[i + 1].endereco.logradouro);
                strcpy(cat[i].endereco.bairro, cat[i + 1].endereco.bairro);
                strcpy(cat[i].endereco.cep, cat[i + 1].endereco.cep);
                strcpy(cat[i].endereco.cidade, cat[i + 1].endereco.cidade);
                strcpy(cat[i].endereco.uf, cat[i + 1].endereco.uf);
                cat = realloc(cat, (num - 1) * sizeof (Fornecedor));
            }
            break;
        }
    }
    //salva no arquivo txt com uma categoria a menos
    // retorna 1, se editou com sucesso e 0 se não achou o codigo;
    return salvarFornecedorTXT(cat, num - 1);

}

/*arquivo binario*/
int cadastrarFornecedorControleBIN(Fornecedor *cat, int qtd) {
    int v = validarFornecedorBIN(cat->codigo);
    if (v == 0) {
        return cadastrarFornecedorBIN(cat, qtd);
    } else {
        return 0;
    }
    return 1;
}

int editarFornecedorControleBIN(Fornecedor cat) {
    int v = validarFornecedorBIN(cat.codigo);
    int r = editarFornecedorBIN(cat, v);
    return r;
}

// remove a categoria do vetor, realoca ele e reecreve o arquivo

int removerFornecedorControleBIN(int cod) {
    int num;
    Fornecedor *cat = listarFornecedorBIN(&num);
    int i;
    for (i = 0; i < num; i++) {
        if (cat[i].codigo == cod) {
            int j;
            //realoca o vetor
            for (j = i; j < num - 1; j++) {
                cat[i].codigo = cat[i + 1].codigo;
                cat[i].codigo = cat[i + 1].codigo;
                //                strcpy(cat[i].descricao, cat[i + 1].descricao);
                // cat[i].categoria.codigo = cat[i + 1].categoria.codigo;
                //strcpy(cat[i].status, cat[i + 1].status);
                //                cat = realloc(cat, (num - 1) * sizeof (Fornecedor));
            }
            break;
        }
    }
    //apaga arquivo
    int r = removerFornecedorBIN();
    if (r == 1) {
        //se deu certo reescreve arquivo
        return cadastrarFornecedorBIN(cat, (num - 1));
    } else {
        return 0;
    }
}
