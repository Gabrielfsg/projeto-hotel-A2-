#include <stdio.h>
#include <stdlib.h>
#include "OperadorSistema.h"
#include "OperadorsistemaMenu.h"
#include "SalvametoBD.h"
#include <string.h>

void cadastrarOperador() {
    int bd = listar();
    OperadorSistema op;
    int n, i, r;
    int aux = 0, cod = 0;
    int valid, valid2, li;
    if (bd > 0) {
        printf("***** CADASTRAR OPERADOR *****\n");
        printf("Digite o Cod do Operador \n");
        scanf("%d%*c", &op.codigo);
        if (bd == 1) {// verifica se é arquivo txt 
            valid = validarOpTXT(op.codigo);//passa o código digitado como parametro
            if (valid == 1) {//se resultado retornado 1
                printf("Operador já cadastrado! \n");
                menuCRUDOperador();
            }
        } else if (bd == 2) {// faz o mesmo com o arquivo bin
            valid2 = validarOpBIN(op.codigo);
            if (valid2 == 1) {
                printf("Operador já cadastrado! \n");
                menuCRUDOperador();
            }
        }
        printf("Digite o Nome do Operador \n");
        fgets(op.nome, 100, stdin);
        strtok(op.nome, "\n");
        setbuf(stdin, NULL);
        printf("Digite o Usuário do Operador \n");
        fgets(op.usuario, 100, stdin);
        strtok(op.usuario, "\n");
        setbuf(stdin, NULL);
        printf("Digite a Senha do Operador \n");
        fgets(op.senha, 100, stdin);
        strtok(op.senha, "\n");
        setbuf(stdin, NULL);

        if (bd == 1) {
            r = controleCadTXT(op);
        } else if (bd == 2) {
            r = cadastrarOpBin(&op, 1);
        }
        //salva no arquivo
        //cadastrarOpBin(&op, 1);
        if (r == 1) {
            printf("Cadastro Efetuado com sucesso! \n");
        } else if (r == 0) {
            printf("Operador já cadastrado! \n");
        }

    } else {
        printf("\nAltere a opção de salvamento em (MENU Principal->9 . Configurações-> 1. Op de BD.)\n");
    }
}

void listarOperador() {
    int n, aux;
    int bd = listar();
    OperadorSistema *opera;
    if (bd == 1) {//verifica o tipo de salvamento
        opera = listarOpTXT();
        n = contarLinhasTXT();
    } else if (bd == 2) {
        opera = listarOpBIN(&n);
    } else {
        printf("\nAltere a opção de salvamento em (MENU Principal->9 . Configurações-> 1. Op de BD.)\n");
    }
    if (bd > 0) {
        int i;
        if (n > 0) {
            for (i = 0; i < n; i++) {// pela contagem de linhas eles mostra os dados
                printf("\n*******%d************", i);
                printf("\nCodigo: %d", opera[i].codigo);
                printf("\nNome: %s", opera[i].nome);
                printf("\nUsuario: %s", opera[i].usuario);
                printf("\nSenha: %s", opera[i].senha);
                printf("\n");
            }
        } else {
            printf("Não à operadores cadastrados. \n");
        }
        free(opera);
    }
}

void atualizarOperador() {
    int n, aux;
    int t;
    int bd = listar();
    OperadorSistema op;
    OperadorSistema *opera;
    // valida arquivos bin ou txt
    if (bd == 1) {
        opera = listarOpTXT();
        n = contarLinhasTXT();
    } else if (bd == 2) {
        opera = listarOpBIN(&n);
    } else {
        printf("\nAltere a opção de salvamento em (MENU Principal->9 . Configurações-> 1. Op de BD.)\n");
    }
    if (bd > 0) {
        if (n > 0) {//valida pelo numero de linhas dos arquivos
            printf("***** ALTERAR DADOS DO OPERADOR *****\n");
            printf("Digite o cod do operador \n");
            scanf("%d%*c", &op.codigo);
            int i;
            for (i = 0; i < n;) {
                if (op.codigo == opera[i].codigo) {
                    printf("Digite o Nome do Operador \n");
                    fgets(op.nome, 100, stdin);
                    strtok(op.nome, "\n");
                    setbuf(stdin, NULL);
                    printf("Digite o Usuário do Operador \n");
                    fgets(op.usuario, 100, stdin);
                    strtok(op.usuario, "\n");
                    setbuf(stdin, NULL);
                    printf("Digite a Senha do Operador \n");
                    fgets(op.senha, 100, stdin);
                    strtok(op.senha, "\n");
                    setbuf(stdin, NULL);
                    aux = 1;
                    break;
                } else {
                    aux == 0;
                }
                i++;
            }
            if (aux == 1) {
                if (bd == 1) {// verifica a salvamento e chama o método de editar
                    t = editarOperadorTXT(opera, op, n);
                } else if (bd == 2) {
                    t = editarOpSBIN(op, i);
                }
                printf("Atualização Efetuada com sucesso! \n");
            } else {
                printf("Operador não cadastrado. \n");
            }
        } else {
            printf("\n  Nenhum operador cadastrado  \n");
        }
    }

}

