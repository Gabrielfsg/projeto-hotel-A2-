/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include "Categoria.h"
#include "Acomodacao.h"
#include "Hospede.h"
#include "HospedeMenu.h"
#include "Reserva.h"
#include "Hotel.h"
#include "Data.h"

#include "SalvametoBD.h"

#include "ReservaSubC.h"

void reservaPQuantidade() {
    int bd = listar();
    Data dataIn;
    Data dataFim;
    int quant = 0, num, cod, num2, hos, num3 = 0, num4, n;
    int r;
    int achei, achei2;
    Acomodacao *aco;
    Categoria *cat;
    Reserva *res;
    Hospede* hosp;
    int achou = 0;
    int achouD = 0, achouR = 0;
    Reserva reserva;
    int codReserva;
    if (bd == 1) {// bd == 1 = txt bd == 2 = bin / chama os metodos utilizados na função
        num4 = numReserva();
        num3 = getNumHospedes();
        num2 = numCategoria();
        num = numAcomodacao();
        aco = listarAcomodacaoTXT();
        cat = listarCategoriaTXT();
        hosp = getAllHospedesTXT(num3);
        res = listarReservaTXT();
    } else if (bd == 2) {
        aco = listarAcomodacaoBIN(&num);
        cat = listarCategoriaBIN(&num2);
        hosp = getAllHospedesBIN(&num3);
        res = listarReservaBIN(&num4);
    }
    int i, j;
    if (bd > 0) {
        int aux = 0;
        while (aux == 0) {
            printf("Entre com a quantidade de pessoas desejada: ");
            scanf("%d*c", &quant);
            if (bd == 1) {
                for (i = 0; i < num2; i++) {// entra com a quantidade minima ou desejada de pessoas no quarto e faz a busca em txt
                    if (cat[i].quantidadePessoas >= quant) {
                        printf("********************\n");
                        printf("CATEGORIA: %s\n", cat[i].descricao);
                        printf("FACILIDADES: %s\n", cat[i].facilidade);
                        printf("VALOR DIARIA: %f\n", cat[i].valorDiario);
                        printf("N° PESSOAS: %d\n", cat[i].quantidadePessoas);
                        printf("--------------------\n");
                        achou++;
                        for (j = 0; j < num; j++) {
                            if (cat[i].codigo == aco[j].categoria.codigo) {
                                printf("\tCOD: %d\n", aco[j].codigo);
                                printf("\tDESCRIÇÃO: %s\n", aco[j].descricao);
                                printf("\tSTATUS: %s\n", aco[j].status);
                                printf("\n");
                            }

                        }
                        aux = 1;
                        printf("********************\n");
                    }
                }
            } else if (bd == 2) {// entra com a quantidade minima ou desejada de pessoas no quarto e faz a busca em bin
                for (i = 0; i < num2; i++) {
                    if (cat[i].quantidadePessoas >= quant) {
                        printf("CATEGORIAS: %s\n", cat[i].descricao);
                        printf("FACILIDADES: %s\n", cat[i].facilidade);
                        printf("VALOR DIARIA: %f\n", cat[i].valorDiario);
                        printf("N° PESSOAS: %d\n", cat[i].quantidadePessoas);
                        achou++;
                        for (j = 0; j < num; j++) {
                            if (cat[i].codigo == aco[j].categoria.codigo) {
                                printf("COD: %d\n", aco[j].codigo);
                                printf("DESCRIÇÃO: %s\n", aco[j].descricao);
                                printf("STATUS: %s\n", aco[j].status);
                            }

                        }
                        aux = 1;
                    }
                }
            }
            if (aux == 0) {// valida se achou a quantidade
                printf("Quantidade não encontrada. \n");
            }
        }
        if (achou > 0) {// caso houver quantidade prossegue
            int aux1 = 0;
            while (aux1 == 0) {
                printf("Digite o código da acomodação que deseja: "); // entra com o código da acomodação que foi mostrada
                scanf("%d*c", &cod);
                if (bd == 1) {
                    achei = validarAcomodacao(cod); // valida se o cod existe
                    if (achei == 1) {
                        aux1 = 1;
                    } else {
                        printf("Código da acomodação não existente. \n");
                    }
                } else if (bd == 2) {
                    achei = validarAcomodacaoBIN(cod); // valida se o cod existe
                    if (achei == 1) {
                        aux1 = 1;
                    } else {
                        printf("Código da acomodação não existente. \n");
                    }
                }
            }
            if (achei == 1) {// se sim preenche o vetor com os dados da acomodação
                for (int i = 0; i < num; i++) {
                    if (aco[i].codigo == cod) {
                        reserva.acomodacao = aco[i];
                    }

                }
                printf("Acomodação %d selecionada. \n", cod); // acomodação que foi pega
                // entra com as datas
                int nq = 0;
                printf("Digita o dia da data de início da reserva (1-30):\n");
                scanf("%d%*c", &dataIn.dia);
                printf("Digita o mes da data de início da reserva (1-12):\n");
                scanf("%d%*c", &dataIn.mes);
                printf("Digita o ano da data de início da reserva:\n");
                scanf("%d%*c", &dataIn.ano);
                reserva.DataIn = dataIn;
                printf("Digita o dia da data do fim da reserva: (1-30)\n");
                scanf("%d%*c", &dataFim.dia);
                printf("Digita o mes da data do fim da reserva: (1-12)\n");
                scanf("%d%*c", &dataFim.mes);
                printf("Digita o ano da data do fim da reserva:\n");
                scanf("%d%*c", &dataFim.ano);
                reserva.DataFin = dataFim;

                aco = listarAcomodacoesDisponiveis(dataIn, dataFim, &nq); // lista as validações disponíveis e quantas são no código digitado
                int isAcoDisponivel = 0;
                for (int i = 0; i < nq; i++) {
                    if (aco[i].codigo == cod) {
                        printf("*******\n"); // mostra os dados das acomodações
                        printf("CODIGO: %d\n", aco[i].codigo);
                        printf("DESC: %s\n", aco[i].descricao);
                        printf("*******\n");
                        isAcoDisponivel = 1; // a acomodacao está disponível nessa data

                    }
                }
                //printf("O NÚMERO DE ACOMODAÇÕES DISPONÍVEIS É %d\n", nq); // numero de acomodações
                if (nq == 0) {// se não houver nenhuma retorna ao menu de cadastro mas se houver prossegue
                    cadReserva();
                }

                if (isAcoDisponivel == 0) {// se a acomodação não está disponível nessa data
                    printf("A ACOMODÃÇÃO NÃO ESTÁ DISPONIVEL NESSA DATA\n");
                    cadReserva();
                }

                int aux2 = 0;
                while (aux2 == 0) {// entrar com o código do hospede
                    printf("Digite o código do hospede: ");
                    scanf("%d*c", &hos);
                    if (bd == 1) {
                        achei2 = validarCodHospede(hos, 1); // valida se o cod existe
                    } else if (bd == 2) {
                        achei2 = validarCodHospede(hos, 2); // valida se o cod existe
                    }

                    if (achei2 == 0) {
                        aux2 = 1;
                    } else {
                        printf("Código do hospede não existente. \n");
                    }
                }
                if (achei2 == 0) {
                    for (int i = 0; i < num3; i++) {// se o cod existir preenche o vetor com todos os dados do hospede
                        if (hos == hosp[i].codigo) {
                            reserva.hospede = hosp[i];
                        }

                    }
                    int aux4 = 0;
                    printf("Hospede %d selecionado. \n", hos);
                    //preenche reserva com as datas digitadas acima
                    reserva.DataIn = dataIn;
                    reserva.DataFin = dataFim;
                    int aux3 = 0;
                    while (aux3 == 0) {
                        printf("Digite o código da Reserva: \n"); // entrar com o cod da reserva
                        scanf("%d%*c", &codReserva);
                        reserva.codigo = codReserva;
                        if (bd == 1) {// txt

                            int validacao = validarReserva(codReserva); //validar o cod da reserva no arquivo txt

                            if (validacao == 1) {// se o resultado que retorna for um o código não pode ser usado e vc deve repetir
                                printf("COD DA RESERVA JÁ EXISTE\n");
                            } else {
                                printf("COD OK!!\n");
                                aux3 = 1;
                            }
                        }
                        if (bd == 2) {// bin

                            int validacao = validarReservaBIN(codReserva); //validar o cod da reserva no arquivo bin

                            if (validacao == 1) {// se o resultado que retorna for um o código não pode ser usado e vc deve repetir
                                printf("COD DA RESERVA JÁ EXISTE\n");
                            } else {
                                printf("COD OK!!\n");
                                aux3 = 1;
                            }
                        }
                    }
                    printf("########## Reserva #############\n"); // mostra tods os dados da struct reserva
                    // com dados da reserva, do hospede, da categoria e da acomodação
                    printf("COD : %d \n", reserva.codigo);
                    printf("Data Inicio: %d/%d/%d \n", reserva.DataIn.dia, reserva.DataIn.mes, reserva.DataIn.ano);
                    printf("Data Fim: %d/%d/%d \n", reserva.DataFin.dia, reserva.DataFin.mes, reserva.DataFin.ano);
                    printf("----Acomodação---\n");
                    printf("cod Aco: %d\n", reserva.acomodacao.codigo);
                    printf("DESCRIÇÃO: %s\n", reserva.acomodacao.descricao);
                    printf("STATUS: %s\n", reserva.acomodacao.status);
                    printf("------Hospede--------\n");
                    printf("COD: %d\n", reserva.hospede.codigo);
                    printf("NOME: %s\n", reserva.hospede.nome);
                    printf("CPF: %s\n", reserva.hospede.cpf);
                    printf("FONE: %s\n", reserva.hospede.telefone);
                    printf("EMAIL: %s\n", reserva.hospede.email);
                    printf("SEXO: %c\n", reserva.hospede.sexo);
                    printf("ESTADO CIVIL: %s\n", reserva.hospede.esCivil);
                    printf("DATA NASC: %d / %d / %d \n", reserva.hospede.dataNascimento.dia, reserva.hospede.dataNascimento.mes, reserva.hospede.dataNascimento.ano);
                    printf("COD ENDER: %d\n", reserva.hospede.endereco.codigo);
                    printf("BAIRRO: %s\n", reserva.hospede.endereco.bairro);
                    printf("CEP: %s\n", reserva.hospede.endereco.cep);
                    printf("CIDADE: %s\n", reserva.hospede.endereco.cidade);
                    printf("LOGRADOURO: %s\n", reserva.hospede.endereco.logradouro);
                    printf("NUMERO: %d\n", reserva.hospede.endereco.numero);
                    printf("UF: %s\n", reserva.hospede.endereco.uf);
                    printf("##########  #############\n");
                    // verifica qual arquivo deve ser e faz o cadastro
                    if (bd == 1) {
                        //TXT
                        int gravou = cadastrarReservaTXT(reserva);
                        if (gravou == 1) {
                            printf("RESERVA CADASTRADA COM SUCESSO\n");
                        } else {
                            printf("ERRO AO CADASTRAR RESERVA\n");
                        }
                    }
                    if (bd == 2) {

                        //BIN
                        int retorno = cadastrarReservaBIN(&reserva, 1);
                        if (retorno == 1) {
                            printf("RESERVA CADASTRADA COM SUCESSO\n");
                        } else {
                            printf("ERRO AO CADASTRAR RESERVA\n");
                        }
                    }


                }
            }
        }


        free(aco);

    }

}

