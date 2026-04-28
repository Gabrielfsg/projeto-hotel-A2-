/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"Data.h"
#include"Endereco.h"
#include"Hospede.h"
#include"HospedeMenu.h"

/*
 * FUNÇÃO: cadastrarHospedesTXT 
 * 
 * Cadastra um Hóspede, escrevendo seus dados na extensão TXT.
 * 
 * PARÂMETROS: 
 * 
 * h - Struct do Hóspede que será cadastrado
 * 
 * RETORNO: retorna o número de caracteres gravados, ou um número negativo em
 * caso de erro
 */
int cadastrarHospedesTXT(Hospede h) {
    FILE* arHospedes;
    //abre o arquivo de hospedes.txt
    arHospedes = fopen(".\\arquivos\\hospedes.txt", "a");
    if (arHospedes == NULL) {
        //se não existir, cria um novo.
        arHospedes = fopen(".\\arquivos\\hospedes.txt", "w");
        if (arHospedes == NULL) {
            printf("ERRO DE ABERTURA\n");
        }
    } else {
        //grava os dados do hóspede no arquivo
        int retorno = 0;
        retorno = fprintf(arHospedes, "Cod: %d\r\nNome: %s\r\nCPF: %s\r\nTelefone: %s\r\nEmail: %s\r\nSexo: %c\r\nEstadoCivil: %s\r\n", h.codigo, h.nome, h.cpf, h.telefone, h.email, h.sexo, h.esCivil);
        retorno += fprintf(arHospedes, "DiaNasc: %d\r\nMesNasc: %d\r\nAnoNasc: %d\r\n", h.dataNascimento.dia, h.dataNascimento.mes, h.dataNascimento.ano);
        retorno += fprintf(arHospedes, "CodEnder: %d\r\nBairro: %s\r\nCEP: %s\r\nCidade: %s\r\nLogradouro: %s\r\nNumero: %d\r\nUF: %s\r\n", h.endereco.codigo, h.endereco.bairro, h.endereco.cep, h.endereco.cidade, h.endereco.logradouro, h.endereco.numero, h.endereco.uf);

        fflush(arHospedes);
        fclose(arHospedes);
        return retorno;
    }
}

int salvarHospedeTXT(Hospede *hos, int num) {
  FILE *arq;
  // w para substituir o arquivo
  arq = fopen("arquivos\\hospedes.txt", "w");
  if (arq == NULL) {
    printf("\nErro ao abrir arquivo!!");
    return 0;
  } else {
    int i;
    // grava todos os dado do vetor no arquivo
    for (i = 0; i < num; i++) {
      fprintf(arq, "%d\r\n%s\r\n%s\r\n%s\r\n%s\r\n%c\r\n%s\r\n%d\r\n%d\r\n%d\r\n%s\r\n%d\r\n%s\r\n%s\r\n%s\r\n%s\r\n", hos[i].codigo, hos[i].nome, 
              hos[i].cpf, hos[i].telefone, hos[i].email, hos[i].sexo, hos[i].esCivil,
              hos[i].dataNascimento.dia, hos[i].dataNascimento.mes, hos[i].dataNascimento.ano,
              hos[i].endereco.logradouro, hos[i].endereco.numero, hos[i].endereco.bairro,
              hos[i].endereco.cidade, hos[i].endereco.cep, hos[i].endereco.uf);
    }
  }
  fflush(arq);
  fclose(arq);
  free(arq);
  free(hos);
  return 1;
}


/*
 * FUNÇÃO: cadastrarHospedesBIN 
 * 
 * Cadastra um Hóspede, escrevendo seus dados na extensçao BIN.
 * 
 * PARÂMETROS: 
 * 
 * h - Struct do Hóspede que será cadastrado
 * 
 * RETORNO: retorna o número de hospedes gravados
 */
