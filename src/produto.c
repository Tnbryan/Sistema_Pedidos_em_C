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

// Cadastrar Produto
void cadastrarProduto() {

    FILE *arquivo;
    int id;
    char nome[50];

    arquivo = fopen("produtos.txt", "a");

    printf("\n=== CADASTRAR PRODUTO ===\n");

    printf("ID: ");
    scanf("%d", &id);

    printf("Nome: ");
    scanf(" %[^\n]", nome);

    fprintf(arquivo, "%d;%s\n", id, nome);

    fclose(arquivo);

    printf("Produto cadastrado com sucesso!\n");
}

// Listar Produtos
void listarProdutos() {

    FILE *arquivo;
    char linha[100];

    arquivo = fopen("produtos.txt", "r");

    printf("\n=== LISTA DE PRODUTOS ===\n");

    while (fgets(linha, 100, arquivo)) {
        printf("%s", linha);
    }

    fclose(arquivo);
}

// Alterar Produto
void alterarProduto() {

    FILE *arquivo;
    FILE *temp;

    int idBusca;
    int id;
    char nome[50];
    char novoNome[50];

    printf("\nDigite o ID do produto que deseja alterar: ");
    scanf("%d", &idBusca);

    arquivo = fopen("produtos.txt", "r");
    temp = fopen("temp.txt", "w");

    while (fscanf(arquivo, "%d;%[^\n]\n", &id, nome) == 2) {

        if (id == idBusca) {

            printf("Novo nome: ");
            scanf(" %[^\n]", novoNome);

            fprintf(temp, "%d;%s\n", id, novoNome);

        } else {

            fprintf(temp, "%d;%s\n", id, nome);
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove("produtos.txt");
    rename("temp.txt", "produtos.txt");

    printf("Produto alterado com sucesso!\n");
}

// Excluir Produto
void excluirProduto() {

    FILE *arquivo;
    FILE *temp;

    int idBusca;
    int id;
    char nome[50];

    printf("\nDigite o ID do produto que deseja excluir: ");
    scanf("%d", &idBusca);

    arquivo = fopen("produtos.txt", "r");
    temp = fopen("temp.txt", "w");

    while (fscanf(arquivo, "%d;%[^\n]\n", &id, nome) == 2) {

        if (id != idBusca) {

            fprintf(temp, "%d;%s\n", id, nome);
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove("produtos.txt");
    rename("temp.txt", "produtos.txt");

    printf("Produto excluido com sucesso!\n");
}