void reservaPCategoria() {
    int bd = listar();
    int num, cod, num2, num3 = 0, num4;
    int opc;
    int r;
    Data dataIn;
    Data dataFim;
    Acomodacao *aco;
    Categoria *cat;
    Reserva *res;
    Hospede *hosp;
    int achou = 0;
    int achei, achei2, hos;
    int achouD = 0, achouR = 0;
    Reserva reserva;
    int codReserva;
    if (bd == 1) {// bd == 1 = txt bd == 2 = bin / chama os metodos utilizados na função
        num4 = numReserva();
        num3 = getNumHospedes();
        num2 = numCategoria();
        num = numAcomodacao();
        aco = listarAcomodacaoTXT();
        cat = listarCategoriaTXT();
        hosp = getAllHospedesTXT(num3);
        res = listarReservaTXT();
    } else if (bd == 2) {
        aco = listarAcomodacaoBIN(&num);
        cat = listarCategoriaBIN(&num2);
        hosp = getAllHospedesBIN(&num3);
        res = listarReservaBIN(&num4);
    }
    if (bd > 0) {
        int aux = 0;
        while (aux == 0) {
            int i, j;
            if (bd == 1) {
                for (i = 0; i < num; i++) {// lista todas as categorias e suas acomodações com o codigo
                    printf("\n****** %d *******\n", i);
                    printf("COD: %d\n", aco[i].codigo);
                    printf("DESCRIÇÃO: %s\n", aco[i].descricao);
                    printf("STATUS: %s\n", aco[i].status);
                    achou++;
                    aux++;
                    for (j = 0; j < num2; j++) {
                        if (aco[i].categoria.codigo == cat[j].codigo) {
                            printf("CATEGORIAS: %s\n", cat[j].descricao);
                            printf("FACILIDADES: %s\n", cat[j].facilidade);
                            printf("VALOR DIARIA: %f\n", cat[j].valorDiario);
                            printf("N° PESSOAS: %d\n", cat[j].quantidadePessoas);
                        }

                    }
                }
            } else if (bd == 2) {
                for (i = 0; i < num; i++) {
                    printf("\n****** %d *******\n", i);
                    printf("COD: %d\n", aco[i].codigo);
                    printf("DESCRIÇÃO: %s\n", aco[i].descricao);
                    printf("STATUS: %s\n", aco[i].status);
                    achou++;
                    aux++;
                    for (j = 0; j < num2; j++) {
                        if (aco[i].categoria.codigo == cat[j].codigo) {
                            printf("CATEGORIAS: %s\n", cat[j].descricao);
                            printf("FACILIDADES: %s\n", cat[j].facilidade);
                            printf("VALOR DIARIA: %f\n", cat[j].valorDiario);
                            printf("N° PESSOAS: %d\n", cat[j].quantidadePessoas);
                        }

                    }
                }
            }
            if (aux == 0) {// se n tiver nenhuma cadastrada ele da essa resposta
                printf("Acomodação não encontrada. \n");
            }
            if (achou > 0) {// se houver vc deve digitar a data
                int nq = 0;
                printf("Digita o dia da data de início da reserva (1-30):\n");
                scanf("%d%*c", &dataIn.dia);
                printf("Digita o mes da data de início da reserva (1-12):\n");
                scanf("%d%*c", &dataIn.mes);
                printf("Digita o ano da data de início da reserva:\n");
                scanf("%d%*c", &dataIn.ano);
                reserva.DataIn = dataIn;
                printf("Digita o dia da data do fim da reserva: (1-30)\n");
                scanf("%d%*c", &dataFim.dia);
                printf("Digita o mes da data do fim da reserva: (1-12)\n");
                scanf("%d%*c", &dataFim.mes);
                printf("Digita o ano da data do fim da reserva:\n");
                scanf("%d%*c", &dataFim.ano);
                reserva.DataFin = dataFim;


                aco = listarAcomodacoesDisponiveis(dataIn, dataFim, &nq); // verifica qual estão disponíveis na data digitada e retorna o código e descrição delas

                for (int i = 0; i < nq; i++) {
                    printf("*****************\n");
                    printf("CODIGO: %d\n", aco[i].codigo);
                    printf("DESC: %s\n", aco[i].descricao);
                    printf("*****************\n");
                }
                printf("O NÚMERO DE ACOMODAÇÕES DISPONÍVEIS É %d\n", nq); // numero de cat cadastradas
                if (nq == 0) {// se n houver nenhuma volta ao menu de cadastro
                    cadReserva();
                }
                int aux1 = 0;
                while (aux1 == 0) {
                    printf("Digite o código da acomodação que deseja: "); // digite o cod da acomodação que escolheu
                    scanf("%d*c", &cod);
                    if (bd == 1) {
                        achei = validarAcomodacao(cod); // valida o codigo txt
                        if (achei == 1) {// se = 1 o código n existe e pode ser usado
                            aux1 = 1;
                        } else {// caso contrario deve digitar outro
                            printf("Código da acomodação não existente. \n");
                        }
                    } else if (bd == 2) {
                        achei = validarAcomodacaoBIN(cod); //valida o cod em bin
                        if (achei == 1) {// se = 1 o código n existe e pode ser usado
                            aux1 = 1;
                        } else {// caso contrario deve digitar outro
                            printf("Código da acomodação não existente. \n");
                        }
                    }
                }
                if (achei == 1) {// preenche o vetor com os dados
                    for (int i = 0; i < num; i++) {
                        if (aco[i].codigo == cod) {
                            reserva.acomodacao = aco[i];
                        }

                    }
                    printf("Acodação %d selecionada. \n", cod);
                    int aux2 = 0;
                    while (aux2 == 0) {
                        printf("Digite o código do hospede: ");
                        scanf("%d*c", &hos);
                        if (bd == 1) {//txt
                            achei2 = validarCodHospede(hos, 1); // valida o codigo txt
                        } else if (bd == 2) {//bin
                            achei2 = validarCodHospede(hos, 2); //valida o cod em bin
                        }
                        if (achei2 == 0) {// se achei == 0  cod pode ser usado se n deve digitar outro
                            aux2 = 1;
                        } else {
                            printf("Código do hospede não existente. \n");
                        }
                    }
                    if (achei2 == 0) {
                        for (int i = 0; i < num3; i++) {// preenche vetor com os dados
                            if (hos == hosp[i].codigo) {
                                reserva.hospede = hosp[i];
                            }

                        }
                        int aux4 = 0;
                        printf("Hospede %d selecionado. \n", cod);
                        reserva.DataIn = dataIn; // aloca os dados da data na struct reserva
                        reserva.DataFin = dataFim;
                        int aux3 = 0;
                        while (aux3 == 0) {
                            printf("Data disponível! \n");
                            printf("Digite o código da Reserva: \n");
                            scanf("%d%*c", &codReserva);
                            reserva.codigo = codReserva;
                            if (bd == 1) {// txt

                                int validacao = validarReserva(codReserva); // valida o cod reserva

                                if (validacao == 1) {
                                    printf("COD DA RESERVA JÁ EXISTE\n");
                                } else {
                                    printf("CODIGO DISPONIVEL !!\n");
                                    aux3 = 1;
                                }
                            }
                            if (bd == 2) {//bin

                                int validacao = validarReservaBIN(codReserva); // valida o cod reserva

                                if (validacao == 1) {
                                    printf("COD DA RESERVA JÁ EXISTE\n");
                                } else {
                                    printf("CODIGO DISPONIVEL !!\n");
                                    aux3 = 1;
                                }
                            }
                        }
                        printf("########## Reserva #############\n");
                        // dados da struct reserva com dados do hospede,acomodação categoria e reserva
                        printf("COD : %d \n", reserva.codigo);
                        printf("Data Inicio: %d/%d/%d \n", reserva.DataIn.dia, reserva.DataIn.mes, reserva.DataIn.ano);
                        printf("Data Fim: %d/%d/%d \n", reserva.DataFin.dia, reserva.DataFin.mes, reserva.DataFin.ano);
                        printf("----Acomodação---\n");
                        printf("cod Aco: %d\n", reserva.acomodacao.codigo);
                        printf("DESCRIÇÃO: %s\n", reserva.acomodacao.descricao);
                        printf("STATUS: %s\n", reserva.acomodacao.status);
                        printf("------Hospede--------\n");
                        printf("COD: %d\n", reserva.hospede.codigo);
                        printf("NOME: %s\n", reserva.hospede.nome);
                        printf("CPF: %s\n", reserva.hospede.cpf);
                        printf("FONE: %s\n", reserva.hospede.telefone);
                        printf("EMAIL: %s\n", reserva.hospede.email);
                        printf("SEXO: %c\n", reserva.hospede.sexo);
                        printf("ESTADO CIVIL: %s\n", reserva.hospede.esCivil);
                        printf("DATA NASC: %d / %d / %d \n", reserva.hospede.dataNascimento.dia, reserva.hospede.dataNascimento.mes, reserva.hospede.dataNascimento.ano);
                        printf("COD ENDER: %d\n", reserva.hospede.endereco.codigo);
                        printf("BAIRRO: %s\n", reserva.hospede.endereco.bairro);
                        printf("CEP: %s\n", reserva.hospede.endereco.cep);
                        printf("CIDADE: %s\n", reserva.hospede.endereco.cidade);
                        printf("LOGRADOURO: %s\n", reserva.hospede.endereco.logradouro);
                        printf("NUMERO: %d\n", reserva.hospede.endereco.numero);
                        printf("UF: %s\n", reserva.hospede.endereco.uf);
                        printf("##########  #############\n");
                        // faz o cadastro de acordo com o arquivo
                        if (bd == 1) {
                            //TXT
                            int gravou = cadastrarReservaTXT(reserva);
                            if (gravou == 1) {
                                printf("RESERVA CADASTRADA COM SUCESSO\n");
                                aux = 1;
                            } else {
                                printf("ERRO AO CADASTRAR RESERVA\n");
                                aux = 1;
                            }
                        }
                        if (bd == 2) {

                            //BIN
                            int retorno = cadastrarReservaBIN(&reserva, 1);
                            if (retorno == 1) {
                                printf("RESERVA CADASTRADA COM SUCESSO\n");
                                aux = 1;
                            } else {
                                printf("ERRO AO CADASTRAR RESERVA\n");
                                aux = 1;
                            }
                        }


                    }
                }
            }
        }
    }
    free(aco);
}


