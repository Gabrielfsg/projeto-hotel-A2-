/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "Principal.h"
#include "Hospede.h"
#include "HospedeMenu.h"
#include "SalvametoBD.h"

void menuCRUDHospedes() {
    int sair = 0;
    int opc;
    while (sair == 0) {
        printf("******* GESTÃO DE DADOS - HÓSPEDES **********\n");
        printf("Opções: \n");
        printf("1.Cadastrar Hospede. \n");
        printf("2.Alterar Dados do Hospede. \n");
        printf("3.Visualizar Todos os Hospedes. \n");
        printf("4.Visualizar Hospede por código. \n");
        printf("5.Excluir Hospede. \n");
        printf("6.Voltar. \n");
        printf("Digite a opção desejada: \n");
        scanf("%d%*c", &opc);
        switch (opc) {
            case 1:
                cadastrarHospedesControl();
                break;
            case 2:
                atualizarHospedesControl();
                break;
            case 3:
                listarHospedesControl();
                break;
            case 4:;
                getHospedeByCodControl();
                break;
            case 5:
                deletarHospedesControl();
                break;
            case 6:
                sair = 1;
                subCadastros();
                break;
            default:
                printf("OPÇÃO INVÁLIDA!\n");

                break;
        }

    }
}

/*
 * FUNÇÃO: cadastrarHospedesControl 
 * 
 * Cadastra um hóspede, validando o código e verificando a extensão do arquivo 
 * 
 * PARÂMETROS: nenhum
 * 
 * RETORNO: Void
 */
void cadastrarHospedesControl() {
    printf("***** CADASTRAR HÓSPEDE *****\n");
    int cod;
    Hospede h;
    //pega a extensão do arquivo
    int ext = listar();

    //pega os dados
    printf("Digite o cod do hóspede \n");
    scanf("%d%*c", &cod);
    //valida para ver se o código já existe
    if (validarCodHospede(cod, ext) == 0) {
        return;
    } else {
        h.codigo = cod;
    }

    printf("Digite o nome do hóspede \n");
    //scanf("%[^\n]s%*c", &h.nome); 
    fgets(h.nome, 101, stdin);
    strtok(h.nome, "\n"); // Esse comando serve para retirar o \n que o fgets coloca no final da string lida

    printf("Digite o cpf do hóspede (apenas números) \n");
    fgets(h.cpf, 13, stdin); // tamanho 13 porque tem o \0 e o fgets adciona uma quebra de linha no final
    strtok(h.cpf, "\n");

    setbuf(stdin, NULL); // limpa o buffer

    printf("Digite o telefone do hóspede \n");
    fgets(h.telefone, 16, stdin);
    strtok(h.telefone, "\n");

    printf("Digite o email do hóspede \n");
    //scanf("%s%*c", &h.email);
    fgets(h.email, 102, stdin);
    strtok(h.email, "\n");
    printf("Digite o sexo do hóspede (M - masculino , F - Feminino) \n");
    scanf("%s%*c", &h.sexo);

    printf("Digite o estado civil do hóspede \n");
    //scanf("%s%*c", &h.esCivil);
    fgets(h.esCivil, 11, stdin);
    strtok(h.esCivil, "\n");

    printf("DATA DE NASCIMENTO DO HÓSPEDE\n");
    printf("Digite o Dia do nascimento do hóspede \n");
    scanf("%d%*c", &h.dataNascimento.dia);

    printf("Digite o Mês do nascimento do hóspede \n");
    scanf("%d%*c", &h.dataNascimento.mes);

    printf("Digite o Ano do nascimento do hóspede \n");
    scanf("%d%*c", &h.dataNascimento.ano);


    printf("ENDEREÇO DO HÓSPEDE\n");
    printf("Digite o Código do endereço \n");
    scanf("%d%*c", &h.endereco.codigo);

    setbuf(stdin, NULL); // limpa o buffer

    printf("Digite o CEP do endereço (Apenas números) \n");
    fgets(h.endereco.cep, 10, stdin);
    strtok(h.endereco.cep, "\n");

    setbuf(stdin, NULL); // limpa o buffer

    printf("Digite a UF do endereço \n");
    //scanf("%s%*c",&h.endereco.uf);
    fgets(h.endereco.uf, 4, stdin);
    strtok(h.endereco.uf, "\n");

    setbuf(stdin, NULL); // limpa o buffer

    printf("Digite a Cidade do endereço \n");
    fgets(h.endereco.cidade, 102, stdin);
    strtok(h.endereco.cidade, "\n");


    printf("Digite o Bairo do endereço \n");
    fgets(h.endereco.bairro, 102, stdin);
    strtok(h.endereco.bairro, "\n");


    printf("Digite o Logradouro do endereço \n");
    fgets(h.endereco.logradouro, 102, stdin);
    strtok(h.endereco.logradouro, "\n");


    printf("Digite o Número do endereço \n");
    scanf("%d%*c", &h.endereco.numero);


    //CADASTRA DE ACORDO COM A EXTENSÃO DO ARQUIVO
    int retorno = 0;
    if (ext == 2) {
        //BIN
        retorno = cadastrarHospedesBIN(h);
        printf("\nHOSPEDE CADASTRADO COM SUCESSO\n");
    }
    if (ext == 1) {
        //TXT
        retorno = cadastrarHospedesTXT(h);
    }

    if (retorno > 0) {
        printf("\nHOSPEDE CADASTRADO COM SUCESSO\n");
    } else {
        printf("ERRO AO CADASTRAR HOSPEDE\n");
    }
}