int cadastrarHospedesBIN(Hospede h) {
    FILE* arqHospedes;
    //abre o arquivo de hospedes.bin
    arqHospedes = fopen(".\\arquivos\\hospedes.bin", "ab");
    if (arqHospedes == NULL) {
        //se não existir, cria um novo.
        arqHospedes = fopen(".\\arquivos\\hospedes.bin", "wb");
        if (arqHospedes == NULL) {
            printf("ERRO DE ABERTURA\n");
        }

    } else {
        int count = 0; //variavel para validar se gravou ou não
        //grava no arquivo binário
        count = fwrite(&h, sizeof (Hospede), 1, arqHospedes);
        fflush(arqHospedes);
        //fecha o arquivo
        fclose(arqHospedes);
        //libera mémoria
        free(arqHospedes);
        fclose(arqHospedes);
        return count;
    }
}

int cadastrarHospedeBIN(Hospede *hos, int quantidade) {
  FILE *arq;
  arq = fopen("arquivos\\hospedes.bin", "ab");
  if (arq == NULL) {
    arq = fopen("arquivos\\hospedes.bin", "wb");
    if (arq == NULL) {
      printf("\nERRO ao acessar arquivo\n");
      return 0;
    }        
  }
    /*grava toda struct de acomodacao no arquivo*/
    fwrite(hos, sizeof (Hospede), quantidade, arq);
    fflush(arq);
    /*fecha o arquivo*/
    fclose(arq);
    /*libera mémoria*/
    free(arq);
    return 1;
}

/*
 * FUNÇÃO: getAllHospedesTXT 
 * 
 * Pega todos os hóspedes cadastrados na extensão TXT.
 * 
 * PARÂMETROS: 
 * 
 * numHospedes - número total de Hóspedes do arquivo.
 * 
 * RETORNO: Retorna um Ponteiro (Array) de Hóspedes, contendo todos os hóspedes
 * do aquivo.
 * 
 * OBS: Onde getAllHospedesTXT for chamado, será preciso também ter o tamanho do
 * array (numHospedes) para percorrer em um for, por exemplo. Como esse valor 
 * é retornado de outra função, chamá-la aqui uma segunda vez seria redundante. 
 * Por isso, numHospedes é passado como parâmetro
 */
