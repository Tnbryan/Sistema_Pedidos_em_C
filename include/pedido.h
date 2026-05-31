#ifndef PEDIDO_H
#define PEDIDO_H


// Esse é o struct base que vamos utilizar em todo o projeto. 
typedef struct {
    int numero;
    int codigoProduto;
    int quantidade;
    float valorTotal;
} Pedido;


// Funções void
void criarPedido();
void listarPedidos();


#endif