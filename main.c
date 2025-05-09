#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Iniciando funcoes

int menu();
int cadastro_cliente();
int lista_cliente();

// Iniciando variaveis

#define total_clientes 10
char cliente[total_clientes][32];
int n_de_clientes = 0;

int main(void){
    menu();
}

int menu(){
    int escolha=0;

    do{

        system("clear");

        printf("\t -------- MENU -------\n");
        printf("\t 1 - CADASTRAR CLIENTE \n");
        printf("\t 2 - CADASTRAR PRODUTO \n");
        printf("\t 3 - LISTAR CLIENTES \n");
        printf("\t 4 - LISTAR PRODUTOS \n");
        printf("\t 5 - SAIR\n");
        printf("\t ----------------------");
        printf("\n Selecione uma opcao:  ");
        scanf("%d", &escolha);

        system("clear");

        switch(escolha){
            case 1:
                cadastro_cliente();
                break;
            case 2:
                //cadastro_produto();
                break;
            case 3:
                lista_cliente();
                break;
            case 4:
                printf("4\n");
                break;
        }

    }while(escolha!=5);

    return 0;
}

int cadastro_cliente(){
    char resposta[8];
    if (strlen(cliente[0]) > 0){ // compara se tem algum nome dentro de cliente, se tiver executa o if, senão o else.
        printf("if\n");

        printf("Cliente %d: ", n_de_clientes+1);
        scanf("%s", cliente[n_de_clientes+1]);

        printf("Deseja cadastrar outro cliente? ");
        scanf("%s", resposta);

        if (strcmp(resposta, "sim") == 0 || strcmp(resposta, "s") == 0){ // esse comando e para verificar se a respota e "sim" ou "s"
            do{
                n_de_clientes++;
                printf("Cliente %d: ", n_de_clientes+1);
                scanf("%s", cliente[n_de_clientes+1]);

                printf("Deseja cadastrar outro cliente? ");
                scanf("%s", resposta);
            }while(strcmp(resposta, "sim") == 0 || strcmp(resposta, "s") == 0);
        }

    }else{
        printf("Cliente %d: ", n_de_clientes+1);
        scanf("%s", cliente[n_de_clientes]);
        n_de_clientes++;
        printf("Deseja cadastrar outro cliente? ");
        scanf("%s", resposta);

        if (strcmp(resposta, "sim") == 0 || strcmp(resposta, "s") == 0){ // esse comando e para verificar se a respota e "sim" ou "s"
            do{
                printf("Cliente %d: ", n_de_clientes+1);
                scanf("%s", cliente[n_de_clientes]);
                n_de_clientes++;
                printf("Deseja cadastrar outro cliente? ");
                scanf("%s", resposta);
            }while(strcmp(resposta, "sim") == 0 || strcmp(resposta, "s") == 0);
        }
    }

    return 0;
}

// arrumar essa lista de clientes que nao ta funcionando

int lista_cliente(){
    char resposta[8];

    printf("Clientes:");

    if (cliente > 0){

        for(int i=0;i<total_clientes;i++){
            printf(" %s", cliente[i]);
        }

        printf("\nDeseja voltar para o menu? ");
        scanf("%s", resposta);

        if (strcmp(resposta, "sim") == 0 || strcmp(resposta, "s") == 0){
            return 0;
        }
    }

    return 0;
}