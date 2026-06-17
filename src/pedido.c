#include <stdio.h>

// os printf é apenas para o compilador executar o codigo, porque ele vazio não funciona
// quando for fazer , pode apagar e alterar




void criarPedido() {
    printf("Criar pedido\n");

    FILE *arquivo;
    int id;
    char cliente[50];
    int quantidade;
    float preco;

    arquivo = fopen("../data/pedidos.txt", "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    printf("\n=== CADASTRAR PEDIDO ===\n");

    printf("ID: ");
    scanf("%d", &id);

    printf("Nome do cliente : ");
    scanf(" %[^\n]", cliente);

    printf("Quantiade: ");
    scanf("%d", &quantidade);

    printf("Preco: ");
    scanf("%f", &preco);

    fprintf(arquivo, "%d;%s;%d,%.2f\n", id, cliente,quantidade, preco);

    fclose(arquivo);

    printf("Pedido cadastrado com sucesso!\n");
    
    printf("\nPressione ENTER para voltar...");
    getchar();
    getchar();
}
void listarPedidos() {
    printf("Listar pedidos\n");
  FILE *arquivo;
    char linha[100];

    arquivo = fopen("../data/pedidos.txt", "r");

    if (arquivo == NULL) {
        printf("Nenhum produto cadastrado!\n");
        return;
    }

    printf("\n=== LISTA DE PEDIDOS ===\n");

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }

    fclose(arquivo);

    printf("\nPressione ENTER para voltar...");
    getchar();
    getchar();
}