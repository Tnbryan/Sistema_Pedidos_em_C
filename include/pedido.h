#ifndef PEDIDO_H
#define PEDIDO_H


// Esse é o struct base que vamos utilizar em todo o projeto. 
typedef struct {
    int id;
    char cliente[50];
    int quantidade;
    float preco;
} Pedido;

// Funções void
void criarPedido();
void listarPedidos();


#endif