void deletarOperador() {
    printf("***** DELETAR OPERADOR *****\n");
    int opc;
    int cod;
    int bd = listar();
    int r;
    printf("DELETAR: \n");
    printf("1.DELETAR 1.\n");
    printf("2.Voltar\n");
    scanf("%d", &opc);
    if (bd > 0) {
        if (opc == 1) {
            printf("Entre com o código do operador: ");
            scanf("%d*c", &cod);
            if (bd == 1) {
                r = removerOperadorControleTXT(cod);
            } else {
                r = removerOpSControleBIN(cod);
            }
            if (r == 1) {
                printf("\nExclusão realizada com sucesso!\n");
            } else {
                printf("\nNão foi possivel encontrar operador de codigo %d \n", cod);
            }
        } else if (opc == 2) {
            menuCRUDOperador();
        }
    } else {
        printf("\nAltere a opção de salvamento em (MENU Principal->9 . Configurações-> 1. Op de BD.)\n");
    }
}

int removerOpSControleBIN(int cod) {
    int num;
    OperadorSistema *opera = listarOpBIN(&num);

    int i;
    for (i = 0; i < num; i++) {
        if (opera[i].codigo == cod) {
            int j;
            for (j = i; j < num - 1; j++) {
                opera[i].codigo = opera[i + 1].codigo;
                strcpy(opera[i].nome, opera[i + 1].nome);
                strcpy(opera[i].usuario, opera[i + 1].usuario);
                strcpy(opera[i].senha, opera[i + 1].senha);
                opera = realloc(opera, (num - 1) * sizeof (OperadorSistema));
            }
            break;
        } else {
            return 0;
        }
    }
    //apaga arquivo
    int r = removerOperadorBIN();
    if (r == 1) {
        //se deu certo reescreve arquivo
        return cadastrarOpBin(opera, (num - 1));
    } else {
        return 0;
    }
}

int controleCadTXT(OperadorSistema opera) {
    return cadastrarOpTXT(opera);

}

int contarLinhasTXT() {

    FILE *listOperador;
    int numOL = 0, c, numF;

    listOperador = fopen(".\\persist\\operadorTXT", "r");
    if (listOperador == NULL) {
        listOperador = fopen(".\\persist\\operadorTXT", "w+");
        if (listOperador == NULL) {
            printf("Erro ao acessar arquivo\n");
            return 0;
        }
    }
    //Lendo o arquivo 1 por 1
    while ((c = fgetc(listOperador)) != EOF) {
        if (c == '\n') {
            //soma a quantidade de linhas do TXT, mas não a quantidade de categorias
            numOL++;
        }
    }
    numF = numOL / 4;
    fclose(listOperador);
    free(listOperador);

    return numF;

}

int contarLinhas() {

    FILE *listOperador;

    char c, letra = '\n';

    int vezes;

    listOperador = fopen(".\\persist\\operador.bin", "rb");

    //Lendo o arquivo 1 por 1
    while (fread(&c, sizeof (char), 1, listOperador)) {
        if (c == letra) {
            vezes++;
        }
    }

    printf("\nLinhas: %i\n", vezes);
    fclose(listOperador);
    free(listOperador);

    return vezes;

}

int salvarOperadorControleTXT(OperadorSistema* opera, int num) {
    return salvarOperadorTXT(opera, num);
}

int removerOperadorControleTXT(int cod) {
    int num = contarLinhasTXT();
    OperadorSistema *opera = listarOpTXT();
    int i;
    for (i = 0; i < num; i++) {
        if (opera[i].codigo == cod) {
            int j;
            for (j = i; j < num - 1; j++) {
                opera[i].codigo = opera[i + 1].codigo;
                strcpy(opera[i].nome, opera[i + 1].nome);
                strcpy(opera[i].usuario, opera[i + 1].usuario);
                strcpy(opera[i].senha, opera[i + 1].senha);
                opera = realloc(opera, (num - 1) * sizeof (OperadorSistema));
            }
            break;
        } else {
            return 0;
        }
    }

    return salvarOperadorTXT(opera, num - 1);

}