/*void reservar() {
    int bd = listar();
    int quant, num, cod, num2;
    int r;
    Acomodacao *aco;
    Categoria *cat;
    int achou = 0;
    int achouD = 0;
    aco = listarAcomodacaoBIN(&num);
    cat = listarCategoriaBIN(&num2);
    int i, j;
    for (i = 0; i < num; i++) {
        printf("\n**************** %d *****************\n", i);
        printf("COD: %d\n", aco[i].codigo);
        printf("DESCRIÇÃO: %s\n", aco[i].descricao);
        printf("STATUS: %s\n", aco[i].status);
        achou++;
        for (j = 0; j < num2; j++) {
            if (aco[i].categoria.codigo == cat[j].codigo) {
                printf("CATEGORIAS: %s\n", cat[j].descricao);
                printf("FACILIDADES: %s\n", cat[j].facilidade);
                printf("VALOR DIARIA: %f\n", cat[j].valorDiario);
                printf("N° PESSOAS: %d\n", cat[j].quantidadePessoas);
            }

        }

    }
    printf("Entre com a quantidade de pessoas desejada: ");
    scanf("%d*c", &quant);

    for (i = 0; i < num; i++) {
        if (cat[i].quantidadePessoas == quant) {
            printf("\n**************** %d *****************\n", i);
            printf("COD: %d\n", aco[i].codigo);
            printf("DESCRIÇÃO: %s\n", aco[i].descricao);
            printf("STATUS: %s\n", aco[i].status);
            achou++;
            for (j = 0; j < num2; j++) {
                if (aco[i].categoria.codigo == cat[j].codigo) {
                    printf("CATEGORIAS: %s\n", cat[j].descricao);
                    printf("FACILIDADES: %s\n", cat[j].facilidade);
                    printf("VALOR DIARIA: %f\n", cat[j].valorDiario);
                    printf("N° PESSOAS: %d\n", cat[j].quantidadePessoas);
                }

            }
        }
    }
    free(aco);
    free(cat);
}
 */

