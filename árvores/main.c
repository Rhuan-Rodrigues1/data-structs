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

void remover(Node *n, int valor) {
    Node *filho = n;
    Node *pai;

    do
    {
        pai = filho;

        if (valor < filho->valor)
        {
            filho = filho->esquerda;
        } else if (valor > filho->valor) {
            filho = filho->direita;
        }
        
    } while (filho != NULL && filho->valor != valor);

    if(filho != NULL) {
        if(filho->esquerda == NULL && filho->direita == NULL) {
            if(pai->esquerda == filho) pai->esquerda = NULL;
            if(pai->direita == filho) pai->direita = NULL;
        }

        if(filho->esquerda != NULL && filho->direita == NULL) {
            if(pai->esquerda == filho) pai->esquerda = filho->esquerda;
            if(pai->direita == filho) pai->direita = filho->esquerda;
        }

        if(filho->direita != NULL && filho->esquerda == NULL) {
            if(pai->esquerda == filho) pai->esquerda = filho->direita;
            if(pai->direita == filho) pai->direita = filho->direita;
        }

        if(filho->esquerda != NULL && filho->direita != NULL) {
            if(filho->esquerda->direita == NULL) {
                filho->valor = filho->esquerda->valor;
                filho->esquerda = NULL;
            } else {
                Node *p = filho->esquerda;
                Node *aux = p;

                while(p->direita != NULL) {
                    aux = p;
                    p = p->direita;
                }

                aux->direita = NULL;
                filho->valor = p->valor;

            }
        }
    }
    
}

int main(void) {

    Node *root = criar(5);

    adicionar(root,2);
	adicionar(root,0);
	adicionar(root,1);
	adicionar(root,8);
	adicionar(root,4);

    remover(root, 4);

    imprimir(root);
    return 0;
}