Hospede* getAllHospedesTXT(int numHospedes) {
    int index = 1; //ÍNDICE DO ARRAY

    Hospede *arrayHospedes = (Hospede *) malloc(sizeof (Hospede) * numHospedes); //Ponteiro de Hóspedes vira um Array ao chamar malloc
    if (arrayHospedes == NULL) {
        printf("ERRO DE ALOCAÇÃO");
        exit(EXIT_FAILURE);
    }

    FILE *scanHospedes;

    scanHospedes = fopen(".\\arquivos\\hospedes.txt", "r");
    if (scanHospedes == NULL) {
        printf("ERRO DE LEITURA, UM NOVO ARQUIVO SERÁ CRIADO\n");
        scanHospedes = fopen(".\\arquivos\\hospedes.txt", "w");
        if (scanHospedes == NULL) {
            printf("ERRO DE LEITURA\n");
            return;
        }


    } else {
        //pega os hóspedes do arquivo
        for (int i = 0; i < numHospedes; i++) {
            Hospede h;
            char text[20];

            //FSCANF para pegar os valores do aquivo. "text[20]" é apenas para armazenar a string que vem antes do valor.

            fscanf(scanHospedes, "%s %d", text, &h.codigo);
            fscanf(scanHospedes, "%s %[^\n]s", text, h.nome);
            strtok(h.nome, "\r\n");
            fscanf(scanHospedes, "%s %s", text, h.cpf);
            fscanf(scanHospedes, "%s %s", text, h.telefone);
            fscanf(scanHospedes, "%s %s", text, h.email);
            fscanf(scanHospedes, "%s %c", text, &h.sexo);
            fscanf(scanHospedes, "%s %s", text, h.esCivil);

            //DATA NASC
            fscanf(scanHospedes, "%s %d", text, &h.dataNascimento.dia);
            fscanf(scanHospedes, "%s %d", text, &h.dataNascimento.mes);
            fscanf(scanHospedes, "%s %d", text, &h.dataNascimento.ano);

            //ENDEREÇO
            fscanf(scanHospedes, "%s %d", text, &h.endereco.codigo);
            fscanf(scanHospedes, "%s %[^\n]s", text, h.endereco.bairro);
            strtok(h.endereco.bairro, "\r\n");
            fscanf(scanHospedes, "%s %s", text, h.endereco.cep);
            fscanf(scanHospedes, "%s %[^\n]s", text, h.endereco.cidade);
            strtok(h.endereco.cidade, "\r\n");
            fscanf(scanHospedes, "%s %[^\n]s", text, h.endereco.logradouro);
            strtok(h.endereco.logradouro, "\r\n");
            fscanf(scanHospedes, "%s %d", text, &h.endereco.numero);
            fscanf(scanHospedes, "%s %s", text, h.endereco.uf);

            //COLOCA O HOSPEDE NO ARRAY
            arrayHospedes[index - 1] = h;
            index++;
        }
        fclose(scanHospedes);

        /*printf("\n TESTE PARA VER TODOS OS ITENS DO ARRAY \n");
        for (int i = 0; i < index - 1; i++) {
            printf("+++++++++++\n");
            printf("POS: %d -> %d\n", i, arrayHospedes[i].codigo);
            printf("POS: %d -> %s\n", i, arrayHospedes[i].nome);
            printf("POS: %d -> %s\n", i, arrayHospedes[i].cpf);
            printf("POS: %d -> %s\n", i, arrayHospedes[i].telefone);
            printf("POS: %d -> %s\n", i, arrayHospedes[i].email);
            printf("POS: %d -> %c\n", i, arrayHospedes[i].sexo);
            printf("POS: %d -> %s\n", i, arrayHospedes[i].esCivil);
            //DATA
            printf("POS: %d -> %d\n", i, arrayHospedes[i].dataNascimento.dia);
            printf("POS: %d -> %d\n", i, arrayHospedes[i].dataNascimento.mes);
            printf("POS: %d -> %d\n", i, arrayHospedes[i].dataNascimento.ano);
            //ENDER
            printf("POS: %d -> %d\n", i, arrayHospedes[i].endereco.codigo);
            printf("POS: %d -> %s\n", i, arrayHospedes[i].endereco.bairro);
            printf("POS: %d -> %s\n", i, arrayHospedes[i].endereco.cep);
            printf("POS: %d -> %s\n", i, arrayHospedes[i].endereco.cidade);
            printf("POS: %d -> %s\n", i, arrayHospedes[i].endereco.logradouro);
            printf("POS: %d -> %d\n", i, arrayHospedes[i].endereco.numero);
            printf("POS: %d -> %s\n", i, arrayHospedes[i].endereco.uf);
            printf("+++++++++++\n");
        }*/
        return arrayHospedes;
    }
}

/*
 * FUNÇÃO: getAllHospedesBIN 
 * 
 * Pega todos os hóspedes cadastrados na extensão BIN.
 * 
 * PARÂMETROS: 
 * 
 * numHospedes - Ponteiro que contém o endereço de memória da variável
 * que armazena o número total de hóspedes do arquivo
 * 
 * RETORNO: Retorna um Ponteiro (Array) de Hóspedes, contendo todos os hóspedes
 * do aquivo.
 * 
 * OBS: Neste caso, *numHospedes deve ser iniciado em 0, pois este método irá
 * incrementá-lo em 1 cada vez que ler um hóspede, retornando, no fim, o número
 * total de hóspedes do arquivo.
 */