/*
 * FUNÇÃO: reservaCombCriterios 
 * 
 * Cadastra uma Reserva de acordo com as preferências do hóspede.
 * O hóspede responsável pela reserva deve informar a quantidade de hóspede,
 * a data inicial e final da reserva, qual facilidades (categoria) quer, para
 * então escolher uma acomodação disponível.
 * 
 * PARÂMETROS: nenhum
 * 
 * RETORNO: Void
 */
void reservaCombCriterios() {
    Data dataIn;
    Data dataFim;
    //Categoria categoriaDaReserva;
    Acomodacao acomodacaoDaReserva;
    //Acomodacao* arrayAllAcomod;
    Acomodacao* arrayAcomodacoesDisponiveis;
    Categoria *arrayAllCat;
    Reserva reserva;
    //Hospede* arrayAllhosp;


    int numLinhaCat, numAcomodDisponivel = 0;
    int codHosp, codCat, codAcomod = 0;

    //pega os dados necessários: Array de Hospedes, de Acomodações e de Categorias
    int ext = listar();
    if (ext == 2) {
        //BIN        
        //arrayAllhosp = getAllHospedesBIN(&numHospedes);
        //arrayAllAcomod = listarAcomodacaoBIN(&numLinhaAcomod);
        arrayAllCat = listarCategoriaBIN(&numLinhaCat);
    }
    if (ext == 1) {
        //TXT
        //numHospedes = getNumHospedes();
        numLinhaCat = numCategoria();
        //numLinhaAcomod = numAcomodacao();

        //arrayAllhosp = getAllHospedesTXT(numHospedes);
        //arrayAllAcomod = listarAcomodacaoTXT();
        arrayAllCat = listarCategoriaTXT();

    }
    int qteHospedes;


    //printf("NUM QUARTOS = %d\n", numLinhaAcomod);
    printf("*********** RESERVA ***********\n\n");

    //pega a quantidade de Hóspedes
    printf("Digite a quantidade de Hospedes da Reserva:\n");
    scanf("%d%*c", &qteHospedes);

    //Será gravado no aquivo apenas o Hóspede responsável por aquela reserva
    printf("Digite o código do Hospede Responsável:\n");
    scanf("%d%*c", &codHosp);
    //printf("DEBUG: COD HOSP = %d\n",codHosp);

    reserva.codH = codHosp;
    if (ext == 1) {
        //TXT
        reserva.hospede = getHospedeByCodTXT(codHosp);

    }
    if (ext == 2) {
        //BIN
        reserva.hospede = getHospedeByCodBIN(codHosp);
    }

    //printf("NUM HOSPEDES = %d\n", numHospedes);
    /*for (int i = 0; i < numHospedes; i++) {
        if (codHosp == arrayAllhosp[i].codigo) {
            printf("HOSPEDE ENCONTRADO\n");
            reserva.codH = codHosp;
            reserva.hospede = arrayAllhosp[i];
        }
    }
     */

    //Lista as categorias que comportam a quantidade de Hóspedes Informada
    printf("************* LISTA DE CATEGORIAS DISPONÍVEIS *************\n");
    for (int i = 0; i < numLinhaCat; i++) {
        if (arrayAllCat[i].quantidadePessoas >= qteHospedes) {
            printf("COD: %d\n", arrayAllCat[i].codigo);
            printf("DESCRIÇÃO: %s\n", arrayAllCat[i].descricao);
            printf("FACILIDADE: %s\n", arrayAllCat[i].facilidade);
            printf("QTE PESSOAS: %d\n", arrayAllCat[i].quantidadePessoas);
            printf("VALOR: %.2f\n", arrayAllCat[i].valorDiario);
        }
    }

    printf("************* FIM DA LISTA DE CATEGORIAS *************\n");
    printf("Digite o código da Categoria:\n");
    scanf("%d%*c", &codCat);

    //valida o codigo da categoria que ele digitou
    int validCat = 0;
    if (ext == 1) {
        //TXT
        validCat = validarCategoria(codCat);
    }
    if (ext == 2) {
        //BIN
        validCat = validarCategoriaBIN(codCat);
    }

    /*for (int i = 0; i < numLinhaCat; i++) {
        if (arrayAllCat[i].codigo == codCat) {
            //categoriaDaReserva = arrayAllCat[i];
            validCat = 1;
        }
    }*/

    if (validCat == 0) {
        printf("CÓDIGO DA CATEGORIA INVÁLIDO\n");
        return;
    }

    //PEGA AS DATAS
    printf("Digita o dia da data de início da reserva:\n");
    scanf("%d%*c", &dataIn.dia);
    printf("Digita o mes da data de início da reserva:\n");
    scanf("%d%*c", &dataIn.mes);
    printf("Digita o ano da data de início da reserva:\n");
    scanf("%d%*c", &dataIn.ano);

    printf("Digita o dia da data do fim da reserva:\n");
    scanf("%d%*c", &dataFim.dia);
    printf("Digita o mes da data do fim da reserva:\n");
    scanf("%d%*c", &dataFim.mes);
    printf("Digita o ano da data do fim da reserva:\n");
    scanf("%d%*c", &dataFim.ano);

    //pega os quartos disponíveis dentro da data que foi digitada
    arrayAcomodacoesDisponiveis = listarAcomodacoesDisponiveis(dataIn, dataFim, &numAcomodDisponivel);
    //mostra os quartos disponíveis que tem a categoria que foi informada
    printf("************* LISTA DE QUARTOS DISPONÍVEIS *************\n");
    for (int i = 0; i < numAcomodDisponivel; i++) {
        // printf("******** %d *********\n", numAcomodDisponivel);
        //printf("COD: %d\n",arrayAcomodacoesDisponiveis[i].codigo);
        //printf("DESC: %d\n",arrayAcomodacoesDisponiveis[i].codigo);
        if (arrayAcomodacoesDisponiveis[i].categoria.codigo == codCat) {
            printf("*****************\n");
            printf("CODIGO: %d\n", arrayAcomodacoesDisponiveis[i].codigo);
            printf("DESC: %s\n", arrayAcomodacoesDisponiveis[i].descricao);
            printf("*****************\n");

        }
    }
    printf("O NÚMERO DE ACOMODAÇÕES DISPONÍVEIS É %d\n", numAcomodDisponivel);
    printf("************* FIM DA LISTA DE QUARTOS *************\n");

    printf("Digite o código do quarto: \n");
    scanf("%d%*c", &codAcomod);
    //valida o código da acomodação
    int achou = 0;
    for (int i = 0; i < numAcomodDisponivel; i++) {
        if (arrayAcomodacoesDisponiveis[i].categoria.codigo == codCat) {
            if (arrayAcomodacoesDisponiveis[i].codigo == codAcomod) {
                acomodacaoDaReserva = arrayAcomodacoesDisponiveis[i];
                achou = 1;
            }
        }

    }

    if (achou == 0) {
        printf("CÓDIGO DO QUARTO INVÁLIDO\n");
        return;
    }

    int codReserva;
    int aux = 0;
    while (aux == 0) {
        printf("Digite o código da Reserva: \n");
        scanf("%d%*c", &codReserva);
        if (ext == 1) {
            //TXT
            int validacao = validarReserva(codReserva);
            //printf("VALID: %d\n", validacao);

            if (validacao == 1) {
                printf("COD DA RESERVA JÁ EXISTE\n");
            } else {
                //printf("COD OK!!\n");
                aux = 1;
            }
        }
        if (ext == 2) {
            //BIN
            int validacao = validarReservaBIN(codReserva);
            //printf("VALID: %d\n", validacao);

            if (validacao == 1) {
                printf("COD DA RESERVA JÁ EXISTE\n");
            } else {
                //printf("COD OK!!\n");
                aux = 1;
            }
        }
    }

    reserva.codigo = codReserva;
    reserva.DataFin = dataFim;
    reserva.DataIn = dataIn;
    reserva.acomodacao = acomodacaoDaReserva;
    reserva.codA = acomodacaoDaReserva.codigo;



    printf("########## SCTRUCT #############\n");

    printf("COD: %d \n", reserva.codigo);
    printf("COD ACOMODACAO: %d \n", reserva.acomodacao.codigo);
    //printf("COD ACOMODACAO: %d \n", reserva.codA);
    printf("ACOMODACAO DESC: %s \n", reserva.acomodacao.descricao);
    printf("COD CATEGORIA: %d \n", reserva.acomodacao.categoria.codigo);
    printf("DATA INI: %d /%d /%d\n", reserva.DataIn.dia, reserva.DataIn.mes, reserva.DataIn.ano);
    printf("DATA FIM: %d /%d /%d\n", reserva.DataFin.dia, reserva.DataFin.mes, reserva.DataFin.ano);
    printf("HOSPEDE: %d\n", reserva.hospede.codigo);
    printf("HOSPEDE: %d\n", reserva.codH);

    printf("##########  #############\n");



    if (ext == 2) {
        //BIN
        int retorno = cadastrarReservaBIN(&reserva, 1);
        if (retorno == 1) {
            printf("RESERVA CADASTRADA COM SUCESSO\n");
        } else {
            printf("ERRO AO CADASTRAR RESERVA\n");
        }
    }
    if (ext == 1) {
        //TXT
        int gravou = cadastrarReservaTXT(reserva);
        if (gravou == 1) {
            printf("RESERVA CADASTRADA COM SUCESSO\n");
        } else {
            printf("ERRO AO CADASTRAR RESERVA\n");
        }
    }


    //free(arrayAllAcomod);
    free(arrayAllCat);
    //free(arrayAllhosp);
}

