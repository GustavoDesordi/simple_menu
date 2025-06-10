#ifndef CLIENTE_H
#define CLIENTE_H

#define MAX_CLIENTES 100

typedef struct {
    int id;
    char nome[100];
    char cpf[20];
} Cliente;

void inserir_cliente();
void listar_clientes();
void atualizar_cliente(int id);
void remover_cliente(int id);

#endif