Hospede* getAllHospedesBIN(int* numHospedes) {
    int index = 0; //ÍNDICE DO ARRAY
    Hospede *arrayHospedes = (Hospede *) malloc(sizeof (Hospede) * 1); //Ponteiro de Hóspedes vira um Array ao chamar malloc
    if (arrayHospedes == NULL) {
        printf("ERRO DE ALOCAÇÃO");
        exit(EXIT_FAILURE);
    }

    FILE *fileHospedes;

    fileHospedes = fopen(".\\arquivos\\hospedes.bin", "rb");
    if (fileHospedes == NULL) {
        fileHospedes = fopen(".\\arquivos\\hospedes.bin", "wb");
        if (fileHospedes == NULL) {
            printf("ERRO DE LEITURA");
        }
    } else {

        while (!feof(fileHospedes)) { //enquanto não for o final do arquivo
            Hospede h;
            //TENTA LER UM HÓSPEDE
            int conseguiuLer = fread(&h, sizeof (Hospede), 1, fileHospedes);
            if (conseguiuLer == 1) {
                //printf("LEU UM HOSPEDE\n");
                (*numHospedes)++;
                arrayHospedes[index] = h;
                index++;
                arrayHospedes = realloc(arrayHospedes, (index + 1) * sizeof (Hospede));
                //printf("INDEX = %d\n", index);
            } 

        }

        fclose(fileHospedes);
        //printf("TOTAL LIDO = %d\n",*numHospedes);

        /*printf("\n TESTE PARA VER TODOS OS ITENS DO ARRAY \n");
        for (int i = 0; i < 3; i++) {
            printf("+++++++++++\n");
            printf("POS: %d -> %d\n", i, arrayHospedes[i].codigo);
            printf("POS: %d -> %s\n", i, arrayHospedes[i].nome);
            printf("POS: %d -> %s\n", i, arrayHospedes[i].cpf);
            printf("POS: %d -> %s\n", i, arrayHospedes[i].telefone);
            printf("POS: %d -> %s\n", i, arrayHospedes[i].email);
            printf("POS: %d -> %c\n", i, arrayHospedes[i].sexo);
            printf("POS: %d -> %s\n", i, arrayHospedes[i].esCivil);
            printf("+++++++++++\n");
        }*/
        return arrayHospedes;
    }
}

/*
 * FUNÇÃO: getHospedeByCodTXT 
 * 
 * Pega um hóspede específico cadastrado na extensão TXT.
 * 
 * PARÂMETROS: 
 * 
 * cod - código do Hóspede que será retornado
 * 
 * RETORNO: Retorna o hóspede encontrado, ou termina a função, se não encontrado.
 * 
 * 
 */
Hospede getHospedeByCodTXT(int cod) {
    //printf("ENTROU GET HOSPEDE BY COD TXT");
    int numHospedes = getNumHospedes();
    if (validarCodHospede(cod, 1) == 0) {
        //se o cod existe
        Hospede* arrHospedes = getAllHospedesTXT(numHospedes);
        for (int i = 0; i < numHospedes; i++) {
            if (arrHospedes[i].codigo == cod) {
                //printf("\nACHOU O COD == AO QUE DIGITOU: %d == %s\n",cod,arrHospedes[i].nome);
                return arrHospedes[i];
            }
        }
    } else {
        //se não existe
        printf("NÃO EXISTE HOSPEDE CADASTRADO COM ESSE CODIGO\n");
        return;
    }

}

/*
 * FUNÇÃO: getHospedeByCodBIN 
 * 
 * Pega um hóspedes específico cadastrados na extensão BIN.
 * 
 * PARÂMETROS: 
 * 
 * cod - código do Hóspede que será retornado
 * 
 * 
 * RETORNO: Retorna o hóspede encontrado, ou termina a função, se não encontrado.
 * 
 * 
 */
Hospede getHospedeByCodBIN(int cod) {
    //printf("ENTROU GET HOSPEDE BY COD BIN");
    Hospede h;
    int numHospedes = 0;
    if (validarCodHospede(cod, 2) == 0) {
        //se o cod existe
        Hospede* arrayHospedes = getAllHospedesBIN(&numHospedes);
        //printf("NUM HOSPEDES = %d\n", numHospedes);
        for (int i = 0; i < numHospedes; i++) {
            if (arrayHospedes[i].codigo == cod) {
                //printf("HÓSPEDE ENCONTRADO!!\n");
                //printf("COD %d == %d\n", arrayHospedes[i].codigo, cod);
                h = arrayHospedes[i];
                return h;
            }
        }
    } else {
        //se não existe
        printf("NÃO EXISTE HOSPEDE CADASTRADO COM ESSE CODIGO\n");
        return;
    }


}

/*
 * FUNÇÃO: atualizarHospedeTXT 
 * 
 * Atualiza um Hóspede cadastrado no arquivo TXT.
 * Este método copia todos os hóspedes cadastrados para um arquivo temporário,
 * e quando encontrar o cod do hospede que será alterado, ele grava os dados 
 * novos desse hóspede.
 * 
 * PARÂMETROS: 
 * 
 * novoHosp - Struct com os novos dados do Hóspede que será alterado.
 * 
 * RETORNO: void
 * 
 * OBS: No processo de atualização, o cod do Hóspede não é alterado.
 * 
 */