int contarLinhasResTXT() {// contar linhas arq txt

    FILE *listOperador;
    int numOL = 0, c, numF;

    listOperador = fopen("arquivos\\ReservaTXT.txt", "r");
    if (listOperador == NULL) {
        listOperador = fopen("arquivos\\ReservaTXT.txt", "w+");
        if (listOperador == NULL) {
            printf("Erro ao acessar arquivo\n");
            return 0;
        }
    }
    //Lendo o arquivo 1 por 1
    while ((c = fgetc(listOperador)) != EOF) {
        if (c == '\n') {
            //soma a quantidade de linhas do TXT
            numOL++;
        }
    }
    numF = numOL / 9; //divide por 18 que é o número de dados do hotel
    fclose(listOperador);
    free(listOperador);

    return numF;



}

void listarReserva() {
    int bd = listar();
    int n, aux;
    Reserva *res;
    if (bd == 1) {
        n = numReserva();
        res = listarReservaTXT();
    } else if (bd == 2) {
        res = listarReservaBIN(&n);
    }
    if (bd > 0) {
        int i;
        for (i = 0; i < n; i++) {
            printf("COD: %d \n", res[i].codigo);
            printf("DATA INI: %d /%d /%d\n", res[i].DataIn.dia, res[i].DataIn.mes, res[i].DataIn.ano);
            printf("DATA FIM: %d /%d /%d\n", res[i].DataFin.dia, res[i].DataFin.mes, res[i].DataFin.ano);
            printf("HOSPEDES: (%d) - %s \n", res[i].hospede.codigo, res[i].hospede.nome);
            printf("Acomodação: (%d) - %s \n", res[i].acomodacao.codigo, res[i].acomodacao.descricao);
            printf("\n");
        }

        free(res);
    }
}

