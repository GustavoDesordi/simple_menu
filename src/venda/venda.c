#include <stdio.h>
#include <string.h>
#include <time.h>
#include "venda.h"

Venda vendas[MAX_VENDAS];
int ultimo_id_venda = 0;

void inserir_venda() {
    if (ultimo_id_venda >= MAX_VENDAS) {
        printf("Limite de vendas atingido!\n");
        return;
    }

    Venda v;
    v.id = ++ultimo_id_venda;
    // lê o cliente
    printf("ID do cliente: ");
    scanf("%d", &v.id_cliente);

    // preenche a data atual, so pra fica bnt
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(v.data, "%02d/%02d/%04d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);

    // lê os itens
    v.num_itens = 0;
    v.total = 0.0f;
    char more;
    do {
        if (v.num_itens >= MAX_ITENS_VENDA) {
            printf("Limite de itens na venda atingido!\n");
            break;
        }
        ItemVenda iv;
        printf("ID do produto: ");
        scanf("%d", &iv.id_produto);
        printf("Quantidade: ");
        scanf("%d", &iv.quantidade);
        // busca preço unitário no array de produtos
        iv.valor_unitario = produtos[iv.id_produto-1].preco;
        v.itens[v.num_itens++] = iv;
        v.total += iv.quantidade * iv.valor_unitario;

        printf("Adicionar mais itens? (s/n): ");
        scanf(" %c", &more);
    } while (more == 's' || more == 'S');

    vendas[ultimo_id_venda-1] = v;
    printf("Venda cadastrada! ID: %03d | Total: R$ %.2f\n", v.id, v.total);
}

void listar_vendas() {
    printf("\n--- Lista de Vendas ---\n");
    for (int i = 0; i < ultimo_id_venda; i++) {
        if (vendas[i].id != -1) {
            Venda *v = &vendas[i];
            printf("ID: %03d | Cliente ID: %d | Data: %s | Total: R$ %.2f\n",
                   v->id, v->id_cliente, v->data, v->total);
            for (int j = 0; j < v->num_itens; j++) {
                ItemVenda *iv = &v->itens[j];
                printf("  - Produto ID: %d | Qtde: %d | Unit: R$ %.2f\n",
                       iv->id_produto, iv->quantidade, iv->valor_unitario);
            }
        }
    }
}

void atualizar_venda(int id) {
    printf("Em breve\n"); // em breve professor, tenha calma!
}

void remover_venda(int id) {
    for (int i = 0; i < ultimo_id_venda; i++) {
        if (vendas[i].id == id) {
            vendas[i].id = -1;
            printf("Venda removida!\n");
            return;
        }
    }
    printf("Venda com ID %d não encontrada.\n", id);
}
