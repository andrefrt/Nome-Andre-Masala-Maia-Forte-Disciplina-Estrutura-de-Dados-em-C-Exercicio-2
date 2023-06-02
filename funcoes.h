typedef struct no_arvore {
    int valor;
    struct no_arvore* esquerda;
    struct no_arvore* direita;
} NoArvore;

void empilha(int valor, int* pilha, int* topo) {
    if (*topo == 99) {
        printf("A pilha está cheia.\n");
    } else {
        *topo += 1;
        pilha[*topo] = valor;
    }
}
void desempilha(int* topo) {
    if (*topo == -1) {
        printf("A pilha está vazia.\n");
    } else {
        *topo -= 1;
    }
}

void imprimirPilha(int* pilha, int topo) {
    if (topo == -1) {
        printf("A pilha está vazia.\n");
    } else {
        printf("Pilha completa:\n");
        for (int i = topo; i >= 0; i--) {
            printf("%d\n", pilha[i]);
        }
    }
}

void limparPilha(int* topo) {
    *topo = -1;
}

void imprimirTopoPilha(int* pilha, int topo) {
    if (topo == -1) {
        printf("A pilha está vazia.\n");
    } else {
        printf("Topo da pilha: %d\n", pilha[topo]);
    }
}

void enqueue(int valor, int* fila, int* frente, int* tras) {
    if (*tras == 99) {
        printf("A fila está cheia.\n");
    } else {
        *tras += 1;
        fila[*tras] = valor;
        if (*frente == -1) {
            *frente = 0;
        }
    }
}

void dequeue(int* frente, int* tras) {
    if (*frente == -1) {
        printf("A fila está vazia.\n");
    } else {
        *frente += 1;
        if (*frente > *tras) {
            *frente = -1;
            *tras = -1;
        }
    }
}

void imprimirFila(int* fila, int frente, int tras) {
    if (frente == -1) {
        printf("A fila está vazia.\n");
    } else {
        printf("Elementos da fila:\n");
        for (int i = frente; i <= tras; i++) {
            printf("%d\n", fila[i]);
        }
    }
}

void limparFila(int* frente, int* tras) {
    *frente = -1;
    *tras = -1;
}

int maiorElementoFila(int* fila, int frente, int tras) {
    int maior = fila[frente];
    for (int i = frente + 1; i <= tras; i++) {
        if (fila[i] > maior) {
            maior = fila[i];
        }
    }
    return maior;
}

int menorElementoFila(int* fila, int frente, int tras) {
    int menor = fila[frente];
    for (int i = frente + 1; i <= tras; i++) {
        if (fila[i] < menor) {
            menor = fila[i];
        }
    }
    return menor;
}

NoArvore* criarNoArvore(int valor) {
    NoArvore* novo = (NoArvore*)malloc(sizeof(NoArvore));
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

NoArvore* inserirArvore(NoArvore* raiz, int valor) {
    if (raiz == NULL) {
        return criarNoArvore(valor);
    } else if (valor < raiz->valor) {
        raiz->esquerda = inserirArvore(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserirArvore(raiz->direita, valor);
    }
    return raiz;
}

void imprimirArvore(NoArvore* raiz) {
    if (raiz != NULL) {
        imprimirArvore(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimirArvore(raiz->direita);
    }
}

NoArvore* buscarElemento(NoArvore* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor) {
        return raiz;
    } else if (valor < raiz->valor) {
        return buscarElemento(raiz->esquerda, valor);
    } else {
        return buscarElemento(raiz->direita, valor);
    }
}

void imprimirArvoreDireitaEsquerda(NoArvore* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        imprimirArvoreDireitaEsquerda(raiz->direita);
        imprimirArvoreDireitaEsquerda(raiz->esquerda);
    }
}

int maiorElementoArvore(NoArvore* raiz) {
    if (raiz == NULL) {
        printf("A árvore está vazia.\n");
        return -1;
    } else if (raiz->direita == NULL) {
        return raiz->valor;
    } else {
        return maiorElementoArvore(raiz->direita);
    }
}

NoArvore* removerNoArvore(NoArvore *raiz, int item) {
    if (raiz == NULL) {
        printf("Valor não encontrado!\n");
        return NULL;
    } else if (raiz->valor == item) {
        if (raiz->esquerda == NULL && raiz->direita == NULL) {
            free(raiz);
            return NULL;
        } else if (raiz->esquerda == NULL || raiz->direita == NULL) {
            NoArvore* aux;
            if (raiz->esquerda != NULL)
                aux = raiz->esquerda;
            else
                aux = raiz->direita;
            free(raiz);
            return aux;
        } else {
            NoArvore* aux = raiz->esquerda;
            while (aux->direita != NULL)
                aux = aux->direita;
            raiz->valor = aux->valor;
            aux->valor = item;
            raiz->esquerda = removerNoArvore(raiz->esquerda, item);
            return raiz;
        }
    } else {
        if (item < raiz->valor) {
            raiz->esquerda = removerNoArvore(raiz->esquerda, item);
        } else {
            raiz->direita = removerNoArvore(raiz->direita, item);
        }
        return raiz;
    }
}
