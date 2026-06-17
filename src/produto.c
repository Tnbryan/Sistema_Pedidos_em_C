#include <stdio.h>

// os printf é apenas para o compilador executar o codigo, porque ele vazio não funciona
// quando for fazer , pode apagar e alterar


//void cadastrarProduto() {
   //printf("Cadastrar produto\n");
//}
//void listarProdutos() {
    //printf("Listar produtos\n");
//}
//void alterarProduto() {
  //  printf("Alterar produto\n");
//}
//void excluirProduto() {
  //  printf("Excluir produto\n");
//}
//-----------------------------------------------------------------------------------------------------------------\\
//Código teste  Caso dê algum problema pode falar comigo C. 


#include <stdio.h>
#include <stdlib.h>

void cadastrarProduto() {

    FILE *arquivo;
    int id;
    char nome[50];
    float preco;

    arquivo = fopen("../data/produtos.txt", "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    printf("\n=== CADASTRAR PRODUTO ===\n");

    printf("ID: ");
    scanf("%d", &id);

    printf("Nome: ");
    scanf(" %[^\n]", nome);

    printf("Preco: ");
    scanf("%f", &preco);

    fprintf(arquivo, "%d;%s;%.2f\n", id, nome, preco);

    fclose(arquivo);

    printf("Produto cadastrado com sucesso!\n");
}

void listarProdutos() {

   FILE *arquivo;
    char linha[100];

    arquivo = fopen("../data/produtos.txt", "r");

    if (arquivo == NULL) {
        printf("Nenhum produto cadastrado!\n");
        return;
    }

    printf("\n=== LISTA DE PRODUTOS ===\n");

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }

    fclose(arquivo);

    printf("\nPressione ENTER para voltar...");
    getchar();
    getchar();
}

void alterarProduto() {

    FILE *arquivo;
    FILE *temp;

    int idBusca;
    int id;
    char nome[50];
    float preco;
    int encontrado = 0;

    printf("Digite o ID do produto que deseja alterar: ");
    scanf("%d", &idBusca);

    arquivo = fopen("../data/produtos.txt", "r");
    temp = fopen("../data/temp.txt", "w");

    if (arquivo == NULL) {
        printf("Arquivo nao encontrado!\n");
        return;
    }

    while (fscanf(arquivo, "%d;%49[^;];%f\n",
                  &id,
                  nome,
                  &preco) == 3) {

        if (id == idBusca) {

            encontrado = 1;

            printf("Novo nome: ");
            scanf(" %[^\n]", nome);

            printf("Novo preco: ");
            scanf("%f", &preco);
        }

        fprintf(temp,
                "%d;%s;%.2f\n",
                id,
                nome,
                preco);
    }

    fclose(arquivo);
    fclose(temp);

    remove("../data/produtos.txt");
    rename("../data/temp.txt", "../data/produtos.txt");

    if (encontrado)
        printf("Produto alterado com sucesso!\n");
    else
        printf("Produto nao encontrado!\n");
}

void excluirProduto() {

    FILE *arquivo;
    FILE *temp;

    int idBusca;
    int id;
    char nome[50];
    float preco;
    int encontrado = 0;

    printf("Digite o ID do produto que deseja excluir: ");
    scanf("%d", &idBusca);

    arquivo = fopen("../data/produtos.txt", "r");
    temp = fopen("../data/temp.txt", "w");

    if (arquivo == NULL) {
        printf("Arquivo nao encontrado!\n");
        return;
    }

    while (fscanf(arquivo, "%d;%49[^;];%f\n",
                  &id,
                  nome,
                  &preco) == 3) {

        if (id == idBusca) {
            encontrado = 1;
            continue;
        }

        fprintf(temp,
                "%d;%s;%.2f\n",
                id,
                nome,
                preco);
    }

    fclose(arquivo);
    fclose(temp);

    remove("../data/produtos.txt");
    rename("../data/temp.txt", "../data/produtos.txt");

    if (encontrado)
        printf("Produto excluido com sucesso!\n");
    else
        printf("Produto nao encontrado!\n");
}




