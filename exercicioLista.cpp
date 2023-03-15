#include<stdio.h>
#include <cstdlib>

struct No {
    int valor;
    No *prox;
};

struct Lista {
    No *cabeca, *cauda;
    int n;

    Lista() {
        cabeca = cauda = NULL;
        n = 0;
    }

    bool vazia() { // O(1)
        return (cabeca == NULL);
    }

    void inserirInicio(int v) { // O(1)
        No *novo = new No();
        novo->valor = v;
        if (vazia()) {
            novo->prox = NULL;
            cabeca = novo;
            cauda = novo;
        } else {
            novo->prox = cabeca;
            cabeca = novo;
        }
        n++;
    }

    void inserirFinal(int v) { // O(1)
        No *novo = new No();
        novo->valor = v;
        if (vazia()) {
            novo->prox = NULL;
            cabeca = novo;
            cauda = novo;
        } else {
            novo->prox = NULL;
            cauda->prox = novo;
            cauda = novo;
        }
        n++;
    }

    void imprimir() { // O(n)
        No *aux = cabeca;
        while (aux != NULL) {
            printf("%d\n", aux->valor);
            aux = aux->prox;
        }
    }

    int tamanho() { // O(1)
        return n;
    }

    void removerInicio() { // O(1)
        if (!vazia()) {
            if (tamanho() == 1) {
                No *aux = cabeca;
                cabeca = NULL;
                cauda = NULL;
                delete(aux);
            } else {
                No *aux = cabeca;
                cabeca = cabeca->prox;
                delete(aux);
            }
            n--;
        }
    }

    void removerFinal() { // O(n)
        if (!vazia()) {
            if (tamanho() == 1) {
                No *aux = cabeca;
                cabeca = NULL;
                cauda = NULL;
                delete(aux);
            } else {
                No *penultimo = cabeca;
                while (penultimo->prox != cauda) {
                    penultimo = penultimo->prox;
                }
                delete(cauda);
                cauda = penultimo;
                cauda->prox = NULL;
            }
            n--;
        }
    }

    //1
    void removerNUltimos(int n) {
        if (n <= 0)
            return;
    
        int tam = tamanho();
        if (n >= tam) {
            while (!vazia()) {
                No *aux = cabeca;
                cabeca = cabeca->prox;
                delete aux;
            }
            cauda = NULL;
        } else {
            No *aux = cabeca;
            for (int i = 0; i < tam - n - 1; i++) {
                aux = aux->prox;
            }
            No *del = aux->prox;
            aux->prox = NULL;
            cauda = aux;
            while (del != NULL) {
                aux = del->prox;
                delete del;
                del = aux;
            }
        }
    }

    //2
    void removerSegundo() {
        if (vazia() || cabeca->prox == NULL) return;
        No *aux = cabeca->prox;
        cabeca->prox = aux->prox;
        delete aux;
    }   

    //3
    void inserirTamanho() {
        int tam = tamanho();
        inserirFinal(tam);
    }

    //4
    void inserirNumeros(int n) {
        if (n <= 0) 
            return;
        for (int i = 1; i <= n; i++) {
            inserirFinal(i);
        }
    }

    //5
    void inserirPenultimo(int v) {
        if (vazia() || cabeca->prox == NULL) 
            return;
        No *aux = cabeca;
        while (aux->prox->prox != NULL) {
            aux = aux->prox;
        }
        No *novo = new No();
        novo->valor = v;
        novo->prox = aux->prox;
        aux->prox = novo;
    }
};

int main() {
    Lista l;

    l.inserirInicio(5);
    l.inserirInicio(7);
    l.inserirInicio(10);
    l.inserirFinal(8);
    l.inserirFinal(2);
    l.inserirFinal(3);
    l.removerInicio();

    l.removerNUltimos(4);
    l.removerSegundo();
    l.inserirNumeros(17);
    l.inserirPenultimo(6);
    l.inserirTamanho();

    l.imprimir();

    return 0;
}

/*
1. Criar um método que recebe um número N e remove os N últimos elementos da lista. 
Caso o tamanho da lista seja menor que N, esvaziar a lista.
2. Crie um método que remove o segundo elemento da lista. Se a lista tiver tamanho <= 1, 
seu método não deve fazer nada.
3. Crie um método que seja capaz de inserir no final da lista o tamanho atual da lista.
4. Crie um método que receba um número N e insira na lista todos os números de 1 até N.
5. Crie um método que insere um elemento sempre na penúltima posição da lista. 
Se a lista tiver tamanho <= 1, seu método não deve fazer nada.
*/
