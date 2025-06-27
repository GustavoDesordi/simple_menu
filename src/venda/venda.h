#ifndef VENDA_H
#define VENDA_H

#include "../cliente/cliente.h"
#include "../produto/produto.h"

#define MAX_ITENS_VENDA 10
#define MAX_VENDAS 100

typedef struct {
    int id_produto;
    int quantidade;
    float valor_unitario;
} ItemVenda;

typedef struct {
    int id;                     // ID da venda
    int id_cliente;             // ID do cliente comprador
    char data[11];              // DD/MM/AAAA, coloquei pra bunitu
    ItemVenda itens[MAX_ITENS_VENDA];
    int num_itens;
    float total;                // calculado automaticamente
} Venda;

void inserir_venda();
void listar_vendas();
void atualizar_venda(int id);
void remover_venda(int id);

#endif