//Daniel

void reservarPorData() {
    int dia, mes, ano;
    Data *dataIn, *dataFim;
    //lista o modo de salvamento de dados
    int bd = listar();
    int aux = 0;
    // se for maior que 0 existe uma opção definida
    if (bd > 0) {
        int quant, num = 0, cod, num2, numH = 0;
        int r;
        Acomodacao *aco;
        Categoria *cat;
        Hospede *hos;
        Reserva res;
        int achou = 0;
        int achouD = 0;

        printf("Entre com a data Desejada: \n");
        while (aux == 0) {
            printf("Digita o dia da data de início da reserva:\n");
            scanf("%d%*c", &dia);
            printf("Digita o mes da data de início da reserva:\n");
            scanf("%d%*c", &mes);
            printf("Digita o ano da data de início da reserva:\n");
            scanf("%d%*c", &ano);
            dataIn = newData(dia, mes, ano);
            if (dataIn != NULL) {
                break;
            }
        }
        aux = 0;
        while (aux == 0) {
            printf("Digita o dia da data do fim da reserva:\n");
            scanf("%d%*c", &dia);
            printf("Digita o mes da data do fim da reserva:\n");
            scanf("%d%*c", &mes);
            printf("Digita o ano da data do fim da reserva:\n");
            scanf("%d%*c", &ano);
            dataFim = newData(dia, mes, ano);
            if (dataFim != NULL) {
                if (data1maiordata2(*dataFim, *dataIn) == 1) {
                    break;
                } else {
                    printf("Data final, menor que data inicial, favor digite uma data final válida!!!\n");
                }

            }
        }
        //lista as Acomodações disponiveis no intervalo da data digitada
        aco = listarAcomodacoesDisponiveis(*dataIn, *dataFim, &num);
        //verifica onde sera buscado os dados
        if (bd == 1) {
            numH = getNumHospedes();
            hos = getAllHospedesTXT(numH);
            cat = listarCategoriaTXT();
            num2 = numCategoria();
            res.codigo = maiorCodReservaTXT() + 1;
        } else {
            hos = getAllHospedesBIN(&numH);
            cat = listarCategoriaBIN(&num2);
            res.codigo = maiorCodReservaBIN() + 1;
        }

        res.DataIn = *dataIn;
        res.DataFin = *dataFim;
        //mostra as acomodações disponiveis
        if (num > 0) {
            int i, j;
            for (i = 0; i < num; i++) {
                printf("\n**************** %d *****************\n", i);
                printf("COD: %d\n", aco[i].codigo);
                printf("DESCRIÇÃO: %s\n", aco[i].descricao);
                printf("STATUS: %s\n", aco[i].status);
                achou++;
                for (j = 0; j < num2; j++) {
                    if (aco[i].categoria.codigo == cat[j].codigo) {
                        printf("CATEGORIAS: %s\n", cat[j].descricao);
                        printf("FACILIDADES: %s\n", cat[j].facilidade);
                        printf("VALOR DIARIA: %f\n", cat[j].valorDiario);
                        printf("N° PESSOAS: %d\n", cat[j].quantidadePessoas);
                    }

                }

            }
            //pede para digitar o codi da acomodação listada, e sai do laço apenas quando o codigo for valido
            int aux2 = 0;
            while (aux2 == 0) {
                printf("Entre com o codigo da acomodação desejada: ");
                scanf("%d*c", &cod);
                for (i = 0; i < num; i++) {
                    if (aco[i].codigo == cod) {
                        for (j = 0; j < num2; j++) {
                            if (aco[i].categoria.codigo == cat[j].codigo) {
                                //coloca a categoria no vetor de acomodação
                                aco[i].categoria = cat[j];
                                //coloca a acomodação junto com a categoria em reserva com acomodação
                                res.acomodacao = aco[i];
                                aux2 = 1;
                            }
                        }
                    }
                }
                if (aux2 == 0) {
                    printf("\nCodigo não encontrado!!\n");
                }
            }
            //lista todos os hospedes cadastrados para o operador digitar o codigo, e sai apenas quando o codigo for valido 
            listarHospedesControl();
            aux2 = 0;
            while (aux2 == 0) {
                printf("Entre com o codigo do hospede desejado: ");
                scanf("%d*c", &cod);
                for (i = 0; i < numH; i++) {
                    //se achar
                    if (hos[i].codigo == cod) {
                        aux2 = 1;
                        // pega todo o Hospede e inclui na reserva
                        res.hospede = hos[i];
                    }
                }
                if (aux2 == 0) {
                    printf("\nCodigo não encontrado!!\n");
                }
            }
            // salva a reserva no determinado tipo de salvamento de dados
            int retorno = 0;
            if (bd == 2) {
                retorno = cadastrarReservaBIN(&res, 1);
                printf("BIN");
            }
            if (bd == 1) {
                retorno = cadastrarReservaTXT(res);
            }

            //printf("DEBUG: O RETORNO É %d\n", retorno);
            if (retorno >= 1) {
                printf("Reserva Cadastrada com Sucesso!!\n");
            } else {
                printf("Erro ao cadastrar!\n");
            }
            //teste(&res);

        } else {
            printf("Nenhuma Acomodação disponivel para esta data!!\n");
        }
        //liera memoria
        free(aco);
        free(cat);
        free(hos);
    } else {
        printf("\nAltere a opção de salvamento em (MENU Principal->9 . Configurações-> 1. Op de BD.)\n");
    }

}
//Tales

