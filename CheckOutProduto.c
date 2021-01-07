/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "CheckOut.h"
#include "Produto.h"
#include "Data.h"
typedef struct checkOut_produto{
    CheckOut *checkOut;
    Produto *produto;
    int qunatidade;
    Data *data;
}CheckOutProduto;