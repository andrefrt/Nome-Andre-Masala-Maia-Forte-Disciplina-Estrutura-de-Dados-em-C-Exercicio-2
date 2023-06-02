#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main() {
    int opcao;

    NoArvore* arvore = NULL;
    int pilha[100];
    int topo = -1;
    int fila[100];
    int frente = -1;
    int tras = -1;

    do {
        printf("\nOpções:\n");
        printf("1. Iniciar Pilha\n");
        printf("2. Iniciar Fila\n");
        printf("3. Iniciar Árvore\n");
        printf("0. Sair\n");
        printf("Digite o número da opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                int opcaoPilha;

                do {
                    printf("\nMenu da Pilha:\n");
                    printf("1. Empilha\n");
                    printf("2. Desempilha\n");
                    printf("3. Imprimir Pilha\n");
                    printf("4. Limpar Pilha\n");
                    printf("5. Imprimir Topo da Pilha\n");
                    printf("0. Voltar\n");
                    printf("Escolha uma opção: ");
                    scanf("%d", &opcaoPilha);

                    switch (opcaoPilha) {
                        case 1: {
                            int valor;
                            printf("Digite o valor a ser empilhado: ");
                            scanf("%d", &valor);
                            empilha(valor, pilha, &topo);
                            break;
                        }
                        case 2:
                            desempilha(&topo);
                            break;
                        case 3:
                            imprimirPilha(pilha, topo);
                            break;
                        case 4:
                            limparPilha(&topo);
                            break;
                        case 5:
                            imprimirTopoPilha(pilha, topo);
                            break;
                        case 0:
                            break;
                        default:
                            printf("Opção inválida.\n");
                    }
                } while (opcaoPilha != 0);

                break;
            }
            case 2: {
                int opcaoFila;

                do {
                    printf("\nMenu da Fila:\n");
                    printf("1. Enqueue\n");
                    printf("2. Dequeue\n");
                    printf("3. Imprimir Fila\n");
                    printf("4. Limpar Fila\n");
                    printf("5. Maior elemento da Fila\n");
                    printf("6. Menor elemento da Fila\n");
                    printf("0. Voltar\n");
                    printf("Escolha uma opção: ");
                    scanf("%d", &opcaoFila);

                    switch (opcaoFila) {
                        case 1: {
                            int valor;
                            printf("Digite o valor a ser enfileirado: ");
                            scanf("%d", &valor);
                            enqueue(valor, fila, &frente, &tras);
                            break;
                        }
                        case 2:
                            dequeue(&frente, &tras);
                            break;
                        case 3:
                            imprimirFila(fila, frente, tras);
                            break;
                        case 4:
                            limparFila(&frente, &tras);
                            break;
                        case 5: {
                            int maior = maiorElementoFila(fila, frente, tras);
                            printf("Maior elemento da Fila: %d\n", maior);
                            break;
                        }
                        case 6: {
                            int menor = menorElementoFila(fila, frente, tras);
                            printf("Menor elemento da Fila: %d\n", menor);
                            break;
                        }
                        case 0:
                            break;
                        default:
                            printf("Opção inválida.\n");
                    }
                } while (opcaoFila != 0);

                break;
            }
            case 3: {
                int opcaoArvore;

                do {
                    printf("\nMenu da Árvore:\n");
                    printf("1. Inserir elemento\n");
                    printf("2. Imprimir Árvore\n");
                    printf("3. Buscar elemento\n");
                    printf("4. Imprimir Árvore (Direita-Esquerda)\n");
                    printf("5. Maior elemento da Árvore\n");
                    printf("0. Voltar\n");
                    printf("Escolha uma opção: ");
                    scanf("%d", &opcaoArvore);

                    switch (opcaoArvore) {
                        case 1: {
                            int valor;
                            printf("Digite o valor a ser inserido na Árvore: ");
                            scanf("%d", &valor);
                            arvore = inserirArvore(arvore, valor);
                            break;
                        }
                        case 2:
                            printf("Árvore: ");
                            imprimirArvore(arvore);
                            printf("\n");
                            break;
                        case 3: {
                            int valor;
                            printf("Digite o valor a ser buscado na Árvore: ");
                            scanf("%d", &valor);
                            NoArvore* no = buscarElemento(arvore, valor);
                            if (no != NULL) {
                                printf("Elemento %d encontrado na Árvore.\n", valor);
                            } else {
                                printf("Elemento %d não encontrado na Árvore.\n", valor);
                            }
                            break;
                        }
                        case 4:
                            printf("Árvore (Direita-Esquerda): ");
                            imprimirArvoreDireitaEsquerda(arvore);
                            printf("\n");
                            break;
                        case 5: {
                            int maior = maiorElementoArvore(arvore);
                            printf("Maior elemento da Árvore: %d\n", maior);
                            break;
                        }
                        case 6:
                            printf("Digite o número do nó a ser removido: ");
                            scanf("%d", &item);
                            arvore = removerNoArvore(arvore, item);
                            printf("Nó removido com sucesso!\n");
                            break;
                        case 0:
                            break;
                        default:
                            printf("Opção inválida.\n");
                    }
                } while (opcaoArvore != 0);

                break;
            }
            case 0:
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}