/*void * mostrarReservaBIN(int *numLinha) {

    FILE *arquivo;
    //abrea arquivo para leitura apenas "rb"
    arquivo = fopen("arquivos\\ReservaBIN.bin", "rb");
    if (arquivo == NULL) {
        //cria arquivo para leitura\escrita se não houver "w+b"
        arquivo = fopen("arquivos\\ReservaBIN.bin", "w+b");
        if (arquivo == NULL) {
            printf("\nERRO ao acessar arquivo\n");
            return NULL;
        }
    }
 *numLinha = 0;

    Reserva re;
    //instancia vetor com tamanho 1 printf("DEBUG 2.5\n");
    Reserva *res = (Reserva*) calloc(1, sizeof (Reserva));
    //pega a primeira linha se existir

    int r = fread(&re, sizeof (Reserva), 1, arquivo);
    if (r > 0) {
        do {
            //soma a +1 no tamanho do vetor o qual comessa com 0
 *numLinha = (*numLinha) + 1;
            // realoca o vetor com o tamanho numLinha, a arqa interação ele realoca um a mais
            res = realloc(res, *numLinha * sizeof (Reserva));
            //adicionar o struct o vetor,(numLinha -1) pois o vetor comessa sempre por 0
            res[(*numLinha) - 1] = re;
            //pega o proximo indice, se existir
            fread(&re, sizeof (Reserva), 1, arquivo);
            //verifica se chegou no fim do arquivo
        } while (!feof(arquivo));
    } else {
        return NULL;
    }
    //fecha arquivo
    fclose(arquivo);
    //libera memoria
    free(arquivo);

    return res;
}*/