/*
 * FUNÇÃO: listarHospedesControl 
 * 
 * Mostra os dados completos de todos os hóspedes cadastrados
 * na extensão escolhida. 
 * 
 * PARÂMETROS: nenhum
 * 
 * RETORNO: Void
 */
void listarHospedesControl() {
    int numHospedes = 0; // o valor será atualizado, para poder mostrar todos os hóspedes;
    Hospede* arrayHospedes;
    printf("LISTA DE TODOS OS HÓSPEDES \n");

    //pega a extensão do arquivo
    int ext = listar();
    if (ext == 2) {
        //BIN
        arrayHospedes = getAllHospedesBIN(&numHospedes);
    }
    if (ext == 1) {
        //TXT
        numHospedes = getNumHospedes();
        arrayHospedes = getAllHospedesTXT(numHospedes);

    }

    //lista os hóspedes
    for (int i = 0; i < numHospedes; i++) {

        printf("***************\n");
        printf("COD: %d\n", arrayHospedes[i].codigo);
        printf("NOME: %s\n", arrayHospedes[i].nome);
        printf("CPF: %s\n", arrayHospedes[i].cpf);
        printf("FONE: %s\n", arrayHospedes[i].telefone);
        printf("EMAIL: %s\n", arrayHospedes[i].email);
        printf("SEXO: %c\n", arrayHospedes[i].sexo);
        printf("ESTADO CIVIL: %s\n", arrayHospedes[i].esCivil);
        //DATA
        printf("DATA NASC: %d / %d / %d \n", arrayHospedes[i].dataNascimento.dia, arrayHospedes[i].dataNascimento.mes, arrayHospedes[i].dataNascimento.ano);
        //ENDEREÇO
        printf("COD ENDER: %d\n", arrayHospedes[i].endereco.codigo);
        printf("BAIRRO: %s\n", arrayHospedes[i].endereco.bairro);
        printf("CEP: %s\n", arrayHospedes[i].endereco.cep);
        printf("CIDADE: %s\n", arrayHospedes[i].endereco.cidade);
        printf("LOGRADOURO: %s\n", arrayHospedes[i].endereco.logradouro);
        printf("NUMERO: %d\n", arrayHospedes[i].endereco.numero);
        printf("UF: %s\n", arrayHospedes[i].endereco.uf);
        printf("***************\n");
    }
    printf("\n FIM DA LISTA DE HÓSPEDES \n");
    //printf("NUMHOSPEDES: %d\n", numHospedes);

    //libera memória
    free(arrayHospedes);
}

