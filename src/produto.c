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

    printf("Produto cadastrado!\n");
}

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




