#include <stdio.h>
#include <stdlib.h>
#include "OperadorSistema.h"
#include <string.h>

void cadastrarOperador() {
    OperadorSistema op;
    printf("***** CADASTRAR OPERADOR *****\n");
    //pega os dados
    printf("Digite o Cod do Operador \n");
    scanf("%d%*c", &op.codigo);

    //valida para ver se já existe

    printf("Digite o Nome do Operador \n");
    scanf("%s%*c", &op.nome);
    printf("Digite o Usuário do Operador \n");
    scanf("%s%*c", &op.usuario);
    printf("Digite a Senha do Operador \n");
    scanf("%s%*c", &op.senha);

    //salva no arquivo
    cadastrarOpSBIN(&op, 1);


}

void listarOperador() {
    int n;
    OperadorSistema *op;
    op = listarOpBIN(&n);
    int i;
    for (i = 0; i < n; i++) {
        printf("\n*******%d************", i);
        printf("\nCodigo: %d", op[i].codigo);
        printf("\nNome: %s", op[i].nome);
        printf("\nUsuario: %s", op[i].usuario);
        printf("\nSenha: %s", op[i].senha);
    }
}

void atualizarOperador() {
    int n, aux;
    OperadorSistema p;
    OperadorSistema *op = listarOpBIN(&n);
    printf("***** ALTERAR DADOS DA ACOMODAÇÃO *****\n");
    printf("Digite o cod da acomodação \n");
    scanf("%d%*c", &p.codigo);
    int i;
    for (i = 0; i < n;) {
        if (p.codigo == op[i].codigo) {
            printf("Digite o Nome do Operador \n");
            scanf("%s%*c", &p.nome);
            printf("Digite o Usuário do Operador \n");
            scanf("%s%*c", &p.usuario);
            printf("Digite a Senha do Operador \n");
            scanf("%s%*c", &p.senha);
            aux = 1;
            break;
        }
        i++;
    }
    if (aux == 1) {
        int r = editarOpSBIN(p, i);
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
        int r = removerOperadorControleBIN(cod); //excluirCategoria(cod);
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
        return cadastrarOpSBIN(opera, (num - 1));
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