void atualizarHospedeTXT(Hospede novoHosp) {
    //abre para escrita um arquivo temporário
    FILE* hosp = fopen(".\\arquivos\\hospedes_temp.txt", "w");
    if (hosp == NULL) {
        printf("ERRO AO ABRIR ARQUIVO");
    } else {
        //pega todos os hóspedes do TXT
        int numHospedes = getNumHospedes();
        Hospede* arrHosp = getAllHospedesTXT(numHospedes);

        //para cada hóspede, verifica se o cod é igual ou não do cod do novo Hóspede.
        for (int i = 0; i < numHospedes; i++) {
            if (arrHosp[i].codigo != novoHosp.codigo) {
                //printf("%d != %d\n", arrHosp[i].codigo, novoHosp.codigo);
                //se é diferente, copia os mesmos dados
                strtok(arrHosp[i].nome, "\r");
                strtok(arrHosp[i].endereco.bairro, "\r");
                strtok(arrHosp[i].endereco.cidade, "\r");
                strtok(arrHosp[i].endereco.logradouro, "\r");
                fprintf(hosp, "Cod: %d\r\nNome: %s\r\nCPF: %s\r\nTelefone: %s\r\nEmail: %s\r\nSexo: %c\r\nEstadoCivil: %s\r\n", arrHosp[i].codigo, arrHosp[i].nome, arrHosp[i].cpf, arrHosp[i].telefone, arrHosp[i].email, arrHosp[i].sexo, arrHosp[i].esCivil);
                fprintf(hosp, "DiaNasc: %d\r\nMesNasc: %d\r\nAnoNasc: %d\r\n", arrHosp[i].dataNascimento.dia, arrHosp[i].dataNascimento.mes, arrHosp[i].dataNascimento.ano);
                fprintf(hosp, "CodEnder: %d\r\nBairro: %s\r\nCEP: %s\r\nCidade: %s\r\nLogradouro: %s\r\nNumero: %d\r\nUF: %s\r\n", arrHosp[i].endereco.codigo, arrHosp[i].endereco.bairro, arrHosp[i].endereco.cep, arrHosp[i].endereco.cidade, arrHosp[i].endereco.logradouro, arrHosp[i].endereco.numero, arrHosp[i].endereco.uf);
                fflush(hosp);

            } else {
                //printf("ESSE É O QUE VAI ALTERAR: COD = %d\n", novoHosp.codigo);
                //se achou o que vai alterar, copia os novos dados.
                strtok(novoHosp.nome, "\r");
                strtok(novoHosp.endereco.bairro, "\r");
                strtok(novoHosp.endereco.cidade, "\r");
                strtok(novoHosp.endereco.logradouro, "\r");
                fprintf(hosp, "Cod: %d\r\nNome: %s\r\nCPF: %s\r\nTelefone: %s\r\nEmail: %s\r\nSexo: %c\r\nEstadoCivil: %s\r\n", novoHosp.codigo, novoHosp.nome, novoHosp.cpf, novoHosp.telefone, novoHosp.email, novoHosp.sexo, novoHosp.esCivil);
                fprintf(hosp, "DiaNasc: %d\r\nMesNasc: %d\r\nAnoNasc: %d\r\n", novoHosp.dataNascimento.dia, novoHosp.dataNascimento.mes, novoHosp.dataNascimento.ano);
                fprintf(hosp, "CodEnder: %d\r\nBairro: %s\r\nCEP: %s\r\nCidade: %s\r\nLogradouro: %s\r\nNumero: %d\r\nUF: %s\r\n", novoHosp.endereco.codigo, novoHosp.endereco.bairro, novoHosp.endereco.cep, novoHosp.endereco.cidade, novoHosp.endereco.logradouro, novoHosp.endereco.numero, novoHosp.endereco.uf);
                fflush(hosp);
            }
        }

        fclose(hosp);
        free(arrHosp);
        /*
        remove o arquivo antigo e renomeia o arquivo temporário, que agora será 
        o arquivo atualizado
         */
        remove(".\\arquivos\\hospedes.txt");
        rename(".\\arquivos\\hospedes_temp.txt", ".\\arquivos\\hospedes.txt");
    }

}

