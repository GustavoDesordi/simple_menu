#include <stdio.h>
#include "cliente.h"

Cliente clientes[MAX_CLIENTES];
int ultimo_id_cliente = 0;

void inserir_cliente() {
    if (ultimo_id_cliente >= MAX_CLIENTES) {
        printf("Limite de clientes atingido!\n");
        return;
    }

    Cliente novo;
    novo.id = ultimo_id_cliente + 1;
    printf("Nome: ");
    scanf(" %[^\n]", novo.nome);
    printf("CPF: ");
    scanf(" %[^\n]", novo.cpf);

    clientes[ultimo_id_cliente] = novo;
    ultimo_id_cliente++;

    printf("Cliente inserido com sucesso!\n");
}

void listar_clientes() {
    printf("\n--- Lista de Clientes ---\n");
    for (int i = 0; i < ultimo_id_cliente; i++) {
        if (clientes[i].id != -1) {
            printf("ID: %d | Nome: %s | CPF: %s\n",
                clientes[i].id,
                clientes[i].nome,
                clientes[i].cpf);
        }
    }
}

void atualizar_cliente(int id) {

    for (int i = 0; i < ultimo_id_cliente; i++) {
        if (clientes[i].id == id) {
            printf("Novo nome: ");
            scanf(" %[^\n]", clientes[i].nome);
            printf("Novo CPF: ");
            scanf(" %[^\n]", clientes[i].cpf);
            printf("Cliente atualizado!\n");
            return;
        }
    }
    printf("Cliente com ID %d não encontrado.\n", id);
}

void remover_cliente(int id) {
    for (int i = 0; i < ultimo_id_cliente; i++) {
        if (clientes[i].id == id) {
            clientes[i].id = -1;
            printf("Cliente removido!\n");
            return;
        }
    }
    printf("Cliente com ID %d não encontrado.\n", id);
}
