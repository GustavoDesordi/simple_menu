#ifndef PRODUTO_H
#define PRODUTO_H

#define MAX_PRODUTOS 100

typedef struct {
    int id;
    char nome[100];
    float preco;
    int estoque;
} Produto;

void inserir_produto();
void listar_produtos();
void atualizar_produto(int id);
void remover_produto(int id);

#endif
