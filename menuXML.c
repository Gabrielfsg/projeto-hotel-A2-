/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SalvametoBD.h"
#include "menuXML.h"
#include "xml.h"

void menuImportXML() {
    int opc = 0, r;
    int num;
    char tab[50];
    int vet[16];
    char *pch;
    int i, j = 0, car = 0, car2 = 0;
    //Categoria *cat;
    printf("******* Importar XML ********\n");
    printf("1.Acomodação.\n");
    printf("2.Categoria.\n");
    printf("3.Caixa.\n");
    printf("4.CheckIn.\n");
    printf("5.CheckOut.\n");
    printf("6.Contas a Pagar.\n");
    printf("7.Contas a Receber.\n");
    printf("8.Fornecedor.\n");
    printf("9.Hospede.\n");
    printf("10.Hotel.\n");
    printf("11.Operador Sistema.\n");
    printf("12.Produtos.\n");
    printf("13.Produto de Reserva.\n");
    printf("14.Reservas.\n");
    printf("15.VendaProduto.\n");
    printf("16.Vendas.\n");

    printf("Digite os numeros correspondete as tabelas as quais deseja importar:Ex(1,2,3):\n");
    scanf("%s%*c", tab);
    //separa strig e adicioa no vetor
    pch = strtok(tab, ",");
    while (pch != NULL) {
        vet[i] = atoi(pch);
        pch = strtok(NULL, ",");
        i++;
    }

    printf("1.Salvar em Arquivos TXT (1).\n");
    printf("2.Salvar em Arquivos BIN (2).\n");
    printf("\nDigite a opção!:");
    scanf("%d%*c", &opc);
    switch (opc) {
        case 1:
            importarDadosXMLparaTXT("arquivos\\xml\\BackupHotelXML.xml", vet, i);
            break;
        case 2:
            r = alterar(2);
            if (r = 0) {
                printf("\nErro :\n");
            } else {
                printf("\nBD alterado com SUCESSO!!\n");
            }
            break;
        default:
            printf("\nOPÇÃO INVÁLIDA!!\n");
            break;
    }


}

/* switch (opc) {
          case 1:

              break;
          case 2:

              break;
          case 3:

              cat = getCategoriaXML("arquivos\\xml\\CategoriaXML.xml", &num);
              int i;
              for (i = 0; i < num; i++) {
                  printf("codigo %d \n", cat[i].codigo);
                  printf("descrição %s \n", cat[i].descricao);
                  printf("facilidade %s \n", cat[i].facilidade);
                  printf("valor diaria %f \n", cat[i].valorDiario);
                  printf("PESSOAS %d \n", cat[i].quantidadePessoas);
                  printf("-----------------------------------\n");
              }

              break;
          case 4:
              menuXML();
              break;
          case 5:
              menuPrincipal();
              break;
          default:
              printf("Valor Invalido!\n");
              break;
      }*/
void menuExportaXML() {
    int opc = 0, r;
    int num;
    char tab[50];
    int vet[16];
    char *pch;
    char* file;
    int i, j = 0;
//    Categoria *cat;

    printf("******* Exporta XML ********\n");
    printf("1.Acomodação.\n");
    printf("2.Categoria.\n");
    printf("3.Caixa.\n");
    printf("4.CheckIn.\n");
    printf("5.CheckOut.\n");
    printf("6.Contas a Pagar.\n");
    printf("7.Contas a Receber.\n");
    printf("8.Fornecedor.\n");
    printf("9.Hospede.\n");
    printf("10.Hotel.\n");
    printf("11.Operador Sistema.\n");
    printf("12.Produtos.\n");
    printf("13.Produto de Reserva.\n");
    printf("14.Reservas.\n");
    printf("15.VendaProduto.\n");
    printf("16.Vendas.\n");

    printf("Digite os numeros correspondete as tabelas as quais deseja Eportar para um arquivo XML:Ex(1,2,3):\n");
    scanf("%s%*c", tab);
    //separa strig e adicioa no vetor
    pch = strtok(tab, ",");
    while (pch != NULL) {
        vet[i] = atoi(pch);
        pch = strtok(NULL, ",");
        i++;
    }
    file = geraBackupXML(vet, i);
    printf("Arquivo gerado em : %s\n", file);

}
