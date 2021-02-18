/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "Data.h"

Data* newData(int dia, int mes, int ano) {
    Data* d = (Data*) calloc(1, sizeof (Data));
    if (d == NULL) {
        printf("Memória insuficiente!\n");
        exit(1);
    }
    int bi = anoBissexto(d);
    if (mes >= 1 && mes <= 12) {
        d->mes = mes;
        if (mes == 2) {
            if (bi == 1) {
                if (dia >= 1 && dia <= 29) {
                    d->dia = dia;
                } else {
                    printf("Valor inválido para o campo dia, no ano bissexto!\n");
                    exit(1);
                }
            } else {
                if (dia >= 1 && dia <= 28) {
                    d->dia = dia;
                } else {
                    printf("Valor inválido para o campo dia!\n");
                    exit(1);
                }
            }
        } else if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
            if (dia >= 1 && dia <= 31) {
                d->dia = dia;
            } else {
                printf("Valor inválido para o campo dia!\n");
                exit(1);
            }
        } else {
            if (dia >= 1 && dia <= 30) {
                d->dia = dia;

            } else {
                printf("Valor inválido para o campo dia!\n");
                exit(1);
            }
        }

    } else {
        printf("Valor inválido para o campo mês!\n");
        exit(1);
    }
    if (ano > 0) {
        d->ano = ano;
    } else {
        printf("Valor inválido para o campo ano!\n");
        exit(1);
    }
}

int anoBissexto(Data *data) {
    //retorna 1 se o ano é issexto
    if (data->ano % 4 == 0) {
        return 1;
    } else {
        // retorn 0 para ano não issexto   
        return 0;
    }


}

void somaDias(Data *data, int dias) {
    int soma = dias + (data->dia);
    printf("data %d ", data->dia);
    for (; dias != 0;) {
        if (data->mes == 1 || data->mes == 3 || data->mes == 5 || data->mes == 7 || data->mes == 8 || data->mes == 10 || data->mes == 12) {
            if (data->dia < 31) {
                (data->dia)++;
                dias--;
            } else {
                data->dia = 1;
                if (data->mes < 11) {
                    dias--;
                    (data->mes)++;
                } else {
                    dias--;
                    (data->ano)++;
                    data->mes = 1;
                }
            }
        } else if (data->mes == 4 || data->mes == 6 || data->mes == 9 || data->mes == 11) {
            if (data->dia < 30) {
                (data->dia)++;
                dias--;
            } else {
                dias--;
                data->dia = 1;
                (data->mes)++;
            }
        } else if (data->mes == 2) {
            if (anoBissexto(data) == 1) {
                if (data->dia < 29) {
                    (data->dia)++;
                    dias--;
                } else {
                    dias--;
                    data->dia = 1;
                    (data->mes)++;
                }
            } else {
                if (data->dia < 28) {
                    (data->dia)++;
                    dias--;
                } else {
                    dias--;
                    data->dia = 1;
                    (data->mes)++;
                }
            }
        }

    }
    if (data->ano % 4 == 0 && soma < 365) {
        if (data->mes > 2) {

        } else {

        }
    } else if (data->ano % 4 != 0 && soma < 366) {

    }
}

void printaDataEx(Data *data) {
    printf("Data é : %d  de", data->dia);
    switch (data->mes) {
        case 1:
            printf(" Janeiro de");
            break;
        case 2:
            printf(" Fevereiro de");
            break;
        case 3:
            printf(" Março de");
            break;
        case 4:
            printf(" Abril de");
            break;
        case 5:
            printf(" Maio de");
            break;
        case 6:
            printf(" Junho de");
            break;
        case 7:
            printf(" Julho de");
            break;
        case 8:
            printf(" Agosto de");
            break;
        case 9:
            printf(" Setemro de");
            break;
        case 10:
            printf(" Outubro de");
            break;
        case 11:
            printf(" Novembro de");
            break;
        case 12:
            printf(" Dezembro de");
            break;
    }
    printf(" de %d ", data->ano);
}

void liberaMemoriaData(Data *data) {
    data->dia = 0;
    data->mes = 0;
    data->ano = 0;
    free(data);
}

int compararDatas(Data in1, Data fin1) {
    if (in1.dia == fin1.dia) {
        if (in1.mes == fin1.mes) {
            if (in1.ano == fin1.ano) {
                return 1;
            }
        }
    }
    return 0;
}

int data1maiordata2(Data data1, Data data2) {
    if (data1.ano >= data2.ano) {
        if (data1.mes >= data2.mes) {
            if (data1.dia > data2.dia) {
                return 1;
            } else if (data1.dia == data2.dia) {
                return 0;
            } else {
                return 0;
            }
        }
    }
    return 0;
}

int dataDisponivel(Data in1, Data fin1, Data in2, Data fin2) {
    //in2, fin2 - da reserva que ele ta analisando
    //in1 fim1 - datas que ele digitou
    
    //se a data digitada está no meio de uma reserva
    //ex Reserva do dia 1/1 até 5/1, ele digitou 2/1 até 4/1 -> a data está no meio da reserva
    
    if((in1.dia > in2.dia &&  in1.dia < fin2.dia) && (fin1.dia > in2.dia &&  fin1.dia < fin2.dia) ){
        //printf("\n\n A data está no meio da reserva\n");
        return 0;
    }
    
    if(in2.mes<fin2.mes){//o mesmo if de cima, mas adaptado para pegar datas entre meses
        if((in1.dia> fin1.dia) &&(in1.dia > in2.dia)){
            if(fin1.dia < fin2.dia){
                //printf("\n\n A DATA ESTÁ ENTRE MESES\n");
                return 0;
            }
            //se o dia inicial que ele digitou é maior que o dia final que ele digitou
            //se o dia inicial que ele digitou é maior que o dia inical da reserva
        }
    }
    
    Data aux = in1;
    for (; data1maiordata2(aux, fin1) == 0;) {
        if (compararDatas(aux, in2) == 1) {
            return 0;
            break;
        } else if (compararDatas(aux, fin2) == 1) {
            return 0;
            break;
        }
        somaDias(&aux, 1);
    }
    return 1;

}
