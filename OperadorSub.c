#include <stdio.h>
#include <stdlib.h>
#include "OperadorSistema.h"
#include "OperadorsistemaMenu.h"
#include <string.h>

void cadastrarOperador() {
    OperadorSistema op;
    int achei = 0;

    printf("***** CADASTRAR OPERADOR *****\n");
    printf("Digite o Cod do Operador \n");
    scanf("%d%*c", &op.codigo);
    printf("Digite o Nome do Operador \n");
    fgets(op.nome, 100, stdin);
    strtok(op.nome, "\n");
    setbuf(stdin, NULL);
    printf("Digite o Usuário do Operador \n");
    fgets(op.usuario, 100, stdin);
    strtok(op.usuario, "\n");
    setbuf(stdin, NULL);
    printf("Digite a Senha do Operador \n");
    fgets(op.usuario, 100, stdin);
    strtok(op.usuario, "\n");
    setbuf(stdin, NULL);

    //salva no arquivo
    cadastrarOpBin(&op, 1);
}

void listarOperador() {
    int n;
    OperadorSistema *opera;
    opera = listarOpBIN(&n);
    int i;
    for (i = 0; i < n; i++) {
        printf("\n*******%d************", i);
        printf("\nCodigo: %d", opera[i].codigo);
        printf("\nNome: %s", opera[i].nome);
        printf("\nUsuario: %s", opera[i].usuario);
        printf("\nSenha: %s", opera[i].senha);
    }
}

void atualizarOperador() {
    int n, aux;
    OperadorSistema op;
    OperadorSistema *opera = listarOpBIN(&n);
    printf("***** ALTERAR DADOS DA ACOMODAÇÃO *****\n");
    printf("Digite o cod da acomodação \n");
    scanf("%d%*c", &op.codigo);
    int i;
    for (i = 0; i < n;) {
        if (op.codigo == opera[i].codigo) {
            printf("Digite o Nome do Operador \n");
            scanf("%s%*c", &op.nome);
            printf("Digite o Usuário do Operador \n");
            scanf("%s%*c", &op.usuario);
            printf("Digite a Senha do Operador \n");
            scanf("%s%*c", &op.senha);
            aux = 1;
            break;
        }
        i++;
    }
    if (aux == 1) {
        int r = editarOpSBIN(op, i);
    }



}

void deletarOperador() {
    printf("***** DELETAR OPERADOR *****\n");
    int opc;
    int cod;
    printf("DELETAR: \n");
    printf("1.DELETAR 1.\n");
    printf("2.DELETAR Todos\n");
    printf("3.Voltar\n");
    scanf("%d", &opc);
    if (opc == 1) {
        printf("Entre com o código do operador: ");
        scanf("%d", &cod);
        int r = removerOperadorControleBIN(cod); 
        if (r == 1) {
            printf("\nExclusão realizada com sucesso!\n");
        } else {
            printf("\nNão foi possivel encontrar categoria de codigo %d \n", cod);
        }
    } else if (opc == 2) {
        FILE *listOperador = fopen(".\\persist\\operador.bin", "wb");
        if (listOperador == NULL) {
            printf("Arquivo inexistente!");
            return;
        }
        listOperador = fopen(".\\persist\\operador.bin", "wb");
        printf("Dados Apagados com sucesso \n");

        fclose(listOperador);
    } else if (opc == 3) {
        menuCRUDOperador();
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

int removerOperadorControleBIN(int cod) {
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
        }
    }
    //apaga arquivo
    int v = removerOperadorBIN();
    if (v == 1) {
        //se deu certo reescreve arquivo
        salvarOperadorTXT(opera, num - 1);
    }
}