/*
 * FUNÇÃO: getHospedeByCodControl 
 * 
 * Busca um Hóspede específico por código, na extensão escolhida
 * 
 * PARÂMETROS: nenhum
 * 
 * RETORNO: retorna o Hóspede, se encontrado, ou termina a função, se não encontrado
 */
Hospede getHospedeByCodControl() {
    Hospede hos;
    int cod;
    //pega a extensão do arquivo
    int ext = listar();
    printf("Digite o código do Hóspede que deseja procurar:\n");
    scanf("%d%*c", &cod);

    //valida se o cod digitado existe
    if (validarCodHospede(cod, ext) == 1) {
        printf("COD INEXISTENTE\n");
        return;
    } else {

        if (ext == 2) {
            //BIN
            hos = getHospedeByCodBIN(cod);
        }
        if (ext == 1) {
            //TXT
            //int numHospede = getNumHospedes();
            hos = getHospedeByCodTXT(cod);

        }
    }

    //EXIBE O HÓSPEDE ENCONTRADO
    printf("INFORMAÇÕES DO HÓSPEDE: \n");
    printf("***************\n");
    printf("COD: %d\n", hos.codigo);
    printf("NOME: %s\n", hos.nome);
    printf("CPF: %s\n", hos.cpf);
    printf("EMAIL: %s\n", hos.email);
    printf("SEXO: %c\n", hos.sexo);
    printf("ESCIVIL: %s\n", hos.esCivil);
    printf("TELEFONE: %s\n", hos.telefone);
    //DATA
    printf("DATA NASC: %d / %d / %d \n", hos.dataNascimento.dia, hos.dataNascimento.mes, hos.dataNascimento.ano);
    //ENDEREÇO
    printf("COD ENDER: %d\n", hos.endereco.codigo);
    printf("BAIRRO: %s\n", hos.endereco.bairro);
    printf("CEP: %s\n", hos.endereco.cep);
    printf("CIDADE: %s\n", hos.endereco.cidade);
    printf("LOGRADOURO: %s\n", hos.endereco.logradouro);
    printf("NUMERO: %d\n", hos.endereco.numero);
    printf("UF: %s\n", hos.endereco.uf);

    printf("***************\n");
    return hos;

}

/*
 * FUNÇÃO: atualizarHospedesControl 
 * 
 * Atualiza os dados de um Hóspede específico, na extensão escolhida.
 * 
 * PARÂMETROS: nenhum
 * 
 * RETORNO: void
 */
