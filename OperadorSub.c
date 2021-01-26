#include <stdio.h>
#include <stdlib.h>
#include "OperadorSistema.h"
#include "OperadorsistemaMenu.h"
#include <string.h>

void cadastrarOperador() {
    OperadorSistema op;
    int n, i, r;
    OperadorSistema *opera = listarOpBIN(&n);
    int aux = 0, cod = 0;
    int valid, li;
    printf("***** CADASTRAR OPERADOR *****\n");
    printf("Digite o Cod do Operador \n");
    scanf("%d%*c", &op.codigo);
    valid = validarOpBIN(op.codigo);
    if (valid == 1) {
        printf("Operador já cadastrado! \n");
    } else {
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

        //salva no arquivo
        //cadastrarOpBin(&op, 1);
        r = controleCadTXT(op);
        printf("Cadastro Efetuado com sucesso! \n");
        aux = 0;
        cod = 0;
    }
}

void listarOperador() {
    printf("ENTROU LISTAR OP\n");
    int n, aux;
    OperadorSistema *opera;
    opera = listarOpTXT();
    n = contarLinhasTXT();
    //opera = listarOpBIN(&n);
    int i;
    for (i = 0; i < n; i++) {
        printf("\n*******%d************", i);
        printf("\nCodigo: %d", opera[i].codigo);
        printf("\nNome: %s", opera[i].nome);
        printf("\nUsuario: %s", opera[i].usuario);
        printf("\nSenha: %s", opera[i].senha);
        printf("\n");
    }
    free(opera);
}

void atualizarOperador() {
    int n, aux;
    OperadorSistema op;
    OperadorSistema *opera;
    //opera = listarOpBIN(&n);
    opera = listarOpTXT();
    n = contarLinhasTXT();
    printf("***** ALTERAR DADOS DO OPERADOR *****\n");
    printf("Digite o cod da acomodação \n");
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
        }
        i++;
    }
    if (aux == 1) {
        //int r = editarOpSBIN(op, i);
        int t = editarOperadorTXT(opera, op, n);
        printf("Atualização Efetuada com sucesso! \n");
    } else {
        printf("Operador não cadastrado. \n");
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
        //int r = removerOperadorControleBIN(cod);
        int r = removerOperadorControleTXT(cod);
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
    numF = numOL/4;
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
    //OperadorSistema *opera = listarOpBIN(&num);
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
        }
    }
    //apaga arquivo
    //int v = removerOperadorBIN();

    return salvarOperadorTXT(opera, num - 1);
}

