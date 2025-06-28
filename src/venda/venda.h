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
    int id;
    int id_cliente;
    char data[11];              // data dia mes e ano
    ItemVenda itens[MAX_ITENS_VENDA];
    int num_itens;
    float total;
} Venda;

void inserir_venda();
void listar_vendas();
void atualizar_venda(int id);
void remover_venda(int id);

#endif
