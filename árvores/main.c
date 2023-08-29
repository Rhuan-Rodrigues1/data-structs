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
        Node *n = malloc(sizeof(Node));

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
    imprimir(n->esquerda);
    printf("\nNode: %d", n->valor);
    imprimir(n->direita);
}

int main(void) {

    Node *root = criar(5);

    adicionar(root,2);
	adicionar(root,0);
	adicionar(root,1);
	adicionar(root,8);
	adicionar(root,4);

    imprimir(root);
    return 0;
}