void atualizarHospedesControl() {
    printf("***** ALTERAR DADOS DO HÓSPEDE *****\n");

    int cod;
    //pega a extensão do arquivo
    int ext = listar();
    Hospede novoHosp;

    //pega o cod e valida para ver se o Hóspede existe
    printf("Digite o cod do hóspede \n");
    scanf("%d%*c", &cod);
    if (validarCodHospede(cod, ext) == 0) {
        //COD EXISTE
        novoHosp.codigo = cod;

        //pega os novos dados
        printf("Atualize o nome do hóspede \n");
        //scanf("%[^\n]s%*c", &h.nome); 
        fgets(novoHosp.nome, 101, stdin);
        strtok(novoHosp.nome, "\n"); // Esse comando serve para retirar o \n que o fgets coloca no final da string lida

        printf("Atualize o cpf do hóspede (apenas números) \n");
        fgets(novoHosp.cpf, 13, stdin); // tamanho 13 porque tem o \0 e o fgets adciona uma quebra de linha no final
        strtok(novoHosp.cpf, "\n");

        setbuf(stdin, NULL); // limpa o buffer

        printf("Atualize o telefone do hóspede \n");
        fgets(novoHosp.telefone, 16, stdin);
        strtok(novoHosp.telefone, "\n");

        printf("Atualize o email do hóspede \n");
        //scanf("%s%*c", &h.email);
        fgets(novoHosp.email, 102, stdin);
        strtok(novoHosp.email, "\n");
        printf("DAtualize o sexo do hóspede (M - masculino , F - Feminino) \n");
        scanf("%s%*c", &novoHosp.sexo);

        printf("Atualize o estado civil do hóspede \n");
        //scanf("%s%*c", &h.esCivil);
        fgets(novoHosp.esCivil, 11, stdin);
        strtok(novoHosp.esCivil, "\n");

        printf("DATA DE NASCIMENTO DO HÓSPEDE\n");
        printf("Atualize o Dia do nascimento do hóspede \n");
        scanf("%d%*c", &novoHosp.dataNascimento.dia);

        printf("Atualize o Mês do nascimento do hóspede \n");
        scanf("%d%*c", &novoHosp.dataNascimento.mes);

        printf("Atualize o Ano do nascimento do hóspede \n");
        scanf("%d%*c", &novoHosp.dataNascimento.ano);

        //printf("DATA = %d  -  %d  -  %d\n", h.dataNascimento.dia, h.dataNascimento.mes, h.dataNascimento.ano);

        printf("ENDEREÇO DO HÓSPEDE\n");
        printf("Atualize o Código do endereço \n");
        scanf("%d%*c", &novoHosp.endereco.codigo);

        setbuf(stdin, NULL); // limpa o buffer

        printf("Atualize o CEP do endereço (Apenas números) \n");
        fgets(novoHosp.endereco.cep, 10, stdin);
        strtok(novoHosp.endereco.cep, "\n");

        setbuf(stdin, NULL); // limpa o buffer

        printf("Atualize a UF do endereço \n");
        //scanf("%s%*c",&h.endereco.uf);
        fgets(novoHosp.endereco.uf, 4, stdin);
        strtok(novoHosp.endereco.uf, "\n");

        setbuf(stdin, NULL); // limpa o buffer

        printf("Atualize a Cidade do endereço \n");
        fgets(novoHosp.endereco.cidade, 102, stdin);
        strtok(novoHosp.endereco.cidade, "\n");


        printf("Atualize o Bairo do endereço \n");
        fgets(novoHosp.endereco.bairro, 102, stdin);
        strtok(novoHosp.endereco.bairro, "\n");


        printf("Atualize o Logradouro do endereço \n");
        fgets(novoHosp.endereco.logradouro, 102, stdin);
        strtok(novoHosp.endereco.logradouro, "\n");


        printf("Atualize o Número do endereço \n");
        scanf("%d%*c", &novoHosp.endereco.numero);


        printf("NOVOS DADOS\n");
        printf("***************\n");
        printf("COD: %d\n", novoHosp.codigo);
        printf("NOME: %s\n", novoHosp.nome);
        printf("CPF: %s\n", novoHosp.cpf);
        printf("FONE: %s\n", novoHosp.telefone);
        printf("EMAIL: %s\n", novoHosp.email);
        printf("SEXO: %c\n", novoHosp.sexo);
        printf("ESTADO CIVIL: %s\n", novoHosp.esCivil);
        //DATA
        printf("DATA NASC: %d / %d / %d \n", novoHosp.dataNascimento.dia, novoHosp.dataNascimento.mes, novoHosp.dataNascimento.ano);
        //ENDEREÇO
        printf("COD ENDER: %d\n", novoHosp.endereco.codigo);
        printf("BAIRRO: %s\n", novoHosp.endereco.bairro);
        printf("CEP: %s\n", novoHosp.endereco.cep);
        printf("CIDADE: %s\n", novoHosp.endereco.cidade);
        printf("LOGRADOURO: %s\n", novoHosp.endereco.logradouro);
        printf("NUMERO: %d\n", novoHosp.endereco.numero);
        printf("UF: %s\n", novoHosp.endereco.uf);
        printf("***************\n");

        //ATUALIZA DE ACORDO COM A EXTENSÃO DO ARQUIVO
        if (ext == 2) {
            //BIN
            atualizarHospedeBIN(novoHosp);
        }
        if (ext == 1) {
            //TXT
            atualizarHospedeTXT(novoHosp);
        }

        printf("ALTERAÇÃO CONCLUÍDA\n");

    } else {
        printf("CÓDIGO NÃO EXISTE\n");
    }
}

