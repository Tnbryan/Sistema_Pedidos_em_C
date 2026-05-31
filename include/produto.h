#ifndef PRODUTO_H
#define PRODUTO_H


// Esse é o struct base que vamos utilizar em todo o projeto. 
typedef struct {
    int codigo;
    char nome[50];
    float preco;
    int estoque;
} Produto;


// Funções void para alteração

void cadastrarProduto();
void listarProdutos();
void alterarProduto();
void excluirProduto();






#endif