#include <stdio.h>
#include <stdlib.h>

struct node
{
    int valor;
    struct node *direita;
    struct node *esquerda;
};

typedef struct node Node;


Node* criar(int valor) {
        Node *n = (Node*) malloc(sizeof(Node));

        n->valor = valor;
        n->direita = NULL;
        n->esquerda = NULL;

        return n;
}

void adicionar(Node *n, int valor) {
    if(valor < n->valor) {
        if(n->esquerda == NULL) {
            n->esquerda = criar(valor);
        } else {
            adicionar(n->esquerda, valor);
        }
    } else {
        if(n->direita == NULL) {
            n->direita = criar(valor);
        } else {
            adicionar(n->direita,valor);
        }
    }
}

void imprimir(Node *n) {
    if(n == NULL) return;
    imprimir(n->direita);
    printf('Node: %d', n->valor);
    imprimir(n->esquerda);
}

int main(void) {

    Node *root = criar(5);

    imprimir(root);
    return 0;
}