/*
 * FUNÇÃO: deletarHospedesControl 
 * 
 * Deleta um Hóspede específico, na extensão escolhida.
 * 
 * PARÂMETROS: nenhum
 * 
 * RETORNO: void
 */
void deletarHospedesControl() {
    printf("***** DELETAR HÓSPEDE *****\n");

    Hospede h;
    char confirmacao;
    int cod;
    //pega a extensão do arquivo
    int ext = listar();

    //pega o cod e valida para ver se o Hóspede existe
    printf("Digite o cod do hóspede \n");
    scanf("%d%*c", &cod);
    if (validarCodHospede(cod, ext) == 1) {

        printf("COD INEXISTENTE\n");
        return;
    } else {

        if (ext == 2) {
            h = getHospedeByCodBIN(cod);
        }
        if (ext == 1) {
            int numHospedes = getNumHospedes();
            h = getHospedeByCodTXT(cod);
        }


        printf("INFORMAÇÕES DO HÓSPEDE: \n");
        printf("***************\n");
        printf("COD: %d\n", h.codigo);
        printf("NOME: %s\n", h.nome);
        printf("CPF: %s\n", h.cpf);
        printf("FONE: %s\n", h.telefone);
        printf("EMAIL: %s\n", h.email);
        printf("SEXO: %c\n", h.sexo);
        printf("ESTADO CIVIL: %s\n", h.esCivil);
        //DATA
        printf("DATA NASC: %d / %d / %d \n", h.dataNascimento.dia, h.dataNascimento.mes, h.dataNascimento.ano);
        //ENDEREÇO
        printf("COD ENDER: %d\n", h.endereco.codigo);
        printf("BAIRRO: %s\n", h.endereco.bairro);
        printf("CEP: %s\n", h.endereco.cep);
        printf("CIDADE: %s\n", h.endereco.cidade);
        printf("LOGRADOURO: %s\n", h.endereco.logradouro);
        printf("NUMERO: %d\n", h.endereco.numero);
        printf("UF: %s\n", h.endereco.uf);
        printf("***************\n");

        printf("DESEJA REALMENTE DELETAR O HÓSPEDE? (S / N)\n");
        scanf("%c%*c", &confirmacao);

        if (confirmacao == 'S' || confirmacao == 's') {
            if (ext == 2) {
                //BIN
                deletarHospedeBIN(cod);
            }
            if (ext == 1) {
                //TXT
                deletarHospedeTXT(cod);
            }
        } else {
            printf("OPERAÇÃO CANCELADA \n");
            return;
        }
        printf("HÓSPEDE DELETADO\n");
    }

}

/*
 * FUNÇÃO: validarCodHospede 
 * 
 * Valida o código de um Hóspede, na extensão escolhida.
 * 
 * PARÂMETROS: 
 * 
 * cod - o código que será verificado
 * ext - a extensão do arquivo
 * 
 * RETORNO: retorna 1 se o cod não existe, ou 0, se já existe
 */
int validarCodHospede(int cod, int ext) {
    //printf("ENTROU VALIDAÇÃO\n");
    int codExistente = 1;
    Hospede* arrHospedes;
    int numHospedes = 0;
    //pega todos dos hospedes, de acordo com a extensão
    if (ext == 2) {
        //BIN
        arrHospedes = getAllHospedesBIN(&numHospedes);
    }
    if (ext == 1) {
        //TXT
        numHospedes = getNumHospedes();
        arrHospedes = getAllHospedesTXT(numHospedes);
    }

    //verifica se o cod existe
    int i;
    for (i = 0; i < numHospedes; i++) {
        if (cod == arrHospedes[i].codigo) {
            codExistente = 0;
            //printf("ACHOU COD HOSP : %d = %d\n",cod,arrHospedes[i].codigo);
        }
    }
    free(arrHospedes);
    if (codExistente == 0) {
        printf("CÓDIGO EXISTENTE\n");
        return 0;
    } else {
        return 1;
    }
}


