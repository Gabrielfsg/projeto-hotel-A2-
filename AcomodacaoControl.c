/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>

void cadastrarAcomodacao() {
    printf("***** CADASTRAR ACOMODAÇÃO *****\n");
    //pega os dados
    printf("Digite o cod da acomodação \n");
    //scanf("%d%*c",&);

    //valida para ver se já existe

    printf("Digite a descrição da acomodação \n");
    //scanf("%d%*c",&);
    printf("Digite as facilidades da acomodação \n");
    //scanf("%d%*c",&);
    
    printf("Digite a categoria da acomodação \n");
    //scanf("%d%*c",&);
    int isCatEscolhida = 0;
    while (isCatEscolhida == 0) {
        int cat;
        printf("CATEGORIA: (1- standard  \n 2- luxo \n3- presidencial\n)\n");
        scanf("%d%*c", &cat);
        switch (cat) {
            case 1:

                isCatEscolhida = 1;
                break;
            case 2:

                isCatEscolhida = 1;
                break;
            case 3:

                isCatEscolhida = 1;
                break;
            default:
                printf("OPÇÃO INVÁLIDA \n");
                break;

        }
    }
    


    //salva no arquivo

}

void listarAcomodacao() {
    //pega a lista de ACOMODAÇÃO do arquivo

    //lista ACOMODAÇÃO
    printf("COD: 123\n");
    printf("DESCRIÇÃO: 123\n");
    //LISTAR FACILIDADES PRECISARÁ DE UM TRATAMENTO ESPECIAL
    printf("FACILIDADES: 123\n");
    printf("CATEGORIAS");

}

void atualizarAcomodacao() {
    printf("***** ALTERAR DADOS DA ACOMODAÇÃO *****\n");

    printf("Digite o cod da acomodação \n");
    //scanf("%d%*c",&);
}

void deletarAcomodacao() {
    printf("***** DELETAR ACOMODAÇÃO *****\n");

    printf("Digite o cod da acomodação \n");
    //scanf("%d%*c",&);
}