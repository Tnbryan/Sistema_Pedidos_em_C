#include <stdio.h>
#include "../include/produto.h"
#include "../include/pedido.h"
#include "../include/arquivo.h"

// Código Main contendo os Menus e suas funções
// Primeiro é a declaração das funções e no main é o chamado deles
// Protótipos
void menuPrincipal();
void menuProdutos();
void menuPedidos();

void menuPrincipal(){

        int opcao;

    do
    {
      printf("\n=== SISTEMA DE PEDIDOS ===\n"); 
      printf("1 - Produtos\n");
      printf("2 - Pedidos\n");
      printf("3 - Sair\n");
      printf("Escolha sua opção\n");
      scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            menuProdutos();
            break;
        case 2:
            menuPedidos();
            break;
        case 3:
            printf("Encerrando o Sistema.....\n");
            break;
        default:
            printf("Opção não reconhecida! Leia as intruções novamente\n");
        }
    } while (opcao != 3);
    
}

void menuProdutos(){

           int opcao;

    do
    {
      printf("\n=== ARÉA DE PRODUTOS ===\n"); 
      printf("1 - Cadastrar\n");
      printf("2 - Listar\n");
      printf("3 - Alterar\n");
      printf("4 - Excluir\n");
      printf("5 - Voltar ao Menu Princaal\n");
      printf("Escolha sua opção\n");
      scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastrarProduto();// Essas funções ainda não foram criadas por vcs mas já foi predefinida
            break;
        case 2:
            listarProdutos();
            break;
        case 3:
            alterarProduto();
            break;
        case 4:
            excluirProduto();
            break;
        default:
            printf("Opção não reconhecida! Leia as intruções novamente\n");
        }
    } while (opcao != 5);
    
}

void menuPedidos(){

           int opcao;

    do
    {
      printf("\n=== ARÉA DE PEDIDOS ===\n"); 
      printf("1 - Criar Pedido\n");
      printf("2 - Listar os Pedidos\n");
      printf("3 - Voltar ao Menu Princaal\n");
      printf("Escolha sua opção\n");
      scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            criarPedido();// Essas funções ainda não foram criadas por vcs mas já foi predefinida
            break;
        case 2:
            listarPedidos();
            break;
        case 3:
            printf("Voltando ao Menu Principal...\n");
            break;

        default:
            printf("Opção não reconhecida! Leia as intruções novamente\n");
        }
    } while (opcao != 3);
    
}

int main(){

    menuPrincipal();

    return 0;
}