/*
 * FUNÇÃO: atualizarHospedeBIN 
 * 
 * Atualiza um Hóspede cadastrado no arquivo BIN.
 * Este método copia todos os hóspedes cadastrados para um arquivo temporário,
 * e quando encontrar o codigo do hospede que será alterado, ele grava os dados 
 * novos desse hóspede.
 * 
 * PARÂMETROS: 
 * 
 * novoHosp - Struct com os novos dados do Hóspede que será alterado.
 * 
 * RETORNO: void
 * 
 * OBS: No processo de atualização, o cod do Hóspede não é alterado.
 */
void atualizarHospedeBIN(Hospede novoHosp) {
    FILE* hosp = fopen(".\\arquivos\\hospedes_temp.bin", "wb");
    if (hosp == NULL) {
        printf("ERRO AO ABRIR ARQUIVO");
    } else {
        //pega todos os hóspedes do BIN
        int numHospedes = 0;
        Hospede* arrHosp = getAllHospedesBIN(&numHospedes);
        //para cada hóspede, verifica se o cod é igual ou não do cod do novo Hóspede.
        for (int i = 0; i < numHospedes; i++) {
            if (arrHosp[i].codigo != novoHosp.codigo) {
                //printf("ESSE É O QUE NAO VAI ALTERAR %d != %d\n", arrHosp[i].codigo, novoHosp.codigo);
                //se é diferente, copia os mesmos dados
                fwrite(&arrHosp[i], sizeof (Hospede), 1, hosp);
                fflush(hosp);

            } else {
                //printf("ESSE É O QUE VAI ALTERAR: COD = %d\n", novoHosp.codigo);
                //se achou o que vai alterar, copia os novos dados.
                fwrite(&novoHosp, sizeof (Hospede), 1, hosp);
                fflush(hosp);
            }
        }

        fclose(hosp);
        free(arrHosp);
        /*
        remove o arquivo antigo e renomeia o arquivo temporário, que agora será 
        o arquivo atualizado
         */
        remove(".\\arquivos\\hospedes.bin");
        rename(".\\arquivos\\hospedes_temp.bin", ".\\arquivos\\hospedes.bin");
    }

}

/*
 * FUNÇÃO: deletarHospedeTXT 
 * 
 * Deleta um Hóspede específico no arquivo TXT.
 * Este método copia todos os hóspedes cadastrados para um arquivo temporário,
 * exceto o hóspede que será deletado.
 * PARÂMETROS: 
 * 
 * cod - código do hóspede que será deletado.
 * 
 * RETORNO: void
 */
void deletarHospedeTXT(int cod) {

    FILE* hosp = fopen(".\\arquivos\\hospedes_temp.txt", "w");
    if (hosp == NULL) {
        printf("ERRO");
    } else {
        //pega todos os hóspedes
        int numHospedes = getNumHospedes();
        Hospede* arrHosp = getAllHospedesTXT(numHospedes);

        for (int i = 0; i < numHospedes; i++) {
            //copia os dados dos hóspedes que não serão deletados
            if (arrHosp[i].codigo != cod) {

                strtok(arrHosp[i].nome, "\r");
                strtok(arrHosp[i].endereco.bairro, "\r");
                strtok(arrHosp[i].endereco.cidade, "\r");
                strtok(arrHosp[i].endereco.logradouro, "\r");
                fprintf(hosp, "Cod: %d\r\nNome: %s\r\nCPF: %s\r\nTelefone: %s\r\nEmail: %s\r\nSexo: %c\r\nEstadoCivil: %s\r\n", arrHosp[i].codigo, arrHosp[i].nome, arrHosp[i].cpf, arrHosp[i].telefone, arrHosp[i].email, arrHosp[i].sexo, arrHosp[i].esCivil);
                fprintf(hosp, "DiaNasc: %d\r\nMesNasc: %d\r\nAnoNasc: %d\r\n", arrHosp[i].dataNascimento.dia, arrHosp[i].dataNascimento.mes, arrHosp[i].dataNascimento.ano);
                fprintf(hosp, "CodEnder: %d\r\nBairro: %s\r\nCEP: %s\r\nCidade: %s\r\nLogradouro: %s\r\nNumero: %d\r\nUF: %s\r\n", arrHosp[i].endereco.codigo, arrHosp[i].endereco.bairro, arrHosp[i].endereco.cep, arrHosp[i].endereco.cidade, arrHosp[i].endereco.logradouro, arrHosp[i].endereco.numero, arrHosp[i].endereco.uf);
                fflush(hosp);

            }
        }

        fclose(hosp);
        free(arrHosp);
        /*
        remove o arquivo antigo e renomeia o arquivo temporário, que agora será 
        o arquivo atualizado
         */
        remove(".\\arquivos\\hospedes.txt");
        rename(".\\arquivos\\hospedes_temp.txt", ".\\arquivos\\hospedes.txt");
    }
}

