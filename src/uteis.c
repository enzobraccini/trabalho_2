#include "../include/uteis.h"
#include "../include/types.h"
#include <stdlib.h>

int contar_aeronaves(NoAeronave_t *nova) {
    int contador = 0;
    NoAeronave_t *atual = nova;
    while (atual != NULL) {
        contador++;
        atual = atual->proximo;
    }
    return contador;
}

int contar_rotas(NoRota_t *nova) {
    int contador = 0;
    NoRota_t *atual = nova;
    while (atual != NULL) {
        contador++;
        atual = atual->proximo;
    }
    return contador;
}

void liberar_lista_aeronaves(NoAeronave_t *nova) {
    NoAeronave_t *atual = nova;
    NoAeronave_t *proximo;
    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

void liberar_lista_rotas(NoRota_t *nova) {
    NoRota_t *atual = nova;
    NoRota_t *proximo;
    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}