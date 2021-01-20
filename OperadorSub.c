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

    FILE *listOperador;

    listOperador = fopen(".\\persist\\operador.bin", "ab");
    if (listOperador == NULL) {
        printf("Erro Arquivo \n");
    } else {
        fprintf(listOperador, "Código do operador: %d \n", op.codigo);
        fprintf(listOperador, "Nome do Operador: %s \n", op.nome);
        fprintf(listOperador, "Usuário do Operador: %s \n", op.usuario);
        fprintf(listOperador, "Senha do Operador: %s \n", op.senha);

        fclose(listOperador);
        printf("Cadastro Efetuado com Sucesso \n");
    }

}

void listarOperador() {
    int opc;
    OperadorSistema op;

    char texto[100];
    FILE *listOperador;
    listOperador = fopen(".\\persist\\operador.bin", "rb");
    if (listOperador == NULL) {
        printf("Erro Arquivo \n");
    } else {
        while (fgets(texto, 100, listOperador) != NULL) {
            printf("%s", texto);
        }

        fclose(listOperador);
    }
}

void atualizarOperador() {



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



