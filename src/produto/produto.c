#include <stdio.h>
#include <string.h>
#include "produto.h"

Produto produtos[MAX_PRODUTOS];
int ultimo_id_produto = 0;

void inserir_produto() {
    if (ultimo_id_produto >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido!\n");
        return;
    }

    Produto novo;
    novo.id = ultimo_id_produto + 1;
    printf("Nome: ");
    scanf(" %[^\n]", novo.nome);
    printf("Preço: ");
    scanf("%f", &novo.preco);
    printf("Estoque: ");
    scanf("%d", &novo.estoque);

    produtos[ultimo_id_produto] = novo;
    ultimo_id_produto++;

    printf("Produto inserido com sucesso!\n");
}

void listar_produtos() {
    printf("\n--- Lista de Produtos ---\n");
    for (int i = 0; i < ultimo_id_produto; i++) {
        if (produtos[i].id != -1) {
            printf("ID: %d | Nome: %s | Preço: R$ %.2f | Estoque: %d\n",
                produtos[i].id,
                produtos[i].nome,
                produtos[i].preco,
                produtos[i].estoque);
        }
    }
}

void atualizar_produto(int id) {
    for (int i = 0; i < ultimo_id_produto; i++) {
        if (produtos[i].id == id) {
            printf("Novo nome: ");
            scanf(" %[^\n]", produtos[i].nome);
            printf("Novo preço: ");
            scanf("%f", &produtos[i].preco);
            printf("Novo estoque: ");
            scanf("%d", &produtos[i].estoque);
            printf("Produto atualizado!\n");
            return;
        }
    }
    printf("Produto com ID %d não encontrado.\n", id);
}

void remover_produto(int id) {
    for (int i = 0; i < ultimo_id_produto; i++) {
        if (produtos[i].id == id) {
            produtos[i].id = -1;
            printf("Produto removido!\n");
            return;
        }
    }
    printf("Produto com ID %d não encontrado.\n", id);
}