//Tales

void mostrarReservas() {
    int bd = listar();
    int numR = 0;
    Reserva *res;
    if (bd == 1) {
        numR = numReserva();
        res = listarReservaTXT();
    }
    if (bd == 2) {

        res = listarReservaBIN(&numR);

    }
    int i;
    for (i = 0; i < numR; i++) {
        printf("################################\n\n");
        printf("COD : %d \n", res[i].codigo);
        printf("Data Inicio: %d/%d/%d \n", res[i].DataIn.dia, res[i].DataIn.mes, res[i].DataIn.ano);
        printf("Data Fim: %d/%d/%d \n", res[i].DataFin.dia, res[i].DataFin.mes, res[i].DataFin.ano);
        printf("Status = %d \n", res[i].status);
        printf("----Acomodação---\n");
        printf("cod Aco: %d\n", res[i].acomodacao.codigo);
        printf("DESCRIÇÃO: %s\n", res[i].acomodacao.descricao);
        printf("STATUS: %s\n", res[i].acomodacao.status);
        printf("------Hospede--------\n");
        printf("COD: %d\n", res[i].hospede.codigo);
        printf("NOME: %s\n", res[i].hospede.nome);
        printf("CPF: %s\n", res[i].hospede.cpf);
        printf("FONE: %s\n", res[i].hospede.telefone);
        printf("EMAIL: %s\n", res[i].hospede.email);
        printf("SEXO: %c\n", res[i].hospede.sexo);
        printf("ESTADO CIVIL: %s\n", res[i].hospede.esCivil);
        //DATA
        printf("DATA NASC: %d / %d / %d \n", res[i].hospede.dataNascimento.dia, res[i].hospede.dataNascimento.mes, res[i].hospede.dataNascimento.ano);
        //ENDEREÇO
        printf("COD ENDER: %d\n", res[i].hospede.endereco.codigo);
        printf("BAIRRO: %s\n", res[i].hospede.endereco.bairro);
        printf("CEP: %s\n", res[i].hospede.endereco.cep);
        printf("CIDADE: %s\n", res[i].hospede.endereco.cidade);
        printf("LOGRADOURO: %s\n", res[i].hospede.endereco.logradouro);
        printf("NUMERO: %d\n", res[i].hospede.endereco.numero);
        printf("UF: %s\n", res[i].hospede.endereco.uf);

        printf("################################\n\n");

    }

}
//Daniel

Acomodacao* listarAcomodacoesDisponiveis(Data in, Data fin, int *quantidadeAcoDisponiveis) {

    int bd = listar();
    Acomodacao *aco;
    Reserva * res;
    int numA;
    int numR;
    if (bd == 1) {
        aco = listarAcomodacaoTXT();
        res = listarReservaTXT();
        numA = numAcomodacao();
        numR = numReserva();
    } else {
        aco = listarAcomodacaoBIN(&numA);
        res = listarReservaBIN(&numR);
    }
    Acomodacao *aco2 = (Acomodacao*) calloc(numA, sizeof (Acomodacao));
    //printf("numA = %d ,numR %d \n",numA,numR);
    int i, j = 0, k = 0, aux = 0, aux2 = 0;
    int acoNDis[numR];
    for (i = 0; i < numR; i++) {

        for (j = 0; j < numA; j++) {

            if (aco[j].codigo == res[i].acomodacao.codigo) {

                if (dataDisponivel(in, fin, res[i].DataIn, res[i].DataFin) == 0) {
                    acoNDis[aux] = aco[j].codigo;
                    aux++;
                    break;
                }
            }
        }
    }

    for (i = 0; i < numA; i++) {

        for (j = 0; j <= aux; j++) {

            if (aco[i].codigo == acoNDis[j]) {
                aux2 = 1;
            }
        }
        if (aux2 == 0) {
            aco2[*quantidadeAcoDisponiveis] = aco[i];
            *quantidadeAcoDisponiveis = (*quantidadeAcoDisponiveis) + 1;
        }
        aux2 = 0;

    }


    /*for (i = 0; i < numA; i++) {
        // aco2 = realloc(aco, *numLinha * sizeof (Acomodacao));
        for (j = 0; j < numR; j++) {
            if (aco[i].codigo == res[j].acomodacao.codigo) {
                aux = 1;
                for (k = 0; k < numR; k++) {
                    if (aco[i].codigo == res[k].acomodacao.codigo) {
                        if (dataDisponivel(in, fin, res[k].DataIn, res[k].DataFin) == 0) {
                            aux2 = 1;
                        }
                    }
                    if (aux2 == 0) {
                        aco2[*quantidadeAcoDisponiveis] = aco[i];
     *quantidadeAcoDisponiveis = (*quantidadeAcoDisponiveis) + 1;
                    }
                    aux2 = 0;
                }
            }
        }
        if (aux == 0) {
            aco2[*quantidadeAcoDisponiveis] = aco[i];
     *quantidadeAcoDisponiveis = (*quantidadeAcoDisponiveis) + 1;
        }
        aux = 0;
    }*/
    free(res);
    return aco2;

}