/*
 * FUNÇÃO: deletarHospedeBIN 
 * 
 * Deleta um Hóspede específico no arquivo BIN.
 * Este método copia todos os hóspedes cadastrados para um arquivo temporário,
 * exceto o hóspede que será deletado.
 * PARÂMETROS: 
 * 
 * cod - código do hóspede que será deletado.
 * 
 * RETORNO: void
 */
void deletarHospedeBIN(int cod) {

    FILE* hosp = fopen(".\\arquivos\\hospedes_temp.bin", "wb");
    if (hosp == NULL) {
        printf("ERRO");
    } else {
        //pega todos os hóspedes
        int numHospedes = 0;
        Hospede* arrHosp = getAllHospedesBIN(&numHospedes);

        for (int i = 0; i < numHospedes; i++) {
            //copia os dados dos hóspedes que não serão deletados
            if (arrHosp[i].codigo != cod) {
                Hospede h = arrHosp[i];
                //printf("NÃO VAI DELETAR: COD %d == %d\n",arrHosp[i].codigo,h.codigo);
                fwrite(&h, sizeof (Hospede), 1, hosp);

            } /*else {
                Hospede h2 = arrHosp[i];
                printf("É ESSE AQUI QUE VAI DELETAR: COD %d == %d\n",arrHosp[i].codigo,h2.codigo);
            }*/

        }

        fclose(hosp);
        free(arrHosp);
        /*
        remove o arquivo antigo e renomeia o arquivo temporário, que agora será 
        o arquivo atualizado
         */
        remove(".\\arquivos\\hospedes.bin");
        rename(".\\arquivos\\hospedes_temp.bin", ".\\arquivos\\hospedes.bin");
    }
}

/*
 * FUNÇÃO: getNumHospedes 
 * 
 * Calcula o número de hóspedes cadastrados no arquivo TXT com base no número
 * de linhas do arquivo
 * 
 * PARÂMETROS: nenhum
 * 
 * RETORNO: Retorna o número de Hóspedes 
 * 
 * OBS: ESTE MÉTODO É SOMENTE USADO PARA A EXTENSÃO TXT
 */
int getNumHospedes() {


    FILE *arq;
    int numLinhas = 0, numHospedes = 0;
    char c;
    //tenta abrir o arquivo, se não conseguir cria um novo.
    arq = fopen(".\\arquivos\\hospedes.txt", "r");
    if (arq == NULL) {
        arq = fopen(".\\arquivos\\hospedes.txt", "w");
        if (arq == NULL) {
            printf("ERRO AO ACESSAR ARQUIVO");
        }
        return 0;
    }
    //enquando nao for o fim do arquivo...
    while ((c = fgetc(arq)) != EOF) {
        //procura pelo caracter de quebra de linha.
        if (c == '\n') {
            numLinhas++;
        }
    }

    numHospedes = numLinhas / 17; // um hóspede gasta 17 linhas no arquivo

    //printf("O NÚMERO DE LINHAS DO ARQ É: %d\n", numLinhas);
    //printf("O NÚMERO DE HOSPEDES CADASTRADOS É: %d\n", numHospedes);
    fclose(arq);
    free(arq);
    return numHospedes;

}
