#include <stdio.h>
#include "src/cliente/cliente.h"
#include "src/produto/produto.h"
#include "src/venda/venda.h"

void menu_clientes() {
    int opcao;
    do {
        printf("\n--- MENU CLIENTES ---\n");
        printf("1 - Inserir Cliente\n");
        printf("2 - Listar Clientes\n");
        printf("3 - Atualizar Cliente\n");
        printf("4 - Remover Cliente\n");
        printf("0 - Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) inserir_cliente();
        else if (opcao == 2) listar_clientes();
        else if (opcao == 3) {
            int id;
            printf("ID do cliente: ");
            scanf("%d", &id);
            atualizar_cliente(id);
        }
        else if (opcao == 4) {
            int id;
            printf("ID do cliente: ");
            scanf("%d", &id);
            remover_cliente(id);
        }

    } while (opcao != 0);
}

void menu_produtos() {
    int opcao;
    do {
        printf("\n--- MENU PRODUTOS ---\n");
        printf("1 - Inserir Produto\n");
        printf("2 - Listar Produtos\n");
        printf("3 - Atualizar Produto\n");
        printf("4 - Remover Produto\n");
        printf("0 - Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) inserir_produto();
        else if (opcao == 2) listar_produtos();
        else if (opcao == 3) {
            int id;
            printf("ID do produto: ");
            scanf("%d", &id);
            atualizar_produto(id);
        }
        else if (opcao == 4) {
            int id;
            printf("ID do produto: ");
            scanf("%d", &id);
            remover_produto(id);
        }

    } while (opcao != 0);
}

void menu_vendas() {
    int opcao;
    do {
        printf("\n--- MENU VENDAS ---\n");
        printf("1 - Inserir Venda\n");
        printf("2 - Listar Vendas\n");
        printf("3 - Atualizar Venda\n");
        printf("4 - Remover Venda\n");
        printf("0 - Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) inserir_venda();
        else if (opcao == 2) listar_vendas();
        else if (opcao == 3) {
            int id; printf("ID da venda: "); scanf("%d", &id);
            atualizar_venda(id);
        }
        else if (opcao == 4) {
            int id; printf("ID da venda: "); scanf("%d", &id);
            remover_venda(id);
        }
    } while (opcao != 0);
}

int main() {
    int opcao;
    do {
        printf(
            "\n--- MENU PRINCIPAL ---\n"
            "1 - Clientes\n"
            "2 - Produtos\n"
            "3 - Vendas\n"
            "0 - Sair\n"
            "Escolha: "
        );
        scanf("%d", &opcao);

        if (opcao == 1) menu_clientes();
        else if (opcao == 2) menu_produtos();
        else if (opcao == 3) menu_vendas();

    } while (opcao != 0);

    return 0;
}
