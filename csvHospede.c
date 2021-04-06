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
#include"csvHospede.h"



void gerarCSVHospede(Hospede* arrayFiltrado, int *qte, int filtro) {
    printf("ENTROU GERAR CSV\n");
    printf("COD = %d\n",arrayFiltrado[1].codigo);
    printf("QTE = %d\n",*qte);
    FILE* arHospedes;
    char path[100];
    //ABRE O ARQUIVO CORRESPONDENTE AO FILTRO
    
    if(filtro == 1){
        arHospedes = fopen(".\\relatorios\\Hospedes_Faixa_Cod.txt", "w");
        
    }else{
        if(filtro == 2){
        arHospedes = fopen(".\\relatorios\\Hospedes_Sexo.txt", "w");    
        }
    }
          
    for(int i =0; i<(*qte);i++){
        printf("DENTRO DO FOR\n");
/*
       
        fprintf(arHospedes, "%d,%s,%s,%s,%s,%c,%d,%d,%d,%d,%s,%s,%s,%s,%d,%s", arrayFiltrado[i].codigo, arrayFiltrado[i].nome, arrayFiltrado[i].cpf, arrayFiltrado[i].telefone, arrayFiltrado[i].email, arrayFiltrado[i].sexo, arrayFiltrado[i].esCivil
                , arrayFiltrado[i].dataNascimento.dia, arrayFiltrado[i].dataNascimento.mes, arrayFiltrado[i].dataNascimento.ano
                , arrayFiltrado[i].endereco.codigo, arrayFiltrado[i].endereco.bairro,arrayFiltrado[i].endereco.cep,arrayFiltrado[i].endereco.cidade,
                arrayFiltrado[i].endereco.logradouro,arrayFiltrado[i].endereco.numero,arrayFiltrado[i].endereco.uf);
        fprintf(arHospedes, "\n");
    
    
*/
        fprintf(arHospedes, "%d,%s,%s,%s,%s,%c,%s,%d,%d,%d,%d,%s,%s,%s,%s,%d,%s",arrayFiltrado[i].codigo,arrayFiltrado[i].nome,arrayFiltrado[i].cpf, arrayFiltrado[i].telefone,arrayFiltrado[i].email,arrayFiltrado[i].sexo,arrayFiltrado[i].esCivil,arrayFiltrado[i].dataNascimento.dia,arrayFiltrado[i].dataNascimento.mes,arrayFiltrado[i].dataNascimento.ano,arrayFiltrado[i].endereco.codigo,arrayFiltrado[i].endereco.bairro,arrayFiltrado[i].endereco.cep,arrayFiltrado[i].endereco.cidade,arrayFiltrado[i].endereco.logradouro,arrayFiltrado[i].endereco.numero,arrayFiltrado[i].endereco.uf);
        fprintf(arHospedes, "\n");
    }
    exit(1);
        //retorno += fprintf(arHospedes, "DiaNasc: %d\r\nMesNasc: %d\r\nAnoNasc: %d\r\n", h.dataNascimento.dia, h.dataNascimento.mes, h.dataNascimento.ano);
        //retorno += fprintf(arHospedes, "CodEnder: %d\r\nBairro: %s\r\nCEP: %s\r\nCidade: %s\r\nLogradouro: %s\r\nNumero: %d\r\nUF: %s\r\n", h.endereco.codigo, h.endereco.bairro, h.endereco.cep, h.endereco.cidade, h.endereco.logradouro, h.endereco.numero, h.endereco.uf);

        fflush(arHospedes);
        fclose(arHospedes);

    
}